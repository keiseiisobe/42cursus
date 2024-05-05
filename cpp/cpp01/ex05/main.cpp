#include "Harl.hpp"

int	main()
{
	class Harl	h;

	h.complain("INFO");
	h.complain("DEBUG");
	h.complain("abc");
	h.complain("INFO");
	h.complain("WARNING");
	h.complain("ERROR");
	return 0;
}
