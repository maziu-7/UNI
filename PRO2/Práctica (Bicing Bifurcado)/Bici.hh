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
 * @brief Contiene los viajes que realiza cada bici
 * en una lista de pares de strings, con su estación
 * de origen y su estación de destino.
 */
class Bici {

private:
    list<pair<string,string>> viajes_bici; //viajes de cada bici

public:
    /**
     * @brief Constructora por defecto
     * \pre: cierto
     * \post: una bici Bici vacía donde se guardan los
     * viajes que ha hecho una bici
     */
    Bici();

    /**
     * @brief Modificadora que añade un viaje a la bici Bici
     * \pre: dos strings de identificación de estación, origen y destino
     * \post: si la estación no existe, si la bici no existe,
     * si la bici no cabe o si origen y destino son iguales,
     * se produce un mensaje de error, sino, se añade el nuevo
     * viaje a viajes_bici
     */
    void viaje_nuevo(string origen, string destino);

    /**
     * @brief Escritora que escribe todos los viajes de una bici
     * \pre: string de identificador de la bici
     * \post: si la estación no existe escribe un mensaje
     * de error, sino, escribe en el canal de salida todos
     * los viajes hechos por la bici identificada
     */
    Bici imprimir_viajes(string idb);
};

#endif