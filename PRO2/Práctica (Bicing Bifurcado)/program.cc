/**
 * @file program.cc
 */
#include "Estacion.hh"
#include "Cjt_bicis.hh"
#include "Cjt_estaciones.hh"

int main() {
    Cjt_estaciones e;
    Cjt_bicis b;
    e.inicializar_estaciones(); //hacerlo en el .cc para probar casos
    string op;
    while (cin >> op and op != "fin") {
        string idb, ide;
        if (op == "alta_bici" or op == "ab") {
            cin >> idb >> ide;
            cout << "#ab " << idb << " " << ide << endl;
            if (b.existe_bici(idb)) cout << "error" << endl;
            else if (not e.existe_estacion(ide)) cout << "error" << endl;
            else if (e.estacion_llena()) cout << "error" << endl;
            else {
                b.alta_bici(idb,ide);
                e.alta_bici(idb,ide);
            }
        }
        else if (op == "baja_bici" or op == "bb") {
            cin >> idb;
            cout << "#bb " << idb << endl;
            if (not b.existe_bici(idb)) cout << "error: la bici no existe" << endl;
            else {
                e.baja_bici(idb);
                b.baja_bici(idb);
            }
        }

        else if (op == "estacion_bici" or op == "eb") {
            cin >> idb;
            cout << "#eb " << idb << endl;
            if (not b.existe_bici(idb)) cout << "error: la bici no existe" << endl;
            else cout << b.estacion_bici(idb) << endl;
        }

        else if (op == "viajes_bici" or op == "vb") {
            cin >> idb;
            cout << "#vb " << idb << endl;
            if (not b.existe_bici(ide)) cout << "error: la bici no existe" << endl;
            else b.imprimir_viajes(idb);
        }

        else if (op == "mover_bici" or op == "mb") {
            cin >> idb >> ide;
            cout << "#mb " << idb << ' ' << ide << endl;
            if (not e.existe_estacion(ide)) cout << "error: la estacion no existe" << endl;
            else if (not b.existe_bici(idb)) cout << "error: la bici no existe" << endl;
            //else if (b.iguales(ide,idb)) cout << "error: la bici ya esta en el sitio" << endl;
            else if (e.estacion_llena()) cout << "error: la bici no cabe" << endl;
            else {
                b.mover_bici(ide,idb);
            }
        }

        else if (op == "bicis_estacion" or op == "be") {
            cin >> ide;
            cout << "#be " << ide << endl;
            if (not b.existe_bici(ide)) cout << "error: la estacion no existe" << endl;
            else e.bicis_estacion(ide);
        }

        else if (op == "modificar_capacitat" or op == "mc") {
            int n;
            cin >> ide >> n;
            cout << "#mc " << ide << ' ' << n << endl;
            if (not b.existe_bici(ide)) cout << "error: la estacion no existe" << endl;
            else if (e.cantidad_bicis(ide) < n) cout << "error: capacidad insuficiente" << endl;
            else e.modificar_capacidad(n);
        }

        else if (op == "plazas_libres" or op == "pl") {
            cout << "#pl" << endl;
            //cout << e.plazas_libres() << endl;
        }

        else if (op == "subir_bicis" or op == "sb") {
            
        }

        else if (op == "asignar_estacion" or op == "ae") {
            
        }
    }
}