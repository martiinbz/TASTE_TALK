//
// Created by marti on 31/05/2023.
#include "estructuras.h"

int busqueda_secuencial(char **lista_de_usuarios, int numero_de_usuarios, char *usuario_buscado) {
    for (int i = 0; i < numero_de_usuarios; i++) {
        if (strcmp(lista_de_usuarios[i], usuario_buscado) == 0) {
            return i;
        }
    }
    return -1;
}
int iniciar_sesion(Usuario u[],char *contrasena,int posicion){
    if(strcmp(contrasena,u[posicion].contrasena)==0){
        return 1;
    }
    else return 0;
}
void ver_perfil(Usuario u[],int indice_usuario){
    printf("\n=============================");
    printf("\n %s\n",u[indice_usuario].usuario);
    printf("=============================\n");
    printf("\nNombre: %s\t Edad:%d\t Ubicacion:%s \t Plato favorito:%s\n",u[indice_usuario].nombre,*u[indice_usuario].edad,u[indice_usuario].ubicacion,u[indice_usuario].platos_favoritos);
    printf("---------Amigos---------\n");
    imprimir_lista_amigos(indice_usuario,u);
    printf("---------Publicaciones---------\n");
    verPublicacionesPropias(u,indice_usuario);
}