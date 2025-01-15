#include "pch.h"
#include "Windows.Xbox.Management.Deployment.DownloadableContentPackageManager.h"
#include "Windows.Xbox.Management.Deployment.DownloadableContentPackageManager.g.cpp"

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

namespace winrt::Windows::Xbox::Management::Deployment::implementation
{
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Management::Deployment::IDownloadableContentPackage> DownloadableContentPackageManager::FindPackages(winrt::Windows::Xbox::Management::Deployment::InstalledPackagesFilter const& filter)
    {
        return winrt::single_threaded_vector<winrt::Windows::Xbox::Management::Deployment::IDownloadableContentPackage>( ).GetView();
    }
    winrt::event_token DownloadableContentPackageManager::DownloadableContentPackageInstallCompleted(winrt::Windows::Xbox::Management::Deployment::DownloadableContentPackageInstallCompletedEventHandler const& handler)
    {
        return m_downloadableContentPackageInstallCompleted.add(handler);
    }
    void DownloadableContentPackageManager::DownloadableContentPackageInstallCompleted(winrt::event_token const& eventCookie) noexcept
    {
        m_downloadableContentPackageInstallCompleted.remove(eventCookie);
    }
    winrt::event_token DownloadableContentPackageManager::DownloadableContentPackageInstallCompletedWithDetails(winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Management::Deployment::IDownloadableContentPackageInstallCompletedEventArgs> const& eventHandler)
    {
        return {};
    }
    void DownloadableContentPackageManager::DownloadableContentPackageInstallCompletedWithDetails(winrt::event_token const& eventCookie) noexcept
    {
        throw hresult_not_implemented();
    }
}
