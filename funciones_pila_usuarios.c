//
// Created by marti on 20/05/2023.

//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Estructuras_pila.h"
#include "estructuras.h"

struct pila_usuarios *crear_pila(char usuario ){
    struct pila_usuarios *usuarios=malloc(sizeof(struct pila_usuarios));
    strcpy(usuarios->usuario,&usuario);
    usuarios->siguiente=NULL;
    return usuarios;
}
int push(struct pila_usuarios **stack,char usuario){
    struct pila_usuarios *usuarios= crear_pila(usuario);
    strcpy(usuarios->siguiente,&usuario);
    *stack=usuarios;
}

char pop(struct pila_usuarios **stack){
    if(*stack==NULL){
        return -1;
    }
    struct pila_usuarios *usuarios=*stack;
    char usuario_pop[20];
    strcpy(usuario_pop,usuarios->usuario);
    *stack=usuarios->siguiente;
    free(usuarios);
    return usuario_pop[20];
}
int isempty(struct pila_usuarios *stack){
    return stack==NULL;
}
void imprimir_pila(struct pila_usuarios *stack){
    while(stack!=NULL){
        printf("%s\n",stack->usuario);
        stack=stack->siguiente;
    }
}