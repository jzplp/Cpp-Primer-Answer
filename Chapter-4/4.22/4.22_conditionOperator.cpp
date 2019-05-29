#include<iostream>
#include<vector>
#include<string> 
int main()
{
	std::vector<int> v{0,10,20,30,40,50,60,70,80,90,100};
	for(int grade : v)
	{
		std::string finalgrade = (grade > 75) ? ((grade > 90) ? "high pass" : "pass") : ((grade >= 60) ? "low pass" : "fail");
		std::cout << finalgrade << std::endl;
	}
	
	return 0;
}

