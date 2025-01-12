#include "pch.h"
#include "Microsoft.Xbox.Services.GameServerPlatform.GameServerPlatformService.h"
#include "Microsoft.Xbox.Services.GameServerPlatform.GameServerPlatformService.g.cpp"

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

namespace winrt::Microsoft::Xbox::Services::GameServerPlatform::implementation
{
    winrt::Windows::Foundation::IAsyncOperation<winrt::Microsoft::Xbox::Services::GameServerPlatform::ClusterResult> GameServerPlatformService::AllocateClusterAsync(uint32_t gameServerTitleId, hstring serviceConfigurationId, hstring sessionTemplateName, hstring sessionName, bool abortIfQueued)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Microsoft::Xbox::Services::GameServerPlatform::ClusterResult> GameServerPlatformService::AllocateClusterInlineAsync(uint32_t gameServerTitleId, hstring serviceConfigurationId, hstring sandboxId, hstring ticketId, hstring gsiSetId, hstring gameVariantId, uint64_t maxAllowedPlayers, hstring location, bool abortIfQueued)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Microsoft::Xbox::Services::GameServerPlatform::GameServerTicketStatus> GameServerPlatformService::GetTicketStatusAsync(uint32_t gameServerTitleId, hstring ticketId)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Microsoft::Xbox::Services::GameServerPlatform::GameServerMetadataResult> GameServerPlatformService::GetGameServerMetadataAsync(uint32_t titleId, uint32_t maxAllowedPlayers, bool publisherOnly, uint32_t maxVariants, hstring locale)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Microsoft::Xbox::Services::GameServerPlatform::GameServerMetadataResult> GameServerPlatformService::GetGameServerMetadataAsync(uint32_t titleId, uint32_t maxAllowedPlayers, bool publisherOnly, uint32_t maxVariants, hstring locale, winrt::Windows::Foundation::Collections::IMapView<hstring, hstring> filterTags)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<winrt::Microsoft::Xbox::Services::GameServerPlatform::QualityOfServiceServer>> GameServerPlatformService::GetQualityOfServiceServersAsync()
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Microsoft::Xbox::Services::GameServerPlatform::AllocationResult> GameServerPlatformService::AllocateSessionHost(uint32_t gameServerTitleId, winrt::Windows::Foundation::Collections::IVectorView<hstring> locations, hstring sessionId, hstring cloudGameId, hstring gameModeId, hstring sessionCookie)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Microsoft::Xbox::Services::GameServerPlatform::AllocationResult> GameServerPlatformService::GetSessionHostAllocationStatus(uint32_t gameServerTitleId, hstring sessionId)
    {
        throw hresult_not_implemented();
    }
}
