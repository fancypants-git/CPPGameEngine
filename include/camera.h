#ifndef ENGINE_CAMERA_H
#define ENGINE_CAMERA_H

#include <windowmanager.h>

namespace engine {
    class Camera
    {
        private:
            bool _autoRenderToTarget { true };
        public:
            Camera(WindowIdentifier, WindowCreationSettings);

            void setAutoRenderToTarget(bool);
            void render();

            WindowIdentifier Target;
            WindowCreationSettings TargetCreationSettings;
    };
}

#endif