/**
 * @file Cjt_estaciones.hh
 * @brief Especificación de la clase Cjt_estaciones
 */
#ifndef CONJ_ESTACIONES_HH
#define CONJ_ESTACIONES_HH

#include "Estacion.hh"
#include "BinTree.hh"

/**
 * @class Cjt_estaciones 
 * @brief Contiene todas las estaciones en un árbol de
 * strings (identificadores de estación)
 */
class Cjt_estaciones {

private:
    BinTree<string> arbol_estaciones;
    map<string,Estacion> estacion;
    int plazas_totales;

    void inicializar_arbol(BinTree<string> &a);
    //inicializar arbol
    //inicializar map
    //inicializar plazas libres totales

public:
    /**
     * @brief Constructora por defecto
     * \pre: cierto
     * \post: una clase Cjt_estaciones vacía para
     * guardar los identificadores de las estaciones
     */
    Cjt_estaciones();

    /**
     * @brief Lee los parámetros de entrada y va añadiéndolos
     * a Cjt_estaciones
     * \pre: árbol de strings (identificadores de estación) vacío
     * \post: los parámetros se guardan en el árbol
     */
    void inicializar_estaciones();

    /**
     * @brief Modificadora que añade una bici a una estación
     * \pre: string identificador de la bici
     * \post: si la estación no existe, si la bici ya está
     * en la estación o si la bici no cabe se escribe un
     * mensaje de error en el canal de salida
     */
    void alta_bici(string idb, string ide);

    /**
     * @brief Modificadora que da de baja la bici especificada
     * \pre: string identificador de la bici
     * \post: si la bici no existe se produce un mensaje de error
     * en el canal de salida, en caso contrario, se elimina la bici
     * del sistema, modificando también las plazas libres de la estación
     */
    void baja_bici(string idb, string ide);

    /**
     * @brief Consultora que indica si existe una estación
     * \pre: string identificador de la estación
     * \post: si la estación no existe, devuelve falso
     */
    bool existe_estacion(string ide);

    /**
     * @brief Modificadora que mueve una bici de una estación a otra
     * \pre: string identificador de la estación destino y string
     * identificador de la bici
     * \post: si la estación destino o la bici no existen, si la
     * estación destino es igual a la estación origen o si la bici no
     * cabe en la estación destino, se escribe un error en el canal de salida
     */
    void mover_bici(string destino, string idb);

    /**
     * @brief Consultora que indica si una estación está llena
     * \pre: cierto
     * \post: si la estación no existe, se escribe un mensaje de error
     * en el canal de salida
     */
    bool estacion_llena(string ide) const;

    /**
     * @brief ?
     */
    void subir_bicis();

    /**
     * @brief Lectora que devuelve la estación correspondiente
     * a su identificador
     * \pre: string identificador de la estación
     * \post: si la estación no existe se escribe un mensaje
     * de error en el canal de salida
     */
    Estacion leer(string ide);
};
#endif