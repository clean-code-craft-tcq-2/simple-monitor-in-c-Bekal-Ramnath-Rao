#include "TestEnvironment.h"
#include "TestSetRangeForBatteryParameter.h"
#include "TestNotifyOutOfRangeforBatteryParameter.h"
#include "TestMonitorBatteryParameter.h"
#include "TestfunctionIsBatteryOK.h"

void Test_Environment()
{
	Test_SetRangeForBatteryParameter();

	Test_NotifyOutOfRangeforBatteryParameter();

	Test_MonitorBatteryParameter();

	Test_functionIsBatteryOK();
}