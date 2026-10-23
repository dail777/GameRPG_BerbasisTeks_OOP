#pragma once
#include <string>

class Character
{
protected:
    std::string name;
    int hp;
    int max_hp;
    int attack_power;
    int defense_power;

    public:
    Character(const std::string& name, int max_hp, int attack_power, int defense_power)
        : name(name), hp(max_hp), max_hp(max_hp), attack_power(attack_power), defense_power(defense_power) {}
    virtual ~Character() = default;

    virtual int attack(Character& target) = 0;
    virtual void showStatus() const;

    int takeDamage(int damage);
    void heal(int amount);
    bool isAlive() const;

    std::string getName() const;
    void setName(const std::string& new_name);
    int getHP() const;
    int getMaxHP() const;
    int getAttackPower() const;
    int getDefensePower() const;
};