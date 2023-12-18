#pragma once

#include <type_traits>

RTMCPP_EXPORT namespace glm {
	struct vec3;
}

RTMCPP_EXPORT namespace rtmcpp {

	template<typename T>
	constexpr bool IsObject = !(std::is_function_v<T> || std::is_reference_v<T> || std::is_void_v<T>);

	template<typename T>
	struct Converter;

}
