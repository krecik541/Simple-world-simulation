#include "Para.h"

using namespace std;

bool operator==(Para par1, Para par2)
{
	if (par1.x == par2.x && par1.y == par2.y)
		return true;
	else 
		return false;
}

bool operator!=(Para par1, Para par2)
{
	if (par1.x != par2.x || par1.y != par2.y)
		return true;
	else
		return false;
}