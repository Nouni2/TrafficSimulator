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
    stbi_set_flip_vertically_on_load(true); // Inverser la texture verticalement lors du chargement
    int width, height, nrChannels;
    unsigned char* data = stbi_load(filepath, &width, &height, &nrChannels, 0);
    if (!data) {
        std::cerr << "Échec du chargement de la texture : " << filepath << std::endl;
        return 0;
    }

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    GLenum format = GL_RGB;
    if (nrChannels == 1)
        format = GL_RED;
    else if (nrChannels == 3)
        format = GL_RGB;
    else if (nrChannels == 4)
        format = GL_RGBA;

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
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
    glEnable(GL_TEXTURE_2D); // Activer le texturing
    glBindTexture(GL_TEXTURE_2D, textureID);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(-0.25f, -0.125f); // Ajuster la taille de la voiture
    glTexCoord2f(1.0f, 0.0f); glVertex2f(0.25f, -0.125f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(0.25f, 0.125f);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(-0.25f, 0.125f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D); // Désactiver le texturing
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

    // Activer la transparence
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Définir la fonction de rappel pour la taille de la fenêtre
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Charger la texture
    const char* texturePath = "../assets/car.png";
    GLuint carTexture = loadTexture(texturePath);

    if (carTexture == 0) {
        std::cerr << "Failed to load texture: " << texturePath << std::endl;
        return -1;
    }

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
