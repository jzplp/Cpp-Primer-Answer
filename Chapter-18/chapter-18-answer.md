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
