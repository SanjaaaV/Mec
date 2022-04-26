#include "Igrac.h"

bool operator==(const Igrac& i1, const Igrac& i2){
	if (i1.dohvImeIgraca() == i2.dohvImeIgraca() && i1.dohvVrednostIgraca() == i2.dohvVrednostIgraca()) return true;
	else return false;
}

ostream& operator<<(ostream& os, const Igrac& i){
	return os << i.dohvImeIgraca() << "#" << i.dohvVrednostIgraca();
}

 Igrac& Igrac::povecajSmanji(double procenat){
	vrednostIgraca += (int)(vrednostIgraca * (procenat / 100));
	return *this;
	
}
