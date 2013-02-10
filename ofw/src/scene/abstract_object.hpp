// Include guard
#ifndef __ABSTRACT_OBJECT_H
#define __ABSTRACT_OBJECT_H

// Dependences
#include <string>
using namespace std;

/**
 * A abstract object class. A more elaborate class description.
 */
class abstract_object
{
	private:
        int id;
        string *name;

	public:

        /**
         * Gets the current id.
         * @return id of this object.
         */
        virtual int get_id(void) = 0;

        /**
         * Gets the current name.
         * @return Name of this object.
         */
        virtual string* get_name() = 0;

        /**
         * Set the id.
         * @param id New int id.
         */
        virtual void set_id(int id) = 0;

        /**
         * Set the name.
         * @param name New int name.
         */
        virtual void set_name(string *name) = 0;
};

#endif
