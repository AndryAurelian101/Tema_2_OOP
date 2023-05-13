//
// Created by andre on 4/10/2023.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include "Player.h"
#include "NPC.h"


class Game {
    sf::RenderWindow window;
    Player human;
    sf::Sprite background;
    sf::Texture background_texture;
    sf::Sprite Sky;
    sf::Sprite Night;
    sf::Texture Night_sky;
    sf::Texture sky_texture;
    NPC folk;
    const float day_duration = 6.0f;
    time_t start;
    time_t duration;
    time_t end;
    int days;
    int monster_bank;

public:
    Game();
    void run();
    void elapsed_time();
};


#endif //OOP_GAME_H
