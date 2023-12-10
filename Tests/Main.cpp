#include <rtmcpp/Common.hpp>
#include <rtmcpp/Scalar.hpp>
#include <rtmcpp/Transforms.hpp>

int main(int argc, char* argv[])
{
	using namespace rtmcpp;

	auto quat = AngleAxis(Radians(50.0f), { 0.0f, 1.0f, 0.0f });
	Mat3x4f quat_mat = Mat3x4Cast(quat);
	Mat4f quat_mat4 = Mat4Cast(quat);

	auto m = Rotation(quat);

	return 0;
}