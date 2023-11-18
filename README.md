# ItorCirc
warpper to make erasing iterator in C++  circulation easier




Sample:


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