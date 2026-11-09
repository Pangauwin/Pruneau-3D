#include "framebuffer.h"

bool init_framebuffer(Framebuffer& _fb, unsigned int width, unsigned int height)
{
	_fb.width = width;
	_fb.height = height;

	_fb.size = width * height;

	_fb.buffer = (uint32_t*)malloc(sizeof(uint32_t) * _fb.size);

	return _fb.buffer != nullptr;
}

void unload_framebuffer(Framebuffer& _fb)
{
	delete _fb.buffer;
}