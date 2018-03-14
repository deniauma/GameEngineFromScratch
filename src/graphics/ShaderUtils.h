#pragma once
#include <string>

namespace engine {
	namespace graphics {

		class ShaderUtils
		{
		public:
			std::string static const TEXTURED_TRIANGLE_VS;
			std::string static const TEXTURED_TRIANGLE_FS;
			std::string static const COORDINATE_SYSTEMS_VS;
			std::string static const COORDINATE_SYSTEMS_FS;
			std::string static const CAMERA_VS;
			std::string static const CAMERA_FS;

			ShaderUtils();
			~ShaderUtils();
		};

	}
}