// Include guard
//* Para que compilador no compile dos veces lo mismo
#ifndef __NPC_H
#define __NPC_H

//include dependences
#include "character.hpp"
using namespace std;

/**
 * A character class. A more elaborate class description.
 */
class npc : public character
{
	private:
        int power;

	public:
        /**
         * A constructor.
         * Create cracker with defaults values.
         */
        npc();

        /**
         * A destructor.
         *
         */
        ~npc();

        /**
         * Gets the current height.
         * @see character()
         * @return Height of this character.
         */
        int get_power(void) {return this->power;}

};

#endif

