
#include<iostream>
#include "AlcoholL.h"
using namespace std;
int main()
{
	AlcoholL a;

	cout << "Alcohol : " << AlcoholL::getCounter() << endl;
	cout << "Alcohol::Liquid : " << AlcoholL::Liquid::getCounter() << endl;
	AlcoholL::Liquid a1;
	cout << "Alcohol::Liquid +1 : " << AlcoholL::Liquid::getCounter() << endl;

	cout << ++a << endl;
	cout << --a << endl;
	cout << a++ << endl;
	cout << a-- << endl;

	cout << " "; cin >> a;
	cout << a << endl;
	a.changeStrength(a.getLiquid());
	cout << a;

	return 0;
}