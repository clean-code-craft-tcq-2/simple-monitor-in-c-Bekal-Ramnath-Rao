#include "WarningBatteryParmeternearOutofRange.h"
#include "SetRangeForBatteryParameter.h"
#include "PrintOnConsole.h"
#include "MessageLanguage.h"

#if(LANGUAGE == LANGUAGE_ENGLISH)
char warning[2][30] = {"is approaching Higher limit","is approaching Lower limit"};
char parameter_warning[3][30] = {"Temperature","State of Charge","Charge Rate"};
#endif

#if(LANGUAGE == LANGUAGE_GERMAN)
char warning[2][50] = {"nähert sich der höheren Grenze","nähert sich der unteren Grenze"};
char parameter_warning[3][50] = {"Temperatur","Ladezustand","Ladestrom"};
#endif

void warningBatteryTempnearOutofRange(float temperature, void (*funp_printOnConsole)(float, char*,char*))
{
	if(temperature > Temperature.highAlert)
	{
		funp_printOnConsole(Temperature.high,parameter_warning[0],warning[0]);
	}
	else if(temperature < Temperature.lowAlert)
	{
		funp_printOnConsole(Temperature.low,parameter_warning[0],warning[1]);
	}
}

void warningBatterySOCnearOutofRange(float soc, void (*funp_printOnConsole)(float, char*,char*))
{
	if(soc > StateOfCharge.highAlert)
	{
		funp_printOnConsole(StateOfCharge.high,parameter_warning[0],warning[0]);
	}
	else if(soc < StateOfCharge.lowAlert)
	{
		funp_printOnConsole(StateOfCharge.low,parameter_warning[0],warning[1]);
	}
}

void warningBatteryChargeRatenearOutofRange(float chargeRate, void (*funp_printOnConsole)(float, char*,char*))
{
	funp_printOnConsole(ChargeRate.limit,parameter_warning[0],warning[0]);
}