#include<iostream>
#include<string>
#include<vector>
#include<stack> 

int countOne(std::stack<int> &st)
{
	int t1,t2,t3;
	t1 = st.top();
	st.pop();
	st.pop();
	t2= st.top();
	st.pop();
	t3 = t1+t2;
	//std::cout << t3 << std::endl;
	return t3;
}

int main()
{
	int co = ((5+3)+6+4)+2+(2+4+4)+4;
	std::string s("((5+3)+6+4)+2+(2+4+4)+4");
	std::stack<int> st;
	int t1;
	for(char c : s)
	{
		switch(c)
		{
			case ')':
				t1 = countOne(st);
				while(!st.empty() && st.top() != -2)
				{
					st.push(t1);
					t1 = countOne(st);
				}
				if(st.top() == -2)
					st.pop();
				st.push(t1);
				break;
			case '+':
				st.push(-1);
				break;
			case '(':	
				st.push(-2);
				break;
			default:
				st.push(c-'0');
				break;
				
		}
	}
	t1 = st.top();
	st.pop();
	while(!st.empty())
	{
		st.push(t1);
		t1 = countOne(st);
	}
	std::cout << co << " " << t1 << std::endl; 

	return 0;
}
