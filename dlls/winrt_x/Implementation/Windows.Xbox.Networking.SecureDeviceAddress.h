#pragma once
#include "Windows.Xbox.Networking.SecureDeviceAddress.g.h"

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
//////////static_assert(false, "This file is generated by a tool and will be overwritten. Open this error and view the comment for assistance.");

namespace winrt::Windows::Xbox::Networking::implementation
{
    struct SecureDeviceAddress : SecureDeviceAddressT<SecureDeviceAddress>
    {
        SecureDeviceAddress() = default;

        SecureDeviceAddress(winrt::Windows::Storage::Streams::IBuffer const& buffer);
        static int32_t CompareBuffers(winrt::Windows::Storage::Streams::IBuffer const& buffer1, winrt::Windows::Storage::Streams::IBuffer const& buffer2);
        static int32_t CompareBytes(array_view<uint8_t const> bytes1, array_view<uint8_t const> bytes2);
        static winrt::Windows::Xbox::Networking::SecureDeviceAddress FromBytes(array_view<uint8_t const> bytes);
        static winrt::Windows::Xbox::Networking::SecureDeviceAddress GetLocal();
        static winrt::Windows::Xbox::Networking::SecureDeviceAddress CreateDedicatedServerAddress(hstring const& hostnameOrAddress);
        static winrt::Windows::Xbox::Networking::SecureDeviceAddress FromBase64String(hstring const& base64String);
        winrt::event_token BufferChanged(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Networking::SecureDeviceAddress, winrt::Windows::Foundation::IInspectable> const& handler);
        void BufferChanged(winrt::event_token const& token) noexcept;
        winrt::Windows::Storage::Streams::IBuffer GetBuffer();
        int32_t Compare(winrt::Windows::Xbox::Networking::SecureDeviceAddress const& secureDeviceAddress);
        hstring GetBase64String();
        bool IsLocal();
        winrt::Windows::Xbox::Networking::NetworkAccessType NetworkAccessType();
    };
}
namespace winrt::Windows::Xbox::Networking::factory_implementation
{
    struct SecureDeviceAddress : SecureDeviceAddressT<SecureDeviceAddress, implementation::SecureDeviceAddress>
    {
    };
}
