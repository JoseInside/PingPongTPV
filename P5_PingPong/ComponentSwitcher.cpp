#include "ComponentSwitcher.h"

ComponentSwitcher::ComponentSwitcher(SDLGame* game, GameComponent* actor,
		SDL_Keycode ctrlKey) :
		GameObject(game), actor_(actor), ctrlKey_(ctrlKey) {
}

ComponentSwitcher::~ComponentSwitcher() {
}

void ComponentSwitcher::update() {
}

void ComponentSwitcher::handleInput(const SDL_Event& event) {
}

void ComponentSwitcher::addMode(InputComponent* inputComp,
		PhysicsComponent* physicsComp, RenderComponent* renderComp,
		RenderComponent* modeRendered) {
	mode n;
	n = { inputComp, physicsComp, renderComp, modeRendered };
//	mode m= new mode(inputComp, physicsComp, renderComp, modeRendered);
	
	modos.push_back(n);
}

void ComponentSwitcher::setMode(int mode) {
}

void ComponentSwitcher::switchToNext() {
}

void ComponentSwitcher::render() {
}
