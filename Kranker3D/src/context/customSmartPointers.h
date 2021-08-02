struct GLFWwindow_deleter
{
	void operator()(GLFWwindow* ptr)
	{
		glfwDestroyWindow(ptr);
	}
};

typedef std::unique_ptr<GLFWwindow, GLFWwindow_deleter> unique_GLFWwindow_ptr;
