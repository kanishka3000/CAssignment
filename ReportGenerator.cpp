#include "ReportGenerator.h"

ReportGenerator::ReportGenerator(void)
{
}

ReportGenerator::~ReportGenerator(void)
{
}

void ReportGenerator::GenarateReport(list<ProductItem> * pItemList, State* pState)
{

	cout << "Item          Price      Qty" << endl;
	double dTaxablePrice = 0.0;
	double dNonTaxablePrice = 0.0;
	double dTotalTax = 0.0;
	for(list<ProductItem>::iterator itr = pItemList->begin(); itr != pItemList->end(); itr++)
	{
		ProductItem pItem = *itr;

		double dPrice;
		dPrice = pItem.CalculatePrice();
		if(!pItem.bTaxEmpt)
		{
			dTaxablePrice+= dPrice;
		}
		else
		{
			dNonTaxablePrice+= dPrice;
		}


		printf("%15s $%.2f    %d \n", pItem.sItemName.c_str(), pItem.dPrice,pItem.iQty);
	}

	dTotalTax = dTaxablePrice * (pState->p_GeneralCategory->dTax) / 100;
	dTotalTax = Util::Round(dTotalTax);
	double dTotalPrice = dTaxablePrice + dNonTaxablePrice;
	dTotalPrice = Util::Round(dTotalPrice);
	printf("Subtotal:    %.2f\n",dTotalPrice);
	printf("Tax:         %2.f\n", dTotalTax);
	double dTotal = dTotalPrice + dTotalTax;
	dTotal = Util::Round(dTotal);
	printf("Total:       %.2f\n",dTotal);

}
