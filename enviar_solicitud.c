#include "estructuras.h"

typedef struct {
    Usuario *emisor;
    Usuario *receptor;
    struct SolicitudAmistad *siguiente;
} SolicitudAmistad;
#include <stdio.h>
#include <stdbool.h>

#define MAX_USERS 100
#define MAX_FRIEND_REQUESTS 100

// Estructura para almacenar la información de un usuario
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_FRIEND_REQUESTS 100


Usuario users[MAX_USERS];
int numUsers = 0;

typedef struct {
    int senderId;
    int receiverId;
} FriendRequest;

FriendRequest friendRequests[MAX_FRIEND_REQUESTS];
int numFriendRequests = 0;

void sendFriendRequest(int senderId, int receiverId) {
    // Verificar que los IDs de los usuarios sean válidos


    // Verificar si ya hay una solicitud pendiente entre los usuarios
    for (int i = 0; i < numFriendRequests; i++) {
        if (friendRequests[i].senderId == senderId && friendRequests[i].receiverId == receiverId) {
            printf("Ya hay una solicitud pendiente entre los usuarios.\n");
            return;
        }
    }

    // Agregar la solicitud al usuario receptor
    users[receiverId].receivedFriendRequests[users[receiverId].numReceivedFriendRequests] = numFriendRequests;
    users[receiverId].numReceivedFriendRequests++;

    // Crear una nueva solicitud de amistad
    FriendRequest newRequest;
    newRequest.senderId = senderId;
    newRequest.receiverId = receiverId;

    // Agregar la solicitud al array de solicitudes
    friendRequests[numFriendRequests] = newRequest;
    numFriendRequests++;

    printf("Solicitud de amistad enviada correctamente.\n");
}

void manageFriendRequests(int userId,Usuario u[]) {
    // Verificar si el usuario tiene solicitudes de amistad pendientes
    if (users[userId].numReceivedFriendRequests == 0) {
        printf("No tienes solicitudes de amistad pendientes.\n");
        return;
    }

    printf("Solicitudes de amistad pendientes:\n");

    // Mostrar y gestionar las solicitudes pendientes del usuario
    for (int i = 0; i < users[userId].numReceivedFriendRequests; i++) {
        int requestId = users[userId].receivedFriendRequests[i];
        FriendRequest request = friendRequests[requestId];

        printf("Solicitud %d: Usuario %s desea agregarte como amigo.\n", requestId + 1, u[request.senderId].usuario);

        // Obtener la decisión del usuario
        char decision[10];
        printf("¿Aceptar la solicitud? (si/no): ");
        scanf("%s", decision);

        // Gestionar la solicitud según la decisión del usuario
        if (strcmp(decision, "si") == 0) {
            printf("Solicitud aceptada. Ahora eres amigo de Usuario %s.\n", users[request.senderId].usuario);
            // Aquí puedes realizar acciones adicionales, como agregar el ID del usuario a la lista de amigos, etc.
        } else if (strcmp(decision, "no") == 0) {
            printf("Solicitud rechazada.\n");
        } else {
            printf("Opción inválida. La solicitud se mantendrá pendiente.\n");
            continue; // Saltar a la siguiente solicitud
        }

        // Eliminar la solicitud gestionada
        for (int j = requestId; j < numFriendRequests - 1; j++) {
            friendRequests[j] = friendRequests[j + 1];
        }
        numFriendRequests--;

        users[userId].numReceivedFriendRequests--;
        for (int j = i; j < users[userId].numReceivedFriendRequests; j++) {
            users[userId].receivedFriendRequests[j] = users[userId].receivedFriendRequests[j + 1];
        }
        i--;
    }
}



// Estructura para almacenar una solicitud de amistad
/*typedef struct {
    int senderId;
    int receiverId;
} FriendRequest;
/*
// Array de usuarios
Usuario users[MAX_USERS];
int numUsers = 0;

// Array de solicitudes de amistad pendientes
FriendRequest friendRequests[MAX_FRIEND_REQUESTS];
int numFriendRequests = 0;

// Función para enviar una solicitud de amistad
void sendFriendRequest(int senderId, int receiverId) {
    // Verificar que los IDs de los usuarios sean válidos


    // Verificar si ya hay una solicitud pendiente entre los usuarios
    for (int i = 0; i < numFriendRequests; i++) {
        if (friendRequests[i].senderId == senderId && friendRequests[i].receiverId == receiverId) {
            printf("Ya hay una solicitud pendiente entre los usuarios.\n");
            return;
        }
    }

    // Crear una nueva solicitud de amistad
    FriendRequest newRequest;
    newRequest.senderId = senderId;
    newRequest.receiverId = receiverId;

    // Agregar la solicitud al array de solicitudes
    friendRequests[numFriendRequests] = newRequest;
    numFriendRequests++;

    printf("Solicitud de amistad enviada correctamente.\n");
}

// Función para gestionar las solicitudes de amistad pendientes
void manageFriendRequests() {
    // Verificar si hay solicitudes pendientes
    if (numFriendRequests == 0) {
        printf("No hay solicitudes de amistad pendientes.\n");
        return;
    }

    printf("Solicitudes de amistad pendientes:\n");

    // Mostrar las solicitudes pendientes y gestionarlas
    for (int i = 0; i < numFriendRequests; i++) {
        FriendRequest request = friendRequests[i];
        char emisor[20];
        strcpy(emisor,users[request.senderId].usuario);

        printf("Solicitud %d: Usuario %s desea agregarte como amigo.\n", i+1, emisor);

        // Gestionar la solicitud (en este caso, simplemente la eliminamos)
        friendRequests[i] = friendRequests[numFriendRequests - 1];
        numFriendRequests--;
        i--;

        printf("Solicitud gestionada correctamente.\n");
    }
}


/////////////////////////////////////////////////////////////////////////////7
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
