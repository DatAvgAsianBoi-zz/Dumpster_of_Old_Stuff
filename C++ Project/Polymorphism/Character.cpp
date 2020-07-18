#include "Character.h"

Character::Character(HeroType type, const string &name, double health, double attackStrength):type(type),name(name),health(health),attackStrength(attackStrength)}{};

HeroType Character::getType() const{
      return type;
}

const string & Character::getName() const{
      return name;
}

int Character::getHealth() const{
      return <static_cast>health;
}

void Character::setHealth(double h){
      if(h <= MAX_HEALTH)
            health = h;
      else
            health = MAX_HEALTH;
}

void Character::damage(double d){
      health -= d;
}

bool Character::isAlive() const{
      return (getHealth() > 0);
}
