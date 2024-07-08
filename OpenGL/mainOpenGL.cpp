#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>

// Fonction de rappel pour ajuster la taille de la fenêtre
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Fonction pour charger une texture avec stb_image
GLuint loadTexture(const char* filepath) {
    int width, height, nrChannels;
    unsigned char* data = stbi_load(filepath, &width, &height, &nrChannels, 0);
    if (!data) {
        std::cerr << "Échec du chargement de la texture : " << filepath << std::endl;
        return 0;
    }

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return textureID;
}

// Fonction pour dessiner la voiture (un simple carré pour la démonstration)
void drawCar(GLuint textureID) {
    glBindTexture(GL_TEXTURE_2D, textureID);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); // Couleur blanche pour afficher la texture
    glTexCoord2f(0.0f, 0.0f); glVertex2f(-0.05f, -0.05f);
    glTexCoord2f(1.0f, 0.0f); glVertex2f( 0.05f, -0.05f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f( 0.05f,  0.05f);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(-0.05f,  0.05f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
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

    // Charger la texture
    GLuint carTexture = loadTexture("../assets/car.png");

    // Boucle de rendu
    while (!glfwWindowShouldClose(window)) {
        // Entrées
        glfwPollEvents();

        // Rendu
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Dessiner la voiture avec la texture
        drawCar(carTexture);

        // Échange des tampons
        glfwSwapBuffers(window);
    }

    // Nettoyage
    glDeleteTextures(1, &carTexture);
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
