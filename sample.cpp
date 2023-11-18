#include "ItorCirc.h"
#include <vector>
#include <iostream>

void main()
{
	std::vector<int> vecData = { 1,2,3,4,5,6,7,8,9,10 };
    std::cout << "before delete : " << std::endl;
    for (auto item : vecData) { std::cout << item << " "; }		//  1 2 3 4 5 6 7 8 9 10
    std::cout << std::endl;
    for (ItorCirc<decltype(vecData)> itor_vecData(vecData); !itor_vecData.isEnd(); itor_vecData.fetch_add())
    {
        int data = *itor_vecData.get_Iterator();

        if (data == 6) {
			std::cout << "before delete, \n current iterator : " << itor_vecData.get_Iterator() - vecData.begin() << "  current data : " << *itor_vecData.get_Iterator() << std::endl;
            //basic use
            itor_vecData.erase(itor_vecData.get_Iterator()); //or itor_vecData.erase_current();
            std::cout << "after erase_current() \n next iterator : " << itor_vecData.get_Iterator() - vecData.begin() << "  next data : " << *itor_vecData.get_Iterator() << std::endl;
            for (auto item : vecData) { std::cout << item << " "; }		//  1 2 3 4 5 7 8 9 10
            std::cout << std::endl;
            std::cout << "/////////////////////////////////////////////////////////////////" << std::endl;

            //Advanced use
            auto index_reserved = itor_vecData.get_Iterator() - vecData.begin();

            std::cout << "erase vecData.begin() + 4 : " << std::endl;
            itor_vecData.erase(vecData.begin() + 4);
            for (auto item : vecData) { std::cout << item << " "; }		//  1 2 3 4 7 8 9 10
            std::cout << std::endl;
            std::cout << "after erase vecData.begin() + 4 : \n next iterator : " << itor_vecData.get_Iterator() - vecData.begin() << "  next data : " << *itor_vecData.get_Iterator() << std::endl;
            std::cout << "/////////////////////////////////////////////////////////////////" << std::endl;

            std::cout << "erase vecData.begin() + 2  by force_change_index but iterator stay still: " << std::endl;
            itor_vecData.force_change_index(vecData.erase(vecData.begin() + 2));
            std::cout << "after force_change_index(vecData.erase(vecData.begin() + 2)) : \n next iterator : " << itor_vecData.get_Iterator() - vecData.begin() << "  next data : " << *itor_vecData.get_Iterator() << std::endl;
            itor_vecData.force_change_index(vecData.begin() + index_reserved);
            std::cout << "after force_change_index(vecData.begin() + index_reserved) : \n next iterator : " << itor_vecData.get_Iterator() - vecData.begin() << "  next data : " << *itor_vecData.get_Iterator() << std::endl;
            for (auto item : vecData) { std::cout << item << " "; }		//  1 2 4 7 8 9 10
            std::cout << std::endl;
            std::cout << "after delete, final next iterator : " << itor_vecData.get_Iterator() - vecData.begin() << "  next data : " << *itor_vecData.get_Iterator() << std::endl;
            std::cout << "/////////////////////////////////////////////////////////////////" << std::endl;
        }
    }
    std::cout << "/////////////////////////////////////////////////////////////////" << std::endl;
    std::cout << "after delete : " << std::endl;
    for (auto item : vecData) { std::cout << item << " "; }
    std::cout << std::endl;
}

//  output : 
//
//  before delete :
//  1 2 3 4 5 6 7 8 9 10
//  before delete current,
//   current iterator : 5  current data : 6
//  after erase_current()
//   next iterator : 5  next data : 7
//  1 2 3 4 5 7 8 9 10
//  /////////////////////////////////////////////////////////////////
//  erase vecData.begin() + 4 :
//  1 2 3 4 7 8 9 10
//  after erase vecData.begin() + 4 :
//   next iterator : 4  next data : 7
//  /////////////////////////////////////////////////////////////////
//  erase vecData.begin() + 2  by force_change_index but iterator stay still:
//  after force_change_index(vecData.erase(vecData.begin() + 2)) :
//   next iterator : 2  next data : 4
//  after force_change_index(vecData.begin() + index_reserved) :
//   next iterator : 5  next data : 9
//  1 2 4 7 8 9 10
//  after delete, final next iterator : 5  next data : 9
//  /////////////////////////////////////////////////////////////////
//  /////////////////////////////////////////////////////////////////
//  after delete :
//  1 2 4 7 8 9 10