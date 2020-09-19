#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int gcb(int a,int b)
{
    if(b==0) return a;
    return gcb(b,a%b);
}
class Rational
{
	private:
		int fz;
		int fm;
	public:
		static int count;
		Rational();
		~Rational();
		Rational(Rational&a);
		Rational(int x,int y);
		void print();
		Rational input();
		friend Rational Multiplier(Rational&,Rational&);
		friend Rational Division(Rational&,Rational&);
		Rational adder(Rational&,Rational&);
		Rational Subtractor(Rational&,Rational&);
		inline void Simplify();
		void Small(Rational&);
		friend bool cmp(Rational&,Rational&);
		friend ostream& operator<<(ostream&,Rational&);
		friend istream& operator>>(istream&,Rational&);
		Rational xingshi(Rational a);
};
Rational::Rational()
{
	fz=0;
	fm=1;
	count++;
}
Rational::~Rational()
{
	count--;
}
Rational::Rational(Rational&a)
{
	fz=a.fz;
	fm=a.fm;
	count++;
}
Rational::Rational(int x,int y)
{
	fz=x;
	fm=y;
	count++;
}
void Rational::print()
{
	cout<<fz<<'/'<<fm<<endl;
}
Rational Rational::input()
{
	cin>>fz>>fm;
}
Rational Multiplier(Rational&a,Rational&b)
{
	Rational x;
	x.fz=a.fz*b.fz;
	x.fm=a.fm*b.fm;
	x.Simplify();
	return x;
}
Rational Division(Rational&a,Rational&b)
{
	Rational x;
	x.fz=a.fz*b.fm;
	x.fm=a.fm*b.fz;
	x.Simplify();
	return x;
}
Rational Rational::adder(Rational&a,Rational&b)
{
	Rational x;
	x.fz=a.fz*b.fm+a.fm*b.fz;
	x.fm=a.fm*b.fm;
	x.Simplify();
	return x;
}
Rational Rational::Subtractor(Rational&a,Rational&b)
{
	Rational x;
	x.fz=a.fz*b.fm-a.fm*b.fz;
	x.fm=a.fm*b.fm;
	x.Simplify();
	return x;
}
inline void Rational::Simplify()
{
	int x;
	x=gcb(this->fz,this->fm);
	this->fz=this->fz/x;
	this->fm=this->fm/x;
}
void Rational::Small(Rational&x)
{
	if(x.fz*fm>x.fm*fz) cout<<x<<'>'<<*this<<endl;
	else if(x.fz*fm==x.fm*fz) cout<<x<<'='<<*this<<endl;
	else cout<<x<<'<'<<*this<<endl;
}
ostream& operator<<(ostream&out,Rational&a)
{
	out<<a.fz<<'/'<<a.fm;
	return out;
}
istream& operator>>(istream&in,Rational&x)
{
	char b;
	in>>x.fz>>b>>x.fm;
	return in;
}
bool cmp(Rational&a,Rational&b)
{
	bool v=true;
	if(a.fz*b.fm>a.fm*b.fz) v=true;
	else v=false;
	return v;
}
int Rational::count=0;
Rational Rational::xingshi(Rational a)
{
	if(a.fm<0)
	{
		fm=-a.fm;
		fz=-a.fz;
	}
	return *this;
}

int main()
{
	cout<<"输入两个分数a,b";
	Rational a,a1,b,b1;
	cin>>a>>b;
	a1=a;
	b1=b;
	a=Multiplier(a1,b1);
	b=Division(a1,b1);
	a1.Simplify();
	b1.Simplify();
	a1.Small(b1);
	a.xingshi(a);
	b.xingshi(b);
	a1.xingshi(a1);
	b1.xingshi(b1);
	cout<<"a*b="<<a<<" "<<"化简得："<<a1<<endl;
	cout<<"a/b="<<b<<" "<<"化简得："<<b1<<endl;
	cout<<"比较积与商的大小:";
	a1.Small(b1);
	Rational temp[3];
	for (int i=0;i<3;i++)
	temp[i].input();
	sort(temp,temp+3,cmp);
	
	for (int i=0;i<3;i++)
	temp[i].print();
	return 0;
}
