#ifndef MANEJADORDOCS_H
#define MANEJADORDOCS_H

#include <string>

#include "pugixml.hpp"

class ManejadorDocs
{
    public:
    ManejadorDocs(char* dV, char* pD, char* bT);
    pugi::xml_document docDV;
    pugi::xml_document docPD;
    pugi::xml_document docBT;
};

#endif