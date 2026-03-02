
#include <iostream> // std::cout and std::endl
#include <cctype> // std::toupper

int	main(int argc, char **argv)
{
	int i = 1;
	int j = 0;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;

	// std	- The Standard Namespace (kind of like a struct, but only groups code)
	// ::	- The Scope Resolution Operator, links the namespace to the object
	// cout	- The Standard Output Object
	// std::cout - "visualizer"
	// << 	- The Insertion Operator, sends data to the stream (pipe)

	else
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				std::cout << (char)std::toupper(argv[i][j]); 
				// converts to upper case, but output is an int ascii value, so we cast to char
				j++;
			}
			if (i < argc - 1)
				std::cout << " ";
			i++;
		}
		std::cout << std::endl;
		// endl	- I/O manipulator, writes \n and flushes the buffer
	}	
	return (0);
}
