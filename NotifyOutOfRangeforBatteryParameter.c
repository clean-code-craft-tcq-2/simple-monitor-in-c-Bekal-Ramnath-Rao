#include "NotifyOutOfRangeforBatteryParameter.h"
#include "SetRangeForBatteryParameter.h"
#include "PrintOnConsole.h"
#include "MessageLanguage.h"
#include <stdio.h>

void notifyTemperatureOutofRange(float temperature, void (*funp_printOnConsole)(float, char*,char*))
{
	if(temperature > Temperature.high)
	{
		funp_printOnConsole(Temperature.high,parameter[0],nonsafeCondition[0]);
	}
	else
	{
		funp_printOnConsole(Temperature.low,parameter[0],nonsafeCondition[1]);
	}
}

void notifySOCOutofRange(float soc, void (*funp_printOnConsole)(float, char*,char*))
{
	if(soc > StateOfCharge.high)
	{
		funp_printOnConsole(StateOfCharge.high,parameter[1],nonsafeCondition[0]);
	}
	else
	{
		funp_printOnConsole(StateOfCharge.low,parameter[1],nonsafeCondition[1]);
	}
}

void notifyChargeRateOutofRange(float chargeRate, void (*funp_printOnConsole)(float, char*,char*))
{
	funp_printOnConsole(ChargeRate.limit,parameter[2],nonsafeCondition[0]);
}