#include<iostream>
#include<fstream>

int main()
{
	char cs[10];
	std::ifstream ifs("C:\\Users\\jz\\Desktop\\test.txt");
	while(ifs)
	{
		ifs.getline(cs, 9, '\n');
		std::cout << "line len: " << ifs.gcount() << std::endl;
		std::cout << cs << std::endl;
	}
	return 0;
}
