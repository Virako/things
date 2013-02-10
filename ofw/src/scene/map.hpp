// Include guard
#ifndef __MAP_H
#define __MAP_H

#include "character.hpp"
#include "abstract_object.hpp"

/**
 * A map class. A more elaborate class description.
 */
class map
{
	private:
        int height;

	public:
        /**
         * A constructor.
         * Create map with defaults values.
         */
        map();

        /**
         * A destructor.
         * Remove the map instance.
         */
        ~map();

        /**
         * Gets the current height.
         * @see map()
         * @return Height of this map.
         */
        int get_height(void) {return this->height;}

};

#endif
