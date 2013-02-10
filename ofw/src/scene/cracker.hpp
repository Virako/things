// Include guard
//* Para que compilador no compile dos veces lo mismo
#ifndef __CRACKER_H
#define __CRACKER_H

//include dependences
#include "character.hpp"
using namespace std;

/**
 * A character class. A more elaborate class description.
 */
class cracker : public player
{
	private:
        int power;

	public:
        /**
         * A constructor.
         * Create cracker with defaults values.
         */
        cracker();

        /**
         * A destructor.
         *
         */
        ~cracker();

        /**
         * Gets the current height.
         * @see character()
         * @return Height of this character.
         */
        int get_power(void) {return this->power;}

};

#endif

