// Include guard
//* Para que compilador no compile dos veces lo mismo
#ifndef __DESIGNER_H
#define __DESIGNER_H

//include dependences
#include "character.hpp"
using namespace std;

/**
 * A character class. A more elaborate class description.
 */
class designer : public player
{
	private:
        int power;

	public:
        /**
         * A constructor.
         * Create designer with defaults values.
         */
        designer();

        /**
         * A destructor.
         *
         */
        ~designer();

        /**
         * Gets the current height.
         * @see character()
         * @return Height of this character.
         */
        int get_power(void) {return this->power;}

};

#endif

