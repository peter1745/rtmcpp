workspace "rtmcpp"
	configurations { "Debug", "Release" }
	language "C++"
	cppdialect "C++latest"

project "rtmcpp"
	kind "None"
	location "Include/"

	files {
		"rtmcpp/**.hpp"
	}

	externalincludedirs {
		"./rtm/includes/"
	}

project "Tests"
	kind "ConsoleApp"
	location "Tests/"

	files {
		"./Tests/**.cpp"
	}

	externalincludedirs {
		"./Include/",
		"./rtm/includes/"
	}

    defines {
        "RTMCPP_EXPORT="
    }

	filter { "configurations:Release" }
		vectorextensions "AVX2"
