/**
 * @file Cjt_bicis.hh
 * @brief Especificación de la clase Cjt_bicis
 */
#ifndef CJT_BICIS_HH
#define CJT_BICIS_HH

#include "Bici.hh"

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
    map<string,Bici> conjunto_bicis; //identificadores de las bicis junto a sus viajes

public:
    /**
     * @brief Constructora por defecto
     * \pre: cierto
     * \post: un conjunto de bicis Cjt_bicis para guardar
     * los viajes que ha hecho cada bici
     */
    Cjt_bicis();

    /**
     * @brief Modificadora que añade una bici a una estación
     * \pre: string identificador de una bici y de una estación
     * \post: si la estación no existe, si la bici ya está
     * en la estación o si la bici no cabe se escribe un
     * mensaje de error en el canal de salida
     */
    void anadir_bici(const string& idb);

    /**
     * @brief Modificadora que da de baja una bici
     * \pre: string identificador de la bici
     * \post: si la bici no existe se produce un mensaje de error
     * en el canal de salida, en caso contrario, se elimina la bici
     * del sistema, modificando también las plazas libres de la estación
     */
    void eliminar_bici(const string& idb);

    /**
     * @brief Consultora que indica si existe una bici
     * \pre: string identificador de la bici
     * \post: si la bici no existe se escribe un mensaje
     * error en el canal de salida 
     */
    bool existe_bici(const string& idb) const;

    /**
     * @brief Consultora que indica en qué estación
     * se encuentra una bici
     * \pre: string idenfiticador de la bici
     * \post: si la bici no existe se escribe un mensaje
     * de error en el canal de salida
     */
    string estacion_bici(const string& idb) const;

    /**
     * @brief 
     */
    void imprimir_viajes(const string& idb);

    /**
     * @brief 
     */
    void mover_bici(const string& origen, const string& destino);

    /**
     * @brief 
     */
    void modificar_estacion(const string& idb, const string& ide);
};
#endif