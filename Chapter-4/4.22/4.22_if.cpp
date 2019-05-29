#include<iostream>
#include<vector>
#include<string> 
int main()
{
	std::vector<int> v{0,10,20,30,40,50,60,70,80,90,100};
	for(int grade : v)
	{
		std::string finalgrade;
		if(grade > 75)
			if(grade > 90)
				finalgrade = "high pass";
			else
				finalgrade = "pass";
		else if(grade < 60)
			finalgrade = "fail";
			else
			finalgrade = "low pass";
		std::cout << finalgrade << std::endl;
	}
	
	return 0;
}

