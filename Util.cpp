#include "Util.h"

Util::Util(void)
{
}

Util::~Util(void)
{
}

double Util::Round( double dRound )
{
	dRound = (dRound * 10) * 2;
	dRound = ceil(dRound);
	dRound = dRound/ ( 2 * 10);
	return dRound;
}
