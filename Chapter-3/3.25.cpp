#include<iostream>
#include<vector>

int main()
{
	std::vector<unsigned> score(11, 0);
	unsigned grade;
	
	while(std::cin >> grade)
		if(grade <= 100)
			(*(score.begin() + grade/10))++;
		
	//output the score to validation results	
	for(std::vector<unsigned>::const_iterator it = score.cbegin(); it != score.cend(); ++it)
		std::cout << *it << " ";
	 
	return 0;
}
