#include "Window.h"
#include <iostream>

namespace engine {
	namespace graphics {

		Window::Window(int width, int height, const char* title): m_Width(width), m_Height(height), m_Title(title)
		{
			
		}


		Window::~Window()
		{
		}

		void Window::init()
		{
			std::cout << "Initialization ... ";
			/* Initialize the library */
			if (glfwInit())
			{
				glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
				glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
				glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

				/* Create a windowed mode window and its OpenGL context */
				m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
				if (!m_Window)
				{
					std::cout << "Failed to create GLFW window" << std::endl;
					glfwTerminate();
				}
			}
			else
				std::cout << "Failed to initialize GLFW" << std::endl;

			/* Make the window's context current */
			glfwMakeContextCurrent(m_Window);

			// tell GLFW to capture our mouse
			glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Failed to initialize GLAD" << std::endl;
			}
			std::cout << "DONE" << std::endl;
		}

		bool Window::closed()
		{
			return glfwWindowShouldClose(m_Window);
		}

		void Window::update()
		{
			/* Swap front and back buffers */
			glfwSwapBuffers(m_Window);

			/* Poll for and process events */
			glfwPollEvents();
		}

		GLFWwindow * Window::getWindow()
		{
			return m_Window;
		}

	}
}
