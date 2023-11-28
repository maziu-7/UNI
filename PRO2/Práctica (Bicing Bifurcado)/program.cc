#include "Estacion.hh"
#include "Cjt_bicis.hh"
#include "Cjt_estaciones.hh"

int main() {
    Cjt_estaciones e;
    Cjt_bicis b;
    e.inicializar_estaciones();
    //declarar estaciones y bicis
    //inicializar estaciones
    string op;
    while (cin >> op and op != "fin") {
        if (op == "alta_bici" or op == "ab") {
            string idb, ide;
            cin >> idb >> ide;
            cout << "#ab " << idb << " " << ide << endl;
            if(b.existe_bici(idb)) cout << "error" << endl;
            else if(not e.existe_estacion(ide)) cout << "error" << endl;
            else if(e.estacion_llena(ide)) cout << "error" << endl;
            else {
                b.alta_bici(idb,ide);
                e.alta_bici(idb,ide);
            }
        }
        else if (op == "baja_bici" or op == "bb") {

        }
        else if (op == "estacion_bici" or "eb") {

        }
        else if (op == "viajes_bici" or "vb") {

        }
        else if (op == "mover_bici" or "mb") {

        }
        else if (op == "bicis_estacion" or "be") {

        }
        else if (op == "modificar_capacidad" or "mc") {

        }
        else if (op == "plazas_libres" or "pl") {

        }
        else if (op == "subir_bicis" or "sb") {

        }
        else {

        }
    }
}