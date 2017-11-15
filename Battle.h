#ifndef _Battle_h
#define _Battle_h
 
#include <iostream>

#include "Soldier.h"
#include "Boss.h"

class Battle {
public:
	Boss& B;

	Battle(Soldier& S);
    void combatChoice(Soldier& S);
    void combat1(Soldier& S);
};
#endif
