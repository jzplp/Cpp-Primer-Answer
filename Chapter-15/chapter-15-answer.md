* **练习15.1**  
基类希望派生类进行覆盖的成员是虚成员

* **练习15.2**  
private成员派生类也不能访问  
protected成员派生类可以访问  

* **练习15.3**  
Quote类和print_total函数 书上的版本  
[15.3 Quote.h程序代码](15.3/Quote.h)  
[15.3 Quote.cpp程序代码](15.3/Quote.cpp)  
[15.3 测试程序代码](15.3/main.cpp)  

* **练习15.4**  
(a) 不正确，类不能派生自己  
(b) 正确  
(c) 不正确，类的声明不能有派生列表  

* **练习15.5**  
Quote类和print_total函数 书上的版本  
增加了Bulk_quote类
[15.5 Quote.h程序代码](15.5/Quote.h)  
[15.5 Quote.cpp程序代码](15.5/Quote.cpp)  
[15.5 测试程序代码](15.5/main.cpp)  

* **练习15.6**  
Quote类和print_total函数 书上的版本  
检查已经在15.5题完成  
[15.5 Quote.h程序代码](15.5/Quote.h)  
[15.5 Quote.cpp程序代码](15.5/Quote.cpp)  
[15.5 测试程序代码](15.5/main.cpp)  

* **练习15.7**  
Quote类和print_total函数 书上的版本  
自定义Spec_quote类 仅本题使用  
[15.7 Quote.h程序代码](15.7/Quote.h)  
[15.7 Quote.cpp程序代码](15.7/Quote.cpp)  
[15.7 测试程序代码](15.7/main.cpp)  

* **练习15.8**  
静态类型是编译时已知的，是变量声明和表达式生成的类型  
动态类型是在运行时才知的，是变量或者表达式表示的内存中的对象的类型  

* **练习15.9**  
1. 把一个基类对象的指针绑定到派生类对象上  
2. 把一个基类对象的引用绑定到派生类的对象上  
3. 用一个派生类对象初始化基类对象  

* **练习15.10**  
read函数接受一个动态类型为ifstream的对象，然后将它绑定在它的基类istream的引用上。  

* **练习15.11**  
Quote类和print_total函数 书上的版本  
增加了debug虚函数  
[15.11 Quote.h程序代码](15.11/Quote.h)  
[15.11 Quote.cpp程序代码](15.11/Quote.cpp)  
[15.11 测试程序代码](15.11/main.cpp)  

* **练习15.12**  
有必要，不允许后续的派生类再覆盖这个虚函数  

* **练习15.13**  
有问题，会造成函数无限递归。  
修改：
```
derived类中的print函数：
void print(ostream & os) override
{
    this->base::print(os);
    os << " " << i;
}
```

* **练习15.14**  
(a) base::print  
(b) derived::print  
(c) base::name  
(d) derived::name  
(e) base::print  
(f) derived::print  

* **练习15.15**  
Quote类 书上的版本  
增加了Disc_quote抽象基类  
[15.15 Quote.h程序代码](15.15/Quote.h)  
[15.15 Quote.cpp程序代码](15.15/Quote.cpp)  
[15.15 测试程序代码](15.15/main.cpp)  

* **练习15.16**  
Quote类 书上的版本  
Disc_quote抽象基类继承的Spec_quote类 仅本题使用  
[15.16 Quote.h程序代码](15.16/Quote.h)  
[15.16 Quote.cpp程序代码](15.16/Quote.cpp)  
[15.16 测试程序代码](15.16/main.cpp)  

* **练习15.17**  
Quote类 书上的版本  
仅更改了main.cpp  
测试使用 用来测试错误 仅本题使用  
[15.17 Quote.h程序代码](15.17/Quote.h)  
[15.17 Quote.cpp程序代码](15.17/Quote.cpp)  
[15.17 测试程序代码](15.17/main.cpp)  
错误信息：
```
C:\Users\jz\Desktop\1.cpp(9): error C2259: “Disc_quote”: 不能实例化抽象类
C:\Users\jz\Desktop\1.cpp(9): note: 由于下列成员:
C:\Users\jz\Desktop\1.cpp(9): note: “double Disc_quote::net_price(std::size_t) const”: 是抽象的
c:\users\jz\desktop\Quote.h(32): note: 参见“Disc_quote::net_price”的声明
```

* **练习15.18**  
