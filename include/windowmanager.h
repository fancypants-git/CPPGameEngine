#ifndef ENGINE_WINDOWMANAGER_H
#define ENGINE_WINDOWMANAGER_H

#include <bits/stdc++.h>
#include <GLFW/glfw3.h>
#include <gpuresourcemanager.h>

namespace engine {
    enum WindowIdentifier {
        Window0,
        Window1,
        Window2,
        Window3,
        Main = Window0,
        Last = Window3
    };

    struct WindowCreationSettings
    {
        int width { 800 };
        int height { 600 };
        char *title { "OpenGL Window" };
        GLFWmonitor *monitor { NULL };
        WindowIdentifier share { (WindowIdentifier) -1 };
    };

    class WindowManager
    {
        private:
            std::map<WindowIdentifier, GLFWwindow *> _windows {};
            std::map<WindowIdentifier, WindowIdentifier> _sharedContexts {};
            std::map<WindowIdentifier, GpuResourceManager> _resourceManagers {};
            std::vector<GLFWwindow *> _closedWindows {};
            std::vector<WindowIdentifier> _windowDrawRequests {};

        public:
            GLFWwindow *getWindow(WindowIdentifier);
            GpuResourceManager &getGpuResourceManager(WindowIdentifier);
            GLFWwindow *createWindow(WindowIdentifier, WindowCreationSettings);
            void registerWindowClose(GLFWwindow *);
            void registerDrawRequest(WindowIdentifier);
            void updateWindows();
            void renderWindows();
    };
}

#endif