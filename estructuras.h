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

//***ESTRUCTURA DE LA PILA DINÁMICA***
struct stack {
    int top;
    int capacity;
    char username[20][20];
};
//****ESTRUCTURA PARA LA INFORMACIÓN DE LOS USUARIOS****
 typedef struct {
    int *id;
    char usuario[20];
    char nombre[50];
    char email[50];
    char edad[2];
    int num_amigos;
    int amigos[MAX_AMIGOS];
    int num_publicaciones;
    int solicitudes_amistad[MAX_SOLICITUDES];
    int num_solicitudes;
    char publicaciones[MAX_PUBLICACIONES][500];
    char platos_favoritos[500];
    char ubicacion[500];
    char contrasena[20];
} Usuario;


// Funciones para manejar la red social
void recopilar_datos(Usuario u[], int numero_de_usuarios);
void almacenar_datos();
void push_user(struct stack *stack, char *string);
void print_stack(struct stack *stack);
void  init_pila(struct stack*pila);
void menu_principal(Usuario u[]);
int busqueda_secuencial(char **lista_de_usuarios, int numero_de_usuarios, char *usuario_buscado);
int iniciar_sesion(Usuario *u[],char *contrasena,int posicion);

