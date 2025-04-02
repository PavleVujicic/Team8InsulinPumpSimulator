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
    , constantLine3_9(new QLineSeries(this))
    , constantLine10(new QLineSeries(this))
{
    ui->setupUi(this);
    user = new User();
    lastGlucose = user->getCurrentGlucoseLevel();
    setArrowRight(); // Set the initial arrow direction to right

    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateChartData);
    updateTimer->start(1000);

    // Making Connections
    connect(ui->SubmitForm, &QPushButton::clicked, this, &MainWindow::createNewProfile);
    connect(ui->deleteProfile, &QPushButton::clicked, this, &MainWindow::deleteSelectedProfile);
    connect(ui->Update, &QPushButton::clicked, this, &MainWindow::updateSelectedProfile);




    // Customize the pen for the series
    QPen pen(Qt::white, 2);
    pen.setStyle(Qt::DotLine); // Make the line dotted
    series->setPen(pen);

    chart->addSeries(series);
    chart->setTheme(QChart::ChartThemeDark);

    // Setting up the constant lines with explicit axis attachment
    QPen linePen3_9(Qt::red, 2, Qt::SolidLine);
    constantLine3_9->setPen(linePen3_9);
    constantLine3_9->append(0, 3.9);
    constantLine3_9->append(30, 3.9);
    chart->addSeries(constantLine3_9);
    constantLine3_9->attachAxis(axisX);
    constantLine3_9->attachAxis(axisY);

    QPen linePen10(Qt::yellow, 2, Qt::SolidLine);
    constantLine10->setPen(linePen10);
    constantLine10->append(0, 10);
    constantLine10->append(30, 10);
    chart->addSeries(constantLine10);
    constantLine10->attachAxis(axisX);
    constantLine10->attachAxis(axisY);



    axisX->setRange(0, 30); // Adjust according to your needs
    axisX->setLabelsVisible(false);
    axisY->setRange(2, 22); // Explicit range to include your tick points
    axisY->setTickCount(6);  // Sets the number of ticks to be exactly 6
    axisY->setTickInterval(4);  // Sets the interval between ticks to 4 (2, 6, 10, 14, 18, 22)

    axisY->setMinorGridLineVisible(false);

    chart->setAxisX(axisX, series);
    chart->setAxisY(axisY, series);

    chart->setAxisX(axisX, constantLine3_9);
    chart->setAxisY(axisY, constantLine3_9);
    chart->setAxisX(axisX, constantLine10);
    chart->setAxisY(axisY, constantLine10);


    // Initialize the chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);



    // Ensure the chartContainer has a layout
    if (ui->chartContainer->layout() == nullptr) {
        QVBoxLayout *layout = new QVBoxLayout();
        ui->chartContainer->setLayout(layout);
    }
    ui->chartContainer->layout()->addWidget(chartView);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Start_clicked()
{
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


    // Ensure the constant lines span the full range of the updated axis
    constantLine3_9->clear();
    constantLine3_9->append(axisX->min(), 3.9);
    constantLine3_9->append(axisX->max(), 3.9);

    constantLine10->clear();
    constantLine10->append(axisX->min(), 10);
    constantLine10->append(axisX->max(), 10);
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




