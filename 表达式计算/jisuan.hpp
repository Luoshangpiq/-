#ifndef jisuan_hpp
#define jisuan_hpp
#include <iostream>
#include <string>
#include <vector>
#include "High precision.hpp"
using namespace std;
struct kuohao//用于存储一个括号左括号和右括号的下标
{
	unsigned long long zuo= -1;
	unsigned long long you=0;
	unsigned long long size()//返回俩括号间内容的长度
	{
		return you-zuo-1;
	}
};
struct kuohaonei
{
	string shu="0";
	unsigned long long xiabiao=0;
	
};
High_recision quzuozhi               (const string      & shizi,      unsigned long long   xiabiao                          )//取shizi中下标为xiabiao的运算符的左边的数的值
{
	unsigned long long size = 0;
	xiabiao-=1;
	while (xiabiao != 0 && (shizi[xiabiao] >= '0' && shizi[xiabiao]<='9'))
	{
		size+=1;
		xiabiao-=1;
	}
	if ((xiabiao == 0)||(xiabiao != 0 &&shizi[xiabiao] == '-'&& (!(shizi[xiabiao-1] >= '0' && shizi[xiabiao-1]<='9'))))
	{
		size+=1;
	}
	else
	{
		xiabiao+=1;
	}
	return High_recision(shizi.substr(xiabiao,size));
}
High_recision quyouzhi               (const string      & shizi,      unsigned long long   xiabiao                          )//取shizi中下标为xiabiao的运算符的右边的数的值
{
	unsigned long long size = 0;
	xiabiao+=1;
	unsigned long long xiabiao_qu=xiabiao;
	while (xiabiao != 0 && (shizi[xiabiao] >= '0' && shizi[xiabiao]<='9'))
	{
		size+=1;
		xiabiao+=1;
	}
	xiabiao-=1;
	return High_recision(shizi.substr(xiabiao_qu,size));
}
void          dangeyusuanfujisuan    (string            & shizi,      unsigned long long   xiabiao                          )//将shizi中下标为xiabiao的运算符及其左、右的值替换为其结果
{
	const string shi=shizi;
	High_recision a=quzuozhi(shizi,xiabiao),b=quyouzhi(shizi,xiabiao);
	switch(shizi[xiabiao])
	{
		case'^':
		{
			shizi.replace(xiabiao-a.size(),a.size()+b.size()+1,(a^b).return_high_recision());
			break;
		}
		case'*':
		{
			shizi.replace(xiabiao-a.size(),a.size()+b.size()+1,(a*b).return_high_recision());
			break;
		}
		case'/':
		{
			shizi.replace(xiabiao-a.size(),a.size()+b.size()+1,(a/b).return_high_recision());
			break;
		}
		case'%':
		{
			shizi.replace(xiabiao - a.size(), a.size() + b.size() + 1, (a % b).return_high_recision());
			break;
		}
		case'+':
		{
			shizi.replace(xiabiao-a.size(),a.size()+b.size()+1,(a+b).return_high_recision());
			break;
		}
		case'-':
		{
			shizi.replace(xiabiao-a.size(),a.size()+b.size()+1,(a-b).return_high_recision());
			break;
		}
		default:
		{
			break;	
		}
	}
	return;
}
bool          find_min               (const string      & shizi,      unsigned long long & xiabiao                          )//在shizi中从右到左寻找‘^’。若找到，返回true;否则返回false。
{
	for (xiabiao = shizi.size() - 1; xiabiao != 0; xiabiao--)
	{
		if (shizi[xiabiao] == '^')
		{
			return true;
		}
	}
	return false;
}
bool          find_chengchu          (const string      & shizi,      unsigned long long & xiabiao                          )//在shizi中从右到左寻找‘*’或‘/’。若找到，返回true;否则返回false。
{
	unsigned long long size = shizi.size();
	for (xiabiao = 1; xiabiao <size ; xiabiao++)
	{
		if (shizi[xiabiao] == '*'||shizi[xiabiao]=='/' || shizi[xiabiao] == '%')
		{
			return 1;
		}
	}
	return 0;
}
bool          find_jiajian           (const string      & shizi,      unsigned long long & xiabiao                          )//在shizi中从右到左寻找‘+’或‘-’。若找到，返回true;否则返回false。
{
	unsigned long long size = shizi.size();
	for (xiabiao = 1; xiabiao <size; xiabiao++)
	{
		if (shizi[xiabiao] == '+' || shizi[xiabiao] == '-')
		{
			return 1;
		}
	}
	return 0;
}
string        wukuohaobiaodashijisuan(string              shizi                                                             )//计算无括号表达式，返回一个数（即计算结果）。shizi是无括号表达式
{
	unsigned long long xiabiao;
	while (find_min(shizi, xiabiao))
	{
		dangeyusuanfujisuan(shizi, xiabiao);
	}
	while (find_chengchu(shizi, xiabiao))
	{
		dangeyusuanfujisuan(shizi, xiabiao);
	}
	while (find_jiajian(shizi, xiabiao))
	{
		dangeyusuanfujisuan(shizi, xiabiao);
	}
	return shizi;
}
bool          find_zuixiaokuohao     (vector<kuohao>    & shuzikuohao,const string       & shizi                            )//寻找最小括号。将shizi中的最小括号的左括号下标及右括号下标计入shuzikuohao内
{
	kuohao A;
	unsigned long long zuo = -1;
	unsigned long long you = 0;
	unsigned long long m = shizi.size();
	for (unsigned long long xiabiao = 0; xiabiao < m; xiabiao++)
	{
		if (shizi[xiabiao] == '('&&you==0)
		{
			zuo = xiabiao;
		}
		else if (shizi[xiabiao] == ')'&&zuo!=-1)
		{
			you = xiabiao;
		}
		if (zuo != -1 && you != 0)
		{
			A.zuo = zuo;
			A.you = you;
			zuo = -1;
			you = 0;
			shuzikuohao.push_back(A);
		}
	}
	return !shuzikuohao.empty();
}
bool          panduankuohaoneishifwsz(const kuohao      & hao,        const string       & shizi                            )//判断shizi.substr(hao.zuo+1,hao.size())是否为数字
{
	for(unsigned long long n=hao.zuo+2;n!=hao.you;n++)
	{
		if(!isdigit(shizi[n]))
		{
			return 0;
		}
	}
	return 1;
}
void          qukuohaoneishu         (vector<kuohaonei> & shuzi,      vector<kuohao>     & shuzikuohao, const string & shizi)//对于shuzikuohao[n],若shizi.substr(shuzikuohao[n].zuo+1,shuzikuohao[n].size())是一个数字，则将kuohaonei A{shizi.substr(shuzikuohao[n].zuo+1,shuzikuohao[n].size()),shuzikuohao[n].zuo}压入shuzi,此时A中的xiabiao为shizi.substr(shuzikuohao[n].zuo+1,shuzikuohao[n].size())在shizi中首字母下标的前一位
{
	kuohaonei A;
	unsigned long long m = shuzikuohao.size();
	for (unsigned long long n = 0; n < m; n++)
	{
		if (shuzikuohao[n].size() == 1)
		{
			A.shu = shizi.substr(shuzikuohao[n].zuo + 1, 1);
			A.xiabiao = shuzikuohao[n].zuo;
			shuzi.push_back(A);
		}
		else if(panduankuohaoneishifwsz(shuzikuohao[n],shizi))
		{
			A.shu = shizi.substr(shuzikuohao[n].zuo + 1, shuzikuohao[n].size());
			A.xiabiao = shuzikuohao[n].zuo;
			shuzi.push_back(A);
		}
	}
	return;
}
int           qianyifuhao            (unsigned long long& xiabiao,    string             & shizi                            )//用于将shizi中下标应为xiabiao处的负号左移
{
	if (shizi[xiabiao - 1] == '^')
	{
		shizi.insert(xiabiao, "-");
		return 1;
	}
	for (xiabiao--; 1; xiabiao--)
	{
		if (shizi[xiabiao] == '+')
		{
			shizi[xiabiao] = '-';
			return 0;
		}
		else if (shizi[xiabiao] == '-')
		{
			if (shizi[xiabiao - 1] == '(')
			{
				shizi.erase(xiabiao);
				return -1;
			}
			else
			{
				shizi[xiabiao] = '+';
				return 0;
			}
		}
		else if (shizi[xiabiao] == ')')
		{
			long long a=0;
			do {
				if (shizi[xiabiao] == ')')
				{
					a += 1;
				}
				if (shizi[xiabiao] == '(')
				{
					a -= 1;
				}
				xiabiao -= 1;
			} while (a != 0);
			xiabiao += 1;
		}
		else if (shizi[xiabiao] == '(')
		{
			shizi.insert(xiabiao+1, "-");
			return 1;
		}
		else if (shizi[xiabiao] != '(' && xiabiao == 0)
		{
			shizi.insert(0, "-");
			return 1;
		}
	}
	return 0;
}
void          xiabiaozuoyouyi        (unsigned long long  size,       int                  yiwei,   vector<kuohaonei>& shizi)//将shizi[size]之后的shizi的xiabiao加上yiwei
{
	if(size==shizi.size()-1)
	{
		return;
	}
	for(size++;size!=shizi.size();size++)
	{
		shizi[size].xiabiao+=yiwei;
	}
	return;
}
void          qushuzikuohao          (string            & shizi,      vector<kuohaonei>  & shuzi                            )//用于去掉数字括号
{
	for(unsigned long long n=0;n<shuzi.size();n++)
	{
		if (shuzi[n].shu[0] == '-')
		{
			shizi.erase(shuzi[n].xiabiao+shuzi[n].shu.size() + 1, 1);
			shizi.erase(shuzi[n].xiabiao, 2);
			xiabiaozuoyouyi(n, -3, shuzi);
			int a = qianyifuhao(shuzi[n].xiabiao, shizi);
			xiabiaozuoyouyi(n, a, shuzi);
		}
		else
		{
			shizi.erase(shuzi[n].xiabiao+shuzi[n].shu.size() + 1, 1);
			shizi.erase(shuzi[n].xiabiao, 1);
			xiabiaozuoyouyi(n, -2, shuzi);
		}
	}
}
void          jisuan                 (string            & shizi                                                             )//计算
{
	vector<kuohao> shuzikuohao;
	vector<kuohaonei> shuzi;
	string a = "";
	while (shizi.find("(") != -1)
	{
		find_zuixiaokuohao(shuzikuohao,shizi);
		qukuohaoneishu(shuzi,shuzikuohao,shizi);
		qushuzikuohao(shizi,shuzi);
		shuzi.clear();
		shuzikuohao.clear();
		if(shizi.find("(")!=-1)
		{
			find_zuixiaokuohao(shuzikuohao,shizi);
			for(unsigned long long n=shuzikuohao.size()-1;n!=-1;n--)
			{
				a=wukuohaobiaodashijisuan(shizi.substr(shuzikuohao[n].zuo+1,shuzikuohao[n].size()));
				shizi.replace(shuzikuohao[n].zuo+1,shuzikuohao[n].size(),a);
			}
			shuzi.clear();
			shuzikuohao.clear();
		}
	}
	shizi=wukuohaobiaodashijisuan(shizi);
}
#endif
