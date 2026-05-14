#include <camera.h>

namespace engine {
    Camera::Camera(WindowIdentifier target, WindowCreationSettings targetCreationSettings)
    {
        Target = target;
        TargetCreationSettings = targetCreationSettings;
    }

    void Camera::setAutoRenderToTarget(bool value)
    {
        _autoRenderToTarget = value;
        if (value)
            // register the camera
            {}
        else
            // unregister the camera
            {}
    }

    void Camera::render()
    {
        
    }
}