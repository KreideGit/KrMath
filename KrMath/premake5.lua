project "KrMath"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "include/**.hpp"
    }

    includedirs
    {
        "include"
    }

    defines
	{
		"_CRT_SECURE_NO_WARNINGS"
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