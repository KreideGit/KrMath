IncludeDir = {}
IncludeDir["KrMath"]     = "%{wks.location}/KrMath/include"
IncludeDir["googletest"] = "%{wks.location}/KrMathTests/vendor/googletest/googletest/include"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace "KrMath"
    architecture "x64"
    startproject "KrMathTests"

    configurations 
    { 
        "Debug", 
        "Release" 
    }

    flags
	{
		"MultiProcessorCompile"
	}

group "Dependencies"
    include "KrMathTests/vendor/googletest/googletest"

group ""
    include "KrMath"
    include "KrMathTests"

newaction 
{
    trigger = "clean",
    description = "cleans the project folder",
    execute = function()
        os.rmdir("./bin")
        os.rmdir("./bin-int")
        os.rmdir("**./bin")
        os.rmdir("**./bin-int")
        os.rmdir("**./.vs")
        os.remove("**.sln")
        os.remove("**.vcxproj")
        os.remove("**.vcxproj.filters")
        os.remove("**.vcxproj.user")
        print("Done")
    end
}