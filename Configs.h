#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "Defs.h"
using namespace std;
class Category
{
public:
	string sName;
	double dTax;
	bool IsTaxExempt();
};
struct Product
{

public:
	string sName;
	Category* p_Category;
};
class State
{
	friend class Configs;
public:
	
	map<string,Product*> map_Products;
	Category* p_GeneralCategory;

	void AddProduct(Product* pProduct);
	Product* GetProduct(string sProduct);
	


private:
	map<string,Category*> map_tmpCatetories;

	//Functions used only for relationship buildup
	void _AddCategory(Category* pCatetory);
	Category* _GetCatetory(string sCategory);
	//Functions used only for relationship buildup


};
struct ConfigItem
{
	string sFirst;
	string sSecond;
	string sThird;
	string sFourth;
};


class Configs
{
public:
	Configs(void);
	~Configs(void);
	void Load();
	map<string,State*> map_State;
	State* GetState(string sState);

private:
	ConfigItem _GetConfigItem(string sLine);
	
};
