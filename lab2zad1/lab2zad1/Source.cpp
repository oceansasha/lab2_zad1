#include<iostream>
#include "fstream"
#include "stdlib.h"
#include <stdio.h>
#include <math.h>

using namespace std;

class Complex { // приватная часть
	float Re;
	float Im;
	float mod; // сравнение по модулю

public:
	Complex(float a) { // констр-р с одним числом
		set(a, 0);
	}

	Complex(Complex& c) { // констр-р копирования
		float a, b;
		c.get(a, b);
		Re = a;
		Im = b;
	}

	Complex() { set(0, 0); }; // констр-р по умолчанию

	Complex(float a, float b) { set(a, b); }; // констр-р с параметрами; метод set
	
	void set(float a, float b) { //метод для чисел
		Re = a; // вещ часть
		Im = b; // мнимая часть
		mod = sqrt(a * a + b * b);
	}

	void get(float& a, float& b) { // метод, подающий числа
		a = Re;
		b = Im;
	}

	Complex operator+ (Complex& c) { // сумма
		float a, b;
		c.get(a, b);
		Complex c1(Re + a, Im + b);
		return c1;
	}

	Complex operator- (Complex& c) { // разность
		float a, b;
		c.get(a, b);
		Complex c1(Re - a, Im - b);
		return c1;
	}

	Complex operator* (Complex& c) { // умножение
		float a, b;
		c.get(a, b);
		Complex c1(Re * a - Im * b, Im * a + Re * b);
		return c1;
	}

	Complex operator/ (Complex& c) { // деление
		float a, b;
		c.get(a, b);
		Complex c1((Re * a + Im * b) / (a * a + b * b), (Im * a - Re * b) / (a * a + b * b));
		return c1;
	}

	//-----------булевские операции-------
	bool operator> (Complex& c) { 
		if (mod > c.getmod())
			return true;
		else return false;
	}

	bool operator< (Complex& c) {
		if (mod < c.getmod())
			return true;
		else return false;
	}

	bool operator== (Complex& c) {
		if (mod == c.getmod())
			return true;
		else return false;
	}

	bool operator!= (Complex& c) {
		if (mod != c.getmod())
			return true;
		else return false;
	}

	float getmod() {
		return mod;
	}

	//--------друж-е ф-ции--------
	friend void input(Complex& c); // ввод
	friend void print(Complex& c); //вывод
};

//--------вывод--------
void print(Complex& c) {
	if (c.Im == 0)
		cout << c.Re << endl;
	else {
		if (c.Im > 0)
			cout << c.Re << "+" << c.Im << "i" << endl;
		else
			cout << c.Re << c.Im << "i" << endl;
	}
}

//--------ввод--------
void input(Complex& c) {
	float a, b;
	cout << "Введите вещественную часть " << endl;
	cin >> a;
	cout << "Введите мнимую часть " << endl;
	cin >> b;
	c.set(a, b);
}

//--------------------
int main() {
	setlocale(LC_ALL, "");
	Complex R;
	Complex C; 
	input(C); 
	input(R);
	cout << "Исходные числа " << endl; // вводим с клавиатуры
	print(C);
	print(R);

	Complex SUM;
	SUM = C + R;
	cout << "Сумма равна ";
	print(SUM);

	Complex MULT;
	MULT = C * R;
	cout << "Произведение равно ";
	print(MULT);

	Complex DIM;
	DIM = C - R;
	cout << "Разность равна ";
	print(DIM);

	Complex DIV;
	DIV = C / R;
	cout << "Частное равно ";
	print(DIV);

	if (C < R) cout << "Второе число больше";
	else if (C > R) cout << "Первое число больше";
	else cout << "Числа равны по модулю";
	return 0;
}