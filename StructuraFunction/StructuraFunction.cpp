#include <iostream>
#include "C:\Users\Сева\source\repos\Struktura\Struktura\Struktura.h"
using namespace std;

int CheckNumber(int f)
{
	string stroka;
	int K;
	if (f == 0)
	{
		cout << "Введите число экзаменов - ";
	}
	else
	{
		cout << "Введите число студентов - ";
	}
	cin >> stroka;
	while (true)
	{
		try
		{
			K = stoi(stroka);
			if ((to_string(K) == stroka) and (K <= 100) and (K >= 0))
			{
				return K;
			}
			else
			{
				throw logic_error("Число введено некорректно");
			}
		}
		catch (...)
		{
			cout << "Число введено некорректно. Введите число - ";
			cin >> stroka;
		}
	}
}
int CheckScore()
{
	string stroka;
	int K;
	cout << "Введите колличество баллов - ";
	cin >> stroka;
	while (true)
	{
		try
		{
			K = stoi(stroka);
			if ((to_string(K) == stroka) and (K <= 100) and (K >= 0))
			{
				return K;
			}
			else
			{
				throw logic_error("Колличество баллов введено некорректно");
			}
		}
		catch (...)
		{
			cout << "Колличество баллов введено некорректно. Введите колличество баллов - ";
			cin >> stroka;
		}
	}
}
void CoutExam(Exam a)
{
	for (int i = 0; i < a.estimation.size(); i++)
	{
		cout << i + 1 << " экзамен - " << a.estimation[i] << " баллов" << endl;
	}
	cout << "Средний балл студента - " << a.AvaregeScore;
}
Exam CreatExam()
{
	Exam a;
	int n = CheckNumber(0);
	for (int i = 0; i < n; i++)
	{
		int c = CheckScore();
		a.estimation.push_back(c);
	}
	int summ = 0;
	for (int i = 0; i < a.estimation.size(); i++)
	{
		summ += a.estimation[i];
	}
	a.AvaregeScore = summ / n;
	return a;
}
void CoutStudent(Student a)
{
	cout << "Имя студента:" << a.Name << endl;
	cout << "Фамилия студента:" << a.Surname << endl;
	cout << "Отчество студента:" << a.Patronymic << endl << endl;
	cout << "Колличество баллов по каждому экзамену и средний балл студента:" << endl;
	CoutExam(a.Exams);
	cout << endl << "------------------------" << endl;
}
Student CreatStudent()
{
	Student a;
	cout << "Введите имя студента - ";
	cin >> a.Name;
	cout << "Введите фамилию студента - ";
	cin >> a.Surname;
	cout << "Введите отчество студента - ";
	cin >> a.Patronymic;
	cout << endl;
	a.Exams = CreatExam();
	return a;
}
University CreatUniversity()
{
	University a;
	int n = CheckNumber(1);
	cout << endl << endl;
	for (int i = 0; i < n; i++)
	{
		a.list_student.push_back(CreatStudent());
		cout << endl;
	}
	int summ = 0;
	for (int i = 0; i < a.list_student.size(); i++)
	{
		summ += a.list_student[i].Exams.AvaregeScore;
	}
	a.AvarageUniversity = summ / n;
	return a;
}
void CoutUniversity(University a)
{
	for (int i = 0; i < a.list_student.size(); i++)
	{
		CoutStudent(a.list_student[i]);
	}
}
University CreatUniversitySorted(University a)
{
	University b;
	int n = a.list_student.size();
	for (int i = 0; i < n; i++)
	{
		if (a.list_student[i].Exams.AvaregeScore == 100)
		{
			b.list_student.push_back(a.list_student[i]);
		}
		else if ((a.list_student[i].Exams.AvaregeScore < 100) and (a.list_student[i].Exams.AvaregeScore >= a.AvarageUniversity))
		{
			b.list_student.push_back(a.list_student[i]);
		}
	}
	return b;
}


int main()
{

}

