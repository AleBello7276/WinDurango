﻿// ReSharper disable CppInconsistentNaming
// ReSharper disable CppParameterMayBeConst
// ReSharper disable CppClangTidyClangDiagnosticMicrosoftCast
// ReSharper disable CppClangTidyClangDiagnosticUndefinedReinterpretCast
// ReSharper disable CppClangTidyClangDiagnosticShadow
// ReSharper disable CppClangTidyClangDiagnosticCastFunctionTypeStrict
// ReSharper disable CppFunctionalStyleCast
// ReSharper disable CppClangTidyClangDiagnosticCastAlign
// ReSharper disable CppClangTidyClangDiagnosticCastQual
// ReSharper disable CppZeroConstantCanBeReplacedWithNullptr
#pragma once
#include <winrt/Windows.ApplicationModel.h>
#include "CoreApplicationX.h"

inline bool IsClassName(HSTRING classId, const char* classIdName)
{
	const wchar_t* classIdString = WindowsGetStringRawBuffer(classId, nullptr);
	std::wstring classIdWString(classIdString);
	const std::string classIdStringUTF8(classIdWString.begin(), classIdWString.end());

	return (classIdStringUTF8 == classIdName);
}

typedef HRESULT(*DllGetForCurrentThreadFunc) (ICoreWindowStatic*, CoreWindow**);
typedef HRESULT(*DllGetForCurrentThreadFunc_App) (ABI::Windows::ApplicationModel::Core::ICoreApplication*, winrt::Windows::ApplicationModel::Core::CoreApplication**);
typedef HRESULT(*DllGetActivationFactoryFunc) (HSTRING, IActivationFactory**);

DllGetForCurrentThreadFunc pDllGetForCurrentThread = nullptr;
DllGetForCurrentThreadFunc_App pDllGetForCurrentThread_App = nullptr;
DllGetActivationFactoryFunc pDllGetActivationFactory = nullptr;

HRESULT(STDMETHODCALLTYPE* TrueGetForCurrentThread_App)(ABI::Windows::ApplicationModel::Core::ICoreApplication* Iapplication,
winrt::Windows::ApplicationModel::Core::CoreApplication** Application);
HRESULT(STDMETHODCALLTYPE* TrueGetForCurrentThread)(ICoreWindowStatic* staticWindow, CoreWindow** window);
HRESULT(WINAPI* TrueRoGetActivationFactory)(HSTRING classId, REFIID iid, void** factory) = RoGetActivationFactory;

inline HRESULT STDMETHODCALLTYPE GetForCurrentThread_Hook(ICoreWindowStatic* paramThis, CoreWindow** window)
{
	// ReSharper disable once CppLocalVariableMayBeConst
	HRESULT hr = TrueGetForCurrentThread(paramThis, window);

	//*reinterpret_cast<void**>(window) = new CoreWindowX(*window);
	auto p = *reinterpret_cast<void**>(window);

	p = new CoreWindowX(*window);

	return hr;
}

inline HRESULT STDMETHODCALLTYPE GetForCurrentThread_Hook_App(ABI::Windows::ApplicationModel::Core::ICoreApplication* paramThis,
	winrt::Windows::ApplicationModel::Core::CoreApplication** Application)
{
	// ReSharper disable once CppLocalVariableMayBeConst
	HRESULT hrApp = TrueGetForCurrentThread_App(paramThis, Application);

	//*reinterpret_cast<void**>(Application) = new CoreApplicationX(*Application);
	auto pApp = *reinterpret_cast<void**>(Application);

	pApp = new CoreApplicationX(*Application);

	return hrApp;
}

inline HRESULT WINAPI RoGetActivationFactory_Hook(HSTRING classId, REFIID iid, void** factory)
{
	auto hr = TrueRoGetActivationFactory(classId, iid, factory);

	if (FAILED(hr))
	{
		auto library = LoadPackagedLibrary(L"winrt_x.dll", 0);

		if (!library) library = LoadLibraryW(L"winrt_x.dll");

		if (!library) return hr;

		pDllGetActivationFactory = reinterpret_cast<DllGetActivationFactoryFunc>
			(GetProcAddress(library, "DllGetActivationFactory"));

		if (!pDllGetActivationFactory)
			return hr;

		ComPtr<IActivationFactory> _factory;


		if (IsClassName(classId, "Windows.UI.Core.CoreWindow"))
		{
			ComPtr<ICoreWindowStatic> coreWindowStatic;

			hr = RoGetActivationFactory(HStringReference(RuntimeClass_Windows_UI_Core_CoreWindow).Get(), IID_PPV_ARGS(&coreWindowStatic));

			*reinterpret_cast<void**>(&TrueGetForCurrentThread) = (*reinterpret_cast<void***>(coreWindowStatic.Get()))[6];

			DetourAttach(&TrueGetForCurrentThread, GetForCurrentThread_Hook);
		}
		else
		{
			hr = pDllGetActivationFactory(classId, _factory.GetAddressOf());
		}

		if (FAILED(hr)) return hr;

		return _factory.CopyTo(iid, factory);

		if (IsClassName(classId, "Windows.ApplicationModel.Core.CoreApplication"))
		{
			ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplication> ICoreApplicationPtr;

			hr = RoGetActivationFactory(HStringReference(RuntimeClass_Windows_ApplicationModel_Core_CoreApplication).Get(), IID_PPV_ARGS(&ICoreApplicationPtr));

			*reinterpret_cast<void**>(&TrueGetForCurrentThread_App) = (*reinterpret_cast<void***>(ICoreApplicationPtr.Get()))[6];

			DetourAttach(&TrueGetForCurrentThread_App, GetForCurrentThread_Hook_App);
		}
		else
		{
			hr = pDllGetActivationFactory(classId, _factory.GetAddressOf());
		}

		if (FAILED(hr)) return hr;

		return _factory.CopyTo(iid, factory);
	}
		
	return hr;

}