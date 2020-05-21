#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

using namespace std;

class my_empty_exception //класс ошибка
{
};

class my_parametrized_exception //класс ошибка
{
	string error_; //текст ошибки
public:
	my_parametrized_exception(const string& data1) //параметризованный конструктор ошибки
	{
		error_ = data1;
	}

	string& get_error() //метод получени¤ текста ошибки
	{
		return error_;
	}
};

class my_derived_exception : public exception //класс ошибка
{
public:
	my_derived_exception(const string& data1): exception(data1.c_str()) //параметризованный конструктор ошибки
	{
	}
};

int convert_to_sec_no_throw(int h, int m)
{
	int sec = h * 3600 + m * 60;
	return sec;
}

int convert_to_sec_throw_spec(int h, int m)
{
	if (h < 0 || h >= 24)
	{
		throw out_of_range("Неподдерживаемое значение H: " + to_string(h));
	}

	if (m < 0 || m >= 60)
	{
		throw out_of_range("Неподдерживаемое значение M: " + to_string(m));
	}

	int sec = h * 3600 + m * 60;
	return sec;
}

int convert_to_sec_throw_my_empty_exc(int h, int m)
{
	if (h < 0 || h >= 24)
	{
		throw my_empty_exception();
	}

	if (m < 0 || m >= 60)
	{
		throw my_empty_exception();
	}

	int sec = h * 3600 + m * 60;
	return sec;
}

int convert_to_sec_throw_my_parametrized_exc(int h, int m)
{
	if (h < 0 || h >= 24)
	{
		throw my_parametrized_exception("Неподдерживаемое значение H: " + to_string(h));
	}

	if (m < 0 || m >= 60)
	{
		throw my_parametrized_exception("Неподдерживаемое значение M: " + to_string(m));
	}

	int sec = h * 3600 + m * 60;
	return sec;
}

int convert_to_sec_throw_my_derived_exc(int h, int m)
{
	if (h < 0 || h >= 24)
	{
		throw my_derived_exception("Неподдерживаемое значение H: " + to_string(h));
	}

	if (m < 0 || m >= 60)
	{
		throw my_derived_exception("Неподдерживаемое значение M: " + to_string(m));
	}

	int sec = h * 3600 + m * 60;
	return sec;
}

void main()
{
	setlocale(LC_ALL, "russian");

	int sec_no_throw = convert_to_sec_no_throw(-1, 10);
	cout << "Без throw: " << sec_no_throw << "\n";

	cout << "throw out_of_range: ";
	try
	{
		int sec_throw_spec = convert_to_sec_throw_spec(-1, 10);
		cout << sec_throw_spec << "\n";
	}
	catch (out_of_range& exception)
	{
		cout << "поймано исключение: " << exception.what() << "\n";
	}

	cout << "throw my_empty_exception: ";
	try
	{
		int sec_throw_my_exc = convert_to_sec_throw_my_empty_exc(-1, 10);
		cout << sec_throw_my_exc << "\n";
	}
	catch (my_empty_exception& exception)
	{
		cout << "поймано исключение\n";
	}

	cout << "throw my_parametrized_exception: ";
	try
	{
		int sec_throw_my_exc = convert_to_sec_throw_my_parametrized_exc(-1, 10);
		cout << sec_throw_my_exc << "\n";
	}
	catch (my_parametrized_exception& exception)
	{
		cout << "поймано исключение: " << exception.get_error() << "\n";
	}

	cout << "throw my_derived_exception: ";
	try
	{
		int sec_throw_my_exc = convert_to_sec_throw_my_derived_exc(-1, 10);
		cout << sec_throw_my_exc << "\n";
	}
	catch (my_derived_exception& exception)
	{
		cout << "поймано исключение: " << exception.what() << "\n";
	}

	system("pause");
}
