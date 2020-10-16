#include<iostream>
#include "fstream"
#include "stdlib.h"
#include <stdio.h>
#include <math.h>

using namespace std;

class Complex { // ��������� �����
	float Re;
	float Im;
	float mod; // ��������� �� ������

public:
	Complex(float a) { // ������-� � ����� ������
		set(a, 0);
	}

	Complex(Complex& c) { // ������-� �����������
		float a, b;
		c.get(a, b);
		Re = a;
		Im = b;
	}

	Complex() { set(0, 0); }; // ������-� �� ���������

	Complex(float a, float b) { set(a, b); }; // ������-� � �����������; ����� set
	
	void set(float a, float b) { //����� ��� �����
		Re = a; // ��� �����
		Im = b; // ������ �����
		mod = sqrt(a * a + b * b);
	}

	void get(float& a, float& b) { // �����, �������� �����
		a = Re;
		b = Im;
	}

	Complex operator+ (Complex& c) { // �����
		float a, b;
		c.get(a, b);
		Complex c1(Re + a, Im + b);
		return c1;
	}

	Complex operator- (Complex& c) { // ��������
		float a, b;
		c.get(a, b);
		Complex c1(Re - a, Im - b);
		return c1;
	}

	Complex operator* (Complex& c) { // ���������
		float a, b;
		c.get(a, b);
		Complex c1(Re * a - Im * b, Im * a + Re * b);
		return c1;
	}

	Complex operator/ (Complex& c) { // �������
		float a, b;
		c.get(a, b);
		Complex c1((Re * a + Im * b) / (a * a + b * b), (Im * a - Re * b) / (a * a + b * b));
		return c1;
	}

	//-----------��������� ��������-------
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

	//--------����-� �-���--------
	friend void input(Complex& c); // ����
	friend void print(Complex& c); //�����
};

//--------�����--------
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

//--------����--------
void input(Complex& c) {
	float a, b;
	cout << "������� ������������ ����� " << endl;
	cin >> a;
	cout << "������� ������ ����� " << endl;
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
	cout << "�������� ����� " << endl; // ������ � ����������
	print(C);
	print(R);

	Complex SUM;
	SUM = C + R;
	cout << "����� ����� ";
	print(SUM);

	Complex MULT;
	MULT = C * R;
	cout << "������������ ����� ";
	print(MULT);

	Complex DIM;
	DIM = C - R;
	cout << "�������� ����� ";
	print(DIM);

	Complex DIV;
	DIV = C / R;
	cout << "������� ����� ";
	print(DIV);

	if (C < R) cout << "������ ����� ������";
	else if (C > R) cout << "������ ����� ������";
	else cout << "����� ����� �� ������";
	return 0;
}