//
// Created by marti on 06/06/2023.
//
#include "estructuras.h"
void realizar_publicacion(Usuario u[],int indice_usuario) {
    if (u->num_publicaciones >= MAX_PUBLICACIONES) {
        printf("Error: Has alcanzado el límite de publicaciones.\n");
        return;
    }

    char texto[121];
    printf("\nIntroduce el texto de la publicación (hasta 120 caracteres): ");
    scanf(" %[^\n]", texto);

    strcpy(u[indice_usuario].publicaciones[u[indice_usuario].num_publicaciones].texto, texto);
    u[indice_usuario].num_publicaciones++;

    printf("\nPublicacion realizada correctamente!\n");
}

void verPublicacionesPropias(Usuario u[], int indice_usuario) {
    printf("\n%d",u[indice_usuario].num_publicaciones);
    if (u[indice_usuario].num_publicaciones == 0) {
        printf("No hay publicaciones.\n");
        return;
    }
    printf("\n=============================");
    printf("\nTus publicaciones:\n");
    for (int i = 0; i < u[indice_usuario].num_publicaciones; i++) {
        printf("%s\n", u[indice_usuario].publicaciones[i].texto);
        printf("---------------------------------\n");
    }
}
