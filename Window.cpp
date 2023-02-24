#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "linmath.h"

#include <stdlib.h>
#include <stdio.h>
#include <fstream>

static const char* vertex_shader_text =
"#version 110\n"
"uniform mat4 MVP;\n"
"attribute vec3 vCol;\n"
"attribute vec2 vPos;\n"
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
"    color = vCol;\n"
"}\n";

static const char* fragment_shader_text =
"#version 110\n"
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_FragColor = vec4(color, 1.0);\n"
"}\n";


class Window
{
	int width, height;
	GLFWwindow* window;

	public:
		Window(int width, int height)
		{
			this->width = width;
			this->height = height;

			while (!glfwWindowShouldClose(window))
			{
		
			}

			glfwDestroyWindow(window);

			glfwTerminate();
			exit(EXIT_SUCCESS);
		}

	private:
		
		void init()
		{
			glfwSetErrorCallback(Window::error_callback);

			if (!glfwInit())
				exit(EXIT_FAILURE);

			window = glfwCreateWindow(width, height, "Window", NULL, NULL);
			if (!window)
			{
				glfwTerminate();
				exit(EXIT_FAILURE);
			}

			glfwMakeContextCurrent(window);
			gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
			glfwSwapInterval(1);

			glfwSetKeyCallback(window, Window::key_callback);
		}

		static void error_callback(int error, const char* description)
		{
			fprintf(stderr, "Error: %s\n", description);
		}

		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GLFW_TRUE);
		}
/*
private:
	void initShaders()
	{
		std::ifstream t("file.txt");
		std::stringstream buffer;
		buffer << t.rdbuf();
	}
*/


};

