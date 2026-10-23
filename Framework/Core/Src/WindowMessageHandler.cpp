#include "Precompiled.h"
#include "WindowMessageHandler.h"
#include "DebugUtil.h"

using namespace BlitzEngine;
using namespace BlitzEngine::Core;

void WindowMessageHandler::Hook(HWND window, Callback cb)
{
    mWindow = window;
    mPreviousCallback = (Callback)GetWindowLongPtrA(window, GWLP_WNDPROC);
    SetWindowLongA(window, GWLP_WNDPROC, (LONG_PTR)cb);
}
void WindowMessageHandler::Unhook()
{
    SetWindowLongPtrA(mWindow, GWLP_WNDPROC, (LONG_PTR)mPreviousCallback);
    mWindow = nullptr;
}
LRESULT WindowMessageHandler::ForwardMessage(HWND window, UINT msg, WPARAM mParam, LPARAM lParam)
{
    ASSERT(mPreviousCallback != nullptr, "WindowMessageHandler: no callback is hooked!");
    return CallWindowProcA((WNDPROC)mPreviousCallback, window, msg, mParam, lParam);
}