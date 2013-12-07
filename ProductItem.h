#pragma once
#include <string>
using namespace std;
class ProductItem
{
public:
	ProductItem(void);
	virtual ~ProductItem(void);
	double dPrice;
	int iQty;
	string sItemName;
	double dTaxPrecentage;
	bool bTaxEmpt;
	double CalculatePrice();

};
