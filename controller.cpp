#include "controller.h"
#include <map>

using namespace std;

Controller::Controller() {
    model = new Model(50, 50);
    view = new View("Game", 1024, 768);
}

Controller::~Controller() {
    delete model;
    delete view;
}
/**
References:
https://wiki.libsdl.org/SDL_PollEvent
https://wiki.libsdl.org/SDL_Event
*/
void Controller::loop() {
    SDL_Event e;
    unsigned int lastTime = 0, currentTime;
    std::map<SDL_Keycode, Direction> direction;
    direction[SDLK_UP] = UP;
    direction[SDLK_DOWN] = DOWN;
    direction[SDLK_LEFT] = LEFT;
    direction[SDLK_RIGHT] = RIGHT;
	direction[SDLK_ESCAPE] = ESCAPE;
	direction[SDLK_SPACE] = SPACE;
	direction[SDLK_RETURN2] = RETURN;
	State check = GAME;

	


    while(!model->gameOver())
	{
        currentTime = SDL_GetTicks();
        // Do stuff here to animate as necessary
        view->show(model);
		
        if (SDL_PollEvent(&e) != 0)
		{
            switch (e.type)
			{
				case SDL_QUIT:
					return;
				case SDL_KEYDOWN:
					if (check == GAME){
						switch(e.key.keysym.sym)
						{
							case SDLK_DOWN:
							case SDLK_UP:
							case SDLK_LEFT:
							case SDLK_RIGHT:
							case SDLK_ESCAPE:
							case SDLK_RETURN:
							case SDLK_SPACE:
							model->go(direction[e.key.keysym.sym]);
						}
						break;
					}
					else if(check == MENU)
					{
						switch(e.key.keysym.sym)
						{
							case SDLK_DOWN:
							case SDLK_UP:
							case SDLK_LEFT:
							case SDLK_RIGHT:
							case SDLK_ESCAPE:
							case SDLK_RETURN:
							case SDLK_SPACE:
								//call the move in menu stuff
								//temp
								break;
						}  
						break;
					}
			
				case SDL_MOUSEBUTTONDOWN: //SDL_GetMouseState
					break;
				default:
					break;
            }
          
        }
    
	}
    // TODO: show something nice?
    view->show(model);
    SDL_Delay(3000);

}
