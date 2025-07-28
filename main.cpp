// #include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Windows.h"
using namespace std;

int player1score = 0;
int player2score = 0;

bool intersects(sf::CircleShape &c1, sf::RectangleShape &rect2)
{
    sf::FloatRect circle = c1.getGlobalBounds();
    sf::FloatRect rectangle = rect2.getGlobalBounds();
    return circle.intersects(rectangle);
}

int main()
{
    cout << "Welcome to yet another Pong clone." << endl;
    cout << "Left side Player you are Player 1, please use W and S." << endl;
    cout << "Right side Player, you are Player 2, please use Arrow Keys." << endl;
    Sleep(5000);

    /*sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Thank You My Twilight [Instrumental] (Cover).wav"))
        return -1;
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(50.f);
    sound.setLoop(true);
    sound.play();*/

    sf::VideoMode videomode(400, 400);
    sf::RenderWindow window(videomode, "PONG");
    sf::CircleShape Ball;
    Ball.setFillColor(sf::Color::White);
    Ball.setRadius(10);
    Ball.setPosition(100, 200);
    sf::RectangleShape firstPlayer;
    firstPlayer.setFillColor(sf::Color::White);
    firstPlayer.setSize(sf::Vector2f(10, 50));
    firstPlayer.setPosition(30, 200);

    sf::RectangleShape secondPlayer;
    secondPlayer.setFillColor(sf::Color::White);
    secondPlayer.setSize(sf::Vector2f(10, 50));
    secondPlayer.setPosition(370, 200);

    sf::RectangleShape outleft;
    outleft.setFillColor(sf::Color::Black);
    outleft.setSize(sf::Vector2f(10, 400));
    outleft.setPosition(390, 0);

    sf::RectangleShape outright;
    outright.setFillColor(sf::Color::Black);
    outright.setSize(sf::Vector2f(10, 400));
    outright.setPosition(0, 0);

    sf::Color gray(128, 128, 128);

    sf::RectangleShape mid;
    mid.setFillColor(gray);
    mid.setSize(sf::Vector2f(10, 500));
    mid.setPosition(200, 0);

    sf::RectangleShape up;
    up.setFillColor(sf::Color::Black);
    up.setSize(sf::Vector2f(20, 400));
    up.setPosition(400, 0);
    up.rotate(90);

    sf::RectangleShape down;
    down.setFillColor(sf::Color::Black);
    down.setSize(sf::Vector2f(20, 400));
    down.setPosition(400, 380);
    down.rotate(90);
    sf::RectangleShape left;
    sf::RectangleShape right;
    sf::Vector2<float> ballSpeed(0.1, 0.1);

    while (window.isOpen())
    {

        Ball.move(ballSpeed.x, ballSpeed.y);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            secondPlayer.move(0, -0.1);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            secondPlayer.move(0, 0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            firstPlayer.move(0, -0.1);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            firstPlayer.move(0, 0.1);
        }
        if (intersects(Ball, outleft))
        {
            player1score++;
            Ball.setPosition(100, 200);
            std::cout << "Player 1 =  " << player1score << std::endl;
            ballSpeed.x = .1;
            ballSpeed.y = .1;
        }
        if (intersects(Ball, outright))
        {
            player2score++;
            Ball.setPosition(100, 200);
            std::cout << "Player 2 =  " << player2score << std::endl;
            ballSpeed.x = .1;
            ballSpeed.y = .1;
        }
        if (intersects(Ball, up) || (intersects(Ball, down)))
        {
            ballSpeed.y = -ballSpeed.y;
        }
        if (intersects(Ball, firstPlayer) || (intersects(Ball, secondPlayer)))
        {
            ballSpeed.x = -ballSpeed.x;
            ballSpeed.x *= 1.025;
            ballSpeed.y *= 1.025;

            if (ballSpeed.x >= .25 || ballSpeed.y >= .25)
            {
                mid.setFillColor(sf::Color::Cyan);

                if (ballSpeed.x >= .3 || ballSpeed.y >= .25)
                {
                    mid.setFillColor(sf::Color::Red);

                    if (ballSpeed.x >= .4 || ballSpeed.y >= .4)
                    {
                        mid.setFillColor(sf::Color::Green);
                    }
                }
            }
            else
            {
                mid.setFillColor(gray);
            }
        }

        if (player1score == 20 || player2score == 20)
        {
            window.close();
            cout << "GAME OVER" << endl;
        }

        window.clear(sf::Color::Black);
        window.draw(mid);
        window.draw(Ball);
        window.draw(secondPlayer);
        window.draw(down);
        window.draw(up);
        window.draw(firstPlayer);
        window.draw(outleft);
        window.draw(outright);
        window.display();
    }
}