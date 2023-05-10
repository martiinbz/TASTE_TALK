//
// Created by 34693 on 26/04/2023.
//

#ifndef EDA2_ESTRUCTURAS_H
#define EDA2_ESTRUCTURAS_H

#endif //EDA2_ESTRUCTURAS_H

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

