a struct defining the settings used for creating and initializing a new window
# properties
### width
the width of the new window (excluding window details)
#### type
int
#### default value
800
### height
the height of the new window (excluding window details)
#### type
int
#### default value
600
### title
the title of the new window
#### type
char*
#### default value
OpenGL Window
### monitor
the monitor to use for full screen mode, or NULL for windowed mode
#### type
GLFWmonitor*
#### default value
NULL
#### see also
[GLFWmonitor](https://www.glfw.org/docs/latest/group__monitor.html#ga8d9efd1cde9426692c73fe40437d0ae3)
### share
the window whose context to share resources with, or NULL to not share resources
#### type
GLFWwindow
#### default value
NULL
#### see also
[GLFWwindow](https://www.glfw.org/docs/latest/group__window.html#ga3c96d80d363e67d13a41b5d1821f3242)

# see also
[GLFWwindow](https://www.glfw.org/docs/latest/group__window.html#ga3c96d80d363e67d13a41b5d1821f3242),
[glfwCreateWindow](https://www.glfw.org/docs/latest/group__window.html#ga3555a418df92ad53f917597fe2f64aeb),
[[WindowManager]]
# tags
#struct
#windowing