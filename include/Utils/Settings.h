//
// Created by kufuk on 19.08.2023.
//

#ifndef SETTINGS_H
#define SETTINGS_H


class Settings {
public:
    // Window and render parameters
    struct General {
        static const int WindowWidth;
        static const int WindowHeight;
        static const int FrameRateLimit;
    };

    // Boid2Boid and Boid2World interaction parameters
    struct Model {
        static float WindowMargin;
        static float TurnFactor;
        static float AvoidFactor;
        static float MathingFactor;
        static float CenteringFactor;
        static float ProtectedRange;
        static float VisualRange;
    };

    // Single Boid behavior parameters
    struct Boid {
        static int   Size;
        static float SteerStrength;
        static float WonderStrength;
    };
};


#endif //SETTINGS_H
