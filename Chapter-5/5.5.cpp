#include<iostream>
#include<vector>
#include<string>
 
int main()
{
	std::vector<std::string> level{"F", "D", "C", "B", "A", "A++"};
	int grade;
	while(std::cin >> grade && grade >= 0 && grade <= 100)
	{
		std::string s;
		if(grade < 60)
			s = level[0];
		else {
			s = level[(grade - 50)/10];
			if(grade != 100)
			{
				if(grade % 10 > 7)
					s += "+";
				if(grade % 10 < 3)
					s += "-";
			}
		}
		std::cout << s << std::endl; 
	}
	
	return 0;
}

