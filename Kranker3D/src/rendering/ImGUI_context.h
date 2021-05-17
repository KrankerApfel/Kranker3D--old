#pragma once 
#include  <mutex>
#include "IContext.h"
#include "../ui/window.h"

// /!\  this singleton is not thread safe !

namespace Kranker3D
{
	class ImGUI_Context : IContext
	{
	private:
		static ImGUI_Context* instance;
		Window* _window;
		static std::mutex _mutex;

	public:
		ImGUI_Context(Window* window) { _window = window; };
		~ImGUI_Context() {};
		ImGUI_Context(ImGUI_Context& other) = delete; // not cloneable
		void operator=(const ImGUI_Context&) = delete; // not assigneable
		static ImGUI_Context* getInstance(Window* window);

		bool isOpen();

		void init() override;
		void preRender() override;
		void render() override;
		void postRender() override;
		void terminate() override;

	};
}