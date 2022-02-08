#include "TestEnvironment.h"
#include "Test_SetRangeForBatteryParameter.h"
#include "TestNotifyOutOfRangeforBatteryParameter.h"

void Test_Environment()
{
	Test_SetRangeForBatteryParameter();

	Test_NotifyOutOfRangeforBatteryParameter();
}