#include "Configs.h"

Configs::Configs(void)
{
}

Configs::~Configs(void)
{
	
}
ConfigItem Configs::_GetConfigItem(string sLine)
{
	ConfigItem oItem;
	char* pch;
	pch = strtok(const_cast<char*>(sLine.c_str()), ",");
	
	oItem.sFirst = pch;
	pch = strtok(NULL, ",");
	oItem.sSecond = pch;
	pch = strtok(NULL, ",");
	oItem.sThird = pch;
	return oItem;
	
}
State* Configs::GetState(string sState)
{
	map<string,State*>::iterator itr = map_State.find(sState);
	if(itr == map_State.end())
	{
		return NULL;
	}
	return itr->second;
}

void Configs::Load()
{

	string sLine;
	ifstream oConfig(TAX_CONFIG);
	
	if(!oConfig.is_open())
	{
		cout << "Unable to open file" << endl;
		return;
	}
	//temporaraly build the category map to build the relationship between, item and category
	while(getline(oConfig,sLine))
	{
		ConfigItem oItem = _GetConfigItem(sLine);
		Category* pCategory = new Category;
		pCategory->sName = oItem.sSecond;
		pCategory->dTax = atof(oItem.sThird.c_str());
		map<string,State*>::iterator itr = map_State.find(oItem.sFirst);
		State* pState = NULL;

		if(itr == map_State.end())
		{
			pState = new State;
			map_State[oItem.sFirst] = pState;
		}
		else
		{
			pState = itr->second;
		}
		if(oItem.sSecond == "Gen")
		{
			pState->p_GeneralCategory = pCategory;

		}
		pState->_AddCategory(pCategory);
	}
	oConfig.close();


	ifstream oConfig_Itm(ITEM_CONFIG);
	 
	if(!oConfig_Itm.is_open())
	{
		cout << "Unable to open file" << endl;
		return;
	}

	while(getline(oConfig_Itm,sLine))
	{
		ConfigItem oItem = _GetConfigItem(sLine);
		State* pState = map_State[oItem.sFirst];
		
		if(!pState)
			return;
		Category* pCategory = pState->_GetCatetory(oItem.sThird);

		Product* pProduct = new Product;
		pProduct->p_Category = pCategory;
		pProduct->sName = oItem.sSecond;

		pState->AddProduct(pProduct);


	}
	oConfig_Itm.close();
}

void State::AddProduct( Product* pProduct )
{
	map_Products[pProduct->sName] = pProduct;
}

Product* State::GetProduct( string sProduct )
{
	map<string,Product*>::iterator itr = map_Products.find(sProduct);
	if(itr != map_Products.end())
	{
		return itr->second;
	}
	return NULL;
}

void State::_AddCategory( Category* pCatetory )
{
	map_tmpCatetories[pCatetory->sName] =  pCatetory;
}

Category* State::_GetCatetory( string sCategory )
{
	map<string,Category*>::iterator itr = map_tmpCatetories.find(sCategory);
	if(itr != map_tmpCatetories.end())
	{
		return itr->second;
	}
	else
	{
		return p_GeneralCategory;
	}
}

bool Category::IsTaxExempt()
{
	if(dTax == 0.0)
	{
		return true;
	}
	return false;
}
