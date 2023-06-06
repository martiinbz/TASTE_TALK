cmake_minimum_required(VERSION 3.24)
project(EDA2 C)

set(CMAKE_C_STANDARD 11)

add_executable(EDA2 main.c "menu principal.c" estructuras.h funciones_pila_usuarios.c "OPCION 3.c" submenu.c enviar_solicitud.c)
