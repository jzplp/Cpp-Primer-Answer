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