// Quidsi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Application.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{

	Application oApp;
	oApp.StartEventLoop();

	system("Pause");
	return 0;
}

