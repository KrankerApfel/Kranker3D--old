#pragma once 
#include "IRenderingContext.h"
#include "window.h"

namespace Kranker3D
{
	class ImGUI_Context : IRenderingContext
	{
	private:
		std::shared_ptr<Window> _window;

	public:
		ImGUI_Context(std::shared_ptr<Window> window);
		~ImGUI_Context() {};

		// not cloneable, assigneable nor moveable
		ImGUI_Context(ImGUI_Context& other) = delete; 
		ImGUI_Context& operator=(const ImGUI_Context&) = delete; 
		ImGUI_Context(ImGUI_Context&& other) = delete; 
		ImGUI_Context& operator=( ImGUI_Context&&) = delete; 

		static ImGUI_Context& getInstance(std::shared_ptr<Window> window);
 
		void init() override;
		void preRender() override;
		void render() override;
		void postRender() override;
		void terminate() override;

	};
}