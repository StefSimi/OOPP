#include "IDGenerator.h"

IDGenerator::IDGenerator():next_id(0)
{
}

int IDGenerator::getNextID()
{
	return next_id++;
}
