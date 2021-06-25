#ifndef GOOGLE_FORM
#define GOOGLE_FORM

#include <string>
#include <fstream>

class Admin
{
public:
	void CreateQuestion(std::string subject);
	static int m_id_q;
private:
	std::ofstream fout1;
	std::ofstream fout2;
	std::ofstream fout3;
	std::string m_questions;
	std::string m_answers;
	int m_correct_answer_id;
	std::string m_subject;
	int m_id_a{ 1 };	
};

class Student
{
public:
	void solve_the_quiz(std::string subject);
	
private:
	std::ifstream inf;
	std::ifstream inf1;
	std::ofstream fout;
	std::ofstream fout1;
	int count;
	char answer;
};

class Connect
{
public:
	Connect() {};
	Connect(std::string st);
	void Check(std::string subject);
	void menu();
private:
	std::ifstream inf;
	std::ifstream inf1;
	std::ifstream inf2;
	std::ofstream fout;
	std::ofstream fout1;
	int valuation{ 0 };
};

#endif // GOOGLE_FORM
