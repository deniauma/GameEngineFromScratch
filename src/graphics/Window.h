#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>

namespace engine {
	namespace graphics {

		class Window
		{
		private:
			const char* m_Title;
			int m_Width;
			int m_Height;
			GLFWwindow* m_Window;

		public:
			Window(int width, int height, const char* title);
			~Window();

			void init();
			bool closed();
			void update();
			GLFWwindow* getWindow();
		};

	}
}
