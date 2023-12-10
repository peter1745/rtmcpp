#pragma once

#include <rtm/quatf.h>
#include <rtm/quatd.h>

namespace rtmcpp {

	template<typename ComponentType>
	struct Quat
	{
		std::conditional_t<std::is_same_v<ComponentType, float>, rtm::quatf, rtm::quatd> Value;

		Quat Inverse() const noexcept
		{
			// NOTE(Peter): Assumes normalized quaternions, add a safety check here at some point
			return { rtm::quat_conjugate(Value) };
		}

		Quat& operator*=(const Quat& other) noexcept
		{
			Value = rtm::quat_mul(Value, other.Value);
			return *this;
		}

		Quat operator*(const Quat& other) const noexcept
		{
			return { rtm::quat_mul(Value, other.Value) };
		}

		static Quat FromEuler(const Vector<ComponentType, 3>& eulerAngles)
		{
			return { rtm::quat_from_euler(eulerAngles.X, eulerAngles.Y, eulerAngles.Z) };
		}

		static Quat AngleAxis(ComponentType angle, const Vector<ComponentType, 3>& axis)
		{
			return { rtm::quat_from_axis_angle(axis.Value, angle) };
		}
	};

	using Quat4f = Quat<float>;
	using Quat4d = Quat<double>;

}
