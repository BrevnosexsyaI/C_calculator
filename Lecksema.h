#pragma once
#include <stdbool.h>

#define TYPE_NUMBER 1
#define TYPE_OPERATOR 0

typedef struct Leksema
{
	char operation;
	double numder;
	bool type;
}Leksema;
