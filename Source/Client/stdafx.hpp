#pragma once

#include <string>

#define DIRECTINPUT_VERSION 0x0800
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <shellapi.h>
#include <ShlObj.h>

#include <d3d9.h>
#include <dinput.h>

#include <MinHook.h>
#include <SharedLib.hpp>

#include <Game/Game.hpp>
#include <Hooks/Hooks.hpp>
#include <Network/Network.hpp>