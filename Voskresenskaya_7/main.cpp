#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

using namespace std;

class my_exception : public exception //класс ошибка
{
	string error_; //текст ошибки
public:
	my_exception(const string& data1) //параметризованный конструктор ошибки
	{
		error_ = data1;
	}

	string& get_error() //метод получени¤ текста ошибки
	{
		return error_;
	}
};

int convert_to_sec(int h, int m)
{
	if (h < 0 || h >= 24)
	{
		throw my_exception("Неподдерживаемое значение H: " + to_string(h));
	}

	if (m < 0 || m >= 60)
	{
		throw my_exception("Неподдерживаемое значение M: " + to_string(m));
	}

	int sec = h * 3600 + m * 60;
	return sec;
}

void main()
{
	setlocale(LC_ALL, "russian");

	try
	{
		cout << "Попытка конвертировать (-1, 10)\n";
		int sec = convert_to_sec(-1, 10);
		cout << "Результат: " << sec << "\n";
	}
	catch (my_exception& exception)
	{
		cout << "Возникла ошибка: " << exception.get_error() << "\n";
	}

	try
	{
		cout << "Попытка конвертировать (4, 70)\n";
		int sec = convert_to_sec(4, 70);
		cout << "Результат: " << sec << "\n";
	}
	catch (my_exception& exception)
	{
		cout << "Возникла ошибка: " << exception.get_error() << "\n";
	}

	try
	{
		cout << "Попытка конвертировать (11, 37)\n";
		int sec = convert_to_sec(11, 37);
		cout << "Результат: " << sec << "\n";
	}
	catch (my_exception& exception)
	{
		cout << "Возникла ошибка: " << exception.get_error() << "\n";
	}

	system("pause");
}
