#pragma once
#include <stdbool.h>

#define TYPE_NUMBER 1	// число 
#define TYPE_OPERATOR 0	// оператор + - ...

typedef struct Leksema
{
	char operation;
	double numder;
	bool type;
}Leksema;
