#include "NotifyOutOfRangeforBatteryParameter.h"
#include "SetRangeForBatteryParameter.h"
#include "PrintOnConsole.h"
#include "MessageLanguage.h"
#include <stdio.h>

#if(LANGUAGE == LANGUAGE_ENGLISH)
char nonsafeCondition[2][30] = {"is Higher than", "is Lower than"};
char parameter_notify[3][30] = {"Temperature","State of Charge","Charge Rate"};
#endif

#if(LANGUAGE == LANGUAGE_GERMAN)
char nonsafeCondition[2][50] = {"ist höher als", "ist niedriger als"};
char parameter_notify[3][50] = {"Temperatur","Ladezustand","Ladestrom"};
#endif

void notifyTemperatureOutofRange(float temperature, void (*funp_printOnConsole)(float, char*,char*))
{
	if(temperature > Temperature.high)
	{
		funp_printOnConsole(Temperature.high,parameter_notify[0],nonsafeCondition[0]);
	}
	else
	{
		funp_printOnConsole(Temperature.low,parameter_notify[0],nonsafeCondition[1]);
	}
}

void notifySOCOutofRange(float soc, void (*funp_printOnConsole)(float, char*,char*))
{
	if(soc > StateOfCharge.high)
	{
		funp_printOnConsole(StateOfCharge.high,parameter_notify[1],nonsafeCondition[0]);
	}
	else
	{
		funp_printOnConsole(StateOfCharge.low,parameter_notify[1],nonsafeCondition[1]);
	}
}

void notifyChargeRateOutofRange(float chargeRate, void (*funp_printOnConsole)(float, char*,char*))
{
	funp_printOnConsole(ChargeRate.limit,parameter_notify[2],nonsafeCondition[0]);
}