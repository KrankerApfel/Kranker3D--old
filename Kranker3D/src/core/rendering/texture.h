#pragma once
#include <cstdint>
#include <iostream>
#include "../../stdafx.h"

namespace Kranker3D {
	enum class Extension {
		PNG, JPG, BMP, TGA
	};
	class Texture {
	private:
		unsigned char* _data = NULL; // table of int sort by order r ,g ,b ,a (according to number of channels)
		std::string  _filePath;
		GLuint _texture_id;
		size_t _size = 0; // data table size
		int _width;
		int _height;
		int _channels;

		void bindTexture();

	public:
	//	Texture(const int width, const int height, const int channels);
		Texture(std::string  filename);
		void use();
	//	~Texture();		
	};
}