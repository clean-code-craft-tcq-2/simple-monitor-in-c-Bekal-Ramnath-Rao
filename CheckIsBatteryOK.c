#include "CheckIsBatteryOK.h"
#include "MonitorBatteryParameter.h"

int batteryIsOk(float temperature, float soc, float chargeRate, 
				int (*funp_monitorBatteryParameter[])(float, void (*[])(float, void (*)(float, char*,char*)),void (*)(float, char*,char*)),
				void (*funp_notifyOutOfRangeForBatteryParameter[])(float, void (*)(float, char*,char*)),
				void (*funp_printOnConsole)(float, char*,char*))
{
	return (funp_monitorBatteryParameter[0](temperature,funp_notifyOutOfRangeForBatteryParameter,funp_printOnConsole)&&
		    funp_monitorBatteryParameter[1](soc,funp_notifyOutOfRangeForBatteryParameter,funp_printOnConsole)&&
		    funp_monitorBatteryParameter[2](chargeRate,funp_notifyOutOfRangeForBatteryParameter,funp_printOnConsole));

}