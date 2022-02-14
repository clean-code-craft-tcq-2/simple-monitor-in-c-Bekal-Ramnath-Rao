#include <stdio.h>
#include "PrintOnConsole.h"

//Adding the Notification Inteface for User to Take Safety Actions
void printOnConsole(float parameterLimit, char* parameter,char* nonsafeCondition)
{
	printf("%s %s %f\n",parameter,nonsafeCondition,parameterLimit);
}