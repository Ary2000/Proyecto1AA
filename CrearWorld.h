#include <stdio.h>  /* defines FILENAME_MAX */
#define WINDOWS  /* uncomment this line to use it for windows.*/ 
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include<iostream>

using namespace std;

std::string GetCurrentWorkingDir( void ) {
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}

void crearCopiasWorld(){

    std::string path = GetCurrentWorkingDir();
    std::string pathCopiar;
    std::string pathCopiarBack;
    std::string pathCopiarProgDi;
    std::string pathCopiarDiVe;
    std::string pathCopiar2= "copy ";
    std::string svgWolrd = "\\\\world.svg ";
    std::string svgWolrdDivideVenceras = "\\\\worldDivideVenceras.svg ";
    std::string svgWolrdBackTraking = "\\\\worldBackTracking.svg ";
    std::string svgWolrdProgDinamica = "\\\\worldProgDinamica.svg ";
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i]==*"\\")
        {
            pathCopiar+="\\";
        }
         pathCopiar+=path[i];
    }
    pathCopiar2+=pathCopiar;
    pathCopiar2+=svgWolrd;
    pathCopiar2+=pathCopiar;

    pathCopiarBack = pathCopiar2;
    pathCopiarBack+=svgWolrdBackTraking;

    pathCopiarProgDi = pathCopiar2;
    pathCopiarProgDi+=svgWolrdProgDinamica;

    pathCopiarDiVe = pathCopiar2;
    pathCopiarDiVe+=svgWolrdDivideVenceras;

    int indiceBack = pathCopiarBack.length();
    char arrayBackTraking[indiceBack + 1];
    strcpy(arrayBackTraking, pathCopiarBack.c_str());

    int indiceProgDi = pathCopiarProgDi.length();
    char arrayProgDi[indiceProgDi + 1];
    strcpy(arrayProgDi, pathCopiarProgDi.c_str());

    int indiceDiVe = pathCopiarDiVe.length();
    char arrayDiVe[indiceDiVe + 1];
    strcpy(arrayDiVe, pathCopiarDiVe.c_str());
    
    system(arrayBackTraking);
    system(arrayDiVe);
    system(arrayProgDi);
}