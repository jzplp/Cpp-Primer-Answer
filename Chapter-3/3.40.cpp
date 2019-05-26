#include<iostream>
#include<cstring>
int main()
{
	char s1[] = "12345";
	char s2[] = "6789";
	char s3[10];
	
	strcpy(s3,s1);
	strcat(s3,s2);
	
	std::cout << s3 << std::endl; 
	return 0;
}
