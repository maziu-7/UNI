#ifndef CONJ_ESTACIONES_HH
#define CONJ_ESTACIONES_HH

#include <iostream>
#include <map>
#include "Estacion.hh"
#include "BinTree.hh"

class Cjt_estaciones {
    private:
        map<string,Estacion> est;
        BinTree<string> a_est;
        int plazas_totales;

        void inicializar_arbol(BinTree<string> &a);
        //inicializar arbol
        //inicializar map
        //inicializar plazas libres totales

    public:
        Cjt_estaciones();
        
        void inicializar_estaciones();

};

#endif