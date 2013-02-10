// Include guard
#ifndef __CHARACTER_H
#define __CHARACTER_H

// Dependences
#include <string>
using namespace std;

/**
 * A character class. A more elaborate class description.
 */
class character
{
	private:
        int height;
        int width;
        string *model;
        string *texture;
        string *name;

	public:
        /**
         * A constructor.
         * Create character with defaults values.
         */
        character();

        /**
         * A destructor.
         * Remove the character instance.
         */
        ~character();

        /**
         * Gets the current height.
         * @see character()
         * @return Height of this character.
         */
        int get_height(void) {return this->height;}

        /**
         * Gets the current width.
         * @return Width of this character.
         */
        int get_width(void) {return this->width;}

        /**
         * Gets the current model.
         * @return Model of this character.
         */
        string* get_model() {return this->model;}

        /**
         * Gets the current texture.
         * @return Texture of this character.
         */
        string* get_texture() {return this->texture;}

        /**
         * Gets the current name.
         * @return Name of this character.
         */
        string* get_name() {return this->name;}

        /**
         * Set height.
         * @param height New int height.
         */
        void set_height(int height);

        /**
         * Set the width.
         * @param width New int width.
         */
        void set_width(int width);

        /**
         * Set the model.
         * @param model New int model.
         */
        void set_model(string *model) {this->model = model;}

        /**
         * Set the texture.
         * @param texture New int texture.
         */
        void set_texture(string *texture) {this->texture = texture;}

        /**
         * Set the name.
         * @param name New int name.
         */
        void set_name(string *name) {this->name = name;}

        /**
         * Increment height.
         */
        void height_inc();

        /**
         * Decrement height.
         */
        void height_dec();

        /**
         * Increment width.
         */
        void width_inc();

        /**
         * Decrement width.
         */
        void width_dec();
};

#endif
