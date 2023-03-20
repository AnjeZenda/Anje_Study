#include "Converter.h"

Converter::Converter() {
    commands.emplace("A", sf::Keyboard::A);
    commands.emplace("B", sf::Keyboard::B);
    commands.emplace("C", sf::Keyboard::C);
    commands.emplace("D", sf::Keyboard::D);
    commands.emplace("E", sf::Keyboard::E);
    commands.emplace("F", sf::Keyboard::F);
    commands.emplace("G", sf::Keyboard::G);
    commands.emplace("H", sf::Keyboard::H);
    commands.emplace("I", sf::Keyboard::I);
    commands.emplace("J", sf::Keyboard::J);
    commands.emplace("K", sf::Keyboard::K);
    commands.emplace("L", sf::Keyboard::L);
    commands.emplace("M", sf::Keyboard::M);
    commands.emplace("O", sf::Keyboard::O);
    commands.emplace("P", sf::Keyboard::P);
    commands.emplace("Q", sf::Keyboard::Q);
    commands.emplace("R", sf::Keyboard::R);
    commands.emplace("S", sf::Keyboard::S);
    commands.emplace("T", sf::Keyboard::T);
    commands.emplace("U", sf::Keyboard::U);
    commands.emplace("V", sf::Keyboard::V);
    commands.emplace("W", sf::Keyboard::W);
    commands.emplace("X", sf::Keyboard::X);
    commands.emplace("Y", sf::Keyboard::Y);
    commands.emplace("Z", sf::Keyboard::Z);
    commands.emplace("Up", sf::Keyboard::Up);
    commands.emplace("Down", sf::Keyboard::Down);
    commands.emplace("Left", sf::Keyboard::Left);
    commands.emplace("Right", sf::Keyboard::Right);
    commands.emplace("1", sf::Keyboard::Num1);
    commands.emplace("2", sf::Keyboard::Num2);
    commands.emplace("3", sf::Keyboard::Num3);
    commands.emplace("4", sf::Keyboard::Num4);
    commands.emplace("5", sf::Keyboard::Num5);
    commands.emplace("6", sf::Keyboard::Num6);
    commands.emplace("7", sf::Keyboard::Num7);
    commands.emplace("8", sf::Keyboard::Num8);
    commands.emplace("9", sf::Keyboard::Num9);
    commands.emplace("0", sf::Keyboard::Num0);
    commands.emplace("F5", sf::Keyboard::F5);
    commands.emplace("F9", sf::Keyboard::F9);
}

sf::Keyboard::Key Converter::convert(std::string string) {
    if (commands.find(string) != commands.end()) {
        return commands.at(string);
    }
    return sf::Keyboard::Unknown;
}
