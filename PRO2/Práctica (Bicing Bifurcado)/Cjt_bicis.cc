#include "Cjt_bicis.hh"
using namespace std;

Cjt_bicis::Cjt_bicis() {}

void Cjt_bicis::anadir_bici(string idb) {
    Bici b;
    conjunto_bicis.insert(make_pair(idb, b));
}

void Cjt_bicis::eliminar_bici(string idb) {
    conjunto_bicis.erase(idb);
}

bool Cjt_bicis::existe_bici(string idb) {
    if (conjunto_bicis.find(idb) == conjunto_bicis.end()) return false;
    return true;
}

string Cjt_bicis::estacion_bici(string idb) {
    return conjunto_bicis.find(idb)->first;
}

void Cjt_bicis::imprimir_viajes(string idb) {
    map<string, Bici>::iterator it;
    it = conjunto_bicis.find(idb);
    (*it).second.imprimir_viajes();
}

void Cjt_bicis::mover_bici(string idb, string ide) {
    map<string, Bici>::iterator it;
}

void Cjt_bicis::modificar_estacion(string idb, string ide) {
    map<string, Bici>::iterator it = conjunto_bicis.find(idb);
    (*it).second.modificar_estacion(ide);
}