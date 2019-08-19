#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

int main()
{
	std::fstream inOut("C:\\Users\\jz\\Desktop\\test.txt", std::fstream::ate | std::fstream::in | std::fstream::out);
	if(!inOut)
	{
		std::cout << "Unable to open file!" << std::endl;
		return EXIT_FAILURE;
	}
	std::fstream::pos_type end_mark = inOut.tellg();
	inOut.seekg(0, std::fstream::beg);
	std::size_t cnt = 0;
	std::string line;
	while(inOut && inOut.tellg() != end_mark && std::getline(inOut, line))
	{
		cnt += line.size() + 1;
		std::fstream::pos_type mark = inOut.tellg();
		inOut.seekp(0, std::fstream::end);
		inOut << cnt;
		if(mark != end_mark)
			inOut << " ";
		inOut.seekg(mark);
	}
	inOut.seekp(0, std::fstream::end);
	inOut << "\n";
	return 0;
}
