#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>

#include<string>

namespace engine {
	namespace graphics {

		class ShaderProgram
		{
		private:
			const char* m_VertexShaderSource;
			const char* m_FragmentShaderSource;
			int m_VertexShader, m_FragmentShader, m_ShaderProgram;

		public:
			ShaderProgram(const char* vertexShader, const char* fragmentShader);
			~ShaderProgram();

			int getProgram();
			void use();

			void setBool(const std::string &name, bool value) const;
			void setInt(const std::string &name, int value) const;
			void setFloat(const std::string &name, float value) const;
			void setVec2(const std::string &name, const glm::vec2 &value) const;
			void setVec2(const std::string &name, float x, float y) const;
			void setVec3(const std::string &name, const glm::vec3 &value) const;
			void setVec3(const std::string &name, float x, float y, float z) const;
			void setVec4(const std::string &name, const glm::vec4 &value) const;
			void setVec4(const std::string &name, float x, float y, float z, float w);
			void setMat2(const std::string &name, const glm::mat2 &mat) const;
			void setMat3(const std::string &name, const glm::mat3 &mat) const;
			void setMat4(const std::string &name, const glm::mat4 &mat) const;
		};

	}
}