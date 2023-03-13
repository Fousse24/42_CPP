#ifndef Karen_HPP
#define Karen_HPP

#include	<string>

class Karen
{
private:
	std::string	levels[4];
	void		(Karen::*f[4])(void);

	void		debug( void );
	void		info( void );
	void		warning( void );
	void		error( void );

public:
    Karen();
    ~Karen();

	void	complain( std::string level );

};

#endif