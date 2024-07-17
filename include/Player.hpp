#ifndef ARNOLD_PLAYER_H
#define ARNOLD_PLAYER_H

#pragma once

#include <SDL2/SDL.h>
#include <thread>
#include <vector>
#include <map>

#include "Utils.hpp"
#include "Entity.hpp"

using namespace Utils::Geometry;

class Player final : public Entity
{
public:
    Player(const Vector2D coordinates, Game *game) : Entity(coordinates, game, 40)
    {
        dimensions = {20, 20};
    }

    void registerMovementKey(SDL_Keycode key, bool isHeld);

    void handleEvents(const SDL_Event &sdlEvent);

    void render(SDL_Renderer *renderer) override;

    void update(double deltaTime) override;

private:
    const int healthCapacity = 40;

    const float movementSpeed = 150.0f;

    std::vector<SDL_Keycode> currentHeldKeys;

    std::thread uziThread;

    Vector2D mouseCoords{};

    bool mouseHeld = false;
    std::map<SDL_Keycode, bool> movementKeys = {
        {SDLK_w, false},
        {SDLK_a, false},
        {SDLK_s, false},
        {SDLK_d, false}};
};

#endif // ARNOLD_PLAYER_H
