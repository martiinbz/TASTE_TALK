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
    fgets(u[numero_de_usuarios].email,20,stdin);

    printf("\nDe donde eres?");
    fgets(u[numero_de_usuarios].ubicacion,20,stdin);

    printf("\nCuales son tus 5 platos favoritos? Introducelos separados por una coma");
    gets(u[numero_de_usuarios].platos_favoritos);
    printf("\n El usuario %s se ha registrado correctamente!",u[numero_de_usuarios].usuario);

    //printf("\n Name: %s \n User: %s  \n contra: %s \n edad: %d \n email: %s \n ubi: %s \n platos: %s",u[numero_de_usuarios].nombre,u[numero_de_usuarios].usuario,u[numero_de_usuarios].contrasena,*u[numero_de_usuarios].edad,u[numero_de_usuarios].email,u[numero_de_usuarios].ubicacion,u[numero_de_usuarios].platos_favoritos);
    //esto es para imprimir los datos recolectados, por si hay algun error y necesitamos mirar si los recolecta bien
};

/*int recopilar_datos_fichero(Usuario u[],int numero_de_usuarios,FILE* fichero,char *lista_de_usuarios[]){
   while(fscanf(fichero,"%s %s %d %s %s %s %s",  u[numero_de_usuarios].nombre,u[numero_de_usuarios].usuario, &u[numero_de_usuarios].edad, u[numero_de_usuarios].contrasena, u[numero_de_usuarios].email, u[numero_de_usuarios].ubicacion, u[numero_de_usuarios].platos_favoritos)>0){
       lista_de_usuarios[numero_de_usuarios]=u[numero_de_usuarios].usuario; //metemos el nombre de usuario en la lista
       numero_de_usuarios += 1; //incrementamos el contador de usuarios.txt
       lista_de_usuarios=(char**)realloc(lista_de_usuarios,sizeof(char*)*(numero_de_usuarios+1));//añadimos más memoria en caso de que se tenga que agregar un nuevo user.
   }
   return numero_de_usuarios;
}
 */
void menu_principal(Usuario u[]) {
    FILE *fichero;
    char filename[] = "courses.txt";
    fichero = fopen(filename, "r");
    if (fichero == NULL) {
        printf("Error opening file %s\n", filename);
    }
    int opcion=0,numero_de_usuarios=0;
    char **lista_de_usuarios;
    lista_de_usuarios=(char**)malloc(sizeof(char*)*(numero_de_usuarios+1));//creamos la lista dinamica con capacidad inicial 1

    printf("\n Welcome to Taste Talk!\n");
    while(opcion<6){
        printf("\n 1. Registarse");
        printf("\n 2. Registrar usuarios.txt desde un fichero");
        printf("\n 3. Lista de Usuarios registrados");
        printf("\n 4. Iniciar sesion");
        printf("\n 5.Salir de la aplicacion");
        scanf("%d", &opcion);
        if (opcion == 1) {
            recopilar_datos(u,numero_de_usuarios); //preguntamos al usuario los datos necesarios
            lista_de_usuarios[numero_de_usuarios]=u[numero_de_usuarios].usuario; //metemos el nombre de usuario en la lista
            numero_de_usuarios += 1; //incrementamos el contador de usuarios.txt
            lista_de_usuarios=(char**)realloc(lista_de_usuarios,sizeof(char*)*(numero_de_usuarios+1));//añadimos más memoria en caso de que se tenga que agregar un nuevo user.

        }
        if(opcion==2){
            while(fscanf(fichero,"%s %s %d %s %s %s %s",  u[numero_de_usuarios].nombre,u[numero_de_usuarios].usuario, &u[numero_de_usuarios].edad, u[numero_de_usuarios].contrasena, u[numero_de_usuarios].email, u[numero_de_usuarios].ubicacion, u[numero_de_usuarios].platos_favoritos)>0){
                lista_de_usuarios[numero_de_usuarios]=u[numero_de_usuarios].usuario; //metemos el nombre de usuario en la lista
                numero_de_usuarios += 1; //incrementamos el contador de usuarios.txt
                lista_de_usuarios=(char**)realloc(lista_de_usuarios,sizeof(char*)*(numero_de_usuarios+1));//añadimos más memoria en caso de que se tenga que agregar un nuevo user.
            }
        }
        if(opcion==3){
            printf("\nHay %d usuarios registrados,son:\n",numero_de_usuarios);
            for(int i=0;i<=(numero_de_usuarios-1);i++){
                printf("%s\n",lista_de_usuarios[i]); //esto va imprimiendo la lista de ususarios
            }
        }
        if(opcion==4){
            if(numero_de_usuarios==0) { //si aun no hay usuarios registrados
                printf("\nNo hay usuarios registrados");
            }
            else{
                char usuario_buscado[20];
                printf("\nIntroduce el nombre de usuario: ");//el usuario introduce el nombre de usuario a buscar
                getchar();
                fgets(usuario_buscado, 20, stdin);

                int indice_usuario = busqueda_secuencial(lista_de_usuarios, numero_de_usuarios, usuario_buscado);
                printf("%d",indice_usuario);

                if (indice_usuario != -1) {
                    printf("\nUsuario encontrado: %s", u[indice_usuario].usuario);
                    char contra[20];
                    printf("Introduce la contrasena");
                    fgets(contra,20,stdin);
                    if(iniciar_sesion(&u,contra,indice_usuario)!=1){
                        printf("Contrasena incorrecta, introducela de nuevo");
                        fgets(contra,20,stdin);
                    }
                    if((iniciar_sesion(&u,contra,indice_usuario)==1)){
                        printf("Bienvenido,%s",&u[indice_usuario].usuario);
                    }
                    submenu(u,indice_usuario);
                } else {
                    printf("\nUsuario no encontrado.");
                }
            }

        }
        }
        if(opcion==5){
            printf("\nGracias por usar nuestra aplicacion!\n Hecha por:\n Martin Barcena \n Arnau Gil \n Adria Casals");

        }
        else{
            printf("\nSelecciona una opcion valida");
        }
    }
