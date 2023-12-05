#include "Cjt_estaciones.hh"
using namespace std;

Cjt_estaciones::Cjt_estaciones() {

}

void inicializar_estaciones(BinTree<string>& a) {
    string ide;
    cin >> ide;

    if (ide != "#") {
        int capacidad;
        cin >> capacidad;
        Estacion e;
        e.modificar_capacidad(capacidad);

        estacion.insert(make_pair(ide,e));
        pl_totales += n;

        BinTree<string> izq,der;
        inicializar_estaciones(izq);
        inicializar_estaciones(der);
        a = BinTree<string>(ide,izq,der);
    }
}

void alta_bici(string idb, string ide) {
    estaciones.find()
}

void baja_bici(string idb) {

}

bool existe_estacion(string ide) {

}

void mover_bici(string destino, string idb) {

}

bool estacion_llena() {

}

void modificar_capacidad(int n) {

}

void subir_bicis() {

}

void bicis_estacion(string ide) {

}

int cantidad_bicis(string ide) {

}

void i_subir_bicis() {
    
}
