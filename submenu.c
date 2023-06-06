#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "estructuras.h"

//
// Created by marti on 31/05/2023.
//
void enviar_solicitud(Usuario u[]){   //funcion que usaremos para enviar solicitudes a usuarios.txt ya registrados
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


void submenu(char **lista_de_usuarios,Usuario u[],int indice_usuario,int numero_de_usuarios) {
    int sub_opcion = 0;
    printf("\nElige que quieres hacer:");
    while (sub_opcion != 4) {
        printf("\n 1. Enviar solicitudes");
        printf("\n 2. Revisar solicitudes");
        printf("\n 3. Realizar una publicacion");
        printf("\n 4. Observar las publicaciones");
        scanf("%d", &sub_opcion);
        if(sub_opcion==1){
            char nombre_receptor[20];
            printf("Introduce el usuario de destino");
            scanf("%s",nombre_receptor);
           // enviar_solicitud_amistad( lista_de_usuarios, u, indice_usuario,  numero_de_usuarios,nombre_receptor);
           int indice_receptor= busqueda_secuencial(lista_de_usuarios,numero_de_usuarios,nombre_receptor);
            sendFriendRequest( indice_usuario,  indice_receptor);
        }
        if(sub_opcion==2){
             //revisar_solicitudes_amistad( u, indice_usuario);
             manageFriendRequests(indice_usuario,u);
        }
        if(sub_opcion==3){
            realizar_publicacion(u,indice_usuario);
        }
        if(sub_opcion==4){
            verPublicacionesPropias(u, indice_usuario);
        }
    }
}