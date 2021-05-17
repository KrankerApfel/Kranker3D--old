#pragma once 
#include "IContext.h"
#include "../ui/window.h"

// /!\ Make sure this singleton is thread safe !

namespace Kranker3D
{
	class OpenGL_Context : IContext
	{
	private:
		static OpenGL_Context* _instance;
		Window* _window;
		static std::mutex _mutex;

	public:
		OpenGL_Context(Window* const window) { _window = window;};
		~OpenGL_Context() {};
		OpenGL_Context(OpenGL_Context& other) = delete; // not cloneable
		void operator=(const OpenGL_Context&) = delete; // not assigneable


		bool isOpen();

		void init() override;
		void preRender() override;
		void render() override;
		void postRender() override;
		void terminate() override;

	};
}