#include <iostream>

#include <rtmcpp/Transforms.hpp>
#include <rtmcpp/PackedVector.hpp>

int main(int argc, char* argv[])
{
	using namespace rtmcpp;

	auto quat = Quat4f::AngleAxis(rtm::scalar_deg_to_rad(50.0f), { 0.0f, 1.0f, 0.0f });
	Mat3x4f quat_mat = Mat3x4Cast(quat);
	Mat4f quat_mat4 = Mat4Cast(quat);

	auto m = Mat3x4f::Rotation(quat);

	return 0;
}
