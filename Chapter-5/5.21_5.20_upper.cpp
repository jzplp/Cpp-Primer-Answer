#include<iostream>
#include<string>
#include<cstring>

int main()
{
	std::string s, pres;
	bool flag = false;
	while (std::cin >> s)
	{
		if(s.empty() || !isupper(s[0]))
			continue; 
		if(s == pres)
		{
			flag = true;
			break;
		}
		pres = s;
	}
	
	if (flag == true)
		std::cout << s << std::endl; 
	else
		std::cout << "NO same word!" << std::endl;
	return 0;
}

