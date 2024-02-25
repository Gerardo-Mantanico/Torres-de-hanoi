cmake_minimum_required(VERSION 3.27)
project(Torre_hanoi)

set(CMAKE_CXX_STANDARD 17)

add_executable(Torre_hanoi main.cpp
        clases/Nodo.h
        codigo-fuente/Pila.cpp
        clases/Pila.h
        clases/Disco.h
        codigo-fuente/PintarTorre.cpp
        clases/PintarTorre.h
        clases/Condiciones.h
        codigo-fuente/Condicion.cpp
)
