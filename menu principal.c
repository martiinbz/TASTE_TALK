#include <stdio.h>

int menu(){
    int n, opcion, edad;
    char username[20], contra[20],name[20], email[50], ubicación,platos;
    printf("\n 1. Insertar nuevo usuario");
    printf("\n 2. Listar todos los usuarios existentes");
    printf("\n 3. Operar como un usuario específico");

    scanf("%d", &opcion);

    if(opcion==1){

        printf("\n Introduce tu nombre");
        scanf("%s", name);
        printf("\n Introduce tu nombre de usuario");
        scanf("%s", username);
        printf("\n Introduce tu contraseña");
        scanf("%s", contra);
        while(sizeof(contra)<6) {
            printf("\n La contraseña debe conter al menos 6 carácteres. Repítela.");
            scanf("%s", contra);
        }
        printf("Introduce tu edad");
        scanf("%i", edad);
        while(edad<12){
            printf("\n Debes tener, como mínimo, 12 años para crear un usuario");
            scanf("%i", edad);
        }
        printf("Introduce tu email");
        scanf("%s", email);
    }
        printf("De dónde eres? (Barcelona / Girona / Tarragona / Lleida)");
        scanf("%s", ubicación);

        printf("Cuáles son tus 5 platos favoritos? Introducelos separados por una coma");
        scanf("%s",platos);




    if(opcion==2)


};



void init_stack(struct stack *s){
    s->size=0;
}
void push(struct stack *s, char *name){
    if (s->size >= 20){
        printf("La pila esta llena");
        return;
    }
    strcpy(s->names[s->size], name);
    s->size++;
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
