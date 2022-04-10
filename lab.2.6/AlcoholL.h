#include<iostream>
#include<string>
#pragma once
using namespace std;
class AlcoholL
{
private:
	double strength;
	static int counter;
public:
	class Liquid
	{
	private:
		string name;
		double density;
		static int counter;
	public:
		string getName() const { return name; }
		double getDensity() const { return density; }

		void setName(string name) { this->name = name; }
		void setDensity(double density) { this->density = density; }

		void Init(string name, double density);
		void Displey();
		void Read();
		void changeDensity();

		Liquid() :name(""), density(0) { AlcoholL::Liquid::counter++; };
		Liquid(const string name);
		Liquid(const double density);
		Liquid(const string name, const double density);
		Liquid(const Liquid& m);
		~Liquid(void){ AlcoholL::Liquid::counter--; };

		Liquid& operator = (const Liquid& m);

		friend ostream& operator << (ostream& out, const Liquid& m);
		friend istream& operator >> (istream& in, Liquid& m);

		operator string () const;

		Liquid& operator ++ ();
		Liquid& operator -- ();
		Liquid operator ++ (int);
		Liquid operator -- (int);

		static int getCounter();
	};
	
	Liquid getLiquid() { return liquid; }
	double getStrength() { return strength; }

	void setLiquid(Liquid liquid) { this->liquid = liquid; }
	void setSrtength(double strength) { this->strength = strength; }

	AlcoholL() :liquid("", 0), strength(0) { AlcoholL::counter++; };
	AlcoholL(const string name , const double density, const double strength );
	AlcoholL(const AlcoholL& s);

	void Init(Liquid liquid, double strength);
	void Display() ;
	void Read();
	void changeStrength(Liquid l);

	AlcoholL& operator = (const AlcoholL& s);

	friend ostream& operator << (ostream& out, const AlcoholL& s);
	friend istream& operator >> (istream& in, AlcoholL& s);

	operator string () const;

	AlcoholL& operator ++ ();
	AlcoholL& operator -- ();
	AlcoholL operator ++ (int);
	AlcoholL operator -- (int);
	~AlcoholL(void) { AlcoholL::counter--; };
	static int getCounter();
private:
	Liquid liquid;
};

