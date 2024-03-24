#include "HelloTriangle.h"

void printVector(glm::vec4 v) {
    std::cout << "(" << 
        v.x << "," << v[1] << "," << v[2] << "," << v[3] 
        << ")" << std::endl;
}

void doMatrix() {
    glm::mat4 translation = glm::mat4(1.0f);
    /*
    column major matrix, got
    1 0 0 1
    0 1 0 2
    0 0 1 3
    0 0 0 1
    */    
    translation[3][0] = 1;
    translation[3][1] = 2;
    translation[3][2] = 3;

    //(x, y, z, 1) is a position in space
    glm::vec4 pos = glm::vec4(1, 1, 1, 1);
    //(x, y, z, 0) is a direction
    glm::vec4 dir = glm::vec4(0, 0, -1, 0);

    //got (2, 3, 4, 1)
    pos = translation * pos;
    printVector(pos);
    //got (0, 0, -1, 0)
    dir = translation * dir;
    printVector(dir);

    glm::mat4 identity = glm::mat4(1.0f);
    glm::mat4 scale = glm::scale(identity, glm::vec3(2, 2, 2));
    /*
    scale matrix:
    2 0 0 1
    0 2 0 1
    0 0 2 1
    0 0 1 1
    got (4, 6, 8, 1)
    */
    pos = scale * pos;
    printVector(pos);

    glm::mat4 rotate = glm::rotate(identity, 
        glm::radians(90.0f), glm::vec3(0, 0, 1));
    //got (-6, 4, 8, 1)
    pos = rotate * pos;
    printVector(pos);

    /*
    matrix multiplication order matters
    transform = translation * rotate * scale
    */
}

int main() {
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported\n";

    doMatrix();

    HelloTriangle app;
    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
