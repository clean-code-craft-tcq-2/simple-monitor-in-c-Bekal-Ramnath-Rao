#include "MonitorBatteryParameter.h"
#include "SetRangeForBatteryParameter.h"
#include "NotifyOutOfRangeforBatteryParameter.h"

int monitorBatteryTemperature(float temperature)
{
	if(temperature<Temperature.low || temperature>Temperature.high)
	{
		notifyTemperatureOutofRange(temperature);
		return 0;
	}
	else
	{
		return 1;
	}
}


int monitorStateOfCharge(float soc)
{
	if(soc<StateOfCharge.low || soc>StateOfCharge.high)
	{
		notifySOCOutofRange(soc);
		return 0;
	}
	else
	{
		return 1;
	}
}

int monitorChargeRate(float chargeRate)
{
	if(chargeRate>ChargeRate.limit)
	{
		notifyChargeRateOutofRange(chargeRate);
		return 0;
	}
	else
	{
		return 1;
	}
}