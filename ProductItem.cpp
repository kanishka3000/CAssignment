#include "ProductItem.h"

ProductItem::ProductItem(void):
dPrice(0.0),iQty(0),sItemName(""),dTaxPrecentage(0.0),bTaxEmpt(false)
{
}

ProductItem::~ProductItem(void)
{
}
double ProductItem::CalculatePrice()
{
	return (dPrice * iQty);

	
}
