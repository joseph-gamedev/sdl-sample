#include <Windows.h>
#include "Application.h"

extern "C" int WINAPI WinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    AllocConsole();

    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    freopen("CON", "w", stderr);

    Application* app = CreateApplciation();
    if (!app->Run())
    {
        delete app;
        app = nullptr;
    }
    return 0;
}

