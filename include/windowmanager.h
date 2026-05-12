#ifndef ENGINE_WINDOWMANAGER_H
#define ENGINE_WINDOWMANAGER_H

#include <bits/stdc++.h>
#include <GLFW/glfw3.h>

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
        GLFWwindow *share { NULL };
    };

    class WindowManager
    {
        private:
            std::map<WindowIdentifier, GLFWwindow *> _windows {};
            std::vector<GLFWwindow *> _closedWindows {};

        public:
            GLFWwindow *getWindow(WindowIdentifier);
            GLFWwindow *createWindow(WindowIdentifier, WindowCreationSettings);
            void registerWindowClose(GLFWwindow *);
            void updateWindows();
            void renderWindows();
    };
}

#endif