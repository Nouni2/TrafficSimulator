#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // Initialiser GLFW
    if (!glfwInit()) {
        std::cerr << "Échec de l'initialisation de GLFW" << std::endl;
        return -1;
    }

    // Créer une fenêtre GLFW
    GLFWwindow* window = glfwCreateWindow(800, 600, "Test OpenGL", NULL, NULL);
    if (!window) {
        std::cerr << "Échec de la création de la fenêtre GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialiser GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Échec de l'initialisation de GLEW" << std::endl;
        return -1;
    }

    // Définir la fonction de rappel pour la taille de la fenêtre
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Boucle de rendu
    while (!glfwWindowShouldClose(window)) {
        // Entrées
        glfwPollEvents();

        // Rendu
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Échange des tampons
        glfwSwapBuffers(window);
    }

    // Nettoyage
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
