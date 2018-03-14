#include "Texture.h"
#include <glad/glad.h> 
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>

namespace engine {
	namespace graphics {

		Texture::Texture(const char* filename, bool transparent): m_Filename(filename)
		{
			// load and create a texture 
			// -------------------------
			glGenTextures(1, &id);
			glBindTexture(GL_TEXTURE_2D, id); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
												   // set the texture wrapping parameters
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			// set texture filtering parameters
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			// load image, create texture and generate mipmaps
			int width, height, nrChannels;
			// The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
			unsigned char *data = stbi_load(m_Filename, &width, &height, &nrChannels, 0);
			if (data)
			{
				if (transparent)
				{
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
				}
				else
				{
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
				}
				glGenerateMipmap(GL_TEXTURE_2D);
			}
			else
			{
				std::cout << "Failed to load texture" << std::endl;
			}
			stbi_image_free(data);
		}


		Texture::~Texture()
		{
		}

		unsigned int Texture::getID()
		{
			return id;
		}

	}
}