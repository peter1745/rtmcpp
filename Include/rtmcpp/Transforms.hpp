#pragma once

#include "Vector.hpp"
#include "Matrix.hpp"
#include "Quat.hpp"

namespace rtmcpp {

	template<typename ComponentType>
	Vector<ComponentType, 4> operator*(const Vector<ComponentType, 4>& vec, const Matrix4x4<ComponentType>& mat)
	{
		return rtm::matrix_mul_vector(vec.Value, mat.Value);
	}

	template<typename ComponentType>
	Vector<ComponentType, 3> operator*(const Vector<ComponentType, 3>& vec, const Quat<ComponentType>& quat)
	{
		return { rtm::quat_mul_vector3(vec.Value, quat.Value) };
	}

	template<typename ComponentType>
	Vector<ComponentType, 3> operator*(const Quat<ComponentType>& quat, const Vector<ComponentType, 3>& vec)
	{
		return { rtm::quat_mul_vector3(vec.Value, rtm::quat_conjugate(quat.Value)) };
	}

	template<typename ComponentType>
	Matrix3x4<ComponentType> Mat3x4Cast(const Quat<ComponentType>& quat)
	{
		return { rtm::matrix_from_quat(quat.Value) };
	}

	template<typename ComponentType>
	Matrix4x4<ComponentType> Mat4Cast(const Quat<ComponentType>& quat)
	{
		typename Matrix3x4<ComponentType>::RTMType mat = rtm::matrix_from_quat(quat.Value);
		typename Matrix4x4<ComponentType>::RTMType result = rtm::matrix_cast(mat);
		return { result };
	}

	template<typename ComponentType>
	Quat<ComponentType> QuatCast(const Matrix3x4<ComponentType>& mat)
	{
		return { rtm::quat_from_matrix(mat.Value) };
	}

	template<typename ComponentType>
	Quat<ComponentType> QuatCast(const Matrix4x4<ComponentType>& mat)
	{
		return { rtm::quat_from_matrix(Matrix4x4<ComponentType>::RTMType(rtm::matrix_cast(mat.Value))) };
	}

}
