//
// Created by andre on 4/10/2023.
//

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>


Game::Game()  {
    window.create(sf::VideoMode(1280, 720), "What Remains");
    background_texture.loadFromFile("images/background_trees.png");
    background.setTexture(background_texture);
    start = 0;
    end = 0;
    time(&start);
    sky_texture.loadFromFile("images/day_sky.png");
    Sky.setTexture(sky_texture);
    Night_sky.loadFromFile("images/night.png");
    Night.setTexture(Night_sky);
    Night.setColor(sf::Color(14, 10, 45));
    days = 1;
    monster_bank = 100;
    duration = static_cast<time_t>(day_duration/2);
}


void Game::elapsed_time(){
    time(&end);
    std::cout << duration<<"\n";
    std::cout<<"Day "<<days<<"\n";
    //std::cout<<"Spawn bank "<<monster_bank<<"\n";
    //Duration of a day in seconds (default 600,0f)
    float time_delayer = std::abs((day_duration - static_cast<float>(duration))/day_duration);
    //day time from 0 to 600(a day has 10 minutes)
    if(duration >=0 && duration < static_cast<int>(day_duration))
    {
        std::cout<<"A new Day!\n";
        Night.setColor(sf::Color(14, 10, 45,128*time_delayer));
        std::cout<<time_delayer<<"\n";

    }
    duration = end - start;
    //night time from 600 to 1200(a night has 10 minutes)
    if(duration >= static_cast<int>(day_duration) && duration <= static_cast<int>(day_duration*2))
    {
        std::cout<<"Night is coming!\n";
        Night.setColor(sf::Color(14, 10, 45,128*time_delayer));
    }
    if(duration > static_cast<int>(day_duration*2))
    {
        time(&start);
        days++;
        monster_bank = 100 * days;
    }
}


void Game::run() {
    while (window.isOpen()) {
        sf::Event event{};
        window.setFramerateLimit(60);
        human.get_view().setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
        window.setView(human.get_view());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        human.get_input();
        elapsed_time();
        //std::cout<<folk.get_NPC_type();
        window.clear(sf::Color::White);
        window.draw(Sky);
        window.draw(background);
        window.draw(folk.get_NPC_body());
        window.draw(human.get_body());
        window.draw(Night);
        //GUI
        window.display();
    }
}
