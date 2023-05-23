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
struct Stack {
    char data[100][100];
    int top;
};


 typedef struct {
    int *id;
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

struct Red_social{
    char *username;
    int numero_de_usuarios;
    struct Red_social *siguiente;
};

// Funciones para manejar la red social
void menu_principal(Usuario u[]);
void init(struct Stack* stack);
void recopilar_datos(Usuario u[], int numero_de_usuarios);
void almacenar_datos();
void push(struct Stack* stack, char* str);
/*void push(char *pila[],int *top,char usuario[],int MAXSIZE);
int contar_numero_de_usuarios(Usuario u[]);







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



