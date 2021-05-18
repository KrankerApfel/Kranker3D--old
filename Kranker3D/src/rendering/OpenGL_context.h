#pragma once 
#include  <mutex>
#include "IContext.h"
#include "window.h"

// /!\  this singleton is not thread safe !

namespace Kranker3D
{
	class OpenGL_Context : IContext
	{
	private:
		static OpenGL_Context* instance;
		Window* _window;
		static std::mutex _mutex;

	public:
		OpenGL_Context(Window* window) { _window = window;};
		~OpenGL_Context() {};
		OpenGL_Context(OpenGL_Context& other) = delete; // not cloneable
		void operator=(const OpenGL_Context&) = delete; // not assigneable
		static OpenGL_Context* getInstance(Window* window);

		bool isOpen();

		void init() override;
		void preRender() override;
		void render() override;
		void postRender() override;
		void terminate() override;

	};
}