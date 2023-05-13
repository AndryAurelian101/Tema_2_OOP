//
// Created by andre on 5/9/2023.
//

#ifndef OOP_MONSTER_H
#define OOP_MONSTER_H
#include <SFML/Graphics.hpp>


class Monster {
    int HP;
    int cost;
    int damage;
    float position_x;
    float position_y;
    sf::Sprite monster_body;
    sf::Texture monster_skin;

public:
    Monster();
};


#endif //OOP_MONSTER_H
