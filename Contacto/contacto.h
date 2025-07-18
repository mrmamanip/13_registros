#ifndef CONTACTO_H
#define CONTACTO_H
#include <string>
#include "funciones.h"
using namespace std;

void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);

#endif