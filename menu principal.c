#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "estructuras.h"




// Función para inicializar la red social
void inicializar_red_social(RedSocial *red_social) {
    red_social->num_usuarios = 0;
}

void llenar_datos_usuario(Usuario *usuario) {
    printf("Ingrese el nombre del usuario: ");
    scanf("%s", usuario->nombre);
    // Agrega aquí más instrucciones para llena
    // r otros datos básicos del usuario
}

// Función para insertar un nuevo usuario en la red social
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

void menu(Usuario u) {
    int n, opcion, edad, capacity = 20;
    char username[20], contra[20], name[20], email[50], ubicacion, platos;
    printf("\n 1. Insertar nuevo usuario");
    printf("\n 2. Listar todos los usuarios existentes");
    printf("\n 3. Operar como un usuario específico");

    scanf("%d", &opcion);

    if (opcion == 1) {
        int n, opcion, edad;
        char username[20], contra[20], name[20], email[50], ubicacion, platos;
        printf("\n Introduce tu nombre");
        scanf("%s", name);
        strcpy(u.nombre, name);
        printf("\n Introduce tu nombre de usuario");
        scanf("%s", username);
        strcpy(u.usuario, username);
        printf("\n Introduce tu contraseña");
        scanf("%s", contra);
        strcpy(u.contrasena, contra);

        printf("Introduce tu edad");

        printf("Introduce tu email");
        scanf("%s", email);
        strcpy(u.email, email);

        printf("De dónde eres? (Barcelona / Girona / Tarragona / Lleida)");
        scanf("%s", ubicacion);
        strcpy(u.ubicacion, &ubicacion);
        printf("Cuáles son tus 5 platos favoritos? Introducelos separados por una coma");
        scanf("%s", platos);
        strcpy(u.platos_favoritos, &platos);
        char  stack_usuarios = newStack(capacity);
        push(stack_usuarios, *u.usuario);
    };

    if (opcion == 2) {
        pop(stack_usuarios);
    }
}