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
 * @brief Representa una estación con todas las bicis que contiene
 */
class Estacion {

private:
    set<string> bicis_est; //identificador de cada bici
    int pl_estacion, capacidad;

public:
    //Consultoras

    /**
     * @brief Constructora por defecto
     * \pre cierto
     * \post El resultado es una <em>Estacion</em> vacía
     * \coste Constante
     */
    Estacion();

    /**
     * @brief Constructora con valores concretos
     * \pre n > 0
     * \post El resultado es una estación con plazas libres <em>n</em> y capacidad <em>n</em>
     * \coste Constante
     */
    Estacion(int n);

    //Modificadoras

    /**
     * @brief Añade una bici a la estación
     * \pre La bici <em>idb</em> no está en la estación y cabe en esta
     * \post El parámetro implícito pasa a tener una bici más
     * \coste Lineal
     */
    void anadir_bici(const string& idb);

    /**
     * @brief Da de baja una bici
     * \pre La bici <em>idb</em> existe y está en la estación
     * \post El parámetro implícito pasa a tener una bici menos
     * \coste Lineal
     */
    void eliminar_bici(const string& idb);

    /**
     * @brief Altera la capacidad de la estación
     * \pre n > 0, n >= cantidad de bicis actual
     * \post Se han modificado los valores del parámetro implícito
     * \coste Constante
     */
    void modificar_capacidad(int n);

    //Consultoras

    /**
     * @brief Consultora de la capacidad de una estación
     * \pre cierto
     * \post Si la estación está llena es cierto, sino, es falso
     * \coste Constante
     */
    bool estacion_llena() const;

    /**
     * @brief Consultora y escritora de qué bicis hay en la estación
     * \pre cierto
     * \post Se han escrito las bicis que contiene la estación en el canal
     * estándar de salida
     * \coste Constante
     */
    void bicis_estacion() const;

    /**
     * @brief Consultora de la cantidad de bicis de la estación
     * \pre cierto
     * \post El resultado es la cantidad de bicis de la estación
     * \coste Constante
     */
    int cantidad_bicis() const;

    /**
     * @brief Consultora de las plazas de la estación
     * \pre cierto
     * \post El resultado es el número de plazas libres que hay en la estación
     * \coste Constante
     */
    int plazas_libres() const;

    /**
     * @brief Consultora de la bici menor
     * \pre La estación no está vacía
     * \post El resultado es la bici con el identificador de orden más pequeño
     * \coste Constante
     */
    string bici_menor() const;
};
#endif