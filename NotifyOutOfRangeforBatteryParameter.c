#include "NotifyOutOfRangeforBatteryParameter.h"
#include "SetRangeForBatteryParameter.h"
#include "PrintOnConsole.h"

void notifyTemperatureOutofRange(float temperature, void (*funp_printOnConsole)(float, char*,char*))
{
	if(temperature > Temperature.high)
	{
		funp_printOnConsole(temperature,"Temperature","Higher than");
	}
	else
	{
		funp_printOnConsole(temperature,"Temperature","Lower than");
	}
}

void notifySOCOutofRange(float soc, void (*funp_printOnConsole)(float, char*,char*))
{
	if(soc > StateOfCharge.high)
	{
		funp_printOnConsole(soc,"SOC","Higher than");
	}
	else
	{
		funp_printOnConsole(soc,"SOC","Lower than");
	}
}

void notifyChargeRateOutofRange(float chargeRate, void (*funp_printOnConsole)(float, char*,char*))
{
	funp_printOnConsole(chargeRate,"ChargeRate","is above threshold");
}