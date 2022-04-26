#pragma once
#include "Par.h"
#include "Tim.h"
#include <string>

enum Ishod{ POBEDA_DOMACIN, NERESENO, POBEDA_GOST };
class GMecNeodigran :public exception {
public:
	const char* what()const override {
		return "Mec neodigran!";
	}
};


class Mec{
	Par<Tim> *par;
	static Ishod ishodMeca;
	bool odigran;
	static string ishodStr[];

public:
	Mec(Tim t1, Tim t2 ){
	Par<Tim>p = Par<Tim> (t1, t2);
	par = &p;
		odigran = false;
	}

	Par<Tim>& dohvParTimova()const { return *par; }

	void odigrajMec(Par<Tim> p) {
		if (p.dohvT1().vrednostTima() > p.dohvT2().vrednostTima()) {
			ishodMeca = POBEDA_DOMACIN;
			p.dohvT1().postaviPoene(3);
			for (int i = 0; i < p.dohvT1().dohvTrenBrojIgraca(); i++) {
				p.dohvT1().dohvTim()[i]->povecajSmanji(10);
			}
			for (int i = 0; i < p.dohvT2().dohvTrenBrojIgraca(); i++) {
				p.dohvT2().dohvTim()[i]->povecajSmanji(-10);
			}
		}
		else
			if (p.dohvT1().vrednostTima() < p.dohvT2().vrednostTima()) {
				ishodMeca = POBEDA_GOST;
				p.dohvT2().postaviPoene(3);
				for (int i = 0; i < p.dohvT1().dohvTrenBrojIgraca(); i++) {
					p.dohvT1().dohvTim()[i]->povecajSmanji(-10);
				}
				for (int i = 0; i < p.dohvT2().dohvTrenBrojIgraca(); i++) {
					p.dohvT2().dohvTim()[i]->povecajSmanji(10);
				}
			}
			else { ishodMeca = NERESENO;
			p.dohvT1().postaviPoene(1);
			p.dohvT2().postaviPoene(1);
				}
		odigran = true;
	}

	Par<int> dohvParPoena() {
			Par<int> m=  Par<int>(par->dohvT1().dohvPoene(), par->dohvT2().dohvPoene());
			return m;
	}
	
	bool daLiJeOdigran()const {
		if (!odigran) throw GMecNeodigran();
		return true;
	}

	friend ostream& operator<<(ostream& os, const Mec& m) {
		 os << m.dohvParTimova() << " ";
		 if (m.daLiJeOdigran())  os << m.ishodStr[ishodMeca] << endl;
		 return os;
	}

};

