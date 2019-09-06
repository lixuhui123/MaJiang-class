//1.#include  <iostream>
//2.using namespace std;
//3.
//4.class Date
//5.{
//6.public:
//	7.    Date(int year = 1900, int month = 1, int day = 1)
//		8. : _year(year)
//		9., _month(month)
//		10., _day(day)
//		11.    {
//		12.        int days = Getmonthday(year, month);
//		13.        if (days == -1 || day<1 || day>days)
//			14.        {
//			15.            //cout<<"���ڲ��Ϸ�"<<Display<<endl;
//				16.            exit(1);
//			17.        }
//		18.    }
//	19.
//		20.    Date(const Date& d)
//		21.    {
//		22.        _year = d._year;
//		23.        _month = d._month;
//		24.        _day = d._day;
//		25.    }
//	26.
//		27.    ~Date()
//		28.    {
//		29.    }
//	30.    void Display()
//		31.    {
//		32.        cout << _year << "-" << _month << "-" << _day << endl;
//		33.    }
//	34.
//		35.    int Getmonthday(int _year, int _month)//��ȡ����
//		36.    {
//		37.        if (_year < 1900 || _month < 1 || _month > 12)
//			38.            return -1;
//		39.        int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		40.        int days = arr[_month];
//		41.        if (_month == 2 && IsLeapYear(_year))//���������Ķ��£��͸����µ�������һ��
//			42.        {
//			43.            ++days;
//			44.        }
//		45.        return days;
//		46.    }
//	47.
//		48.    bool IsLeapYear(int year)//�ж��Ƿ�������
//		49.    {
//		50.        return (((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0));
//		51.    }
//	52.
//		53.    bool IsInvalid(int year, int month, int day)//�ж������Ƿ�Ϸ�
//		54.    {
//		55.        return ((year > 1900) && (month > 0) && (month < 13) && (day > 0) && (day < Getmonthday(year, month)));
//		56.    }
//	57.
//		58.    //d1 > d2   
//		59.    bool operator>(const Date& d) const
//		60.    {
//		61.        if (_year > d._year)
//			62.            return true;
//		63.        if (_year == d._year)
//			64.        {
//			65.            if (_month > d._month)
//				66.                return true;
//			67.            if (_month == d._month)
//				68.            {
//				69.                if (_day > d._day)
//					70.                    return true;
//				71.            }
//			72.        }
//		73.        return false;
//		74.    }
//	75.
//		76.    bool operator>=(const Date& d)const
//		77.    {
//		78.        return ((*this > d) && (*this == d));
//		79.    }
//	80.
//		81.    bool operator<(const Date& d)const
//		82.    {
//		83.        return !((this == &d) && (this > (&d)));
//		84.    }
//	85.
//		86.    bool operator<=(const Date& d)const
//		87.    {
//		88.        return ((*this < d) && (*this == d));
//		89.    }
//	90.
//		91.    bool operator==(const Date& d)const
//		92.    {
//		93.        return ((_year == d._year) && (_month == d._month) && (_day == d._day));
//		94.    }
//	95.
//		96.    bool operator!=(const Date& d)const
//		97.    {
//		98.        return !(*this == d);
//		99.    }
//	100.
//		101.    //d1 + 100 
//		102.    Date operator+(int day)//���ڼ�������
//		103.    {
//		104.        if (day < 0)
//			105.            return *this - (-day);
//		106.        _day += day;
//		107.        while (_day > Getmonthday(_year, _month))//�������ӵ����µ����һ��ʱ����һ�½�λ
//			108.        {
//			109.            _day = _day - Getmonthday(_year, _month);
//			110.            ++_month;
//			111.            if (_month > 12)
//				112.            {
//				113.                ++_year;
//				114.                _month = 1;
//				115.            }
//			116.        }
//		117.        return *this;
//		118.    }
//	119.
//		120.    Date operator-(int day)//����-
//		121.    {
//		122.        if (day < 0) //��-һ������ʱ����+,��������+
//			123.            return *this + (-day);
//		124.        _day -= day;
//		125.        while (_day < 1)// �����ڵ���������0��ʱ������һ���½�
//			126.        {
//			127.            --_month;
//			128.            if (_month == 0)//���·ݼ���0��ʱ������һ���
//				129.            {
//				130.                --_year;
//				131.                _month = 12;
//				132.            }
//			133.            _day = Getmonthday(_year, _month) + _day;
//			134.        }
//		135.        return *this;
//		136.    }
//	137.
//		138.    Date operator++()//����+һ��
//		139.    {
//		140.        _day += 1;
//		141.        if (_day > Getmonthday(_year, _month))//�������ӵ�����µ����һ��ʱ���¸��½���һ��
//			142.        {
//			143.            ++_month;
//			144.            _day = 1;
//			145.            if (_month == 13)//����һ�����ʱ������һ�����һ��
//				146.            {
//				147.                ++_year;
//				148.                _month = 1;
//				149.            }
//			150.        }
//		151.        return *this;
//		152.    }
//	153.
//		154.    Date operator++(int)
//		155.    {
//		156.        return *this;
//		157.    }
//	158.
//		159.    Date operator--()//���ڼ�һ��
//		160.    {
//		161.        --_day;
//		162.        if (_day == 0)//��һ���¼���ʱ������һ���½���һ��
//			163.        {
//			164.            --_month;
//			165.            if (_month == 0)//��һ�����ʱ������һ�����һ��
//				166.            {
//				167.                --_year;
//				168.                _month = 12;
//				169.            }
//			170.            _day = Getmonthday(_year, _month);
//			171.        }
//		172.        if (IsInvalid(_year, _month, _day) == 0)//������1900���ʱ�����ټ���
//			173.        {
//			174.            cout << "���ڳ����Ϸ��߽�" << endl;
//			175.            system("pause");
//			176.            return -1;
//			177.        }
//		178.        return *this;
//		179.    }
//	180.
//		181.    Date operator--(int)//����--��ԭ���ڲ���
//		182.    {
//		183.        return *this;
//		184.    }
//	185.
//		186.    int operator-(const Date& d)//������������֮����˶�����
//		187.    {
//		188.        int count = 0;
//		189.        Date big;
//		190.        Date small;
//		191.        if (operator<(d))//����һ����С���ڣ���С����һ��һ��ļӣ�ֱ�����ڴ�����ڣ������м���˶�����
//			192.        {
//			193.            big = *this;
//			194.            small = d;
//			195.        }
//		196.        else
//			197.        {
//			198.            big = d;
//			199.            small = *this;
//			200.        }
//		201.        while (small != big)
//			202.        {
//			203.            small.operator++();
//			204.            count++;
//			205.        }
//		206.        return count;
//		207.    }
//	208.
// private:
//    int _year;
//    int _month;
//    int _day;
//  
