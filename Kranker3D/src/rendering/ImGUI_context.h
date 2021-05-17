//#pragma once 
//#include "IContext.h"
//#include "../ui/window.h"
//
//// /!\ Make sure this singleton is thread safe !
//
//namespace Kranker3D
//{
//	class ImGUI_Context : IContext
//	{
//	private:
//		static Context* _instance;
//		Window* _window;
//		static std::mutex _mutex;
//
//	public:
//		ImGUI_Context(const Window& window) { _window = window; };
//		~ImGUI_Context() {};
//		ImGUI_Context(Context& other) = delete; // not cloneable
//		void operator=(const ImGUI_Context&) = delete; // not assigneable
//		static ImGUI_Context* getInstance(const Window& window);
//	};
//}