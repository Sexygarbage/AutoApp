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
//���������� ��������������� ��� ������ ���������� �� �����
#pragma warning(disable:4996)
struct Fuel //�������
{
public :
	int id_fuel;
	string name; //��� �������
	double cost; //����
	double amount; //���������� �������, �������
} ;
struct Selling //���� ������
{
public:
	int id_order;
	int id_fuel;
	int id_vendor;
	double amount; //���������� �������
};
struct Vendor //��������
{
public:
	int id_vendor;
	string name_vendor; //��� ��������
};
struct Purchase //������� �������
{
public:
	int id_purchase;
	int id_agent; //��� �����������
	int id_fuel;
	double amount; //���������� �������
};
struct Agent //����������
{
public:
	int id_agent;
	string name_agent; //��� �����������
};

class AutoClass
{
public:
	map <int,Fuel> fuels;
	map <int,Selling> sellings; //���������
	map <int,Vendor> vendors; 
	map <int,Purchase> purchases; //�� ���������
	map <int,Agent> agents;

	void inputFuel(Fuel fuel);//���� � map ������ ��������
	void inputSelling(Selling selling);
	void inputVendor(Vendor vendor);
	void inputPurchase(Purchase Purchase);
	void inputAgent(Agent agent);

	void inputAllFuel();//���� � map
	void inputAllSelling();
	void inputAllVendor();
	void inputAllPurchase();
	void inputAllAgent();

	void addFuel(Fuel fuel);//���������� � map ������ ��������
	void addSelling(Selling selling);
	void addVendor(Vendor vendor);
	void addPurchase(Purchase Purchase);
	void addAgent(Agent agent);

	void updateFuel(Fuel fuel);//���������� � map ������ ��������
	void updateSelling(Selling selling);
	void updateVendor(Vendor vendor);
	void updatePurchase(Purchase Purchase);
	void updateAgent(Agent agent);

	void deleteFuel(Fuel fuel);//�������� �� map ������ ��������
	void deleteSelling(Selling selling);
	void deleteVendor(Vendor vendor);
	void deletePurchase(Purchase Purchase);
	void deleteAgent(Agent agent);

	void outputFuel(Fuel fuel);//����� �� ����� ������ ��������
	void outputSelling(Selling selling);
	void outputVendor(Vendor vendor);
	void outputPurchase(Purchase Purchase);
	void outputAgent(Agent agent);

	void outputAllFuel();//����� map �� �����
	void outputAllSelling();
	void outputAllVendor();
	void outputAllPurchase();
	void outputAllAgent();

	void readFromFuels();//������ �� ����� � ������
	void readFromSelling();
	void readFromVendors();
	void readFromPurchases();
	void readFromAgents();

	void writeFuels();//������ �� ������ � ����
	void writeSelling();
	void writeVendors();
	void writePurchases();
	void writeAgents();


};

//���������� ������ �� ����� ���������-�������� �������, ����� ����� �������� ����� ������� ��������� ������.
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

//����� ����� � ���������
int main()
{
	//�������� ������ map c ���������� �������
	std::map <int, Fuel> fuels;
	setlocale(LC_ALL, "RUS");
	
	//�������� ��������� fuel
	Fuel *fuel = new Fuel;
	fuel->id_fuel = 1;
	fuel->name = "Lookoil";
	fuel->cost = 15.8;
	fuel->amount = 20;

	//������ � map � id_fuel ������� ��������� fuel
	fuels[fuel->id_fuel] = *fuel;

	//std::cout << fuel;
	//����� map �� id->fuel � ����������� ������
	std::cout << fuels[fuel->id_fuel];
	
	//������ 1 �������� ������� � ����
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
	//������ �� ����� � ���������(�������� fuel)
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
	
	//����� ���� ������� �� �����
	std::cout << fuel->name<<endl;

	AutoClass *autoObjs = new AutoClass[5];
	AutoClass currAutoObj;
	currAutoObj=autoObjs[0];
	//��������� ���� ��� ������ 8 �� ������ �������
	//����� ����
	int choose = 0;
	do
	{
		std::cout << "1 - ����� �������� �� �������, � ������� ����������� ��������.\n";
		std::cout << "2 - C����� ��������\n";
		std::cout << "0 - ���������� ���������\n";
		std::cout << "������� �����, ��� ������ ��������!\n";
			cin >> choose;
			if (choose == 1){
				cout << "�������� ���� �� 5(1-5) ������� � ������� ���������� ��������\n";
				int elem;
				cin>>elem;
				if(elem < 1 || elem > 5)
					cout << "�� ����� �� ������ �������\n";
				else
				{
					cout << "�� ������� ������� � �������: " << elem << endl;
					currAutoObj = autoObjs[elem-1];
				}
			}
			if (choose == 2)
			{
				do
				{
					std::cout << "1 - ��������� �� �����\n";
					std::cout << "2 - ������� - �������� 1\n";
					std::cout << "3 - ���� ������ - �������� 2\n";
					std::cout << "4 - �������� - �������� 3\n";
					std::cout << "5 - ������� ������� - �������� 4\n";
					std::cout << "6 - ���������� - �������� 5\n";
					std::cout << "7 - ������������ ����� 1\n";
					std::cout << "8 - ������������ ����� 2 � �.�.\n";
					std::cout << "9 - ��������� � ����\n";
					std::cout << "10 - ������� � ������� ��������(�������� � ������� ������).\n";
					std::cout << "������� �����, ��� ������ ��������!\n";
					cin >> choose;
					if (choose == 1)
						0;
					if (choose == 2 || choose == 3 || choose == 4 || choose == 5) {
						do {
							std::cout << "1 - ��������\n";
							std::cout << "2 - ��������\n";
							std::cout << "3 - �������\n";
							std::cout << "4 - ������� �� �����\n";
							std::cout << "5 - �������� � ������ ��������\n";
							std::cout << "������� �����, ��� ������ ��������!\n";
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
	std::cout << "������� ����� ������� ��� ������\n";
	getch();
    return 0;
}


