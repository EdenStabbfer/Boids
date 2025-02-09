//
// Created by kufuk on 05.08.2023.
//

#ifndef TIME_H
#define TIME_H

#include <SFML/System.hpp>


class Time {
public:
    Time() = default;

    static const float &getDt();

    static void update();

private:
    static sf::Clock m_clock;

    static float m_deltaTime;

};


#endif //TIME_H
