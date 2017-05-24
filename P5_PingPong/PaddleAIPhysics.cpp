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
	
	if (paddle->getPosition().getX() < paddle->getGame()->getWindowWidth() / 2) {
		//LEFT PADDLE

		if (ball_->getPosition().getX() < ball_->getGame()->getWindowWidth() / 2) {
			y_pred = ball_->getPosition().getY();

			if (paddle->getPosition().getY() > y_pred) {
				paddle->setDirectionY(-1 * 4);
			}
			else { paddle->setDirectionY(4); };
		}
		else if (ball_->getPosition().getX() > ball_->getGame()->getWindowWidth() / 2) {

			if (paddle->getPosition().getY() == (paddle->getGame()->getWindowHeight() - paddle->getHeight()) / 2) {
				paddle->setDirectionY(0);
			}
			else if (paddle->getPosition().getY() > (paddle->getGame()->getWindowHeight() - paddle->getHeight()) / 2) {
				paddle->setDirectionY(-1);
			}
			else { paddle->setDirectionY(1); };
		}
	}
	else { //RIGHT PADDLE
		
		if (ball_->getPosition().getX() < ball_->getGame()->getWindowWidth() / 2) {
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
				paddle->setDirectionY(-1 * 8);
			}
			else { paddle->setDirectionY(8); };
		}
	}
	paddle->setPosition(nextPos);
}

