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
//			15.            //cout<<"日期不合法"<<Display<<endl;
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
//		35.    int Getmonthday(int _year, int _month)//获取天数
//		36.    {
//		37.        if (_year < 1900 || _month < 1 || _month > 12)
//			38.            return -1;
//		39.        int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		40.        int days = arr[_month];
//		41.        if (_month == 2 && IsLeapYear(_year))//如果是闰年的二月，就给二月的天数加一天
//			42.        {
//			43.            ++days;
//			44.        }
//		45.        return days;
//		46.    }
//	47.
//		48.    bool IsLeapYear(int year)//判断是否是闰年
//		49.    {
//		50.        return (((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0));
//		51.    }
//	52.
//		53.    bool IsInvalid(int year, int month, int day)//判断日期是否合法
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
//		102.    Date operator+(int day)//日期加上天数
//		103.    {
//		104.        if (day < 0)
//			105.            return *this - (-day);
//		106.        _day += day;
//		107.        while (_day > Getmonthday(_year, _month))//当天数加到本月的最后一天时向下一月进位
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
//		120.    Date operator-(int day)//重载-
//		121.    {
//		122.        if (day < 0) //当-一个负数时就是+,返回重载+
//			123.            return *this + (-day);
//		124.        _day -= day;
//		125.        while (_day < 1)// 当日期的天数减到0的时候，向上一个月借
//			126.        {
//			127.            --_month;
//			128.            if (_month == 0)//当月份减到0的时候向上一年借
//				129.            {
//				130.                --_year;
//				131.                _month = 12;
//				132.            }
//			133.            _day = Getmonthday(_year, _month) + _day;
//			134.        }
//		135.        return *this;
//		136.    }
//	137.
//		138.    Date operator++()//日期+一天
//		139.    {
//		140.        _day += 1;
//		141.        if (_day > Getmonthday(_year, _month))//当天数加到这个月的最后一天时向下个月借上一天
//			142.        {
//			143.            ++_month;
//			144.            _day = 1;
//			145.            if (_month == 13)//当这一年加满时，向下一年借上一天
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
//		159.    Date operator--()//日期减一天
//		160.    {
//		161.        --_day;
//		162.        if (_day == 0)//当一个月减完时，向上一个月借上一天
//			163.        {
//			164.            --_month;
//			165.            if (_month == 0)//当一年减完时，向上一年借上一天
//				166.            {
//				167.                --_year;
//				168.                _month = 12;
//				169.            }
//			170.            _day = Getmonthday(_year, _month);
//			171.        }
//		172.        if (IsInvalid(_year, _month, _day) == 0)//当减到1900年的时候不用再减了
//			173.        {
//			174.            cout << "日期超过合法边界" << endl;
//			175.            system("pause");
//			176.            return -1;
//			177.        }
//		178.        return *this;
//		179.    }
//	180.
//		181.    Date operator--(int)//日期--，原日期不变
//		182.    {
//		183.        return *this;
//		184.    }
//	185.
//		186.    int operator-(const Date& d)//计算两个日期之间差了多少天
//		187.    {
//		188.        int count = 0;
//		189.        Date big;
//		190.        Date small;
//		191.        if (operator<(d))//定义一个大小日期，用小日期一天一天的加，直到等于大的日期，计算中间加了多少天
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
