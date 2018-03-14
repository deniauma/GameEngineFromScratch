#pragma once

namespace engine {
	namespace graphics {

		class Texture
		{
		private:
			const char* m_Filename;
			unsigned int id;

		public:
			Texture(const char* filename, bool transparent = false);
			~Texture();

			unsigned int getID();
		};

	}
}