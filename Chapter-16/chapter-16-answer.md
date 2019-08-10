* **练习16.1**  
编译器使用实际的模板实参代替对应的模板参数来创建出模板的一个实例。

* **练习16.2**  
[16.2 程序代码](16.2.cpp)  

* **练习16.3**  
Sales_data类 书上的版本  
测试错误信息 仅本题使用  
[16.3 Sales_data.h程序代码](16.3/Sales_data.h)  
[16.3 Sales_data.cpp程序代码](16.3/Sales_data.cpp)  
[16.3 测试程序代码](16.3/main.cpp)  
错误信息为：
```
error C2678: 二进制“<”: 没有找到接受“const Sales_data”类型的左操作数的运算符(或没有可 接受的转换)
note: 可能是“内置 C++ operator<(double, double)”
note: 尝试匹配参数列表“(const Sales_data, const Sales_data)”时
note: 参见对正在编译的函数 模板 实例化“int compare<Sales_data>(const T &,const T &)”的 引用
        with
        [
            T=Sales_data
        ]
error C2678: 二进制“<”: 没有找到接受“const Sales_data”类型的左操作数的运算符(或没有可 接受的转换)
note: 可能是“内置 C++ operator<(double, double)”
note: 尝试匹配参数列表“(const Sales_data, const Sales_data)”时
```

* **练习16.4**  
[16.4 程序代码](16.4.cpp)  

* **练习16.5**  
[16.5 程序代码](16.5.cpp)  

* **练习16.6**  
[16.6 程序代码](16.6.cpp)  

* **练习16.7**  
[16.7 程序代码](16.7.cpp)  

* **练习16.8**  
因为!=仅需要判断对象是否相等，而<需要判断对象的大小关系，相等关系相对更容易定义，适用范围更广  

* **练习16.9**  
函数模板是用来生成针对不同类型的函数的模板。
类模板是用来生成针对不同类型的类的模板。

* **练习16.10**  
类模板被实例化时生成针对特定类型的类。

* **练习16.11**  
修改：
```
template<typename elemType> class ListItem;
template<typename elemType>
class List
{
public:
    List();
    List(const List &);
    List & operator=(const List &);
    ~List();
    void insert(ListItem<elemType> *ptr, elemType value);
private:
    ListItem<elemType> * front, * end;
};
```

* **练习16.12**  
Blob类 书上的版本  
实现了书上未定义的各种成员 也实现了ConstBlobPtr类模板  
[16.12 Blob.h程序代码](16.12/Blob.h)  
[16.12 测试程序代码](16.12/main.cpp)  

* **练习16.13**  
选择了建立对应类型示例的友好关系，因为同类型的类和相关成员是在操作上相关的，不同类型模板实例的是在操作上无关的。  

* **练习16.14**  
Screen类和Window_mgr类 书上的版本  
用类模板进行了重写并添加了重载的输入输出运算符  
[16.14 Screen.h程序代码](16.14/Screen.h)  
[16.14 测试程序代码](16.14/main.cpp)  

* **练习16.15**  
已经在练习16.14中添加  

* **练习16.16**  
Vec类  
由书上的StrVec类用类模板进行了重写  
[16.16 Vec.h程序代码](16.16/Vec.h)  
[16.16 测试程序代码](16.16/main.cpp)  

* **练习16.17**  
关键字class和typename在模板类型参数中含义相同，只不过typename出现时间较晚  

* **练习16.18**  
```
(a) 非法。修改：
template <typename T, typename U, typename V> void f1(T, U, V);
(b) 合法  
(c) 合法  
(d) 非法。修改：
template <typename T> void f4(T, T);
(e) 合法 
```

* **练习16.19**  
[16.19 程序代码](16.19.cpp)  

* **练习16.20**  
[16.20 程序代码](16.20.cpp)  

* **练习16.21**  
DebugDelete类 书上的版本  
[16.21 DebugDelete.h程序代码](16.21/DebugDelete.h)  
[16.21 测试程序代码](16.21/main.cpp)  

* **练习16.22**  
TextQuery类 书上的版本  
Query和继承类 书上的版本  
DebugDelete类 书上的版本  
为TextQuery中的shared_ptr替换删除器为DebugDelete 仅本题使用  
[16.22 DebugDelete.h程序代码](16.22/DebugDelete.h)  
[16.22 TextQuery.h程序代码](16.22/TextQuery.h)  
[16.22 TextQuery.cpp程序代码](16.22/TextQuery.cpp)  
[16.22 Query.h程序代码](16.22/Query.h)  
[16.22 Query.cpp程序代码](16.22/Query.cpp)  
[16.22 测试程序代码](16.22/main.cpp)  

* **练习16.23**  
在所有查询结束，程序结束时会执行调用运算符  

* **练习16.24**  
Blob类 书上的版本  
实现了两个迭代器的构造函数  
[16.24 Blob.h程序代码](16.24/Blob.h)  
[16.24 测试程序代码](16.24/main.cpp)  

* **练习16.25**  
```
extren template class vector<string>;
声明模板类vector的string实例，定义在别处
template class vector<Sales_data>;
定义模板类vector的Sales_data实例
```

* **练习16.26**  
不可以。因为vector有调用元素默认构造函数的成员，无法对这个成员实例化，所以无法对vector实例化  

* **练习16.27**  
(a) 未实例化，因为只是函数声明  
(b) 未实例化，因为是引用  
(c) 实例化了Stack<int>  
(d) 未实例化，因为是指针  
(e) 实例化了Stack<char>  
(f) 实例化了Stack<string>  

* **练习16.28**  
shared_ptr2类  
模仿标准库的shared_ptr，自己实现  
make_shared还不会实现  
[16.28 shared_ptr2.h程序代码](16.28/shared_ptr2/shared_ptr2.h)  
[16.28 DebugDelete.h程序代码](16.28/shared_ptr2/DebugDelete.h)  
[16.28 测试程序代码](16.28/shared_ptr2/main.cpp)  
unique_ptr2类  
模仿标准库的unique_ptr，自己实现  
[16.28 unique_ptr2.h程序代码](16.28/unique_ptr2/unique_ptr2.h)  
[16.28 DebugDelete.h程序代码](16.28/unique_ptr2/DebugDelete.h)  
[16.28 测试程序代码](16.28/unique_ptr2/main.cpp)  

* **练习16.29**  
Blob类 书上的版本 仅本题使用  
用自己的shared_ptr2类替代shared_ptr  
[16.29 Blob.h程序代码](16.29/Blob.h)  
[16.29 shared_ptr2.h程序代码](16.29/shared_ptr2.h)  
[16.29 测试程序代码](16.29/main.cpp)  

* **练习16.30**  
练习16.29中已经验证  

* **练习16.31**  
编译器可能会去掉DebugDelete类对象和相关函数，替换为对应的输出语句和释放操作  

* **练习16.32**  
编译器用传递给函数模板的实参来推断模板实参，并可能发生两种类型转换  

* **练习16.33**  
1. const引用和指针的转换  
2. 数组或函数指针的转换  

* **练习16.34**  
(a) 不合法，因为是引用类型，数组长度不同  
(b) 合法，T为 char [4]  

* **练习16.35**  
(a) 合法 T为char  
(b) 合法 T为double  
(c) 合法 T为char  
(d) 不合法 参数类型不同  

* **练习16.36**  
```
(a) T为int * 
(b) T1为int *，T2为int * 
(c) T为const int * 
(d) T1为const int *，T2为const int * 
(e) T为const int * 
(f) T1为int *，T2为const int * 
```

* **练习16.37**  
不能直接传给他一个int和double，可以显示指定模板实参进行调用  

* **练习16.38**  
因为make_shared是可以构造一个参数类型的对象的，因此我们需要指定模板参数类型，否则编译器无法从函数实参来推断模板实参的  

* **练习16.39**  
```
compare<std::string>("11qwe", "12345")
```

* **练习16.40**  
合法，It的实参类型的解引用必须是一个可以加0的对象。返回类型是It的实参类型的解引用对象的常量引用   

* **练习16.41**  
```
template <typename T1, typename T2>
auto sum(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}
```

* **练习16.42**  
```
(a) T : int &  val : int &
(b) T : const int & val : const int &
(c) T : int val : int &&
```

* **练习16.43**  
```
T : int & val : int &
```

* **练习16.44**  
```
template<typename T> void g(T val);
(a) T : int val : int 
(b) T : int val : int
(c) T : int val : int
template<typename T> void g(const T & val);
(a) T : int val : const int &
(b) T : int val : const int &
(c) T : int val : const int &
```

* **练习16.45**  
如果用一个42调用g，则42是字面值常量，是右值，因此T为int，val为int && 类型。  
如果用一个int类型变量调用g，因为变量是左值，将一个左值传递给函数的右值引用参数，编译器会推断模板T的类型为int & ，这样val的类型就是 int & &&，折叠后就是 int &

* **练习16.46**  
这段代码是要把元素从旧地址移动到新地址，虽然是左值，但是我们确定移动是安全的。  
首先elem是string * 类型，*elem++是令elem指向下一个位置，同时返回当前位置对象的左值引用。 
然后用std::move函数令左值类型转换为右值引用，再传参给alloc.construct函数，令其利用这个右值移动到新的内存中。

* **练习16.47**  
[16.47 程序代码](16.47.cpp)  

* **练习16.48**  
debug_rep模板重载函数 书上的版本  
[16.48 程序代码](16.48.cpp)  

* **练习16.49**  
```
g(42)
候选函数:
void g<int>(int);
最后选择:
void g<int>(int);
g(p)
候选函数:
void g<int *>(int *);
void g<int>(int *);
最后选择:
void g<int>(int *);
g(ci)
候选函数:
void g<int>(int);
最后选择:
void g<int>(int);
g(p2)
候选函数:
void g<const int *>(const int *);
void g<const int>(const int *);
最后选择:
void g<const int>(const int *);
f(42)
候选函数:
void f<int>(int);
最后选择:
void f<int>(int);
f(p)
候选函数:
void f<int *>(int *);
void f<int>(const int *);
最后选择:
void f<int *>(int *);
f(ci)
候选函数:
void f<int>(int);
最后选择:
void f<int>(int);
f(p2)
候选函数:
void f<const int *>(const int *);
void f<int>(const int *);
最后选择:
void f<int>(const int *);
```

* **练习16.50**  
[16.50 程序代码](16.50.cpp)  
程序输出的结果是：
```
void g(T t)
void g(T * t)
void g(T t)
void g(T * t)
void f(T t)
void f(T t)
void f(T t)
void f(const T * t)
```
结果相同  

* **练习16.51**  
猜测结果为：  
```
foo(i, s, 42, d);
sizeof...(Args) 为 3
sizeof...(rest) 为 3
foo(i, 42, "hi");
sizeof...(Args) 为 2
sizeof...(rest) 为 2
foo(d, s);
sizeof...(Args) 为 1
sizeof...(rest) 为 1
foo("hi");
sizeof...(Args) 为 0
sizeof...(rest) 为 0
```

* **练习16.52**  
[16.52 程序代码](16.52.cpp)  

* **练习16.53**  
重载的可变参数函数模板的print函数 书上的版本  
[16.53 程序代码](16.53.cpp)  

* **练习16.54**  
会发生编译错误  

* **练习16.55**  
调用大于1个的除ostream实参时会发生编译错误。  
因为print可变参数函数递归到只剩一个除ostream实参时，传递给下一个递归的rest中没有任何元素，不能匹配T，因此出现编译错误  

* **练习16.56**  
可变参数函数模板的errorMsg函数 书上的版本  
[16.56 程序代码](16.56.cpp)  

* **练习16.57**  
与旧版本相比，新版本可以接受不同的类型的参数，旧版本只能接受相同类型的，而且还必须放在大括号中  
但是新版本需要递归，函数调用次数多，耗费资源多  

* **练习16.58**  
StrVec类 书上的版本   
增加了emplace_back函数  
[16.58 StrVec.h 程序代码](16.58/StrVec/StrVec.h)  
[16.58 StrVec.cpp 程序代码](16.58/StrVec/StrVec.cpp)  
[16.58 测试程序代码](16.58/StrVec/main.cpp)  
Vec类  
增加了emplace_back函数  
[16.58 Vec.h程序代码](16.58/Vec/Vec.h)  
[16.58 测试程序代码](16.58/Vec/main.cpp)  

* **练习16.59**  
由于s是一个string左值，因此Args中的内容为一个类型，类型为string &，与&& 折叠后为string &  
由chk_n_alloc()确定空间足够后，std::forward生成一个左值类型，然后传递给alloc.construct构造一个string对象  

* **练习16.60**  
猜想make_shared的实现方式：  
make_shared是一个可变参数模板的函数，它的第一个模板类型是需要手动指定的，表示了构造的类型。  
后面的是可变参数模板。函数形参是可变参数模板类型。  
函数内容是new一个对象，用std::forward<args>保持参数类型，然后用指针来构造一个shared_ptr，并返回。

* **练习16.61**  
shared_ptr2类  
模仿标准库的shared_ptr，自己实现  
增加了make_shared2函数  
[16.61 shared_ptr2.h程序代码](16.61/shared_ptr2.h)  
[16.61 DebugDelete.h程序代码](16.61/DebugDelete.h)  
[16.61 测试程序代码](16.61/main.cpp)  

* **练习16.62**  
Sales_data类 书上的版本  
增加了特例化的hash<Sales_data>  
测试代码仅本题使用  
[16.62 Sales_data.h程序代码](16.62/Sales_data.h)  
[16.62 Sales_data.cpp程序代码](16.62/Sales_data.cpp)  
[16.62 测试程序代码](16.62/main.cpp)  

* **练习16.63**  
函数模板，统计给定值在vector中出现的次数  
[16.63 程序代码](16.63.cpp)  

* **练习16.64**  
函数模板，统计给定值在vector中出现的次数  
增加了处理const char * 的特例化版本  
[16.64 程序代码](16.64.cpp)  

* **练习16.65**  
debug_rep模板重载函数  
另char * 和const char * 成为模板的特例化版本
[16.65 程序代码](16.65.cpp)  

* **练习16.66**  
优点：  
不会影响重载函数的匹配规则  
缺点  
不能实现重载函数的匹配规则优先级的提升  
需要严格遵守模板的定义规则  

* **练习16.67**  
如果对于之前没特例化的版本来讲，是和之前函数匹配规则不一样  
但是特例化的版本不会提高优先级，因此不会影响正常函数的匹配规则  
