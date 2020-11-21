#ifndef MANEJADORDOCS_H
#define MANEJADORDOCS_H

#include <string>

#include "pugixml.hpp"

class ManejadorDocs
{
    public:
    ManejadorDocs(char* dV, char* pD, char* bT);

    char* dV;
    char* pD;
    char* bT;

    pugi::xml_document docDV;
    pugi::xml_document docPD;
    pugi::xml_document docBT;

    void salvarArchivoDV() { docDV.save_file(dV); }
    void salvarArchivoPD() { docPD.save_file(pD); }
    void salvarArchivoBT() { docBT.save_file(bT); }
    void ponerBlancosYTiempoDV(int blancos, double tiempo);
    void ponerBlancosYTiempoPD(int blancos, double tiempo);
    void ponerBlancosYTiempoBT(int blancos, double tiempo);
};

#endif