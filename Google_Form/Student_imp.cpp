#include "Google_Form.h"
#include <iostream>


void Student::solve_the_quiz(std::string subject)
{
	std::string str;
	inf.open(subject + ".txt");
	if (!inf.is_open()) {
		throw std::exception("File is not open!");
	}
	else
	{
		while (!inf.eof())
		{
			std::getline(inf, str);
			std::cout << str<<'\n';
		}
		std::string str1;
		inf1.open(subject + "ID.txt");
		if (!inf1.is_open()) {
			throw std::exception("File is not open!");
		}
		else
		{
			while (!inf1.eof())
			{
				std::getline(inf1, str1);
			}
			count = std::stoi(str1);
		}
		for (int i = 0; i < count - 1; ++i) {
			std::cout << "Please enter answer " << "Question " << i + 1 << " ";
			std::cin >> answer;
			fout1.open(subject + "_Student_answers.txt", std::ofstream::app);
			if (!fout1.is_open())
			{
				throw std::exception("File is not open!");
			}
			else
			{
				fout1 << answer << '\n';
			}
			fout1.close();
		}
	}
}
