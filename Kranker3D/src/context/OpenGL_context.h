#pragma once 
#include "IRenderingContext.h"
#include "window.h"


namespace Kranker3D
{
	class OpenGL_Context : IRenderingContext
	{
	private:
		Window* _window;

	public:
		OpenGL_Context(Window* window) { _window = window;};
		~OpenGL_Context() {};

		OpenGL_Context(OpenGL_Context& other) = delete; 
		OpenGL_Context& operator=(const OpenGL_Context&) = delete; 
		OpenGL_Context(OpenGL_Context&& other) = delete; 
		OpenGL_Context& operator=(const OpenGL_Context&&) = delete; 

		static OpenGL_Context& getInstance(Window* window);

		bool isOpen();

		void init() override;
		void preRender() override;
		void render() override;
		void postRender() override;
		void terminate() override;

	};
}