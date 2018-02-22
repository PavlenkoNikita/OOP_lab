#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <wchar.h>


class MyWString
{
public:
	//����������� �� ���������
	MyWString()
	{
		this->STR = L"";
		this->count_UpSymb_InWord = 0;
		this->count_words = 0;
	}

	~MyWString()
	{
	}

	//�������� �� ���������� ���������� ����
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
	//���������� �� ����������� ����
	void getSimilarWords()
	{
		bool check_words = false;
		std::wstring last_word = words.back();
		std::wstring current_word;
		for (int i = 0; last_word != words[i]; i++)
		{
			current_word = words[i];
			if (wcscmp(words[i].c_str(), last_word.c_str()) && current_word.find(current_word[i], 1) != std::string::npos)
			{
				check_words = true;
				std::wcout << current_word << L" ";
			}
		}
		if (!check_words)
		{
			std::wcout << (L"���������� �� ����������.");
		}
	}
	//���������� ������� � ������
	MyWString & operator+=(const wchar_t& symbol_add)
	{
		this->STR += symbol_add;
		return (*this);
	}
	//���������� ������� � ������
	MyWString & operator+(const wchar_t& symbol_add)
	{
		this->STR = STR + symbol_add;
		return (*this);
	}

private:
	//������
	std::wstring STR;
	//��� �����
	std::vector<std::wstring> words;
	//��������� �����
	std::wstring temp_word;
	//���������� ��������� ����
	int count_UpSymb_InWord;
	//���������� ����
	int count_words;

	//����� �������� �������
	bool CheckSymbol(const wchar_t & symb_check)
	{
		//�������� �� ������ [�-�]
		if (symb_check >= 1040 && symb_check <= 1071)
		{
			if (++this->count_UpSymb_InWord <= 8)
			{
				this->temp_word += symb_check;
				return true;
			}
			else
			{
				return false;
			}
		}
		//�������� �� ������
		else if (symb_check == 32)
		{
			if (this->count_words != 50 && (!this->temp_word.empty() || this->count_words != 0))
			{
				this->count_UpSymb_InWord = 0;
				if (this->STR[this->STR.length() - 1] != L' ')
				{
					this->words.push_back(this->temp_word);
					this->temp_word.clear();
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