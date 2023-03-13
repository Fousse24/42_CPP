#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"
# define MATERIA_N_SLOT 4
using std::string;

class Character : virtual public ICharacter
{
private:
	string		_name;
	AMateria	*_materias[MATERIA_N_SLOT];
	void		setMateria(int idx, AMateria * m);

public:
	Character();
	Character(string const & name);
	Character( Character const & src );
	~Character();

	Character &		operator=( Character const & obj );

	string const & 		getName() const;
	AMateria const *	getMateria(int idx) const;

	void	equip(AMateria * m);
	void	unequip(int idx);
	void	use(int idx, ICharacter & target);
};

#endif