#include "wenjian.hpp"
#include "jiancha.hpp"
#include "jisuan.hpp"
#include<Windows.h>
int main()
{
	
	dudizhi();
	system("cls");
	if (dizhi_in.empty())
	{
		string shi_zi;
		cout << "������Ҫ�����ʽ�ӣ�";
		cin >> shi_zi;
		system("cls");
		while (shi_zi != "end")
		{
			if (JIANCHA(shi_zi))
			{
				jisuan(shi_zi);
				if (dizhi_out.empty())
				{
					cout << "�ϸ�ʽ�ӽ����";
					cout << shi_zi << endl;
				}
				else
				{
					out_dizhi(shi_zi);
				}
			}
			cout << "������Ҫ�����ʽ�ӣ�";
			cin >> shi_zi;
			system("cls");
		}
	}
	else
	{
		in_dizhi();
		for (unsigned long long n = 0; n < SHIZI.size(); n++)
		{
			if (!JIANCHA(SHIZI[n]))
			{
				cout << "����" <<n<<"��ʽ���У�" << endl;
				return 0;
			}
		}
		for (unsigned long long n = 0; n < SHIZI.size(); n++)
		{
			jisuan(SHIZI[n]);
		}
		if (dizhi_out.empty())
		{
			for (unsigned long long n = 0; n < SHIZI.size(); n++)
			{
				cout << SHIZI[n] << endl;
			}
			Sleep(10000);
		}
		else
		{
			out_dizhi();
		}
	}
	return 0;
}//8||9
