#include <BlitzEngine/Inc/BlitzEngine.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    BlitzEngine::AppConfig config;
    config.appName = L"BlitzEngine";
    config.winWidth = 1000;
    config.winHeight = 600;

    BlitzEngine::App app;
    app.Run(config);
    return 0;
}