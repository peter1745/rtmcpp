#include <rtmcpp/Common.hpp>
#include <rtmcpp/Scalar.hpp>
#include <rtmcpp/Transforms.hpp>

namespace glm {

	struct vec3
	{
		float x, y, z;
	};

}

int main(int argc, char* argv[])
{
	using namespace rtmcpp;

	auto proj = Mat4::PerspectiveInfReversedZ(Radians(90.0f), 1920.0f / 1080.0f, 0.01f);
	auto v = (Scale<float>({ 100.0f, 0.5f, 1000.0f }) * Rotation<float>(AngleAxis<float>(Radians(60.0f), { 0.0f, 1.0f, 0.0f })) * Translation<float>({ 10000.0f, 1000.0f, 5000.0f })) * proj;

	auto t = Translation(Vec3{ 5.0f, 10.0f, 15.0f });
	Mat4 a = Mat4Cast(t);

	return 0;
}
