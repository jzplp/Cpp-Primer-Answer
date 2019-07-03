* **练习12.1**  
代码的结尾b2已经被释放，b1中包含4个元素

* **练习12.2**  
[12.2 StrBlob.h程序代码](12.2/StrBlob.h)  
[12.2 StrBlob.cpp程序代码](12.2/StrBlob.cpp)  
[12.2 测试程序代码](12.2/main.cpp)  

* **练习12.3**  
不需要，因为push_back和pop_back会改变对象，但是const是不允许改变的。

* **练习12.4**  
因为data.size()的返回值肯定是大于等于0的。

* **练习12.4**  
因为size_type类型是unsigned类型，如果i的值为负，那么便自动转化为大整数。
而且check是私有函数，值是我们控制的

* **练习12.5**  
可以用一个初始化列表对StrBlob进行隐式转换。缺点是在不需要转换的地方可能会造成错误。

* **练习12.6**  
[12.6程序代码](12.6.cpp)  

* **练习12.7**  
[12.7程序代码](12.7.cpp)  

* **练习12.8**  
首先是把p当作一个bool值返回，实际效果是如果p不是一个空指针，那么就会返回true  
其次是没有释放p所指向的动态内存空间  

* **练习12.9**  
r被q中的内容覆盖，其原来的地址中的内存无法被释放。  
r2中的内存被智能指针自动释放。

* **练习12.10**  
正确

* **练习12.11**  
函数执行完毕后，p指向的内存会被释放

* **练习12.12**  
(a) 合法  
(b) 不合法  
(c) 不合法  
(d) 合法但有危险  

* **练习12.13**  
sp指向的内存被释放

* **练习12.14**  
部分内容只有声明无定义，不能执行  
[12.14 connection程序代码](12.14.cpp)  

* **练习12.15**  
部分内容只有声明无定义，不能执行  
[12.15 用lambda改写connection程序代码](12.15.cpp)  

* **练习12.16**  
[12.16 错误程序代码](12.16.cpp)  
错误信息：
```
[Error] use of deleted function 'std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]'
```

* **练习12.17**  
(a) 不合法，ix是int，不是指针  
(b) 合法，但后续程序错误。局部变量的地址不能传递给智能指针，后面无法销毁  
(c) 合法  
(d) 合法，但后续程序错误。局部变量的指针不能传递给智能指针，后面无法销毁  
(e) 合法  
(f) 合法,但是造成了两个unique_ptr共享一个指针，后面会造成错误  
  
* **练习12.18**  
因为对shared_ptr销毁或者赋值会自动放弃对指针的控制权  

* **练习12.19**  
其中添加了自己的compare函数比较StrBlobPtr  
[12.19 添加了StrBlobPtr的 StrBlob.h程序代码](12.19/StrBlob.h)  
[12.19 添加了StrBlobPtr的 StrBlob.cpp程序代码](12.19/StrBlob.cpp)  
[12.19 测试程序代码](12.19/main.cpp)  

* **练习12.20**  
[12.20 未改动 StrBlob.h程序代码](12.20/StrBlob.h)  
[12.20 未改动 StrBlob.cpp程序代码](12.20/StrBlob.cpp)  
[12.20 测试程序代码](12.20/main.cpp)  

* **练习12.21**  
都可以

* **练习12.22**  
[12.22 添加了ConstStrBlobPtr的 StrBlob.h程序代码](12.22/StrBlob.h)  
[12.22 添加了ConstStrBlobPtr的 StrBlob.cpp程序代码](12.22/StrBlob.cpp)  
[12.22 测试程序代码](12.22/main.cpp)  

* **练习12.23**  
