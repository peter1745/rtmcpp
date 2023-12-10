cmake_minimum_required(VERSION 3.28)
project(rtmcpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(RTMCPP_BUILD_AS_MODULE "Whether or not RTM should be built as a C++20 module." OFF)
option(RTMCPP_USE_SIMD "Whether or not RTM should use SSE instructions." ON)
option(RTMCPP_BUILD_TESTS "Whether or not the Tests project should be built" ON)

file(GLOB RTMCPP_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/Include/rtmcpp/**.hpp)

if (RTMCPP_BUILD_AS_MODULE)
	set(CMAKE_CXX_SCAN_FOR_MODULES ON)

	add_library(${PROJECT_NAME})
	target_sources(${PROJECT_NAME} PUBLIC
			FILE_SET cxx_modules
			TYPE CXX_MODULES
			FILES ${CMAKE_CURRENT_SOURCE_DIR}/Source/rtmcpp.ixx)
	target_sources(${PROJECT_NAME} PRIVATE ${RTMCPP_HEADERS})

	target_include_directories(${PROJECT_NAME} PUBLIC
			${CMAKE_CURRENT_SOURCE_DIR}/Include/rtmcpp/
			${CMAKE_CURRENT_SOURCE_DIR}/rtm/includes/)

	add_compile_definitions(-DRTMCPP_EXPORT=export -DRTMCPP_BUILD_MODULE)

	if (RTMCPP_USE_SIMD)
		target_compile_options(${PROJECT_NAME} PRIVATE
				$<$<CXX_COMPILER_ID:MSVC>:/arch:AVX2>
				$<$<CXX_COMPILER_ID:GNU>:-mavx2>
				$<$<CXX_COMPILER_ID:Clang>:-mavx2>)
	endif()
else()
	add_library(${PROJECT_NAME} INTERFACE)

	target_sources(${PROJECT_NAME} PUBLIC
			FILE_SET HEADERS
			BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Include/rtmcpp/
			FILES ${RTMCPP_HEADERS}
	)

	add_compile_definitions(-DRTMCPP_EXPORT=)
endif()

if (RTMCPP_BUILD_TESTS)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Tests/)
endif()
