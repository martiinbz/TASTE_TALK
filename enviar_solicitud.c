#include "estructuras.h"


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


FriendRequest friendRequests[MAX_FRIEND_REQUESTS];
int numFriendRequests = 0;

void sendFriendRequest(int senderId, int receiverId) {

    // Verificar si ya hay una solicitud pendiente entre los usuarios
    for (int i = 0; i < numFriendRequests; i++) {
        if (friendRequests[i].senderId == senderId && friendRequests[i].receiverId == receiverId) {
            printf("Ya hay una solicitud pendiente entre los usuarios.\n");
            return;
        }
    }

    // Si no,agregamos la solicitud al usuario receptor
    users[receiverId].receivedFriendRequests[users[receiverId].numReceivedFriendRequests] = numFriendRequests;
    users[receiverId].numReceivedFriendRequests++; //incrementamos el numero de solicitudes recibidas

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
        printf("¿Aceptar la solicitud? (si/no): \t\n");
        scanf("%s", decision);

        // Gestionar la solicitud según la decisión del usuario
        if (strcmp(decision, "si") == 0) {
            printf("Solicitud aceptada. Ahora eres amigo de Usuario %s.\n", u[request.senderId].usuario);
            strcpy(u[request.receiverId].nombre_amigos[u[request.receiverId].num_amigos].nombre_amigo, //añadimos al emisor a la lista de amigos del receptor
                   u[request.senderId].usuario);
            strcpy(u[request.senderId].nombre_amigos[u[request.senderId].num_amigos].nombre_amigo, //añadimos al receptro a la lista de amigos del emisor
                   u[request.receiverId].usuario);
            u[request.receiverId].num_amigos++; //incrementamos el numero de amigos de ambos
            u[request.senderId].num_amigos++;

        } else if (strcmp(decision, "no") == 0) {
            printf("Solicitud rechazada.\n"); //si la rechaza, no hacemos nada
        } else {
            printf("Opción inválida. La solicitud se mantendrá pendiente.\n");
            continue; // Saltar a la siguiente solicitud
        }

        // Eliminar la solicitud gestionada, da igual si ha sido aceptada o rechazada
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
void imprimir_lista_amigos(int userId, Usuario u[]) { //funcion que imprime la lista de amigos de un usuario especifico (si tiene).
    printf("\nLista de amigos de Usuario %s:\n", u[userId].usuario);

    if (u[userId].num_amigos == 0) {
        printf("No tienes amigos en tu lista.\n");
        return;
    }

    for (int i = 0; i < u[userId].num_amigos; i++) {
        printf("\t%d. %s\n", i + 1, u[userId].nombre_amigos[i].nombre_amigo);
    }
}

