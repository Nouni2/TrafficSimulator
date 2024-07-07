#!/bin/bash

# Options de compilation
CXXFLAGS="-g -Wall -std=c++17 -I./include"
LDFLAGS="-lGL -lGLEW -lglfw"

# Compilez les fichiers .cpp de src en un exécutable src/main
g++ $CXXFLAGS $(find ./src -name "*.cpp") -o ./src/main

# Compilez les fichiers .cpp de OpenGL en un exécutable OpenGL/main
g++ $CXXFLAGS $(find ./OpenGL -name "*.cpp") -o ./OpenGL/mainOpenGL $LDFLAGS
