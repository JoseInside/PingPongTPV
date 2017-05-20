#include <cmath>
#include <random>
#include "PingPongPhysics.h"

PingPongPhysics::PingPongPhysics(GameObject* left_paddle,
		GameObject* right_paddle) :
		left_paddle_(left_paddle), right_paddle_(right_paddle), hits_(
				0), speed_(0) {
}

PingPongPhysics::~PingPongPhysics() {
}

void PingPongPhysics::init(GameObject* o) {
	
}

void PingPongPhysics::update(GameObject* o) {

	Vector2D<int> nextPos = o->getPosition() + o->getDirection();
	bool collisionHappened = false;

	if (o->getPosition().getX() < left_paddle_->getWidth() &&
		o->getPosition().getX() > left_paddle_->getPosition().getX() &&
		o->getPosition().getY() < left_paddle_->getHeight() &&
		o->getPosition().getY() > left_paddle_->getPosition().getY()) {
	
		//Collision happened
		++hits_;
		if (hits_ == 5) {
			hits_ = 0;
			speed_++;
		}
		for (auto i : observadores_) {
			i->onCollision(o, left_paddle_);
		}
		int sign = o->getDirection().getX() < 0 ? 1 : -1;
		int rel_y = (o->getPosition().getY() - left_paddle_->getPosition().getY() + o->getHeight());
		float angle = (2.14f * rel_y - 75.0f);
		int dx = sign * speed_ * std::cos(angle * M_PI / 180.0f);
		int dy = speed_ * std::sin(angle * M_PI / 180.0f);

		o->setDirection(dx, dy);
		
	}
	else if (o->getPosition().getX() < right_paddle_->getWidth() &&
		o->getPosition().getX() > right_paddle_->getPosition().getX() &&
		o->getPosition().getY() < right_paddle_->getHeight() &&
		o->getPosition().getY() > right_paddle_->getPosition().getY()) {
		
		//Collision happened
		++hits_;
		if (hits_ == 5) {
			hits_ = 0;
			speed_++;
		}
		for (auto i : observadores_) {
			i->onCollision(o, right_paddle_);
		}

		int sign = o->getDirection().getX() < 0 ? 1 : -1;
		int rel_y = (o->getPosition().getY() - right_paddle_->getPosition().getY() + o->getHeight());
		float angle = (2.14f * rel_y - 75.0f);
		int dx = sign * speed_ * std::cos(angle * M_PI / 180.0f);
		int dy = speed_ * std::sin(angle * M_PI / 180.0f);

		o->setDirection(dx, dy);
	}
}


void PingPongPhysics::resgisterBallObserver(BallObserver* o) {
	observadores_.push_back(o);
}


void PingPongPhysics::onGameStart() {
	hits_ = 0;
	speed_ = 8;
	
}

void PingPongPhysics::onGameOver() {
}

void PingPongPhysics::onRoundStart() {
	hits_ = 0;
	speed_ = 8;

	int direction = 1 - 2 * (rand() % 2);
	int angle = 60 - (rand() % 121);
	int dx = direction * speed_ * std::cos(angle * M_PI / 180.0f);
	int dy = speed_ * std::sin(angle * M_PI / 180.0f);
//	o->setDirection(dx, dy);


}

void PingPongPhysics::onRoundOver() {
}

