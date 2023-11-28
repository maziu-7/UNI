/**
 * @file Cjt_bicis.hh
 * @brief Especificación de la clase Cjt_bicis
 */
#ifndef CONJ_BICIS_HH
#define CONJ_BICIS_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif

/**
 * @class Cjt_bicis
 * @brief Contiene la información de todas las bicis.
 * A través de un mapa, se indica en qué estación están 
 */
class Cjt_bicis {

private:
    map<string,Bici> conjunto_bicis; //(?)

public:
    /**
     * @brief Constructora por defecto
     * \pre: cierto
     * \post: un conjunto de bicis Cjt_bicis para guardar
     * los viajes que ha hecho cada bici
     */
    Cjt_bicis();

    /**
     * @brief Consultora que indica si existe una bici
     * \pre: string identificador de la bici
     * \post: si la bici no existe se escribe un mensaje
     * error en el canal de salida 
     */
    bool existe_bici(string idb);

    /**
     * @brief Consultora que indica en qué estación
     * se encuentra una bici
     * \pre: string idenfiticador de la bici
     * \post: si la bici no existe se escribe un mensaje
     * de error en el canal de salida
     */
    string estacion_bici(string idb);
};

#endif