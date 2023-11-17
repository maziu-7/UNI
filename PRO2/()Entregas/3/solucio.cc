//hira.sheikh@estudiantat.upc.edu L43
//mateus.grandolfi@estudiantat.upc.edu L43

#include "Cjt_estudiants.hh"

/* Pre: el paràmetre implícit no està ple */
/* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
   si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */
void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
    int pos_est = cerca_dicot(vest, 0, nest - 1, est.consultar_DNI());
    if (pos_est < nest and vest[pos_est].consultar_DNI() == est.consultar_DNI()) b = true;
    //l'estudiant ja està inclós al vector

    //en cas de que no ho estigui:
    else {
        b = false;
        //
        for (int i = nest - 1; i >= pos_est; --i) {
            vest[i + 1] = vest[i];
        }
        vest[pos_est] = est;
        ++nest;

        //
        if (pos_est <= imax) ++imax;
        //
        if (est.te_nota()) {
            //
            if (imax == -1) imax = pos_est;
            //
            else if (est.consultar_nota() > vest[imax].consultar_nota()) imax = pos_est;
            else if (est.consultar_nota() == vest[imax].consultar_nota()) {
                if (est.consultar_DNI() < vest[imax].consultar_DNI()) imax = pos_est;
            }
        }
    }
}

/* Pre: cert */
/* Post: el paràmetre implicit no conté cap estudiant sense nota */ 
void Cjt_estudiants::eliminar_estudiants_sense_nota() {
    int est_sense_nota = 0;
    for (int i = 0; i < nest; ++i) {
        if (not vest[i].te_nota()) ++est_sense_nota;
        //reagrupem tots els estudiants que es troben al vector en dos conjunts,
        //els que tenen nota es posicionen al principi del vector, i justament
        //després van tots els que no tenen nota
        else vest[i - est_sense_nota] = vest[i];
        //si 
        if (imax == i) imax = i - est_sense_nota;
    }
    //modifiquem el nombre d'estudiants ja que els que no
    //tenen nota no ens interessen
    nest = nest - est_sense_nota;
}