//
// Created by andre on 5/3/2023.
//

#include <iostream>
#include <ctime>
#include "NPC.h"

NPC::NPC() {
    HP = 100;
    srand(time(nullptr));
    NPC_type = rand()%2;
    position_x = 4480.0f;
    position_y = 480.0f;
    if(NPC_type == 1)
        NPC_skin.loadFromFile("images/male_NPC.png");
    else
        NPC_skin.loadFromFile("images/female_NPC.png");
    NPC_body.setTexture(NPC_skin);
    NPC_body.setPosition(sf::Vector2f(position_x, position_y));
}

int NPC::get_NPC_type() const{
    return NPC_type;
}

sf::Sprite NPC::get_NPC_body() {
    return NPC_body;
}