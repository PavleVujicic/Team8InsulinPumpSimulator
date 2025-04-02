#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , profileGroup(new QButtonGroup(this))
    , series(new QLineSeries(this))
    , chart(new QChart())
    , axisX(new QValueAxis())
    , axisY(new QValueAxis())
{
    ui->setupUi(this);
    user = new User();

    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::update);

    // Making Connections
    connect(ui->SubmitForm, &QPushButton::clicked, this, &MainWindow::createNewProfile);
    connect(ui->deleteProfile, &QPushButton::clicked, this, &MainWindow::deleteSelectedProfile);
    connect(ui->Update, &QPushButton::clicked, this, &MainWindow::updateSelectedProfile);
    connect(ui->toolButton_2, &QPushButton::clicked, this, &MainWindow::onBolusClicked);
    connect(ui->btnBolusBack, &QPushButton::clicked, this, &MainWindow::onBolusCancel);
    connect(ui->btnBolusCalculate, &QPushButton::clicked, this, &MainWindow::onBolusCalculate);
    connect(ui->btnBolusStart, &QPushButton::clicked, this, &MainWindow::onBolusStart);
    connect(ui->btnScanGlucose, &QPushButton::clicked, this, &MainWindow::onBolusScan);
    connect(ui->btnStopBolus, &QPushButton::clicked, this, &MainWindow::onBolusStop);


    // Connect Keyboard Shorcuts
    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+B"), this);
    connect(shortcut, &QShortcut::activated, this, &MainWindow::onCtrlB);

    // Customize the pen for the series
    QPen pen(Qt::white, 2);
    pen.setStyle(Qt::DotLine); // Make the line dotted
    series->setPen(pen);

    chart->addSeries(series);
    chart->setTheme(QChart::ChartThemeDark);




    axisX->setRange(0, 30); // Adjust according to your needs
    axisY->setRange(2, 22); // Explicit range to include your tick points
    axisY->setTickCount(6);  // Sets the number of ticks to be exactly 6
    axisY->setTickInterval(4);  // Sets the interval between ticks to 4 (2, 6, 10, 14, 18, 22)
    chart->setAxisX(axisX, series);
    chart->setAxisY(axisY, series);


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
    // Process components
    device.tick();

    // Update UI
    updateChartData();
    ui->barBattery->setValue(std::ceil(device.getBatteryPercent()));
    ui->lblRemainingBolus->setText((QString::number(device.getBolusBuffer()) + " units"));
    ui->lblRemainingOnboard->setText((QString::number(device.getInsulinOnBoard()) + " units"));
    ui->btnStopBolus->setEnabled(device.getBolusBuffer() > 0);
}

void MainWindow::on_Start_clicked()
{
    update();
    updateTimer->start(1000);
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
    Profile* profile = profileManager.getProfile(profileName.toStdString());
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
        profileManager.createProfile(name.toStdString(), basalRate, carbRatio, correctionFactor, pin);
        profileManager.listProfiles();

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
    if (!profileManager.deleteProfile(profileName.toStdString())) {
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
    Profile* profile = profileManager.getProfile(oldProfileName.toStdString());
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
    if (!profileManager.updateProfile(oldProfileName.toStdString(), basalRate, carbRatio, correctionFactor, pin, newName.toStdString())) {
        QMessageBox::warning(this, "Update Profile", "Failed to update profile.");
        return;
    }

    profileManager.listProfiles();

    // Update the radio button text
    if (oldProfileName != newName) {
        selectedButton->setText(newName);
    }

    QMessageBox::information(this, "Update Profile", "Profile updated successfully!");

    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::updateChartData() {
    user->simulateGlucose(); // Simulate data change
    QVector<float> glucoseHistory = user->getGlucoseHistoryTail();

    // Add new data to the series
    series->append(dataCount++, glucoseHistory.last());

    // Keep only the latest 30 data points, scroll X-axis
    if (dataCount > 30) {
        series->remove(0);
        axisX->setMin(axisX->min() + 1);
        axisX->setMax(axisX->max() + 1);
    }
}


void MainWindow::onBolusClicked() {
    ui->stackedWidget->setCurrentWidget(ui->PageBolus);
    // Check User Info and populate

}

void MainWindow::onBolusCancel() {
    ui->stackedWidget->setCurrentWidget(ui->page4);
}

void MainWindow::onBolusCalculate() {
    float glucose = 0;
    float carbs = 0;
    bool useCarbs = ui->radUseCarbs->isChecked();
    carbs = ui->txtInsulinAmount->text().toFloat() * (useCarbs ? 1 : 10.0f); // TODO: Replace 10.0f with current profile carb ratio


    // BolusResult br = BolusCalculator.calculateBolus(glucose, cabrs);

    // Send br for bolus delivery

    // Update br
}

void MainWindow::onBolusStart() {
    // TODO: implement
}

void MainWindow::onBolusScan() {
    ui->txtGlucoseAmount->setText(QString::number(user->getCurrentGlucoseLevel()));
}

void MainWindow::onBolusStop()
{
    device.cancel();
    ui->btnStopBolus->setEnabled(false);
}

void MainWindow::onCtrlB()
{
    device.addBattery(1);
}
