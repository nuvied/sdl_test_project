#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

#define GLM_ENABLE_EXPERIMENTAL

#include <iostream>

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))




int main(int argc, char* argv[])
{
    int window_width = 640;
    int window_height = 320;

    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window* pWindow = SDL_CreateWindow("sdl3 window", window_width, window_height, SDL_WINDOW_RESIZABLE);
    //SDL_Surface* pSurf = SDL_CreateSurface(300, 300, SDL_PIXELFORMAT_RGBA8888);
    //SDL_ClearSurface(pSurf, 0.4f, 1.0f, 0.0f, 1.0f);
    SDL_Renderer* renderer = SDL_CreateRenderer(pWindow, "");
    

    
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, window_width, window_height);
    
    //SDL_FRect src_rect = {0,0,300,200};
    
    SDL_FRect dst_rect = {0,0,640,320};
    
    
    
    
    int current_width;
    int current_height;
    
    SDL_Event e;
    SDL_zero(e);
    
    while (true) {
        
        if(SDL_PollEvent(&e))
        {
            if(e.type == SDL_EVENT_QUIT)
                break;
        }
        
        //float ar = window_width / window_height;
        
        
        

        SDL_GetWindowSize(pWindow, &current_width, &current_height);
        float scale = MIN((float)current_width / (float)window_width, (float)current_height / (float)window_height);

                       
                       
        dst_rect.x = (float)(current_width - (float)(window_width * scale)) * 0.5f;
        dst_rect.y = (float)(current_height - (float)(window_height * scale)) * 0.5f;
        dst_rect.w = float(window_width * scale);
        dst_rect.h = float(window_height * scale);
        
        
        
        //SDL_log(current_width);
       // std::cout << current_width+ " : "+ current_height << std::endl;
        SDL_SetRenderTarget(renderer, texture);
        
        SDL_SetRenderDrawColor(renderer, 50, 50, 100, 255);
        
        SDL_RenderClear(renderer);
        
        SDL_SetRenderTarget(renderer, NULL);
        SDL_RenderTexture(renderer, texture,NULL, &dst_rect);
        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyWindow(pWindow);
    SDL_DestroyTexture(texture);
   // sdl_destroyre
    //SDL_DestroySurface(pSurf);
    
    return 0;
}
