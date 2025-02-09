//
// Created by kufuk on 04.08.2023.
//

#include "Math/MathPlus.h"

float lenSq(const sf::Vector2f &v) {
    return v.x * v.x + v.y * v.y;
}

float len(const sf::Vector2f &v) {
    return sqrt(lenSq(v));
}

float lenSq(const sf::Vector3f &v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

float len(const sf::Vector3f &v) {
    return sqrt(lenSq(v));
}

sf::Vector2f &norm(sf::Vector2f &v) {
    v /= static_cast<float>(len(v));
    return v;
}

sf::Vector2f norm(const sf::Vector2f &v) {
    sf::Vector2f nv = v / static_cast<float>(len(v));
    return nv;
}

sf::Vector3f &norm(sf::Vector3f &v) {
    v /= static_cast<float>(len(v));
    return v;
}

sf::Vector3f norm(const sf::Vector3f &v) {
    sf::Vector3f nv = v / static_cast<float>(len(v));
    return nv;
}

sf::Vector2f getRandomVector() {
    static std::random_device               rd;
    static std::mt19937                     gen(rd());
    static std::uniform_real_distribution<> dis(-1.0, 1.0);

    return norm(sf::Vector2f(dis(gen), dis(gen)));
}

float dot(const sf::Vector2f &v1, const sf::Vector2f &v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

float getAngleBetween(const sf::Vector2f &v1, const sf::Vector2f &v2) {
    return acos(dot(v1, v2) / len(v1) / len(v2)) * 180.0f / std::numbers::pi;
}

float getAngleAbsolute(const sf::Vector2f &v) {
    float angle = acos(v.x / len(v)) * 180 / std::numbers::pi;
    return (v.y > 0.0f) ? angle : -angle;
}