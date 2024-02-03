#pragma once

#include "Core.hpp"

#if !defined(RTMCPP_BUILD_MODULE)
	#include <rtm/matrix3x4f.h>
	#include <rtm/matrix3x4d.h>
	#include <rtm/matrix4x4f.h>
	#include <rtm/matrix4x4d.h>
#endif

RTMCPP_EXPORT namespace rtmcpp {

	template<typename ComponentType>
	struct Matrix3x4
	{
		using ValueType = std::conditional_t<std::is_same_v<ComponentType, float>, rtm::matrix3x4f, rtm::matrix3x4d>;
		ValueType Value = rtm::matrix_identity();

		Matrix3x4& RTMCPP_VECTOR_CALL operator*=(const Matrix3x4& other)
		{
			Value = rtm::matrix_mul(Value, other.Value);
			return *this;
		}

		Matrix3x4 RTMCPP_VECTOR_CALL operator*(const Matrix3x4& other) const
		{
			return { rtm::matrix_mul(Value, other.Value) };
		}
	};
	
	template<typename ComponentType>
	struct Matrix4x4
	{
		using ValueType = std::conditional_t<std::is_same_v<ComponentType, float>, rtm::matrix4x4f, rtm::matrix4x4d>;
		ValueType Value = rtm::matrix_identity();

		Matrix4x4() = default;

		Matrix4x4(ValueType value)
			: Value(value) {}

		Matrix4x4(const Matrix3x4<ComponentType>& mat)
			: Value(rtm::matrix_cast(mat.Value))
		{
		}

		Matrix4x4& RTMCPP_VECTOR_CALL operator=(const Matrix3x4<ComponentType>& mat)
		{
			Value = rtm::matrix_cast(mat.Value);
			return *this;
		}

		Matrix4x4& RTMCPP_VECTOR_CALL operator*=(const Matrix4x4& other)
		{
			Value = rtm::matrix_mul(Value, other.Value);
			return *this;
		}

		Matrix4x4 RTMCPP_VECTOR_CALL operator*(const Matrix4x4& other) const
		{
			return { rtm::matrix_mul(Value, other.Value) };
		}

		static Matrix4x4 RTMCPP_VECTOR_CALL PerspectiveInfReversedZ(ComponentType fovy, ComponentType aspect, ComponentType nearZ)
		{
			Matrix4x4 result;

			auto f = ComponentType(1) / (rtm::scalar_tan(fovy / ComponentType(2)));

			result.Value.x_axis = rtm::vector_set(f / aspect,		ComponentType(0), ComponentType(0), ComponentType(0));
			result.Value.y_axis = rtm::vector_set(ComponentType(0), f,				  ComponentType(0), ComponentType(0));
			result.Value.z_axis = rtm::vector_set(ComponentType(0), ComponentType(0), ComponentType(0), ComponentType(-1));
			result.Value.w_axis = rtm::vector_set(ComponentType(0), ComponentType(0), nearZ,			ComponentType(0));

			return result;
		}

		static Matrix4x4 RTMCPP_VECTOR_CALL Orthographic(ComponentType width, ComponentType height, ComponentType near, ComponentType far)
		{
			Matrix4x4 result;
			ComponentType invDistance = ComponentType(1) / (far - near);
			result.Value.x_axis = rtm::vector_set(ComponentType(2) / width, ComponentType(0), ComponentType(0), ComponentType(0));
			result.Value.y_axis = rtm::vector_set(ComponentType(0), ComponentType(2) / height, ComponentType(0), ComponentType(0));
			result.Value.z_axis = rtm::vector_set(ComponentType(0), ComponentType(0), invDistance, ComponentType(0));
			result.Value.w_axis = rtm::vector_set(ComponentType(0), ComponentType(0), -invDistance * near, ComponentType(1));
			return result;
		}
	};

	template<typename ComponentType>
	Matrix3x4<ComponentType> RTMCPP_VECTOR_CALL operator*(const Matrix3x4<ComponentType>& lhs, const Matrix4x4<ComponentType>& rhs)
	{
		auto mat = Matrix4x4<ComponentType>{ rtm::matrix_cast(lhs.Value) } * rhs;
		return { rtm::matrix_cast(mat.Value) };
	}

	using Mat3x4 = Matrix3x4<float>;
	using Mat4 = Matrix4x4<float>;

	using Mat3x4D = Matrix3x4<double>;
	using Mat4D = Matrix4x4<double>;

}
