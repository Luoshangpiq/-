#ifndef jiancha_hpp
#define jiancha_hpp
#include <iostream>
#include <string>
using namespace std;
void qukuohao(string & shizi)//ȥ��shizi�еĿո�
{
	for (unsigned long long n = 0; n < shizi.size(); n++)
	{
		while (n < shizi.size() && shizi[n] == ' ')
		{
			shizi.erase(n, 1);
		}
	}
}
bool jianchakuohaoshu(const string& shizi)//���shizi�е��������Ƿ���ȷ����ȷ����1�����󷵻�0��
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
bool jianchadangezifu(const string& shizi)//���shizi�еĵ����ַ��Ƿ���ȷ����ȷ����1�����󷵻�0��
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
void huanjianzhengfuhao(string& shizi)//����shizi�е�������
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
bool jianchacuowu(const string& shizi)//���shizi�е��������д�Ƿ���ȷ����ȷ����1�����󷵻�0��
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
bool JIANCHA(string& shizi)//���shizi�ǲ�����ȷ�ı��ʽ���Ƿ���1���񷵻�0��
{
	qukuohao(shizi);
	if (!jianchakuohaoshu(shizi))
	{
		cout << "ʽ������ȱʧ" << endl;
		return 0;
	}
	if (!jianchadangezifu(shizi))
	{
		cout << "ʽ���д��ڷǷ��ַ�" << endl;
		return 0;
	}
	huanjianzhengfuhao(shizi);
	if (!jianchacuowu(shizi))
	{
		cout << "ʽ����д����" << endl;
		return 0;
	}
	char qian = shizi[0];
	if (qian == '*' || qian == '^' || qian == '/')
	{
		cout << "ʽ�Ӳ���ȱʧ" << endl;
		return 0;
	}
	qian = shizi[shizi.size() - 1];
	if (qian == '*' || qian == '^' || qian == '/'||qian=='+'||qian=='-')
	{
		cout << "ʽ�Ӳ���ȱʧ" << endl;
		return 0;
	}
	return 1;
}
#endif
//