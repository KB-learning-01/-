#include <iostream>
#include <cmath>
#include <algorithm> 
using namespace std;
class Complex
{
	private:
		float a;
		float b;
		static float count;
	public:
		Complex();
		Complex(float a,float b);
		Complex(const Complex &a);
		void print();
		void input();
		Complex Multiplier(Complex a);
		Complex Division(Complex a);
		Complex adder(Complex a);
		Complex Subtractor(Complex a);
		inline Complex Conjugate();
		friend Complex Bigger(Complex a,Complex b);
};
Complex::Complex()
{
	a=0.0;
	b=0.0;
}
Complex::Complex(float a,float b)
{
	this->a=a;
	this->b=b;
}
Complex::Complex(const Complex &a)
{
	*this=a;
}
void Complex::print()
{
	if (a!=0) cout<<a;
	else if (a==0);
	if (b>0) cout<<"+"<<b<<"i";
	else if (b==0);
	else if (b<0) cout<<b<<"i";
	if ((a==0)&&(b==0)) cout<<0;
	cout<<endl; 
}
void Complex::input()
{
	cin>>this->a>>this->b;
}
Complex Complex::Multiplier(Complex a)
{
	float aa=this->a;
	float bb=this->b;
	float c=a.a;
	float d=a.b;
	Complex p(aa*c-bb*d,aa*c+bb*d);
	return p;
}
Complex Complex::Division(Complex a){
	float aa=this->a;
	float bb=this->b;
	float c=a.a;
	float d=a.b;
	Complex p((aa*c+bb*d)/(c*c+d*d),(bb*c-aa*d)/(c*c+d*d));
	return p;
}
Complex Complex::adder(Complex a)
{
	Complex p(this->a+a.a,this->b+a.b);
	return p;
}
Complex Complex::Subtractor(Complex a)
{
	Complex p(this->a-a.a,this->b-a.b);
	return p;
}
inline Complex Complex::Conjugate()
{
	Complex temp(this->a,-this->b);
	return temp;
}
Complex Bigger(Complex a,Complex b)//a<b小于为真 
{
	float temp1,temp2;
	temp1=sqrt(a.a*a.a+a.b*a.b);
	temp2=sqrt(b.a*b.a+b.b*b.b);
	if (temp1<=temp2) return b;
	return a;
}
bool cmp(Complex a,Complex b)
{
	if (Bigger(a,b)==b);
}
int main()
{
	Complex a;
	Complex b(3.0,4.0);
	Complex c(b);
	a.print();
	b.print();
	c.print();
	a.input();
	a.print();
	a.Multiplier(b).print();
	a.Division(b).print();
	a.adder(b).print();
	a.Subtractor(b).print();
	a.Conjugate().print();
	Complex data[3];
	for (int i=0;i<3;i++)
	data[i].input();
	sort(data,data+3,Bigger);
	for (int i=0;i<3;i++)
	data[i].print();
	return 0;
}
