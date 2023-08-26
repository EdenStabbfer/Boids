//
// Created by kufuk on 04.08.2023.
//

#include "../../include/Entities/Boid.h"

size_t generateId()
{
    static size_t counter{0};
    return counter++;
}

Boid::Boid(sf::Vector2f pos, float maxSpeed) : m_position(pos), m_maxSpeed(maxSpeed)
{
    m_velocity = getRandomVector();
    m_desiredDirection = m_velocity;
    m_velocity *= maxSpeed;
    m_acceleration = {0, 0};
    _id = generateId();
}

const sf::Vector2f &Boid::getPosition() const
{
    return m_position;
}

const sf::Vector2f &Boid::getVelocity() const
{
    return m_velocity;
}

float Boid::getMaxSpeed() const
{
    return m_maxSpeed;
}

void Boid::setPosition(const sf::Vector2f &pos)
{
    m_position = pos;
}

void Boid::setVelocity(const sf::Vector2f &vel)
{
    m_velocity = vel;
}

void Boid::setMaxSpeed(float speed)
{
    m_maxSpeed = (speed > 0.0f) ? speed : 1;
}

void Boid::move()
{
    m_velocity += m_acceleration * Time::getDt();
    m_velocity = norm(m_velocity) * m_maxSpeed;
    m_position += m_velocity * Time::getDt();

    m_acceleration = {0, 0};
}

bool Boid::operator==(const Boid &other) const
{
    return this->_id == other._id;
}

bool Boid::operator!=(const Boid &other) const
{
    return this->_id != other._id;
}
