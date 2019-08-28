* **练习19.1**  
重载new和delete 书上的版本  
[19.1 程序代码](19.1.cpp)  

* **练习19.2**  
StrVec类 仅本题使用  
重载new和delete  
[19.2 StrVec.h 程序代码](19.2/StrVec.h)  
[19.2 StrVec.cpp 程序代码](19.2/StrVec.cpp)  
[19.2 测试程序代码](19.2/main.cpp)  

* **练习19.3**  
(a) 正确  
(b) 错误  
(c) 正确  

* **练习19.4**  
```
try
{
    C & cy = dynamic_cast<C &>(*pa);
    //use C
}
catch (bad_cast)
{
    //use A
}
```

* **练习19.5**  
当基类和派生类的同名函数完成不同的，没有联系的功能时  

* **练习19.6**  
TextQuery类 仅本题使用  
Query和继承类 仅本题使用  
测试Query_base指针转换为AndQuery指针  
本题题目错误：  
AndQuery构造函数是私有的，对用户封装的，因此只有把AndQuery构造函数设为public的才能实现，但是这破坏了封装。  
[19.6 TextQuery.h程序代码](19.6/TextQuery.h)  
[19.6 TextQuery.cpp程序代码](19.6/TextQuery.cpp)  
[19.6 Query.h程序代码](19.6/Query.h)  
[19.6 Query.cpp程序代码](19.6/Query.cpp)  
[19.6 测试程序代码](19.6/main.cpp)  

* **练习19.7**  
TextQuery类 仅本题使用  
Query和继承类 仅本题使用  
测试Query_base引用转换为AndQuery引用  
本题题目错误：  
AndQuery构造函数是私有的，对用户封装的，因此只有把AndQuery构造函数设为public的才能实现，但是这破坏了封装。  
[19.7 TextQuery.h程序代码](19.7/TextQuery.h)  
[19.7 TextQuery.cpp程序代码](19.7/TextQuery.cpp)  
[19.7 Query.h程序代码](19.7/Query.h)  
[19.7 Query.cpp程序代码](19.7/Query.cpp)  
[19.7 测试程序代码](19.7/main.cpp)  

* **练习19.8**  
TextQuery类 仅本题使用  
Query和继承类 仅本题使用  
测试Query_base引用和typeid  
本题题目错误：  
AndQuery构造函数是私有的，对用户封装的，因此只有把AndQuery构造函数设为public的才能实现，但是这破坏了封装。  
[19.8 TextQuery.h程序代码](19.8/TextQuery.h)  
[19.8 TextQuery.cpp程序代码](19.8/TextQuery.cpp)  
[19.8 Query.h程序代码](19.8/Query.h)  
[19.8 Query.cpp程序代码](19.8/Query.cpp)  
[19.8 测试程序代码](19.8/main.cpp)  

* **练习19.9**  
[19.9 程序代码](19.9.cpp)  

* **练习19.10**  
```
(a) A*
(b) A*
(c) B
```

* **练习19.11**  
普通指针只能定义指向的类型，而数据成员指针可以指向特定类的成员类型，并且在解引用时才指定类对象。  

* **练习19.12**  
```
const Screen::pos Screen::*data;
data = &Screen::cursor;
```

* **练习19.13**  
```
const std::string Sales_data::*pdata;
pdata = &Sales_data::bookNo;
```

* **练习19.14**  
合法，因为pmf指向的类一样，函数类型也一样  

* **练习19.15**  
普通指针只能定义指向函数类型，而成员函数指针可以指向特定类的成员函数类型，并且在解引用时才指定类对象。  

* **练习19.16**  
```
double (Sales_data::*pfun)() const;
pfun = &Sales_data::avg_price;
```

* **练习19.17**  
```
using Action = Screen & (Screen::*)();
using getSome = char (Screen::*)() const;
using getSome2 = char (Screen::*)(Screen::pos, Screen::pos) const;
```

* **练习19.18**  

