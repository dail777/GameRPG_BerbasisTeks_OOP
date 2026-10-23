#pragma once
#include <string>

class player : public Character

private:

    int level;
    int exp;
    int gold;
    int potions;

void levelUp();

public:
    player(const std::string& name);

    int attack(Character& target) override;
    void showStatus() const override;
    void showInventory() const;
    void addGold(int amount);
    void addPotion();
    void gainExp(int amount);
    bool spendGold(int amount);
    void upgradeWeapon(int bonus);
    void restoreFull();
    bool usePotion();
    int getLevel() const;
    int getGold() const;