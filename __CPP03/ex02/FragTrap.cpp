#ifndef FLAGTRAP_HPP 
# define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap
{
	public: 
		FlagTrap (void);
		FlagTrap (const FlagTrap&);
		FlagTrap (const std::string&);
		~FlagTrap (void);

		FlagTrap& 	operator=(const FlagTrap&);

		void		attack (const std::string&);
		void highFivesGuys(void);
};

#endif