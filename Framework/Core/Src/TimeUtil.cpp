#include "Precompiled.h"
#include "TimeUtil.h"

using namespace BlitzEngine;
using namespace BlitzEngine::Core;

float TimeUtil::GetTime()
{
    static const auto startTime = std::chrono::high_resolution_clock::now();
    const auto currentTime = std::chrono::high_resolution_clock::now();
    const auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();
    return milliseconds / 1000.0f;
}

float TimeUtil::GetDeltaTime()
{
    static auto lastCallTime = std::chrono::high_resolution_clock::now();
    const auto currentTime = std::chrono::high_resolution_clock::now();
    const auto millieseconds = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - currentTime).count();
    lastCallTime = currentTime;
    return millieseconds / 1000.0f;
}