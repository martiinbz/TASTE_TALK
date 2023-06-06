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
