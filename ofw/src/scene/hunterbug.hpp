// Include guard
//* Para que compilador no compile dos veces lo mismo
#ifndef __HUNTERBUG_H
#define __HUNTERBUG_H

//include dependences
#include "character.hpp"
using namespace std;

/**
 * A character class. A more elaborate class description.
 */
class hunterbug : public player
{
	private:
        int power;

	public:
        /**
         * A constructor.
         * Create hunterbug with defaults values.
         */
        hunterbug();

        /**
         * A destructor.
         *
         */
        ~hunterbug();

        /**
         * Gets the current height.
         * @see character()
         * @return Height of this character.
         */
        int get_power(void) {return this->power;}

};

#endif

