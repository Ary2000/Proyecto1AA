#include "manejadorDocs.h"

ManejadorDocs::ManejadorDocs(char* dV, char* pD, char* bT)
{
    this->dV = dV;
    this->pD = pD;
    this->bT = bT;
    pugi::xml_parse_result resultDV = docDV.load_file(dV);
    pugi::xml_parse_result resultPD = docPD.load_file(pD);
    pugi::xml_parse_result resultBT = docBT.load_file(bT);
}

void ManejadorDocs::ponerBlancosYTiempoBT(int blancos, double tiempo)
{
    pugi::xml_document lineaTexto;
    pugi::xml_document lineaTexto2;
    pugi::xml_document lineaTexto3;
    std::string linea1 = "<text x='0' y='13' fill='red'>Cantidad blancos: ";
    linea1.append(std::to_string(blancos));
    linea1.append("</text>");

    std::string linea2 = "<text x='0' y='30' fill='red'>Tiempo: ";
    linea2.append(std::to_string(tiempo));
    linea2.append("</text>");

    std::string linea3 = "<text x='150' y='30' fill='red'> Milisegundos ";
    linea3.append("</text>");

    const char* linea1Char = linea1.c_str();
    const char* linea2Char = linea2.c_str();
    const char* linea3Char = linea3.c_str();

    lineaTexto.load_string(linea1Char);
    lineaTexto2.load_string(linea2Char);
    lineaTexto3.load_string(linea3Char);
    pugi::xml_node textito = lineaTexto.child("text");
    pugi::xml_node textito2 = lineaTexto2.child("text");
    pugi::xml_node textito3 = lineaTexto3.child("text");

    docBT.child("svg").append_copy(textito);
    docBT.child("svg").append_copy(textito2);
    docBT.child("svg").append_copy(textito3);
}

void ManejadorDocs::ponerBlancosYTiempoDV(int blancos, double tiempo)
{
    pugi::xml_document lineaTexto;
    pugi::xml_document lineaTexto2;
    pugi::xml_document lineaTexto3;
    std::string linea1 = "<text x='0' y='13' fill='red'>Cantidad blancos: ";
    linea1.append(std::to_string(blancos));
    linea1.append("</text>");


    std::string linea2 = "<text x='0' y='30' fill='red'>Tiempo: ";
    linea2.append(std::to_string(tiempo));
    linea2.append("</text>");

    std::string linea3 = "<text x='150' y='30' fill='red'> Milisegundos ";
    linea3.append("</text>");

    const char* linea1Char = linea1.c_str();
    const char* linea2Char = linea2.c_str();
    const char* linea3Char = linea3.c_str();

    lineaTexto.load_string(linea1Char);
    lineaTexto2.load_string(linea2Char);
    lineaTexto3.load_string(linea3Char);
    pugi::xml_node textito = lineaTexto.child("text");
    pugi::xml_node textito2 = lineaTexto2.child("text");
    pugi::xml_node textito3 = lineaTexto3.child("text");
    docDV.child("svg").append_copy(textito);
    docDV.child("svg").append_copy(textito2);
    docDV.child("svg").append_copy(textito3);
}

void ManejadorDocs::ponerBlancosYTiempoPD(int blancos, double tiempo)
{
    pugi::xml_document lineaTexto;
    pugi::xml_document lineaTexto2;
    pugi::xml_document lineaTexto3;
    std::string linea1 = "<text x='0' y='13' fill='red'>Cantidad blancos: ";
    linea1.append(std::to_string(blancos));
    linea1.append("</text>");


    std::string linea2 = "<text x='0' y='30' fill='red'>Tiempo: ";
    linea2.append(std::to_string(tiempo));
    linea2.append("</text>");

    std::string linea3 = "<text x='150' y='30' fill='red'> Milisegundos ";
    linea3.append("</text>");

    const char* linea1Char = linea1.c_str();
    const char* linea2Char = linea2.c_str();
    const char* linea3Char = linea3.c_str();

    lineaTexto.load_string(linea1Char);
    lineaTexto2.load_string(linea2Char);
    lineaTexto3.load_string(linea3Char);
    pugi::xml_node textito = lineaTexto.child("text");
    pugi::xml_node textito2 = lineaTexto2.child("text");
    pugi::xml_node textito3 = lineaTexto3.child("text");
    docPD.child("svg").append_copy(textito);
    docPD.child("svg").append_copy(textito2);
    docPD.child("svg").append_copy(textito3);
}