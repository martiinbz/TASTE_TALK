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
//***ESTRUCTURA DE LA COLA PARA MANEJAR SOLICITUDES***//
typedef struct {
    int senderId;
    int receiverId;
} FriendRequest;
//**ESTRUCTURA PARA LAS PUBLICACIONES**//
typedef struct {
    char texto[121]; // 120 caracteres para el texto de la publicación + 1 para el carácter nulo
} Publicacion;

//***ESTRUCTURA PARA LOS AMIGOS***//
typedef struct{
    char nombre_amigo[20];
}Amigos;
//****ESTRUCTURA PARA LA INFORMACIÓN DE LOS USUARIOS****
 typedef struct {
    int *id;
    char usuario[20];
    char nombre[50];
    char email[50];
    int edad[2];
    Publicacion publicaciones[MAX_PUBLICACIONES];
    int num_publicaciones;
    char platos_favoritos[500];
    char ubicacion[500];
    char contrasena[20];
    int num_amigos;
    Amigos nombre_amigos[20];
    int receivedFriendRequests[50]; // IDs de las solicitudes de amistad recibidas
    int numReceivedFriendRequests; // Número de solicitudes de amistad recibidas
} Usuario;
 ///ESTRUCTURA PARA CONTAR LAS PALABRAS(DICCIONARIO)///
typedef struct {
    char palabra[100];
    int conteo;
} ConteoPalabras;

// Funciones para manejar la red social
void recopilar_datos(Usuario u[], int numero_de_usuarios);
void menu_principal(Usuario u[]);
int busqueda_secuencial(char **lista_de_usuarios, int numero_de_usuarios, char *usuario_buscado);
int iniciar_sesion(Usuario u[],char *contrasena,int posicion);
void submenu(char **lista_de_usuarios,Usuario u[],int indice_usuario,int numero_de_usuarios);
void sendFriendRequest(int senderId, int receiverId);
void manageFriendRequests(int userId,Usuario u[]);
void realizar_publicacion(Usuario usuario[],int indice_usuario);
void verPublicacionesPropias(Usuario u[], int indice_usuario);
void contarPalabras(Usuario* u, int numero_de_usuario, ConteoPalabras* conteo, int* numPalabras);
void imprimirPalabrasMasUsadas(ConteoPalabras* conteo, int numPalabras);
void imprimir_lista_amigos(int userId, Usuario u[]);
void ver_perfil(Usuario u[],int indice_usuario);
void sugerencias_amistad(Usuario u[], int numero_usuarios, int indice_usuario);

