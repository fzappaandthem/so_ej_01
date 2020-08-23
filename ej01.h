#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 50

/* 
*   Retorna un String nuevo que es la concatenación
*   de los dos Strings pasados por parámetro
*   Ejemplo:
*   char* nombre = "Ritchie";
*   char* saludo = string_concat("Hola ", nombre);
*   =>
*   saludo = "Hola Ritchie"
*/
void concatenarDosStrings();

/*
*   Asigna en el tercer parámetro, la concatenación
*   de los primeros dos Strings
*   Ejemplo:
*   char* nombre = "Ritchie";
*   char* saludo;
*   string_concat("Hola ", nombre, &saludo);
*   =>
*   saludo = "Hola Ritchie"
*/
void concatenarDosStringsEnElTercerParametro();

/*
*   Separa el mail en un usuario y un dominio.
*   Ejemplo:
*   char* mail = "ritchie@ansic.com.ar";
*   char* user;
*   char* dominio;
*   mail_split(mail, &user, &dominio);
*   =>
*   user = "ritchie"
*   dominio = "ansic.com.ar"
*/
void separarMailDeDominio();

void mail_split(char * restrict mail, char** user, char** dominio);

char result_1[SIZE*2];
void leerTextoAConcatenar(char *input);
void readString(char*);

char* string_concat(const char*, const char*);
void string_concat_dinamyc(const char*, const char*, char**);