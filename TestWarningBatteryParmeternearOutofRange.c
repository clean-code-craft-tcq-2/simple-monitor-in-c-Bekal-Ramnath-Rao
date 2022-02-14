#include "WarningBatteryParmeternearOutofRange.h"
#include "SetRangeForBatteryParameter.h"
#include "TestWarningBatteryParmeternearOutofRange.h"
#include "MessageLanguage.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

#if(LANGUAGE == LANGUAGE_ENGLISH)

void Test_warningTemperatureprintOnConsole(float parameterLimit, char* parameter,char* nonsafeCondition)
{
	if(parameterLimit == Temperature.high)
	{
		assert(strcmp(parameter,"Temperature")==0);
		assert(strcmp(nonsafeCondition,"is approaching Higher limit")==0);
	}
	else if(parameterLimit == Temperature.low)
	{
		assert(strcmp(parameter,"Temperature")==0);
		assert(strcmp(nonsafeCondition,"is approaching Lower limit")==0);
	}
}


void Test_warningSOCprintOnConsole(float parameterLimit, char* parameter,char* nonsafeCondition)
{
	if(parameterLimit == StateOfCharge.highAlert)
	{
		assert(strcmp(parameter,"State of Charge")==0);
		assert(strcmp(nonsafeCondition,"is approaching Higher limit")==0);
	}
	else if(parameterLimit == StateOfCharge.low)
	{
		assert(strcmp(parameter,"State of Charge")==0);
		assert(strcmp(nonsafeCondition,"is approaching Lower limit")==0);
	}
}

void Test_warningChargeRateprintOnConsole(float parameterLimit, char* parameter,char* nonsafeCondition)
{
	if(parameterLimit == ChargeRate.limit)
	{
		assert(strcmp(parameter,"Charge Rte")==0);
		assert(strcmp(nonsafeCondition,"is approaching Higher limit")==0);
	}
}

#endif

#if(LANGUAGE == LANGUAGE_GERMAN)

void Test_warningTemperatureprintOnConsole(float parameterLimit, char* parameter,char* nonsafeCondition)
{
	if(parameterLimit == Temperature.high)
	{
		assert(strcmp(parameter,"Temperatur")==0);
		assert(strcmp(nonsafeCondition,"nähert sich der höheren Grenze")==0);
	}
	else if(parameterLimit == Temperature.low)
	{
		assert(strcmp(parameter,"Temperatur")==0);
		assert(strcmp(nonsafeCondition,"nähert sich der unteren Grenze")==0);
	}
}


void Test_warningSOCprintOnConsole(float parameterLimit, char* parameter,char* nonsafeCondition)
{
	if(parameterLimit == StateOfCharge.high)
	{
		assert(strcmp(parameter,"Ladezustand")==0);
		assert(strcmp(nonsafeCondition,"nähert sich der höheren Grenze")==0);
	}
	else if(parameterLimit == StateOfCharge.low)
	{
		assert(strcmp(parameter,"Ladezustand")==0);
		assert(strcmp(nonsafeCondition,"nähert sich der unteren Grenze")==0);
	}
}

void Test_warningChargeRateprintOnConsole(float parameterLimit, char* parameter,char* nonsafeCondition)
{
	if(parameterLimit == ChargeRate.limit)
	{
		assert(strcmp(parameter,"Ladestrom")==0);
		assert(strcmp(nonsafeCondition,"nähert sich der höheren Grenze")==0);
	}
}

#endif

void Test_warningBatteryParameternearOutofRange()
{
	void (*funp_printOnConsole[])(float, char*,char*) = {Test_warningTemperatureprintOnConsole,
														 Test_warningSOCprintOnConsole,
														 Test_warningChargeRateprintOnConsole};

	setSafetyRangeforTemperature(0,45);
  	setSafetyRangeforStateOfCharge(20,80);
  	setThresholdforChargeRate(0.8);

  	warningBatteryTempnearOutofRange(25,Test_warningTemperatureprintOnConsole);
  	warningBatteryTempnearOutofRange(0,Test_warningTemperatureprintOnConsole);
  	warningBatteryTempnearOutofRange(45,Test_warningTemperatureprintOnConsole);
  	warningBatteryTempnearOutofRange(55,Test_warningTemperatureprintOnConsole);
  	warningBatteryTempnearOutofRange(-10,Test_warningTemperatureprintOnConsole);
  	warningBatteryTempnearOutofRange(43,Test_warningTemperatureprintOnConsole);
  	warningBatteryTempnearOutofRange(44,Test_warningTemperatureprintOnConsole);
  	warningBatteryTempnearOutofRange(2,Test_warningTemperatureprintOnConsole);
  	warningBatteryTempnearOutofRange(1,Test_warningTemperatureprintOnConsole);

  	warningBatterySOCnearOutofRange(40,Test_warningSOCprintOnConsole);
  	warningBatterySOCnearOutofRange(20,Test_warningSOCprintOnConsole);
  	warningBatterySOCnearOutofRange(80,Test_warningSOCprintOnConsole);
  	warningBatterySOCnearOutofRange(90,Test_warningSOCprintOnConsole);
  	warningBatterySOCnearOutofRange(10,Test_warningSOCprintOnConsole);
  	warningBatterySOCnearOutofRange(21,Test_warningSOCprintOnConsole);
  	warningBatterySOCnearOutofRange(22,Test_warningSOCprintOnConsole);
  	warningBatterySOCnearOutofRange(88,Test_warningSOCprintOnConsole);
  	warningBatterySOCnearOutofRange(89,Test_warningSOCprintOnConsole);

  	warningBatteryChargeRatenearOutofRange(0.4,Test_warningChargeRateprintOnConsole);
  	warningBatteryChargeRatenearOutofRange(0.8,Test_warningChargeRateprintOnConsole);
  	warningBatteryChargeRatenearOutofRange(0.9,Test_warningChargeRateprintOnConsole);
  	warningBatteryChargeRatenearOutofRange(0.0,Test_warningChargeRateprintOnConsole);
  	warningBatteryChargeRatenearOutofRange(0.75,Test_warningChargeRateprintOnConsole);
}