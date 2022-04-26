#ifndef _Privilegovani_h_
#define _Privilegovani_h_
#include "Tim.h"

class GMalaVrednostIgraca :public exception {
public:
	const char* what()const override {
		return "Mala je vrednost igraca za privilegovani tim!";
	}
};



class Privilegovani:public Tim{
	int minVrednost;
public:
	Privilegovani(string ime, int max, int min) : Tim(ime, max), minVrednost(min) {}

	virtual void dodaj(int pozicija, Igrac& i)override {
		if (i.dohvVrednostIgraca() < minVrednost)throw GMalaVrednostIgraca();
		if (broj == maxIgraca) throw GNemaMesta();
		if (pozicija < 0 || pozicija >= maxIgraca) return;
		for (int i = pozicija-1; i <= broj; i ++ ) {
			igraci[i + 1] = igraci[i];
		}
		igraci[pozicija] = &i;
		broj++;
	}

	void pisi(ostream& os)const override {
		os << imeTima << "(" << minVrednost << ")" << "[";
		for (int i = 0; i < broj - 1; i++) {
			//if (igraci[i] != nullptr)
			os << *igraci[i] << ",";
		}
		os << *(igraci[broj-1])<<"]"<< endl;
	}

};

#endif