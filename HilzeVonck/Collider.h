#include <iostream>
#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& body);
	~Collider(); //destructor

	void Move(float dx, float dy) {body.move(dx, dy);}

	bool CheckCollision(Collider& other, float push);

	//constructors

	Collider::Collider(sf::RectangleShape& body) :
		body(body)

	Collider::~Collider();

	bool Collider::CheckCollision(Collider& other, float push)
	{
		sf::Vector2f otherPosition = other.GetPosition();
		sf::Vector2f otherHalfSize = other.GetHalfSize();
		sf::Vector2f thisPosition = GetPosition();
		sf::Vector2f thisHalfSize = GetHalfSize();

		float deltaX = otherPosition.x - thisPosition.x;
		float deltaY = otherPosition.y - thisPosition.y;
		float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
		float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

		if (intersectX < 0.0f && intersectY < 0.0f)
		{
			push = std::min(std::max(push, 0.0f), 1.0f); //"clamping" between two values

			if(intersectX > intersectY)
			{
				if(deltaX > 0.0f)
				{
					Move(intersectX * (1.0f - push), 0.0f);
					other.Move(-intersectX * push, 0.0f);
				}
				else
				{
					Move(-intersectX * (1.0f - push), 0.0f);
					other.Move(intersectX * )
				}
			}
			else
			{
				if(deltaY > 0.0f)
				{
					Move(intersectY * (1.0f - push), 0.0f);
					other.Move(-intersectY * push, 0.0f);
				}
				else
				{
					Move(-intersectY * (1.0f - push), 0.0f);
					other.Move(intersectY * )
				}
			}

			return true;
		}

		return false;
	}
	//constructors above 

	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

private:
	sf::RectangleShape& body;
};