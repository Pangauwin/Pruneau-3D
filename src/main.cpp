#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <cstdint>
#include <vector>

#include "framebuffer/framebuffer.h"

int main(int, char**) {
    constexpr int W = 640, H = 360;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    if (!SDL_CreateWindowAndRenderer("Pruneau-3D", W * 2, H * 2, 0, &window, &renderer)) {
        SDL_Log("Window creation failed: %s", SDL_GetError());
        return 1;
    }

    SDL_Texture* tex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING, W, H);
    SDL_SetTextureScaleMode(tex, SDL_SCALEMODE_NEAREST);

    Framebuffer framebuffer;
    init_framebuffer(framebuffer, W, H);

    bool running = true;
    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e))
            if (e.type == SDL_EVENT_QUIT) running = false;

        for (int y = 0; y < H; ++y)
            for (int x = 0; x < W; ++x)
                framebuffer.buffer[y * W + x] = 0xFF000000u | (x * 255 / W) << 16 | (y * 255 / H) << 8;

        SDL_UpdateTexture(tex, nullptr, framebuffer.buffer, W * sizeof(uint32_t));
        SDL_RenderClear(renderer);
        SDL_RenderTexture(renderer, tex, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }

    unload_framebuffer(framebuffer);

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}