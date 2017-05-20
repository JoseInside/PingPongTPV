#include "PaddleAIPhysics.h"


PaddleAIPhysics::PaddleAIPhysics(GameObject* ball) :
		ball_(ball) {
}

PaddleAIPhysics::~PaddleAIPhysics() {
}

void PaddleAIPhysics::init(GameObject* paddle) {
	paddle->setDirectionY(0);
}

void PaddleAIPhysics::update(GameObject* paddle) {

	Vector2D<int> nextPos = paddle->getPosition() + paddle->getDirection();
	int y_pred;
	
	if (ball_->getPosition().getX() < ball_->getGame()->getWindowWidth() / 2) {
		//paddle->setPositionY(paddle->getGame()->getWindowHeight() / 2);
		if (paddle->getPosition().getY() == (paddle->getGame()->getWindowHeight() - paddle->getHeight()) / 2) {
			paddle->setDirectionY(0);
		}
		else if (paddle->getPosition().getY() > (paddle->getGame()->getWindowHeight() - paddle->getHeight()) / 2) {
			paddle->setDirectionY(-1);
		}
		else { paddle->setDirectionY(1); };
		
	}
	else if (ball_->getPosition().getX() > ball_->getGame()->getWindowWidth() / 2) {
		y_pred = ball_->getPosition().getY();
		
		if (paddle->getPosition().getY() > y_pred) {
			paddle->setDirectionY(-1 * 4);
		}
		else { paddle->setDirectionY(4); };
		//paddle->setDirectionY(y_pred);
	}
	
	paddle->setPosition(nextPos);


/*	if (ball_->getDirection() != paddle->getDirection())
		paddle->setPosition(paddle->getPosition().getX(), paddle->setDirectionY(height));
	else {

	}*/

}

