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
```
Base *p = &d1;
合法
p = &d2;
不合法
p = &d3;
不合法
p = &dd1;
合法
p = &dd2;
不合法
p = &dd3;
不合法
```

* **练习15.19**  
Base 合法  
Pub_Derv 合法  
Priv_Derv 合法  
Derived_from_Public 合法  
Derived_from_Private 不合法  
Derived_from_Protect 合法  

* **练习15.20**  
[15.20 程序代码](15.20.cpp)  
15.18和15.19测试代码 测试回答正确  

* **练习15.21**  
选择(b)

* **练习15.22**  
实现了15.21的类继承体系  
[15.22 Graphic.h程序代码](15.22/Graphic.h)  
[15.22 Graphic.cpp程序代码](15.22/Graphic.cpp)  
[15.22 测试程序代码](15.22/main.cpp)  

* **练习15.23**  
```
class D1 : public Base
{
public:
    using Base::int;
    int fcn(int);
    virtual void f2();
};
```
本节的调用语句没有变化  

* **练习15.24**  
基类需要虚析构函数，在动态绑定时执行正确的版本  

* **练习15.25**  
因为它的派生类初始化时需要用到Disc_quote的构造函数，如果不定义默认构造函数，它的派生类也无法默认初始化。
Quote类 书上的版本  
增加了默认的拷贝控制成员 非题目要求  
[15.25 Quote.h程序代码](15.25/Quote.h)  
[15.25 Quote.cpp程序代码](15.25/Quote.cpp)  
[15.25 测试程序代码](15.25/main.cpp)  

* **练习15.26**  
Quote类 书上的版本  
增加了自定义的拷贝控制成员和对应的输出测试 仅本题使用  
[15.26 Quote.h程序代码](15.26/Quote.h)  
[15.26 Quote.cpp程序代码](15.26/Quote.cpp)  
[15.26 测试程序代码](15.26/main.cpp)  

* **练习15.27**  
Quote类 自定义的拷贝控制成员和对应的输出的版本  
增加了继承构造函数 仅本题使用  
[15.27 Quote.h程序代码](15.27/Quote.h)  
[15.27 Quote.cpp程序代码](15.27/Quote.cpp)  
[15.27 测试程序代码](15.27/main.cpp)  

* **练习15.28**  
Quote类 书上的版本  
仅更改了测试代码   
[15.28 Quote.h程序代码](15.28/Quote.h)  
[15.28 Quote.cpp程序代码](15.28/Quote.cpp)  
[15.28 测试程序代码](15.28/main.cpp)  

* **练习15.29**  
Quote类 书上的版本  
仅更改了测试代码   
[15.29 Quote.h程序代码](15.29/Quote.h)  
[15.29 Quote.cpp程序代码](15.29/Quote.cpp)  
[15.29 测试程序代码](15.29/main.cpp)  
不一致，因为智能指针进行了动态绑定  

* **练习15.30**  
Quote类 书上的版本  
增加了Basket类   
[15.30 Quote.h程序代码](15.30/Quote.h)  
[15.30 Quote.cpp程序代码](15.30/Quote.cpp)  
[15.30 测试程序代码](15.30/main.cpp)  

* **练习15.31**  
仅为示意
(a) WordQuery(s1) WordQuery(s2) WordQuery(s3) OrQuery(s1, s2 & ~s3) NotQuery(s3) AndQuery(s2, ~s3)  
(b) WordQuery(s1) WordQuery(s2) WordQuery(s3) OrQuery(s1, s2 & ~s3) NotQuery(s3) AndQuery(s2, ~s3)  
(c) WordQuery(s1) WordQuery(s2) WordQuery(s3) WordQuery(s4) AndQuery(s1, s2) AndQuery(s3, s4) OrQuery(s1 & s2, s3 & s4)  

* **练习15.32**  
拷贝，移动，赋值，销毁一个shared_ptr的指针  

* **练习15.33**  
Query_base无数据成员，仅拷贝，移动，赋值，销毁类本身  

* **练习15.34**  
```
(a)
Query(const std::string &);
Query_base();
WordQuery(const std::string &);
BinaryQuery(const Query &l, const Query &r, std::strin s);
AndQuery(const Query &left, const Query &right);
OrQuery(const Query &left, const Query &right);
(b)
Query::rep
WordQuery::rep
AndQuery::rep
OrQuery::rep
(c)
Query::eval
WordQuery::eval
AndQuery::eval
OrQuery::eval
```

* **练习15.35**  
TextQuery类 书上的版本  
Query和继承类 书上的版本  
未定义的eval用了无意义的内容代替  
[15.35 TextQuery.h程序代码](15.35/TextQuery.h)  
[15.35 TextQuery.cpp程序代码](15.35/TextQuery.cpp)  
[15.35 Query.h程序代码](15.35/Query.h)  
[15.35 Query.cpp程序代码](15.35/Query.cpp)  
[15.35 测试程序代码](15.35/main.cpp)  

* **练习15.36**  

