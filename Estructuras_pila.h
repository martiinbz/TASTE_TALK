//
// Created by marti on 20/05/2023.
//

#ifndef EDA2_ESTRUCTURAS_PILA_H
#define EDA2_ESTRUCTURAS_PILA_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#endif //EDA2_ESTRUCTURAS_PILA_H

typedef struct pila_usuarios{
    char usuario[20];
    struct pila_usuarios *siguiente;
};


