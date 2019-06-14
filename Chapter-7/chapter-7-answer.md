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
```
struct X {
    X (int i, int j) : base(i), rem(i % j) { }
    int rem, base;
};

```

* **练习7.37**  
```
next:
Sales_data(std::string s = "") : bookNp(s) { }
0 , 0 , ""
last:
Sales_data(std::string s = "") : bookNp(s) { }
0 , 0 , "9-999-99999-9"
```

* **练习7.38**  
```
funConstruct(std::istream &in = std::cin);
```

* **练习7.39**  
不合法。会造成程序不能正确匹配到重载函数。

* **练习7.40**  
```
class Tree
{
public:
    Tree() = default;
    Tree(int d) : data(d) { }
    Tree(int d, Tree * l, Tree * r) : data(d), left(l), right(r) { }
private:
    int data = 0;
    Tree * left = nullptr;
    Tree * right = nullptr;
};
```

* **练习7.41**  
带输出的测试委托构造函数  
[7.41 Sales_data.h程序代码](7.41/Sales_data.h)  
[7.41 Sales_data.cpp程序代码](7.41/Sales_data.cpp)  
[7.41 测试程序代码](7.41/main.cpp)  

* **练习7.42**  
[7.42 Tree.h程序代码](7.42/Tree.h)  
[7.42 测试程序代码](7.42/main.cpp)  

* **练习7.43**  
```
class C
{
public:
    C () : no(0) { }
private:
    NoDefault no(0);
};
```

* **练习7.44**  
不合法，因为NoDefault类没有默认构造函数，vec无法对它进行值初始化

* **练习7.45**  
合法，因为C有默认构造函数，而且C的默认构造函数可以正常初始化NoDefault类

* **练习7.46**  
(a) 即使不提供，系统也会自动帮你生成一个（如果可以生成的话）  
(b) 正确  
(c) 不正确，如果不提供默认构造函数，那么就无法进行默认初始化和值初始化  
(d) 不正确，如果是内置类型的数据成员，那么进行默认初始化，其值是未定义的  

* **练习7.47**  
目前来看，可以是explicit的，也可以不是。因为即使允许隐式转换，由于units_sold和revenue都被初始化为0，因此不会影响正常计算。

* **练习7.48**  
```
不是explicit:
string null_isbn("9-999-99999-9")；
接受一个const char *作为参数，创建一个string变量
Sales_data item1(null_isbn);
接受一个string，创建一个Sales_data变量
Sales_data item2("9-999-99999-9");
const char * 隐式转换为string，再创建一个Sales_data变量

是explicit:
操作无影响，与上面相同
```

* **练习7.49**  
(a) string隐式转换为临时Sales_data对象，再值传递给函数  
(b) 非常量引用，无法调用  
(c) string隐式转换为临时Sales_data对象,再传递常量引用给函数

* **练习7.50**  
接受std::istream &为参数的构造函数可以是explicit的

* **练习7.51**  
因为string接受一个const char *作为非explicit的构造函数是有实际含义和需求的，不会造成歧义。
但是需要一个vector的地方却用一个整数作为实参有时会造成误解。

* **练习7.52**  
"978-0590353403"被bookNo用来初始化，25被units_sold用来初始化，15.99被revenue用来初始化  
作为真实的书好像太便宜了？应该是25 * 15.99被revenue用来初始化：  
Sales_data item = {"978-0590353403", 25, 25 * 15.99};

* **练习7.53**  
[7.53 Debug.h程序代码](7.53/Debug.h)  
[7.53 测试程序代码](7.53/main.cpp)  

* **练习7.54**  
不能，因为函数内存在执行实际操作的非return语句。

* **练习7.55**  
Data不是字面值常量类，因为数据成员string不是字面值类型。

* **练习7.56**  
静态成员类似于静态变量，提供了一种类的通用属性。不在类的变量中存储，不随类的变量而改变。

* **练习7.57**  
[7.57 Account.h程序代码](7.57/Account.h)  
[7.57 Account.cpp程序代码](7.57/Account.cpp)  
[7.57 测试程序代码](7.57/Account.cpp)  

* **练习7.58**  
有错误，带有类内初始值的静态数据成员必须是constexpr的,vector不是字面值常量类，不能使用constexpr，因此必须在类的外部初始化。
修改：
```
class Example
{
public:
    static constexpr double rate = 6.5;
    static constexpr int vecSize = 20;
    static std::vector<double> vec;
};

#include "example.h"
constexpr double Example::rate;
constexpr int Example::vecSize;
std::vector<double> Example::vec(vecSize);
```


