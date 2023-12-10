#pragma once

#include "Vector.hpp"
#include "Quat.hpp"

#include <rtm/matrix3x4f.h>
#include <rtm/matrix3x4d.h>
#include <rtm/matrix4x4f.h>
#include <rtm/matrix4x4d.h>

namespace rtmcpp {

	template<typename ComponentType>
	struct Matrix3x4
	{
		using RTMType = std::conditional_t<std::is_same_v<ComponentType, float>, rtm::matrix3x4f, rtm::matrix3x4d>;
		RTMType Value;

		Matrix3x4& operator*=(const Matrix3x4& other)
		{
			Value = rtm::matrix_mul(Value, other.Value);
			return *this;
		}

		Matrix3x4 operator*(const Matrix3x4& other) const
		{
			return rtm::matrix_mul(Value, other.Value);
		}

		static Matrix3x4 Translation(const Vector<ComponentType, 3>& translation)
		{
			return { rtm::matrix_from_translation(translation.Value) };
		}

		static Matrix3x4 Rotation(const Quat<ComponentType>& rotation)
		{
			return { rtm::matrix_from_quat(rotation.Value) };
		}

		static Matrix3x4 Scale(const Vector<ComponentType, 3>& scale)
		{
			return { rtm::matrix_from_scale(scale.Value) };
		}
	};
	
	template<typename ComponentType>
	struct Matrix4x4
	{
		using RTMType = std::conditional_t<std::is_same_v<ComponentType, float>, rtm::matrix4x4f, rtm::matrix4x4d>;
		RTMType Value;

		Matrix4x4& operator*=(const Matrix4x4& other)
		{
			Value = rtm::matrix_mul(Value, other.Value);
			return *this;
		}

		Matrix4x4 operator*(const Matrix4x4& other) const
		{
			return rtm::matrix_mul(Value, other.Value);
		}

		static Matrix4x4 PerspectiveInfReversedZ(ComponentType fovy, ComponentType aspect, ComponentType nearZ)
		{
			Matrix4x4 result;

			auto f = ComponentType(1) / (rtm::scalar_tan(fovy / ComponentType(2)));

			result.Value.x_axis = rtm::vector_set(f / aspect,		ComponentType(0), ComponentType(0), ComponentType(0));
			result.Value.y_axis = rtm::vector_set(ComponentType(0), f,				  ComponentType(0), ComponentType(0));
			result.Value.z_axis = rtm::vector_set(ComponentType(0), ComponentType(0), ComponentType(0), ComponentType(-1));
			result.Value.w_axis = rtm::vector_set(ComponentType(0), ComponentType(0), nearZ,			ComponentType(0));

			return result;
		}
	};

	template<typename ComponentType>
	Matrix3x4<ComponentType> operator*(const Matrix3x4<ComponentType>& lhs, const Matrix4x4<ComponentType>& rhs)
	{
		return rtm::matrix_cast((Matrix4x4<ComponentType>{rtm::matrix_cast(lhs.Value)} * rhs).Value);
	}

	using Mat3x4f = Matrix3x4<float>;
	using Mat4f = Matrix4x4<float>;

	using Mat3x4d = Matrix3x4<double>;
	using Mat4d = Matrix4x4<double>;

}
