#include<fstream>
#include<algorithm>
#include<vector>
#include<iterator>

int main()
{
	std::ifstream inf("1.txt");
	std::ofstream of1("2.txt");
	std::ofstream of2("3.txt");
	std::istream_iterator<int> is(inf), eof;
	std::ostream_iterator<int> os_odd(of1, "\n");
	std::ostream_iterator<int> os_even(of2, "\n");
	
	std::vector<int> v(is, eof);
	std::copy_if(v.begin(), v.end(), os_odd, [](int i) { return i%2; });
	std::copy_if(v.begin(), v.end(), os_even, [](int i) { return !(i%2); });
	return 0;
} 

