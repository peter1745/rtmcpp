cmake_minimum_required(VERSION 3.28)
project(Tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (RTMCPP_BUILD_AS_MODULE)
    add_executable(${PROJECT_NAME})
    target_sources(${PROJECT_NAME} PUBLIC
            FILE_SET cxx_modules
            TYPE CXX_MODULES
            FILES ${CMAKE_CURRENT_SOURCE_DIR}/Main.ixx
    )

    target_include_directories(${PROJECT_NAME} PRIVATE
            ../Include/
            ../rtm/includes/)

    target_link_libraries(${PROJECT_NAME} PUBLIC rtmcpp)
else()
    file(GLOB TESTS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/**.cpp)
    add_executable(${PROJECT_NAME} ${TESTS_FILES})

    target_include_directories(${PROJECT_NAME} PRIVATE
            ../Include/
            ../rtm/includes/)

    target_link_libraries(${PROJECT_NAME} INTERFACE rtmcpp)
endif()

if (RTMCPP_USE_SIMD)
    target_compile_options(${PROJECT_NAME} PUBLIC
            $<$<CXX_COMPILER_ID:MSVC>:/arch:AVX2>
            $<$<CXX_COMPILER_ID:GNU>:-mavx2>
            $<$<CXX_COMPILER_ID:Clang>:-mavx2>)
endif()
