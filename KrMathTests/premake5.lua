project "KrMathTests"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "src/**.hpp", 
        "src/**.cpp" 
    }

    includedirs
    {
        "src",
        "%{IncludeDir.KrMath}",
        "%{IncludeDir.googletest}"
    }

    links 
    { 
        "googletest"
    }

    filter "system:windows"
		systemversion "latest"

    filter "configurations:Debug"
        defines "KR_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "KR_RELEASE"
        runtime "Release"
        optimize "On"