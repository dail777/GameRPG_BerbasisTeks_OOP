#include "Character.h"
#include <iostream>

Character::Character(const std::string& name, int max_hp, int attack_power, int defense_power)
    : name(name), hp(max_hp), max_hp(max_hp), attack_power(attack_power), defense_power(defense_power) {}

Character::~Character() {}

void Character::showStatus() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "HP: " << hp << " / " << max_hp << std::endl;
    std::cout << "Attack Power: " << attack_power << std::endl;
    std::cout << "Defense Power: " << defense_power << std::endl;
}

int Character::takeDamage(int damage) {
    int actual_damage = damage - defense_power;
    if (actual_damage < 0) {
        actual_damage = 0;
    }
    hp -= actual_damage;
    if (hp < 0) {
        hp = 0;
    }
    return actual_damage;
}

void Character::heal(int amount) {
    hp += amount;
    if (hp > max_hp) {
        hp = max_hp;
    }
}

bool Character::isAlive() const {
    return hp > 0;
}

std::string Character::getName() const {
    return name;
}

void Character::setName(const std::string& new_name) {
    name = new_name;
}

int Character::getHP() const {
    return hp;
}

int Character::getMaxHP() const {
    return max_hp;
}

int Character::getAttackPower() const {
    return attack_power;
}

int Character::getDefensePower() const {
    return defense_power;
}
