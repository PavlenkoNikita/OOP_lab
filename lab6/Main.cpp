#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
//#include <conio.h>
#include "MyWString.h"

int main() 
{	
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stdin), _O_WTEXT);
	int number_str = 0;
	wchar_t button_exit = 0x1B;
	do
	{
		std::wcout << L"Строка №" << ++number_str << std::endl;
		MyWString MyStr;
		wchar_t symbol;
		while (true)
		{
			symbol = _getwch();
			switch (MyStr.CheckWords(symbol))
			{
			case 0:
			{
				MyStr += symbol;
				std::wcout << symbol;
				break;
			}
			case 1:
			{
				continue;
			}
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
		MyStr.getSimilarWords();
		std::wcout << L"\nДля продолжения нажмите любую клавишу. ESC - выход. \n";
	} while (_getwch() != button_exit);
	return 0;
}