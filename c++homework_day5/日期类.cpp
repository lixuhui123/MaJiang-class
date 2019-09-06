#include <iostream>
using namespace std;
/* 三、设计一个日期类，包含以下功能：
1、只能通过传入年月日初始化。
2、可以加上一个数字n，返回一个该日期后推n天之后的日期。
不考虑润年和闰月的条件，1 3 5 7 8 10 12 为大月31天*/
/* 另一种方法，日期一天天加 */
class date
{
public:
	date(int year,int mouth,int day,int n)
	{
		m_year = year;
		m_mouth = mouth;
		m_day = day;
		int tag = 0;
		/* 日为30进制，月为12进制，年为365进制 */
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
		cout << m_year << "年" << m_mouth << "月" << m_day << "日"<<endl;
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