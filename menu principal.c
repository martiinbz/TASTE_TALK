#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "estructuras.h"
void recopilar_datos( Usuario u[],int numero_de_usuarios){ //con esto se pregunta y se almacena la info en la estructura
    printf("Registrando usuario:");
    u[numero_de_usuarios].num_publicaciones = 0;
    printf("\n Introduce tu nombre");
    scanf("%s",u[numero_de_usuarios].nombre);
    while(strlen(u[numero_de_usuarios].nombre)>20){
        printf("El nombre excede el maximo de caracteres (20). Vuelve a intentarlo");
        scanf("%s",u[numero_de_usuarios].nombre);

    }
    printf("\n Introduce tu nombre de usuario");
    scanf("%s",u[numero_de_usuarios].usuario);
    while(strlen(u[numero_de_usuarios].usuario)>20){
        printf("El usuario excede el maximo de caracteres (20). Vuelve a intentarlo");
        scanf("%s",u[numero_de_usuarios].usuario);

    }
    printf("\n Introduce tu contrasena");
    scanf("%s",u[numero_de_usuarios].contrasena);
    while(strlen(u[numero_de_usuarios].contrasena)>20||strlen(u[numero_de_usuarios].contrasena)<6){
        printf("La contrasena debe de tener entre 6 y 20 caracteres.Vuelve a intentarlo");
        scanf("%s",u[numero_de_usuarios].contrasena);

    }
    printf("\nIntroduce tu edad");
    scanf("%d",&u[numero_de_usuarios].edad);
    while(*u[numero_de_usuarios].edad<16){
        printf("\nDebes de tener al menos 16 anos");
        scanf("%d",&u[numero_de_usuarios].edad);
    }
    printf("\nIntroduce tu email");
    getchar();
    scanf("%s",u[numero_de_usuarios].email);

    printf("\nDe donde eres?");
    scanf("%s",u[numero_de_usuarios].ubicacion);

    printf("\nCuales son tus 5 platos favoritos? Introducelos separados por una coma");
    scanf("%s",u[numero_de_usuarios].platos_favoritos);
    printf("\n El usuario %s se ha registrado correctamente!",u[numero_de_usuarios].usuario);

    printf("\n Name: %s \n User: %s  \n contra: %s \n edad: %d \n email: %s \n ubi: %s \n platos: %s",u[numero_de_usuarios].nombre,u[numero_de_usuarios].usuario,u[numero_de_usuarios].contrasena,*u[numero_de_usuarios].edad,u[numero_de_usuarios].email,u[numero_de_usuarios].ubicacion,u[numero_de_usuarios].platos_favoritos);
    //esto es para imprimir los datos recolectados, por si hay algun error y necesitamos mirar si los recolecta bien
};

void menu_principal(Usuario u[]) {      //esta función imprime el menu y pide al usuario que ingrese una opción según lo que quiera hacer. cada opción lleva a una función diferente.
   int numero_de_palabras;
    struct ConteoPalabras *conteo[1000];
    FILE *fichero; //esto abre el .txt que contiene la informacion de los usuarios
    char filename[] = "usuarios.txt";
    fichero = fopen(filename, "r");
    if (fichero == NULL) {
        printf("Error opening file %s\n", filename); //en caso de que de error al abrir
    }
    int opcion = 0, numero_de_usuarios = 0;
    char **lista_de_usuarios;
    lista_de_usuarios = (char **) malloc(sizeof(char *) * (numero_de_usuarios + 1));//creamos la lista dinamica con capacidad inicial 1
    printf(" _____ ___   _____ _____ _____   _____ ___   _      _   __\n"
           "|_   _/ _ \\ /  ___|_   _|  ___| |_   _/ _ \\ | |    | | / /\n"
           "  | |/ /_\\ \\\\ `--.  | | | |__     | |/ /_\\ \\| |    | |/ / \n"
           "  | ||  _  | `--. \\ | | |  __|    | ||  _  || |    |    \\ \n"
           "  | || | | |/\\__/ / | | | |___    | || | | || |____| |\\  \\\n"
           "  \\_/\\_| |_/\\____/  \\_/ \\____/    \\_/\\_| |_/\\_____/\\_| \\_/");

    printf("\n=============================");
    printf("\n Bienvenido a Taste Talk!\n");
    printf("=============================\n");
    while (opcion != -1) {
        printf("\n Selecciona una opcion valida:");
        printf("\n\t 1. Registarse");
        printf("\n\t 2. Registrar usuarios desde un fichero");
        printf("\n\t 3. Lista de Usuarios registrados");
        printf("\n\t 4. Iniciar sesion");
        printf("\n\t 5. Salir de la aplicacion\n");
        printf("=============================\n");
        scanf("%d", &opcion);
        if (opcion == 1) {
            recopilar_datos(u, numero_de_usuarios); //preguntamos al usuario los datos necesarios
            lista_de_usuarios[numero_de_usuarios] = u[numero_de_usuarios].usuario; //metemos el nombre de usuario en la lista
            numero_de_usuarios += 1; //incrementamos el contador de usuarios  de la red social
            lista_de_usuarios = (char **) realloc(lista_de_usuarios, sizeof(char *) * (numero_de_usuarios +
                                                                                       1));//añadimos más memoria en caso de que se tenga que agregar un nuevo user.

        }
        if (opcion == 2) { //para registrar usuarios desde un fichero
            while (fscanf(fichero, "%s %s %d %s %s %s %s", u[numero_de_usuarios].nombre, u[numero_de_usuarios].usuario,
                          &u[numero_de_usuarios].edad, u[numero_de_usuarios].contrasena, u[numero_de_usuarios].email,
                          u[numero_de_usuarios].ubicacion, u[numero_de_usuarios].platos_favoritos) > 0) { //leemos los datos del fichero
                lista_de_usuarios[numero_de_usuarios] = u[numero_de_usuarios].usuario; //metemos el nombre de usuario en la lista
                numero_de_usuarios += 1; //incrementamos el contador de usuarios
                lista_de_usuarios = (char **) realloc(lista_de_usuarios, sizeof(char *) * (numero_de_usuarios +
                                                                                           1));//añadimos más memoria en caso de que se tenga que agregar un nuevo user.
            }
        }
        if (opcion == 3) {
            printf("\nHay %d usuarios registrados,son:\n", numero_de_usuarios);
            for (int i = 0; i <= (numero_de_usuarios - 1); i++) {
                printf("%s\n", lista_de_usuarios[i]); //esto va imprimiendo la lista de usuarios
            }
        }
        if (opcion == 4) {
            if (numero_de_usuarios == 0) { //si aun no hay usuarios registrados
                printf("\nNo hay usuarios registrados");
            } else {
                char usuario_buscado[20];
                printf("\nIntroduce el nombre de usuario: ");//el usuario introduce el nombre de usuario a buscar
                scanf("%s", usuario_buscado);

                int indice_usuario = busqueda_secuencial(lista_de_usuarios, numero_de_usuarios,usuario_buscado); //esto devuelve la posicion de la lista
                //donde está el usuario

                if (indice_usuario != -1) { //si es -1, quiere decir que no está en la lista
                    printf("\nUsuario encontrado: %s", u[indice_usuario].usuario);
                    char contra[20];
                    printf("\nIntroduce la contrasena"); //pedimos por la contraseña
                    scanf("%s", contra);
                    while (iniciar_sesion(u, contra, indice_usuario) !=1) { //si la función para verificar la contra no devuelve 1, la contra es incorrecta
                        printf("\nContrasena incorrecta, introducela de nuevo\n");
                        scanf("%s", contra);
                    }
                    if ((iniciar_sesion(u, contra, indice_usuario) == 1)) {
                        printf("\n=============================\n");
                        printf("Bienvenido/a,%s!\n",
                               u[indice_usuario].usuario);//una vez validada la contraseña,damos la bienvenida
                        printf("=============================\n");
                    }
                    submenu(lista_de_usuarios, u, indice_usuario, numero_de_usuarios);//imprimimos el submenu de usuario
                } else {
                    printf("\nUsuario no encontrado.");//en caso de que el usuario no esté registrado
                }
            }

        }
        if (opcion == 5) { //opcion para contar las palabras más usadas de la aplicacion e imprimirlas.
            contarPalabras( u, numero_de_usuarios, conteo, &numero_de_palabras);
            imprimirPalabrasMasUsadas( conteo,  numero_de_palabras);



        }
        if (opcion==6){ //salir de la app.
            printf("\nGracias por usar nuestra aplicacion!\n Hecha por:\n Martin Barcena \n Arnau Gil \n Adria Casals");
            break;
        }

    }
}