#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;

#include "item.h"


class Character {
private:
    string description;
     vector <Item> itemsInCharacter;
public:
    void addItem (Item &Item);
    vector <Item> getItems();
    Item* getItem (int area);
    int isItemInCharacter (string description);
    void removeItem (int area);

    Character(string description);
    string shortDescription();
    string longDescription();
    void setHealth();
    int getHealth();
    void setStamina();
    int getStamina();
    int health;
    int stamina;

};

#endif /*CHARACTER_H_*/
