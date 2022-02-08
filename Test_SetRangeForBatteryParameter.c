#include "SetRangeForBatteryParameter.h"
#include "Test_SetRangeForBatteryParameter.h"
#include <assert.h>

void Test_setSafetyRangeforTemperature(float low, float high)
{
	setSafetyRangeforTemperature(low,high);
	assert(Temperature.low == low);
	assert(Temperature.high == high);
}

void Test_setSafetyRangeforStateOfCharge(float low, float high)
{
	setSafetyRangeforStateOfCharge(low,high);
	assert(StateOfCharge.low == low);
	assert(StateOfCharge.high == high);
}

void Test_setThresholdforChargeRate(float limit)
{
	setThresholdforChargeRate(limit);
	assert(ChargeRate.limit  == limit);
}

void Test_SetRangeForBatteryParameter()
{
  /*int (*funp_monitorBatteryParameter[])(float, void (*[])(float, void (*)(float, char*,char*)), void (*)(float, char*,char*)) = {Test_monitorBatteryTemperature,
  	                                              					 							   								 Test_monitorStateOfCharge,
  	                                              					 							   								 Test_monitorChargeRate};
  void (*funp_notifyOutOfRangeForBatteryParameter[])(float, void (*)(float, char*,char*)) = {Test_notifyTemperatureOutofRange, 
  	                                                           								 Test_notifySOCOutofRange, 
  	                                                           								 Test_notifyChargeRateOutofRange};
  void (*funp_printOnConsole)(float, char*,char*) = Test_printOnConsole;*/

  Test_setSafetyRangeforTemperature(0,45);
  Test_setSafetyRangeforStateOfCharge(20,80);
  Test_setThresholdforChargeRate(0.8);
}