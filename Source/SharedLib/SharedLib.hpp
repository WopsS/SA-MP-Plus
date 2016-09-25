#pragma once

#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <mutex>
#include <sstream>
#include <unordered_map>

#include <fmt/format.h>
#include <fmt/time.h>

#include <Version.hpp>
#include <Singleton/Singleton.hpp>

#include <Logger/Logger.hpp>
#include <PlusNet/Peer.hpp>
#include <Utils/String.hpp>
#include <Settings/Settings.hpp>

// TODO: Create a new type for char / wchar and std::string / std::wstring.