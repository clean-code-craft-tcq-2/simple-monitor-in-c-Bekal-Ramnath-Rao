#include "MessageLanguage.h"

#if(LANGUAGE == LANGUAGE_ENGLISH)
char parameter[3][50] = {"Temperature","State of Charge","Charge Rate"};
char warning[2][50] = {"is approaching Higher limit","is approaching Lower limit"};
char nonsafeCondition[2][50] = {"is Higher than", "is Lower than"};
#endif

#if(LANGUAGE == LANGUAGE_GERMAN)
char parameter[3][50] = {"Temperatur","Ladezustand","Ladestrom"};
char warning[2][50] = {"nähert sich der höheren Grenze","nähert sich der unteren Grenze"};
char nonsafeCondition[2][50] = {"ist höher als", "ist niedriger als"};
#endif

