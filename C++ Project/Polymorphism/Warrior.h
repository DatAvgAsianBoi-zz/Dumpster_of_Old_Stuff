#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior: public Character {
      string allegiance;
public:
      Warrior(const string& name, double health, double attackStrength, string alliegence);
      const string& getAllegiance() const;
      void attack(Character &);
 };

#endif
