* **练习17.1**  
[17.1 程序代码](17.1.cpp)  

* **练习17.2**  
[17.2 程序代码](17.2.cpp)  

* **练习17.3**  
TextQuery类 仅本题使用  
Query和继承类 仅本题使用  
QueryResult类更改为tuple类型   
[17.3 TextQuery.h程序代码](17.3/TextQuery.h)  
[17.3 TextQuery.cpp程序代码](17.3/TextQuery.cpp)  
[17.3 Query.h程序代码](17.3/Query.h)  
[17.3 Query.cpp程序代码](17.3/Query.cpp)  
[17.3 测试程序代码](17.3/main.cpp)  
我认为QueryResult类的设计更好，因为类把对象封装了起来，还可以增加类方便，不用了解内部的实现。也适合进行改动。

* **练习17.4**  
Sales_data类 书上的版本  
增加了书上版本的findBook和reportResult函数  
测试代码仅本题使用  
[17.4 Sales_data.h程序代码](17.4/Sales_data.h)  
[17.4 Sales_data.cpp程序代码](17.4/Sales_data.cpp)  
[17.4 测试程序代码](17.4/main.cpp)  

* **练习17.5**  
Sales_data类 仅本题使用  
findBook和reportResult函数 用pair不用tuple  
[17.5 Sales_data.h程序代码](17.5/Sales_data.h)  
[17.5 Sales_data.cpp程序代码](17.5/Sales_data.cpp)  
[17.5 测试程序代码](17.5/main.cpp)  

* **练习17.6**  
Sales_data类 仅本题使用  
findBook和reportResult函数 不用pair不用tuple用类  
[17.6 Sales_data.h程序代码](17.6/Sales_data.h)  
[17.6 Sales_data.cpp程序代码](17.6/Sales_data.cpp)  
[17.6 测试程序代码](17.6/main.cpp)  

* **练习17.7**  
我更倾向于类和tuple的，pair的太麻烦了  

* **练习17.8**  
最后计算的Sales_data中将不包含isbn

* **练习17.9**  
(a) 64位，其中第6位为1，其余为0  
(b) 32位，其中低20位为1111 0110 1001 1011 0101  
(c) 8位，具体表示由输入的字符串决定  

* **练习17.10**  
[17.10 程序代码](17.10.cpp)  

* **练习17.11**  
```
std::bitset<10> b1;
std::bitset<100> b1;
```

* **练习17.12**  
[17.12 程序代码](17.12.cpp)  

* **练习17.13**  
[17.13 程序代码](17.13.cpp)  

* **练习17.14**  
测试错误程序代码  
[17.14 程序代码](17.14.cpp)  

* **练习17.15**  
书上的版本  
[17.15 程序代码](17.15.cpp)  

* **练习17.16**  
此时只输出三个字母，后两个是ei  
[17.16 程序代码](17.16.cpp)  

* **练习17.17**  
书上的版本  
[17.17 程序代码](17.17.cpp)  

* **练习17.18**  
[17.18 程序代码](17.18.cpp)  

* **练习17.19**  
如果未匹配，str()会返回空的string，不会出现异常情况。

* **练习17.20**  
电话验证程序 书上的版本  
[17.20 程序代码](17.20.cpp)  

* **练习17.21**  
电话号码记录程序  
增加了regex识别电话号码  
[17.21 PersonInfo.h程序代码](17.21/PersonInfo.h)  
[17.21 测试程序代码](17.21/main.cpp)  

* **练习17.22**  
电话号码记录程序  
识别电话号码三个部分中可以增加空格    
[17.22 PersonInfo.h程序代码](17.22/PersonInfo.h)  
[17.22 测试程序代码](17.22/main.cpp)  

* **练习17.23**  
```
(\\d{5})([-])?(\\d{4})?
```

* **练习17.24**  

