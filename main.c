#include <stdio.h>
#include "estructuras.h"
#include "Estructuras_pila.h"

int main(){
    Usuario u[5];
    struct pila_usuarios pila_usuarios;
    menu_principal(u,pila_usuarios,pila_usuarios);

};

int read_option(void){
    int value;
    if(scanf("%d", &value) != 1)
        return -1;
    return value;
}

void show_user_menu(void){
    int option =-1;
    while(option!=5)  //aqui supongo que la opcion 5 es salir
        if(option == 1){

        }
}