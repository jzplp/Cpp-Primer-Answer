#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int v1,v2,temp;
	cin >> v1 >> v2;
	if(v1 > v2)
	{
		temp = v1;
		v1 = v2;
		v2 = temp;
	}
	while(v2 >= v1)
	{
		cout << v1 << " ";
		v1++;
	}
	cout << endl;
	return 0;
} 
