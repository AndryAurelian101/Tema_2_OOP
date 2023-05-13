//
// Created by andre on 3/28/2023.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Player {
    std::string Name;
    int HP;
    float position_x;
    float position_y;
    sf::Sprite body;
    sf::Texture skin;
    sf::View player_view;
    float background_x;
    float background_width;
    int coins;
    int damage;

public:
    Player();
    std::string get_name();
    void get_input();
    sf::Sprite get_body();
    float get_x() const;
    sf::View get_view();
};


#endif //OOP_PLAYER_H
