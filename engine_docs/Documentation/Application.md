The static, and thus has no constructor, Application class manages the application and program loop. It contains the methods for running the game application and requesting a shutdown of the game application. The [[WindowManager]] and [[RenderPipelineManager]] are also contained in this class.

# Methods
## run
initializes the Application and calls mainloop()
### returns
void

## requestShutdown
sets the variable responsible for keeping track of application runstate to false, causing the application to shut down and call dispose()
### returns
void

## getWindowManager
gets the [[WindowManager]] class stored by the application
### returns
[[WindowManager]]
### see also
[[WindowManager]]
## getRenderPipelineManager
gets the [[RenderPipelineManager]] class stored by the application
### returns
[[RenderPipelineManager]]
### see also
[[RenderPipelineManager]]