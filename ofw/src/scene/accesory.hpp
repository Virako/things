// Include guard
//* Para que compilador no compile dos veces lo mismo
#ifndef __ACCESORY_H
#define __ACCESORY_H

//include dependences
#include "character.hpp"
using namespace std;

/**
 * A character class. A more elaborate class description.
 */
class accesory : public abstract_object
{
	private:
        int power;

	public:
        /**
         * A constructor.
         * Create cracker with defaults values.
         */
        accesory();

        /**
         * A destructor.
         *
         */
        ~accesory();

        /**
         * Gets the current height.
         * @see character()
         * @return Height of this character.
         */
        int get_power(void) {return this->power;}

        /**
         * Gets the current id.
         * @return id of this object.
         */
        virtual int get_id(void) {return this->id;}

        /**
         * Gets the current name.
         * @return Name of this object.
         */
        virtual string* get_name() {return this->name;}

        /**
         * Set the id.
         * @param id New int id.
         */
        virtual void set_id(int id);

        /**
         * Set the name.
         * @param name New int name.
         */
        virtual void set_name(string *name) {this->name = name;}

};

#endif

