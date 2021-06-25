#ifndef _ADDRESS_BOOK_
#define _ADDRESS_BOOK_

#include <string>
#include <vector>


struct Contact
{
	std::string name;
	std::string surname;
	std::string mobile_number;
	int id{ 0 };
};

class Address_book 
{
public:

	~Address_book();
    void menu();
    
    
private:
	void Create_new_contact();
	void Delete_contact();
	void Search_contact();
	void See_all_contacts();

	std::string m_name;
	std::string m_surname;
	std::string m_mobile_number;
	int m_id{ 0 };
	std::vector<Contact*> book;
    

};
#endif // !_ADDRESS_BOOK_
