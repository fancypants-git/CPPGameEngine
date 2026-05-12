#include <application.h>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

        if (_isGLFWInitialized)
            glfwTerminate();

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
