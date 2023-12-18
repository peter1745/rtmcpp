#pragma once

#include "Vector.hpp"
#include "Quat.hpp"

#if !defined(RTMCPP_BUILD_MODULE)
	#include <rtm/qvvf.h>
	#include <rtm/qvvd.h>
#endif

RTMCPP_EXPORT namespace rtmcpp {

	template<typename ComponentType>
	struct TRS
	{
		Vector<ComponentType, 3> Translation;
		Quat<ComponentType> Rotation;
		Vector<ComponentType, 3> Scale;
	};

}
