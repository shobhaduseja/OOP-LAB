#include <iostream>
using namespace std;

class Character {
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;

public:
    Character(int id, string n, int lvl, int hp ) 
        : characterID(id), name(n), level(lvl), healthPoints(hp) {}

    virtual void attack() {
        cout << name << " attacks!" << endl;
    }

    virtual void defend() {
        cout << name << " defends!" << endl;
    }

    virtual void displayStats() {
        cout << "ID: " << characterID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health Points: " << healthPoints << endl;
    }

    void operator<<(Character& character) {
        character.displayStats();
    }
};

class Warrior : public Character {
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int id, string n, int lvl, int hp, int armor, int damage) 
        : Character(id, n, lvl, hp), armorStrength(armor), meleeDamage(damage) {}

    void attack() override {
        cout << name << " performs melee strike with" << meleeDamage << " damage" << endl;
    }
};

class Mage : public Character {
    int manaPoints;
    int spellPower;

public:
    Mage(int id, string n, int lvl, int hp, int mana, int spell) 
        : Character(id, n, lvl, hp), manaPoints(mana), spellPower(spell) {}

    void defend() override {
        cout << name << " uses a magical barrier!" << endl;
    }
};

class Archer : public Character {
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(int id, string n, int lvl, int hp, int arrows, int accuracy) 
        : Character(id, n, lvl, hp), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override {
        if (arrowCount > 0) {
            cout << name << " fires an arrow with " << rangedAccuracy << "% accuracy!" << endl;
            arrowCount--;
        } else {
            cout << name << " is out of arrows!" << endl;
        }
    }
};

class Rogue : public Character {
    int stealthLevel;
    int agility;

public:
    Rogue(int id, string n, int lvl, int hp, int stealth, int ag) 
        : Character(id, n, lvl, hp), stealthLevel(stealth), agility(ag) {}

    void displayStats() override {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main() {
    Warrior warrior(101, "shooby", 13, 1222, 50, 33);
    Mage mage(102, "aseelah", 13, 100, 200, 98);
    Archer archer(103, "abeer", 12, 120, 20, 20);
    Rogue rogue(104, "sam", 34, 110, 80, 95);

    warrior.displayStats();
    cout << endl;
    mage.displayStats();
    cout << endl;
    archer.displayStats();
    cout << endl;
    rogue.displayStats();
    
    warrior.attack();
    mage.defend();
    archer.attack();
    rogue.attack();

    warrior << mage;

    return 0;
}