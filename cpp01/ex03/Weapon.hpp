#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon( const std::string& newType );
		~Weapon();
		void setType( const std::string& newType );
		const std::string &getType() const; // eu prometo que nao vou alterar nenhuma das member variables da classe, quando chamar esta função
	private:
		std::string type;
};

#endif
