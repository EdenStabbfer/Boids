//
// Created by kufuk on 19.08.2023.
//

#include "../../include/Utils/Settings.h"


// General
int const Settings::General::WindowWidth =      2240;
int const Settings::General::WindowHeight =     1360;
int const Settings::General::FrameRateLimit =   60;

// Model
float Settings::Model::WindowMargin =       200.0;
float Settings::Model::TurnFactor =         50.0;
float Settings::Model::AvoidFactor =        40.0;
float Settings::Model::MathingFactor =      10.0;
float Settings::Model::CenteringFactor =    70.0;
float Settings::Model::ProtectedRange =     40;
float Settings::Model::VisualRange =        70;

// Boid
int Settings::Boid::Size =              6;
float Settings::Boid::SteerStrength =   120;
float Settings::Boid::WonderStrength =  0.6;
