#include "NotifyOutOfRangeforBatteryParameter.h"
#include "SetRangeForBatteryParameter.h"
#include "TestNotifyOutOfRangeforBatteryParameter.h"
#include <assert.h>
#include <string.h>

void Test_TemperatureprintOnConsole(float parameterValue, char* parameter,char* nonsafeCondition)
{
	if(parameterValue > Temperature.high)
	{
		assert(strcmp(parameter,"Temperature")==0);
		assert(strcmp(nonsafeCondition,"is Higher than")==0);
	}
	else if(parameterValue < Temperature.low)
	{
		assert(strcmp(parameter,"Temperature")==0);
		assert(strcmp(nonsafeCondition,"is Lower than")==0);
	}
}


void Test_SOCprintOnConsole(float parameterValue, char* parameter,char* nonsafeCondition)
{
	if(parameterValue > StateOfCharge.high)
	{
		assert(strcmp(parameter,"SOC")==0);
		assert(strcmp(nonsafeCondition,"is Higher than")==0);
	}
	else if(parameterValue < StateOfCharge.low)
	{
		assert(strcmp(parameter,"SOC")==0);
		assert(strcmp(nonsafeCondition,"is Lower than")==0);
	}
}

void Test_ChargeRateprintOnConsole(float parameterValue, char* parameter,char* nonsafeCondition)
{
	if(parameterValue > ChargeRate.limit)
	{
		assert(strcmp(parameter,"ChargeRate")==0);
		assert(strcmp(nonsafeCondition,"is Higher than")==0);
	}
}

void Test_NotifyOutOfRangeforBatteryParameter()
{
	void (*funp_printOnConsole[])(float, char*,char*) = {Test_TemperatureprintOnConsole,
														 Test_SOCprintOnConsole,
														 Test_ChargeRateprintOnConsole};

	setSafetyRangeforTemperature(0,45);
  	setSafetyRangeforStateOfCharge(20,80);
  	setThresholdforChargeRate(0.8);

  	notifyTemperatureOutofRange(25,Test_TemperatureprintOnConsole);
  	notifyTemperatureOutofRange(0,Test_TemperatureprintOnConsole);
  	notifyTemperatureOutofRange(45,Test_TemperatureprintOnConsole);
  	notifyTemperatureOutofRange(55,Test_TemperatureprintOnConsole);
  	notifyTemperatureOutofRange(-10,Test_TemperatureprintOnConsole);

  	notifySOCOutofRange(40,Test_SOCprintOnConsole);
  	notifySOCOutofRange(20,Test_SOCprintOnConsole);
  	notifySOCOutofRange(80,Test_SOCprintOnConsole);
  	notifySOCOutofRange(90,Test_SOCprintOnConsole);
  	notifySOCOutofRange(10,Test_SOCprintOnConsole);

  	notifyChargeRateOutofRange(0.4,Test_ChargeRateprintOnConsole);
  	notifyChargeRateOutofRange(0.8,Test_ChargeRateprintOnConsole);
  	notifyChargeRateOutofRange(0.9,Test_ChargeRateprintOnConsole);
  	notifyChargeRateOutofRange(0.0,Test_ChargeRateprintOnConsole);
}