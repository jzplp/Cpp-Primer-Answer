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


