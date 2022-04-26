#include "Igrac.h"
#include "Tim.h"
#include "Privilegovani.h"
#include "Mec.h"


int main() {
	try {

		Igrac i1("Sasa", 635);
		Igrac i2("Nikola", 320);
		Igrac i3("Mika", 350);
		Igrac i4("Jova", 200);
		cout << i1 << endl;
		cout << i2 << endl;

		i1.povecajSmanji(25);
		cout <<i1 << endl;

		Tim t1("fudbal", 2);
		Tim t2("fudbal", 2);
		Privilegovani p1("kosarka", 3,250 );
		Privilegovani p2("tenis", 3, 300);

		p1.dodaj(0, i1);
		p1.dodaj(1, i3);
		p2.dodaj(0, i1);
		p2.dodaj(1, i2);
		p2.dodaj(2, i3);

		t1.dodaj(0,i1);
		t1.dodaj(1,i2);
		t2.dodaj(0,i1);
		t2.dodaj(1,i2);



		cout << t1[1] << endl;
		cout << "Srednja vrednost tima:" << t1.vrednostTima() << endl;

		cout << "Jednakost timova:" << (t1 == t2)<< endl;

		cout << "Tim:" << t1 << endl << endl;
		cout << "privilegovani tim:" << p1 << endl;
		cout << "privilegovani tim:" << p2 << endl;





	}
	catch (GIndeks& e) {
		cout << e.what();
	}
	
	catch (GNemaMesta& e) {
		cout << e.what();
	}

	catch (GMalaVrednostIgraca& e) {
		cout << e.what();
	}
	catch (GMecNeodigran& e) {
		cout << e.what();
	}
}
