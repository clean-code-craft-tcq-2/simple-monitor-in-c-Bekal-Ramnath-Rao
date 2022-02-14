#include "WarningBatteryParmeternearOutofRange.h"
#include "SetRangeForBatteryParameter.h"
#include "PrintOnConsole.h"
#include "MessageLanguage.h"

void warningBatteryTempnearOutofRange(float temperature, void (*funp_printOnConsole)(float, char*,char*))
{
	if(temperature > Temperature.highAlert)
	{
		funp_printOnConsole(Temperature.high,parameter[0],warning[0]);
	}
	else if(temperature < Temperature.lowAlert)
	{
		funp_printOnConsole(Temperature.low,parameter[0],warning[1]);
	}
}

void warningBatterySOCnearOutofRange(float soc, void (*funp_printOnConsole)(float, char*,char*))
{
	if(soc > StateOfCharge.highAlert)
	{
		funp_printOnConsole(StateOfCharge.high,parameter[1],warning[0]);
	}
	else if(soc < StateOfCharge.lowAlert)
	{
		funp_printOnConsole(StateOfCharge.low,parameter[1],warning[1]);
	}
}

void warningBatteryChargeRatenearOutofRange(float chargeRate, void (*funp_printOnConsole)(float, char*,char*))
{
	if(chargeRate > StateOfCharge.highAlert)
	{
		funp_printOnConsole(ChargeRate.limit,parameter[2],warning[0]);
	}
}