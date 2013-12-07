#include "Application.h"

Application::Application(void)
{
}

Application::~Application(void)
{
}


void Application::StartEventLoop()
{

	Configs oConfigs;
	oConfigs.Load();
	string sTmp;
	string sState("");
	int iTotalCount = 0;
	string sItemCode("");
	double dPrice(0.0);
	while(true)
	{
		cout << "Please enter a state" << endl;	
		getline(cin,sState);
		cout << sState.c_str() << endl;
		if(sState == "End")
		{
			cout << "End of day" << endl;
			break;
		}

		State* pState = oConfigs.GetState(sState);

		if(!pState)
		{
			cout << "No such state" << endl;
			continue;
		}
		
		int iProductCount = 0;
		list<ProductItem> lstProducts;
		while(true)
		{
			cout << "Enter item name" << endl;
			getline(cin,sItemCode);
			if(sItemCode == "Done")
			{
				break;
			}

			Product* pProduct = pState->GetProduct(sItemCode);
			if(!pProduct)
			{
				cout << "Incorrect product" << endl;
				continue;
			}
			Category* pCategory = pProduct->p_Category;



			ProductItem pProductItem;
			if(pCategory->IsTaxExempt())
			{
				pProductItem.bTaxEmpt = true;
			}

			pProductItem.sItemName = sItemCode;
			cout << "Enter Price" << endl;
			getline(cin,sTmp);
			pProductItem.dPrice = atof(sTmp.c_str());
			cout << "Enter Qty" << endl;
			getline(cin, sTmp);
			pProductItem.iQty = atoi(sTmp.c_str());
			
			lstProducts.push_back(pProductItem);

			iProductCount++;
			if(iProductCount > SAFE_COUNT_ITEM_PER_PERSON)
			{
				break;
			}
		}

		ReportGenerator::GenarateReport(&lstProducts,pState);



	iTotalCount++;
	if (iTotalCount > SAFE_COUNT_TOTAL)
	{
		break;
	}
	}


	


}
