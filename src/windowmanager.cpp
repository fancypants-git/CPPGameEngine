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
            std::cout << "tried to create window, but GLFW failed to initialize" << std::endl;
            return nullptr;
        }

        GLFWwindow *window = getWindow(identifier);
        if (window != nullptr)
            return window;

        GLFWwindow *share = NULL;
        if (settings.share)
        {
            share = getWindow(settings.share);
            _sharedContexts[identifier] = settings.share;
        }
        else
        {
            // create a new GpuResourceManager if the context is not shared
            GpuResourceManager gpuRM { GpuResourceManager() };
            _resourceManagers[identifier] = gpuRM;
        }

        window = glfwCreateWindow(settings.width, settings.height, settings.title, settings.monitor, share);
        glfwSetFramebufferSizeCallback(window, defaultFramebufferSizeCallback);
        glfwSetWindowCloseCallback(window, windowCloseCallback);

        _windows[identifier] = window;
    }

    void WindowManager::registerWindowClose(GLFWwindow *window)
    {
        _closedWindows.push_back(window);
    }

    void WindowManager::updateWindows()
    {
        if (!Application::getRenderPipelineManager().getIsGLFWInitialized())
            return;

        if (_windows.empty())
            return;
        
        glfwPollEvents();
    }

    void WindowManager::renderWindows()
    {
        if (!Application::getRenderPipelineManager().getIsGLFWInitialized())
            return;
        
        for (WindowIdentifier identifier : _windowDrawRequests)
        {
            GLFWwindow *window = getWindow(identifier);
            glfwSwapBuffers(window);
        }
    }

    // default glfw window callbacks
    void defaultFramebufferSizeCallback(GLFWwindow *window, int width, int height)
    {
        glfwSetWindowSize(window, width, height);
    }

    void windowCloseCallback(GLFWwindow *window)
    {
        Application::getWindowManager().registerWindowClose(window);
    }
}