#include <iostream>
#include <string>
using namespace std;

// Base class Character
class Character {
public:
    virtual void attack() = 0;  // Pure virtual function
    virtual ~Character() {}  // Virtual destructor
};

// Derived class Warrior
class Warrior : public Character {
public:
    void attack() override {
        cout << "Warrior swings a sword!" << endl;
    }
};

// Derived class Mage
class Mage : public Character {
public:
    void attack() override {
        cout << "Mage casts a fireball!" << endl;
    }
};

// Function to demonstrate character attack
void performAttack(Character* character) {
    character->attack();
}

int main() {
    // Creating characters
    Warrior warrior;
    Mage mage;

    // Polymorphic behavior
    performAttack(&warrior);  // Warrior attack
    performAttack(&mage);     // Mage attack

    return 0;
}
