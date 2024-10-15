#include <iostream>
using namespace std;

class Character {
public:
    virtual void attack() const = 0;
};

class Warrior : public Character {
public:
    void attack() const override { cout << "Warrior attacks with sword!\n"; }
};

class Mage : public Character {
public:
    void attack() const override { cout << "Mage casts a spell!\n"; }
};

int main() {
    Character* c1 = new Warrior();
    Character* c2 = new Mage();
    c1->attack();
    c2->attack();
    delete c1; delete c2;
    return 0;
}
