#include <stdio.h>
#include "estructuras.h"


int main(){
    Usuario u[5];
    menu_principal(u);
    int numero_de_usuarios;
    contar_numero_de_usuarios(u);
    numero_de_usuarios=contar_numero_de_usuarios(u);
    recopilar_datos(u,numero_de_usuarios);
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