cmake_minimum_required(VERSION 3.28)
project(Tests LANGUAGES CXX)

option(RTMCPP_USE_SIMD "Whether or not RTM should use SSE instructions." OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

file(GLOB TESTS_FILES Tests/**.cpp)

add_executable(${PROJECT_NAME} ${TESTS_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
							Include/
							rtm/includes/)

file(GLOB RTMCPP_HEADERS Include/rtmcpp/**.hpp)
target_sources(${PROJECT_NAME} PRIVATE ${RTMCPP_HEADERS})

if (RTMCPP_USE_SIMD)
	target_compile_options(${PROJECT_NAME} PRIVATE /arch:AVX2)
endif()
