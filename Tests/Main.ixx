module;

#include <iostream>

export module Main;

namespace glm {

	struct vec3
	{
		float x, y, z;
	};

}


import rtmcpp;
/*
import rtmcpp.glm;
import rtmcpp.joltmath;
*/

/*
template<>
struct rtmcpp::Converter<glm::vec3>
{
	static glm::vec3 Convert(const rtmcpp::Vec3& vec)
	{
		return { vec.X, vec.Y, vec.Z };
	}
};
*/

export int main()
{
	using namespace rtmcpp;

	/*Vec3 v = { 1.0f, 0.0f, 1000.0f };

	Vec4 v2 = v;

	glm::vec3 v3 = v;*/

	return 0;
}
