#include <iostream>

#include <SFML/Graphics.hpp>

#include "../include/Solver/ModelSolver.h"
#include "../include/Render/Renderer.h"

#include "../include/Utils/Settings.h"


int main()
{
    float fpsSum{0}, avgFps{0};
    int boidSize{6};
    int minBoidSpeed{400}, maxBoidSpeed{800};
    int boidsPerClick{10};


    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(Settings::General::WindowWidth, Settings::General::WindowHeight),
                            "Boids",
                            sf::Style::Default,
                            settings);
    window.setFramerateLimit(Settings::General::FrameRateLimit);
    sf::Event event{};

    std::vector<Boid> boids;
    ModelSolver solver(boids);

    Renderer renderer(&window, boids, solver.stats);

    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(minBoidSpeed, maxBoidSpeed);

    int cnt{0};
    while (window.isOpen())
    {
        Time::update();

        fpsSum += 1/Time::getDt();
        if(cnt++ % 20 == 0)
        {
            avgFps = fpsSum / 20;
            fpsSum = 0;
        }
        window.setTitle("Fps: " + std::to_string((int)avgFps) + "    Objects: " + std::to_string(boids.size()));

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    for (int i{0}; i < boidsPerClick; i++)
                        boids.emplace_back(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y), dis(gen));
                }
            }
        }

        solver.update();
        renderer.render();

    }
    return 0;
}
