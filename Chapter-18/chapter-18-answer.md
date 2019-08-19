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

