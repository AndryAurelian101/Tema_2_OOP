//
// Created by andre on 3/28/2023.
//

#include "Player.h"
#include <string>

std::string Player::get_name() {
    return Name;
}

Player::Player() {
    HP = 100;
    coins = 5;
    damage = 30;
    position_x = 4420.0f;
    position_y = 480.0f;
    skin.loadFromFile("images/player.png");
    body.setTexture(skin);
    body.setPosition(sf::Vector2f(position_x, position_y));
    player_view.setCenter(sf::Vector2f(position_x, 360.f));
    player_view.setSize(sf::Vector2f(1280.f, 720.f));
    background_x = position_x - 640.0f;
    background_width = 8960.0f;
}

sf::View Player::get_view() {
    return player_view;
}

void Player::get_input() {
    // When the player press a key: move the character
    //Camera moves until the margin of the background (IF I CHANGE BACKGROUND, DO NOT FORGET TO CHANGE THE BACKGROUND_WIDTH PARAMETERS OF THE CAMERA!!!!)
    //Run
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && position_x > 6.0f)
    {
        body.move(-6.0f,0.0f);
        position_x -= 6.0f;
        if((player_view.getCenter().x - position_x > 507.0f) && background_x > 6.0f)
        {
            player_view.move(-6.0f,0.0f);
            background_x -= 6.0f;
        }

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && position_x < (background_width - 6 - 64))
    {
        body.move(6.0f,0.0f);
        position_x += 6.0f;
        if((position_x - player_view.getCenter().x  > 387.0f) && background_x < (background_width - 6.0f - 1280.0f))
        {
            player_view.move(6.0f,0.0f);
            background_x += 6.0f;
        }
    }
    //Walk
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && position_x > 3.0f)
    {
        body.move(-3.0f,0.0f);
        position_x -= 3.0f;
        if((player_view.getCenter().x - position_x > 507.0f) && background_x > 3.0f)
        {
            player_view.move(-3.0f,0.0f);
            background_x -= 3.0f;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && position_x < (background_width - 3.0f - 64.0f))
    {
        body.move(3.0f,0.0f);
        position_x += 3.0f;
        if((position_x - player_view.getCenter().x  > 387.0f) && background_x < (background_width - 3.0f - 1280.0f))
        {
            player_view.move(3.0f,0.0f);
            background_x += 3.0f;

        }
    }
    //Attack
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        std::cout<<"Left button is pressed\n";
    }
    //std::cout<<background_x<<" "<<player_view.getCenter().x<<" "<<position_x<<" "<<position_x - player_view.getCenter().x<<"\n";
}

sf::Sprite Player::get_body(){
    return body;
}

float Player::get_x() const {
    return position_x;
}
