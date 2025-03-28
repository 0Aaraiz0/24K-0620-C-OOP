#include <iostream>
using namespace std;

class Character {
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(int id, string n, int lvl, int hp, string weapon = "")
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}

    virtual void attack() {
        cout << name << " attacks with " << weaponType << "!" << endl;
    }
    
    virtual void defend() {
        cout << name << " defends!" << endl;
    }
    
    virtual void displayStats() {
        cout << "Character ID: " << characterID << "\nName: " << name << "\nLevel: " << level 
             << "\nHealth Points: " << healthPoints << "\nWeapon: " << weaponType << "\n";
    }
};

class Warrior : public Character {
private:
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int id, string n, int lvl, int hp, string weapon, int armor, int damage)
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}

    void attack() override {
        cout << name << " swings their weapon, dealing " << meleeDamage << " melee damage!" << endl;
    }
};

class Mage : public Character {
private:
    int manaPoints;
    int spellPower;

public:
    Mage(int id, string n, int lvl, int hp, int mana, int power)
        : Character(id, n, lvl, hp, "Magic Staff"), manaPoints(mana), spellPower(power) {}

    void defend() override {
        cout << name << " casts a magical barrier with " << manaPoints << " mana!" << endl;
    }
};

class Archer : public Character {
private:
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(int id, string n, int lvl, int hp, int arrows, int accuracy)
        : Character(id, n, lvl, hp, "Bow"), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override {
        cout << name << " shoots an arrow with " << rangedAccuracy << "% accuracy!" << endl;
    }
};

class Rogue : public Character {
private:
    int stealthLevel;
    int agility;

public:
    Rogue(int id, string n, int lvl, int hp, int stealth, int agil)
        : Character(id, n, lvl, hp, "Daggers"), stealthLevel(stealth), agility(agil) {}

    void displayStats() override {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << "\nAgility: " << agility << "\n";
    }
};

int main() {
    Warrior w1(1, "Gulzar", 10, 100, "Sword", 50, 20);
    Mage m1(2, "Adeel", 12, 80, 100, 25);
    Archer a1(3, "Zoya", 8, 90, 30, 85);
    Rogue r1(4, "Bilal", 11, 85, 70, 90);

    cout << "--- Warrior Stats ---\n";
    w1.displayStats();
    w1.attack();
    cout << "--------------------\n\n";

    cout << "--- Mage Stats ---\n";
    m1.displayStats();
    m1.defend();
    cout << "--------------------\n\n";

    cout << "--- Archer Stats ---\n";
    a1.displayStats();
    a1.attack();
    cout << "--------------------\n\n";

    cout << "--- Rogue Stats ---\n";
    r1.displayStats();
    cout << "--------------------\n";

    return 0;
}
