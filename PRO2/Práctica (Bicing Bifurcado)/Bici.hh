#ifndef BICI_HH
#define BICI_HH

#include <iostream>
#include <list>
using namespace std;

class Bici {

private:
    list<pair<string,string>> viajes; //

public:
    bool existe_bici(string idb);
    

};

#endif