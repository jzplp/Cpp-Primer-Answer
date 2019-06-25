* **练习10.1**  
[10.1程序代码](10.1.cpp)  

* **练习10.2**  
[10.2程序代码](10.2.cpp)  

* **练习10.3**  
[10.3程序代码](10.3.cpp)  

* **练习10.4**  
会舍弃每个double中的小数部分，得到的结果是一个整数

* **练习10.5**  
会比较两个roster中对应C风格字符串的地址是否一致  

* **练习10.6**  
[10.6程序代码](10.6.cpp)  

* **练习10.7**  
```
(a)
vector<int> vec;
list<int> lst;
int i;
while(cin >> i)
    lst.push_back(i);
vec.resize(lst.size());
copy(lst.cbegin(), lst.cend(), vec.begin());

(b)
vector<int> vec(10);
fill_n(vec.beigin(), 10, 0);
```

* **练习10.8**  
因为算法本身不改变容器大小，但是用back_inserter迭代器的内部操作，调用push_back来改变。

* **练习10.9**  
[10.9程序代码](10.9.cpp)  

* **练习10.10**  
1. 使算法独立于各种容器，甚至内置数组也能正常使用算法
2. 改变容器大小会使迭代器失效

* **练习10.11**  
[10.11程序代码](10.11.cpp)  

* **练习10.12**  
未更改Sales_data类  
[10.12 Sales_data.h程序代码](10.12/Sales_data.h)  
[10.12 Sales_data.cpp程序代码](10.12/Sales_data.cpp)  
[10.12 调用封装的类程序代码](10.12/main.cpp)  

* **练习10.13**  
[10.13程序代码](10.13.cpp)  

* **练习10.14**  
```
[](int i,int j){ return i+j; }
```

* **练习10.15**  
[10.15程序代码](10.15.cpp)  

* **练习10.16**  
[10.16 biggies程序代码](10.16.cpp)  

* **练习10.17**  
未更改Sales_data类  
[10.12 Sales_data.h程序代码](10.17/Sales_data.h)  
[10.12 Sales_data.cpp程序代码](10.17/Sales_data.cpp)  
[10.12 lambda测试程序代码](10.17/main.cpp)  

* **练习10.18**  
[10.18 biggies程序代码](10.18.cpp)  

* **练习10.19**  
[10.19 biggies程序代码](10.19.cpp)  

* **练习10.20**  
[10.20 biggies程序代码](10.20.cpp)  

* **练习10.21**  
[10.21程序代码](10.21.cpp)  