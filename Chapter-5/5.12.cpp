#include<iostream>
#include<cstring>
 
int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, nlCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
	int ch,prech = 0;
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
				if(prech == 'f')
					++fiCnt;
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
			case 'f':
				if(prech == 'f')
					++ffCnt;
				break;
			case 'l':
				if(prech == 'f')
					++flCnt;
				break;
		}
		prech = ch;	
	}
	
	std::cout 	<< "Number of vowel a: \t" << aCnt << '\n'  
				<< "Number of vowel e: \t" << eCnt << '\n'
				<< "Number of vowel i: \t" << iCnt << '\n' 
				<< "Number of vowel o: \t" << oCnt << '\n' 
				<< "Number of vowel u: \t" << uCnt << std::endl
				<< "Number of vowel space: \t" << spaceCnt << std::endl
				<< "Number of vowel tab: \t" << tabCnt << std::endl
				<< "Number of vowel nl: \t" << nlCnt << std::endl
				<< "Number of vowel ff: \t" << ffCnt << std::endl
				<< "Number of vowel fl: \t" << flCnt << std::endl
				<< "Number of vowel fi: \t" << fiCnt << std::endl;
				
	return 0;
}

