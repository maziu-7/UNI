/** @file Bici.hh
    @brief Especificación de la clase Bici
*/
#ifndef BICI_HH
#define BICI_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <list>
using namespace std;
#endif

/** @class Bici
    @brief Representa una bici con sus respectivos viajes
 */
class Bici {

private:
    list<pair<string, string>> vbicis; //viajes de la bici
    string estacion; //identificador de la estación actual en la que
                     //se encuentra la bici
public:
    //Constructoras

    /**
     * @brief Constructora por defecto
     * \pre cierto
     * \post El resultado es una <em>Bici</em> sin viajes
     * \coste 
     */
    Bici();

    //Modificadoras

    /**
     * @brief Añade un viaje a la bici
     * \pre Origen y destino existen y son diferentes
     * \post Añade un viaje al parámetro implícito
     * \coste 
     */
    void viaje_nuevo(const string& origen, const string& destino);

    /**
     * @brief Modifica la estación en la que se encuentra la bici
     * \pre cierto
     * \post El parámetro implícito se convierte en <em>ide</em>
     * \coste 
     */
    void modificar_estacion(const string& ide);

    //Consultoras
    
    /**
     * @brief Consultora de la estación
     * \pre cierto
     * \post El resultado es la estación en la que se encuentra la bici actualmente
     * \coste 
     */
    string estacion_actual() const;

    //Lectura y/o escritura

    /**
     * @brief Operación de escritura
     * \pre: cierto
     * \post: Escribe todos los viajes que ha hecho la bici
     */
    void imprimir_viajes();
};
#endif