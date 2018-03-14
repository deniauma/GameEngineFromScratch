#pragma once
#include <map>
#include <string>
using namespace std;

namespace engine {
	namespace graphics {

		class ShaderManager
		{
		private:
			map<string, string> shaderLibrary;

		public:
			ShaderManager();
			~ShaderManager();

			void add(string name, string shader);
			string get(string name);
		};

	}
}