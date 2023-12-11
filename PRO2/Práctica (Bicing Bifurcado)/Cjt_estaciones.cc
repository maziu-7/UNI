#include "Cjt_estaciones.hh"
using namespace std;

Cjt_estaciones::Cjt_estaciones() {}

void Cjt_estaciones::inicializar_arbol(BinTree<string>& a) {
    string ide;
    cin >> ide;
    if (ide != "#") {
        int c;
        cin >> c;
        Estacion e;
        pl_totales += c;
        estaciones.insert(make_pair(ide, e));
        BinTree<string> izq, der;
        inicializar_arbol(izq);
        inicializar_arbol(der);
        a = BinTree<string>(ide, izq, der);
    }
}

void Cjt_estaciones::inicializar_estaciones() {
    inicializar_arbol(arbol_estaciones);
}

void Cjt_estaciones::alta_bici(const string& idb, const string& ide) {
    estaciones[ide].anadir_bici(idb);
    --pl_totales;
}

void Cjt_estaciones::baja_bici(const string& idb, const string& ide) {
    estaciones[ide].eliminar_bici(idb);
    ++pl_totales;
}

string Cjt_estaciones::estacion_bici(const string& idb) const {
    map<string,Estacion>::const_iterator it = estaciones.find(idb);
    return (*it).first;
}

bool Cjt_estaciones::existe_estacion(const string& ide) const {
    if (estaciones.find(ide) == estaciones.end()) return false;
    return true;
}

void Cjt_estaciones::mover_bici(const string& ide, const string& idb) {
    map<string,Estacion>::const_iterator it = estaciones.find(idb);
    string origen = estacion_bici(idb);
    alta_bici(idb, ide);
    baja_bici(idb, origen);
}

bool Cjt_estaciones::estacion_llena(const string& ide) const {
    if ((*estaciones.find(ide)).second.estacion_llena()) return true;
    return false;
}

void Cjt_estaciones::modificar_capacidad(const string& ide, int n) {
    estaciones.find(ide)->second.modificar_capacidad(n);
}

void Cjt_estaciones::bicis_estacion(const string& ide) const {
    estaciones.find(ide)->second.bicis_estacion();
}

int Cjt_estaciones::cantidad_bicis(const string& ide) const {
    return (*estaciones.find(ide)).second.cantidad_bicis();
}

int Cjt_estaciones::plazas_totales() const {
    return pl_totales;
}

void Cjt_estaciones::subir_bicis(Cjt_bicis& b) {
    i_subir_bicis(arbol_estaciones, b);
}

void Cjt_estaciones::i_subir_bicis(const BinTree<string>& a, Cjt_bicis& b) {
    if (not a.right().empty() and not a.left().empty()) {
        map<string, Estacion>::iterator it = estaciones.find(a.value());
        map<string, Estacion>::iterator izq = estaciones.find(a.left().value());
        map<string, Estacion>::iterator der = estaciones.find(a.right().value());
        while (not (*it).second.estacion_llena() and ((*izq).second.cantidad_bicis() != 0 or (*der).second.cantidad_bicis() != 0)) {
            if ((*izq).second.cantidad_bicis() > (*der).second.cantidad_bicis()) {
                string idb = (*izq).second.bici_menor();
                baja_bici(idb, a.left().value());
                alta_bici(idb, a.value());
                b.modificar_estacion(idb, a.value());
            }
            else if ((*izq).second.cantidad_bicis() < (*der).second.cantidad_bicis()) {
                string idb = (*der).second.bici_menor();
                baja_bici(idb, a.right().value());
                alta_bici(idb, a.value());
                b.modificar_estacion(idb, a.value());
            }
            else {
                string bici_izq = (*izq).second.bici_menor();
                string bici_der = (*der).second.bici_menor();
                if (bici_izq < bici_der) {
                    string idb = (*izq).second.bici_menor();
                    baja_bici(idb, a.left().value());
                    alta_bici(idb, a.value());
                    b.modificar_estacion(idb, a.value());
                    i_subir_bicis(a.left(), b);
                }
                else {
                    string idb = (*der).second.bici_menor();
                    baja_bici(idb, a.right().value());
                    alta_bici(idb, a.value());
                    b.modificar_estacion(idb, a.value());
                    i_subir_bicis(a.right(), b);
                }
            }
        }
    }
}

void asignar_estacion(const BinTree<string>& a) {
    i_asignar_estacion(a);
}

void i_asignar_estacion(const BinTree<string>& a) {
    
}