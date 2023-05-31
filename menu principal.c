#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "estructuras.h"





// Función para el submenú del usuario

void recopilar_datos( Usuario u[],int numero_de_usuarios){ //con esto se pregunta y se almacena la info en la estructura
    printf("\n Introduce tu nombre");
    getchar();
    fgets(u[numero_de_usuarios].nombre,20,stdin);

    printf("\n Introduce tu nombre de usuario");
    fgets(u[numero_de_usuarios].usuario,20,stdin);

    printf("\n Introduce tu contrasena");
    fgets(u[numero_de_usuarios].contrasena,20,stdin);    //FALTA TRATAR LOS ERRORES(poner una letra en la edad, requisitos contras y eso)

    printf("\nIntroduce tu edad");
    scanf("%d",&u[numero_de_usuarios].edad);

    printf("\nIntroduce tu email");
    getchar();
    gets(u[numero_de_usuarios].email);

    printf("\nDe donde eres?");
    fgets(u[numero_de_usuarios].ubicacion,20,stdin);

    printf("\nCuales son tus 5 platos favoritos? Introducelos separados por una coma");
    gets(u[numero_de_usuarios].platos_favoritos);
    printf("\n El usuario %s se ha registrado correctamente!",u[numero_de_usuarios].usuario);

    //printf("\n Name: %s \n User: %s  \n contra: %s \n edad: %d \n email: %s \n ubi: %s \n platos: %s",u[numero_de_usuarios].nombre,u[numero_de_usuarios].usuario,u[numero_de_usuarios].contrasena,*u[numero_de_usuarios].edad,u[numero_de_usuarios].email,u[numero_de_usuarios].ubicacion,u[numero_de_usuarios].platos_favoritos);
    //esto es para imprimir los datos recolectados, por si hay algun error y necesitamos mirar si los recolecta bien
};


void menu_principal(Usuario u[]) {
    int opcion=0,numero_de_usuarios=0;
    char **lista_de_usuarios;
    lista_de_usuarios=(char**)malloc(sizeof(char*)*(numero_de_usuarios+1));//creamos la lista dinamica con capacidad inicial 1

    printf("\n Welcome to Taste Talk!\n");
    while(opcion!=4){
        printf("\n 1. Registarse");
        printf("\n 2. Lista de Usuarios registrados");
        printf("\n 3. Iniciar sesion");
        printf("\n 4.Salir de la aplicacion");
        scanf("%d", &opcion);
        if (opcion == 1) {
            recopilar_datos(u,numero_de_usuarios); //preguntamos al usuario los datos necesarios
            lista_de_usuarios[numero_de_usuarios]=u[numero_de_usuarios].usuario; //metemos el nombre de usuario en la lista
            numero_de_usuarios += 1; //incrementamos el contador de usuarios
            lista_de_usuarios=(char**)realloc(lista_de_usuarios,sizeof(char*)*(numero_de_usuarios+1));//añadimos más memoria en caso de que se tenga que agregar un nuevo user.

        }
        if(opcion==2){
            printf("\nHay %d usuarios registrados,son:\n",numero_de_usuarios);
            for(int i=0;i<=(numero_de_usuarios-1);i++){
                printf("%s",lista_de_usuarios[i]); //esto va imprimiendo la lista de ususarios
            }
        }
        if(opcion==3){
            printf("\nPROXIMAMENTE\n");
        }
        if(opcion==4){
            printf("\nGracias por usar nuestra aplicacion!\n Hecha por:\n Martin Barcena \n Arnau Gil \n Adria Casals");

        }
        else{
            printf("\nSelecciona una opcion valida");
        }
    }
}