cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(TrafficSimulator)

# Version du C++
set(CMAKE_CXX_STANDARD 17)

# Ajout des sources
file(GLOB SOURCES "src/*.cpp")

# Génération de l'exécutable
add_executable(TrafficSimulator ${SOURCES})

# Inclusion des fichiers d'en-tête
include_directories(include)
