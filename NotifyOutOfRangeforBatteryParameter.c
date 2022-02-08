#include "NotifyOutOfRangeforBatteryParameter.h"
#include "SetRangeForBatteryParameter.h"
#include "PrintOnConsole.h"

void notifyTemperatureOutofRange(float temperature, void (*funp_printOnConsole)(float, char*,char*))
{
	if(temperature > Temperature.high)
	{
		funp_printOnConsole(Temperature.high,"Temperature","is Higher than");
	}
	else
	{
		funp_printOnConsole(Temperature.low,"Temperature","is Lower than");
	}
}

void notifySOCOutofRange(float soc, void (*funp_printOnConsole)(float, char*,char*))
{
	if(soc > StateOfCharge.high)
	{
		funp_printOnConsole(StateOfCharge.high,"SOC","is Higher than");
	}
	else
	{
		funp_printOnConsole(StateOfCharge.low,"SOC","is Lower than");
	}
}

void notifyChargeRateOutofRange(float chargeRate, void (*funp_printOnConsole)(float, char*,char*))
{
	funp_printOnConsole(ChargeRate.limit,"ChargeRate","is Higher than");
}