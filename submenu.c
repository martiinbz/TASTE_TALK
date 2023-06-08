#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "estructuras.h"

void submenu(char **lista_de_usuarios,Usuario u[],int indice_usuario,int numero_de_usuarios) {
    int sub_opcion = 0;
    printf("\nElige que quieres hacer:");
    while (sub_opcion != -1) {
        printf("\n 1. Enviar solicitud de amistad");
        printf("\n 2. Revisar solicitudes pendientes");
        printf("\n 3. Sugerencias de amistad");
        printf("\n 4. Realizar una publicacion");
        printf("\n 5. Ver mi perfil");
        printf("\n 6. Buscar usuario");
        printf("\n 7. Cerrar sesion");
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
            manageFriendRequests(indice_usuario, u); //se gestiona las solicitudes del usuario
        }
        if(sub_opcion==3){
            sugerencias_amistad( u,  numero_de_usuarios,  indice_usuario);
        }
        if (sub_opcion == 4) {
            realizar_publicacion(u, indice_usuario);
        }
        if (sub_opcion == 5) {
            ver_perfil( u, indice_usuario);
        }
        if(sub_opcion==6){
            char usuario_a_buscar[20];
            int encontrado=0;
            printf("Introduce el usuario a buscar(debe de ser tu amigo!):"); //el usuario introduce el nombre de su amigo que quiere buscar
            scanf("%s",usuario_a_buscar);
            int indice_usuario_a_buscar=busqueda_secuencial(lista_de_usuarios, numero_de_usuarios, usuario_a_buscar); //obtenemos la id del amigo
            if(indice_usuario_a_buscar==-1){
                printf("No se ha encontrado al usuario");
            }
            for(int i=0;i<u[indice_usuario].num_amigos;i++){ //vamos comparando el nombre del amigo con la lista de amigos del usuario
                if(strcmp(u[indice_usuario_a_buscar].usuario,u[indice_usuario].nombre_amigos[i].nombre_amigo)==0){
                    ver_perfil( u, indice_usuario_a_buscar); //si se encuentra en la lista, accedemos a su perfil
                    encontrado++;
                }
            }
            if(encontrado==0){
                printf("El usuario no se encuentra en tu lista de amigos");
            }


        }
        if(sub_opcion==7){
            printf("\n Cerrando sesion..."); //se vuelve al menu principal
            break;
        }
    }
}