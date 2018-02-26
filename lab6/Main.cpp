#include <io.h>
#include <fcntl.h>
#include "GetRightWString.h"

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
		GetRightWString MyStr;
		while (true)
		{
			//Проверка символа точки
			if (MyStr.CheckWords(_getwch()))
			{
				break;
			}
		}
		std::wcout << L"\nРезультат: ";
		//Получение не совпадающих слов
		MyStr.getSimilarWords();
		std::wcout << L"\nДля продолжения нажмите любую клавишу. ESC - выход. \n";
	} while (_getwch() != button_exit);
	return 0;
}