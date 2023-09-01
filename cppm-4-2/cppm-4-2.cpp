// cppm-4-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>
#include <windows.h>
#include <ostream>

class Addres {
	std::string street, city;
	int dom, kv;
public:
	Addres() {
		street = "unknown";
		city = "unknown";
		dom = 0;
		kv = 0;
	}
	Addres(std::string street, std::string city, int dom, int kv) {
		this->dom = dom;
		this->city = city;
		this->street = street;
		this->kv = kv;
	}
	void setStreet(std::string street) {
		this->street = street;
	}
	void setCity(std::string city) {
		this->city = city;
	}
	void setKv(int kv) {
		this->kv = kv;
	}
	void setDom(int dom) {
		this->dom = dom;
	}
	std::string getStreet() {
		return street;
	}
	std::string getCity() {
		return city;
	}
	int getKv() {
		return kv;
	}
	int getDom() {
		return dom;
	}
};

int main()
{
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");
	if (!fin.is_open()) {
		std::cout << "File not found!\n";
		return 1;
	}
	int n;
	fin >> n;
	Addres* adress = new Addres[n];

	for (int i = 0; i < n; ++i) {
		std::string a, b;
		int c, d;
		fin >> a >> b >> c >> d;
		adress[i].setCity(a);
		adress[i].setDom(c);
		adress[i].setStreet(b);
		adress[i].setKv(d);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			if (adress[j].getCity() < adress[j-1].getCity()) {
				std::swap(adress[j - 1], adress[j]);
			}
		}
	}

	fout << n << "\n";
	for (int i = 0; i < n; ++i) {
		fout << adress[i].getCity() << ", " << adress[i].getStreet() << ", " << adress[i].getDom() << ", " << adress[i].getKv() << "\n";
	}
	delete[] adress;
	fin.close();
	fout.close();


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
