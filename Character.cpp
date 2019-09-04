#include "Character.h"
#include "item.h"

Character::Character(string description) {
    this->description = description;
}
void Character::addItem(Item &item) {
    cout << "The item will now be added to this character: " << item.getShortDescription() << endl;
    itemsInCharacter.push_back(item);
    cout << "The character now has " << itemsInCharacter.size() << " in their inventory" << endl;
}

/*void Character::addItem(Item *item) {
    itemsInCharacter.push_back(*item);
    delete item;
}*/

int Character::isItemInCharacter (string description)
{
    for (unsigned int i = 0; i < itemsInCharacter.size(); i++)
    {
        if (description.compare(itemsInCharacter[i].getShortDescription()) == 0)
        {
            return i;
        }
    }

    return -1;
}

Item* Character::getItem (int area)
{
    return &itemsInCharacter[area];
}

void Character::removeItem (int area)
{
    itemsInCharacter.erase(itemsInCharacter.begin() + area);
}

string Character::longDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";
  for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
    ret += "\t"+ (*i).getLongDescription() + "\n";
  return ret;
}

vector <Item> Character::getItems()
{
    return itemsInCharacter;
}

void Character::setHealth()
{
    int health = 100;
}

int Character::getHealth()
{
    return health;
}

void Character::setStamina()
{
    int stamina = 100;
}

int Character::getStamina()
{
    return stamina;
}



