#ifndef wenjian_hpp
#define wenjian_hpp
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
string dizhi_in;
string dizhi_out;
vector<string> SHIZI;
void        dudizhi  ()//����dizhi.txt�еĵ�ַ
{
	string neirong, jia;
	cout << "�洢���롢�����ַ��.txt�ļ���ַ��";
	cin >> neirong;
	if (neirong == "end")
	{
		dizhi_in="";
		dizhi_out="";
	}
	else
	{
		fstream flie(neirong, ios::in);
		if (!flie.is_open())
		{
			system("cls");
			cout << "���ļ�ʧ��";
			while (1)
			{

			}
		}
		getline(flie, neirong);
		while (getline(flie, jia))
		{
			neirong += jia;
			cout << jia;
		}
		flie.close();
		auto biao_in = neirong.find("cin:");
		auto biao_out = neirong.find("cout:");
		dizhi_in = neirong.substr(4, biao_out - 4);
		dizhi_out = neirong.substr(biao_out + 5, neirong.size() - biao_out - 5);
	}
	
}
inline void out_dizhi()//���SHIZI���ļ���
{
	fstream out(dizhi_out.c_str(), ios::app);
	if (!out.is_open())
	{
		system("cls");
		cout << "���ļ�ʧ��";
		while (1)
		{

		}
	}
	for (unsigned long long n = 0; n < SHIZI.size(); n++)
	{
		out << SHIZI[n] << endl;
	}
	out.close();
}
inline void out_dizhi(string& shizi)//���shizi���ļ���
{
	fstream out(dizhi_out.c_str(), ios::app);
	if (!out.is_open())
	{
		system("cls");
		cout << "���ļ�ʧ��";
		while (1)
		{

		}
	}
	out << shizi << endl;
	out.close();
}
void        in_dizhi ()//���ļ��ж���shizi��SHIZI
{
	fstream in(dizhi_in.c_str(), ios::in);
	string a;
	if (!in.is_open())
	{
		system("cls");
		cout << "���ļ�ʧ��";
		while (1)
		{

		}
	}
	while (getline(in, a))
	{
		if (a != "")
		{
			SHIZI.push_back(a);
		}
	}
}
#endif
