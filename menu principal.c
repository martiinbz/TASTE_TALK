#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "estructuras.h"

int menu(){
    int n, opcion, edad;
    char username[20], contra[20],name[20], email[50], ubicación,platos;
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
        char stack_usuarios= newStack( capacity);
        push( stack_usuarios,  *u.usuario);
    };

    if (opcion == 2) {
        


    };