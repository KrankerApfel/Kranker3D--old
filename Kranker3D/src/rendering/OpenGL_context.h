#pragma once 
#include  <mutex>
#include "IContext.h"
#include "../ui/window.h"

// /!\  this singleton is not thread safe !

namespace Kranker3D
{
	class OpenGL_Context : IContext
	{
	private:
		static OpenGL_Context* _instance;
		Window* _window;
	//	static std::mutex _mutex;

	public:
		OpenGL_Context(Window* window) { _window = window;};
		~OpenGL_Context() {};
		OpenGL_Context(OpenGL_Context& other) = delete; // not cloneable
		void operator=(const OpenGL_Context&) = delete; // not assigneable
		static OpenGL_Context* getInstance( Window* window) {
			//std::lock_guard<std::mutex> lock(_mutex);
			if (_instance == nullptr)
			{
				_instance = new OpenGL_Context(window);
			}
			return _instance;
		};

		bool isOpen();

		void init() override;
		void preRender() override;
		void render() override;
		void postRender() override;
		void terminate() override;

	};
}