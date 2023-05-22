#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "estructuras.h"




// Función para inicializar la red social
void inicializar_red_social(struct Red_social *red_social) {
    red_social->numero_de_usuarios=0;
}
int contador_usuarios(struct Red_social *red_social){
    red_social->numero_de_usuarios+=1;
    return red_social->numero_de_usuarios;
}
// Función para insertar un nuevo usuario en la red social
/*
void insertar_usuario(RedSocial* red_social,char *nombre,char *email) {
    Usuario nuevo_usuario;
    llenar_datos_usuario(&nuevo_usuario);

    NodoUsuario* nuevo_nodo = (NodoUsuario*)malloc(sizeof(NodoUsuario));
    nuevo_nodo->usuario = nuevo_usuario;
    nuevo_nodo->siguiente = NULL;

    if (red_social->cabeza == NULL) {
        red_social->cabeza = nuevo_nodo;
    } else {
        NodoUsuario* actual = red_social->cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
    }

    red_social->num_usuarios++;

    printf("Usuario agregado correctamente.\n");
}

// Función para listar todos los usuarios de la red social
void listar_usuarios(const RedSocial* red_social) {
    printf("Usuarios registrados:\n");
    NodoUsuario* actual = red_social->cabeza;
    while (actual != NULL) {
        printf("- %s\n", actual->usuario.nombre);
        actual = actual->siguiente;
    }
}


/*
 void listarUsuarios(Usuario usuarios[], int numUsuarios) {
    printf("Lista de usuarios registrados:\n");
    for (int i = 0; i < numUsuarios; i++) {
        printf("Usuario %d:\n", i + 1);
        printf("Nombre: %s\n", usuarios[i].nombre);
        printf("Edad: %d\n", usuarios[i].edad);
        printf("\n");
    }
}

 */
// Función para el submenú del usuario
int contar_numero_de_usuarios(Usuario u[]){
    for(int i=0;i<20;i++){
        if (&u[i].nombre==NULL){
            printf("hay %d usuarios registraos",i);
        };
    }
    printf("puta");
}
void recopilar_datos( Usuario u[],int numero_de_usuarios){

    u[numero_de_usuarios].id=numero_de_usuarios;
    printf("\n Introduce tu nombre");
    getchar();
    fgets(u[numero_de_usuarios].nombre,20,stdin);

    printf("\n Introduce tu nombre de usuario");
    fgets(u[numero_de_usuarios].usuario,20,stdin);

    printf("\n Introduce tu contraseña");
    fgets(u[numero_de_usuarios].contrasena,20,stdin);

    printf("\nIntroduce tu edad");
    scanf("%d",&u[numero_de_usuarios].edad);

    printf("\nIntroduce tu email");
    getchar();
    gets(u[numero_de_usuarios].email);

    printf("\nDe donde eres?");
    fgets(u[numero_de_usuarios].ubicacion,20,stdin);

    printf("\nCuales son tus 5 platos favoritos? Introducelos separados por una coma");
    gets(u[numero_de_usuarios].platos_favoritos);

    printf("\n ID: %d\n Name: %s \n User: %s  \n contra: %s \n edad: %d \n email: %s \n ubi: %s \n platos: %s",u[numero_de_usuarios].nombre,u[numero_de_usuarios].usuario,u[numero_de_usuarios].contrasena,*u[numero_de_usuarios].edad,u[numero_de_usuarios].email,u[numero_de_usuarios].ubicacion,u[numero_de_usuarios].platos_favoritos);

};


void menu_principal(Usuario u[]) {
    int opcion=1000;
    while(opcion!=4){
        int numero_de_usuarios=0;
        printf("\n 1. Registarse");
        printf("\n 2. Lista de Usuarios registrados");
        printf("\n 3. Iniciar sesion");
        printf("\n 4.Salir de la aplicación");
        scanf("%d", &opcion);
        if (opcion == 1) {
            recopilar_datos(u,numero_de_usuarios);
            numero_de_usuarios+=1;





        }
    }
}