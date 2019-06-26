#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

int main()
{
	std::istream_iterator<int> is(std::cin), eof;
	std::vector<int> v(is, eof);
	std::ostream_iterator<int> os(std::cout, " ");
	std::sort(v.begin(), v.end());
	std::unique_copy(v.cbegin(), v.cend(), os);
	
	return 0;
} 



