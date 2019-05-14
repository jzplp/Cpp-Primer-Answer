* **练习2.1**  
位数不同，能表示的整数范围大小不同。  
无符号类型只能表示大于等于0的数。有符号则也可以表示小于0的数。  
float和double位数不同，能表示的浮点数精度和范围不同。  

* **练习2.2**  
利率： 浮点数，比如float  
本金： 整数，比如int  
付款： 浮点数，比如double  
因为利率一般都不是整数，本金是整数，最后的付款可能也不是整数。  

* **练习2.3**  
输出结果为：  
32  
MAX-32  
32  
-32  
0  
0  
其中 MAX是int类型的最大值+1。

* **练习2.4**  
[2.4程序代码](2.4.cpp)   
结果证明2.3的估计正确。

* **练习2.5**  
```
(a)
'a'     char
L'a'    wchar_t
"a"     char数组
L"a"    wchar_t数组
(b)
10      int
10u     unsigned int
10L     long
10uL    unsigned long
012     八进制int
0xC     16进制int
(c)
3.14    double
3.14f   float
3.14L   long double
(d)
10      int
10u     unsigned int
10.     double
10e-2   double
```  

* **练习2.6**  
有区别。  
9并不是8进制中的数字，所以09会发生编译错误。

* **练习2.7**  
(a)  
含义： "What goes with Fergus? \n"  
类型：char数组  
(b)  
含义： 31.4  
类型：long double  
(c)  
含义： 1024.0  
类型：float  
(d)  
含义： 3.14  
类型：long double  

* **练习2.8**  
[2.8程序代码](2.8.cpp)  

* **练习2.9**  
(a) 不能对定义语句进行运算操作。  
改正：
```
int input_value;
std::cin >> input_value;
```
(b) 错误，花括号的初始化形式不支持丢失信息的初始化。  
改正：
```
int i = (3.14);
```
(c) 如果wage之前已经定义，则正确，如果未定义则错误。  
改正：
```
double wage = 9999.99 , salary = wage;
```

(d) 正确，但是会损失小数部分。

* **练习2.10**  
global_str 初值 空字符串  
global_int 初值 0  
local_int 初值 未定义  
local_str 初值 空字符串

* **练习2.11**  
(a) 定义 (b) 定义 (c) 声明 

* **练习2.12**  
(a) 非法 (b) 合法 (c) 非法 (d) 非法 (e) 合法 