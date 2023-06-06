#include "estructuras.h"

typedef struct {
    Usuario *emisor;
    Usuario *receptor;
    struct SolicitudAmistad *siguiente;
} SolicitudAmistad;


void agregar_solicitud(Usuario *emisor, Usuario *receptor, SolicitudAmistad **cola_solicitudes) {
    SolicitudAmistad *nueva_solicitud = (SolicitudAmistad *)malloc(sizeof(SolicitudAmistad));
    nueva_solicitud->emisor = emisor;
    nueva_solicitud->receptor = receptor;
    nueva_solicitud->siguiente = NULL;

    if (*cola_solicitudes == NULL) {
        *cola_solicitudes = nueva_solicitud;
    } else {
        SolicitudAmistad *actual = *cola_solicitudes;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nueva_solicitud;
    }

    emisor->num_solicitudes++;
    printf("Solicitud de amistad enviada a %s.\n", receptor->usuario);
}
void enviar_solicitud_amistad(char **lista_de_usuarios, Usuario *u, int indice_usuarios, int numero_de_usuarios, char *nombre_receptor) {
    Usuario *emisor = NULL;
    Usuario *receptor = NULL;

    int indice_receptor = busqueda_secuencial(lista_de_usuarios, numero_de_usuarios, nombre_receptor);

    if (indice_receptor == -1) {
        printf("No se pudo encontrar al usuario.\n");
        return;
    }

    emisor = &u[indice_usuarios];
    receptor = &u[indice_receptor];

    agregar_solicitud(emisor, receptor, &receptor->solicitudes);
}






/*void enviar_solicitud_amistad(char **lista_de_usuarios, Usuario *u, int indice_usuarios, int numero_de_usuarios, char *nombre_receptor) {
    Usuario *emisor = NULL;
    Usuario *receptor = NULL;

    // Buscar a los usuarios emisor y receptor en el array de usuarios
    int indice_receptor = busqueda_secuencial(lista_de_usuarios, numero_de_usuarios, nombre_receptor);


    // Si no se encuentran ambos usuarios, no se puede enviar la solicitud
    if (indice_receptor == -1) {
        printf("No se pudo encontrar al usuario.\n");
        return;
    }

    // Asignar los punteros emisor y receptor a los usuarios correspondientes
    emisor = &u[indice_usuarios];
    receptor = &u[indice_receptor];

    // Crear una nueva solicitud de amistad y asignar los usuarios emisor y receptor
    SolicitudAmistad *nueva_solicitud = (SolicitudAmistad *)malloc(sizeof(SolicitudAmistad));
    nueva_solicitud->emisor = emisor;
    nueva_solicitud->receptor = receptor;
    nueva_solicitud->siguiente = NULL;

    // Agregar la nueva solicitud a la cola de solicitudes del usuario emisor
    if (emisor->num_solicitudes == 0) {
        emisor->solicitudes = nueva_solicitud;
    } else {
        SolicitudAmistad *actual = emisor->solicitudes;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nueva_solicitud;
    }

    emisor->num_solicitudes++;
    printf("Solicitud de amistad enviada a %s.\n", nombre_receptor);
}
*/
void revisar_solicitudes_amistad(Usuario *u,int indice_usuario) {
        if (u->num_solicitudes == 0) {
            printf("No tienes solicitudes de amistad pendientes.\n");
            return;
        }

        printf("Solicitudes de amistad pendientes:\n");
        SolicitudAmistad *actual = u->solicitudes;
        int contador = 1;

        while (actual != NULL) {
            printf("%d. %s\n", contador, actual->emisor->nombre);
            actual = actual->siguiente;
            contador++;
        }
    }


void mostrar_solicitudes_recibidas(Usuario *u, int indice_usuario) {
    Usuario *usuario = &u[indice_usuario];
    SolicitudAmistad *solicitud = usuario->solicitudes;

    if (solicitud == NULL) {
        printf("No tienes solicitudes de amistad pendientes.\n");
        return;
    }

    printf("Solicitudes de amistad recibidas:\n");

    while (solicitud != NULL) {
        printf("- Emisor: %s\n", solicitud->emisor->usuario);
        solicitud = solicitud->siguiente;
    }
}
