cmake_minimum_required(VERSION 3.21)
project(MiRestaurante)

set(CMAKE_CXX_STANDARD 14)

add_executable(MiRestaurante main.cpp Restaurante.cpp Restaurante.h Persona.cpp Persona.h Contenedor.h Plato.cpp Plato.h ConocimientosInsuficientes.h JefeDeCocina.cpp JefeDeCocina.h AprendizDeCocina.cpp AprendizDeCocina.h)
