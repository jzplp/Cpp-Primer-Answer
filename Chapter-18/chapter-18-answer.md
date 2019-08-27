* **练习18.1**  
(a) range_error  
(b) exception  
改写(b) exception *  

* **练习18.2**  
vector正常析构，文件正常关闭，但是指针p指向的内容不会被释放  

* **练习18.3**  
```
方法1 : 用一个类封装起来  
class pointerArr
{
public:
    void pointerArr(int * pt) : p(pt) { }
    ~pointerArr() { delete [] p; }
private:
    int * p;
}
void exercise(int * b, int * e)
{
    vector<int> v(b, e);
    pointerArr p = new int[v.size()];
    ifstream in("ints");
}

方法2 : 在本函数内进行处理  
void exercise(int * b, int * e)
{
    int *p =new int[v.size()];
    try
    {
        vector<int> v(b, e);
        ifstream in("ints");
    }
    catch(someErr r)
    {
        delete [] p;
    }
    
}
```

* **练习18.4**  
基类会匹配了派生类的所有类型，下面的catch永远不会被匹配  
```
try
{
    //...
}catch(overflow_error eobj)
{ //... }
catch(const runtime_error & re)
{ //... }
catch(exception)
{ //... }
```

* **练习18.5**  
```
int main()
{
    try
    {
        //...
    }catch(const runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
        abort();
    }
    catch(const logic_error &e)
    {
        std::cerr << e.what() << std::endl;
        abort();
    }
    catch(exception &e)
    {
        std::cerr << "error!" << std::endl;
        abort();
    }
}
```

* **练习18.6**  
```
(a) throw new exceptionType();
(b) 任何正确的throw表达式都能被捕获
(c) throw 3;
```

* **练习18.7**  
Blob类 书上的版本  
实现了构造函数try语句块  
[18.7 Blob.h程序代码](18.7/Blob.h)  
[18.7 测试程序代码](18.7/main.cpp)  

* **练习18.8**  
Sales_data类 书上的版本  
增加了noexcept说明  
测试代码仅本题使用  
[18.8 Sales_data.h程序代码](18.8/Sales_data/Sales_data.h)  
[18.8 Sales_data.cpp程序代码](18.8/Sales_data/Sales_data.cpp)  
[18.8 测试程序代码](18.8/Sales_data/main.cpp)  
shared_ptr2类  
模仿标准库的shared_ptr，自己实现  
增加了noexcept说明  
[18.8 shared_ptr2.h程序代码](18.8/shared_ptr2/shared_ptr2.h)  
[18.8 DebugDelete.h程序代码](18.8/shared_ptr2/DebugDelete.h)  
[18.8 测试程序代码](18.8/shared_ptr2/main.cpp)  
Vec类  
增加了noexcept说明  
[18.8 Vec.h程序代码](18.8/Vec/Vec.h)  
[18.8 测试程序代码](18.8/Vec/main.cpp)  
unique_ptr2类  
模仿标准库的unique_ptr，自己实现  
增加了noexcept说明  
[18.8 unique_ptr2.h程序代码](18.8/unique_ptr2/unique_ptr2.h)  
[18.8 DebugDelete.h程序代码](18.8/unique_ptr2/DebugDelete.h)  
[18.8 测试程序代码](18.8/unique_ptr2/main.cpp)  
Blob类 书上的版本  
增加了noexcept说明  
[18.8 Blob.h程序代码](18.8/Blob/Blob.h)  
[18.8 测试程序代码](18.8/Blob/main.cpp)  
TextQuery类 书上的版本  
Query和继承类 书上的版本  
增加了noexcept说明  
[18.8 TextQuery.h程序代码](18.8/Query/TextQuery.h)  
[18.8 TextQuery.cpp程序代码](18.8/Query/TextQuery.cpp)  
[18.8 Query.h程序代码](18.8/Query/Query.h)  
[18.8 Query.cpp程序代码](18.8/Query/Query.cpp)  
[18.8 测试程序代码](18.8/Query/main.cpp)  
Quote类 书上的版本  
增加了noexcept说明  
[18.8 Quote.h程序代码](18.8/Quote/Quote.h)  
[18.8 Quote.cpp程序代码](18.8/Quote/Quote.cpp)  
[18.8 测试程序代码](18.8/Quote/main.cpp)  
String类 自己定义 模仿书上的StrVec类  
增加了noexcept说明  
[18.8 String.h 程序代码](18.8/String/String.h)  
[18.8 String.cpp 程序代码](18.8/String/String.cpp)  
[18.8 测试程序代码](18.8/String/main.cpp)  

* **练习18.9**  
Sales_data类 书上的版本  
增加了部分异常类和改写了+=运算符  
测试代码仅本题使用  
[18.9 Sales_data.h程序代码](18.9/Sales_data.h)  
[18.9 Sales_data.cpp程序代码](18.9/Sales_data.cpp)  
[18.9 测试程序代码](18.9/main.cpp)  

* **练习18.10**  
处理异常的版本见练习18.9  
Sales_data类 仅本题使用  
不处理异常的版本  
[18.10 Sales_data.h程序代码](18.10/Sales_data.h)  
[18.10 Sales_data.cpp程序代码](18.10/Sales_data.cpp)  
[18.10 测试程序代码](18.10/main.cpp)  
未被捕获异常，程序自动结束  

* **练习18.11**  
因为what函数一般在catch语句中使用，如果what函数引发了异常，那么前一个异常没有处理完毕，又来了新的异常，会很难处理  

* **练习18.12**  
TextQuery类 仅本题使用  
Query和继承类 仅本题使用  
增加了对应章的命名空间  
[18.12 TextQuery.h程序代码](18.12/TextQuery.h)  
[18.12 TextQuery.cpp程序代码](18.12/TextQuery.cpp)  
[18.12 Query.h程序代码](18.12/Query.h)  
[18.12 Query.cpp程序代码](18.12/Query.cpp)  
[18.12 测试程序代码](18.12/main.cpp)  

* **练习18.13**  
希望使用单个文件范围内的静态变量时，可以使用未命名的命名空间  

* **练习18.14**  
```
mathLib::MatrixLib::matrix mathLib::MatrixLib::matrix::operator*(const matrix &, const matrix &);
```

* **练习18.15**  
using指示是让命名空间整个暴露在当前作用域中。  
using声明仅仅让命名空间中的单个成员暴露在当前作用域中。  
还有更多细节的差别  

* **练习18.16**  
位置1出现using声明：  
出现命名冲突，ivar是一个当前作用域的变量，也是命名空间Exercise中的变量声明到当前作用域  
位置2出现using声明：  
出现命名冲突，dvar是一个当前作用域的变量，也是命名空间Exercise中的变量声明到当前作用域  
位置1出现using指示：  
manip函数中的++ivar出现调用的二义性，ivar是一个外层作用域的变量，也是命名空间Exercise中的变量指示到外层作用域  
位置2出现using指示：  
manip函数中的++ivar出现调用的二义性，ivar是一个外层作用域的变量，也是命名空间Exercise中的变量指示到外层作用域  

* **练习18.17**  
下面的代码都是测试错误的代码，仅本题使用  
位置1出现using声明：  
[18.17 using1测试程序代码](18.17/using1.cpp)  
错误信息：
```
[Error] 'ivar' is already declared in this scope
```
位置2出现using声明：  
[18.17 using2测试程序代码](18.17/using2.cpp)  
错误信息：
```
In function 'void manip()':
[Error] redeclaration of 'double dvar'
[Note] previous declaration 'double Exercise::dvar'
```
位置1出现using指示：  
[18.17 using3测试程序代码](18.17/using3.cpp)  
错误信息：
```
In function 'void manip()':
[Error] reference to 'ivar' is ambiguous
[Note] candidates are: int ivar
[Note] int Exercise::ivar
```
位置2出现using指示：  
[18.17 using4测试程序代码](18.17/using4.cpp)  
错误信息：
```
In function 'void manip()':
[Error] reference to 'ivar' is ambiguous
[Note] candidates are: int ivar
[Note] int Exercise::ivar
```
与上一题的回答一致  

* **练习18.18**  
使用std的版本，因为using声明，所以std::swap在本作用域中，而自定义的swap函数在外层作用域中，因此被隐藏了  

* **练习18.19**  
直接使用标准库的版本  

* **练习18.20**  
```
匹配的函数为：
void compute(int);
可行函数和对应的转换：
void primerLib::compute(const void *);
0 转换为 nullptr
void compute(int);
类型符合
void compute(double, double = 3.14);
int 转换为 double
void compute(char *, char * = 0);
0 转换为 nullptr

如果将using声明放到computer的调用点之前，那么候选函数只有：
void primerLib::compute(const void *);
0 转换为 nullptr
```

* **练习18.21**  
```
(a) CADVehicle类public继承CAD类，private继承Vehicle类  
(b) 错误，重复继承同一个类  
(c) iostream类public继承istream类，public继承ostream类  
```

* **练习18.22**  
按照执行完成的顺序：
```
A-B-C-X-Y-Z-MI
```

* **练习18.23**  
(a) 允许  
(b) 允许  
(c) 允许  
(d) 允许  

* **练习18.24**  
```
pb->print();
正确，调用Panda::print()
pb->cuddle();
错误
pb->highlight();
错误
delete pb;
正确，调用Panda::~Panda()
```

* **练习18.25**  
```
(a) MI::print()
(b) MI::print()
(c) MI::print()
(d) MI::~MI()
(e) MI::~MI()
(f) MI::~MI()
```

* **练习18.26**  
```
因为在MI的作用域中只找到void print(std::vector<double>)函数，因此参数类型不匹配。
MI中增加函数
void print(int i) const
{
    Base1::print(i);
}
```

* **练习18.27**  
```
不看成员函数
(a) 
函数作用域：
int dval
double cval
MI类作用域：
int * ival
std::vector<double> dvec
Derived类作用域：
string sval
Base1类作用域：
无
Base2类作用域：
double fval
剩下的名字应该都是隐藏不可见的  
(b)
不存在
(c)
dval = Base1::dval + Derived::dval;
(d)
假设MI::dvec的长度至少为1
Base2::fval = MI::dvec[MI::dvec.size() - 1];
(e)
Devired::sval = Base1::cval + Devired::sval; 
```

* **练习18.28**  
```
无需前缀限定符的：
Devired2::ival
void Devired1::bar()
需要前缀限定符的：
Base::ival
void Base::bar(int)
void Derived1::foo(char)
Derived1::cval
void Derived2::foo(int)
Derived2::cval
```

* **练习18.29**  
(a) 构造函数执行次序,按照结束的时间排序：  
Class, Base, D1, D2, MI, Class, Final  
析构函数执行次序,按照结束的时间排序：  
Final, MI, D1 D2 Base Class, Class
(b) 1个Base部分，2个Class部分  
(c) 
```
(a) 错误
(b) 正确  
(c) 正确  
(d) 正确  
```

* **练习18.30**  
[18.30 程序代码](18.30.cpp)  

