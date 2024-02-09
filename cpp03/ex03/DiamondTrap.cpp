#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : FragTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap: Parameterized constructor called" << std::endl;
	Name = name;
	HitPoints = FragTrap::HitPoints;
	AttackDamage = FragTrap::AttackDamage;
	EnergyPoints = energy;
}

DiamondTrap::DiamondTrap()
{
    this->Name = "_clap_name";
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap& other) : FragTrap(other)
{
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap: Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->Name = other.Name;
		this->HitPoints = other.HitPoints;
		this->EnergyPoints = other.EnergyPoints;
		this->AttackDamage = other.AttackDamage;
	}
	return *this;
};

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Destructor called" << std::endl;
};

void DiamondTrap::whoAmI()
{
	std::cout << "I am: " << this->Name << "! " << ClapTrap::Name << "'s grandson!" << std::endl;
}
