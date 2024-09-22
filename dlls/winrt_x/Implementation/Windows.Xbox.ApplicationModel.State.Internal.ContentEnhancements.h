#pragma once
#include "Windows.Xbox.ApplicationModel.State.Internal.ContentEnhancements.g.h"

// WARNING: This file is automatically generated by a tool. Do not directly
// add this file to your project, as any changes you make will be lost.
// This file is a stub you can use as a starting point for your implementation.
//
// To add a copy of this file to your project:
//   1. Copy this file from its original location to the location where you store 
//      your other source files (e.g. the project root). 
//   2. Add the copied file to your project. In Visual Studio, you can use 
//      Project -> Add Existing Item.
//   3. Delete this comment and the 'static_assert' (below) from the copied file.
//      Do not modify the original file.
//
// To update an existing file in your project:
//   1. Copy the relevant changes from this file and merge them into the copy 
//      you made previously.
//    
// This assertion helps prevent accidental modification of generated files.
//static_assert(false, "This file is generated by a tool and will be overwritten. Open this error and view the comment for assistance.");

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    struct ContentEnhancements : ContentEnhancementsT<ContentEnhancements>
    {
        ContentEnhancements() = default;

        uint64_t GetEnhancementSettings(uint32_t titleId);
        winrt::Windows::Xbox::ApplicationModel::State::Internal::EnhancementFeatureState GetAutoHDREnabledGlobally();
        bool GetAutoHDRAllowedForGame(uint32_t titleId);
        bool GetAutoHDREnabledForGame(uint32_t titleId);
        void SetAutoHDREnabledForGame(uint32_t titleId, bool isFeatureEnabled);
        bool GetPerformanceModeAllowedForGame(uint32_t titleId);
        bool GetPerformanceModeEnabledForGame(uint32_t titleId);
        void SetPerformanceModeEnabledForGame(uint32_t titleId, bool isFeatureEnabled);
        bool GetPerformanceModeForGameRequires120Hz(uint32_t titleId);
        winrt::Windows::Xbox::ApplicationModel::State::Internal::PerformanceModeDetails GetPerformanceModeDetailsForGame(uint32_t titleId);
        bool GetAutoHDRAllowedForGameFromManifest(hstring const& aumid);
        bool GetAutoHDREnabledForGameFromManifest(uint32_t titleId);
        bool IsGen9AwareGame(winrt::guid const& legacyProductId);
    };
}
namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::factory_implementation
{
    struct ContentEnhancements : ContentEnhancementsT<ContentEnhancements, implementation::ContentEnhancements>
    {
    };
}
