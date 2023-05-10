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

    if(opcion==1){
        int n, opcion, edad;
        char username[20], contra[20],name[20], email[50], ubicación,platos;
        printf("\n Introduce tu nombre");
        scanf("%s", name);
        strcpy(u->nombre,name);
        printf("\n Introduce tu nombre de usuario");
        scanf("%s", username);
        strcpy(u->username,username);
        printf("\n Introduce tu contraseña");
        scanf("%s", contra);
        strcpy(u->contrasena,contra);

        printf("Introduce tu edad");
        scanf("%i", edad);
        while(edad<12){
            printf("\n Debes tener, como mínimo, 12 años para crear un usuario");
            scanf("%i", edad);
        }
        u->edad=edad;
        printf("Introduce tu email");
        scanf("%s", email);
        strcpy(&u->email,email);

        printf("De dónde eres? (Barcelona / Girona / Tarragona / Lleida)");
        scanf("%s", ubicación);
        strcpy(&u->ubicación,&ubicación);
        printf("Cuáles son tus 5 platos favoritos? Introducelos separados por una coma");
        scanf("%s",platos);
        strcpy(&u->platos_favoritos,&platos);
    };

    if(opcion==2);

};

struct stack* newStack(int capacity)
{
    stack stack_usuarios;
    stack_usuarios.maxsize = capacity;
    stack_usuarios.top = -1;
    return  &stack_usuarios;
}
int isempty(struct stack stack_usuarios){
    return stack_usuarios.top<0;
}

void push(struct stack stack_usuarios, char *name){
    if (isempty(  stack_usuarios)){
        printf("La pila está vacia");
    };
    stack_usuarios.top++;
    stack_usuarios.usuario[stack_usuarios.top]=*name;
}

void pop(struct stack *s){
    if (s->size <= 0){
        printf("La pila esta vacia");
        return;
    }
    s->size--;
}
char* top(struct stack *s) {
    if (s->size <= 0) {
        printf("La pila esta vacia");
        return NULL;
    }
    return s->names[s->size-1];
}
