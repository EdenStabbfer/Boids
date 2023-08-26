//
// Created by kufuk on 04.08.2023.
//

#ifndef BOID_H
#define BOID_H

#include "../Math/MathPlus.h"
#include "../Utils/Time.h"
#include "../Utils/Statistics.h"

class Boid
{
    friend class ModelSolver;
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

    bool operator==(const Boid& other) const;
    bool operator!=(const Boid& other) const;

private:
    sf::Vector2f m_position;
    sf::Vector2f m_velocity;
    sf::Vector2f m_desiredDirection;
    sf::Vector2f m_acceleration;

    float m_maxSpeed;

    size_t _id;

public:

    BoidStats stats;
};


#endif //BOID_H
