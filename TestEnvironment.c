#include "TestEnvironment.h"
#include "TestSetRangeForBatteryParameter.h"
#include "TestNotifyOutOfRangeforBatteryParameter.h"
#include "TestMonitorBatteryParameter.h"
#include "TestfunctionIsBatteryOK.h"
#include "TestWarningBatteryParmeternearOutofRange.h"

void Test_Environment()
{
	Test_SetRangeForBatteryParameter();

	Test_NotifyOutOfRangeforBatteryParameter();

	Test_warningBatteryParameternearOutofRange();

	Test_MonitorBatteryParameter();

	Test_functionIsBatteryOK();
}