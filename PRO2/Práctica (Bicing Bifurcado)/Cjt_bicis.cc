#include "Cjt_bicis.hh"
using namespace std;

Cjt_bicis::Cjt_bicis() {}

void Cjt_bicis::anadir_bici(const string& idb) {
    Bici b;
    conjunto_bicis.insert(make_pair(idb, b));
}

void Cjt_bicis::eliminar_bici(const string& idb) {
    conjunto_bicis.erase(idb);
}

bool Cjt_bicis::existe_bici(const string& idb) const {
    if (conjunto_bicis.find(idb) == conjunto_bicis.end()) return false;
    return true;
}

string Cjt_bicis::estacion_bici(const string& idb) {
    return conjunto_bicis[idb].estacio_actual();
}

void Cjt_bicis::viaje_nuevo(const string& origen, const string& destino, const string& idb) {
    map<string, Bici>::iterator it = conjunto_bicis.find(idb);
    (*it).second.viaje_nuevo(origen, destino);
}

void Cjt_bicis::imprimir_viajes(const string& idb) {
    map<string, Bici>::iterator it;
    it = conjunto_bicis.find(idb);
    (*it).second.imprimir_viajes();
}

void Cjt_bicis::modificar_estacion(const string& idb, const string& ide) {
    map<string, Bici>::iterator it = conjunto_bicis.find(idb);
    (*it).second.modificar_estacion(ide);
}