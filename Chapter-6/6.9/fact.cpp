#include"Chapter6.h"
int fact (int x)
{
	int value = 1;
	for ( ; x > 1; --x)
		value *= x;
	return value; 
}
