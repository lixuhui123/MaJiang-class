//#include <iostream>
//using namespace std;
//#define NUM 5
///* ĳ�ϰ���Ҫһ���ܿ��ټ��㶩���۸�ĳ�������������һ���ࣺ  
//1�����������Ҫԭ�ۺ�������ԭ�۴�һ�������ж������ɣ����ж������飩��
//������Ҫ��ʼ����
//2���ϰ�᲻���ڵ����۸񣬵����ķ�ʽ��ͨ������һ���۸�ϵ����
//���ϵ������ԭ�ۼ�Ϊ���ռ۸�����ۿۻ�Ӱ�쵽���в�Ʒ��  
//������Ƴ�һ���������ϰ����ɸ㶨��һ�С� */
///* �۸������Ӧ����������д��� */
////enum
////{
////	Sweater,
////	jacket,
////	shirt,
////	hoodie,
////	pants
////};
//class Goods
//{
//public:
//	void MakeGoods(const char* name,double price,int num )
//	{
//		m_name = name;
//		m_num = num;
//		m_price = price;
//		 
//	}
//	void dealchangeprice(double coef)
//	{
//		m_price *= coef;
//		//cout << (int)m_price << endl;
//	}
//private:
//	const char* m_name ;
//	double m_price ;
//	int m_num ;
//};
//void changeprice(Goods * all,double coef )
//{
//	int j = 0;
//	for (j=0;j<NUM;++j)
//	{
//		all[j].dealchangeprice(coef);
//	}
//}
//int main()
//{
//	Goods gd[NUM];
//	const char*  name[NUM] = { "Sweater","jacket","shirt","hoodie","pants" };
//	double  price[NUM] = { 20,50,30,45,100 };
//	int  num[NUM] = {1,2,3,4,5};
//	int i = 0;
//	for (i=0;i< NUM;++i)
//	{
//		gd[i].MakeGoods(name[i], price[i], num[i]);
//
//	}
//	double coef = 0.8;
//	changeprice(gd,coef );
//	system("pause"); 
//	return 0;
//}