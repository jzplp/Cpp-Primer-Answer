#include<iostream>
#include<string>

int main()
{
	std::string s, pres;
	bool flag = false;
	while (std::cin >> s)
	{
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

