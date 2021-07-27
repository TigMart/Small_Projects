// Frankenstein's_List.cpp : 

#include <iostream>
#include "Franklist.h"

int main()
{
    Franklist<int> f5;
    f5.push_back(7);
    f5.push_back(5);
    f5.insert(2, 10);
    f5.pop_back();
    f5.print();
    Franklist<int> f1;
    f1.push_front(8);
    f1.push_front(6);
    f1.push_front(10);
    f1.print();
    Franklist<int> f2(f1);
    f2.print();
    Franklist<int>  f3;
    f3.push_back(8);
    f3.push_back(6);
    f3.push_back(9);
    std::cout << std::endl <<"Push_back "<< std::endl;
    f3.print();
    std::cout << std::endl <<"Front: "<< std::endl;
    std::cout<<f3.front();    
    std::cout << std::endl <<"Back: "<< std::endl;
    std::cout<<f3.back(); 
    std::cout << std::endl <<"Size: "<< std::endl;
    std::cout<<f3.size(); 
    std::cout << std::endl <<"Empty: "<< std::endl;
    std::cout << std::boolalpha << f3.empty();     
    std::cout << std::endl <<"Clear: "<< std::endl;
    f2.clear();  
    f2.print();





    
}


