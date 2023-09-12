//
// Created by kufuk on 04.08.2023.
//

#ifndef BOID_H
#define BOID_H

#include "IEntity.h"

#include "../Math/MathPlus.h"
#include "../Utils/Time.h"
#include "../Utils/Statistics.h"

class Boid : public IEntity
{
    friend class ModelSolver;
    friend class BoundariesSolver;
    friend class InteractionSolver;
    friend class Renderer;

public:
    Boid(sf::Vector2f pos, float maxSpeed);

    [[nodiscard]]
    const sf::Vector2f& getPosition() const;
    [[nodiscard]]
    const sf::Vector2f& getVelocity() const;
    [[nodiscard]]
    float               getMaxSpeed() const;

    void setPosition(const sf::Vector2f& pos);
    void setVelocity(const sf::Vector2f& vel);
    void setMaxSpeed(float speed);

    void move();

private:
    sf::Vector2f m_position;
    sf::Vector2f m_velocity;
    sf::Vector2f m_desiredDirection;
    sf::Vector2f m_acceleration;

    float m_maxSpeed;

public:

    BoidStats stats;
};


#endif //BOID_H
