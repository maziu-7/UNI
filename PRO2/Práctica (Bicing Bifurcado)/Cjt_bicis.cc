#include "Cjt_bicis.hh"
using namespace std;

Cjt_bicis::Cjt_bicis() {

}

void Cjt_bicis::anadir_bici(string idb) {
    Bici b;
    conjunto_bicis.insert(make_pair(idb, b));
}

void Cjt_bicis::eliminar_bici(string idb) {
    conjunto_bicis.erase(idb);
}

/*bool Cjt_bicis::estaciones_iguales(const string ide, const string idb) {
    if ( == ide) return true;
    return false;
}*/

bool Cjt_bicis::existe_bici(string idb) {
    if (conjunto_bicis.find(idb) == conjunto_bicis.end()) return false;
    return true;
}

string Cjt_bicis::estacion_bici(string idb) {
    return conjunto_bicis.find(idb)->first;
}