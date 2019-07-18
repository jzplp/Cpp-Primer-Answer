* **练习13.1**  
拷贝构造函数是类进行拷贝初始化时使用的构造函数。

* **练习13.2**  
对于该构造函数的调用会造成无限循环。

* **练习13.3**  
拷贝一个StrBlob时，拷贝了智能指针  
拷贝一个StrBlobPtr时，拷贝了智能指针和size_t类型

* **练习13.4**  
1. 这个函数被调用时
2. local初始化时 
3. new一个指针时  
答案书中没有写这条，这条可能会调用，也可能不会调用。但即使调用，也可能是调用的拷贝构造函数进行的直接初始化，并不是拷贝初始化  
4. *heap赋值时（拷贝赋值运算符）
5. pa数组初始化时，调用了2次  
6. return语句调用1次

* **练习13.5**  
[13.5 HasPtr类 程序代码](13.5.cpp)  

* **练习13.6**  
拷贝赋值运算符是控制类对象拷贝时候的的函数  
在对象赋值的时候使用  
如果类未定义拷贝复制运算符时，编译器会生成一个合成的  

* **练习13.7**  
与调用拷贝构造函数类似，拷贝一个StrBlob时，拷贝了智能指针  
拷贝一个StrBlobPtr时，拷贝了智能指针和size_t类型  

* **练习13.8**  
添加了拷贝赋值运算符  
[13.8 HasPtr类 程序代码](13.8.cpp)  

* **练习13.9**  
析构函数是在类对象销毁时执行的函数。  
合成的析构函数一般用来销毁类对象内的对象。  
如果类未定义自己的析构函数，编译器会合成一个。  

* **练习13.10**  
销毁StrBlob对象：销毁一个shared_ptr对象。  
销毁StrBlobPtr对象：销毁一个weak_ptr对象和size_t对象。  

* **练习13.11**  
添加了析构函数  
[13.11 HasPtr类 程序代码](13.11.cpp)  

* **练习13.12**  
1. accum销毁
2. item1销毁
3. item2销毁  
3次析构函数调用

* **练习13.13**  
[13.13程序代码](13.13.cpp)  

* **练习13.14**  
输出相同的序号

* **练习13.15**  
会改变上一题中的输出结果，但是并不是我们想要的a，b，c的序号

* **练习13.16**  
会改变输出结果，改成了我们想要的a，b，c的序号

* **练习13.17**  
[13.17 numbered类 13.14合成的拷贝构造函数程序代码](13.17/numbered_syn.cpp)  
[13.17 numbered类 13.15自定义拷贝构造函数程序代码](13.17/numbered_copyCon.cpp)  
[13.17 numbered类 13.16引用参数f函数程序代码](13.17/numbered_referFun.cpp)  

* **练习13.18**  
[13.18 Employee类 程序代码](13.18.cpp)  

* **练习13.19**  
我认为Employee类应该禁止拷贝。因为员工是唯一的，复制是没有意义的。  
[13.19 Employee类 程序代码](13.19.cpp)  

* **练习13.20**  
TextQuery参照书上的使用vector的，12章进行添加后的版本    
TextQuery类  
拷贝：拷贝一个shared_ptr和一个map  
赋值：赋值一个shared_ptr和一个map  
销毁：默认销毁一个shared_ptr和一个map  
QueryResult类  
拷贝：拷贝2个shared_ptr和一个string  
赋值：赋值2个shared_ptr和一个string  
销毁：默认销毁2个shared_ptr和一个string  

* **练习13.21**  
TextQuery参照书上的使用vector的，12章进行添加后的版本  
TextQuery类和QueryResult类中的指针成员都是智能指针，依赖于合成的操作即可正常使用。因此不需要定义拷贝控制成员。  
main.cpp仅用于本题测试  
[13.21 TextQuery.h程序代码](13.21/TextQuery.h)  
[13.21 TextQuery.cpp程序代码](13.21/TextQuery.cpp)  
[13.21 测试程序代码](13.21/main.cpp)  

* **练习13.22**  
使用之前练习中的代码，即可让HasPtr类具有值行为  
[13.11 HasPtr类 程序代码](13.11.cpp)  

* **练习13.23**  
之前自己编写的拷贝赋值运算符是错误的  
这一节是书上的HasPtr类 具有值行为的版本  
[13.23 HasPtr类 程序代码](13.23.cpp)  

* **练习13.24**  
如果未定义析构函数，ps指针指向的资源将不能释放  
如果未定义拷贝构造函数，新对象的ps指针和原对象的ps指针指向的是相同的资源  

* **练习13.25**  
对于shared_ptr指针中的内容需要复制一份。
因为shared_ptr指针会自动释放资源，因此不需要自定义析构函数

* **练习13.26**  
[13.26 添加了拷贝赋值成员的 StrBlob.h程序代码](13.26/StrBlob.h)  
[13.26 添加了拷贝赋值成员的 StrBlob.cpp程序代码](13.26/StrBlob.cpp)  
[13.26 测试程序代码](13.26/main.cpp)  

* **练习13.27**  
书上的HasPtr类 具有指针行为的版本  
[13.27 HasPtr类 程序代码](13.27.cpp)  

* **练习13.28**  
书上的定义有些不好，count应该是指针类型，下面代码改为指针   
[13.28 BinStrTree类 程序代码](13.28.cpp)  

* **练习13.29**  
swap是重载的，里面的swap并不是调用的外面的那个，不存在递归。

* **练习13.30**  
HasPtr类 具有指针行为的版本  
[13.30 添加了swap函数的 HasPtr类 程序代码](13.30.cpp)  

* **练习13.31**   
HasPtr类 具有类值行为的版本  
[13.31 重载了小于运算符的 HasPtr类 程序代码](13.31/HasPtr.h)  
[13.31 vector和sort测试程序代码](13.31/main.cpp)  

* **练习13.32**  
不会受益。因为本质上就是指针交换，没有新增空间来存放对象。

* **练习13.33**  
如果参数是Folder，那么相当于新建立了一个临时的Folder副本并把副本的指针添加了。但是函数结束后，这个副本就被销毁了，因此Message就访问不到这个Folder了。  
因为要改变Folder的内容，因此不能是const的  

* **练习13.34**  
Message类 书上的版本，缺少Folder类，不能执行（因此可能有错误）  
[13.34 Message.h 程序代码](13.34/Message.h)  
[13.34 Message.cpp 程序代码](13.34/Message.cpp)  

* **练习13.35**  
Folder类中将不能更新Message的状态，Folder类将指向错误的Message类  

* **练习13.36**  
Message类 书上的版本，添加了自定义的Folder类，添加了显示内容的函数。  
为了实现Folder类的拷贝控制操作，添加了13.37题目要求的代码  
[13.36 Message.h 程序代码](13.36/Message.h)  
[13.36 Message.cpp 程序代码](13.36/Message.cpp)  
[13.36 测试程序代码](13.36/main.cpp)  

* **练习13.37**  
函数已经在13.36的代码中实现  
[13.36 Message.h 程序代码](13.36/Message.h)  
[13.36 Message.cpp 程序代码](13.36/Message.cpp)  
[13.36 测试程序代码](13.36/main.cpp)  

* **练习13.38**  
拷贝时会新生成一个临时对象，在folders包含的Folder中都复制一次，然后交换操作又要双方都删除再添加一次。最后还要销毁临时对象，再删除一次。  
因此效率低下，不如直接用拷贝赋值运算符。

* **练习13.39**  
StrVec类 书上的版本。  
自己编写了reserve和resize函数，并修改了书上reallocate函数操作，委托reserve函数执行。  
[13.39 StrVec.h 程序代码](13.39/StrVec.h)  
[13.36 StrVec.cpp 程序代码](13.39/StrVec.cpp)  
[13.39 测试程序代码](13.39/main.cpp)  

* **练习13.40**  
StrVec类 书上的版本。  
自己编写了initializer_list的构造函数  
[13.40 StrVec.h 程序代码](13.40/StrVec.h)  
[13.40 StrVec.cpp 程序代码](13.40/StrVec.cpp)  
[13.40 测试程序代码](13.40/main.cpp)  

* **练习13.41**  
如果使用前置递增运算符，每次添加时会隔开一个未构造的元素  

* **练习13.42**  
StrVec类 书上的，经过前面的题目改写后的版本。  
TextQuery类 书上的，经过前面的题目改写后的版本。  
TextQuery中vector用StrVec类代替  
[13.42 TextQuery.h程序代码](13.42/TextQuery.h)  
[13.42 TextQuery.cpp程序代码](13.42/TextQuery.cpp)  
[13.42 StrVec.h 程序代码](13.42/StrVec.h)  
[13.42 StrVec.cpp 程序代码](13.42/StrVec.cpp)  
[13.42 测试程序代码](13.42/main.cpp)  

* **练习13.43**  
StrVec类 书上的，经过前面的题目改写后的版本。   
用for_each和lambda改写了free成员函数  
[13.43 StrVec.h 程序代码](13.43/StrVec.h)  
[13.43 StrVec.cpp 程序代码](13.43/StrVec.cpp)  
[13.43 测试程序代码](13.43/main.cpp)  

* **练习13.44**  
String类 自己定义  
模仿书上的StrVec类  
[13.44 String.h 程序代码](13.44/String.h)  
[13.44 String.cpp 程序代码](13.44/String.cpp)  
[13.44 测试程序代码](13.44/main.cpp)  

* **练习13.45**  
左值引用：引用对象的身份  
右值引用：引用对象的值，制能绑定到临时对象，要被销毁的  

* **练习13.46**  
```
r1 : &&
r2 : &
r3 : &
r4 : &&
```

* **练习13.47**  
String类 自己定义 模仿书上的StrVec类  
只在拷贝构造函数和拷贝控制运算符添加了输出语句  
[13.47 String.h 程序代码](13.47/String.h)  
[13.47 String.cpp 程序代码](13.47/String.cpp)  
[13.47 测试程序代码](13.47/main.cpp)  

* **练习13.48**  
String类 自己定义 模仿书上的StrVec类  
利用上一题添加了输出语句的程序，只更改了main.cpp  
[13.48 String.h 程序代码](13.48/String.h)  
[13.48 String.cpp 程序代码](13.48/String.cpp)  
[13.48 测试程序代码](13.48/main.cpp)  
push_back了三次，运行结果为：  
```
String(const String & s)

String(const String & s)
String(const String & s)

String(const String & s)
String(const String & s)
String(const String & s)
```

* **练习13.49**  
StrVec类 书上的版本  
增加了书上版本的移动构造函数和移动赋值运算符  
[13.49 StrVec.h 程序代码](13.49/StrVec/StrVec.h)  
[13.49 StrVec.cpp 程序代码](13.49/StrVec/StrVec.cpp)  
[13.49 测试程序代码](13.49/StrVec/main.cpp)  
String类 自己定义 模仿书上的StrVec类  
增加了移动构造函数和移动赋值运算符  
[13.49 String.h 程序代码](13.49/String/String.h)  
[13.49 String.cpp 程序代码](13.49/String/String.cpp)  
[13.49 测试程序代码](13.49/String/main.cpp)  
Message类 书上的版本 Folder类自己定义的版本(书上无定义)    
Message类和Folder类增加了移动构造函数和移动赋值运算符  
[13.49 Message.h 程序代码](13.49/Message/Message.h)  
[13.49 Message.cpp 程序代码](13.49/Message/Message.cpp)  
[13.49 测试程序代码](13.49/Message/main.cpp)  

* **练习13.50**  

