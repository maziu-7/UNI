/** @file Cjt_estaciones.hh
    @brief Especificación de la clase Cjt_estaciones
*/
#ifndef CJT_ESTACIONES_HH
#define CJT_ESTACIONES_HH

#include "Estacion.hh"
#include "Cjt_bicis.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <map>
#endif

/**
 * @class Cjt_estaciones 
 * @brief Representa todas las estaciones del sistema de Bicing
 */
class Cjt_estaciones {

private:
    BinTree<string> arbol_estaciones;
    map<string, Estacion> ce;
    int pl_totales = 0;
    void inicializar_arbol(BinTree<string>& a);
    void i_subir_bicis(const BinTree<string>& a, Cjt_bicis& cb);
    void i_asignar_estacion(const BinTree<string>& a, string& ide, double& coef_max, int& num_est, int& pl);

public:
    //Constructoras

    /**
     * @brief Constructora por defecto
     * \pre cierto
     * \post El resultado es un <em>Cjt_estaciones</em> vacío
     * \coste Constante
     */
    Cjt_estaciones();

    //Modificadoras

    /**
     * @brief Da de alta una bici a una estación
     * \pre La estación existe. La bici no está en la estación y cabe en esta 
     * \post Se ha dado de alta la bici en el parámetro implícito
     * \coste Cuasilineal
     */
    void alta_bici(const string& idb, const string& ide);

    /**
     * @brief Da de baja una bici
     * \pre La bici existe
     * \post Se ha dado de baja la bici del parámetro implícito
     * \coste Logarítmico
     */
    void baja_bici(const string& idb, const string& ide);

    /**
     * @brief Mueve una bici de una estación a otra
     * \pre Tanto la estación destino como la bici existen, la bici cabe en la estación
     * destino y las estaciones origen y destino con diferentes
     * \post Se ha movido la bici desde <em>origen</em> hasta <em>destino</em>
     * \coste Cuasilineal
     */
    void mover_bici(const string& ide, const string& idb, const string& origen);

    /**
     * @brief Altera la capacidad de una estación
     * \pre La estación existe y n > 0, n >= cantidad de bicis actual
     * \post Se ha modificado la capacidad total de la estación
     * \coste Logarítmico
     */
    void modificar_capacidad(const string& ide, int n);

    /**
     * @brief Mueve bicis a niveles superiores del conjunto
     * \pre El parámetro implícito está inicializado
     * \post Las bicis afectadas pasan a estar asignadas a estaciones de niveles superiores
     * a las que estaban
     * \coste Cuadrático
     */
    void subir_bicis(Cjt_bicis& cb);

    //Consultoras

    /**
     * @brief Consultora que indica si existe una estación
     * \pre El parámetro implícito está inicializado
     * \post si la estación no existe, devuelve falso
     * \coste Logarítmico
     */
    bool existe_estacion(const string& ide) const;

    /**
     * @brief Consultora que indica si una estación está llena
     * \pre cierto
     * \post si la estación no está llena, devuelve falso
     * \coste Logarítmico
     */
    bool estacion_llena(const string& ide) const;

    /**
     * @brief Consultora y escritora que indica qué bicis contiene una estación
     * \pre La estación <em>ide</em> existe
     * \post Se han escrito las bicis de la estación <em>ide</em> en el canal
     * estándar de salida
     * \coste Logarítmico
     */
    void bicis_estacion(const string& ide) const;

    /**
     * @brief Consultora de las bicis de una estación
     * \pre cierto
     * \post El resultado es el número de bicis que contiene la estación
     * \coste Logarítmico
     */
    int cantidad_bicis(const string& ide) const;

    /**
     * @brief Consultora del conjunto de estaciones
     * \pre cierto
     * \post El resultado es el número de plazas totales entre todas las estaciones
     * \coste Constante
     */
    int plazas_totales() const;

    /**
     * @brief Consultora y escritora que asigna una bici a una estación
     * \pre El parámetro implícito está inicializado
     * \post Se ha añadido una bici al conjunto de estaciones
     * \coste Cuasilineal
     */
    void asignar_estacion(const string& idb, Cjt_bicis& b);

    //Lectura y/o escritura

    /**
     * @brief Lee los parámetros de entrada y va añadiéndolos a Cjt_estaciones
     * \pre El parámetro implícito está inicializado y vacío
     * \post Los nuevos parámetros se guardan en el conjunto de estaciones
     * \coste Lineal
     */
    void inicializar_estaciones();
};
#endif