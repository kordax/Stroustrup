// Intuit.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	try
	{
		try
		{
			try{ throw 1; }
			catch (float) { cout << "Exception 1"; }
		}
		catch (int){ cout << "Exception 2"; }
	}
	catch (int){ cout << "Exception 3"; }
	return 0;
}