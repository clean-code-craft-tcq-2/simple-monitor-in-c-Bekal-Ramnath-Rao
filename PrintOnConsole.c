#include <stdio.h>
#include "PrintOnConsole.h"

//Adding the Notification Inteface for User to Take Safety Actions
void printOnConsole(float parameterValue, char* parameter,char* nonsafeCondition)
{
	printf("%s is %s than %f\n",parameter,nonsafeCondition,parameterValue);
}