#pragma once
#include <iostream>
#include <string>
#include <vector>

class GetRightString
{
public:
	//Конструктор по умолчанию
	GetRightString()
	{
		this->STR = L"";
		this->count_UpSymb_InWord = 0;
		this->count_words = 0;
	}
	//Проверка на количество допустимых слов
	int CheckWords(const wchar_t& symb_check)
	{
		if (this->count_words <= 50 && symb_check == L'.')
		{
			if (this->count_words >= 1)
			{
				if (this->STR[STR.length() - 1] != L' ')
				{
					words.push_back(temp_word);
					this->count_words++;
					AddAndWriteSymb(symb_check);
					return 1;
				}
			}
			else
			{
				return 0;
			}
		}
		else if (this->count_words <= 50)
		{
			if (CheckCyrillicAlpha(symb_check)) {}
			else if (CheckSpace(symb_check)) {}
			return 0;
		}
	}
	//Нахождение не совпадающий слов
	void getSimilarWords()
	{
		bool check_words = false;
		std::wstring last_word = words.back();
		std::wstring current_word;
		for (int i = 0; i < words.size(); i++)
		{
			current_word = words[i];
			if (wcscmp(words[i].c_str(), last_word.c_str()) && current_word.find(current_word[0], 1) != std::string::npos)
			{
				check_words = true;
				std::wcout << current_word << L" ";
			}
		}
		if (!check_words)
		{
			std::wcout << (L"совпадений не обнаружено.");
		}
	}
private:
	//Строка
	std::wstring STR;
	//Все слова
	std::vector<std::wstring> words;
	//Собирание слова
	std::wstring temp_word;
	//Количество прописных букв
	int count_UpSymb_InWord;
	//Количество слов
	int count_words;
	//Вывод допустимого символа в консоль и добавление его в строку
	void AddAndWriteSymb(const wchar_t& symb)
	{
		std::wcout << symb;
		this->STR += symb;
	}
	//Проверка на символ прописной кириллицы
	bool CheckCyrillicAlpha(const wchar_t& symb_check)
	{
		if (symb_check >= 1040 && symb_check <= 1071)
		{
			if (++this->count_UpSymb_InWord <= 8)
			{
				this->temp_word += symb_check;
				AddAndWriteSymb(symb_check);
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	//Проверка на символ пробела
	bool CheckSpace(const wchar_t & symb_check)
	{
		if (symb_check == 32)
		{
			if (!this->temp_word.empty() || this->count_words != 0)
			{
				this->count_UpSymb_InWord = 0;
				if (this->STR[this->STR.length() - 1] != L' ')
				{
					this->words.push_back(this->temp_word);
					this->temp_word.clear();
					this->count_words++;
					AddAndWriteSymb(symb_check);
					return true;
				}
				else
				{
					AddAndWriteSymb(symb_check);
					return true;
				}
			}
		}
		else
		{
			return false;
		}
	}
};