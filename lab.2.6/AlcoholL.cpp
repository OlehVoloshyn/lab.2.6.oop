#include<iostream>
#include<sstream>
#include "AlcoholL.h"
using namespace std;

int AlcoholL::Liquid::counter = 0;

void AlcoholL::Liquid::Init(string name, double density)
{
	setName(name);
	setDensity(density);
}

void AlcoholL::Liquid::Displey()
{
	cout << endl;
	cout << "name = " << name << endl;
	cout << "density = " << density << endl;
}

void AlcoholL::Liquid::Read()
{
	string name;
	double density;
	cout << endl;
	cout << "name =  "; cin >> name;
	cout << "density =  "; cin >> density;
	Init(name, density);
}

void AlcoholL::Liquid::changeDensity()
{
	double density;
	cout << endl;
	cout << "new density =  "; cin >> density;
	setDensity(density);
}

AlcoholL::Liquid::Liquid(const string name)
	:name(name), density(0)
{
	AlcoholL::Liquid::counter++;
}

AlcoholL::Liquid::Liquid(const double density)
	: name(""), density(density)
{
	AlcoholL::Liquid::counter++;
}

AlcoholL::Liquid::Liquid(const string name, const double density)
	: name(name), density(density)
{
	AlcoholL::Liquid::counter++;
}

AlcoholL::Liquid::Liquid(const Liquid& r)
	: name(r.name), density(r.density)
{
	AlcoholL::Liquid::counter++;
}

AlcoholL::Liquid& AlcoholL::Liquid::operator=(const Liquid& m)
{
	this->name = m.name;
	this->density = m.density;

	return *this;
}

AlcoholL::Liquid::operator string() const
{
	stringstream sout;
	sout << endl;
	sout << "name = " << getName() << endl;
	sout << "density = " << getDensity() << endl;

	return sout.str();
}

AlcoholL::Liquid& AlcoholL::Liquid::operator++()
{
	++density;
	return *this;
}

AlcoholL::Liquid& AlcoholL::Liquid::operator--()
{
	--density;
	return *this;
}

AlcoholL::Liquid AlcoholL::Liquid::operator++(int)
{
	AlcoholL::Liquid t(*this);
	density++;
	return t;

}

AlcoholL::Liquid AlcoholL::Liquid::operator--(int)
{
	AlcoholL::Liquid t(*this);
	density--;
	return t;
}

int AlcoholL::Liquid::getCounter()
{
	return AlcoholL::Liquid::counter;
}

ostream& operator<<(ostream& out, const AlcoholL::Liquid& m)
{
	out << string(m);
	return out;
}

istream& operator>>(istream& in, AlcoholL::Liquid& m)
{
	string name;
	double density;
	cout << endl;
	cout << "name =  "; in >> name;
	cout << "density =  "; in >> density;
	m.setName(name);
	m.setDensity(density);
	return in;
}
//////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& out, const AlcoholL& s)
{
	out << string(s);
	return out;
}
istream& operator>>(istream& in, AlcoholL& s)
{
	double strength;
	cout << endl;
	cout << "liquid =  "; in >> s.liquid;
	cout << "strength =  "; in >> strength;
	s.setSrtength(strength);
	return in;
}

int AlcoholL::counter = 0;

AlcoholL::AlcoholL(const string name, const double density, const double strength)
	:liquid(name, density),strength(strength)
{
	 AlcoholL::counter++;
}

AlcoholL::AlcoholL(const AlcoholL& s)
{
	liquid = s.liquid;
	strength = s.strength;
	AlcoholL::counter++;
}

void AlcoholL::Init(Liquid liquid, double strength)
{
	setLiquid(liquid);
	setSrtength(strength);
}

void AlcoholL::Display() 
{
	cout << endl;
	cout << "Liquid = " << endl;
	liquid.Displey();
	cout << "strength = " << strength << endl;
}

void AlcoholL::Read()
{
	double strength;
	Liquid l;
	cout << endl;
	cout << "Liquid =  " << endl;
	l.Read();
	cout << "strength =  "; cin >> strength;
	Init(l, strength);
}

void AlcoholL::changeStrength(Liquid l)
{
	double strength;
	cout << endl;
	l.changeDensity();
	cout << "new strength = "; cin >> strength;
	Init(l, strength);
}

AlcoholL& AlcoholL::operator=(const AlcoholL& s)
{
	liquid = s.liquid;
	strength = s.strength;

	return *this;
}

AlcoholL::operator string() const
{
	stringstream ss;
	ss << "strength = " << strength << endl;
	return string(liquid) + ss.str();

}

AlcoholL& AlcoholL::operator++()
{
	++liquid;
	return *this;

}

AlcoholL& AlcoholL::operator--()
{
	++liquid;
	return *this;

}

AlcoholL AlcoholL::operator++(int)
{
	AlcoholL s(*this);
	liquid++;
	return s;

}

AlcoholL AlcoholL::operator--(int)
{
	AlcoholL s(*this);
	liquid--;
	return s;
}

int AlcoholL::getCounter()
{
	return AlcoholL::counter;
}

