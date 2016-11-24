// AutoAppVS12.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <locale.h>
#include <map>
#include <conio.h>
#include "AutoApp.h"
using namespace std;
using namespace System;
//Отключение предупреждениея для записи считывания из файла
#pragma warning(disable:4996)

#pragma region structs
struct Fuel //Топливо
{
public :
	int id_fuel; //Номер топлива, 2
	string name; //Вид топлива, 3
	double cost; //Цена, 4
	double amount; //Количество топлива, галлоны, 5
} ;
struct Selling //Учет продаж
{
public:
	int id_order; //Номер заказа, 2
	int id_fuel; //Номер вида топлива, 3
	int id_vendor; //Номер продавца, 4
	double amount; //Количество топлива,5
};
struct Vendor //Продавец
{
public:
	int id_vendor; //Номер продавца, 2
	string name_vendor; //Имя продавца, 3
};
struct Purchase //Закупки топлива
{
public:
	int id_purchase; //Номер закупки топлива, 2
	int id_agent; //Номер контрагента, 3
	int id_fuel; //Номер вида топлива, 4
	double amount; //Количество топлива, 5
};
struct Agent //Контрагент
{
public:
	int id_agent; //Номер контрагента, 2
	string name_agent; //Имя контрагента, 3
};

#pragma endregion structs

class AutoClass
{
public:

#pragma region constants

	const string* Fuels = new string [6]{
		"fuel.txt","Count map: ","Fuel: ","Cost: ","Name: ","Amount: "
	};//"fuel.txt","Count map: ","Fuel: ","Cost: ","Name: ","Amount: "
	
	const string* Sellings = new string[6]{
		"selling.txt","Count map: ","Selling: ","id Fuel: ","id Vendor: ","Amount: "
	};//"selling.txt","Count map: ","Selling: ","id Fuel: ","id Vendor: ","Amount: "

	const string* Vendors = new string[4]{
		"vendor.txt","Count map: ","Vendor: ","Name: "
	};//"vendor.txt","Count map: ","Vendor: ","Name: "

	const string* Purchases = new string[6]{
		"purchase.txt","Count map: ","Purchase: ","id Agent: ","id Fuel: ","Amount: "
	};//"purchase.txt","Count map: ","Purchase: ","id Agent: ","id Fuel: ","Amount: "

	const string* Agents = new string[4]{
		"agent.txt","Count map: ","Agent: ","Name: "
	};//"agent.txt","Count map: ","Agent: ","Name: "

#pragma endregion constants

	map <int,Fuel> fuels; //не зависимые
	map <int,Selling> sellings; //зависимые
	map <int,Vendor> vendors; //не зависимые
	map <int,Purchase> purchases; //зависимые
	map <int,Agent> agents; //не зависимые

#pragma region prototype
		
	void inputFuel(Fuel fuel);//Ввод в map одного элемента
	void inputSelling(Selling selling);
	void inputVendor(Vendor vendor);
	void inputPurchase(Purchase purchase);
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

	void readFromAll();

	void writeFuels();//Запись из списка в файл
	void writeSelling();
	void writeVendors();
	void writePurchases();
	void writeAgents();

	void writeAll();

#pragma endregion prototype
};

//Точка входа в программу
int main()
{
	setlocale(LC_ALL, "RUS");
	
	AutoClass *autoObjs = new AutoClass[5];
	AutoClass currAutoObj;
	currAutoObj=autoObjs[0];
	//Заготовка меню для пункта 8 из общего задания
	//Вывод меню
	int choose = 0;
	do
	{
#pragma region 1_level
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
#pragma region 2_level
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
						currAutoObj.readFromAll();
					if (choose == 2 || choose == 3 || choose == 4 || choose == 5 || choose == 6) {
						int chooseEntity = choose;
						do {
#pragma region 3_level
							std::cout << "1 - добавить\n";
							std::cout << "2 - изменить\n";
							std::cout << "3 - удалить\n";
							std::cout << "4 - вывести на экран\n";
							std::cout << "5 - вернутся к списку действий\n";
							std::cout << "Введите число, для выбора действия!\n";
							cin >> choose;
							if (choose == 1)
							{
								int id;
								std::cout << "Введите номер добавляемой сущности" << endl;
								std::cin >> id;
								if (chooseEntity == 2)
								{
									currAutoObj.addFuel(Fuel{ id = id });
								}
								if (chooseEntity == 3)
									currAutoObj.addSelling(Selling{ id = id });
								if (chooseEntity == 4)
									currAutoObj.addVendor(Vendor{ id = id });
								if (chooseEntity == 5)
									currAutoObj.addPurchase(Purchase{ id = id });
								if (chooseEntity == 6)
									currAutoObj.addAgent(Agent{ id = id });
							}
							if (choose == 2)
							{
								int id;
								std::cout << "Введите номер обновляемой сущности" << endl;
								std::cin >> id;
								if (chooseEntity == 2)
								{
									currAutoObj.updateFuel(Fuel{ id = id });
								}
								if (chooseEntity == 3)
									currAutoObj.updateSelling(Selling{ id = id });
								if (chooseEntity == 4)
									currAutoObj.updateVendor(Vendor{ id = id });
								if (chooseEntity == 5)
									currAutoObj.updatePurchase(Purchase{ id = id });
								if (chooseEntity == 6)
									currAutoObj.updateAgent(Agent{ id = id });
							}
							if (choose == 3)
							{
								int id;
								std::cout << "Введите номер удаляемой сущности" << endl;
								std::cin >> id;
								if (chooseEntity == 2)
								{
									currAutoObj.deleteFuel(Fuel{ id = id });
								}
								if (chooseEntity == 3)
									currAutoObj.deleteSelling(Selling{ id = id });
								if (chooseEntity == 4)
									currAutoObj.deleteVendor(Vendor{ id = id });
								if (chooseEntity == 5)
									currAutoObj.deletePurchase(Purchase{ id = id });
								if (chooseEntity == 6)
									currAutoObj.deleteAgent(Agent{ id = id });
							}
							if (choose == 4)
							{
								
								if (chooseEntity == 2)
								{
									currAutoObj.outputAllFuel();
								}
								if (chooseEntity == 3)
									currAutoObj.outputAllSelling();
								if (chooseEntity == 4)
									currAutoObj.outputAllVendor();
								if (chooseEntity == 5)
									currAutoObj.outputAllPurchase();
								if (chooseEntity == 6)
									currAutoObj.outputAllAgent();
							}
#pragma endregion 3_level
						} while (choose != 5);
					}					
					if (choose == 7)
						0;
					if (choose == 8)
						0;
					if (choose == 9)
						currAutoObj.writeAll();
#pragma endregion 2_level
				} while (choose != 10);
			} 
#pragma endregion 1_level		
	} while (choose != 0);
	std::cout << "Нажмите любую клавишу для выхода\n";
	getch();
    return 0;
}

void AutoClass::inputFuel(Fuel fuel)
{
	fuels[fuel.id_fuel] = fuel;

}

void AutoClass::inputSelling(Selling selling)
{
	sellings[selling.id_fuel] = selling;
}

void AutoClass::inputVendor(Vendor vendor)
{
	vendors[vendor.id_vendor] = vendor;
}

void AutoClass::inputPurchase(Purchase purchase)
{
	purchases[purchase.id_purchase] = purchase;
}

void AutoClass::inputAgent(Agent agent)
{
	agents[agent.id_agent] = agent;
}

void AutoClass::inputAllFuel()
{
}

void AutoClass::inputAllSelling()
{
}

void AutoClass::inputAllVendor()
{
}

void AutoClass::inputAllPurchase()
{
}

void AutoClass::inputAllAgent()
{
}

#pragma region add

void AutoClass::addFuel(Fuel fuel)
{
	std::cout << "Введите Название вида топлива" << std::endl;
	std::cin >> fuel.name;
	std::cout << "Введите цену топлива" << std::endl;
	std::cin >> fuel.cost;

	std::cout << "Введите количество вида топлива" << std::endl;
	std::cin >> fuel.amount;
	inputFuel(fuel);
}

void AutoClass::addSelling(Selling selling)
{
	bool verify = true;
	string verifyString = "";
	std::cout << "Введите Номер вида топлива" << std::endl;
	std::cin >> selling.id_fuel;
	if (!std::cin)
	{
		verify = false;
		std::cout << "Введено не целое число\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	}
	std::cout << "Введите номер продавца" << std::endl;
	std::cin >> selling.id_vendor;
	if (!std::cin)
	{
		verify = false;
		std::cout << "Введено не целое число\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	}
	
	
	std::cout << "Введите количество топлива" << std::endl;
	std::cin >> selling.amount;
	if (!std::cin)
	{
		verify = false;
		std::cout << "Введено не вещественное число\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	}
	if(verify)
		inputSelling(selling);
}

void AutoClass::addVendor(Vendor vendor)
{
	std::cout << "Введите Имя продавца" << std::endl;
	std::cin >> vendor.name_vendor;
	inputVendor(vendor);
}

void AutoClass::addPurchase(Purchase purchase)
{
	bool verify = true;
	std::cout << "Введите Номер агента" << std::endl;
	std::cin >> purchase.id_agent;
	if (!std::cin)
	{
		verify = false;
		std::cout << "Введено не целое число\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	}
	std::cout << "Введите номер вида топлива" << std::endl;
	std::cin >> purchase.id_fuel;
	if (!std::cin)
	{
		verify = false;
		std::cout << "Введено не целое число\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	}
	std::cout << "Введите количество топлива" << std::endl;
	std::cin >> purchase.amount;
	if (!std::cin)
	{
		verify = false;
		std::cout << "Введено не вещественное число\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	}
	if(verify)
		inputPurchase(purchase);
}

void AutoClass::addAgent(Agent agent)
{
	std::cout << "Введите Имя агента" << std::endl;
	std::cin >> agent.name_agent;	
	inputAgent(agent);
}

#pragma endregion add

#pragma region update

void AutoClass::updateFuel(Fuel fuel)
{
	addFuel(fuel);
}

void AutoClass::updateSelling(Selling selling)
{
	addSelling(selling);
}

void AutoClass::updateVendor(Vendor vendor)
{
	addVendor(vendor);
}

void AutoClass::updatePurchase(Purchase purchase)
{
	addPurchase(purchase);
}

void AutoClass::updateAgent(Agent agent)
{
	addAgent(agent);
}

#pragma endregion update

#pragma region delete

void AutoClass::deleteFuel(Fuel fuel)
{
	bool exist = false;

	for (std::map<int, Selling>::iterator selling = sellings.begin(); selling != sellings.end(); ++selling)
	{
		if (selling->second.id_fuel == fuel.id_fuel)
		{
			exist = true;
		}
	}

	for (std::map<int, Purchase>::iterator purchase = purchases.begin(); purchase != purchases.end(); ++purchase)
	{
		if (purchase->second.id_fuel == fuel.id_fuel)
		{
			exist = true;
		}
	}

	if (!exist)
	{
		fuels.erase(fuel.id_fuel);
		std::cout << "Успешно удалено!" << std::endl;
	}
	else
		std::cout << "Удалите номер из зависимых сущностей!\n";
}

void AutoClass::deleteSelling(Selling selling)
{

	sellings.erase(selling.id_order);
	std::cout << "Успешно удалено!" << std::endl;
}

void AutoClass::deleteVendor(Vendor vendor)
{

	bool exist = false;

	for (std::map<int, Selling>::iterator selling = sellings.begin(); selling != sellings.end(); ++selling)
	{
		if (selling->second.id_vendor == vendor.id_vendor)
		{
			exist = true;
		}
	}

	
	if (!exist)
	{
		vendors.erase(vendor.id_vendor);
		std::cout << "Успешно удалено!" << std::endl;
	}
	else
		std::cout << "Удалите номер из зависимой сущности, Учет продаж!\n";
}

void AutoClass::deletePurchase(Purchase purchase)
{
	purchases.erase(purchase.id_purchase);
	std::cout << "Успешно удалено!" << std::endl;
}

void AutoClass::deleteAgent(Agent agent)
{
	bool exist = false;

	
	for (std::map<int, Purchase>::iterator purchase = purchases.begin(); purchase != purchases.end(); ++purchase)
	{
		if (purchase->second.id_agent == agent.id_agent)
		{
			exist = true;
		}
	}

	if (!exist)
	{
		agents.erase(agent.id_agent);
		std::cout << "Успешно удалено!" << std::endl;
	}
	else
		std::cout << "Удалите номер из зависимой сущности, Закупки топлива!\n";
}

#pragma endregion delete

#pragma region output

void AutoClass::outputFuel(Fuel fuel)
{ 
	std::map<int, Fuel>::iterator fuelIter = fuels.find(fuel.id_fuel);
	cout << Fuels[2] << fuelIter->second.id_fuel << endl;
	cout << Fuels[3] << fuelIter->second.cost << endl;
	cout << Fuels[4] << fuelIter->second.name << endl;
	cout << Fuels[5] << fuelIter->second.amount << endl;
}

void AutoClass::outputSelling(Selling selling)
{
	std::map<int, Selling>::iterator sellingIter = sellings.find(selling.id_order);
	cout << Sellings[2] << sellingIter->second.id_order << endl;
	cout << Sellings[3] << sellingIter->second.id_fuel << endl;
	cout << Sellings[4] << sellingIter->second.id_vendor << endl;
	cout << Sellings[5] << sellingIter->second.amount << endl;
}

void AutoClass::outputVendor(Vendor vendor)
{
	std::map<int, Vendor>::iterator vendorIter = vendors.find(vendor.id_vendor);
	cout << Vendors[2] << vendorIter->second.id_vendor << endl;
	cout << Vendors[3] << vendorIter->second.name_vendor << endl;
}

void AutoClass::outputPurchase(Purchase purchase)
{
	std::map<int, Purchase>::iterator purchaseIter = purchases.find(purchase.id_purchase);
	cout << Purchases[2] << purchaseIter->second.id_purchase << endl;
	cout << Purchases[3] << purchaseIter->second.id_agent << endl;
	cout << Purchases[4] << purchaseIter->second.id_fuel << endl;
	cout << Purchases[5] << purchaseIter->second.amount << endl;
}

void AutoClass::outputAgent(Agent agent)
{
	std::map<int, Agent>::iterator agentIter = agents.find(agent.id_agent);
	cout << Agents[2] << agentIter->second.id_agent << endl;
	cout << Agents[3] << agentIter->second.name_agent << endl;
}

void AutoClass::outputAllFuel()
{	
	for (std::map<int, Fuel>::iterator fuel = fuels.begin(); fuel != fuels.end(); ++fuel)
	{
		cout << Fuels[2] << fuel->second.id_fuel << endl;
		cout << Fuels[3] << fuel->second.cost << endl;
		cout << Fuels[4] << fuel->second.name << endl;
		cout << Fuels[5] << fuel->second.amount << endl;
	}
}

void AutoClass::outputAllSelling()
{
	for (std::map<int, Selling>::iterator selling = sellings.begin(); selling != sellings.end(); ++selling)
	{
		cout << Sellings[2] << selling->second.id_order << endl;
		cout << Sellings[3] << selling->second.id_fuel << endl;
		cout << Sellings[4] << selling->second.id_vendor << endl;
		cout << Sellings[5] << selling->second.amount << endl;
	}
}

void AutoClass::outputAllVendor()
{
	for (std::map<int, Vendor>::iterator vendor = vendors.begin(); vendor != vendors.end(); ++vendor)
	{
		cout << Vendors[2] << vendor->second.id_vendor << endl;
		cout << Vendors[3] << vendor->second.name_vendor << endl;
	}
}

void AutoClass::outputAllPurchase()
{
	for (std::map<int, Purchase>::iterator purchase = purchases.begin(); purchase != purchases.end(); ++purchase)
	{
		cout << Purchases[2] << purchase->second.id_purchase << endl;
		cout << Purchases[3] << purchase->second.id_agent << endl;
		cout << Purchases[4] << purchase->second.id_fuel << endl;
		cout << Purchases[5] << purchase->second.amount << endl;
	}
}

void AutoClass::outputAllAgent()
{
	for (std::map<int, Agent>::iterator agent = agents.begin(); agent != agents.end(); ++agent)
	{
		cout << Agents[2] << agent->second.id_agent << endl;
		cout << Agents[3] << agent->second.name_agent << endl;
	}
}

#pragma endregion output

#pragma region write

void AutoClass::writeFuels()
{
	ofstream fout(Fuels[0]);
	fout << Fuels[1] << fuels.size() << endl;
	for (std::map<int, Fuel>::iterator fuel = fuels.begin(); fuel != fuels.end(); ++fuel)
	{
		fout << Fuels[2] << fuel->second.id_fuel << endl;
		fout << Fuels[3] << fuel->second.cost << endl;
		fout << Fuels[4] << fuel->second.name << endl;
		fout << Fuels[5] << fuel->second.amount << endl;
	}
	
}

void AutoClass::writeSelling()
{
	ofstream fout(Sellings[0]);
	fout << Sellings[1] << sellings.size() << endl;
	for (std::map<int, Selling>::iterator selling = sellings.begin(); selling != sellings.end(); ++selling)
	{
		fout << Sellings[2] << selling->second.id_order << endl;
		fout << Sellings[3] << selling->second.id_fuel << endl;
		fout << Sellings[4] << selling->second.id_vendor << endl;
		fout << Sellings[5] << selling->second.amount << endl;
	}
}

void AutoClass::writeVendors()
{
	ofstream fout(Vendors[0]);
	fout << Vendors[1] << vendors.size() << endl;
	for (std::map<int, Vendor>::iterator vendor = vendors.begin(); vendor != vendors.end(); ++vendor)
	{
		fout << Vendors[2] << vendor->second.id_vendor << endl;
		fout << Vendors[3] << vendor->second.name_vendor << endl;
	}
}

void AutoClass::writePurchases()
{
	ofstream fout(Purchases[0]);
	fout << Purchases[1] << purchases.size() << endl;
	for (std::map<int, Purchase>::iterator purchase = purchases.begin(); purchase != purchases.end(); ++purchase)
	{
		fout << Purchases[2] << purchase->second.id_purchase << endl;
		fout << Purchases[3] << purchase->second.id_agent << endl;
		fout << Purchases[4] << purchase->second.id_fuel << endl;
		fout << Purchases[5] << purchase->second.amount << endl;
	}
}

void AutoClass::writeAgents()
{
	ofstream fout(Agents[0]);
	fout << Agents[1] << agents.size() << endl;
	for (std::map<int, Agent>::iterator agent = agents.begin(); agent != agents.end(); ++agent)
	{
		fout << Agents[2] << agent->second.id_agent << endl;
		fout << Agents[3] << agent->second.name_agent << endl;		
	}
}

void AutoClass::writeAll()
{
	writeFuels();
	writeSelling();
	writeVendors();
	writePurchases();
	writeAgents();
}

#pragma endregion write

#pragma region readFromStructure

void AutoClass::readFromAll()
{
	readFromFuels();
	readFromSelling();
	readFromVendors();
	readFromPurchases();
	readFromAgents();
}

void AutoClass::readFromFuels()
{
	Fuel fuel;
	int count_map;
	//чтение из файла в структуру(сущность fuel)
	//FILE *fread;
	//fread = fopen("fuel.txt", "r");
	ifstream fin(Fuels[0]);
	fin.ignore(Fuels[1].size());
	fin >> count_map;
	fin.ignore(strlen("\n"));
	for (int i = 0; i < count_map; i++)
	{
		//fin.ignore(strlen("Fuel: "));
		fin.ignore(Fuels[2].size());
		fin >> fuel.id_fuel;
		fin.ignore(strlen("\n"));
		//fin.ignore(strlen("Cost: "));
		fin.ignore(Fuels[3].size());
		fin >> fuel.cost;
		fin.ignore(strlen("\n"));
		//fin.ignore(strlen("Name: "));
		fin.ignore(Fuels[4].size());
		fin >> fuel.name;
		fin.ignore(strlen("\n"));
		fin.ignore(Fuels[5].size());
		//fin.ignore(strlen("Amount: "));
		fin >> fuel.amount;
		fin.ignore(strlen("\n"));
		fuels[fuel.id_fuel] = fuel;
	}
}

void AutoClass::readFromSelling()
{
	Selling selling;
	int count_map;
	ifstream fin(Sellings[0]);
	fin.ignore(Sellings[1].size());
	fin >> count_map;
	fin.ignore(strlen("\n"));
	for (int i = 0; i < count_map; i++)
	{		
		fin.ignore(Sellings[2].size());
		fin >> selling.id_order;
		fin.ignore(strlen("\n"));

		fin.ignore(Sellings[3].size());
		fin >> selling.id_fuel;
		fin.ignore(strlen("\n"));

		fin.ignore(Sellings[4].size());
		fin >> selling.id_vendor;
		fin.ignore(strlen("\n"));

		fin.ignore(Sellings[5].size());
		fin >> selling.amount;
		fin.ignore(strlen("\n"));
		sellings[selling.id_order] = selling;
	}
}

void AutoClass::readFromVendors()
{
	Vendor vendor;
	int count_map;
	ifstream fin(Vendors[0]);
	fin.ignore(Vendors[1].size());
	fin >> count_map;
	fin.ignore(strlen("\n"));
	for (int i = 0; i < count_map; i++)
	{
		fin.ignore(Vendors[2].size());
		fin >> vendor.id_vendor;
		fin.ignore(strlen("\n"));

		fin.ignore(Vendors[3].size());
		fin >> vendor.name_vendor;
		fin.ignore(strlen("\n"));

	}
}

void AutoClass::readFromPurchases()
{
	Purchase purchase;
	int count_map;
	ifstream fin(Purchases[0]);
	fin.ignore(Purchases[1].size());
	fin >> count_map;
	fin.ignore(strlen("\n"));
	for (int i = 0; i < count_map; i++)
	{
		fin.ignore(Purchases[2].size());
		fin >> purchase.id_purchase;
		fin.ignore(strlen("\n"));

		fin.ignore(Purchases[3].size());
		fin >> purchase.id_agent;
		fin.ignore(strlen("\n"));

		fin.ignore(Purchases[4].size());
		fin >> purchase.id_fuel;
		fin.ignore(strlen("\n"));

		fin.ignore(Purchases[5].size());
		fin >> purchase.amount;
		fin.ignore(strlen("\n"));
		purchases[purchase.id_purchase] = purchase;
	}
}

void AutoClass::readFromAgents()
{
	Agent agent;
	int count_map;
	ifstream fin(Agents[0]);
	fin.ignore(Agents[1].size());
	fin >> count_map;
	fin.ignore(strlen("\n"));
	for (int i = 0; i < count_map; i++)
	{
		fin.ignore(Agents[2].size());
		fin >> agent.id_agent;
		fin.ignore(strlen("\n"));

		fin.ignore(Agents[3].size());
		fin >> agent.name_agent;
		fin.ignore(strlen("\n"));

	}
}

#pragma endregion readFromStructure

void checkDouble()
{

}