#pragma once
#include <iostream>
#include <string>
#include <vector>

class GetRightWString
{
public:
	//����������� �� ���������
	GetRightWString();
	//�������� �� ���������� ���������� ����
	int CheckWords(const wchar_t& symb_check);
	//���������� �� ����������� ����
	void getSimilarWords();
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
	//����� ����������� ������� � ������� � ���������� ��� � ������
	void AddAndWriteSymb(const wchar_t& symb);
	//�������� �� ������ ��������� ���������
	bool CheckCyrillicAlpha(const wchar_t& symb_check);
	//�������� �� ������ �������
	bool CheckSpace(const wchar_t & symb_check);
	//�������� �� ������ Backspace
	bool CheckBackspace(const wchar_t & symb_check);
};