#ifndef ENGINE_APPLICATION_H
#define ENGINE_APPLICATION_H

#include <windowmanager.h>
#include <renderpipelinemanager.h>

namespace engine {
    class Application {
        private:
            static void mainloop();
            static void dispose();

            static bool _isRunning;
            static bool _isDisposed;
            static WindowManager _windowManager;
            static RenderPipelineManager _renderPipelineManager;

        public:
            static void run();
            static void requestShutdown();
            static WindowManager getWindowManager();
            static RenderPipelineManager getRenderPipelineManager();
    };
} // namespace engine


#endif