* **练习9.1**  
(a) 先用一个vector尾插元素，读取结束后再用sort排序。  
(b) deque  
(c) 先用一个vector尾插元素，读取结束后再用sort排序。  

* **练习9.2**  
```
std::list<std::deque<int>> l;
```

* **练习9.3**  
1. 两个迭代器必须都指向同一个容器中的元素或者是尾元素之后的位置
2. 构成一个左闭合区间  

* **练习9.4**  
[9.4程序代码](9.4.cpp)  

* **练习9.5**  
[9.5程序代码](9.5.cpp)  

* **练习9.6**  
```
while(iter1 != iter2)
```

* **练习9.7**  
```
std::vector<int>::const_iterator
```

* **练习9.8**  
```
使用 std::list<std::string>::value_type
写入 std::list<std::string>::reference
```

* **练习9.9**  
返回的迭代器是否可以修改指向的元素内容。

* **练习9.10**  
```
it1     vector<int>::iterator
it2     vector<int>::const_iterator
it3     vector<int>::const_iterator
it4     vector<int>::const_iterator
```

* **练习9.11**  
[9.11程序代码](9.11.cpp)  

* **练习9.12**  
接受一个容器的构造函数必须元素和容器类型都相同，接受迭代器的构造函数不要求类型相同，只要元素类型可转换为新构造的容器的元素类型即可。

* **练习9.13**  
[9.13程序代码](9.13.cpp)  

* **练习9.14**  
[9.14程序代码](9.14.cpp)  

* **练习9.15**  
