#include<iostream>
#include<cstring>
 
int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, nlCnt = 0;
	int ch;
	while((ch = std::cin.get()) != EOF) 
	{
		//ch = tolower(ch);
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
			case ' ':
				++spaceCnt;
				break;
			case '\t':
				++tabCnt;
				break;
			case '\n':
				++nlCnt;
				break;
		}
	}
	
	std::cout 	<< "Number of vowel a: \t" << aCnt << '\n'  
				<< "Number of vowel e: \t" << eCnt << '\n'
				<< "Number of vowel i: \t" << iCnt << '\n' 
				<< "Number of vowel o: \t" << oCnt << '\n' 
				<< "Number of vowel u: \t" << uCnt << std::endl
				<< "Number of vowel space: \t" << spaceCnt << std::endl
				<< "Number of vowel tab: \t" << tabCnt << std::endl
				<< "Number of vowel nl: \t" << nlCnt << std::endl;
	return 0;
}

