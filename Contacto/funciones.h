#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
#include "contacto.h"
using namespace std;

void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);

#endif