//
// Created by marti on 20/05/2023.

//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "estructuras.h"
//********ESTO ES PARA UNA PILA DINÁMICA(FUNCIONA PERO AUN NO LA USAMOS)*******


/*void  init_pila(struct stack*pila) {
    struct stack *stack = malloc(sizeof(struct stack));
    stack->top = -1;
    stack->capacity = 10; //asignamos unos valores de capacidad inicial
    stack->username = malloc(sizeof(char *) * stack->capacity);
}

void push_user(struct stack *stack, char *string) {
    if (stack->top == stack->capacity - 1) {
        stack->capacity *= 2;
        stack->username = realloc(stack->username, sizeof(char) * stack->capacity);
    }
    stack->top+=1;
    strcpy(stack->username[stack->top],string);

}

void print_stack(struct stack *stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%s\n", &stack->username[i]);
    }
}
*/