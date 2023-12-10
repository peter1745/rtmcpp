#pragma once

#include "Vector.hpp"
#include "Quat.hpp"
#include "Matrix.hpp"

RTMCPP_EXPORT namespace rtmcpp {

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

}
