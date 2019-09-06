//#include <iostream>
//using namespace std;
//#define NUM 5
///* 某老板想要一个能快速计算订单价格的程序，请你帮他设计一个类：  
//1、这个类里需要原价和数量，原价从一个数组中读出即可（自行定义数组），
//数量需要初始化。
//2、老板会不定期调整价格，调整的方式是通过调整一个价格系数，
//这个系数乘以原价即为最终价格，这个折扣会影响到所有产品。  
//请你设计出一个类能让老板轻松搞定这一切。 */
///* 价格和数量应该在这个类中存在 */
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