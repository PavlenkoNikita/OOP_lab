#pragma once
#include <iostream>
#include <string>
#include <vector>

class GetRightWString
{
public:
	//Конструктор по умолчанию
	GetRightWString();
	//Проверка на количество допустимых слов
	int CheckWords(const wchar_t& symb_check);
	//Нахождение не совпадающий слов
	void getSimilarWords();
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
	void AddAndWriteSymb(const wchar_t& symb);
	//Проверка на символ прописной кириллицы
	bool CheckCyrillicAlpha(const wchar_t& symb_check);
	//Проверка на символ пробела
	bool CheckSpace(const wchar_t & symb_check);
	//Проверка на символ Backspace
	bool CheckBackspace(const wchar_t & symb_check);
};