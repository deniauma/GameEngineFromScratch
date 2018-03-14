#include "ShaderProgram.h"
#include <glad/glad.h> 

#include <iostream>

namespace engine {
	namespace graphics {

		ShaderProgram::ShaderProgram(const char* vertexShader, const char* fragmentShader): m_VertexShaderSource(vertexShader), m_FragmentShaderSource(fragmentShader)
		{
			// build and compile our shader program
			// ------------------------------------
			// vertex shader
			m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(m_VertexShader, 1, &m_VertexShaderSource, NULL);
			glCompileShader(m_VertexShader);
			// check for shader compile errors
			int success;
			char infoLog[512];
			glGetShaderiv(m_VertexShader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(m_VertexShader, 512, NULL, infoLog);
				std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
			}
			// fragment shader
			m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(m_FragmentShader, 1, &m_FragmentShaderSource, NULL);
			glCompileShader(m_FragmentShader);
			// check for shader compile errors
			glGetShaderiv(m_FragmentShader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(m_FragmentShader, 512, NULL, infoLog);
				std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
			}
			// link shaders
			m_ShaderProgram = glCreateProgram();
			glAttachShader(m_ShaderProgram, m_VertexShader);
			glAttachShader(m_ShaderProgram, m_FragmentShader);
			glLinkProgram(m_ShaderProgram);
			// check for linking errors
			glGetProgramiv(m_ShaderProgram, GL_LINK_STATUS, &success);
			if (!success) {
				glGetProgramInfoLog(m_ShaderProgram, 512, NULL, infoLog);
				std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
			}
			glDeleteShader(m_VertexShader);
			glDeleteShader(m_FragmentShader);
		}

		int ShaderProgram::getProgram()
		{
			return m_ShaderProgram;
		}

		void ShaderProgram::use()
		{
			glUseProgram(m_ShaderProgram);
		}

		void ShaderProgram::setBool(const std::string & name, bool value) const
		{
			glUniform1i(glGetUniformLocation(m_ShaderProgram, name.c_str()), (int)value);
		}

		void ShaderProgram::setInt(const std::string & name, int value) const
		{
			glUniform1i(glGetUniformLocation(m_ShaderProgram, name.c_str()), value);
		}

		void ShaderProgram::setFloat(const std::string & name, float value) const
		{
			glUniform1f(glGetUniformLocation(m_ShaderProgram, name.c_str()), value);
		}

		void ShaderProgram::setVec2(const std::string & name, const glm::vec2 & value) const
		{
			glUniform2fv(glGetUniformLocation(m_ShaderProgram, name.c_str()), 1, &value[0]);
		}

		void ShaderProgram::setVec2(const std::string & name, float x, float y) const
		{
			glUniform2f(glGetUniformLocation(m_ShaderProgram, name.c_str()), x, y);
		}

		void ShaderProgram::setVec3(const std::string & name, const glm::vec3 & value) const
		{
			glUniform3fv(glGetUniformLocation(m_ShaderProgram, name.c_str()), 1, &value[0]);
		}

		void ShaderProgram::setVec3(const std::string & name, float x, float y, float z) const
		{
			glUniform3f(glGetUniformLocation(m_ShaderProgram, name.c_str()), x, y, z);
		}

		void ShaderProgram::setVec4(const std::string & name, const glm::vec4 & value) const
		{
			glUniform4fv(glGetUniformLocation(m_ShaderProgram, name.c_str()), 1, &value[0]);
		}

		void ShaderProgram::setVec4(const std::string & name, float x, float y, float z, float w)
		{
			glUniform4f(glGetUniformLocation(m_ShaderProgram, name.c_str()), x, y, z, w);
		}

		void ShaderProgram::setMat2(const std::string & name, const glm::mat2 & mat) const
		{
			glUniformMatrix2fv(glGetUniformLocation(m_ShaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
		}

		void ShaderProgram::setMat3(const std::string & name, const glm::mat3 & mat) const
		{
			glUniformMatrix3fv(glGetUniformLocation(m_ShaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
		}

		void ShaderProgram::setMat4(const std::string & name, const glm::mat4 & mat) const
		{
			glUniformMatrix4fv(glGetUniformLocation(m_ShaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
		}


		ShaderProgram::~ShaderProgram()
		{
		}

	}
}