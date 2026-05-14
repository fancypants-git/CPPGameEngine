#ifndef ENGINE_RENDERPIPELINEMANAGER_H
#define ENGINE_RENDERPIPELINEMANAGER_H

namespace engine {
    class RenderPipelineManager
    {
        private:
            bool _isGLFWInitialized { false };
            bool _isGladInitialized { false };
            bool _isDisposed { false };
        
        public:
            bool initializeGLFW();
            bool initializeGlad();
            bool getIsGLFWInitialized();
            bool getIsGladInitialized();

            void dispose();
    };
}

#endif