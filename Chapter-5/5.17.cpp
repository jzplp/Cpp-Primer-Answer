#include<iostream>
#include<vector>

bool prefix(const std::vector<int> &vp, const std::vector<int> &vr)
{
	std::vector<int>::const_iterator vpit, vrit;
	for (vpit = vp.cbegin(), vrit = vr.cbegin(); vpit != vp.cend() && vrit != vr.cend(); ++vpit, ++vrit)
		if (*vpit != *vrit)
			return false;
	return true;
}

int main()
{
	std::vector<int> v1{0,1,1,3};
	std::vector<int> v2{0,1,1,2,3,5,8};
	bool flag;
	if (v1.size() > v2.size())
		flag = prefix (v2, v1);
	else
		flag = prefix (v1, v2);
	
	std::cout << flag << std::endl;
	return 0;
}

