// Include guard
//* Para que compilador no compile dos veces lo mismo
#ifndef __HACKER_H
#define __HACKER_H

//include dependences
#include "character.hpp"
using namespace std;

/**
 * A character class. A more elaborate class description.
 */
class hacker : public player
{
	private:
        int power;

	public:
        /**
         * A constructor.
         * Create hacker with defaults values.
         */
        hacker();

        /**
         * A destructor.
         *
         */
        ~hacker();

        /**
         * Gets the current height.
         * @see character()
         * @return Height of this character.
         */
        int get_power(void) {return this->power;}

};

#endif

