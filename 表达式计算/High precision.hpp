#ifndef High_precision_hpp
#define High_precision_hpp
#include <iostream>
#include <string>
#include <vector>
class High_recision
{
public:
	friend High_recision  operator+ (const High_recision & Addend1   ,const High_recision& Addend2   );
	friend High_recision  operator- (const High_recision & Minuend   ,const High_recision& Subtrahend);
	friend High_recision  operator* (const High_recision & Factor1   ,const High_recision& Factor2   );
	friend High_recision  operator/ (const High_recision & Dividend  ,const High_recision& Divisor   );
	friend High_recision  operator% (const High_recision & Divisor   ,const High_recision& moshu     );
	friend High_recision  operator^ (const High_recision & dishu     ,const High_recision& zhishu    );
	friend bool           operator> (const High_recision & Parameter1,const High_recision& Parameter2);
	friend bool           operator< (const High_recision & Parameter1,const High_recision& Parameter2);
	friend bool           operator>=(const High_recision & Parameter1,const High_recision& Parameter2);
	friend bool           operator<=(const High_recision & Parameter1,const High_recision& Parameter2);
	friend bool           operator==(const High_recision & Parameter1,const High_recision& Parameter2);
	friend bool           operator!=(const High_recision & Parameter1,const High_recision& Parameter2);
	friend bool           operator! (const High_recision & Parameter                                 );
	friend bool           operator&&(const High_recision & Parameter1,const High_recision& Parameter2);
	friend bool           operator||(const High_recision & Parameter1,const High_recision& Parameter2);
	friend std::ostream & operator<<(std::ostream & os,const High_recision & out                     );
	friend std::istream & operator>>(std::istream & os,      High_recision & in                      );
		   High_recision& operator= (const High_recision & other                                     );
	       High_recision& operator+=(const High_recision & other                                     );
	       High_recision& operator-=(const High_recision & other                                     );
	       High_recision& operator*=(const High_recision & other                                     );
	       High_recision& operator/=(const High_recision & other                                     );
	       High_recision& operator%=(const High_recision & other                                     );
		   High_recision& operator^=(const High_recision & other                                     );
		   High_recision& operator++(   );
		   High_recision& operator++(int);
		   High_recision& operator--(   );
		   High_recision& operator--(int);
	       High_recision                   (std::string Parameter);//    ʽ  ֵ
	       High_recision                   ();                     //    
		   unsigned long long size         ();					   //       ֵĳ   
	       std::string return_high_recision();                     //    high_recision
private:
	std::string high_recision;// ߾       
	std::string Addition      (const std::string & Add_number1, const std::string & Add_number2)const;//    ӷ 
	std::string jian          (const std::string & beijianshu,  const std::string & jianshu    )const;//        
	std::string Multiplication(const std::string & yingshu1,    const std::string   yinshu2    )const;//    ˷  
	std::string Division      (const std::string & Dividend,    const std::string   Divisor    )const;//        
	std::string ten_min       (const std::string & dishu                                       )const;//    dishu  ʮ η 
	std::string n_min         (const std::string & dishu,       const short         zhishu     )const;//    dishu  n η 
	std::string min           (const std::string & dishu,       const std::string & zhishu     )const;//          
	std::string mod           (const std::string & beimoshu,     const std::string& moshu      )const;//    ģ    
	bool dayu                 (const std::string & can1,        const std::string & can2       )const;// жϴ    
};
High_recision::High_recision()
{
	high_recision = "0";
}
High_recision::High_recision(std::string Parameter)
{
	for (unsigned long long n = 0; n < Parameter.size(); n++)
	{
	la:
		if (!((Parameter[n] <= '9' && Parameter[n] >= '0') || (Parameter[n] == '-' && n == 0)))
		{
			Parameter.erase(n, 1);
			goto la;
		}
	}
	high_recision = Parameter;
}
unsigned long long High_recision::size()
{
	return this->high_recision.size();
}
std::string High_recision::return_high_recision()
{
	return high_recision;
}
std::string High_recision::Addition(const std::string& Add_number1, const std::string& Add_number2)const
{
	if (Add_number1.size() < 19 && Add_number2.size() < 19)
	{
		return std::to_string(std::stoull(Add_number1) + std::stoull(Add_number2));
	}
	std::string a, b;
	if (Add_number1.size() >= Add_number2.size())
	{
		a = Add_number1;
		b = Add_number2;
	}
	else
	{
		b = Add_number1;
		a = Add_number2;
	}
	if (a.size() < 19 && b.size() < 19)
	{
		return std::to_string(std::stoull(a) + std::stoull(b));
	}
	for (unsigned long long n = 0; n < a.size(); n++)
	{
		if (n < b.size())
		{
			a[a.size() - 1 - n] += b[b.size() - 1 - n] - '0';
		}
		if (a[a.size() - 1 - n] - '0' > 9)
		{
			a[a.size() - 1 - n] -= 10;
			if (a.size() - n - 1 == 0)
			{
				a = "1" + a;
			}
			else
			{
				a[a.size() - 2 - n] += 1;
			}
		}
	}
	return a;
}
std::string High_recision::jian(const std::string& beijianshu, const std::string& jianshu)const
{
	bool zhengfu = 1;
	std::string a, b;
	if (dayu(jianshu, beijianshu))
	{
		a = jianshu;
		b = beijianshu;
		zhengfu = 0;
	}
	else
	{
		a = beijianshu;
		b = jianshu;
	}
	if (a.size() < 19 && b.size() < 19)
	{
		a=std::to_string(std::stoull(a) - std::stoull(b));
	}
	else
	{
		for (unsigned long long n = 0; n < a.size(); n++)
		{
			if (n < b.size())
			{
				a[a.size() - 1 - n] -= b[b.size() - n - 1] - '0';
			}
			if (a[a.size() - n - 1] < '0')
			{
				a[a.size() - n - 1] += 10;
				a[a.size() - n - 2] -= 1;
			}
		}
	}
	while (a[0] == '0')
	{
		a = a.substr(1);
	}
	if(zhengfu)
	{
		return  a;
	}
	else
	{
		a="-"+a;
		return  a;
	}
}
bool        High_recision::dayu(const std::string& can1, const std::string& can2)const
{
	if (can1 == can2 || (can1[0] == '-' && can2[0] != '-')) { return 0; }
	if (can1[0] != '-' && can2[0] == '-') { return 1; }
	bool zheng = 1;
	if (can1[0] == '-' && can2[0] == '-') { zheng = 0; }
	if (can1.size() > can2.size()) { return 1 && zheng; }
	if (can1.size() < can2.size()) { return !zheng; }
	return zheng && (can1 > can2);
}
std::string High_recision::Multiplication(const std::string& factor1, const std::string   factor2)const
{
	if (factor1.size() < 10 && factor2.size() < 10)
	{
		return std::to_string(std::stoull(factor1) * std::stoull(factor2));
	}
	std::string A, B;
	if (factor1.size() >= factor2.size())
	{
		A = factor1;
		B = factor2;
	}
	else
	{
		B = factor1;
		A = factor2;
	}
	unsigned long long n = A.size(), m = B.size();
	if (n >= 10 && m < 10)
	{
		std::string a = A.substr(0, n / 2), b = A.substr(n / 2, A.size() - n / 2);
		std::string ad = Multiplication(a, B) + std::string(n - n / 2, '0'), bd = Multiplication(b, B);
		return Addition(bd, ad);
	}
	std::string a = A.substr(0, n / 2), b = A.substr(n / 2, A.size() - n / 2),
		c = B.substr(0, m / 2), d = B.substr(m / 2, B.size() - m / 2);
	std::string ad = Multiplication(a, d) + std::string(n - n / 2, '0'), bd = Multiplication(b, d),
		cb = Multiplication(c, b) + std::string(m - m / 2, '0'), ac = Multiplication(a, c) + std::string(m + n - m / 2 - n / 2, '0');
	ad = Addition(ad, cb);
	bd = Addition(bd, ac);
	return Addition(ad, bd);
}
std::string High_recision::Division(const std::string& Dividend, const std::string   Divisor)const
{
	if (Divisor == "0")
	{
		return "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
	}
	if (Dividend.size() < 19 && Divisor.size() < 19)
	{
		return std::to_string(std::stoull(Dividend) / std::stoull(Divisor));
	}
	if (dayu(Divisor, Dividend))
	{
		return "0";
	}
	std::string ret = "0", bijiao = Divisor;
	while (dayu(Dividend, bijiao))
	{
		ret = Addition(ret, "1");
		bijiao = Addition(bijiao, Divisor);
	}
	return ret;
}
std::string High_recision::ten_min(const std::string& dishu)const
{
	std::string a = Multiplication(Multiplication(Multiplication(Multiplication(dishu, dishu), dishu), dishu), dishu);
	return Multiplication(a, a);
}
std::string High_recision::n_min(const std::string& dishu, const short         zhishu)const
{
	std::string ret = "1";
	if (zhishu == 1)
	{
		ret = dishu;
	}
	else if (zhishu == 2)
	{
		ret = Multiplication(dishu, dishu);
	}
	else if (zhishu == 3)
	{
		ret = Multiplication(Multiplication(dishu, dishu), dishu);
	}
	else if (zhishu == 4)
	{
		ret = Multiplication(dishu, dishu);
		ret = Multiplication(ret, ret);
	}
	else if (zhishu == 5)
	{
		ret = Multiplication(Multiplication(Multiplication(Multiplication(dishu, dishu), dishu), dishu), dishu);
	}
	else if (zhishu == 6)
	{
		ret = Multiplication(Multiplication(dishu, dishu), dishu);
		ret = Multiplication(ret, ret);
	}
	else if (zhishu == 7)
	{
		ret = Multiplication(Multiplication(Multiplication(Multiplication(Multiplication(Multiplication(dishu, dishu), dishu), dishu), dishu), dishu), dishu);
	}
	else if (zhishu == 8)
	{
		ret = Multiplication(dishu, dishu);
		ret = Multiplication(ret, ret);
		ret = Multiplication(ret, ret);
	}
	else if (zhishu == 9)
	{
		ret = Multiplication(Multiplication(dishu, dishu), dishu);
		ret = Multiplication(Multiplication(ret, ret), ret);
	}
	return ret;
}
std::string High_recision::min(const std::string& dishu, const std::string& zhishu)const
{
	std::vector<std::string> ten(zhishu.size());
	ten[0] = dishu;
	unsigned long long n = 1;
	unsigned long long m = zhishu.size();
	while (n < m)
	{
		ten[n] = ten_min(ten[n - 1]);
		n++;
	}
	std::string ret = "1";
	for (n = 0; n < m; n++)
	{
		ret = Multiplication(ret, n_min(ten[n], zhishu[zhishu.size() - n - 1] - '0'));
	}
	return ret;
}
std::string High_recision::mod(const std::string& beimoshu, const std::string& moshu)const
{
	if (beimoshu.size() < 19 && moshu.size() < 19)
	{
		return std::to_string(std::stoull(beimoshu) % std::stoull(moshu));
	}
	std::string ret = beimoshu;
	while (dayu(ret, moshu) || ret == moshu)
	{
		ret = jian(ret, moshu);
	}
	return ret;
}
std::ostream& operator<<(std::ostream& os, const High_recision& out)
{
	os << out.high_recision;
	return os;
}
std::istream& operator>>(std::istream& os, High_recision& in)
{
	do
	{
		os >> in.high_recision;
	} while (!os);
	return os;
}
High_recision  operator+ (const High_recision& Addend1, const High_recision& Addend2)
{
	if (Addend1.high_recision[0] == '-' && Addend2.high_recision[0] == '-')//-a+-b=-(a+b)
	{
		High_recision ret("-" + Addend1.Addition(Addend1.high_recision.substr(1), Addend2.high_recision.substr(1)));
		return ret;
	}
	if (Addend1.high_recision[0] != '-' && Addend2.high_recision[0] == '-')//a+(-b)=a-b
	{
		High_recision ret(Addend1.jian(Addend1.high_recision, Addend2.high_recision.substr(1)));
		return ret;
	}
	if (Addend1.high_recision[0] == '-' && Addend2.high_recision[0] != '-')//-a+b=b-a
	{
		High_recision ret(Addend1.jian(Addend2.high_recision, Addend1.high_recision.substr(1)));
		return ret;
	}
	High_recision ret(Addend1.Addition(Addend1.high_recision, Addend2.high_recision));//a+b
	return ret;
}
High_recision  operator- (const High_recision& Minuend, const High_recision& Subtrahend)
{
	if (Minuend.high_recision[0] == '-' && Subtrahend.high_recision[0] != '-')//-a-b=-(a+b)
	{
		High_recision ret("-" + Minuend.Addition(Minuend.high_recision.substr(1), Subtrahend.high_recision));
		return ret;
	}
	if (Minuend.high_recision[0] != '-' && Subtrahend.high_recision[0] == '-')//a-(-b)=a+b
	{
		High_recision ret(Minuend.Addition(Minuend.high_recision, Subtrahend.high_recision.substr(1)));
		return ret;
	}
	if (Minuend.high_recision[0] == '-' && Subtrahend.high_recision[0] == '-')//-a-(-b)=-a+b=b-a
	{
		High_recision ret(Minuend.jian(Subtrahend.high_recision.substr(1), Minuend.high_recision.substr(1)));
		return ret;
	}
	High_recision ret(Minuend.jian(Minuend.high_recision, Subtrahend.high_recision));//a-b=a-b
	return ret;
}
High_recision  operator* (const High_recision& Factor1, const High_recision& Factor2)
{
	if (Factor1.high_recision[0] == '-' && Factor2.high_recision[0] == '-')//-a*(-b)=a*b
	{
		High_recision ret(Factor1.Multiplication(Factor1.high_recision.substr(1), Factor2.high_recision.substr(1)));
		return ret;
	}
	if (Factor1.high_recision[0] != '-' && Factor2.high_recision[0] == '-')//a*(-b)=-a*b
	{
		High_recision ret("-" + Factor1.Multiplication(Factor1.high_recision, Factor2.high_recision.substr(1)));
		return ret;
	}
	if (Factor1.high_recision[0] == '-' && Factor2.high_recision[0] != '-')//-a*b=-a*b
	{
		High_recision ret("-" + Factor1.Multiplication(Factor1.high_recision.substr(1), Factor2.high_recision));
		return ret;
	}
	High_recision ret(Factor1.Multiplication(Factor1.high_recision, Factor2.high_recision));
	return ret;
}
High_recision  operator/ (const High_recision& Dividend, const High_recision& Divisor)
{
	if (Dividend.high_recision[0] == '-' && Divisor.high_recision[0] == '-')//(-a)/(-b)==a/b
	{
		High_recision ret(Dividend.Division(Dividend.high_recision.substr(1), Divisor.high_recision.substr(1)));
		return ret;
	}
	if (Dividend.high_recision[0] != '-' && Divisor.high_recision[0] == '-')//a/(-b)==-a/b
	{
		High_recision ret("-" + Dividend.Division(Dividend.high_recision, Divisor.high_recision.substr(1)));
		return ret;
	}
	if (Dividend.high_recision[0] == '-' && Divisor.high_recision[0] != '-')//(-a)/b==-a/b
	{
		High_recision ret("-" + Dividend.Division(Dividend.high_recision.substr(1), Divisor.high_recision));
		return ret;
	}

	High_recision ret(Dividend.Division(Dividend.high_recision, Divisor.high_recision));
	return ret;
}
High_recision  operator^ (const High_recision& dishu, const High_recision& zhishu)
{
	if (zhishu.high_recision == "0")
	{
		High_recision ret("1");
		return ret;
	}
	if (zhishu.high_recision[0] == '-')
	{
		High_recision ret("0");
		return ret;
	}
	if (dishu.high_recision[0] == '-')
	{
		High_recision ret("-" + dishu.min(dishu.high_recision.substr(1), zhishu.high_recision));
		return ret;
	}
	High_recision ret(dishu.min(dishu.high_recision, zhishu.high_recision));
	return ret;
}
High_recision  operator% (const High_recision& Divisor, const High_recision& moshu)
{
	if (Divisor.high_recision[0] == '-' && moshu.high_recision[0] != '-')
	{
		std::string a = Divisor.mod(Divisor.high_recision.substr(1), moshu.high_recision);
		High_recision ret(((a != "0") ? "-" : "") + a);
		return ret;
	}
	if (Divisor.high_recision[0] == '-' && moshu.high_recision[0] == '-')
	{
		std::string a = Divisor.mod(Divisor.high_recision.substr(1), moshu.high_recision.substr(1));
		High_recision ret(((a != "0") ? "-" : "") + a);
		return ret;
	}
	if (Divisor.high_recision[0] != '-' && moshu.high_recision[0] == '-')
	{
		High_recision ret(Divisor.mod(Divisor.high_recision, moshu.high_recision.substr(1)));
		return ret;
	}
	High_recision ret(Divisor.mod(Divisor.high_recision, moshu.high_recision));
	return ret;
}
bool           operator> (const High_recision& Parameter1, const High_recision& Parameter2)
{
	return Parameter1.dayu(Parameter1.high_recision, Parameter2.high_recision);
}
bool           operator< (const High_recision& Parameter1, const High_recision& Parameter2)
{
	return Parameter1.dayu(Parameter2.high_recision, Parameter1.high_recision);
}
bool           operator>=(const High_recision& Parameter1, const High_recision& Parameter2)
{
	return Parameter1.dayu(Parameter1.high_recision, Parameter2.high_recision) || (Parameter1.high_recision == Parameter2.high_recision);
}
bool           operator<=(const High_recision& Parameter1, const High_recision& Parameter2)
{
	return Parameter1.dayu(Parameter2.high_recision, Parameter1.high_recision) || (Parameter1.high_recision == Parameter2.high_recision);
}
bool           operator==(const High_recision& Parameter1, const High_recision& Parameter2)
{
	return Parameter1.high_recision == Parameter2.high_recision;
}
bool           operator!=(const High_recision& Parameter1, const High_recision& Parameter2)
{
	return !(Parameter1.high_recision == Parameter2.high_recision);
}
bool           operator! (const High_recision& Parameter)
{
	return Parameter.high_recision != "0";
}
bool           operator&&(const High_recision& Parameter1, const High_recision& Parameter2)
{
	return Parameter1.high_recision != "0" && Parameter2.high_recision != "0";
}
bool           operator||(const High_recision& Parameter1, const High_recision& Parameter2)
{
	return Parameter1.high_recision != "0" || Parameter2.high_recision != "0";
}
High_recision& High_recision::operator= (const High_recision& other)
{
	if (this != &other)
	{
		this->high_recision = other.high_recision;
	}
	return *this;
}
High_recision& High_recision::operator+=(const High_recision& other)
{
	if (this->high_recision[0] == '-' && other.high_recision[0] == '-')//-a+-b=-(a+b)
	{
		this->high_recision = "-" + Addition(this->high_recision.substr(1), other.high_recision.substr(1));
		return *this;
	}
	if (this->high_recision[0] != '-' && other.high_recision[0] == '-')//a+(-b)=a-b
	{
		this->high_recision = jian(this->high_recision, other.high_recision.substr(1));
		return *this;
	}
	if (this->high_recision[0] == '-' && other.high_recision[0] != '-')//-a+b=b-a
	{
		this->high_recision = "-" + jian(this->high_recision.substr(1), other.high_recision);
		return *this;
	}
	this->high_recision = Addition(this->high_recision, other.high_recision);//a+b
	return *this;
}
High_recision& High_recision::operator-=(const High_recision& other)
{
	if (this->high_recision[0] == '-' && other.high_recision[0] != '-')//-a-b=-(a+b)
	{
		this->high_recision = "-" + this->Addition(this->high_recision.substr(1), other.high_recision);
		return *this;
	}
	if (this->high_recision[0] != '-' && other.high_recision[0] == '-')//a-(-b)=a+b
	{
		this->high_recision = Addition(this->high_recision, other.high_recision.substr(1));
		return *this;
	}
	if (this->high_recision[0] == '-' && other.high_recision[0] == '-')//-a-(-b)=-a+b=b-a
	{
		this->high_recision = jian(other.high_recision.substr(1), this->high_recision.substr(1));
		return *this;
	}
	this->high_recision = jian(this->high_recision, other.high_recision);//a-b=a-b
	return *this;
}
High_recision& High_recision::operator*=(const High_recision& other)
{
	if (this->high_recision[0] == '-' && other.high_recision[0] == '-')//-a*(-b)=a*b
	{
		this->high_recision = Multiplication(this->high_recision.substr(1), other.high_recision.substr(1));
		return *this;
	}
	if (this->high_recision[0] != '-' && other.high_recision[0] == '-')//a*(-b)=-a*b
	{
		this->high_recision = "-" + Multiplication(this->high_recision, other.high_recision.substr(1));
		return *this;
	}
	if (this->high_recision[0] == '-' && other.high_recision[0] != '-')//-a*b=-a*b
	{
		this->high_recision = "-" + Multiplication(this->high_recision.substr(1), other.high_recision);
		return *this;
	}
	this->high_recision = Multiplication(this->high_recision, other.high_recision);
	return *this;
}
High_recision& High_recision::operator/=(const High_recision& other)
{
	if (this->high_recision[0] == '-' && other.high_recision[0] == '-')//(-a)/(-b)==a/b
	{
		this->high_recision = Division(this->high_recision.substr(1), other.high_recision.substr(1));
		return *this;
	}
	if (this->high_recision[0] != '-' && other.high_recision[0] == '-')//a/(-b)==-a/b
	{
		this->high_recision = "-" + Division(this->high_recision, other.high_recision.substr(1));
		return *this;
	}
	if (this->high_recision[0] == '-' && other.high_recision[0] != '-')//(-a)/b==-a/b
	{
		this->high_recision = "-" + Division(this->high_recision.substr(1), other.high_recision);
		return *this;
	}

	this->high_recision = Division(this->high_recision, other.high_recision);
	return *this;
}
High_recision& High_recision::operator%=(const High_recision& other)
{
	if (this->high_recision[0] == '-' && other.high_recision[0] != '-')
	{
		this->high_recision = mod(this->high_recision.substr(1), other.high_recision);
		return *this;
	}
	if (this->high_recision[0] == '-' && other.high_recision[0] == '-')
	{
		this->high_recision = mod(this->high_recision.substr(1), other.high_recision.substr(1));
		return *this;
	}
	if (this->high_recision[0] != '-' && other.high_recision[0] == '-')
	{
		this->high_recision = mod(this->high_recision, other.high_recision.substr(1));
		return *this;
	}
	this->high_recision = mod(this->high_recision, other.high_recision);
	return *this;
}
High_recision& High_recision::operator^=(const High_recision& other)
{
	if (other.high_recision == "0")
	{
		this->high_recision = "1";
		return *this;
	}
	if (other.high_recision[0] == '-')
	{
		this->high_recision = "0";
		return *this;
	}
	if (this->high_recision[0] == '-')
	{
		this->high_recision = "-" + min(this->high_recision.substr(1), other.high_recision);
		return *this;
	}
	this->high_recision = min(this->high_recision, other.high_recision);
	return *this;
}
High_recision& High_recision::operator++()
{
	if (this->high_recision[0] == '-')
	{
		this->high_recision = "-" + jian(this->high_recision.substr(1), "1");
		if (this->high_recision == "-0")
		{
			this->high_recision = "0";
		}
	}
	else
	{
		this->high_recision = Addition(this->high_recision, "1");
	}
	return *this;
}
High_recision& High_recision::operator++(int)
{
	High_recision ret(this->high_recision);
	if (this->high_recision[0] == '-')
	{
		this->high_recision = "-" + jian(this->high_recision.substr(1), "1");
		if (this->high_recision == "-0")
		{
			this->high_recision = "0";
		}
	}
	else
	{
		this->high_recision = Addition(this->high_recision, "1");
	}
	return ret;
}
High_recision& High_recision::operator--()
{
	if (this->high_recision[0] == '-' || this->high_recision == "0")
	{
		this->high_recision = "-" + Addition(this->high_recision.substr(1), "1");
	}
	else
	{
		this->high_recision = jian(this->high_recision, "1");
	}
	return *this;
}
High_recision& High_recision::operator--(int)
{
	High_recision ret(this->high_recision);
	if (this->high_recision[0] == '-' || this->high_recision == "0")
	{
		this->high_recision = "-" + Addition(this->high_recision.substr(1), "1");
	}
	else
	{
		this->high_recision = jian(this->high_recision, "1");
	}
	return ret;
}
#endif
                  