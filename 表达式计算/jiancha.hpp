#ifndef jiancha_hpp
#define jiancha_hpp
#include <iostream>
#include <string>
using namespace std;
void qukuohao(string & shizi)//去掉shizi中的空格
{
	for (unsigned long long n = 0; n < shizi.size(); n++)
	{
		while (n < shizi.size() && shizi[n] == ' ')
		{
			shizi.erase(n, 1);
		}
	}
}
bool jianchakuohaoshu(const string& shizi)//检查shizi中的括号数是否正确。正确返回1，错误返回0。
{
	unsigned long long qian = 0, hou = 0, m = shizi.size();
	for (unsigned long long n = 0; n < m; n++)
	{
		if (shizi[n] == '(')
		{
			qian+=1;
		}
		if (shizi[n] == ')')
		{
			hou+=1;
		}
	}
	if (qian != hou)
	{
		return 0;
	}
	if (qian)
	{
		if (shizi.find("(") > shizi.find(")"))
		{
			return 0;
		}
		if (shizi.rfind("(") > shizi.rfind(")"))
		{
			return 0;
		}
	}
	return 1;
}
bool jianchadangezifu(const string& shizi)//检查shizi中的单个字符是否正确。正确返回1，错误返回0。
{
	unsigned long long m = shizi.size();
	for (unsigned long long n = 0; n < m; n++)
	{
		if (!((shizi[n] >= '0' && shizi[n] <= '9') || shizi[n] == '(' || shizi[n] == ')' || shizi[n] == '+' || shizi[n] == '-' || shizi[n] == '*' || shizi[n] == '/' || shizi[n] == '^' || shizi[n] == '%'))
		{
			return 0;
		}
	}
	return 1;
}
inline bool find_fu(unsigned long long& a, const string& shizi, string fu)
{
	a = shizi.find(fu);
	if (a == string::npos)
	{
		return 0;
	}
	return 1;
}
void huanjianzhengfuhao(string& shizi)//化简shizi中的正负号
{
	unsigned long long a;
	bool b = 1;
	while (b)
	{
		if (find_fu(a, shizi,"++"))//++ -> +
		{
			shizi.replace(a, 2, "+");
		}
		else if (find_fu(a, shizi, "+-"))//+- -> -
		{
			cout<<2;shizi.replace(a, 2, "-");
		}
		else if (find_fu(a, shizi, "--"))//-- -> +
		{
			cout<<3;shizi.replace(a, 2, "+");
		}
		else if (find_fu(a, shizi, "-+"))//-+ -> +
		{
			cout<<4;shizi.replace(a, 2, "-");
		}
		else if (find_fu(a, shizi, "(+)"))//(+) -> +
		{
			cout<<5;shizi.replace(a, 3, "+");
		}
		else if (find_fu(a, shizi, "(-)"))//(-) -> -
		{
			cout<<6;shizi.replace(a, 3, "-");
		}
		else if (find_fu(a, shizi, "(+"))//(+ -> (
		{
			cout<<7;shizi.replace(a, 2, "(");
		}
		else if (find_fu(a, shizi, "*+"))//*+ -> *
		{
			cout<<8;shizi.replace(a, 2, "*");
		}
		else if (find_fu(a, shizi, "/+"))///+ -> /
		{
			cout<<9;shizi.replace(a, 2, "/");
		}
		else if (find_fu(a, shizi, "^+"))//^+ -> ^
		{
			cout<<10;shizi.replace(a, 2, "^");
		}
		else
		{
			b = 0;
		}
	}
	if (shizi[0] == '+')
	{
		shizi.erase(0, 1);
	}
}
bool jianchacuowu(const string& shizi)//检查shizi中的运算符书写是否正确。正确返回1，错误返回0。
{
	if (shizi.find("+*") != string::npos)
	{
		return 0;
	}
	if (shizi.find("+/") != string::npos)
	{
		return 0;
	}
	if (shizi.find("+^") != string::npos)
	{
		return 0;
	}
	if (shizi.find("-*") != string::npos)
	{
		return 0;
	}
	if (shizi.find("-/") != string::npos)
	{
		return 0;
	}
	if (shizi.find("-^") != string::npos)
	{
		return 0;
	}
	if (shizi.find("*/") != string::npos)
	{
		return 0;
	}
	if (shizi.find("/*") != string::npos)
	{
		return 0;
	}
	if (shizi.find("*^") != string::npos)
	{
		return 0;
	}
	if (shizi.find("^*") != string::npos)
	{
		return 0;
	}
	if (shizi.find("/^") != string::npos)
	{
		return 0;
	}
	if (shizi.find("^/") != string::npos)
	{
		return 0;
	}
	if (shizi.find("//") != string::npos)
	{
		return 0;
	}
	if (shizi.find("%%") != string::npos)
	{
		return 0;
	}
	if (shizi.find("**") != string::npos)
	{
		return 0;
	}
	if (shizi.find("%*") != string::npos)
	{
		return 0;
	}
	if (shizi.find("*%") != string::npos)
	{
		return 0;
	}
	if (shizi.find("%/") != string::npos)
	{
		return 0;
	}
	if (shizi.find("/%") != string::npos)
	{
		return 0;
	}
	if (shizi.find("^^") != string::npos)
	{
		return 0;
	}
	if (shizi.find("%^") != string::npos)
	{
		return 0;
	}
	if (shizi.find("^%") != string::npos)
	{
		return 0;
	}
	if (shizi.find("-%") != string::npos)
	{
		return 0;
	}
	if (shizi.find("+%") != string::npos)
	{
		return 0;
	}
	return 1;
}
bool JIANCHA(string& shizi)//检查shizi是不是正确的表达式，是返回1，否返回0。
{
	qukuohao(shizi);
	if (!jianchakuohaoshu(shizi))
	{
		cout << "式子括号缺失" << endl;
		return 0;
	}
	if (!jianchadangezifu(shizi))
	{
		cout << "式子中存在非法字符" << endl;
		return 0;
	}
	huanjianzhengfuhao(shizi);
	if (!jianchacuowu(shizi))
	{
		cout << "式子书写错误" << endl;
		return 0;
	}
	char qian = shizi[0];
	if (qian == '*' || qian == '^' || qian == '/')
	{
		cout << "式子参数缺失" << endl;
		return 0;
	}
	qian = shizi[shizi.size() - 1];
	if (qian == '*' || qian == '^' || qian == '/'||qian=='+'||qian=='-')
	{
		cout << "式子参数缺失" << endl;
		return 0;
	}
	return 1;
}
#endif
//