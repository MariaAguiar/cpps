#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "ScavTrap: Parameterized constructor called" << std::endl;
	Name = name;
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	energy = EnergyPoints;
};

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap: Default constructor called" << std::endl;
	Name = "name";
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	energy = EnergyPoints;
};

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
	*this = other;
};

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->Name = other.Name;
		this->HitPoints = other.HitPoints;
		this->EnergyPoints = other.EnergyPoints;
		this->AttackDamage = other.AttackDamage;
	}
	return *this;
};

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor called" << std::endl;
};

void ScavTrap::attack(const std::string& target)
{
	if (EnergyPoints > 0)
	{
		std::cout << Name << " attacks! " << target << " lost " << AttackDamage << " hitPoints! DAAAMN!" << std::endl;
		EnergyPoints--;
		std::cout << Name << "'s attacking action cost them 1 EnergyPoint. DAAAMN!" << std::endl;
	}
	else
		std::cout << "Can't attack! " << Name << " ran out of EnergyPoints! DAAAMN!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << Name << " is now in Gate keeper mode!" << std::endl;
}
