#include "historymanager.h"
#include <algorithm>

HistoryManager::HistoryManager() {
    events = QVector<Event>();
    glucosePoints = QVector<DataPoint>();
    insulinPoints = QVector<DataPoint>();
}

void HistoryManager::addDataPoint(int step, float glucose) {
    glucosePoints.push_back(DataPoint(step, glucose));
    if (step > maxGlucoseStep) maxGlucoseStep = step;
}

void HistoryManager::addEvent(int step, const QString &title, const QString &text) {
    events.push_back(Event(step, title, text));
}

void HistoryManager::addInsulinUse(int step, float amount) {
    insulinPoints.push_back(DataPoint(step, amount));
    if (step > maxInsulinStep) maxInsulinStep = step;
}

HistoryManager::Data HistoryManager::getData(int range) {
    float total = 0;
    int count = 0;
    float min = -1;
    float max = -1;
    for (DataPoint d: glucosePoints) {
        if (d.step >= maxGlucoseStep - range || range == -1) {
            if (min == -1 || d.data < min) min = d.data;
            if (max == -1 || d.data > max) max = d.data;
            total += d.data;
            count++;
        }
    }
    float totalInsulin = 0;
    for (DataPoint d: insulinPoints) {
        if (d.step >= maxInsulinStep - range || range == -1) {
            totalInsulin += d.data;
        }
    }
    Data out;
    out.averageGlucose = total / (float) count;
    out.maxGlucose = max;
    out.minGlucose = min;
    out.insulinUsed = totalInsulin;
    return out;
}

QVector<Event> HistoryManager::getEvents(int range) {
    QVector<Event> out;
    for (Event e: events) {
        if (e.step <= range || range == -1) {
            out.push_back(e);
        }
    }
    std::sort(events.begin(), events.end(), [] (Event a, Event b) { return a.step < b.step; });
    return out;
}
