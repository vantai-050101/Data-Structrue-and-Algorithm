#include "MangeCovid.h"
void Person::input() {
	cout << "Name: "; cin >> this->name;
	cout << "Address: "; cin >> this->address;
	cout << "Date import: "; cin >> this->dateNhapcanh;
	cout << "ID: "; cin >> this->id;
	cout << "Place depart: "; cin >> this->placeDepart;
	cout << "Probility: "; cin >> this->p;
}
string Person::getType()const {
	return this->type;
}
string Person::getName()const {
	return this->name;
}
string Person::getAddress()const {
	return this->address;
}
string Person::getDateNhapcanh()const {
	return this->dateNhapcanh;
}
string Person::getID()const {
	return this->id;
}
string Person::getPlaceDepart()const {
	return this->placeDepart;
}
string Person::getInfo()const {
	string stt = "";
	stt += "Name: " + this->name + '\n';
	stt += "Address: " + this->address + '\n';
	stt += "Date nhap canh: " + this->dateNhapcanh + '\n';
	stt += "ID: " + this->id + '\n';
	stt += "Place depart: " + this->placeDepart + '\n';
	stt += "Probility man benh: " + to_string(this->p) + '\n';
	return stt;
}
float Person::getP()const {
	return this->p;
}

void notPersonVN::input() {
	Person::input();
	cout << "Name nguoi than: "; cin >> this->nameNguoithan;
	cout << "Address nguoi than: "; cin >> this->addressNguoithan;
}
string notPersonVN::getNameNguoithan()const {
	return this->nameNguoithan;
}
string notPersonVN::getAddressNguoithan()const {
	return this->addressNguoithan;
}
string notPersonVN::getInfo()const {
	string stt = "";
	stt += Person::getInfo();
	stt += "Name nguoi than: " + this->nameNguoithan + '\n';
	stt += "Address nguoi than: " + this->addressNguoithan + '\n';
	return stt;
}

void Khucachly::input() {
	cout << "Name khu cach ly: "; cin >> this->nameKhucachly;
	cout << "Address khu cach ly: "; cin >> this->addressKhucachly;
	cout << "Distance from Tan Son Nhat airport: "; cin >> this->distance;
	cout << "Capility: "; cin >> this->capi;
	cout << "Price tren moi nguoi: "; cin >> this->price_everyone;
}
void Khucachly::setList(int i) {
	this->list.push_back(i);
}
string Khucachly::getNameKhucachly()const {
	return this->nameKhucachly;
}
string Khucachly::getAddressKhucachly()const {
	return this->addressKhucachly;
}
int Khucachly::getDistance()const {
	return this->distance;
}
int Khucachly::getCapi()const {
	return this->capi;
}
int Khucachly::getPrice_everyone()const {
	return this->price_everyone;
}
string Khucachly::getInfo()const {
	string stt = "";
	stt += "Name khu cach ly: " + this->nameKhucachly + '\n';
	stt += "Address khu cach ly: " + this->addressKhucachly + '\n';
	stt += "Distance from Tan Son Nhat aiport: " + to_string(this->distance) + '\n';
	stt += "Capicity: " + to_string(this->capi) + '\n';
	stt += "Price on everyone: " + to_string(this->price_everyone) + '\n';
	return stt;
}
vector <int> Khucachly::getList()const {
	return this->list;
}
string Khucachly::getType()const {
	return this->typeKhucachly;
}

void MangeCovid::setListPerson() {
	int n, k;
	cout << "So luong nguoi: "; cin >> n;
	Person* p = NULL;
	for (int i = 0; i < n; i++) {
		cout << "Nhap loai(0-VN, 1-notVN): ";
		cin >> k;
		switch (k)
		{
		case 0:p = new PersonVN; break;
		case 1:p = new notPersonVN; break;
		default:
			break;
		}
		p->input();
		this->listPerson.push_back(p);
	}
}
void MangeCovid::setListKhucachly() {
	int n, k;
	cout << "So luong khu cach ly: "; cin >> n;
	Khucachly* p = NULL;
	for (int i = 0; i < n; i++) {
		cout << "Nhap loai(0-TT, 1-TNCT): ";
		cin >> k;
		switch (k)
		{
		case 0:p = new KhucachlyTT; break;
		case 1:p = new KhucachlyTNCT; break;
		default:
			break;
		}
		p->input();
		this->listKhucachly.push_back(p);
	}
}
void MangeCovid::setPersonToKhucachly() {
	int n = this->listPerson.size();
	int k;
	cout << "So luong khu cach ly: " << this->listKhucachly.size() << '\n';
	int i = 0;
	while(i<n){
		printf("Chon khu cach ly (0 - %d) cho nguoi cach ly [%d]: ", n, i);
		cin >> k;
		if (this->listPerson[i]->getType() == "VN" and this->listKhucachly[k]->getType() == "TNCT")
			cout << "Error: Nguoi VN khong duoc chon khu cach ly tu nguyen chi tra\n";
		else {
			this->listKhucachly[k]->setList(i);
			i++;
		}
	}
}
vector <float> MangeCovid::Pmanbenh_max_khucachly()const {
	vector<float> max_p;
	for (int i = 0; i < this->listKhucachly.size(); i++) {
		float max = 0;
		vector<int> list = this->listKhucachly[i]->getList();
		for (int j = 0; j < list.size(); j++)
			if (this->listPerson[list[j]]->getP() > max)
				max = this->listPerson[list[j]]->getP();
		max_p.push_back(max);
	}
	return max_p;
}
vector <float> MangeCovid::Price()const {
	vector <float> total;
	for (int i = 0; i < this->listKhucachly.size(); i++) {
		float subTotal = 0;
		if (listKhucachly[i]->getType() == "TNCT")
			subTotal += this->listKhucachly[i]->getPrice_everyone()
			* this->listKhucachly[i]->getList().size() * 1.2;
		else {
			int n_VN = 0;
			int n_notVN = 0;
			vector <int> list = this->listKhucachly[i]->getList();
			for (int j = 0; j < list.size(); j++)
				if (this->listPerson[list[j]]->getType() == "VN")
					n_VN++;
				else
					n_notVN++;
			subTotal += n_VN * this->listKhucachly[i]->getPrice_everyone();
			subTotal += n_notVN * this->listKhucachly[i]->getPrice_everyone() * 1.2;
		}
		total.push_back(subTotal);
	}
	return total;
}
float MangeCovid::AllPrice()const {
	float total_all = 0;
	vector <float> price = this->Price();
	for (int i = 0; i < price.size(); i++)
		total_all += price[i];
	return total_all;
}
float MangeCovid::maxPrice_khucachly()const {
	float max = 0;
	vector <float> price = this->Price();
	for (int i = 0; i < price.size(); i++)
		if (max < price[i])
			max = price[i];
	return max;
}
void MangeCovid::getListPerson()const {
	for (int i = 0; i < this->listPerson.size(); i++) {
		printf("Info person [%d]: \n", i);
		cout << this->listPerson[i]->getInfo();
	}
}
void MangeCovid::getListKhucachly()const {
	for (int i = 0; i < this->listKhucachly.size(); i++) {
		printf("Info khu cach ly [%d]: \n", i);
		cout << this->listKhucachly[i]->getInfo();
	}
		
}
void MangeCovid::getListPerson_inKhucachly()const {
	for (int i = 0; i < this->listKhucachly.size(); i++) {
		vector <int> temp = this->listKhucachly[i]->getList();
		printf("Khu cach ly [%d]: ", i);
		for (int j = 0; j < temp.size(); j++)
			cout << '\t' << temp[j];
		cout << '\n';
	}
}