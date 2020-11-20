#include "manejadorDocs.h"

ManejadorDocs::ManejadorDocs(char* dV, char* pD, char* bT)
{
    pugi::xml_parse_result resultDV = docDV.load_file(dV);
    pugi::xml_parse_result resultPD = docPD.load_file(pD);
    pugi::xml_parse_result resultBT = docBT.load_file(bT);
}