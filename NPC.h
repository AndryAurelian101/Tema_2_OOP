//
// Created by andre on 5/3/2023.
//

#ifndef OOP_NPC_H
#define OOP_NPC_H
#include <SFML/Graphics.hpp>


class NPC {
    std::string Name;
    int HP;
    float position_x;
    float position_y;
    sf::Sprite NPC_body;
    sf::Texture NPC_skin;
    int NPC_type;

public:
    NPC();
    int get_NPC_type() const;
    sf::Sprite get_NPC_body();
};


#endif //OOP_NPC_H
