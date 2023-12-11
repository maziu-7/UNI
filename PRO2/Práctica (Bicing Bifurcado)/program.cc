/**
 * @file program.cc
 */
#include "Cjt_bicis.hh"
#include "Estacion.hh"
#include "Cjt_estaciones.hh"
using namespace std;

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
            if (b.existe_bici(idb)) cout << "error: la bici ya existe" << endl;
            else if (not e.existe_estacion(ide)) cout << "error: la estacion no existe" << endl;
            else if (e.estacion_llena(ide)) cout << "error: la estacion esta llena" << endl;
            else {
                b.anadir_bici(idb);
                e.alta_bici(idb,ide);
            }
        }
        
        else if (op == "baja_bici" or op == "bb") {
            cin >> idb;
            cout << "#bb " << idb << endl;
            if (not b.existe_bici(idb)) cout << "error: la bici no existe" << endl;
            else {
                b.eliminar_bici(idb);
                e.baja_bici(idb,ide);
            }
        }

        else if (op == "estacion_bici" or op == "eb") {
            cin >> idb;
            cout << "#eb " << idb << endl;
            if (not b.existe_bici(idb)) cout << "error: la bici no existe" << endl;
            else cout << e.estacion_bici(idb) << endl;
        }

        else if (op == "viajes_bici" or op == "vb") {
            cin >> idb;
            cout << "#vb " << idb << endl;
            if (not b.existe_bici(idb)) cout << "error: la bici no existe" << endl;
            else b.imprimir_viajes(idb);
        }

        else if (op == "mover_bici" or op == "mb") {
            cin >> idb >> ide;
            cout << "#mb " << idb << ' ' << ide << endl;
            if (not e.existe_estacion(ide)) cout << "error: la estacion no existe" << endl;
            else if (not b.existe_bici(idb)) cout << "error: la bici no existe" << endl;
            else if (e.estacion_bici(idb) == ide) cout << "error: la bici ya esta en el sitio" << endl;
            else if (e.estacion_llena(ide)) cout << "error: la bici no cabe" << endl;
            else {
                string origen = e.estacion_bici(idb);
                e.mover_bici(ide, idb);
                b.viaje_nuevo(origen, ide, idb);
            }
        }

        else if (op == "bicis_estacion" or op == "be") {
            cin >> ide;
            cout << "#be " << ide << endl;
            if (not e.existe_estacion(ide)) cout << "error: la estacion no existe" << endl;
            else e.bicis_estacion(ide);
        }

        else if (op == "modificar_capacidad" or op == "mc") {
            int n;
            cin >> ide >> n;
            cout << "#mc " << ide << ' ' << n << endl;
            if (not b.existe_bici(ide)) cout << "error: la estacion no existe" << endl;
            else if (e.cantidad_bicis(ide) < n) cout << "error: capacidad insuficiente" << endl;
            else e.modificar_capacidad(ide, n);
        }

        else if (op == "plazas_libres" or op == "pl") {
            cout << "#pl" << endl;
            cout << e.plazas_totales() << endl;
        }

        else if (op == "subir_bicis" or op == "sb") {
            cout << "#sb" << endl;
            //e.subir_bicis(a);
        }

        else if (op == "asignar_estacion" or op == "ae") {
            cin >> idb;
            cout << "#ae " << idb << endl;
            //e.asignar_estacion(idb);
        }
    }
}