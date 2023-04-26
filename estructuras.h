//
// Created by 34693 on 26/04/2023.
//

#ifndef EDA2_ESTRUCTURAS_H
#define EDA2_ESTRUCTURAS_H

#endif //EDA2_ESTRUCTURAS_H

typedef struct{
    char nombre[20];
    char username[20];
    char contrasena;
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
struct pila_usuarios {
    struct usuario *usuarios;
    int contador;
    int top;
};

struct stack{
    char names[20];
    int size;
};