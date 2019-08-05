#include<iostream>
#include<string>
#include<vector>

template <typename T> 
void print(const T &t)
{
	for(typename T::size_type i = 0; i < t.size(); ++i)
		std::cout << t[i] << " ";
	std::cout << std::endl;
}

int main()
{
	std::string s = "12345";
	std::vector<int> v{1,2,34,4,5,32};
	print(s);
	print(v);
	return 0;
}









