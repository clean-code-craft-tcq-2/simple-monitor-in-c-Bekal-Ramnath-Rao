#include "WarningBatteryParmeternearOutofRange.h"
#include "SetRangeForBatteryParameter.h"
#include "PrintOnConsole.h"

void warningBatteryTempnearOutofRange(float temperature, void (*funp_printOnConsole)(float, char*,char*))
{
	if(temperature > Temperature.highAlert)
	{
		funp_printOnConsole(Temperature.high,"Temperature","is approaching Higher limit");
	}
	else
	{
		funp_printOnConsole(Temperature.low,"Temperature","is approaching Lower limit");
	}
}

void warningBatterySOCnearOutofRange(float soc, void (*funp_printOnConsole)(float, char*,char*))
{
	if(soc > StateOfCharge.highAlert)
	{
		funp_printOnConsole(StateOfCharge.high,"SOC","is approaching Higher limit");
	}
	else
	{
		funp_printOnConsole(StateOfCharge.low,"SOC","is approaching Lower limit");
	}
}

void warningBatteryChargeRatenearOutofRange(float chargeRate, void (*funp_printOnConsole)(float, char*,char*))
{
	funp_printOnConsole(ChargeRate.limit,"ChargeRate","is approaching Higher limit");
}