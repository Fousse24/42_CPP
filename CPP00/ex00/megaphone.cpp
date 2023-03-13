#include <iostream>
#include <cstring>
#include <string>

int main(int argc, char** argv)
{
	size_t	i;
	size_t 	j;
 
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (i = 1; i < (size_t)argc; i++)
		{
			for (j = 0; j < strlen(argv[i]); j++)
			{
				std::cout << (char)toupper(argv[i][j]);
			}
		}
	}
	std::cout << std::endl;
    return 0;
}