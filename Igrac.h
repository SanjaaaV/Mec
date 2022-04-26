#ifndef _Igrac_h_
#define _Igrac_h_
#include <string>
#include <iostream>

using namespace std;

class Igrac{
	string imeIgraca;
	int vrednostIgraca;

public:
	Igrac(string ime, int vrednost=1000):imeIgraca(ime), vrednostIgraca(vrednost){}
	Igrac() = default;

	string dohvImeIgraca()const { return imeIgraca; }
	int dohvVrednostIgraca()const { return vrednostIgraca; }

	friend bool operator== (const Igrac & i1, const Igrac & i2);
	Igrac& povecajSmanji(double procenat);
	

	friend ostream& operator<<(ostream& os, const Igrac& i);

};

#endif