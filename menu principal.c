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



 struct Usuario *preguntas(int numero_de_usuarios){
    Usuario u[numero_de_usuarios];
    u->id=numero_de_usuarios;
    printf("\n Introduce tu nombre");
    gets(u[numero_de_usuarios].nombre);
    printf("\n Introduce tu nombre de usuario");
    gets(u[numero_de_usuarios].usuario);
    printf("\n Introduce tu contraseña");
    gets(u[numero_de_usuarios].contrasena);
    printf("\nIntroduce tu edad");
    scanf("%d",&u[numero_de_usuarios].edad);
    printf("\nIntroduce tu email");
    gets(u[numero_de_usuarios].email);
    printf("\nDe dónde eres?");
    gets(u[numero_de_usuarios].ubicacion);
    printf("\nCuáles son tus 5 platos favoritos? Introducelos separados por una coma");
    gets(u[numero_de_usuarios].platos_favoritos);
    return &u[numero_de_usuarios];
}

void agregar_usuario(struct Red_social*red_social){
   preguntas( red_social->numero_de_usuarios);








void menu_principal() {
    Usuario usuario;
    struct Red_social red_social;
    int opcion;
    printf("\n 1. Insertar nuevo usuario");
    printf("\n 2. Listar todos los usuarios existentes");
    printf("\n 3. Operar como un usuario específico");

    scanf("%d", &opcion);

    if (opcion == 1) {
        agregar_usuario();



    }
}