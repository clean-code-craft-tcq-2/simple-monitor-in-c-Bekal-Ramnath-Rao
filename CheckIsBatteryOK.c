#include "CheckIsBatteryOK.h"
#include "MonitorBatteryParameter.h"

int batteryIsOk(float temperature, float soc, float chargeRate)
{
	return (monitorBatteryTemperature(temperature)&&
		    monitorStateOfCharge(soc)&&
		    monitorChargeRate(chargeRate));

}