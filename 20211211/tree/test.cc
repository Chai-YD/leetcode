#include <iostream>
#include <vector>

int main()
{
	std::string str(" ");
	str += std::to_string("#");
	str += std::to_string(1);
	str += std::to_string(2);
	str += std::to_string(3);

	std::cout << str << std::endl;
	return 0;
}
