* **练习5.1**  
只有一个分号的语句是空语句。  
语法上需要但逻辑上不需要语句的时候会使用空语句。

* **练习5.2**  
块是用花括号括起来的语句序列。  
在语法上需要一条语句但是逻辑上需要多条语句的时候会使用块。

* **练习5.3**  
```
while(val <= 10)
    sum += val, val++;
```
由于递增运算符的存在，我觉得可读性降低了。

* **练习5.4**  
(a) 初始化迭代器并判断是否到string尾
```
string::iterator iter = s.begin();
while(iter != s.end())
    {...}
```
(b) 初始化状态，更新状态并在循环后判断状态。
```
bool status;
while(status = find(word))
    {...}
if(!ststua)
    {...}
```

* **练习5.5**  
[5.5程序代码](5.5.cpp)  

* **练习5.6**  
[用条件运算符重写5.5程序代码](5.6_5.5_conditionOperator.cpp)  

* **练习5.7**  
```
(a)
if (ival1 != ival2)
    ival1 = ival2;
else
    ival1 = ival2 = 0;

(b)
if (ival < minval)
{
    minval = ival;
    occurs = 1;
}

(c)
int ival;
if (ival = get_value())
    cout << "ival = " << ival << endl;
if (!ival)
    cout << "ival = 0\n";

(d)
if (ival == 0)
    ival = get_value();
```

* **练习5.8**  
垂悬else：else语句上面有很多个if，需要判断和哪个if语句匹配。  
else和最近的if语句匹配。

* **练习5.9**  
[5.9程序代码](5.9.cpp)  

* **练习5.10**  
[5.10程序代码](5.10.cpp)  

* **练习5.11**  
[5.11程序代码](5.11.cpp)  

* **练习5.12**  
[5.12程序代码](5.12.cpp)  

* **练习5.13**  
```
(a)
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch)
{
    case 'a': aCnt++; break;
    case 'e': eCnt++; break;
    case 'i': case 'o': case 'u': iouCnt++; break;    
}

(b)
unsigned index = some_value();
switch (index) {
    case 1:
        int ix;
        ix = get_value();
        ivec[ix] = index;
        break;
    default:
        ix = ivec.size() - 1;
        ivec[ix] = index;
}

(c)
unsigned evenCnt = 0,oddCnt = 0;
int digit = get_num() % 10;
switch (digit)
{
    case 1: case 3: case 5: case 7: case 9:
        oddCnt++;
        break;
    case 2: case 4: case 6: case 8: case 10:
        evenCnt++;
        break;
}

(d)
constexpr unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch()
{
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval：
        bufsize = kval * sizeof(int);
        break;
}
```

* **练习5.14**  
[5.14程序代码](5.14.cpp)  

* **练习5.15**  
```
(a)
int ix;
for (ix = 0;ix != sz; ++ix) {...}
if (ix != sz)

(b)
int ix;
for ( ; ix != sz; ++ix) {...}

(c)
for(int ix = 0; ix != sz; ++ix) {...}
```

* **练习5.16**  
[5.16while循环程序代码](5.16/5.16_while.cpp)  
[5.16for循环程序代码](5.16/5.16_for.cpp)  

* **练习5.17**  
[5.17程序代码](5.17.cpp)  

* **练习5.18**  
```
(a)
do
{
    int v1, v2;
    cout << "...";
    if (cin >> v1 >> v2)
        cout << "Sum is " << v1 + v2 <<endl;
}while (cin);

(b)
int ival;
do { ... } while (ival = get_response());

(c)
int ival;
do { 
    ival = get_response();
} while (ival);

```

* **练习5.19**  
[5.19程序代码](5.19.cpp)  

* **练习5.20**  
[5.20程序代码](5.20.cpp)  

* **练习5.21**  
[重写5.20程序代码](5.21_5.20_upper.cpp)  

* **练习5.22**  
```
int sz = get_size();
while(sz <= 0)
    sz = get_size();
```

* **练习5.23**  
[5.23程序代码](5.23.cpp)  

* **练习5.24**  
[5.24程序代码](5.24.cpp)  
程序输出下面内容并终止：
```
terminate called after throwing an instance of 'std::runtime_error'
  what():  i2 is zero!
```

* **练习5.25**  
[5.25程序代码](5.25.cpp)  
