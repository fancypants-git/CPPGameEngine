## Create windowing system
### plan
- [ ] Allow the user to set a camera's target initialization variables (see [[WindowCreationSettings]])
- [x] Each window context (because windows can have a shared context) contains a [[GpuResourceManager]], this is done by storing the resource managers paired with the [[WindowIdentifier]] of which the window context is paired to.
- [x] If a context is requested to be shared, the [[WindowIdentifier]] of the new window will be added to a map pointing to the window which's context it shares
- [ ] implement rendering method to [[WindowManager]] (see [[#game loop]] - 4)
- [ ] implement method that handles [[#game loop]] - 5
#### game loop
1. window update
	all windows are updated accordingly and window events are polled
2. game update
	the game scene state is updated and the physics update will be called
3. rendering preparation
	all drawables and cameras are prepared for rendering
	all camera's rendering will send a draw request to their target window
4. rendering phase
	all windows' back buffers are cleared
	each window with their own render context is rendered to (so windows containing a context that is shared with others counts, but windows using a shared context that they don't own do not)
	GLAD will also be initialized if it wasn't already
5. window display
	all windows' buffers are swapped
	the windows that did not get a draw request registered will be closed
## Camera
### camera class
- [x] implement a target [[WindowIdentifier]] and [[WindowCreationSettings]] for when the target needs to be instantiated
- [x] implement an auto render variable
- [ ] implement a rendering preparation method, which upon called, registers a render request (and later calculates the projection/view matrix when transforms have been added)
### render pipeline manager
- [ ] implement a method for handling drawable registration
- [ ] implement a method for handling camera auto rendering
- [ ] implement a method for executing the rendering preparation (see [[#game loop]] - 3)
- [ ] implement a method for executing the rendering phase (see [[#game loop]] - 4)