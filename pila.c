#include "estructuras.h"

//
// Created by marti on 17/05/2023.
//
struct stack newStack(int capacity) {
    stack stack_usuarios;
    stack_usuarios.maxsize = capacity;
    stack_usuarios.top = -1;
    return stack_usuarios;
}
int isempty(struct stack stack_usuarios) {
    return stack_usuarios.top < 0;
}

void push(struct stack stack_usuarios, char *name) {
    if (isempty(stack_usuarios)) {
        printf("La pila está vacia");
    };
    stack_usuarios.top++;
    stack_usuarios.usuario[stack_usuarios.top] = *name;
}

char pop(struct stack stack_usuarios) {
    if (isempty(stack_usuarios)) {
        printf("La pila está vacia");
    };
    char auxiliar = stack_usuarios.usuario[stack_usuarios.top];
    stack_usuarios.top--;
    return auxiliar;
};