/*     Título = Ejercicios básicos de C: ejercicio 1
 *     Fecha = dom 16/8/2020
 *     Autor = Gastón Di Filippo
 */

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

void mail_split(const char* mail, char** user, char** dominio);

char result_1[SIZE*2];

void readString(char*);

char* string_concat(const char*, const char*);
void string_concat_dinamyc(const char*, const char*, char**);


int main(void)
{
    puts("punto 1: concatenar dos strings");
    concatenarDosStrings();
    puts("punto 2: concatenar dos strings dinamicamente");
    concatenarDosStringsEnElTercerParametro();
    puts("punto 3: Separar mail y dominio");

    return 0 ;
}


void concatenarDosStrings()
{

    char w1[SIZE], w2[SIZE];

    readString(w1);
    readString(w2);

    char *concat = string_concat(w1, w2);

    printf("Concatenacion: %s\n", concat);
}

void readString(char* input)
{
    int i = 0, c;

    puts("Ingresar texto a concatenar: ");

    while( (i < SIZE - 1 ) && (c = getchar() ) != '\n' )
    {
        input[i++] = c;
    }
    input[i] = '\0';
}

char* string_concat(const char *w1, const char *w2)
{
    strcat(result_1, w1);
    strcat(result_1, w2);
    return result_1;
}

void concatenarDosStringsEnElTercerParametro()
{
    char w1[SIZE], w2[SIZE];
    char *result[1];
    result[0] = malloc(sizeof(char) * (strlen(w1) + strlen(w2)));

    readString(w1);
    readString(w2);

    string_concat_dinamyc(w1, w2, result);
    printf("El resultado de concatener los strings es: %s\n", result[0]);

}


void string_concat_dinamyc(const char* w1, const char* w2, char** result)
{
    strcat(result[0], w1);
    strcat(result[0], w2);
}

