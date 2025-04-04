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
void        dudizhi  ()//读出dizhi.txt中的地址
{
	string neirong, jia;
	cout << "存储输入、输出地址的.txt文件地址：";
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
			cout << "打开文件失败";
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
inline void out_dizhi()//输出SHIZI到文件中
{
	fstream out(dizhi_out.c_str(), ios::app);
	if (!out.is_open())
	{
		system("cls");
		cout << "打开文件失败";
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
inline void out_dizhi(string& shizi)//输出shizi到文件中
{
	fstream out(dizhi_out.c_str(), ios::app);
	if (!out.is_open())
	{
		system("cls");
		cout << "打开文件失败";
		while (1)
		{

		}
	}
	out << shizi << endl;
	out.close();
}
void        in_dizhi ()//从文件中读出shizi到SHIZI
{
	fstream in(dizhi_in.c_str(), ios::in);
	string a;
	if (!in.is_open())
	{
		system("cls");
		cout << "打开文件失败";
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
