#include "ShaderManager.h"

namespace engine {
	namespace graphics {

		ShaderManager::ShaderManager()
		{
		}


		ShaderManager::~ShaderManager()
		{
		}

		void ShaderManager::add(string name, string shader)
		{
			shaderLibrary.insert(pair<string, string>(name, shader));
		}

		string ShaderManager::get(string name)
		{
			if (shaderLibrary.count(name) > 0)
			{
				return shaderLibrary[name];
			}
			else
				return "";
		}

	}
}