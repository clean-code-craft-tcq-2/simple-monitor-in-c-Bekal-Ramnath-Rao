#include "TestMonitorBatteryParameter.h"
#include "MonitorBatteryParameter.h"
#include "SetRangeForBatteryParameter.h"
#include "NotifyOutOfRangeforBatteryParameter.h"
#include "PrintOnConsole.h"
#include <assert.h>

void Test_MonitorBatteryParameter()
{
	  void (*funp_notifyOutOfRangeForBatteryParameter[])(float, void (*)(float, char*,char*)) = {notifyTemperatureOutofRange, 
  	                                                           								     notifySOCOutofRange, 
  	                                                           								     notifyChargeRateOutofRange};
 	  void (*funp_printOnConsole)(float, char*,char*) = printOnConsole; 

	  setSafetyRangeforTemperature(0,45);
  	  setSafetyRangeforStateOfCharge(20,80);
  	  setThresholdforChargeRate(0.8);

  	  assert(monitorBatteryTemperature(25,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole));
  	  assert((monitorBatteryTemperature(45,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole)));
  	  assert((monitorBatteryTemperature(0,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole)));
  	  assert(!(monitorBatteryTemperature(55,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole)));

  	  assert((monitorStateOfCharge(40,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole)));
  	  assert((monitorStateOfCharge(20,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole)));
  	  assert((monitorStateOfCharge(80,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole)));
  	  assert(!(monitorStateOfCharge(90,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole)));
  	  assert(!(monitorStateOfCharge(10,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole)));

  	  assert((monitorChargeRate(0.4,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole)));
  	  assert((monitorChargeRate(0.8,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole)));
  	  assert((monitorChargeRate(0.0,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole)));
  	  assert(!(monitorChargeRate(0.9,funp_notifyOutOfRangeForBatteryParameter, funp_printOnConsole)));
}