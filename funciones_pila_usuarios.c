//
// Created by marti on 20/05/2023.

//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Estructuras_pila.h"
#include "estructuras.h"



void push(char pila[],int *top,char *usuario,int MAXSIZE){
    if(*top >=MAXSIZE-1){
        printf("La pila está llena");
        return;
    }
    (*top)++;
    strcpy(&pila[*top],usuario);

}
void pop(char pila[],int top,int MAXSIZE){
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

}