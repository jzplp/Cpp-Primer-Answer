* **练习14.1**  
重载的运算符和内置运算符在对象求值顺序和短路求值属性上不同。  
在优先级和结合律，运算对象的数量上相同。  

* **练习14.2**  
Sales_data类 书上的版本  
添加了重载的输入，输出，加法和复合赋值运算符  
[14.2 Sales_data.h程序代码](14.2/Sales_data.h)  
[14.2 Sales_data.cpp程序代码](14.2/Sales_data.cpp)  
[14.2 测试程序代码](14.2/main.cpp)  

* **练习14.3**  
(a) 使用const char * 的  
(b) 使用string的  
(c) 使用vector的，在vector内部使用string的  
(d) 使用string的  

* **练习14.4**  
(a) 非成员  
(b) 成员  
(c) 成员  
(d) 成员  
(e) 非成员  
(f) 非成员  
(g) 非成员  
(h) 成员  

* **练习14.5**  
Tree类 自己的简单版本（始于7.40题）  
增加了重载的==运算符  
[14.5 Tree.h程序代码](14.5/Tree.h)  
[14.5 测试程序代码](14.5/main.cpp)  

* **练习14.6**  
Sales_data类 书上的版本  
函数已经在14.2的代码中实现  
[14.2 Sales_data.h程序代码](14.2/Sales_data.h)  
[14.2 Sales_data.cpp程序代码](14.2/Sales_data.cpp)  
[14.2 测试程序代码](14.2/main.cpp)  

* **练习14.7**  
String类 自己定义 模仿书上的StrVec类  
增加了重载的输出运算符  
[14.7 String.h 程序代码](14.7/String.h)  
[14.7 String.cpp 程序代码](14.7/String.cpp)  
[14.7 测试程序代码](14.7/main.cpp)  

* **练习14.8**  
Tree类 自己的简单版本（始于7.40题）  
增加了重载的输出运算符  
[14.8 Tree.h程序代码](14.8/Tree.h)  
[14.8 测试程序代码](14.8/main.cpp)  

* **练习14.9**  
Sales_data类 书上的版本  
更改为了书上版本的重载输入运算符  
[14.9 Sales_data.h程序代码](14.9/Sales_data.h)  
[14.9 Sales_data.cpp程序代码](14.9/Sales_data.cpp)  
[14.9 测试程序代码](14.9/main.cpp)  

* **练习14.10**  
(a) 正常读取  
(b) 非正常读取，把书单价设置为了0.95  
（经测试与答案书上结果不同，.95被成功输入为了0.95）

* **练习14.11**  
存在错误  
(a) 正常读取  
(b) 非正常读取，把书单价设置为了0.95  

* **练习14.12**  
Tree类 自己的简单版本（始于7.40题）  
增加了重载的输入运算符  
[14.12 Tree.h程序代码](14.12/Tree.h)  
[14.12 测试程序代码](14.12/main.cpp)  

* **练习14.13**  
目前没有想到

* **练习14.14**  
1. 这样在操作上可行，是可以正常运行的
2. +=和+在逻辑上是类似的运算符，具体的操作也是大部分相同的，如果利用+=来定义+，这样避免了重复定义操作。

* **练习14.15**  
不应该，因为树不应该含有加减乘除等操作  

* **练习14.16**  
Sales_data类 书上的版本（题目未要求）  
增加了书上版本的重载相等性运算符  
[14.16 Sales_data.h程序代码](14.16/Sales_data/Sales_data.h)  
[14.16 Sales_data.cpp程序代码](14.16/Sales_data/Sales_data.cpp)  
[14.16 仅本题测试程序代码](14.16/Sales_data/main.cpp)  
StrBlob类 增加了重载相等性运算符  
[14.16 StrBlob.h程序代码](14.16/StrBlob/StrBlob.h)  
[14.16 StrBlob.cpp程序代码](14.16/StrBlob/StrBlob.cpp)  
[14.16 测试程序代码](14.16/StrBlob/main.cpp)  
StrVec类 书上的版本   
增加了重载相等性运算符    
[14.16 StrVec.h 程序代码](14.16/StrVec/StrVec.h)  
[14.16 StrVec.cpp 程序代码](14.16/StrVec/StrVec.cpp)  
[14.16 测试程序代码](14.16/StrVec/main.cpp)  
String类 自己定义 模仿书上的StrVec类  
增加了重载相等性运算符  
[14.16 String.h 程序代码](14.16/String/String.h)  
[14.16 String.cpp 程序代码](14.16/String/String.cpp)  
[14.16 测试程序代码](14.16/String/main.cpp)  

* **练习14.17**  
Tree类 自己的简单版本（始于7.40题）  
增加了重载的相等性运算符  
[14.17 Tree.h程序代码](14.17/Tree.h)  
[14.17 测试程序代码](14.17/main.cpp)  

* **练习14.18**  
StrBlob类  
增加了重载关系运算符 改写了重载相等性运算符  
[14.18 StrBlob.h程序代码](14.18/StrBlob/StrBlob.h)  
[14.18 StrBlob.cpp程序代码](14.18/StrBlob/StrBlob.cpp)  
[14.18 测试程序代码](14.18/StrBlob/main.cpp)  
StrVec类 书上的版本   
增加了重载关系运算符    
[14.18 StrVec.h 程序代码](14.18/StrVec/StrVec.h)  
[14.18 StrVec.cpp 程序代码](14.18/StrVec/StrVec.cpp)  
[14.18 测试程序代码](14.18/StrVec/main.cpp)  
String类 自己定义 模仿书上的StrVec类  
增加了重载关系运算符    
[14.18 String.h 程序代码](14.18/String/String.h)  
[14.18 String.cpp 程序代码](14.18/String/String.cpp)  
[14.18 测试程序代码](14.18/String/main.cpp)  

* **练习14.19**  
不应该，因为树不应该含有关系运算符   

* **练习14.20**  
Sales_data类 书上的版本  
加法运算符已经在之前实现了  
[14.16 Sales_data.h程序代码](14.16/Sales_data/Sales_data.h)  
[14.16 Sales_data.cpp程序代码](14.16/Sales_data/Sales_data.cpp)  
[14.9 测试程序代码](14.9/main.cpp)  

* **练习14.21**  
Sales_data类 本题代码后续不应采用  
较差版本的加法运算符  
+运算符执行实际的加法操作，而+=调用+，这样会造成定义额外的局部变量，造成额外的资源消耗  
[14.21 Sales_data.h程序代码](14.21/Sales_data.h)  
[14.21 Sales_data.cpp程序代码](14.21/Sales_data.cpp)  
[14.21 测试程序代码](14.21/main.cpp)  

* **练习14.22**  
Sales_data类 书上的版本  
增加了参数为string的赋值运算符  
[14.22 Sales_data.h程序代码](14.22/Sales_data.h)  
[14.22 Sales_data.cpp程序代码](14.22/Sales_data.cpp)  
[14.22 仅本题测试程序代码](14.22/main.cpp)  

* **练习14.23**  
StrVec类 书上的版本   
增加了重载花括号列表赋值运算符    
[14.23 StrVec.h 程序代码](14.23/StrVec.h)  
[14.23 StrVec.cpp 程序代码](14.23/StrVec.cpp)  
[14.23 测试程序代码](14.23/main.cpp)  

* **练习14.24**  
不应该。

* **练习14.25**  
不应定义其它赋值运算符。(我偷懒了)

* **练习14.26**  
StrBlob类  
为StrBlob类，StrBlobPtr类，ConstStrBlobPtr类增加了下标运算符  
[14.26 StrBlob.h程序代码](14.26/StrBlob/StrBlob.h)  
[14.26 StrBlob.cpp程序代码](14.26/StrBlob/StrBlob.cpp)  
[14.26 测试程序代码](14.26/StrBlob/main.cpp)  
StrVec类 书上的版本   
增加了下标运算符  
[14.26 StrVec.h 程序代码](14.26/StrVec/StrVec.h)  
[14.26 StrVec.cpp 程序代码](14.26/StrVec/StrVec.cpp)  
[14.26 测试程序代码](14.26/StrVec/main.cpp)  
String类 自己定义 模仿书上的StrVec类  
增加了下标运算符  
[14.26 String.h 程序代码](14.26/String/String.h)  
[14.26 String.cpp 程序代码](14.26/String/String.cpp)  
[14.26 测试程序代码](14.26/String/main.cpp)  

* **练习14.27**  
StrBlob类  
为StrBlobPtr类，ConstStrBlobPtr类增加了递增递减运算符  
[14.27 StrBlob.h程序代码](14.27/StrBlob.h)  
[14.27 StrBlob.cpp程序代码](14.27/StrBlob.cpp)  
[14.27 测试程序代码](14.27/main.cpp)  

* **练习14.28**  
StrBlob类  
为StrBlobPtr类，ConstStrBlobPtr类增加了各类加减运算符  
[14.28 StrBlob.h程序代码](14.28/StrBlob.h)  
[14.28 StrBlob.cpp程序代码](14.28/StrBlob.cpp)  
[14.28 测试程序代码](14.28/main.cpp)  

* **练习14.29**  
因为递增和递减运算符需要改变类对象，因此const类对象不能进行这种操作

* **练习14.30**  
StrBlob类  
为StrBlobPtr类，ConstStrBlobPtr类增加了解引用和箭头运算符  
[14.30 StrBlob.h程序代码](14.30/StrBlob.h)  
[14.30 StrBlob.cpp程序代码](14.30/StrBlob.cpp)  
[14.30 测试程序代码](14.30/main.cpp)  

* **练习14.31**  
StrBlobPtr和ConstStrBlobPtr因为weak_ptr只是对指针的弱引用，因此直接销毁不影响指针引用的对象，而且可以随便复制。
所以拷贝构造函数，拷贝复制运算符，析构函数依赖于合成的版本即可  

* **练习14.32**  
StrBlob类 仅更改了测试代码  
[14.32 StrBlob.h程序代码](14.32/StrBlob.h)  
[14.32 StrBlob.cpp程序代码](14.32/StrBlob.cpp)  
[14.32 新建类测试程序代码](14.32/main.cpp)  

* **练习14.33**  
有一个默认的类对象this实参，其他的任意  

* **练习14.34**  
重载了函数调用运算符的if-then-else类  
[14.34 程序代码](14.34.cpp)  

* **练习14.35**  
自己定义的InputString类 仿照书上的PrintString类  
[14.35 程序代码](14.35.cpp)  

* **练习14.36**  
自己定义的InputString类 仿照书上的PrintString类  
只更改了测试代码  
[14.36 程序代码](14.36.cpp)  

* **练习14.37**  
检查相等类  
[14.37 程序代码](14.37.cpp)  

* **练习14.38**  
[14.38 程序代码](14.38.cpp)  

* **练习14.39**  
[14.39 程序代码](14.39.cpp)  

* **练习14.40**  
biggies函数 用函数对象类代替lambda  
[14.40 程序代码](14.40.cpp)  

* **练习14.41**  
因为lambda编写方便，对于小函数很好用  
如果需要保存状态，或者是处理复杂，可以使用函数对象类

* **练习14.42**  
```
(a)
std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, 1024));
(b)
std::find_not_if(v.begin(), v.end(), std::bind(std::equal_to<std::string>(), std::placeholders::_1, "pooh"));
(c)
std::tranform(v.begin(), v.end(), v.begin(), std::bind(std::multiplies<int>(),std::placeholders::_1, 2));
```

* **练习14.43**  
[14.43 程序代码](14.43.cpp)  

* **练习14.44**  
[14.44 简单的二元运算计算器 程序代码](14.44.cpp)  

* **练习14.45**  
Sales_data类 书上的版本  
增加了转换为string和double的类型转换运算符  
[14.45 Sales_data.h程序代码](14.45/Sales_data.h)  
[14.45 Sales_data.cpp程序代码](14.45/Sales_data.cpp)  
[14.45 仅本题测试程序代码](14.45/main.cpp)  

* **练习14.46**  
应该定义，但是必须声明成explicit的。如果是隐式的，可能会造成意外结果  

* **练习14.47**  
```
operator const int();
转换为const int类型，并且只能是非常量类对象才能使用
operator int() const;
转换为int类型，常量和非常量类对象都可以使用
```

* **练习14.48**  
可以定义，但是必须是explicit的，否则可能造成意外结果  

* **练习14.49**  
Tree类 自己的简单版本（始于7.40题）  
增加了转换为bool的类型转换运算符  
[14.49 Tree.h程序代码](14.49/Tree.h)  
[14.49 测试程序代码](14.49/main.cpp)  

* **练习14.50**  
```
ex1: 初始化错误  
1. LongDouble转换为double，double转换为int  
2. LongDouble转换为float，float转换为int  
ex2: 初始化正确  
LongDouble到float
```

* **练习14.51**  
```
可能的类型转换序列：  
1. double转换为LongDouble， 调用void calc(LongDouble)  
2. double转换为int，调用void calc(int)  
最佳可行函数为2，因为通过算术类型的转化比类类型转换的等级要高  
```

* **练习14.52**  
```
ld = si + ld;  
1. SmallInt转换为int，LongDouble转换为double，double转换为int，调用int的加法  
2. SmallInt转换为int，LongDouble转换为float，float转换为int，调用int的加法  
3. SmallInt转换为int，int转换为double，LongDouble转换为double，调用double的加法  
没有哪种方式明确的优于另外的几种，因此会发生错误  

ld = si + ld;  
1. SmallInt转换为int，int转换为double， 调用LongDoule operator+(LongDouble&, double)
2. LongDouble转换为double，SmallInt转换为int，int转换为double，调用double的加法  
3. LongDouble转换为double，double转换为int，SmallInt转换为int，调用int的加法  
4. LongDouble转换为float，float转换为int，SmallInt转换为int，调用int的加法  
5. 调用LongDouble LongDouble::operator(const SmallInt&)
第5种不需要转换，优于其他几种
```

* **练习14.53**  
```
不合法，会产生二义性
1. s1转换为int，int转换为double，调用double的加法  
2. double转换为int，int转换为SmallInt，调用SmallInt SmallInt::operator(const SmallInt&, const SmallInt&)
修改的方式有很多种，其中一种为：
double d = int(s1) + 3.14;
```
