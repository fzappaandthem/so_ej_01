/*     Título = Ejercicios básicos de C: ejercicio 1
 *     Fecha = dom 16/8/2020
 *     Autor = Gastón Di Filippo
 */

#include "ej01.h"

int main(void)
{

	puts("Borro el comment, y genero conflictos desde el repo local!");

    puts("Generando conflictos!!!");

    puts("punto 1: concatenar dos strings");
    concatenarDosStrings();
    puts("punto 2: concatenar dos strings dinamicamente");
    concatenarDosStringsEnElTercerParametro();
    puts("punto 3: Separar mail y dominio");
    separarMailDeDominio();
    return 0 ;
}

void concatenarDosStrings()
{

    char w1[SIZE], w2[SIZE];

    leerTextoAConcatenar(w1);
    leerTextoAConcatenar(w2);

    char *concat = string_concat(w1, w2);

    printf("Concatenacion: %s\n", concat);
}

void readString(char* input)
{
    int i = 0, c;

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

void leerTextoAConcatenar(char *input)
{
    puts("Ingresar texto a concatenar: ");
    readString(input);
}

void concatenarDosStringsEnElTercerParametro()
{
    char w1[SIZE], w2[SIZE];
    char *result[1];
    result[0] = malloc(sizeof(char) * (strlen(w1) + strlen(w2)));


    leerTextoAConcatenar(w1);
    leerTextoAConcatenar(w2);

    string_concat_dinamyc(w1, w2, result);
    printf("El resultado de concatener los strings es: %s\n", result[0]);
}


void string_concat_dinamyc(const char* w1, const char* w2, char** result)
{
    strcat(result[0], w1);
    strcat(result[0], w2);
}

void separarMailDeDominio()
{
    char mail[SIZE];
    puts("Ingresar un email:");
    readString(mail);
    char *user[1];
    char *dominio[1];
    mail_split(mail, user, dominio);
    printf("User: %s\tDominio: %s\n", user[0], dominio[0]);
}

//strchr(const char* s, int c); -> SI encuentra el caracter c en s, devuelve c y todo lo que sigue en el string (de no haber overflow)

/*
    El dominio se podía obtener de la siguiente manera
    int s = '@';
    dominio[0] = strchr(mail, s);
    dominio[0] = ++*user;
    ---pero hay una función de c que está mucho mejor para este ejercicio: strtok
*/

/*strtok: This function returns a pointer to the first token found in the string. A null pointer is returned if there are no tokens left to retrieve.*/

void mail_split(char * restrict mail, char** user, char** dominio)
{
    char c[2] = "@";
    char *token = strtok(mail, c);
    //asigno el string hasta el primer token (sin incluirlo)
    user[0] = token;
    //avanzo hasta el siguiente token (NULL o siguiente aparición del token -en este caso @-)
    token = strtok(NULL, c);
    dominio[0] = token;
}

