#include <assert.h>
#include "CheckIsBatteryOK.h"
#include "SetRangeForBatteryParameter.h"
#include "MonitorBatteryParameter.h"
#include "NotifyOutOfRangeforBatteryParameter.h"
#include "PrintOnConsole.h"
#include "TestfunctionIsBatteryOK.h"

void Test_functionIsBatteryOK()
{
  int (*funp_monitorBatteryParameter[])(float, void (*[])(float, void (*)(float, char*,char*)), void (*)(float, char*,char*)) = {monitorBatteryTemperature,
  	                                              					 							   								 monitorStateOfCharge,
  	                                              					 							   								 monitorChargeRate};
  void (*funp_notifyOutOfRangeForBatteryParameter[])(float, void (*)(float, char*,char*)) = {notifyTemperatureOutofRange, 
  	                                                           								 notifySOCOutofRange, 
  	                                                           								 notifyChargeRateOutofRange};
  void (*funp_printOnConsole)(float, char*,char*) = printOnConsole;

  setSafetyRangeforTemperature(0,45);
  setSafetyRangeforStateOfCharge(20,80);
  setThresholdforChargeRate(0.8);
  assert(batteryIsOk(25, 70, 0.7,funp_monitorBatteryParameter,funp_notifyOutOfRangeForBatteryParameter,funp_printOnConsole));
  assert(!batteryIsOk(50, 85, 0,funp_monitorBatteryParameter,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole));
  assert(!batteryIsOk(50,50,0.5,funp_monitorBatteryParameter,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole));
  assert(!batteryIsOk(40,85,0.5,funp_monitorBatteryParameter,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole));
  assert(!batteryIsOk(40,85,1.0,funp_monitorBatteryParameter,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole));
 }