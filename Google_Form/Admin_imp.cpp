#include "Google_Form.h"
#include <fstream>
#include <exception>
#include <iostream>

int Admin::m_id_q{ 1 };

void Admin::CreateQuestion(std::string subject)
{
	fout1.open(subject+".txt", std::ofstream::app);
	fout3.open(subject + "ID.txt");
	subject += ("_answer.txt");
	fout2.open(subject, std::ofstream::app);
	if (!fout1.is_open()&&!fout2.is_open()&&!fout3.is_open())
	{
		throw std::exception("File is not open!");
	}
	else 
	{	
		std::cout << "Please enter " << m_id_q << " question ";
		std::cin.get();
		std::getline(std::cin, m_questions);
		fout1 << "Question " << m_id_q <<" "<< m_questions << '\n';
		++m_id_q;
		int answer;
		std::cout << "How many answers does your question have ? 2 or 4 ";
		std::cin >> answer;
		std::cin.get();
		m_id_a = 1;
		for (int i = 0; i < answer; ++i) {
			std::cout << "Please enter answers: " << m_id_a << std::endl;
			std::getline(std::cin, m_answers);
			
			fout1 << m_id_a << ") " << m_answers << '\n';
			++m_id_a;
		}
		std::cout << "Please enter correct answer_id: ";
		std::cin >> m_correct_answer_id;
		fout2 << m_correct_answer_id<<'\n';
	}
	fout3 << m_id_q;
	fout1.close();
	fout2.close();
	fout3.close();
}
