#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "estructuras.h"

//
// Created by marti on 31/05/2023.
//
void enviar_solicitud(Usuario u[]){   //funcion que usaremos para enviar solicitudes a usuarios ya registrados
    char usuario_solicitado[20], numero_de_usuarios=0; char **lista_de_usuarios;
    printf("Introduce el nombre del usuario al que quieres añadir");
    getchar();
    fgets(usuario_solicitado, 20, stdin);
    int indice_busqueda = busqueda_secuencial(lista_de_usuarios, numero_de_usuarios, usuario_solicitado);
    if(indice_busqueda!=-1){
        printf("Se ha enviado tu solicitud a %s", usuario_solicitado);
    } else {
        printf("El usuario %s no existe", usuario_solicitado);
    }
}


void submenu(Usuario u[],int indice_usuario,int opcion) {
    int sub_opcion = 0;
    printf("\nBienvenido %s", u->usuario[indice_usuario]);
    printf("\nElige que quieres hacer:");
    while (sub_opcion != 4) {
        printf("\n 1. Enviar solicitudes");
        printf("\n 2. Revisar solicitudes");
        printf("\n 3. Visitar perfil");
        printf("\n 4. Volcer al menu principal");
        scanf("%d", &sub_opcion);
        if(opcion==1){
            //enviar_solicitud(Usuario u[]);
        }
    }
}