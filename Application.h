#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Defs.h"
#include "Configs.h"
#include "ProductItem.h"
#include "ReportGenerator.h"
using namespace std;
class Application
{
public:
	Application(void);
	~Application(void);
	void StartEventLoop();
	
};
