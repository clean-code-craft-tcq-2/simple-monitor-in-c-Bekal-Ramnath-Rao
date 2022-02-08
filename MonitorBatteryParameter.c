#include "MonitorBatteryParameter.h"
#include "SetRangeForBatteryParameter.h"
#include "NotifyOutOfRangeforBatteryParameter.h"

int monitorBatteryTemperature(float temperature, 
	    					  void (*funp_notifyOutOfRangeForBatteryParameter[])(float, void (*)(float, char*,char*)), 
	    					  void (*funp_printOnConsole)(float, char*,char*))
{
	if(temperature<Temperature.low || temperature>Temperature.high)
	{
		funp_notifyOutOfRangeForBatteryParameter[0](temperature,funp_printOnConsole);
		return 0;
	}
	else
	{
		return 1;
	}
}


int monitorStateOfCharge(float soc, 
	                     void (*funp_notifyOutOfRangeForBatteryParameter[])(float, void (*)(float, char*,char*)), 
	                     void (*funp_printOnConsole)(float, char*,char*))
{
	if(soc<StateOfCharge.low || soc>StateOfCharge.high)
	{
		funp_notifyOutOfRangeForBatteryParameter[1](soc,funp_printOnConsole);
		return 0;
	}
	else
	{
		return 1;
	}
}

int monitorChargeRate(float chargeRate, 
					  void (*funp_notifyOutOfRangeForBatteryParameter[])(float, void (*)(float, char*,char*)), 
					  void (*funp_printOnConsole)(float, char*,char*))
{
	if(chargeRate>ChargeRate.limit)
	{
		funp_notifyOutOfRangeForBatteryParameter[2](chargeRate,funp_printOnConsole);
		return 0;
	}
	else
	{
		return 1;
	}
}