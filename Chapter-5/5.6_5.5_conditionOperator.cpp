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
		(grade < 60) ? (s = level[0]) : ((s = level[(grade - 50)/10]), (grade != 100) ? (s += (grade % 10 > 7) ? "+" : "" ), (s += (grade % 10 < 3) ? "-" : "" ) : "" );
		std::cout << s << std::endl; 
	}
	
	return 0;
}

