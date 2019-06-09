* **练习7.1**  
[7.1程序代码](7.1.cpp)  

* **练习7.2**  
[7.2程序代码](7.2.cpp)  

* **练习7.3**  
[7.3程序代码](7.3.cpp)  

* **练习7.4**  
[7.4程序代码](7.4.cpp)  

* **练习7.5**  
[7.5程序代码](7.5.cpp)  
应该是const的，因为不修改类的成员，类的常量也能使用这些函数。

* **练习7.6**  
[7.6 Sales_data.h程序代码](7.6/Sales_data.h)  
[7.6 Sales_data.cpp程序代码](7.6/Sales_data.cpp)  

* **练习7.7**  
[7.7 重写交易处理程序代码](7.7/main.cpp)  

* **练习7.8**  
因为read函数要更改对象本身，print函数而不需要。

* **练习7.9**  
[7.9 Person.h程序代码](7.9/Person.h)  
[7.9 Person.cpp程序代码](7.9/Person.cpp)  

* **练习7.10**  
先写入data1，再写入data2,如果都成功则为真。

* **练习7.11**  
[7.11 Sales_data.h程序代码](7.11/Sales_data.h)  
[7.11 Sales_data.cpp程序代码](7.11/Sales_data.cpp)  
[7.11 调用构造函数程序代码](7.11/main.cpp)  

* **练习7.12**  
[7.12 Sales_data.h程序代码](7.12/Sales_data.h)  
[7.12 Sales_data.cpp程序代码](7.12/Sales_data.cpp)  
[7.12 调用构造函数程序代码](7.12/main.cpp)  

* **练习7.13**  
[7.13 调用istream构造函数重写程序代码](7.13/main.cpp)  
个人认为把trans用istream构造函数重写是错误的做法。

* **练习7.14**  
构造函数：
```
Sales_data() : ISBN(""), amount(0), totalPrice(0.0) { }
```

* **练习7.15**  
[7.15 Person.h程序代码](7.15/Person.h)  
[7.15 Person.cpp程序代码](7.15/Person.cpp)  
[7.15 调用构造函数程序代码](7.15/main.cpp)  

* **练习7.16**  
访问说明符出现在类中间即可，位置和数量没有限定。  
希望外部使用的接口应该在public说明符之后，不希望外部访问的成员在private说明符之后。

* **练习7.17**  
有区别。class成员默认是private的，struct成员默认是public的。

* **练习7.18**  
隐藏了实现的细节，只保留了接口给用户调用。

* **练习7.19**  
[7.19 Person.h程序代码](7.19/Person.h)  

* **练习7.20**  
在外部函数实现一些类的接口时可以使用友元函数。  
利：方便外部函数调用类的私有成员。  
弊：如果友元函数定义不良好，容易造成数据破坏。  

* **练习7.21**  
[7.21 Sales_data.h程序代码](7.21/Sales_data.h)  
[7.21 Sales_data.cpp程序代码](7.21/Sales_data.cpp)  
[7.21 调用封装的类程序代码](7.21/main.cpp)  

* **练习7.22**  
[7.22 Person.h程序代码](7.22/Person.h)  
[7.22 Person.cpp程序代码](7.22/Person.cpp)  
[7.22 调用封装的类程序代码](7.22/main.cpp)  

* **练习7.23**  

