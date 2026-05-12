#include <windowmanager.h>
#include <application.h>

namespace engine {
    GLFWwindow *WindowManager::getWindow(WindowIdentifier identifier)
    {
        if (std::find(_windows.begin(), _windows.end(), identifier) == _windows.end())
            return nullptr;
        
        return _windows[identifier];
    }

    GLFWwindow *WindowManager::createWindow(WindowIdentifier identifier, WindowCreationSettings settings)
    {
        if (!Application::getRenderPipelineManager().initializeGLFW())
        {
            std::cout << "tried creating window, but GLFW is not initialized yet" << std::endl;
            return nullptr;
        }

        GLFWwindow *window = getWindow(identifier);
        if (window != nullptr)
            return window;

        window = glfwCreateWindow(settings.width, settings.height, settings.title, settings.monitor, settings.share);
        glfwSetFramebufferSizeCallback(window, defaultFramebufferSizeCallback);
        glfwSetWindowCloseCallback(window, windowCloseCallback);

        _windows[identifier] = window;
    }

    void WindowManager::registerWindowClose(GLFWwindow *window)
    {
        _closedWindows.push_back(window);
    }

    void defaultFramebufferSizeCallback(GLFWwindow *window, int width, int height)
    {
        glfwSetWindowSize(window, width, height);
    }

    void windowCloseCallback(GLFWwindow *window)
    {
        Application::getWindowManager().registerWindowClose(window);
    }
}