/**
 * @file Bici.hh
 * @brief Especificación de la clase Bici
 */
#ifndef BICI_HH
#define BICI_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <list>
using namespace std;
#endif

/**
 * @class Bici
 * @brief Contiene los viajes que realiza cada bici en una lista
 * de pair de strings, con su estación de origen y su estación de destino.
 */
class Bici {

private:
    list<pair<string,string>> viajes_bici; //viajes de cada bici
    string estacion; //identificador de estación de la bici

public:
    /**
     * @brief Constructora por defecto
     * \pre: cierto
     * \post: una clase Bici vacía donde se guardan los viajes
     * que ha hecho una bici
     */
    Bici();

    /**
     * @brief Modificadora que añade un viaje a una bici
     * \pre: dos strings de identificación de estación, origen y destino
     * \post: si la estación no existe, si la bici no existe,
     * si la bici no cabe o si origen y destino son iguales,
     * se escribe un mensaje de error en el canal de salida,
     * en caso contrario, se añade el viaje nuevo a viajes_bici
     */
    void viaje_nuevo(const string& origen, const string& destino);

    /**
     * @brief Escritora que imprime todos los viajes de una bici
     * \pre: cierto
     * \post: si la estación no existe escribe un mensaje de error en
     * el canal de salida
     */
    void imprimir_viajes();

    /**
     * @brief 
     */
    void modificar_estacion(const string& ide);
};
#endif