//#include "Fraction.h"
//Fraction::Fraction() {
//}
//Fraction::Fraction(int x) {
//	this->n = x;
//	this->d = 1;
//}
//Fraction::Fraction(int n, int d) {
//	this->n = n;
//	this->d = d;
//}
//Fraction::~Fraction() {
//}
//Fraction Fraction::operator+(const Fraction& ft)const {
//	Fraction temp;
//	temp.d = this->d * ft.d;
//	temp.n = this->n * ft.d + this->d * ft.n;
//	return temp;
//}
//Fraction Fraction::operator-(const Fraction& ft)const {
//	Fraction temp;
//	temp.d = this->d * ft.d;
//	temp.n = this->n * ft.d - this->d * ft.n;
//	return temp;
//}
//Fraction Fraction::operator*(const Fraction& ft)const {
//	Fraction temp;
//	temp.d = this->d * ft.d;
//	temp.n = this->n * ft.n;
//	return temp;
//}
//Fraction Fraction::operator/(const Fraction& ft)const {
//	Fraction temp;
//	temp.d = this->d * ft.n;
//	temp.n = this->n * ft.d;
//	return temp;
//}
//Fraction Fraction::operator=(const Fraction& ft) {
//	this->n = ft.n;
//	this->d = ft.d;
//	return *this;
//}
//istream& operator >> (istream& ist, Fraction& ft) {
//	ist >> ft.n;
//	ist >> ft.d;
//	return ist;
//}
//int UCLN(int a, int b) {
//	while (a * b != 0) {
//		if (a > b)
//			a = a % b;
//		else
//			b = b % a;
//	}
//	return a + b;
//}
//ostream& operator << (ostream& ost, const Fraction& ft) {
//	int k = UCLN(ft.n, ft.d);
//	ost << ft.n / k << "/" << ft.d / k;
//	return ost;
//}