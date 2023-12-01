#include "Estacion.hh"
#include "Cjt_bicis.hh"
#include "Cjt_estaciones.hh"

int main() {
    Cjt_estaciones e;
    Cjt_bicis b;
    e.inicializar_estaciones();
    string op;
    while (cin >> op and op != "fin") {
        string idb, ide;
        if (op == "alta_bici" or op == "ab") {
            cin >> idb >> ide;
            cout << "#ab " << idb << " " << ide << endl;
            if(b.existe_bici(idb)) cout << "error" << endl;
            else if(not e.existe_estacion(ide)) cout << "error" << endl;
            else if(e.estacion_llena()) cout << "error" << endl;
            else {
                b.alta_bici(idb,ide);
                e.alta_bici(idb,ide);
            }
        }
        else if (op == "baja_bici" or op == "bb") {
            cin >> idb;
            if (not b.existe_bici(idb)) cout << "error: no existe la bici" << endl;
            else e.baja_bici(idb);
        }

        else if (op == "estacion_bici" or op == "eb") {
            cin >> idb;
            if (not b.existe_bici(idb)) cout << "error: no existe la bici" << endl;
            else cout << b.estacion_bici(idb) << endl;
        }

        else if (op == "viajes_bici" or op == "vb") {
            cin >> idb;
            if (not b.existe_bici(ide)) cout << "error: no existe la bici" << endl;
            else b.imprimir_viajes(idb);
        }

        else if (op == "mover_bici" or op == "mb") {
            cin >> idb >> ide;
            if (not b.existe_bici(ide)) cout << "error: no existe la estacion" << endl;
            else if (not b.existe_bici(idb)) cout << "error: no existe la bici" << endl;
            //else if (b.iguales(ide,idb)) cout << "error: la bici ya esta en el sitio" << endl;
            else if (e.estacion_llena()) cout << "error: la bici no cabe" << endl;
            else {
                b.mover_bici(ide,idb);
            }
        }

        else if (op == "bicis_estacion" or op == "be") {
            cin >> ide;
            if (not b.existe_bici(ide)) cout << "error: no existe la estacion" << endl;
            else e.bicis_estacion(ide);
        }

        else if (op == "modificar_capacitat" or op == "mc") {
            cin >> ide;
            int n;
            cin >> n;
            if (not b.existe_bici(ide)) cout << "error: no existe la estacion" << endl;
            else if (e.cantidad_bicis(ide) < n) cout << "error: capacidad insuficiente" << endl;
            else e.modificar_capacidad(n);
        }

        else if (op == "plazas_libres" or op == "pl") {
            //cout << e.plazas_libres() << endl;
        }

        else if (op == "subir_bicis" or op == "sb") {
            
        }

        else if (op == "asignar_estacion" or op == "ae") {
            
        }
    }
}