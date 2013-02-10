// Include guard
//* Para que compilador no compile dos veces lo mismo
#ifndef __PICACODE_H
#define __PICACODE_H

//include dependences
#include "character.hpp"
using namespace std;

/**
 * A character class. A more elaborate class description.
 */
class picacode : public player
{
	private:
        int power;

	public:
        /**
         * A constructor.
         * Create picacode with defaults values.
         */
        picacode();

        /**
         * A destructor.
         *
         */
        ~picacode();

        /**
         * Gets the current height.
         * @see character()
         * @return Height of this character.
         */
        int get_power(void) {return this->power;}

};

#endif

