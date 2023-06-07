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
    int i, j, k;
    for (i = 0; i < numero_de_usuario; i++) {
        Usuario usuario = u[i];
        for (j = 0; j < MAX_PUBLICACIONES; j++) {
            Publicacion publicacion = usuario.publicaciones[j];
            char* token = strtok(publicacion.texto, " ");
            while (token != NULL) {
                // Verificar si la palabra ya existe en el conteo
                int palabraExistente = 0;
                for (k = 0; k < *numPalabras; k++) {
                    if (strcmp(conteo[k].palabra, token) == 0) {
                        conteo[k].conteo++;
                        palabraExistente = 1;
                        break;
                    }
                }
                // Si la palabra no existe, se agrega al conteo
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
    // Ordenar las palabras en orden descendente según el conteo
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
    // Imprimir las palabras más usadas
    for (i = 0; i < numPalabras; i++) {
        printf("%s : %d\n", conteo[i].palabra, conteo[i].conteo);
    }
}

