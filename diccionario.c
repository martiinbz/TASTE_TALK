#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#define MAX_TEXT_LENGTH 1000
#define MAX_WORD_LENGTH 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PUBLICACIONES 100
#define MAX_TEXT_LENGTH 1000
#define MAX_WORD_LENGTH 50


void contarPalabras(Usuario* u, int numero_de_usuario, ConteoPalabras* conteo, int* numPalabras) {
    *numPalabras = 0;
    int i, j, k; //3 bucles, para iterar entre diferentes usuarios, entre diferentes publicaciones y dividir por palabras
    for (i = 0; i < numero_de_usuario; i++) {
        Usuario usuario = u[i];//se selecciona un usuario
        for (j = 0; j < MAX_PUBLICACIONES; j++) {
            Publicacion publicacion = usuario.publicaciones[j]; //se selecciona una publicacion suya
            char* token = strtok(publicacion.texto, " ");//se separa en palabras
            while (token != NULL) {
                // Verificar si la palabra ya existe en el diccionario
                int palabraExistente = 0;
                for (k = 0; k < *numPalabras; k++) {
                    if (strcmp(conteo[k].palabra, token) == 0) {
                        conteo[k].conteo++; //si ya está en el diccionario, se suma 1 al conteo de esa palabra
                        palabraExistente = 1;
                        break;
                    }
                }
                // Si la palabra no existe, se agrega al diccionario
                if (!palabraExistente) {
                    strcpy(conteo[*numPalabras].palabra, token);
                    conteo[*numPalabras].conteo = 1;
                    (*numPalabras)++;
                }
                token = strtok(NULL, " ");
            }
        }
    }
}

void imprimirPalabrasMasUsadas(ConteoPalabras* conteo, int numPalabras) {
    // Algoritmo BubbleSort para ordenar palabras en orden descendiente segun sus apariciones
    int i, j;
    for (i = 0; i < numPalabras - 1; i++) {


        
        for (j = 0; j < numPalabras - i - 1; j++) {
            if (conteo[j].conteo < conteo[j + 1].conteo) {
                ConteoPalabras temp = conteo[j];
                conteo[j] = conteo[j + 1];
                conteo[j + 1] = temp;
            }
        }
    }
    // Imprimir las 10 palabras más usadas palabras más usadas
    printf("Las 10 palabras mas usadas en la aplicacion son:\n");
    for (i = 0; i < 10; i++) {
        if(conteo[i].conteo==0){
            printf("\nNadie ha publicado aun!\n"); //en el caso de que no haya ninguna palabra publicada
            break;
        }
        printf("%s : %d\n", conteo[i].palabra, conteo[i].conteo);
    }
}

