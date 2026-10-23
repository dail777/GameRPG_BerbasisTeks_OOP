#include "player.h"
#include <iostream>
#include <cstdlib>

player::player(const std::string& name)
    : Character(name, 100, 10, 5), level(1), exp(0), gold(0), potions(3) {}

int player::attack(Character& target){
    int damage = attack_power + rand () % 5;
    bool criticalHit = (rand() % 100) < 10; // 10% chance for critical hit
    if (criticalHit) {
        damage *= 2;
        std::cout << "Critical hit!" << std::endl;
    }
    int actual_damage = target.takeDamage(damage);
    std::cout << name << " attacks " << target.getName() << " for "<< actual_damage << " damage." << std::endl;
    return actual_damage;
}

void player::showStatus() const {
    std::cout << "Player: " << name << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "HP: " << hp << " / " << max_hp << std::endl;
    std::cout << "Attack Power: " << attack_power << std::endl;
    std::cout << "exp: " << exp << "/" << level * 50 << std::endl;
    std::cout << "Gold: " << gold << std::endl;
}

void player::levelUp() {
    exp -= level * 50;
    level++;
    attack_power += 5;
    defense_power += 2;
    max_hp += 10;
    hp = max_hp;
    std::cout << "You leveled up to level " << level << "!" << std::endl;
}

void player::gainExp(int amount) {
    exp += amount;
    std::cout << name << " gained " << amount << " exp." << std::endl;
    while (exp >= level * 50) {
        levelUp();
    }
}

void player::addGold(int amount) {
    gold += amount;
    std::cout << name << " gained " << amount << " gold." << std::endl;
}

bool player::spendGold(int amount) {
    if (gold < amount) return false;
    gold -= amount;
    std::cout << name << " spent " << amount << " gold." << std::endl;
    return true;
}

void player::upgradeWeapon(int bonus) {
    attack_power += bonus;
    std::cout << name << "'s weapon upgraded! Attack power increased by " << bonus << "." << std::endl;
}
void player::restoreFull() {
    hp = max_hp;
    std::cout << name << "'s HP is fully restored!" << std::endl;
}

void player::addPotion() {
    potions++;
    std::cout << name << " received a potion." << std::endl;
}

bool player::usePotion() {
    if (potions <= 0) {
        std::cout << name << " has no potions left!" << std::endl;
        return false;
    }
    potions--;
    heal(50);
    std::cout << name << " used a potion and restored 50 HP." << std::endl;
    return true;
}

int player::getLevel() const {
    return level;
}
int player::getGold() const {
    return gold;
}
int player::getExp() const {
    return exp;
}