//hira.sheikh@estudiantat.upc.edu L43
//mateus.grandolfi@estudiantat.upc.edu L43

#include "Cjt_estudiants.hh"

/* Pre: el paràmetre implícit no està ple */
/* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
   si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */
void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
  if (nest >= MAX_NEST) throw PRO2Excepcio("Conjunt ple");
  int i = nest - 1;
  bool b = false;
  int dni = est.consultar_DNI();
  while (i >= 0 and not b) {
    if (dni > vest[i].consultar_DNI()) b = true;
    else {
        vest[i+1] = vest[i];
        --i;
    }
  }
  //i és la posició més avançada amb el DNI més petit que dni, si n'hi ha;
  //si no, i = -1
  vest[i+1] = est;
  ++nest;
}

/* Pre: cert */
/* Post: el paràmetre implicit no conté cap estudiant sense nota */ 
void Cjt_estudiants::eliminar_estudiants_sense_nota()
{
  
}