//
// Created by 34693 on 26/04/2023.
//

#ifndef EDA2_ESTRUCTURAS_H
#define EDA2_ESTRUCTURAS_H

#endif //EDA2_ESTRUCTURAS_H

#ifndef UNTITLED9_STRUCTS_H
#define UNTITLED9_STRUCTS_H

#endif //UNTITLED9_STRUCTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USUARIOS 100
#define MAX_AMIGOS 100
#define MAX_SOLICITUDES 100
#define MAX_PUBLICACIONES 100

typedef struct {
    int id;
    char usuario[20];
    char nombre[50];
    char email[50];
    char edad[2];
    int num_amigos;
    int amigos[MAX_AMIGOS]; // Arreglo para guardar los IDs de amigos
    int num_publicaciones;
    int solicitudes_amistad[MAX_SOLICITUDES];
    int num_solicitudes;
    char publicaciones[MAX_PUBLICACIONES][500]; // Arreglo para guardar las publicaciones del usuario
    char platos_favoritos[500];
    char ubicacion[500];
    char contrasena[20];
} Usuario;

// Definimos la estructura de la red social
typedef struct {
    int num_usuarios;
    Usuario usuarios[MAX_USUARIOS]; // Arreglo para guardar todos los usuarios de la red social
} RedSocial;

// Funciones para manejar la red social
void menu(Usuario u);
void inicializar_red_social(RedSocial *red_social);
int insertar_usuario(RedSocial *red_social, char *nombre, char *email);
void listar_usuarios(RedSocial red_social);
void submenu_usuario(RedSocial *red_social, int id_usuario);
void enviar_solicitud_amistad(RedSocial *red_social, int id_emisor, int id_receptor);
void gestionar_solicitudes_pendientes(RedSocial *red_social, int id_usuario);
void realizar_publicacion(RedSocial *red_social, int id_usuario, char *publicacion);
void listar_publicaciones_usuario(RedSocial red_social, int id_usuario);







/*
typedef struct{
    int cantidad_de_usuarios;
    char nombre[20];
    char username[20];
    char contrasena[20];
    int edad;
    char email;
    int amigos;
    char ubicación;
    char platos_favoritos;

}Usuario;

struct usuario{
    int x;
    int y;
};


/*
 * Vamos a usar otra estructura para representar la pila, majenar la pila con
 * una estructura es mas practico que tener 3 o 4 independientes para hacerlo.
 */
typedef struct stack {
    char usuario[20];
    int maxsize;
    int top;
};

