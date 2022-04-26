#include "Tim.h"


bool operator==(const Tim& t1, const Tim& t2){
	bool sveSemIgracaJeJednako = t1.imeTima == t2.imeTima && t1.maxIgraca == t2.maxIgraca && t1.dohvTrenBrojIgraca() == t2.dohvTrenBrojIgraca();
	if (sveSemIgracaJeJednako) {
		for (int i = 0; i < t1.broj; i++) {
				if (!(*(t1.igraci[i]) == *(t2.igraci[i]))) return false;
		}
		return true;
	}
	return false;
}




ostream& operator<<(ostream& os, const Tim& t){
	t.pisi(os);
	return os;
}


