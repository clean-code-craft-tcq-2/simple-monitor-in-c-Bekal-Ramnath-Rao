#include <assert.h>
#include "CheckIsBatteryOK.h"
#include "SetRangeForBatteryParameter.h"
#include "MonitorBatteryParameter.h"
#include "NotifyOutOfRangeforBatteryParameter.h"
#include "PrintOnConsole.h"
#include "TestfunctionIsBatteryOK.h"

void Test_functionIsBatteryOK()
{
  setSafetyRangeforTemperature(0,45);
  setSafetyRangeforStateOfCharge(20,80);
  setThresholdforChargeRate(0.8);
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(50,50,0.5));
  assert(!batteryIsOk(40,85,0.5));
  assert(!batteryIsOk(40,85,1.0));
 }