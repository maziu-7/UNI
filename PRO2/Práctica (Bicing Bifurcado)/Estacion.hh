/**
 * @file Estacion.hh
 * @brief Especificación de la clase Estacion
 */
#ifndef ESTACION_HH
#define ESTACION_HH

#include "Bici.hh"

#ifndef NO_DIAGRAM
#include <set>
#endif

/**
 * @class Estacion 
 * @brief Contiene las bicis que hay en una estación, almacenadas
 * en un set con sus respectivos identificadores y viajes
 */
class Estacion {

private:
    set<string> Bicis; //identificador de la bici junto a sus viajes
    int plazas_libres; //plazas libres de una estación

public:
    /**
     * @brief Constructora por defecto
     * \pre: cierto
     * \post: una clase Estacion vacía para guardar los
     * identificadores de las bicis que contiene una estación
     */
    Estacion();

    /**
     * @brief Modificadora que añade una bici a una estación
     * \pre: string identificador de la bici
     * \post: si la estación no existe, si la bici ya está
     * en la estación o si la bici no cabe se escribe un
     * mensaje de error en el canal de salida
     */
    void alta_bici(string idb);

    /**
     * @brief Modificadora que da de baja la bici especificada
     * \pre: string identificador de la bici
     * \post: si la bici no existe se produce un mensaje de error
     * en el canal de salida, en caso contrario, se elimina la bici
     * del sistema, modificando también las plazas libres de la estación
     */
    void baja_bici(string idb);

    /**
     * @brief 
     */
    string bici_seleccionada_para_subir();

    /**
     * @brief Modificadora que altera la capacidad de la estación especificada
     * \pre: string identificador de la estación y un entero
     * estrictamente positivo
     * \post: si la estación no existe o si el entero es un número
     * menor a la cantidad de bicis que hay actualmente en la estación,
     * se escribe un error en el canal de salida
     */
    void modificar_capacidad(int n);

    /**
     * @brief Consultora que indica si una estación está llena
     * \pre: cierto
     * \post: si la estación no existe, se escribe un mensaje de error
     * en el canal de salida
     */
    bool estacion_llena() const;

    /**
     * @brief Consultora que indica qué bicis contiene una estación
     * \pre: string identificador de la estación
     * \post: si la estación no existe se escribe un mensaje de error
     * en el canal de salida
     */
    void bicis_estacion(string ide);
};
#endif