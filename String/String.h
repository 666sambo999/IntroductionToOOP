#pragma once
#include <iostream>

using namespace std;
#define delimeter "\n--------------------------------------------"

////////////////////////////////////////////////////////////
////////////// class declaration (���������� ������)//////


class String;
String operator +(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator >>(std::istream& is, String& obj);
class String
{
	int size;		// ������ ������ � ������ 	
	char* str;		// ����� ������ � ������������ ������ 
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	// ������ �������� ����� ������ � �������������
	explicit String(int size = 256);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	// Operators
	String& operator=(const String& other);
	String& operator =(String&& other);
	String& operator +=(const String& other);
	const char& operator [](char i)const;
	char& operator [](char i);
	// Metods 
	void print()const;
};
////////// class declaration end (����� ���������� ������) /////////
/////////////////////////////////////////////////////////////////
