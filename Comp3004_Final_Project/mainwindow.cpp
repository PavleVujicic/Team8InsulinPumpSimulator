#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , device(Device())
    , profileGroup(new QButtonGroup(this))
    , chart(new QChart())
    , series(new QLineSeries(this))
    , axisX(new QValueAxis())
    , axisY(new QValueAxis())
    , constantLine3_9(new QLineSeries(this))
    , constantLine10(new QLineSeries(this))
{
    ui->setupUi(this);
    user = new User();
    device.setUser(user);

    lastGlucose = user->getCurrentGlucoseLevel();
    setArrowRight(); // Set the initial arrow direction to right

    setIcon(":/Images/Maintains.png");

    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::update);

    hourlyBasalTimer = new QTimer(this);
    connect(hourlyBasalTimer, &QTimer::timeout, this, &MainWindow::basalDeposit);

    // Making Connections
    connect(ui->SubmitForm, &QPushButton::clicked, this, &MainWindow::createNewProfile);
    connect(ui->deleteProfile, &QPushButton::clicked, this, &MainWindow::deleteSelectedProfile);
    connect(ui->Update, &QPushButton::clicked, this, &MainWindow::updateSelectedProfile);

    connect(ui->sliFood, &QAbstractSlider::valueChanged, this, &MainWindow::onFoodSliderChange);
    //settings
    connect(ui->btnOptions, &QPushButton::clicked, this, &MainWindow::onOptionsPress);
    connect(ui->btnOptionsHome, &QPushButton::clicked, this, &MainWindow::onOptionsHome);
    connect(ui->btnOptionsProfiles, &QPushButton::clicked, this, &MainWindow::onOptionsProfile);

    //bolus stuff
    connect(ui->btnBolus, &QPushButton::clicked, this, &MainWindow::onBolusClicked);
    connect(ui->btnBolusBack, &QPushButton::clicked, this, &MainWindow::onBolusCancel);
    connect(ui->btnBolusCalculate, &QPushButton::clicked, this, &MainWindow::onBolusCalculate);
    connect(ui->btnBolusStart, &QPushButton::clicked, this, &MainWindow::onBolusStart);
    connect(ui->btnScanGlucose, &QPushButton::clicked, this, &MainWindow::onBolusScan);
    connect(ui->btnStopBolus, &QPushButton::clicked, this, &MainWindow::onBolusStop);


    // Connect Keyboard Shorcuts
    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+B"), this);
    connect(shortcut, &QShortcut::activated, this, &MainWindow::onCtrlB);

    // Set text box validation (only set text boxes to ints, doubles, etc...)
    // - Manual Bolus Page
    ui->txtBolusInstant->setValidator(new QDoubleValidator(0, 100, 10, this));
    ui->txtBolusLongterm->setValidator(new QDoubleValidator(0, 100, 10, this));
    ui->txtBolusRate->setValidator(new QDoubleValidator(0, 100, 10, this));
    ui->txtGlucoseAmount->setValidator(new QDoubleValidator(0, 100, 10, this));
    ui->txtInsulinAmount->setValidator(new QDoubleValidator(0, 100, 10, this));

    // Generate premade profile
    user->getProfileManager()->createProfile("Regular Use (Pin: 1234)", 0.1f, 10.0f, 1.4f, 1234);
    addProfileToUI("Regular Use (Pin: 1234)");

    // Customize the pen for the series
    QPen pen(Qt::white, 2);
    pen.setStyle(Qt::DotLine); // Make the line dotted
    series->setPen(pen);
    series->setName("current glucose (mmol/L)");

    chart->addSeries(series);
    chart->setTheme(QChart::ChartThemeDark);

    // Setting up the constant lines with explicit axis attachment
    QPen linePen3_9(Qt::red, 2, Qt::SolidLine);
    constantLine3_9->setPen(linePen3_9);
    constantLine3_9->append(0, 3.9);
    constantLine3_9->append(30, 3.9);
    constantLine3_9->setName("min. safe range");
    chart->addSeries(constantLine3_9);

    QPen linePen10(Qt::yellow, 2, Qt::SolidLine);
    constantLine10->setPen(linePen10);
    constantLine10->append(0, 10);
    constantLine10->append(30, 10);
    constantLine10->setName("max. safe range");
    chart->addSeries(constantLine10);

    // Attach the axes to the chart (chart's addAxis)
    chart->addAxis(axisX, Qt::AlignBottom);  // Attach X-axis at the bottom
    chart->addAxis(axisY, Qt::AlignLeft);    // Attach Y-axis on the left

    // Attach the series and constant lines to the axes
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    constantLine3_9->attachAxis(axisX);
    constantLine3_9->attachAxis(axisY);

    constantLine10->attachAxis(axisX);
    constantLine10->attachAxis(axisY);


    axisX->setRange(0, 30); // Adjust according to your needs
    axisX->setLabelsVisible(false);
    axisY->setRange(2, 16); // Explicit range to include your tick points
    axisY->setTickCount(6);  // Sets the number of ticks to be exactly 6
    axisY->setTickInterval(4);  // Sets the interval between ticks to 4 (2, 6, 10, 14, 18, 22)
    axisY->setMinorGridLineVisible(false);



    // Initialize the chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);



    // Ensure the chartContainer has a layout
    if (ui->chartContainer->layout() == nullptr) {
        QVBoxLayout *layout = new QVBoxLayout();
        ui->chartContainer->setLayout(layout);
    }
    ui->chartContainer->layout()->addWidget(chartView);

    ui->stackedWidget->setCurrentWidget(ui->Page1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// MAIN UPDATE FUNCTION
// CALLED EVERY SECOND
void MainWindow::update()
{
    secondsElapsed++;
    // Process components
    device.tick();
    user->simulateGlucose(); // Simulate Glucose

    // Update UI
    float onboard = device.getInsulinOnBoard();
    updateChartData();                                                                          // Chart
    ui->barBattery->setValue(std::ceil(device.getBatteryPercent()));                            // Battery Bar
    ui->lblRemainingBolus->setText((QString::number(device.getBolusBuffer()) + " units"));      // Remaining Bolus
    ui->btnStopBolus->setEnabled(device.getBolusBuffer() > 0);                                  // Cancel Button
    if (onboard > 240) {                                                                        // Insulin Onboard
        ui->lblRemainingOnboard->setText("+240 units");                                         // |
        ui->barOnBoard->setValue(100);                                                          // |
    } else {                                                                                    // |
        ui->lblRemainingOnboard->setText((QString::number(std::floor(onboard)) + " units"));    // |
        ui->barOnBoard->setValue(std::floor(100.00 * onboard / 240.0f));                        // |
    }                                                                                           // |
    ui->lblTime->setText(QString::number(secondsElapsed / 60) + ":" + QString::number(secondsElapsed * 10 % 60)); // Time
}



void MainWindow::on_Start_clicked()
{
  	QRadioButton* selectedButton = qobject_cast<QRadioButton*>(profileGroup->checkedButton());
    if (!selectedButton) {
        QMessageBox::warning(this, "Failed to start", "No profile selected.");
        return;
    }
    QString profileName = selectedButton->text();

    Profile* profile = user->getProfileManager()->getProfile(profileName.toStdString());
    if (!profile) {
        QMessageBox::warning(this, "Failed to start", "Profile not found.");
        return;
    }

    bool ok;
    int enteredPin = QInputDialog::getInt(this, "Enter PIN",
                                          "Enter the 4-digit PIN for profile \"" + profileName + "\":",
                                          0, 0, 9999, 1, &ok);

    if (!ok) return;

    if (enteredPin != profile->pin) {
        QMessageBox::critical(this, "Incorrect PIN", "The entered PIN is incorrect.");
        return;
    }

    // Populate graph with starter values

    device.setSelectedProfile(profile);
    update();
    updateTimer->start(1000);
    hourlyBasalTimer->start(6000);
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_createProfile_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_updateProfile_clicked()
{
    // Get the selected profile
    QRadioButton* selectedButton = qobject_cast<QRadioButton*>(profileGroup->checkedButton());

    if (!selectedButton) {
        QMessageBox::warning(this, "Update Profile", "No profile selected.");
        return;
    }

    QString profileName = selectedButton->text();

    // Fetch the profile from ProfileManager
    Profile* profile = user->getProfileManager()->getProfile(profileName.toStdString());
    if (!profile) {
        QMessageBox::warning(this, "Update Profile", "Profile not found.");
        return;
    }

    ui->ProfileName2->setText(QString::fromStdString(profile->name));
    ui->BasalRates2->setText(QString::number(profile->basalRate));
    ui->Carbohydrate2->setText(QString::number(profile->carbRatio));
    ui->CorrectionFactor2->setText(QString::number(profile->correctionFactor));
    ui->Pin2->setText(QString::number(profile->pin));

    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::createNewProfile() {
    QString name = ui->ProfileName->text();
    double basalRate = ui->BasalRates->text().toDouble();
    double carbRatio = ui->Carbohydrate->text().toDouble();
    double correctionFactor = ui->CorrectionFactor->text().toDouble();
    int pin = ui->Pin->text().toInt();

    if (name.isEmpty() || pin < 1000 || pin >  9999) {
            QMessageBox::warning(this, "Invalid Input", "Please enter valid profile details. PIN must be a 4-digit number.");
            return;
        }

        // Create profile and store it in memory
        user->getProfileManager()->createProfile(name.toStdString(), basalRate, carbRatio, correctionFactor, pin);
        user->getProfileManager()->listProfiles();

        QMessageBox::information(this, "Profile Created", "Profile successfully added!");

        addProfileToUI(name);

        // Clear fields after submission
        ui->ProfileName->clear();
        ui->BasalRates->clear();
        ui->Carbohydrate->clear();
        ui->CorrectionFactor->clear();
        ui->Pin->clear();

        // Navigate back to main screen
        ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::addProfileToUI(const QString& name) {
    QRadioButton* radioButton = new QRadioButton(name, this);
    profileGroup->addButton(radioButton);

    // Add radio button to layout
    ui->profileLayout->addWidget(radioButton);
}


void MainWindow::deleteSelectedProfile() {
    // Get the selected button from the button group
    QRadioButton* selectedButton = qobject_cast<QRadioButton*>(profileGroup->checkedButton());

    if (!selectedButton) {
        QMessageBox::warning(this, "Delete Profile", "No profile selected.");
        return;
    }

    QString profileName = selectedButton->text();

    // Remove profile from ProfileManager
    if (!user->getProfileManager()->deleteProfile(profileName.toStdString())) {
        QMessageBox::warning(this, "Delete Profile", "Failed to delete profile.");
        return;
    }

    // Remove radio button from UI
    profileGroup->removeButton(selectedButton);
    delete selectedButton;  // Remove from memory

    QMessageBox::information(this, "Delete Profile", "Profile deleted successfully!");
}

void MainWindow::updateSelectedProfile() {
    // Get the selected profile
    QRadioButton* selectedButton = qobject_cast<QRadioButton*>(profileGroup->checkedButton());

    if (!selectedButton) {
        QMessageBox::warning(this, "Update Profile", "No profile selected.");
        return;
    }

    QString oldProfileName = selectedButton->text();

    // Fetch the profile from ProfileManager
    Profile* profile = user->getProfileManager()->getProfile(oldProfileName.toStdString());
    if (!profile) {
        QMessageBox::warning(this, "Update Profile", "Profile not found.");
        return;
    }

    // Retrieve updated values from UI fields
    QString newName = ui->ProfileName2->text();
    double basalRate = ui->BasalRates2->text().toDouble();
    double carbRatio = ui->Carbohydrate2->text().toDouble();
    double correctionFactor = ui->CorrectionFactor2->text().toDouble();
    int pin = ui->Pin2->text().toInt();

    if (newName.isEmpty() || pin < 1000 || pin > 9999) {
        QMessageBox::warning(this, "Invalid Input", "Please enter valid profile details. PIN must be a 4-digit number.");
        return;
    }

    // Update the profile in ProfileManager
    if (!user->getProfileManager()->updateProfile(oldProfileName.toStdString(), basalRate, carbRatio, correctionFactor, pin, newName.toStdString())) {
        QMessageBox::warning(this, "Update Profile", "Failed to update profile.");
        return;
    }

    user->getProfileManager()->listProfiles();

    // Update the radio button text
    if (oldProfileName != newName) {
        selectedButton->setText(newName);
    }

    QMessageBox::information(this, "Update Profile", "Profile updated successfully!");

    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::updateChartData() {
    QVector<float> glucoseHistory = user->getGlucoseHistoryTail();

    if (user->foodConsumed == false) {
        ui->EatFood->setEnabled(true);
    }

    // Update the Glucose_tracker label with the new value
    float currentGlucose = user->getCurrentGlucoseLevel(); // Assumes such a getter exists
    ui->Glucose_tracker->setText(QString::number(currentGlucose, 'f', 1));

    // Add new data to the series
    series->append(dataCount++, glucoseHistory.last());

    updateDirection();

    // Keep only the latest 30 data points, scroll X-axis
    if (dataCount > 30) {
        series->remove(0);
        axisX->setMin(axisX->min() + 1);
        axisX->setMax(axisX->max() + 1);
    }

    updateConditionIcon();

    // Update text label (STATE_OUTPUT)
    updateStateOutput();

    // Ensure the constant lines span the full range of the updated axis
    constantLine3_9->clear();
    constantLine3_9->append(axisX->min(), 3.9);
    constantLine3_9->append(axisX->max(), 3.9);

    constantLine10->clear();
    constantLine10->append(axisX->min(), 10);
    constantLine10->append(axisX->max(), 10);
}

void MainWindow::basalDeposit(){
    device.simulateBasal();
}

void MainWindow::setArrowRight() {
    QLabel* arrowLabel = findChild<QLabel*>("ARROW");
    if (arrowLabel) {
        arrowLabel->setText("➔"); // Unicode for right arrow
    }
}

void MainWindow::setArrowUp() {
    QLabel* arrowLabel = findChild<QLabel*>("ARROW");
    if (arrowLabel) {
        arrowLabel->setText("↑"); // Unicode for up arrow
    }
}

void MainWindow::setArrowDown() {
    QLabel* arrowLabel = findChild<QLabel*>("ARROW");
    if (arrowLabel) {
        arrowLabel->setText("↘"); // Unicode for down arrow
    }
}

//Temporary condition will be changed to make work properly
void MainWindow::updateDirection() {
    float currentGlucose = user->getCurrentGlucoseLevel();
    if (currentGlucose > lastGlucose) {
        setArrowUp();
    } else if (currentGlucose < lastGlucose) {
        setArrowDown();
    } else {
        setArrowRight();
    }
    lastGlucose = currentGlucose;
}


void MainWindow::updateConditionIcon()
{
    float currentGlucose = user->getCurrentGlucoseLevel();

    if (currentGlucose <= 3.9f) {
        setIcon(":/Images/Stops.png");
    } else if (currentGlucose > 3.9f && currentGlucose < 6.25f) {
        setIcon(":/Images/Decreases.png");
    } else if (currentGlucose >= 6.25f && currentGlucose < 8.9f) {
        setIcon(":/Images/Maintains.png");
    } else if (currentGlucose >= 8.9f && currentGlucose < 10.0f) {
        setIcon(":/Images/Increases.png");
    } else { // currentGlucose >= 10.0f
        setIcon(":/Images/Delivers.png");
    }
}

void MainWindow::setIcon(const QString &filePath)
{
    QPixmap pixmap(filePath);
    if (!pixmap.isNull()) {
        // Scale to fit the label nicely
        ui->iconLabel->setPixmap(pixmap.scaled(ui->iconLabel->size(),
                                               Qt::KeepAspectRatio,
                                               Qt::SmoothTransformation));
    } else {
        qDebug() << "Failed to load image from:" << filePath;
    }
}

void MainWindow::updateStateOutput()
{
    float currentGlucose = user->getCurrentGlucoseLevel();

    QString stateText;
    QString color; // Use a valid CSS color (hex, named color, etc.)

    if (currentGlucose <= 3.9f) {
        stateText = "Stops";
        color = "#E74C3C"; // red
    } else if (currentGlucose > 3.9f && currentGlucose < 6.25f) {
        stateText = "Decreases";
        color = "#F39C12"; // orange
    } else if (currentGlucose >= 6.25f && currentGlucose < 8.9f) {
        stateText = "Maintains";
        color = "#2E86C1"; // blue (example)
    } else if (currentGlucose >= 8.9f && currentGlucose < 10.0f) {
        stateText = "Increases";
        color = "#6699CC"; // lighter blue (example)
    } else { // currentGlucose >= 10.0f
        stateText = "Delivers";
        color = "#00AEEF"; // another blue shade (example)
    }

    // Find the label named "STATE_OUTPUT" in the UI
    QLabel* stateLabel = findChild<QLabel*>("STATE_OUTPUT");
    if (stateLabel) {
        stateLabel->setText(stateText);
        // Apply color via stylesheet
        QString style = QString("QLabel { color: %1; }").arg(color);
        stateLabel->setStyleSheet(style);
    }
}


void MainWindow::on_EatFood_clicked()
{
    user->eatFood(ui->sliFood->value());
    ui->EatFood->setEnabled(false);
}

void MainWindow::onBolusClicked() {
    ui->stackedWidget->setCurrentWidget(ui->PageBolus);
}

void MainWindow::onBolusCancel() {
    // Go back
    ui->stackedWidget->setCurrentWidget(ui->page4);
    // Clear
    ui->txtBolusInstant->setText("");
    ui->txtBolusLongterm->setText("");
    ui->txtBolusRate->setText("");
    ui->txtInsulinAmount->setText("");
    ui->txtGlucoseAmount->setText("");
}

void MainWindow::onBolusCalculate() {
    QMessageBox startBox;
    startBox.setText("Calculate insulin dose?");
    startBox.setInformativeText("Values in bolus dose will be overwritten with suggested amounts based off input & preferences.");
    startBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
    switch (startBox.exec()) {
    case QMessageBox::Cancel:
        return;
        break;

    case QMessageBox::Ok:
        break;

    default:
        // should not be reached
        break;
    }


    // float glucose = 0;
    float totalInsulin = 0;
    float time = 30.0f; // in seconds. Normally, 3 hours however for demo purposes it has been cut to 30 secs
    bool useCarbs = ui->radUseCarbs->isChecked();
    totalInsulin = ui->txtInsulinAmount->text().toFloat() / (!useCarbs ? 1 : device.getSelectedProfile()->carbRatio);

    totalInsulin += std::min(0.0f, 4.5f - user->getCurrentGlucoseLevel()) / 4.0f;

    // Calculate plan
    float multiplier = ui->radDeliveryImmediate->isChecked() ? 0.6f : 0.4;
    float instant = multiplier * totalInsulin;
    float extended = totalInsulin - instant;
    float rate = extended / time;

    //Set values
    ui->txtBolusInstant->setText(QString::number(std::max(0.0f, instant)));
    ui->txtBolusLongterm->setText(QString::number(std::max(0.0f, extended)));
    ui->txtBolusRate->setText(QString::number(std::max(0.0f, rate)));
}

void MainWindow::onBolusStart() {

    QMessageBox startBox;
    startBox.setText("Start insulin?");
    startBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
    switch (startBox.exec()) {
    case QMessageBox::Cancel:
        return;
        break;

    case QMessageBox::Ok:
        break;

    default:
        // should not be reached
        break;
    }

    // Collect info
    float initial = ui->txtBolusInstant->text().toFloat();
    float longterm = ui->txtBolusLongterm->text().toFloat();
    float rate = ui->txtBolusRate->text().toFloat();

    // Start thingy
    bool started = device.startBolusPlan(initial, longterm, rate);

    if (!started) {
        QMessageBox::warning(this, "Error!", "Not enough insulin on board! Please add more.");
    }


    // Clear and return to home
    onBolusCancel();
}

void MainWindow::onBolusScan() {
    ui->txtGlucoseAmount->setText(QString::number(user->getCurrentGlucoseLevel()));
}

void MainWindow::onBolusStop()
{
    device.cancel();
    ui->btnStopBolus->setEnabled(false);
}

void MainWindow::onOptionsPress()
{
    updateTimer->stop();
    hourlyBasalTimer->stop();
    ui->stackedWidget->setCurrentWidget(ui->PageOptions);
}

void MainWindow::onOptionsHome()
{
    updateTimer->start();
    hourlyBasalTimer->start();
    ui->stackedWidget->setCurrentWidget(ui->page4);
}

void MainWindow::onOptionsProfile()
{
    ui->stackedWidget->setCurrentWidget(ui->Page1);
}

void MainWindow::onFoodSliderChange()
{
    switch (ui->sliFood->value()) {
    case 1:
        ui->lblFood->setText("Snack");
        break;
    case 2:
        ui->lblFood->setText("Meal");
        break;
    case 3:
        ui->lblFood->setText("XL Meal");
        break;
    default:
        break;
    }
}

void MainWindow::onCtrlB()
{
    device.addBattery(1);
}
