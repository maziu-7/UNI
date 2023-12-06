#include "Estacion.hh"
using namespace std;

Estacion::Estacion() {

}

void Estacion::anadir_bici(string idb) {
    Bici b;
    bicis.insert(idb);
    --pl_estacion;
}

void Estacion::eliminar_bici(string idb) {
    bicis.erase(idb);
    ++pl_estacion;
}

void Estacion::modificar_capacidad(int n) {
    pl_estacion += n - capacidad;
    capacidad = n;
}

bool Estacion::estacion_llena() const {
    if (pl_estacion == 0) return true;
    return false;
}

void Estacion::bicis_estacion() const {
    set<string>::iterator it = bicis.begin();
    while (it != bicis.end()) {
        cout << *it << endl;
        ++it;
    }
}

int Estacion::cantidad_bicis() const {
    return capacidad - pl_estacion;
}

int Estacion::plazas_libres() const {
    return pl_estacion;
}