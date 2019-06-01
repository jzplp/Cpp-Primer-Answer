#include<iostream>
#include<cstring>
 
int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;
	while(std::cin >> ch)
	{
		ch = tolower(ch);
		switch (ch)
		{
			case 'a':
				++aCnt;
				break;
			case 'e':
				++eCnt;
				break;
			case 'i':
				++iCnt;
				break;
			case 'o':
				++oCnt;
				break;
			case 'u':
				++uCnt;
				break;
		}
	}
	
	std::cout 	<< "Number of vowel a: \t" << aCnt << '\n'  
				<< "Number of vowel e: \t" << eCnt << '\n'
				<< "Number of vowel i: \t" << iCnt << '\n' 
				<< "Number of vowel o: \t" << oCnt << '\n' 
				<< "Number of vowel u: \t" << uCnt << std::endl;
	return 0;
}

