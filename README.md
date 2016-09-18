# SA-MP+

| Travis CI | AppVeyor |
| ------------- | ------------- |
| [![Build Status](https://travis-ci.org/WopsS/SA-MP-Plus.svg?branch=master)](https://travis-ci.org/WopsS/SA-MP-Plus) | [![Build status](https://ci.appveyor.com/api/projects/status/y9m6maygl4i6ldt0/branch/master?svg=true)](https://ci.appveyor.com/project/WopsS/sa-mp-plus/branch/master) |

A plugin that adds new features to [SA-MP](http://www.sa-mp.com).

## Installation

### Client

1. Download the [ASI Loader for GTA San Andreas](http://www.gtagarage.com/mods/show.php?id=8321) and extract it into the **GTA San Andreas** directory.
2. Download the [latest release](https://github.com/WopsS/SA-MP-Plus/releases/latest) of this project.
3. Extract the **samp-plus.asi** file into the **GTA San Andreas** directory.

### Server

1. Extract the content of the [latest release](https://github.com/WopsS/SA-MP-Plus/releases/latest) into the **root** directory of your SA-MP server.
2. Add the following line to **server.cfg**:
    * `plugins samp-plus` for **Windows**.
    * `plugins samp-plus.so` for **Linux**.
3. Add the following line to any script that uses **SA-MP+**:
    * `#include <a_samp+.inc>`

## Build instructions

### Requirements

* **[fmt](https://github.com/fmtlib/fmt)** library.
* **[MinHook](https://github.com/TsudaKageyu/minhook)** library.
* **[PREMAKE 5](https://github.com/premake/premake-core/releases)**.
* **[RakNet](https://github.com/WopsS/RakNet)** library.

### Windows

1. Download and install **[Visual Studio 2015 Community Edition](https://www.visualstudio.com/)** or a higher version.
2. Download and install **[DirectX Software Development Kit](https://www.microsoft.com/en-us/download/details.aspx?id=6812)**.
3. Clone this repository.
4. Extract the content of **[PREMAKE 5](https://github.com/premake/premake-core/releases)** into the **Premake** directory.
5. Copy all headers from the **[fmt](https://github.com/fmtlib/fmt/tree/master/fmt)** directory into the **Includes/Common/fmt** directory.
6. Copy the content of the **MinHook/include** directory into the **Includes/Client** directory.
7. Copy the content of the **RakNet/include** directory into the **Includes/Common** directory.
8. Copy the compiled **[fmt](https://github.com/fmtlib/fmt)** (**fmt**) library, **[MinHook](https://github.com/TsudaKageyu/minhook)** (**libMinHook.x86**) library and **[RakNet](https://github.com/WopsS/RakNet)** (**RakNetLibStatic**) library into the **Libs** directory.
9. Go to the **Premake** directory and run **MakeVS2015Projects.bat**.
10. Open the solution (**SA-MP+.sln**) located in **Premake/Projects** directory.
11. Build the projects.

### Linux

1. Download and install a **C++ compiler**.
2. Clone this repository.
3. Extract the content of **[PREMAKE 5](https://github.com/premake/premake-core/releases)** into the **Premake** directory.
4. Copy all headers from the **[fmt](https://github.com/fmtlib/fmt/tree/master/fmt)** directory into the **Includes/Common/fmt** directory.
5. Copy the content of the **RakNet/include** directory into the **Includes/Common** directory.
6. Copy the compiled **[fmt](https://github.com/fmtlib/fmt)** (**libfmt**) library and **[RakNet](https://github.com/WopsS/RakNet)** (**libRakNetLibStatic**) library into the **Libs** directory.
7. Go to the **Premake** directory and run **MakeGMakeProjects.sh**.
8. Build the projects by running the `make` command into the **Premake/Projects** directory.