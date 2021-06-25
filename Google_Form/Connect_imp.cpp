#include "Google_Form.h"
#include <iostream>
#include <exception>

void Connect::menu()
{
    int answer;
    std::cout << "If you admin press 1: " << '\n' << "If you user press 2: " << '\n';
    std::cin >> answer;
    if (answer == 1) {
        Connect a("Admin");
    }
    else if (answer == 2) {
        Connect b("Student");
    }
    else {
        std::cout << "error!";
    }
}

Connect::Connect(std::string st)
{
    if (st == "Admin") {
        std::cout << "Please enter subject name: ";
        std::string sub;
        std::cin >> sub;
        fout1.open("list.txt", std::ofstream::app);
        if (!fout1.is_open())
        {
            throw std::exception("File is not open!");
        }
        else
        {
            fout1 << sub << std::endl;
        }
        fout1.close();
        Admin obj;
        obj.CreateQuestion(sub);
      
        int answer;
        std::cout << "If you want to add more question press 1 or 0 to exit: ";
        std::cin >> answer;
        if (answer == 0) {
            menu();
        }
        while (answer != 0)
        {
            obj.CreateQuestion(sub);
            
            std::cout << "If you want to add more question press 1 or 0 to exit: ";
            std::cin >> answer;
            if (answer == 0) {
                menu();
            }
        }
    }
    else {
        inf2.open("list.txt");
        if (!inf2.is_open()) {
            throw std::exception("File is not open!");
        }
        else
        {
            while (!inf2.eof())
            {
                std::string subj;
                std::getline(inf2, subj);
                std::cout << subj << std::endl;
            }
        }
        inf2.close();
        std::cout << "Please enter subject name: ";
        std::string str;
        std::cin >> str;
        Student a;
        a.solve_the_quiz(str);
        Check(str);
        fout.open(str + "_Student_answers.txt");
        if (!fout.is_open())
        {
            throw std::exception("File is not open!");
        }
        else
        {
            while (fout.eof())
            {
                fout << " ";
            }
        }
        fout.close();
    }
}
  
void Connect::Check(std::string subject)
{
    int i = 0;
    inf.open(subject + "_answer.txt");
    inf1.open(subject + "_Student_answers.txt");
    if (!inf.is_open() && !inf1.is_open()) {
        throw std::exception("File is not open!");
    }
    else
    {
        while (!inf.eof())
        {
            std::string str1;
            std::string str2;
            std::getline(inf, str1);
            std::getline(inf1, str2);
            ++i;
            if (inf.eof()) {
                break;
            }
            std::cout << "Question " << i << std::endl;
            if (str1 == str2)
            {
                std::cout << "True " << 10 << std::endl;
                valuation += 10;
            }
            else {
                std::cout << "False " << 0 << std::endl;
            }

        }
        std::cout << "Your Valuation is " << valuation;
    }
}
