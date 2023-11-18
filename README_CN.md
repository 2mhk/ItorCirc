# ItorCirc
一个简单的warpper，使c++循环中的迭代器erase更容易

## 说明
ItorCirc使迭代器在循环中删除时不会再造成崩溃。

但是仍然要注意迭代器在下一个循环中是什么。


## 示例

下面是一个简单的示例，向您展示如何使用。

除了下面的例子，您还可以在 sample.cpp 中找到更多用法。

```cpp
#include "ItorCirc.h"
#include <vector>

void main()
{
    std::vector<int> vecData = { 1,2,3,4,5,6,7,8,9,10 };
    for (ItorCirc<decltype(vecData)> itor_vecData(vecData); !itor_vecData.isEnd(); itor_vecData.fetch_add())
    {
        int data = *itor_vecData.get_Iterator();
        if (data == 6) {
            itor_vecData.erase(itor_vecData.get_Iterator()); 			//or itor_vecData.erase_current();
            for (auto item : vecData) { std::cout << item << " "; }		//  1 2 3 4 5 7 8 9 10
        }
    }
}
```




