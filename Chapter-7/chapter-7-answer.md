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
[7.23 Screen.h程序代码](7.23/Screen.h)  

* **练习7.24**  
[7.24 Screen.h程序代码](7.24/Screen.h)  
[7.24 类测试程序代码](7.24/main.cpp)  

* **练习7.25**  
Screen类可以依赖于默认版本的复制和拷贝操作。因为没有分配类对象以外的资源，且内部成员都支持默认复制和拷贝操作。

* **练习7.26**  
[7.26 Sales_data.h程序代码](7.26/Sales_data.h)  
[7.26 Sales_data.cpp程序代码](7.26/Sales_data.cpp)  
[7.26 测试程序代码](7.26/main.cpp)  

* **练习7.27**  
[7.27 Screen.h程序代码](7.27/Screen.h)  
[7.27 类检验程序代码](7.27/main.cpp)  

* **练习7.28**  
set将只修改临时对象。第一行输出正确的更改后的临时对象，第二行输出的是未整改的对象。

* **练习7.29**  
逻辑上非正确的程序代码：  
[7.29 Screen.h程序代码](7.29/Screen.h)  
[7.29 类检验程序代码](7.29/main.cpp)  

* **练习7.30**  
优点：结构清晰，容易让人了解变量的作用域。  
缺点：有些多余  

* **练习7.31**  
[7.31程序代码](7.31.cpp)  

* **练习7.32**  
[7.32 Screen.h程序代码](7.32/Screen.h)  
[7.32 类检验程序代码](7.32/main.cpp)  

* **练习7.33**  
出现编译错误。   
正确的程序代码：  
[7.33 Screen.h程序代码](7.33/Screen.h)  
[7.33 类检验程序代码](7.33/main.cpp)  

* **练习7.34**  
会出现编译错误，成员找不到pos类型

* **练习7.35**  
类型定义分别是：
```
typedef string Type;
Type initVal(); //string
class Exercise {
public:
    typedef double Type;
    Type setVal (Type); //double
    Type initVal (); //double
private:
    int val;
};
Type Exercise::setVal(Type parm) { //string double
    val += parm + initVal();
    return val;
}
```

修改后：（我觉得val也应该用double,但是下面并未修改）
```
typedef string Type;
Type initVal(); //string
class Exercise {
public:
    typedef double Type;
    Type setVal (Type); //double
    Type initVal (); //double
private:
    int val;
};
Exercise::Type Exercise::setVal(Type parm) { //string double
    val += parm + initVal();
    return val;
}
```

* **练习7.36**  

