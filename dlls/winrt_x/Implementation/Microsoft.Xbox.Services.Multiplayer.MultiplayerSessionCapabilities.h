#pragma once
#include "Microsoft.Xbox.Services.Multiplayer.MultiplayerSessionCapabilities.g.h"

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
////////static_assert(false, "This file is generated by a tool and will be overwritten. Open this error and view the comment for assistance.");

namespace winrt::Microsoft::Xbox::Services::Multiplayer::implementation
{
    struct MultiplayerSessionCapabilities : MultiplayerSessionCapabilitiesT<MultiplayerSessionCapabilities>
    {
        MultiplayerSessionCapabilities() = default;

        bool Connectivity();
        void Connectivity(bool value);
        bool SuppressPresenceActivityCheck();
        void SuppressPresenceActivityCheck(bool value);
        bool Gameplay();
        void Gameplay(bool value);
        bool Large();
        void Large(bool value);
        bool ConnectionRequiredForActiveMembers();
        void ConnectionRequiredForActiveMembers(bool value);
        bool UserAuthorizationStyle();
        void UserAuthorizationStyle(bool value);
        bool Crossplay();
        void Crossplay(bool value);
        bool Team();
        void Team(bool value);
        bool Arbitration();
        void Arbitration(bool value);
        bool Searchable();
        void Searchable(bool value);
        bool HasOwners();
        void HasOwners(bool value);
    };
}
namespace winrt::Microsoft::Xbox::Services::Multiplayer::factory_implementation
{
    struct MultiplayerSessionCapabilities : MultiplayerSessionCapabilitiesT<MultiplayerSessionCapabilities, implementation::MultiplayerSessionCapabilities>
    {
    };
}
