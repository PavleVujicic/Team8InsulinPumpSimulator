#ifndef TEAM8INSULINPUMPSIMULATOR_HISTORYMANAGER_H
#define TEAM8INSULINPUMPSIMULATOR_HISTORYMANAGER_H

#include <QVector>
#include <QString>
class Event {
public:
    int step;
    QString title;
    QString event;
    Event(int s, const QString& t, const QString& e) : step(s), title(t), event(e){}
};

class DataPoint {
public:
    int step;
    float data;
    DataPoint(int s, float d) : step(s), data(d) {}
};

class HistoryManager {
private:
    QVector<Event> events;
    QVector<DataPoint> glucosePoints;
    QVector<DataPoint> insulinPoints;
public:
    struct Data {
        float maxGlucose;
        float minGlucose;
        float averageGlucose;
        float insulinUsed;
    };
    int maxGlucoseStep = 0;
    int maxInsulinStep = 0;
    HistoryManager();
    void addDataPoint(int step, float glucose);
    void addInsulinUse(int step, float amount);
    void addEvent(int step, const QString& title, const QString& text);

    Data getData(int range);
    QVector<Event> getEvents(int range);
};


#endif //TEAM8INSULINPUMPSIMULATOR_HISTORYMANAGER_H
