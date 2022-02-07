#include "NotifyOutOfRangeforBatteryParameter.h"
#include "SetRangeForBatteryParameter.h"
#include "PrintOnConsole.h"

void notifyTemperatureOutofRange(float temperature)
{
	if(temperature > Temperature.high)
	{
		printOnConsole(temperature,"Temperature","Higher than");
	}
	else
	{
		printOnConsole(temperature,"Temperature","Lower than");
	}
}

void notifySOCOutofRange(float soc)
{
	if(soc > StateOfCharge.high)
	{
		printOnConsole(soc,"SOC","Higher than");
	}
	else
	{
		printOnConsole(soc,"SOC","Lower than");
	}
}

void notifyChargeRateOutofRange(float chargeRate)
{
	printOnConsole(chargeRate,"ChargeRate","is above threshold");
}