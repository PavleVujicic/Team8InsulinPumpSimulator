//
// Created by akil on 3/29/25.
//

#ifndef BASALMONITOR_H
#define BASALMONITOR_H

class BasalMonitor {
  public:
    BasalMonitor();

    void startBasal(float rate);
    void adjustBasalRate(float cgmReading);
    void suspendIfLowGlucose(float cgmReading);
    void resumeIfSafe(float cgmReading);

  private:
    const float lowGlucoseThreshold = 3.9f;
    const float highGlucoseThreshold = 10.0f;
}

#endif //BASALMONITOR_H
