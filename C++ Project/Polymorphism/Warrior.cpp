#include "Warrior.h"

Warrior::Warrior(const string&name, double health, double attackStrength string allegiance): allegiance(allegiance),Character(WARRIOR,name,health,attackStrength){}

const string& getAllegiance() const{
      return allegiance;
}

void Warrior::attack(Character & enemy){
      if(enemy.getType() == WARRIOR){
            Warrior &opp = dynamic_cast<Warrior &>(enemy);
            if(opp.getAllegiance() == allegiance){
                  cout << "Warrior " << getName() << " does not attack Warrior " << opp.getName() << "." << endl;
                  cout << "They share an allegiance with " << getAllegiance() << "." << endl;
                  return;
            }
      }

      cout << "Warrior " << getName() << " attacks " << enemy.getName() << " --- SLASH!!" << endl;
      double dmg = (getHealth/MAX_HEALTH) * attackStrength;
      cout << enemy.getName() << " takes " << dmg << " damage." << endl;
      opp.damage(dmg);



}
