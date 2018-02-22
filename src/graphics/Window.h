#pragma once

namespace engine {
	namespace graphics {

		class Window
		{
		private:
			const char* m_Name;
			int m_Width;
			int m_Height;

		public:
			Window();
			~Window();
		};

	}
}
