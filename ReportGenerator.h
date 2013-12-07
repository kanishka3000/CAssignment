#pragma once
#include <iostream>
#include <string>
#include <list>
#include "ProductItem.h"
#include "Configs.h"
#include "Util.h"
class ReportGenerator
{
public:
	ReportGenerator(void);
	virtual ~ReportGenerator(void);
	static void GenarateReport(list<ProductItem> * pItemList, State* pState);
};
