#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FragTrap: Parameterized constructor called" << std::endl;
	Name = name;
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
};

FragTrap::FragTrap()
{
	std::cout << "FragTrap: Default constructor called" << std::endl;
	Name = "name";
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
};

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap: Copy constructor called" << std::endl;
	*this = other;
};

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->Name = other.Name;
		this->HitPoints = other.HitPoints;
		this->EnergyPoints = other.EnergyPoints;
		this->AttackDamage = other.AttackDamage;
	}
	return *this;
};

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor called" << std::endl;
};

void FragTrap::highFivesGuys()
{
	std::cout << Name << ": High-Five time! NOW!" << std::endl;
};
