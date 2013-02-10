// Include guard
//* Para que compilador no compile dos veces lo mismo
#ifndef __PLAYER_H
#define __PLAYER_H

//forward declared dependences

//include dependences
#include <string>;

class player : public character
{
    // static constants
    static const int size_inventary = 20;

	private:
        int type_class;
        std::string user;
        std::string password;

	public:
		//CONSTRUCTORS
        player(int id, int type_class, std::string user, std::string password);

		//DESTRUCTORS
		~player();

		//Getters
        // int check_user_pass{return valid;}
        int get_type_class(){return type_class;}

		//Setters
};

#endif
