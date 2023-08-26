//
// Created by kufuk on 04.08.2023.
//

#ifndef MATHPLUS_H
#define MATHPLUS_H

#include <SFML/Graphics.hpp>
#include <random>
#include <math.h>

float len(const sf::Vector2f& v);
float lenSq(const sf::Vector2f& v);

sf::Vector2f& norm(sf::Vector2f& v);
sf::Vector2f norm(const sf::Vector2f& v);

float dot(const sf::Vector2f& v1, const sf::Vector2f& v2);

float getAngleBetween(const sf::Vector2f& v1, const sf::Vector2f& v2);
float getAngleAbsolute(const sf::Vector2f& v);

sf::Vector2f getRandomVector();

// Operators
template<class T>
sf::Vector3<T> operator*(const sf::Vector3<T>& v1, const sf::Vector3<T>& v2)
{
    return {v1.x * v2.x, v1.y * v2.y, v1.z * v2.z};
}

template<class T>
sf::Vector2<T> operator*(const sf::Vector2<T>& v1, const sf::Vector2<T>& v2)
{
    return {v1.x * v2.x, v1.y * v2.y, v1.z * v2.z};
}

#endif //MATHPLUS_H
