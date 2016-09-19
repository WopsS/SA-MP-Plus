require("premake", ">=5.0.0-alpha9")

local version = 
{ 
    1,  -- Major
    0,  -- Minor
    0   -- Patch
}

local config =
{
    includes={ "../Includes/Common", "../Source/SharedLib" },
    libs={ "fmt", "RakNetLibStatic" },
    libsPath={ "../Build/Libs", "../Libs" }
}

local function formatVersion(inputFile, outputFile)
    local inFile = io.open(inputFile, "r")

    if not inFile then
        return nil
    end

    local outFile = io.open(outputFile, "w")

    outFile:write(string.format(inFile:read("*a"), table.implode(version, "", "", ".")))

    inFile:close()
    outFile:close()
end

formatVersion("../a_samp+.inc.in", "../Build/Server/pawno/include/a_samp+.inc")
formatVersion("../Source/SharedLib/Version.hpp.in", "../Includes/Common/Version.hpp")

workspace ("SA-MP+")
    architecture ("x86")
    configurations { "Debug", "Release" }
    flags { "C++14" }
    location ("Projects")

     filter { "action:gmake" }
        defines { "LINUX" }

    filter { "action:vs*" }
        defines { "WIN32" }

    filter { "configurations:Debug" }
        defines { "DEBUG" }
        flags { "Symbols" }
        targetsuffix ("_d")

    filter { "configurations:Release" }
        defines { "NDEBUG" }
        optimize ("On")

    if (os.is("Windows") == true) then
        project ("Client")
            kind ("SharedLib")
            language ("C++")
            targetdir ("../Build/Client")
            targetextension (".asi")
            targetname ("samp-plus")
            pchheader ("stdafx.hpp")
            pchsource ("../Source/Client/stdafx.cpp")

            includedirs { config["includes"], "$(DXSDK_DIR)Include", "../Includes/Client", "../Source/Client" }
            libdirs { config["libsPath"] }
            links { config["libs"], "libMinHook.x86", "SharedLib" }

            files { "../Source/Client/**.cpp", "../Source/Client/**.hpp" }
    end

    project ("Server")
        kind ("SharedLib")
        language ("C++")
        targetdir ("../Build/Server")
        targetname ("samp-plus")
        pchheader ("stdafx.hpp")
        pchsource ("../Source/Server/stdafx.cpp")

        defines { "SAMPGDK_CPP_WRAPPERS", "SAMPGDK_AMALGAMATION" }

        includedirs { config["includes"], "../Includes/Server", "../Source/Server" }
        libdirs { config["libsPath"] }
        links { config["libs"], "SharedLib" }

        files { "../Source/Server/**.cpp", "../Source/Server/**.hpp", "../Source/Server/**.def" }

    group ("Dependencies")
        project ("SharedLib")
            kind ("StaticLib")
            language ("C++")
            targetdir ("../Build/Libs")
            pchheader ("SharedLib.hpp")
            pchsource ("../Source/SharedLib/SharedLib.cpp")

            includedirs { config["includes"] }
            libdirs { config["libsPath"] }
            links { config["libs"] }

            files { "../Source/SharedLib/**.cpp", "../Source/SharedLib/**.hpp" }