/** @file Cjt_bicis.hh
    @brief Especificación de la clase Cjt_bicis
*/
#ifndef CJT_BICIS_HH
#define CJT_BICIS_HH

#include "Bici.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif

/** @class Cjt_bicis
    @brief Representa todas las bicis con sus identificadores e viajes
 */
class Cjt_bicis {

private:
    map<string,Bici> cb; //identificadores de las bicis junto a sus viajes

public:
    //Constructoras

    /**
     * @brief Constructora por defecto
     * \pre cierto
     * \post El resultado es un <em>Cjt_bicis</em> vacío 
     * \coste 
     */
    Cjt_bicis();

    //Modificadoras

    /**
     * @brief Añade una bici a una estación
     * \pre La estación <em>ide</em> existe, la bici <em>idb</em> no está incluída previamente en la estación
     * y la bici cabe en la estación
     * \post El parámetro implícito pasa a tener una bici más
     * \coste 
     */
    void anadir_bici(const string& idb, const string& ide);

    /**
     * @brief Elimina una bici
     * \pre La bici <em>idb</em> existe
     * \post El parámetro implícito pasa a tener una bici menos
     * \coste 
     */
    void eliminar_bici(const string& idb);

    /**
     * @brief Añade un viaje a una bici
     * \pre La bici <em>idb</em> existe
     * \post El parámetro implícito pasa a tener un viaje más
     * \coste 
     */
    void viaje_nuevo(const string& origen, const string& destino, const string& idb);

    /**
     * @brief Modifica la estación en la que se encuentra una bici
     * \pre La bici <em>idb</em> existe
     * \post El parámetro implícito de una bici del conjunto pasa a tener una estación diferente
     * \coste 
     */
    void modificar_estacion(const string& idb, const string& ide);

    //Consultoras

    /**
     * @brief Consulta la existencia de una bici
     * \pre El parámetro implícito está inicializado
     * \post El resultado es cierto si existe; falso si no
     * \coste 
     */
    bool existe_bici(const string& idb) const;

    /**
     * @brief Consultora de una estación
     * \pre El parámetro implícito está inicializado y la bici <em>idb</em> existe
     * \post El resultado es el identificador de la estación del parámetro implícito
     * \coste 
     */
    string estacion_bici(const string& idb);

    //Lectura y/o escritura

    /**
     * @brief Operación de escritura
     * \pre La bici <em>idb</em> existe
     * \post Escribe todos los viajes que ha hecho la bici <em>idb</em>
     * \coste 
     */
    void imprimir_viajes(const string& idb);
};
#endif