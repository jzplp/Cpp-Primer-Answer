* **练习11.1**  
map用关键字索引，是一个字典。vector用整数索引，是一个列表。

* **练习11.2**  
list    链表  
vector  顺序列表  
deque   双端队列  
map     字典  
set     集合

* **练习11.3**  
[11.3 map单词计数程序代码](11.3.cpp)  

* **练习11.4**  
[11.4 去标点map单词计数程序代码](11.4.cpp)  

* **练习11.5**  
如果关键字有对应的值就用map，只有关键字就用set

* **练习11.6**  
set是按照关键字索引读取的，list只能是用迭代器读取的。  
顺序存储可以选list，需要关键字索引可以用set

* **练习11.7**  
[11.7程序代码](11.7.cpp)  

* **练习11.8**  
[11.8程序代码](11.8.cpp)  
使用set的优势是不需要手动去除重复元素

* **练习11.9**  
```
std::map<std::string, std::list<size_t>> m;
```

* **练习11.10**  
可以定义vector<int>::iterator到int的map，前提是实际的关键字必须来自同一容器。  
不可以定义list<int>::iterator到int的map，因为关键字类型没有定义<操作

* **练习11.11**  
```
multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>
```

* **练习11.12**  
[11.12程序代码](11.12.cpp)  

* **练习11.13**  
[11.13 make_pair程序代码](11.13/11.13_make_pair.cpp)  
[11.13 构造pair程序代码](11.13/11.13_construct.cpp)  
[11.13 列表初始化构造pair程序代码](11.13/11.13_listConstruct.cpp)  

* **练习11.14**  
[11.14程序代码](11.14.cpp)  

* **练习11.15**  
```
mapped_type     vector<int>
key_type        int
value_type      pair<const int, vector<int>>
```

* **练习11.16**  
```
iter->second = value;
```

* **练习11.17**  
1. 不合法
2. 不合法
3. 合法
4. 合法

* **练习11.18**  
```
std::map<const std::string, size_t>::iterator
```

* **练习11.19**  
```
std::multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>::iterator mp = bookstore.begin();
```
答案书中的pair迭代器错误。

* **练习11.20**  
[11.20 insert改写单词计数程序代码](11.20.cpp)  

* **练习11.21**  
循环输入单词，添加到map中作为关键字，如果是新加入的则设置值为1，以前加入的则设置为当前值+1

* **练习11.22**  
```
参数类型：
{std::string, std::vector<int>}
返回类型：
std::pair<std::map<std::string, std::vector<int>>::iterator, bool>
```

* **练习11.23**  
[11.23 用multimap重写11.14程序代码](11.23.cpp)  

* **练习11.24**  
创建一个map，并添加一个{0,1}元素

* **练习11.25**  
创建一个vector，第二句话错误。

* **练习11.26**  
用key_type对map进行下标操作。下标运算符返回的类型是mapped_type  
例子：
```
std::map<std::string, zise_t> m;
m[std::string("str")] = 1;
```

* **练习11.27**  
需要查找关键字有几个时用count，仅仅需要知道关键字在不在容器中时用find

* **练习11.28**  
```
std::map<std::string, std::vector<int>> m;
std::map<std::string, std::vector<int>>::iterator = m.find(str);
```

* **练习11.29**  
他们全部返回大于该关键字的第一个元素，如果不存在则返回尾迭代器

* **练习11.30**  
pos.first是一个迭代器，指向当前使用的元素。  
pos.first->second 取出当前使用的元素的值。

* **练习11.31**  
[11.31程序代码](11.31.cpp)  

* **练习11.32**  
11.31答案代码中已经实现了按照字典序打印  
[11.31程序代码](11.31.cpp)  

* **练习11.33**  

