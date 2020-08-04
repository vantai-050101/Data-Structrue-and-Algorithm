#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Person {
protected:
	string type;
	string name;
	string address;
	string dateNhapcanh;
	string id;
	string placeDepart;
	float p;
public:
	Person() {};
	~Person() {};
	virtual void input();
	string getType()const;
	string getName()const;
	string getAddress()const;
	string getDateNhapcanh()const;
	string getID()const;
	string getPlaceDepart()const;
	float getP()const;
	virtual string getInfo()const;
};
class PersonVN : public Person {
public:
	PersonVN() {
		this->type = "VN";
	}
};
class notPersonVN : public Person {
private:
	string nameNguoithan;
	string addressNguoithan;
public:
	notPersonVN() {
		this->type = "notVN";
	}
	void input();
	string getNameNguoithan()const;
	string getAddressNguoithan()const;
	string getInfo()const;
};

class Khucachly {
protected:
	vector <int> list;
	string typeKhucachly;
	string nameKhucachly;
	string addressKhucachly;
	int distance;
	int capi;
	int price_everyone;
public:
	virtual void input();
	void setList(int);
	string getNameKhucachly()const;
	string getAddressKhucachly()const;
	int getDistance()const;
	int getCapi()const;
	int getPrice_everyone()const;
	string getType()const;
	virtual string getInfo()const;
	vector <int> getList()const;
};
class KhucachlyTT : public Khucachly {
public:
	KhucachlyTT() {
		this->typeKhucachly = "TT";
	}
};
class KhucachlyTNCT : public Khucachly {
public:
	KhucachlyTNCT() {
		this->typeKhucachly = "TNCT";
	}
};

class MangeCovid {
private:
	vector <Person*> listPerson;
	vector <Khucachly*> listKhucachly;
public:
	void setListPerson();
	void setListKhucachly();
	void setPersonToKhucachly();
	vector<float> Pmanbenh_max_khucachly()const;
	vector <float> Price()const;
	void getListPerson()const;
	void getListKhucachly()const;
	void getListPerson_inKhucachly()const;
	float AllPrice()const;
	float maxPrice_khucachly()const;
};

