#pragma once

#include <cstdint>
#include <vector>

typedef struct Framebuffer {
	unsigned int width = 0;
	unsigned int height = 0;
	unsigned int size = 0;
	uint32_t* buffer = nullptr;
} Framebuffer;

bool init_framebuffer(Framebuffer& _fb, unsigned int width, unsigned int height);

void unload_framebuffer(Framebuffer& _fb);