#ifndef _Tim_h_
#define _Tim_h_
#include "Igrac.h"
#include <exception>

class GIndeks :public exception {
public:
	const char* what()const {
		return "Greska u indeksu!";
	}
};


class GNemaMesta :public exception {
public:
	const char* what()const {
		return "Nema mesta u timu!";
	}
};




class Tim{
protected:
	int poeni;
	string imeTima;
	int maxIgraca;
	Igrac** igraci;
	int broj;

	virtual void pisi(ostream& os)const {
		os << imeTima << "[";
		for (int i = 0; i < broj-1; i++) {
			//if (igraci[i] != nullptr)
				os << *igraci[i] << ",";
		}
		os << *igraci[broj - 1] << "]"<< endl;
		
	}

	void premesti(Tim& t) {
		imeTima = t.imeTima;
		maxIgraca = t.maxIgraca;
		igraci = t.igraci;
		broj = t.broj;

		t.igraci = nullptr;
	}
	void brisi() {
		broj = 0;
		for (int i = 0; i <maxIgraca; i++)
			delete igraci[i];
		delete[] igraci;
		igraci = nullptr;
	}

	void kopiraj(const Tim& t) {
		igraci = new Igrac * [t.maxIgraca];
		maxIgraca = t.maxIgraca;
		broj = t.broj;
		imeTima = t.imeTima;
		for (int i = 0; i < maxIgraca; i++) {
			if (t.igraci[i] != nullptr)
				igraci[i] = new Igrac(*t.igraci[i]);
			else igraci[i] = nullptr;
		}
	}

public:
	Tim(string ime, int max) :imeTima(ime){
		igraci = new Igrac* [maxIgraca=max];
		for (int i = 0; i < maxIgraca; i++) {
			igraci[i]=nullptr;
		}
		poeni = 0;
		broj = 0;
	}

	Tim(const Tim& t) {
		kopiraj(t);
	}

	Tim(Tim&& t) {
		premesti(t);
	}

	Tim& operator=(const Tim& t) {
		if (this != &t) { brisi(); kopiraj(t); }
		return *this;
	}
	Tim& operator=( Tim&& t) {
		if (this != &t) { brisi(); premesti(t); }
		return *this;
	}

	virtual ~Tim() { brisi(); }

	virtual void dodaj(  int pozicija,Igrac& i) {
		if (broj == maxIgraca) throw GNemaMesta();
		if (pozicija < 0 || pozicija >= maxIgraca) return;
		for (int i = pozicija-1; i <= broj; i ++ ) {
			igraci[i + 1] = igraci[i];
		}
		igraci[pozicija] = &i;
		broj++;
	}

	int dohvTrenBrojIgraca()const { return broj; }
	int dohvPoene()const { return poeni; }
	void postaviPoene(int i) { poeni = i; }

	Igrac** dohvTim() { return igraci; }


	Igrac& operator[](int p) {
		if (p<0 || p>=maxIgraca) throw GIndeks();
		return *(igraci[p]);
	}

	const Igrac& operator[](int p)const {
		return const_cast<Tim&>(*this)[p];
	}


	int vrednostTima()const{
		int v = 0;
		for (int i = 0; i < maxIgraca; i++) {
				v += (*igraci[i]).dohvVrednostIgraca();
		}
		return v / dohvTrenBrojIgraca();
	}


	friend bool operator==(const Tim& t1, const Tim& t2);

	
	friend ostream& operator<<(ostream& os, const Tim& t);



};

#endif