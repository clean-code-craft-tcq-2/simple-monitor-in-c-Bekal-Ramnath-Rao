#include "NotifyOutOfRangeforBatteryParameter.h"
#include "SetRangeForBatteryParameter.h"
#include "PrintOnConsole.h"

void notifyTemperatureOutofRange(float temperature, void (*funp_printOnConsole)(float, char*,char*))
{
	if(temperature > Temperature.high)
	{
		funp_printOnConsole(temperature,"Temperature","is Higher than");
	}
	else
	{
		funp_printOnConsole(temperature,"Temperature","is Lower than");
	}
}

void notifySOCOutofRange(float soc, void (*funp_printOnConsole)(float, char*,char*))
{
	if(soc > StateOfCharge.high)
	{
		funp_printOnConsole(soc,"SOC","is Higher than");
	}
	else
	{
		funp_printOnConsole(soc,"SOC","is Lower than");
	}
}

void notifyChargeRateOutofRange(float chargeRate, void (*funp_printOnConsole)(float, char*,char*))
{
	funp_printOnConsole(chargeRate,"ChargeRate","is Higher than");
}