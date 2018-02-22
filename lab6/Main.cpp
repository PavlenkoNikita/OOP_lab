#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
//#include <conio.h>
#include "MyWString.h"

int main() 
{	
	//Поддержка Unicode
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stdin), _O_WTEXT);
	//Номер вводимой строки
	int number_str = 0;
	//ESC код
	wchar_t button_exit = 0x1B;
	do
	{
		std::wcout << L"Строка №" << ++number_str << std::endl;
		MyWString MyStr;
		wchar_t symbol;
		while (true)
		{
			//Считываем символ
			symbol = _getwch();
			switch (MyStr.CheckWords(symbol))
			{
			//Введенный символ прописная кириллица или пробел
			case 0:
			{
				MyStr += symbol;
				std::wcout << symbol;
				break;
			}
			//Введенный символ не прописная кириллица и не пробел
			case 1:
			{
				continue;
			}
			//Введенный символ точка
			case 2:
			{
				MyStr += symbol;
				std::wcout << symbol;
				goto END_STR;
			}
			}
		}
	END_STR:
		std::wcout << L"\nРезультат: ";
		//Получение не совпадающих слов
		MyStr.getSimilarWords();
		std::wcout << L"\nДля продолжения нажмите любую клавишу. ESC - выход. \n";
	} while (_getwch() != button_exit);
	return 0;
}