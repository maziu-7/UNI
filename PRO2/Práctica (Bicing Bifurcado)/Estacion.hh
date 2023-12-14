/** @file Estacion.hh
    @brief Especificación de la clase Estacion
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
    set<string> bicis_est; //identificador de cada bici
    int pl_estacion, capacidad;

public:
    /**
     * @brief Constructora por defecto
     * \pre cierto
     * \post una clase Estacion vacía para guardar los
     * identificadores de las bicis que contiene una estación
     * \coste 
     */
    Estacion();

    /**
     * @brief 
     * \pre 
     * \post 
     * \coste 
     */
    Estacion(int n);

    /**
     * @brief Modificadora que añade una bici a una estación
     * \pre string identificador de la bici y de la estación
     * \post si la estación no existe, si la bici ya está
     * en la estación o si la bici no cabe se escribe un
     * mensaje de error en el canal de salida
     * \coste 
     */
    void anadir_bici(const string& idb);

    /**
     * @brief Modificadora que da de baja la bici especificada
     * \pre string identificador de la bici
     * \post si la bici no existe se produce un mensaje de error
     * en el canal de salida, en caso contrario, se elimina la bici
     * del sistema, modificando también las plazas libres de la estación
     * \coste 
     */
    void eliminar_bici(const string& idb);

    /**
     * @brief Modificadora que altera la capacidad de la estación especificada
     * \pre entero estrictamente positivo
     * \post si la estación no existe o si el entero es un número
     * menor a la cantidad de bicis que hay actualmente en la estación,
     * se escribe un error en el canal de salida
     * \coste 
     */
    void modificar_capacidad(int n);

    /**
     * @brief Consultora que indica si una estación está llena
     * \pre cierto
     * \post si la estación no existe, se escribe un mensaje de error
     * en el canal de salida
     * \coste 
     */
    bool estacion_llena() const;

    /**
     * @brief Consultora que indica qué bicis contiene una estación
     * \pre cierto
     * \post si la estación no existe se escribe un mensaje de error
     * en el canal de salida
     * \coste 
     */
    void bicis_estacion() const;

    /**
     * @brief 
     * \pre 
     * \post 
     * \coste 
     */
    int cantidad_bicis() const;

    /**
     * @brief 
     * \pre 
     * \post 
     * \coste 
     */
    int plazas_libres() const;

    /**
     * @brief 
     * \pre 
     * \post 
     * \coste 
     */
    string bici_menor() const;
};
#endif