#include <stdio.h>
#include <assert.h>
#include "CheckIsBatteryOK.h"
#include "SetRangeForBatteryParameter.h"

int main() {
  setSafetyRangeforTemperature(0,45);
  setSafetyRangeforStateOfCharge(20,80);
  setThresholdforChargeRate(0.8);
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(50,50,0.5));
  assert(!batteryIsOk(40,85,0.5));
  assert(!batteryIsOk(40,85,1.0));
}
