#include <iostream>
#include <string>

using namespace std;

class Item {
    private:
    string name;
    int cost;

    public:
    Item(string name, int cost) {
        this->name = name;
        this->cost = cost;
    }

    string getName() { return name; }

    void setName(string name) { this->name = name; }

    int getCost() { return cost; }

    void setCost(int cost) { this->cost = cost; }

    void print() {
        cout << "{name: " << name << "; cost: " << cost << "}" << endl;
    }
}

class Weapon : public Item {
    private:
    int minDamage;
    int maxDamage;

    public:
    Weapon(string name, int cost, int minDamage, int maxDamage) : Item(name, cost) {
        this->minDamage = minDamage;
        this->maxDamage = maxDamage;
    }

    int getMinDamage() { return minDamage; }

    void setMinDamage(int minDamage) { this->minDamage = minDamage; }

    int getMaxDamage() { return maxDamage; }

    void setMaxDamage(int maxDamage) { this->maxDamage = maxDamage; }

    void print() {
        cout << "{name: " << getName() << "; cost: " << getCost()
             << "; minDamage: " << minDamage << "; maxDamage: " << maxDamage << "}" << endl;
    }
};

class Armor : public Item {
    private:
    int defense;

    public:
    Armor(string name, int cost, int defense) : Item(name, cost) {
        this->defense = defense;
    }

    int getDefense() { return defense; }

    void setDefense(int defense) { this->defense = defense; }

    void print() {
        cout << "{name: " << getName() << "; cost: " << getCost()
             << "; defense: " << defense << "}" << endl;
    }
}

int main() {

    Item item1 = Item("Teleport Scroll", 25);
    item1.print();

    Weapon weapon1 = Weapon("Broad Sword", 55, 6, 12);
    weapon1.print();

    Armor armor1 = Armor("Chainmail", 95, 28);
    armor1.print();

    Weapon weapon2 = Weapon("Battle Axe", 125, 18, 24);
    Item *item2 = (Item *) &weapon2;
    weapon2.print();
    item2.print();

    return 0;
}