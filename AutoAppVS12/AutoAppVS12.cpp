// AutoAppVS12.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <locale.h>
#include <map>
#include <conio.h>
using namespace std;
//using namespace System;
//Отключение предупреждениея для записи считывания из файла
#pragma warning(disable:4996)
struct Fuel //Топливо
{
public :
	int id_fuel;
	string name; //Вид топлива
	double cost; //Цена
	double amount; //Количество топлива, галлоны
} ;
struct Selling //Учет продаж
{
public:
	int id_order;
	int id_fuel;
	int id_vendor;
	double amount; //Количество топлива
};
struct Vendor //Продавец
{
public:
	int id_vendor;
	string name_vendor; //Имя продавца
};
struct Purchase //Закупки топлива
{
public:
	int id_purchase;
	int id_agent; //Имя контрагента
	int id_fuel;
	double amount; //Количество топлива
};
struct Agent //Контрагент
{
public:
	int id_agent;
	string name_agent; //Имя контрагента
};

class AutoClass
{
public:
	map <int,Fuel> fuels;
	map <int,Selling> sellings; //зависимые
	map <int,Vendor> vendors; 
	map <int,Purchase> purchases; //не зависимые
	map <int,Agent> agents;

	void inputFuel(Fuel fuel);//Ввод в map одного элемента
	void inputSelling(Selling selling);
	void inputVendor(Vendor vendor);
	void inputPurchase(Purchase Purchase);
	void inputAgent(Agent agent);

	void inputAllFuel();//Ввод в map
	void inputAllSelling();
	void inputAllVendor();
	void inputAllPurchase();
	void inputAllAgent();

	void addFuel(Fuel fuel);//Добавление в map одного элемента
	void addSelling(Selling selling);
	void addVendor(Vendor vendor);
	void addPurchase(Purchase Purchase);
	void addAgent(Agent agent);

	void updateFuel(Fuel fuel);//Обновление в map одного элемента
	void updateSelling(Selling selling);
	void updateVendor(Vendor vendor);
	void updatePurchase(Purchase Purchase);
	void updateAgent(Agent agent);

	void deleteFuel(Fuel fuel);//Удаление из map одного элемента
	void deleteSelling(Selling selling);
	void deleteVendor(Vendor vendor);
	void deletePurchase(Purchase Purchase);
	void deleteAgent(Agent agent);

	void outputFuel(Fuel fuel);//Вывод на экран одного элемента
	void outputSelling(Selling selling);
	void outputVendor(Vendor vendor);
	void outputPurchase(Purchase Purchase);
	void outputAgent(Agent agent);

	void outputAllFuel();//Вывод map на экран
	void outputAllSelling();
	void outputAllVendor();
	void outputAllPurchase();
	void outputAllAgent();

	void readFromFuels();//Чтение из файла в список
	void readFromSelling();
	void readFromVendors();
	void readFromPurchases();
	void readFromAgents();

	void writeFuels();//Запись из списка в файл
	void writeSelling();
	void writeVendors();
	void writePurchases();
	void writeAgents();


};

//Перегрузка вывода на экран структуры-сущности топлива, позже будет заменена более простым вариантом вывода.
std::ostream& operator<<(std::ostream& fout, const Fuel& fuel)
{
	//for (auto& el : )
	{
		fout << "Fuel: " << fuel.id_fuel << endl;
		fout << "Cost: " << fuel.cost << endl;
		fout << "Name: " << fuel.name << endl;
		fout << "Amount: " << fuel.amount << endl;
	}
	return fout;
}

//Точка входа в программу
int main()
{
	//создание списка map c сущностями топлива
	std::map <int, Fuel> fuels;
	setlocale(LC_ALL, "RUS");
	
	//создание структуры fuel
	Fuel *fuel = new Fuel;
	fuel->id_fuel = 1;
	fuel->name = "Lookoil";
	fuel->cost = 15.8;
	fuel->amount = 20;

	//запись в map с id_fuel объекта структуры fuel
	fuels[fuel->id_fuel] = *fuel;

	//std::cout << fuel;
	//Вывод map по id->fuel с перегрузкой вывода
	std::cout << fuels[fuel->id_fuel];
	
	//запись 1 элемента топлива в файл
	//FILE *f;
	//f = fopen("fuel.txt", "w");
	ofstream fout("fuel.txt");
	fout << "Count map: " << fuels.size() << endl;
	fout << "Fuel: " << fuel->id_fuel << endl;
	fout << "Cost: " << fuel->cost << endl;
	fout << "Name: " << fuel->name << endl;
	fout << "Amount: " << fuel->amount << endl;

	fout << "Fuel: " << fuel->id_fuel << endl;
	fout << "Cost: " << fuel->cost << endl;
	fout << "Name: " << fuel->name << endl;
	fout << "Amount: " << fuel->amount << endl;

	//fclose(f);
	int count_map;
	//чтение из файла в структуру(сущность fuel)
	//FILE *fread;
	//fread = fopen("fuel.txt", "r");
	ifstream fin("fuel.txt");
	fin.ignore(strlen("Count map: "));
	fin >> count_map;
	fin.ignore(strlen("\n"));
	fin.ignore(strlen("Fuel: "));
	fin >> fuel->id_fuel;
	fin.ignore(strlen("\n"));
	fin.ignore(strlen("Cost: ")); 
	fin >> fuel->cost; 
	fin.ignore(strlen("\n"));
	fin.ignore(strlen("Name: "));
	fin >> fuel->name; 
	fin.ignore(strlen("\n"));
	fin.ignore(strlen("Amount: "));
	fin >> fuel->amount;
	fin.ignore(strlen("\n"));
	//fclose(fread);
	
	//Вывод вида топлива на экран
	std::cout << fuel->name<<endl;

	AutoClass *autoObjs = new AutoClass[5];
	AutoClass currAutoObj;
	currAutoObj=autoObjs[0];
	//Заготовка меню для пункта 8 из общего задания
	//Вывод меню
	int choose = 0;
	do
	{
		std::cout << "1 - Выбор элемента из массива, с которым планируется работать.\n";
		std::cout << "2 - Cписок действий\n";
		std::cout << "0 - Завершение программы\n";
		std::cout << "Введите число, для выбора действия!\n";
			cin >> choose;
			if (choose == 1){
				cout << "Выберите один из 5(1-5) элемент с которым планируете работать\n";
				int elem;
				cin>>elem;
				if(elem < 1 || elem > 5)
					cout << "Вы ввели не верный элемент\n";
				else
				{
					cout << "Вы выбрали элемент с номером: " << elem << endl;
					currAutoObj = autoObjs[elem-1];
				}
			}
			if (choose == 2)
			{
				do
				{
					std::cout << "1 - Загрузить из файла\n";
					std::cout << "2 - Топливо - Сущность 1\n";
					std::cout << "3 - Учет продаж - Сущность 2\n";
					std::cout << "4 - Продавец - Сущность 3\n";
					std::cout << "5 - Закупки топлива - Сущность 4\n";
					std::cout << "6 - Контрагент - Сущность 5\n";
					std::cout << "7 - Сформировать отчет 1\n";
					std::cout << "8 - Сформировать отчет 2 и т.д.\n";
					std::cout << "9 - Сохранить в файл\n";
					std::cout << "10 - Перейти к другому элементу(вернутся к первому уровню).\n";
					std::cout << "Введите число, для выбора действия!\n";
					cin >> choose;
					if (choose == 1)
						0;
					if (choose == 2 || choose == 3 || choose == 4 || choose == 5) {
						do {
							std::cout << "1 - добавить\n";
							std::cout << "2 - изменить\n";
							std::cout << "3 - удалить\n";
							std::cout << "4 - вывести на экран\n";
							std::cout << "5 - вернутся к списку действий\n";
							std::cout << "Введите число, для выбора действия!\n";
							cin >> choose;
							if (choose == 1)
								0;
							if (choose == 2)
								0;
							if (choose == 3)
								0;
							if (choose == 4)
								0;
						} while (choose != 5);
					}
					if (choose == 6)
						0;
					if (choose == 7)
						0;
					if (choose == 8)
						0;
				} while (choose != 10);
			} 
		
	} while (choose != 0);
	std::cout << "Нажмите любую клавишу для выхода\n";
	getch();
    return 0;
}


