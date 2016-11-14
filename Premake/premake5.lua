require("premake", ">=5.0.0-alpha10")

local version = 
{ 
    1,  -- Major
    0,  -- Minor
    0   -- Patch
}

local prereleaseVersion =
{
     "alpha", -- Name (alpha or beta)
     "1" -- Number
}

local protocolVersion = 1;

local config =
{
    includes={ "../Includes/Common", "../Source/SharedLib" },
    libs={ "RakNetLibStatic" },
    libsPath={ "../Build/Libs", "../Libs" }
}

if (os.is("Windows") == true) then
    config["libs"] = table.insertflat(config["libs"], "ws2_32")
end

local function formatVersion(inputFile, outputFile, writeProtocol)
    local inFile = io.open(inputFile, "r")

    if not inFile then
        return nil
    end

    local outFile = io.open(outputFile, "w")
    local versionString = table.implode(version, "", "", ".")
    local prereleaseVersionString = ""
    local result = inFile:read("*a")

    if string.len(prereleaseVersion[1]) > 0 then
        versionString = versionString .. "-" .. table.implode(prereleaseVersion, "", "", "")
    end

    if writeProtocol == false then
        outFile:write(string.format(result, versionString))
    else
        outFile:write(string.format(result, versionString, protocolVersion))
    end

    inFile:close()
    outFile:close()
end

formatVersion("../a_samp+.inc.in", "../Build/Server/pawno/include/a_samp+.inc", false)
formatVersion("../Source/SharedLib/Version.hpp.in", "../Includes/Common/Version.hpp", true)

workspace ("SA-MP+")
    architecture ("x86")
    configurations { "Debug", "Release" }
    flags { "C++14" }
    location ("Projects")
    characterset ("MBCS")

     filter { "action:gmake" }
        defines { "LINUX" }

    filter { "action:vs*" }
        defines { "_CRT_SECURE_NO_WARNINGS", "WIN32" }

    filter { "configurations:Debug" }
        defines { "DEBUG" }
        targetsuffix ("_d")

    filter { "configurations:Release" }
        defines { "NDEBUG" }
        optimize ("On")

    if (os.is("Windows") == true) then
        project ("Client")
            kind ("SharedLib")
            language ("C++")
            pchheader ("stdafx.hpp")
            pchsource ("../Source/Client/stdafx.cpp")
            symbols ("On")
            targetdir ("../Build/Client")
            targetextension (".asi")
            targetname ("samp-plus")

            includedirs { config["includes"], "$(DXSDK_DIR)Include", "../Includes/Client", "../Source/Client" }
            libdirs { config["libsPath"] }
            links { config["libs"], "dxguid", "libMinHook.x86", "SharedLib" }

            files { "../Source/Client/**.cpp", "../Source/Client/**.hpp" }
    end

    project ("Server")
        kind ("SharedLib")
        language ("C++")
        pchheader ("stdafx.hpp")
        pchsource ("../Source/Server/stdafx.cpp")
        symbols ("On")
        targetdir ("../Build/Server")
        targetname ("samp-plus")

        defines { "SAMPGDK_CPP_WRAPPERS", "SAMPGDK_AMALGAMATION" }

        includedirs { config["includes"], "../Includes/Server", "../Source/Server" }
        libdirs { config["libsPath"] }
        links { config["libs"], "SharedLib" }

        files { "../Includes/Server/samp-plugin-sdk/amxplugin.cpp", "../Source/Server/**.cpp", "../Source/Server/**.hpp", "../Source/Server/**.def", "../Source/Server/sampgdk/*.c", "../Source/Server/sampgdk/*.h" }
        vpaths { ["*"] = "../Source/Server", ["Sdk"] = "../Includes/Server/samp-plugin-sdk/**" }

        -- Disable precompiled headers for this file.
        filter { "files:../Includes/Server/samp-plugin-sdk/amxplugin.cpp or ../Source/Server/**.c" }
            flags { "NoPCH" }

    group ("Dependencies")
        project ("SharedLib")
            kind ("StaticLib")
            language ("C++")
            pchheader ("SharedLib.hpp")
            pchsource ("../Source/SharedLib/SharedLib.cpp")
            symbols ("On")
            targetdir ("../Build/Libs")

            includedirs { config["includes"] }
            libdirs { config["libsPath"] }
            links { config["libs"] }

            files { "../Source/SharedLib/**.cpp", "../Source/SharedLib/**.hpp" }