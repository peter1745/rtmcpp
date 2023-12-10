#pragma once

#if !defined(RTMCPP_BUILD_MODULE)
	#include <rtm/scalarf.h>
	#include <rtm/scalard.h>
#endif

RTMCPP_EXPORT namespace rtmcpp {

	template<typename ComponentType>
	ComponentType Clamp(ComponentType value, ComponentType min, ComponentType max) noexcept
	{
		return rtm::scalar_clamp(value, min, max);
	}

	template<typename ComponentType>
	ComponentType Abs(ComponentType value) noexcept
	{
		return rtm::scalar_abs(value);
	}

	template<typename ComponentType>
	ComponentType Sqrt(ComponentType value) noexcept
	{
		return rtm::scalar_sqrt(value);
	}

	template<typename ComponentType>
	ComponentType Min(ComponentType v0, ComponentType v1) noexcept
	{
		return rtm::scalar_min(v0, v1);
	}

	template<typename ComponentType>
	ComponentType Max(ComponentType v0, ComponentType v1) noexcept
	{
		return rtm::scalar_max(v0, v1);
	}

	template<typename ComponentType>
	ComponentType Sin(ComponentType value) noexcept
	{
		return rtm::scalar_sin(value);
	}

	template<typename ComponentType>
	ComponentType Cos(ComponentType value) noexcept
	{
		return rtm::scalar_cos(value);
	}

	template<typename ComponentType>
	ComponentType Asin(ComponentType value) noexcept
	{
		return rtm::scalar_asin(value);
	}

	template<typename ComponentType>
	ComponentType Acos(ComponentType value) noexcept
	{
		return rtm::scalar_acos(value);
	}

	template<typename ComponentType>
	ComponentType Tan(ComponentType angle) noexcept
	{
		return rtm::scalar_tan(angle);
	}

	template<typename ComponentType>
	ComponentType Atan(ComponentType value) noexcept
	{
		return rtm::scalar_atan(value);
	}

	template<typename ComponentType>
	ComponentType Atan2(ComponentType y, ComponentType x) noexcept
	{
		return rtm::scalar_atan2(y, x);
	}

	template<typename ComponentType>
	ComponentType Degrees(ComponentType radians) noexcept
	{
		return rtm::scalar_rad_to_deg(radians);
	}

	template<typename ComponentType>
	ComponentType Radians(ComponentType degrees) noexcept
	{
		return rtm::scalar_deg_to_rad(degrees);
	}

}
