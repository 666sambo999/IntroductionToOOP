#include "string.h"


//#define CONSTRUCTOR_CHECK
#define HOME_WORK
//#define IOSTREAM
//#define CLASS_RABOTA
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTOR_CHECK
	String str1;		// Default constructor
	str1.print();

	//String str2 = 16; // Конструктор с одним параметром Single-argumen 
	String str2(16);
	str2.print(); // explicit конструктор невозможно вызвать оператором присвоить
	// его можно выхвать только так

	String str3 = "Hello";
	str3 = str3; 
	str3.print();

	//String str4 = str3; //Copy constructor
	String str4; //Copy constructor
	str4 = str3; // оператор присваивания 
	
	str4.print();// ошибка Debug когда удаляеться два раза одна и таже память

#endif // CONSTRUCTOR_CHECK
	
#ifdef HOME_WORK
	String str1 = "Hello";
	String str2 = "World";
	str1 += str2;
	cout << delimeter << endl; 
	cout << str1 << endl; 
	cout << delimeter << endl; 

	String str3 = str1;
	str3.print();
	//String str3 = str1 + " "+ str2; // Move contructor
	//String str3;
	//str3 = str1 + str2; // move assignment 
	//cout << str1 << "+" << str2 << "=" << str3 << endl;
#endif // HOME_WORK

#ifdef IOSTREAM
			/*String str;
str.print();
cout << "Введите строку: "; cin >> str;
cout << str << endl;*/
	String last_name;
	String first_name;
	cout << "Введите Ваше имя: "; cin >> last_name >> first_name;
	cout << last_name << " " << first_name << endl;
#endif // IOSTREAM

#ifdef CLASS_RABOTA
	String str1; //Default construtor
	str1.print();
	String str2(8); //Single-argument construtor of type int
	str2.print();
	String str3 = "Hello"; //Single-argument construtor of type const char
	str3.print();
	String str4(); //Здесь не вызывается конструктор по умолчанию, в этой строке
	// объявляется ф-я str4, которая ничего не принимает, и возвращает 
	// значение типа String
	//str4 This is not an object 
	String str5{};
	str5.print();

	String str6{ 1234 };
	str6.print();

	String str7{ "Hello World" };
	str7.print();
#endif // CLASS_RABOTA


}