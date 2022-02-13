#include "TestMonitorBatteryParameter.h"
#include "MonitorBatteryParameter.h"
#include "SetRangeForBatteryParameter.h"
#include "NotifyOutOfRangeforBatteryParameter.h"
#include "PrintOnConsole.h"
#include <assert.h>

void Test_MonitorBatteryParameter()
{
	  setSafetyRangeforTemperature(0,45);
  	setSafetyRangeforStateOfCharge(20,80);
  	setThresholdforChargeRate(0.8);

	  assert(monitorBatteryTemperature(25));
	  assert(monitorBatteryTemperature(45));
	  assert(monitorBatteryTemperature(0));
	  assert(!(monitorBatteryTemperature(55)));

	  assert(monitorStateOfCharge(40));
	  assert(monitorStateOfCharge(20));
	  assert(monitorStateOfCharge(80));
	  assert(!(monitorStateOfCharge(90)));
	  assert(!(monitorStateOfCharge(10)));

	  assert(monitorChargeRate(0.4));
	  assert(monitorChargeRate(0.8));
	  assert(monitorChargeRate(0.0));
	  assert(!(monitorChargeRate(0.9)));
}