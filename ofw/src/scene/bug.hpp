// Include guard
//* Para que compilador no compile dos veces lo mismo
#ifndef __BUG_H
#define __BUG_H

//include dependences
#include "character.hpp"
using namespace std;

/**
 * A character class. A more elaborate class description.
 */
class bug : public character
{
	private:
        int power;

	public:
        /**
         * A constructor.
         * Create cracker with defaults values.
         */
        bug();

        /**
         * A destructor.
         *
         */
        ~bug();

        /**
         * Gets the current height.
         * @see character()
         * @return Height of this character.
         */
        int get_power(void) {return this->power;}

};

#endif

