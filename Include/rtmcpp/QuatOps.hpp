#pragma once

#include "Vector.hpp"
#include "Quat.hpp"
#include "Matrix.hpp"

RTMCPP_EXPORT namespace rtmcpp {

	template<typename ComponentType>
	Quat<ComponentType> QuatCast(const Matrix3x4<ComponentType>& mat)
	{
		return { rtm::quat_from_matrix(mat.Value) };
	}

	template<typename ComponentType>
	Quat<ComponentType> QuatCast(const Matrix4x4<ComponentType>& mat)
	{
		return { rtm::quat_from_matrix(Matrix4x4<ComponentType>::ValueType(rtm::matrix_cast(mat.Value))) };
	}

	template<typename ComponentType>
	Quat<ComponentType> FromEuler(const Vector<ComponentType, 3>& eulerAngles)
	{
		return { rtm::quat_from_euler(eulerAngles.X, eulerAngles.Y, eulerAngles.Z) };
	}

	template<typename ComponentType>
	Quat<ComponentType> AngleAxis(ComponentType angle, const Vector<ComponentType, 3>& axis)
	{
		return { rtm::quat_from_axis_angle(axis.Value, angle) };
	}

}
