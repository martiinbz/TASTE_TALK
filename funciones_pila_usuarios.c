//
// Created by marti on 20/05/2023.

//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Estructuras_pila.h"
#include "estructuras.h"


// Initialize the stack
void init(struct Stack* stack) { //funcion para inicializar la pila
    stack->top = -1;
}

// Push a string onto the stack
void push(struct Stack* stack, char* str){ //funcion para hacer push
    if (stack->top == 20 - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->top+=1;
    strcpy(stack->data[stack->top], str);
}

/*void pop(char pila[],int top,int MAXSIZE){   //esta creo que no funciona
    if(top==-1){
        printf("La pila está vacía!");
    }
    else{
        printf("Se ha eliminado a %s",pila[top]);
        if (top==MAXSIZE-1){
            top=-1;
        }
        else{
            top--;
        }

    }

}*/