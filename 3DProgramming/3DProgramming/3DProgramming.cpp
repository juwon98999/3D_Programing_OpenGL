#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

#pragma comment(lib, "freeglut.lib")
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
    window = glfwCreateWindow(800, 720, "Simple example", NULL, NULL);
    

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

        float r = 0.0f;
        int max_angle = 362;
        float radius = 0.5f;

        double angle = 3.141592 / 180;
        
        glClearColor(0.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

       

        glBegin(GL_LINE_STRIP);

        for (int i = 0; i < max_angle; i++) {
            glVertex3f(radius * glm::sin(glm::radians(90.0f) + r), radius * glm::cos(glm::radians(90.0f) + r), 0);
            r += 0.1f;
        }
        glEnd();

        /*glColor4f(0.0f, 0.0f, 0.0f, 1.0f);*/

        glPointSize(10.0f);
        glBegin(GL_POINTS);
        glVertex2f(radius * glm::cos(0.0f * angle), radius * glm::sin(0.0f * angle));
        glVertex2f(radius * glm::cos(72.0f * angle), radius * glm::sin(72.0f * angle));
        glVertex2f(radius * glm::cos(144.0f * angle), radius * glm::sin(144.0f * angle));
        glVertex2f(radius * glm::cos(216.0f * angle), radius * glm::sin(216.0f * angle));
        glVertex2f(radius * glm::cos(288.0f * angle), radius * glm::sin(288.0f * angle));
        
        glEnd();


        glBegin(GL_LINE_STRIP);

        glVertex2f(radius * glm::cos(0.0f * angle), radius * glm::sin(0.0f * angle));
        glVertex2f(radius * glm::cos(144.0f * angle), radius * glm::sin(144.0f * angle));
        glVertex2f(radius * glm::cos(288.0f * angle), radius * glm::sin(288.0f * angle));
        glVertex2f(radius * glm::cos(72.0f * angle), radius * glm::sin(72.0f * angle));
        glVertex2f(radius * glm::cos(216.0f * angle), radius * glm::sin(216.0f * angle));
        glVertex2f(radius * glm::cos(360.0f * angle), radius * glm::sin(360.0f * angle));
        

        glEnd();

        glLoadIdentity();
        glPushMatrix();
        glTranslatef(5.0f, 0.0f, -10.0f);
        glScalef(1.0f, 1.0f, 1.0f);
        glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
        glPopMatrix();
        

        double time = 0.0f;
        
        time = glfwGetTime();


        static float step = 0.1f;

        if (radius >= 10.0f) {
            step -= step;
        }
        else if (radius <= 0.0f) {
            step = -step;
        }
        
        


        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    
    exit(EXIT_SUCCESS);
}