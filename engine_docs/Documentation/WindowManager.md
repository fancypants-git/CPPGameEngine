This class manages the windowing system. It keeps track of all windows, and to which [[WindowIdentifier]] they correspond. It keeps the methods for creating, updating and closing windows and polling window events.

# Methods
### getWindow
gets the window corresponding to the passed on [[WindowIdentifier]], or a nullptr if no window is registered by the [[WindowIdentifier]].
#### parameters
- [[WindowIdentifier]]
	the identifier by which the window should be stored
#### returns
GLFWwindow* or nullptr
#### see also
[[WindowIdentifier]],
[GLFWwindow](https://www.glfw.org/docs/latest/group__window.html#ga3c96d80d363e67d13a41b5d1821f3242)

### createWindow
creates and initializes a new window with given settings for the passed on [[WindowIdentifier]] if no window has been registered for that [[WindowIdentifier]]. This function also registers the newly created window. This function returns a nullptr if the GLFW library failed to initialize.
#### parameters
- [[WindowIdentifier]]
	the identifier by which the window should be registered
- [[WindowCreationSettings]]
	the creation settings for the new window
#### returns
GLFWwindow* or nullptr
#### see also
[[WindowIdentifier]],
[[WindowCreationSettings]],
[GLFWwindow](https://www.glfw.org/docs/latest/group__window.html#ga3c96d80d363e67d13a41b5d1821f3242)

### registerWindowClose
registers a window as closed, this method should be called when the user manually closes the window either by code or with the close widget of the window.
#### parameters
- GLFWwindow*
	a pointer to the GLFWwindow that should be registered as closed
#### returns
void

### updateWindows
updates all windows and polls the window events for the next frame. This method should not be called by the user, as it is called automatically in the mainloop
#### returns
void

### renderWindows
renders all windows to the screen. This method should not be called by the user, as it is called automatically in the mainloop
#### returns
void

# tags
#class
#windowing
#manager