#ifndef _Par_h_
#define _Par_h_
#include<iostream>
using namespace std;

template<typename T>
class Par{
	T** skup;
	int kap;


	void premesti(Par<T>& p) {
		skup = p.skup;
		kap = p.kap;

		p.skup = nullptr;
	}
	void brisi() {
		
		for (int i = 0; i < 2; i++)
			delete skup[i];
		delete[] skup;
		skup = nullptr;
	}

	void kopiraj(const Par<T>& p) {
		skup = new T * [p.kap];
		kap = p.kap;
		
		for (int i = 0; i < 2; i++) {
			if (p.skup[i] != nullptr)
				skup[i] = new T(*p.skup[i]);
			else skup[i] = nullptr;
		}
	}


public:
	Par(T t1, T t2) {
		skup = new T* [2];
		skup[0] = &t1;
		skup[1] = &t2;
	}


	Par(const Par<T>& p) {
		kopiraj(p);
	}

	Par(Par<T>&& p) {
		premesti(p);
	}

	Par& operator=(const Par<T>& p) {
		if (this != &p) { brisi(); kopiraj(p); }
		return *this;
	}
	Par& operator=(Par<T>&& p) {
		if (this != &p) { brisi(); premesti(p); }
		return *this;
	}

	 ~Par() { brisi(); }


	T dohvT1() { return *skup[0]; }
	T dohvT2() { return *skup[1]; }

	void postaviT1(T& t, int i) { skup[i] =& t; };
	void postaviT2(T& t, int i) { skup[i] = &t; };

	friend bool operator==(const Par& p1, const Par& p2) {
		for (int i = 0; i < 2; i++) {
			if (p1.skup[i] != p2.skup[i]) return false;
		}
		return true;
	}

	friend ostream& operator<<(ostream& os,  Par& p) {
		return os << "[" << p.dohvT1() << "," << p.dohvT2() << "]";
	}
};

#endif


