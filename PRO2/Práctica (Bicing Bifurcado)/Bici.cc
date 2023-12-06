#include "Bici.hh"
using namespace std;

Bici::Bici() {}

void Bici::viaje_nuevo(string origen, string destino) {
    pair<string, string> viajes(origen, destino);
    viajes_bici.insert(viajes_bici.end(),viajes);
}

void Bici::imprimir_viajes() {
    list<pair<string, string>>::iterator pos;
    for (pos = viajes_bici.begin(); pos != viajes_bici.end(); ++pos) {
        cout << pos->first << ' ' << pos->second << endl;
    }
}

void Bici::mover_bici(string ide) {

}