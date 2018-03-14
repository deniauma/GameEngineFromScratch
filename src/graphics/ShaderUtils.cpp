#include "ShaderUtils.h"

namespace engine {
	namespace graphics {

		const std::string ShaderUtils::TEXTURED_TRIANGLE_VS = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"layout(location = 1) in vec3 aColor;\n"
			"layout(location = 2) in vec2 aTexCoord;\n"
			"out vec3 ourColor;\n"
			"out vec2 TexCoord;\n"
			"void main()\n"
			"{\n"
			"	gl_Position = vec4(aPos, 1.0);\n"
			"	ourColor = aColor;\n"
			"	TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
			"}\0";

		const std::string ShaderUtils::TEXTURED_TRIANGLE_FS = "#version 330 core\n"
			"out vec4 FragColor;\n"
			"in vec3 ourColor;\n"
			"in vec2 TexCoord;\n"
			"uniform sampler2D texture1;\n"
			"void main()\n"
			"{\n"
			"   FragColor = texture(texture1, TexCoord);\n"
			"}\n\0";

		const std::string ShaderUtils::COORDINATE_SYSTEMS_VS = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"layout (location = 1) in vec2 aTexCoord;\n"
			"out vec2 TexCoord;\n"
			"uniform mat4 model;\n"
			"uniform mat4 view;\n"
			"uniform mat4 projection;\n"
			"void main()\n"
			"{\n"
			"    gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
			"    TexCoord = vec2(aTexCoord.x, 1.0 - aTexCoord.y);\n"
			"}\n";

		const std::string ShaderUtils::COORDINATE_SYSTEMS_FS = "#version 330 core\n"
			"out vec4 FragColor;\n"
			"in vec2 TexCoord;\n"
			"uniform sampler2D texture1;\n"
			"uniform sampler2D texture2;\n"
			"void main()\n"
			"{\n"
			"   FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);\n"
			"}\n\0";

		const std::string ShaderUtils::CAMERA_VS = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"layout (location = 1) in vec2 aTexCoord;\n"
			"out vec2 TexCoord;\n"
			"uniform mat4 model;\n"
			"uniform mat4 view;\n"
			"uniform mat4 projection;\n"
			"void main()\n"
			"{\n"
			"	gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
			"	TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
			"}\n";

		const std::string ShaderUtils::CAMERA_FS = "#version 330 core\n"
			"out vec4 FragColor;\n"
			"in vec2 TexCoord;\n"
			"uniform sampler2D texture1;\n"
			"uniform sampler2D texture2;\n"
			"void main()\n"
			"{\n"
			"   FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);\n"
			"}\n\0";

		ShaderUtils::ShaderUtils()
		{
		}


		ShaderUtils::~ShaderUtils()
		{
		}
	}
}