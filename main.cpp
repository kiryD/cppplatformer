#include <stdio.h>
#include <string.h>
#include <SDL2\SDL.h>
#include <vector>

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int movement_speed = 1; // Movement speed of the player
int jump_force = 55;

std::vector<SDL_Rect> platforms;

bool onFloor =  false;
bool quit = false;
SDL_Window* gWindow = NULL;

SDL_Renderer* renderer = NULL;
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

SDL_Rect r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;

struct Color{
    int r = 0;
    int g = 0;
    int b = 0;
    int a = 255;
};

Color bgcolor;
//Starts up SDL and creates window
bool init(){
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}
	else{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Platformer by kiryD :D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			return false;
		}
        renderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED);
        if( renderer == NULL){
            return false;
        }
		return true;
	}
}
void close(){	
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    //Quit SDL subsystems
    SDL_Quit();
}
void rectsetup(){
    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );

    // Clear window
    SDL_RenderClear( renderer );
    
    r1.x = 50;
    r1.y = 0;
    r1.w = 50;
    r1.h = 50;

    r2.x = 0;
    r2.y = 250;
    r2.w = 150;
    r2.h = 50;

    r3.x = 230;
    r3.y = 250;
    r3.w = 150;
    r3.h = 50;

    r4.x = 534;
    r4.y = 350;
    r4.w = 150;
    r4.h = 50;

    r5.x = 714;
    r5.y = 338;
    r5.w = 75;
    r5.h = 50;
    
    r6.x = 840;
    r6.y = 347;
    r6.w = 75;
    r6.h = 50;
    
    r7.x = 1012;
    r7.y = 362;
    r7.w = 140;
    r7.h = 50;
    
    r8.x = 1200;
    r8.y = 476;
    r8.w = 75;
    r8.h = 50;

    r9.x = 1126;
    r9.y = 499;
    r9.w = 75;
    r9.h = 50;

    r10.x = 992;
    r10.y = 499;
    r10.w = 140;
    r10.h = 50;

    r11.x = 830;
    r11.y = 560;
    r11.w = 140;
    r11.h = 50;

    r12.x = 320;
    r12.y = 600;
    r12.w = 140;
    r12.h = 50;

    r13.x = 490;
    r13.y = 580;
    r13.w = 140;
    r13.h = 50;

    r14.x = 580;
    r14.y = 580;
    r14.w = 140;
    r14.h = 50;

    r15.x = 0;
    r15.y = 400;
    r15.w = 1200;
    r15.h = 0;


    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

    // Render rect
    SDL_RenderFillRect( renderer, &r1 );

    platforms.push_back(r2); platforms.push_back(r3); platforms.push_back(r4); platforms.push_back(r5);
    // Render the rect to the screen
    SDL_RenderPresent(renderer);
}
void resetscreen(){
    SDL_SetRenderDrawColor( renderer, bgcolor.r, bgcolor.g, bgcolor.b, bgcolor.a );

    SDL_RenderClear( renderer );
}
void drawcube(){
    SDL_SetRenderDrawColor( renderer, 0, 0, 200, 255 );
    // Render rect
    SDL_RenderFillRect( renderer, &r1 );

    SDL_SetRenderDrawColor( renderer, 0, 105, 0, 255 );
    r2 = platforms[0]; r3 = platforms[1]; r4 = platforms[2]; r5 = platforms[3];
    // Render rect
    SDL_RenderFillRect( renderer, &r2 );
    SDL_RenderFillRect( renderer, &r3 );
    SDL_RenderFillRect( renderer, &r4 );
    SDL_RenderFillRect( renderer, &r5 );
    SDL_RenderFillRect( renderer, &r6 );
    SDL_RenderFillRect( renderer, &r7 );
    SDL_RenderFillRect( renderer, &r8 );
    SDL_RenderFillRect( renderer, &r9 );
    SDL_RenderFillRect( renderer, &r10 );
    SDL_RenderFillRect( renderer, &r11 );
    SDL_RenderFillRect( renderer, &r12 );
    SDL_RenderFillRect( renderer, &r13 );
    SDL_RenderFillRect( renderer, &r14 );

    // Render the rect to the screen
    SDL_RenderPresent(renderer);
}
bool checkCollision( SDL_Rect a, SDL_Rect b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;
    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}
void physics(){
    r1.y += 1;
    if (checkCollision(r1,r2) or checkCollision(r1,r3) or checkCollision(r1,r4) or checkCollision(r1,r5) or checkCollision(r1,r6) or checkCollision(r1,r7) or checkCollision(r1,r15) or checkCollision(r1,r9) or checkCollision(r1,r10) or checkCollision(r1,r11) or checkCollision(r1,r12) or checkCollision(r1,r13) or checkCollision(r1,r14) or checkCollision(r1,r8)){
        r1.y -= 1;
        onFloor = true;
    }
    else{
        onFloor = false;
    }
}
void mainloop(){
    resetscreen();
    physics();
    drawcube();
    SDL_Delay(10);
}

int main( int argc, char* args[] )
{
    bgcolor.r = 125;
    bgcolor.g = 125;
    bgcolor.b = 125;
	//Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
        return 1;
    }
    rectsetup();
    SDL_Event e;
    while( quit == false ){ 
        while( SDL_PollEvent( &e ) ){ 
            if (e.type == SDL_QUIT ) {quit = true; break;}}
        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_D]){
            r1.x += movement_speed;
            if (checkCollision(r1,r2) or checkCollision(r1,r3) or checkCollision(r1,r4) or checkCollision(r1,r5) or checkCollision(r1,r6) or checkCollision(r1,r7) or checkCollision(r1,r8) or checkCollision(r1,r9) or checkCollision(r1,r10) or checkCollision(r1,r11) or checkCollision(r1,r12) or checkCollision(r1,r13) or checkCollision(r1,r14)){
                r1.x -= movement_speed;
            }
        }
        if (keystate[SDL_SCANCODE_SPACE] and onFloor){
            r1.y -= jump_force;
        }
        if (keystate[SDL_SCANCODE_A]){
            r1.x -= movement_speed;
            if (checkCollision(r1,r2) or checkCollision(r1,r3) or checkCollision(r1,r4) or checkCollision(r1,r5) or checkCollision(r1,r6) or checkCollision(r1,r7) or checkCollision(r1,r8) or checkCollision(r1,r9) or checkCollision(r1,r10) or checkCollision(r1,r11) or checkCollision(r1,r12) or checkCollision(r1,r13) or checkCollision(r1,r14)){
                r1.x += movement_speed;
            }
        }
        if (keystate[SDL_SCANCODE_R]){
            r1.x = 50;
            r1.y = 0;
        }
        mainloop();
    }
    //Free resources and close SDL
    close();
	return 0;
}