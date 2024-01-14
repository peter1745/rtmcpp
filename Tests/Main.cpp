#include <rtmcpp/Common.hpp>
#include <rtmcpp/Scalar.hpp>
#include <rtmcpp/Transforms.hpp>

int main(int argc, char* argv[])
{
	using namespace rtmcpp;

	auto proj = Mat4::PerspectiveInfReversedZ(Radians(90.0f), 1920.0f / 1080.0f, 0.01f);
	auto v = (Scale<float>({ 100.0f, 0.5f, 1000.0f }) * Rotation<float>(AngleAxis<float>(Radians(60.0f), { 0.0f, 1.0f, 0.0f })) * Translation<float>({ 10000.0f, 1000.0f, 5000.0f })) * proj;

	Mat4 a = Translation(Vec3{ 5.0f, 10.0f, 15.0f });
	auto b = Inverse(a);

	return 0;
}
