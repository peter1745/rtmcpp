#pragma once

#include "Quat.hpp"
#include "Matrix.hpp"

RTMCPP_EXPORT namespace rtmcpp {

	template<typename ComponentType>
	Matrix3x4<ComponentType> Mat3x4Cast(const Quat<ComponentType>& quat)
	{
		return { rtm::matrix_from_quat(quat.Value) };
	}

	template<typename ComponentType>
	Matrix4x4<ComponentType> Mat4Cast(const Quat<ComponentType>& quat)
	{
		typename Matrix3x4<ComponentType>::ValueType mat = rtm::matrix_from_quat(quat.Value);
		typename Matrix4x4<ComponentType>::ValueType result = rtm::matrix_cast(mat);
		return { result };
	}

	template<typename ComponentType>
	Matrix4x4<ComponentType> Mat4Cast(const Matrix3x4<ComponentType>& mat)
	{
		return Matrix4x4<ComponentType>{rtm::matrix_cast(mat.Value)};
	}

	template<typename ComponentType>
	Matrix3x4<ComponentType> operator*(const Matrix3x4<ComponentType>& mat, const Quat<ComponentType>& quat)
	{
		return mat * Mat3x4Cast(quat);
	}

	template<typename ComponentType>
	Matrix3x4<ComponentType> operator*(const Quat<ComponentType>& quat, const Matrix3x4<ComponentType>& mat)
	{
		return Mat3x4Cast(quat) * mat;
	}

	template<typename ComponentType>
	Matrix4x4<ComponentType> operator*(const Matrix4x4<ComponentType>& mat, const Quat<ComponentType>& quat)
	{
		return mat * Mat4Cast(quat);
	}

	template<typename ComponentType>
	Matrix4x4<ComponentType> operator*(const Quat<ComponentType>& quat, const Matrix4x4<ComponentType>& mat)
	{
		return Mat4Cast(quat) * mat;
	}

	template<typename ComponentType>
	Matrix4x4<ComponentType> Inverse(const Matrix4x4<ComponentType>& mat)
	{
		return { rtm::matrix_inverse(mat.Value) };
	}

	template<typename ComponentType>
	Matrix4x4<ComponentType> Transpose(const Matrix4x4<ComponentType>& mat)
	{
		return { rtm::matrix_transpose(mat.Value) };
	}

}
