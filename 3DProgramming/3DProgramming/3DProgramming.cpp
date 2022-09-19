#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>


#pragma comment(lib, "OpenGL32")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

}


int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        ////90도와 같이 각도로 연산하고 싶으면
        ////glm의 삼각함수는 radian 형식으로 입력을 받기 때문에 변환해서 넣어주어야한다.
        //glm에 있는 sin 과 cos 함수를 활용하여 OpenGL의 line strip으로 화면에 해당하는 2차원 공간상에서 반지름이 1인 원을 그려보도록 하자.

        //float test1 = glm::sin(glm::radians(90.0f));
        //float test2 = glm::cos(glm::radians(45.0f));
        //std::cout << test1 << "\n";
        //std::cout << test2 << "\n";

        float Line = 0;
        
        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_LINE_STRIP);
        
        for (int i = 0; i < 360; i++) {
            glVertex3f(glm::sin(glm::radians(90.0f) + Line), glm::cos(glm::radians(90.0f) + Line), 0.0f);
            Line += 0.1f;
        }

        glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
        glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    
    exit(EXIT_SUCCESS);
}