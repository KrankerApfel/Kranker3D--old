#pragma once 

namespace Kranker3D
{
	class IContext {


	public:
	   virtual void init() = 0;
	   virtual void preRender() = 0;
	   virtual void render() = 0;
	   virtual void postRender() = 0;
	   virtual void terminate() = 0;
	};

}