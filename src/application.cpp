#include <application.h>
#include <iostream>

namespace engine {
    bool Application::_isRunning = false;
    bool Application::_isDisposed = false;
    WindowManager Application::_windowManager { WindowManager() };
    RenderPipelineManager Application::_renderPipelineManager { RenderPipelineManager() };

    void Application::mainloop()
    {
        while (_isRunning)
        {
            
        }

        dispose();
    }

    void Application::dispose()
    {
        if (_isDisposed) return;

        _renderPipelineManager.dispose();

        _isDisposed = true;
    }

    void Application::run()
    {
        _isRunning = true;
        mainloop();
    }

    void Application::requestShutdown()
    {
        _isRunning = false;
    }

    WindowManager Application::getWindowManager()
    {
        return _windowManager;
    }

    RenderPipelineManager Application::getRenderPipelineManager()
    {
        return _renderPipelineManager;
    }
} // namespace engine
