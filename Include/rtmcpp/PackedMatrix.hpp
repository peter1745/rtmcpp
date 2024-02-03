#pragma once

#include "Core.hpp"
#include "Matrix.hpp"

#include <array>

namespace rtmcpp {

	template<typename ComponentType>
	struct PackedMatrix4x4
	{
		std::array<ComponentType, 16> Values;

		PackedMatrix4x4() = default;
		PackedMatrix4x4(const Matrix4x4<ComponentType>& mat) noexcept
		{
			Values[0] = rtm::vector_get_x(mat.Value.x_axis);
			Values[1] = rtm::vector_get_y(mat.Value.x_axis);
			Values[2] = rtm::vector_get_z(mat.Value.x_axis);
			Values[3] = rtm::vector_get_w(mat.Value.x_axis);

			Values[4] = rtm::vector_get_x(mat.Value.y_axis);
			Values[5] = rtm::vector_get_y(mat.Value.y_axis);
			Values[6] = rtm::vector_get_z(mat.Value.y_axis);
			Values[7] = rtm::vector_get_w(mat.Value.y_axis);

			Values[8]  = rtm::vector_get_x(mat.Value.z_axis);
			Values[9]  = rtm::vector_get_y(mat.Value.z_axis);
			Values[10] = rtm::vector_get_z(mat.Value.z_axis);
			Values[11] = rtm::vector_get_w(mat.Value.z_axis);

			Values[12] = rtm::vector_get_x(mat.Value.w_axis);
			Values[13] = rtm::vector_get_y(mat.Value.w_axis);
			Values[14] = rtm::vector_get_z(mat.Value.w_axis);
			Values[15] = rtm::vector_get_w(mat.Value.w_axis);
		}

		operator Matrix4x4<ComponentType>() const noexcept
		{
			Matrix4x4<ComponentType> result;
			result.Value.x_axis = rtm::vector_set(Values[0],  Values[1],  Values[2],  Values[3]);
			result.Value.y_axis = rtm::vector_set(Values[4],  Values[5],  Values[6],  Values[7]);
			result.Value.z_axis = rtm::vector_set(Values[8],  Values[9],  Values[10], Values[11]);
			result.Value.w_axis = rtm::vector_set(Values[12], Values[13], Values[14], Values[15]);
			return result;
		}
	};

	using PackedMat4 = PackedMatrix4x4<float>;
	using PackedMat4D = PackedMatrix4x4<double>;

}
