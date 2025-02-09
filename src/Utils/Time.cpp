//
// Created by kufuk on 05.08.2023.
//

#include "Utils/Time.h"

const float &Time::getDt() {
    return m_deltaTime;
}

sf::Clock Time::m_clock = sf::Clock();
float Time::m_deltaTime = 0.0f;

void Time::update() {
    m_deltaTime = m_clock.restart().asSeconds();
}
