#pragma once

#include "Vector.hpp"
#include "Matrix.hpp"
#include "Quat.hpp"
#include "TRS.hpp"

RTMCPP_EXPORT namespace rtmcpp {

	template<typename ComponentType>
	Matrix3x4<ComponentType> Translation(const Vector<ComponentType, 3>& translation)
	{
		return { rtm::matrix_from_translation(translation.Value) };
	}

	template<typename ComponentType>
	Matrix3x4<ComponentType> Rotation(const Quat<ComponentType>& rotation)
	{
		return { rtm::matrix_from_quat(rotation.Value) };
	}

	template<typename ComponentType>
	Matrix3x4<ComponentType> Scale(const Vector<ComponentType, 3>& scale)
	{
		return { rtm::matrix_from_scale(scale.Value) };
	}

	template<typename ComponentType>
	Matrix3x4<ComponentType> MatrixFromTRS(const TRS<ComponentType>& trs)
	{
		return { rtm::matrix_from_qvv(rtm::qvv_set(trs.Rotation.Value, trs.Translation.Value, trs.Scale.Value)) };
	}

}
