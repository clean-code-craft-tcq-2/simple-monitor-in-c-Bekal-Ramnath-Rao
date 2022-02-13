#include "MonitorBatteryParameter.h"
#include "SetRangeForBatteryParameter.h"
#include "NotifyOutOfRangeforBatteryParameter.h"
#include "PrintOnConsole.h"

int monitorBatteryTemperature(float temperature)
{
	void (*funp_printOnConsole)(float, char*,char*) = printOnConsole;

	if(temperature<Temperature.low || temperature>Temperature.high)
	{
		notifyTemperatureOutofRange(temperature,funp_printOnConsole);
		return 0;
	}
	else
	{
		return 1;
	}
}


int monitorStateOfCharge(float soc)
{
	void (*funp_printOnConsole)(float, char*,char*) = printOnConsole;

	if(soc<StateOfCharge.low || soc>StateOfCharge.high)
	{
		notifySOCOutofRange(soc,funp_printOnConsole);
		return 0;
	}
	else
	{
		return 1;
	}
}

int monitorChargeRate(float chargeRate)
{
	void (*funp_printOnConsole)(float, char*,char*) = printOnConsole;

	if(chargeRate>ChargeRate.limit)
	{
		notifyChargeRateOutofRange(chargeRate,funp_printOnConsole);
		return 0;
	}
	else
	{
		return 1;
	}
}