#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include <algorithm>
#include <wchar.h>


class MyWString
{
public:
	//Конструктор по умолчанию
	MyWString()
	{
		this->STR = L"";
		this->count_UpSymb_InWord = 0;
		this->count_words = 1;
		this->last_word = L"";
		massive_index_words[0] = 0;
	}

	~MyWString()
	{
	}

	//Проверка на количество допустимых слов
	int CheckWords(const wchar_t& symb_check)
	{
		if (this->count_words <= 50 && symb_check == L'.')
		{
			if (this->count_words >= 2)
			{
				if (this->STR[STR.length() - 1] != L' ')
				{
					return 2;
				}
			}
			return 1;
		}
		else if (this->count_words <= 50)
		{
			if (this->CheckSymbol(symb_check))
			{
				return 0;
			}
			return 1;
		}
	}
	//
	void getSimilarWords()
	{
		bool check_words = false;
		getLastWord();
		for (int i = 0; i < count_words-1; i++)
		{
			std::wstring next_word = L"";
			getNextWord(next_word, i);
			if (wcscmp(next_word.c_str(), last_word.c_str()) != 0)
			{
				if (next_word.find(next_word[0], 1) != std::string::npos)
				{
					check_words = true;
					std::wcout << next_word << L" ";
				}	
			}
		}
		if (!check_words)
		{
			std::wcout << (L"Сравнений не обнаружено.");
		}
	}
	//Нахождение следующего слова
	void getNextWord(std::wstring & next_word, int index_next_word)
	{
		
		int index_word = massive_index_words[index_next_word];
		for (int i = 0; STR[index_word + i] != L' '; i++)
		{
			next_word += STR[index_word + i];
		}
	}
	//Нахождение последнего слова
	void getLastWord()
	{
		for (int i = 0; STR[STR.length() - 2 - i] != L' '; i++)
		{
			last_word += STR[STR.length() - 2 - i];
		}
		std::reverse(last_word.begin(), last_word.end());
	}

	MyWString & operator+=(const wchar_t symbol_add)
	{
		this->STR += symbol_add;
		return (*this);
	}

	MyWString & operator+(const wchar_t symbol_add)
	{
		this->STR = STR + symbol_add;
		return (*this);
	}

private:
	//Строка
	std::wstring STR;
	//Последнее слово в строке
	std::wstring last_word;
	//Количество прописных букв
	int count_UpSymb_InWord;
	int massive_index_words[50];
	//Количество слов
	int count_words;

	//Метод проверки символа
	bool CheckSymbol(const wchar_t & symb_check)
	{
		//Проверка на символ [А-Я]
		if (symb_check >= 1040 && symb_check <= 1071)
		{
			if (++this->count_UpSymb_InWord <= 8)
			{
				if (this->count_UpSymb_InWord == 1 && this->count_words >= 2)
				{
					massive_index_words[count_words - 1] = STR.length();
				}
				return true;
			}
			else
			{
				return false;
			}
		}
		//Проверка на пробел
		else if (symb_check == 32)
		{
			if (this->count_words != 50 && this->count_UpSymb_InWord != 0)
			{
				this->count_UpSymb_InWord = 0;
				if (this->STR[STR.length() - 1] != L' ')
				{
					this->count_words++;
					return true;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
	
	
};