#include <iostream>
using namespace std;
/* �������һ�������࣬�������¹��ܣ�
1��ֻ��ͨ�����������ճ�ʼ����
2�����Լ���һ������n������һ�������ں���n��֮������ڡ�
��������������µ�������1 3 5 7 8 10 12 Ϊ����31��*/
/* ��һ�ַ���������һ����� */
class date
{
public:
	date(int year,int mouth,int day,int n)
	{
		m_year = year;
		m_mouth = mouth;
		m_day = day;
		int tag = 0;
		/* ��Ϊ30���ƣ���Ϊ12���ƣ���Ϊ365���� */
 		if (m_day+n>30)
		{
			m_day += n;
			m_day %= 30;
			tag = (n) / 30;
			m_mouth += tag;
			if (m_mouth>12&&m_mouth<=24)
			{
				m_mouth -= 12;
				m_year += 1;
			}
  		}
		else
		{
			m_day += n;
		}
	}  
	void print()
	{
		cout << m_year << "��" << m_mouth << "��" << m_day << "��"<<endl;
	}
 private:
	int m_year;
	int m_mouth;
	int m_day;

};
int main()
{
	date da(2019,9,4,300);
	da.print();
	system("pause"); 
	return 0;
}