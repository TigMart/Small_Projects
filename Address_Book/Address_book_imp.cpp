#include "Address_book.h"
#include <iostream>

Address_book::~Address_book()
{
    for (int i = 0; i < book.size(); ++i) delete book[i];
}

void Address_book::menu()
{
    int answer;
    std::cout << "If you want to create new contact press 1:\n";
    std::cout << "If you want to delete contact press 2:\n";
    std::cout << "If you want search contact by name press 3:\n";
    std::cout << "If you want to see all contacts press 4:\n";
    std::cin >> answer;
    switch (answer)
    {
    case 1:
        Create_new_contact();
        break;
    case 2:
        Delete_contact();
        break;
    case 3:
        Search_contact();
        break;
    case 4:
        See_all_contacts();
        break;
    default:
        break;
    }
}

void Address_book::Create_new_contact()
{
    Contact* p = new Contact;
    std::cout << "\tFirst name: ";
    std::cin >> m_name;
    p->id = ++m_id;
    p->name = m_name;
    std::cout << "\tLast name: ";
    std::cin >> m_surname;
    p->surname = m_surname;
    std::cout << "\tmobile_number: ";
    std::cin >> m_mobile_number;
    p->mobile_number = m_mobile_number;
    
    book.push_back(p);
    int answer1;
    std::cout << "If you want to add more contact press 1 or 0 to exit: ";
    std::cin >> answer1;
    if (answer1 == 1) {
        Create_new_contact();
    }
    else menu();
}

void Address_book::Delete_contact()
{
    int id;
    int count = 0;
    std::cout << "Which contact do you want to delete:\n Please enter id this contact: ";
    std::cin >> id;
    for (int i = 0; book.size(); ++i) {
        if (id > m_id || id == 0) {
            int ans;
            std::cout << "There is not such contact \n";
            std::cout << "press 1: to try again or press 0:\n";
            std::cin >> ans;
            if (ans == 1) Delete_contact();
            else menu();
        }
        if (id == book[i]->id)
        {
            book[i]->id = NULL;
            book[i]->name = "";
            book[i]->surname = "";
            book[i]->mobile_number = "";
            book.erase(book.begin() + i);
            break;
        }
    }
    int answer2;
    std::cout << "If you want to delete more contact press 1 or 0 to exit:\n";
    std::cin >> answer2;
    if (answer2 == 1) {
        Create_new_contact();
    }
    else menu();
}

void Address_book::Search_contact()
{
    
    std::string name;
    std::cout << "Please enter the name you are looking for: ";
    std::cin >> name;
    for (int i = 0; i<book.size(); ++i) {
        if (name != book[i]->name) {
            std::cout << "There is not such contact: ";
            int ans1;
            std::cout << "for try again press 1 or 0 to exit: ";
            std::cin >> ans1;
            if (ans1 == 1) Search_contact();
            else menu();
        }
        if (name == book[i]->name) {
            std::cout << "ID: " << book[i]->id << "  ";
            std::cout << "Name: " << book[i]->name << ' ';
            std::cout << "Surname: " << book[i]->surname << std::endl;
            std::cout << "Mobile number: " << book[i]->mobile_number << std::endl;
            continue;
        }
    }
    int answer4;
    std::cout << "If you want to search more contact press 1 or 0 to exit:\n";
    std::cin >> answer4;
    if (answer4 == 1) {
        Search_contact();
    }
    else menu();
}

void Address_book::See_all_contacts()

{   std::cout << "All contacts: \n";
    for (int i = 0; i < book.size(); ++i)
    {
        std::cout <<"ID: " << book[i]->id << "  ";
        std::cout <<"Name: "<< book[i]->name << ' ';
        std::cout <<"Surname: "<< book[i]->surname << std::endl;
        std::cout <<"Mobile number: "<< book[i]->mobile_number << std::endl;
    }
    int answer3;
    std::cout << "If you want to see again press 1 or 0 to exit:\n";
    std::cin >> answer3;
    if (answer3 == 1) {
        See_all_contacts();
    }
    else menu();
}
