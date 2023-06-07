#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "estructuras.h"

void submenu(char **lista_de_usuarios,Usuario u[],int indice_usuario,int numero_de_usuarios) {
    int sub_opcion = 0;
    printf("\nElige que quieres hacer:");
    while (sub_opcion != -1) {
        printf("\n 1. Enviar solicitudes");
        printf("\n 2. Revisar solicitudes");
        printf("\n 3. Realizar una publicacion");
        printf("\n 4. Ver mi perfil");
        printf("\n 5. Buscar usuario");
        printf("\n 6. Cerrar sesion");
        scanf("%d", &sub_opcion);
        if (sub_opcion == 1) {
            char nombre_receptor[20];
            printf("Introduce el usuario de destino");
            scanf("%s", nombre_receptor);
            // enviar_solicitud_amistad( lista_de_usuarios, u, indice_usuario,  numero_de_usuarios,nombre_receptor);
            int indice_receptor = busqueda_secuencial(lista_de_usuarios, numero_de_usuarios, nombre_receptor);
            sendFriendRequest(indice_usuario, indice_receptor);
        }
        if (sub_opcion == 2) {
            //revisar_solicitudes_amistad( u, indice_usuario);
            manageFriendRequests(indice_usuario, u);
        }
        if (sub_opcion == 3) {
            realizar_publicacion(u, indice_usuario);
        }
        if (sub_opcion == 4) {
            ver_perfil( u, indice_usuario);
        }
        if(sub_opcion==5){
            char usuario_a_buscar[20];
            int encontrado=0;
            printf("Introduce el usuario a buscar(debe de ser tu amigo):");
            scanf("%s",usuario_a_buscar);
            int indice_usuario_a_buscar=busqueda_secuencial(lista_de_usuarios, numero_de_usuarios, usuario_a_buscar);
            if(indice_usuario_a_buscar==-1){
                printf("No se ha encontrado al usuario");
            }
            for(int i=0;i<u[indice_usuario].num_amigos;i++){
                if(strcmp(u[indice_usuario_a_buscar].usuario,u[indice_usuario].nombre_amigos[i].nombre_amigo)==0){
                    ver_perfil( u, indice_usuario_a_buscar);
                    encontrado++;
                }
            }
            if(encontrado==0){
                printf("El usuario no se encuentra en tu lista de amigos");
            }


        }
        if(sub_opcion==6){
            printf("\n Cerrando sesion...");
            break;
        }
    }
}