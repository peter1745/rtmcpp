#pragma once

#include "Core.hpp"

#if !defined(RTMCPP_BUILD_MODULE)
	#include <rtm/quatf.h>
	#include <rtm/quatd.h>
#endif

RTMCPP_EXPORT namespace rtmcpp {

	template<typename ComponentType>
	struct Quat
	{
		std::conditional_t<std::is_same_v<ComponentType, float>, rtm::quatf, rtm::quatd> Value = rtm::quat_identity();

		Quat RTMCPP_VECTOR_CALL Inverse() const noexcept
		{
			// NOTE(Peter): Assumes normalized quaternions, add a safety check here at some point
			return { rtm::quat_conjugate(Value) };
		}

		Quat& RTMCPP_VECTOR_CALL operator*=(const Quat& other) noexcept
		{
			Value = rtm::quat_mul(Value, other.Value);
			return *this;
		}

		Quat RTMCPP_VECTOR_CALL operator*(const Quat& other) const noexcept
		{
			return { rtm::quat_mul(Value, other.Value) };
		}
	};

	using Quat4 = Quat<float>;
	using Quat4D = Quat<double>;

}
