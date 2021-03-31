#include "stdafx.h"
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class Point
{
private:
	double x,y;
public:
	Point (double x=0,double y=0):x(x),y(y){}
	Point(const Point &p):x(p.x),y(p.y){}
	~Point(){}
	double Getx()const{ return x;}
	double Gety()const{ return y;}
	void SetX(double x1) { x=x1;}
	void SetY(double y1) { y=y1;}
	double Distance (Point &p);
	
	void Move(double dx,double dy) {  x+=dx;y+=dy;}
	
	int operator==(Point &p);

	friend ostream & operator<<(ostream &out,Point &p);
	friend istream & operator>>(istream &in,Point &p);
};

class Shape{
private:
	Point p1;
    int ID;
    string Name;
public:
	Shape(Point p,int id,string name):p1(p),ID(id),Name(name){ }

	double Getx()const{ return p1.Getx();}
	double Gety()const{ return p1.Gety();}

	int getID(){return ID;}
	string getName(){return Name;}
	void setID(int ID){this->ID=ID;}
	void setName(string Name){this->Name=Name;}
	virtual void show(){
		cout<<"x= "<<p1.Getx()<<", y= "<<p1.Gety();
	};
};
class Square:public Shape{
private:
	double w;
public:
	Square(Point p1,double w1,int id,string name="Square"):Shape(p1,id,name),w(w1){ }
	double getArea(){return w*w;}
	double getW(){return w;}
	void show(){
		cout<<"ID = "<<this->getID()<<", Name = "<<this->getName()<<", x= "<<this->Getx()<<", y= "<<this->Gety()<<", w= "<<w<<endl;
	}
};
class Rectangle:public Square{
private:
	double h;
public:
	Rectangle(Point p1,double w1,double h1,int id=0):Square(p1,w1,id,"Rectangle"),h(h1){ }

	void show(){
		//Square::show();
		cout<<"ID = "<<this->getID()<<", Name = "<<this->getName()<<", x= "<<this->Getx()<<", y= "<<this->Gety()<<", w= "<<this->getW()<<", h = "<<h<<endl;
	}

};

class Circle:public Shape{
private:
	double r;
	const double PI;
public:
	Circle(Point p1,double r1,int id,string name="Circle"):Shape(p1,id,name),r(r1),PI(13.4){ }
	double getArea(){
		return PI * r *r;
	}
	void show(){
		//Shape::show();
		cout<<"ID = "<<this->getID()<<", Name = "<<this->getName()<<", x= "<<this->Getx()<<", y= "<<this->Gety()<<", r= "<<r<<endl;
	}
};
class Ellipse:public Circle{
private:
	double r2;
public:
	Ellipse(Point p1,double r1,double r3,int id):Circle(p1,r1,id,"Ellipse"),r2(r3){ }
	void show(){
		Circle::show();
		cout<<", r2 = "<<r2<<endl;
	}
};

class Triangle:public Shape{
private:
	double base,height;
public:
	Triangle(Point p1,double a1,double b1,int id):Shape(p1,id,"Triangle"),base(a1),height(b1){ }
	void setBase(double b)
	{
		base = b;
	}
	void setHeight(double h)
	{
		height = h;
	}
	double getArea()
	{
		double a;
		a= 1.0 / 2.0 * base * height;
		return a;
	}
	void show(){
		cout<<"ID = "<<this->getID()<<", Name = "<<this->getName()<<", x= "<<this->Getx()<<", y= "<<this->Gety()<<", base= "<<base<<", height= "<<height<<endl;
	}
};

void display(Shape *s)
{
	s->show();
}

int main()
{

	Shape *s[1000];
	int count = 6;
	double x,y,w,l,r,r2,base,height;
	int select;
	int cont=1;
	int index=1;
	
	while(cont)
	{
		cout<<"************************************************"<<endl;
		cout<<"0.Exit"<<endl;
		cout<<"1.Create a Square"<<endl;
		cout<<"2.Create a Rectangle"<<endl;
		cout<<"3.Create a Circle"<<endl;
		cout<<"4.Create a Ellipse"<<endl;
		cout<<"5.Create a Triangle"<<endl;
		cout<<"6.List a Gemoatirc shapes"<<endl;
		
		cout<<"Enter your choise:"<<endl;
		cin>>select;
		switch(select){
			case 0:
				cont = 0;
				break;
			case 1:
				{
					cout<<"Enter x,y,side lenght of square:"<<endl;
					cin>>x>>y>>w;
					
					Point p1(x,y);
					s[index] = new Square(p1,w,index);
					index++;
				
				}
				break;
			
			case 2:
				{
					cout<<"Enter x,y,width,length:"<<endl;
					cin>>x>>y>>w>>l;
					
					Point p1(x,y);
					s[index] = new Rectangle(p1,w,l,index);
					index++;
				
				}
				break;
			case 3:
				{
					cout<<"Enter x,y,radius:"<<endl;
					cin>>x>>y>>r;
					
					Point p1(x,y);
					s[index] = new Circle(p1,r,index);
					index++;
				}
				break;
			case 4:
				{
					cout<<"Enter x,y,r,r2:"<<endl;
					cin>>x>>y>>r>>r2;
					
					Point p1(x,y);
					s[index] = new Ellipse(p1,r,r2,index);
					index++;
				}
				break;
			case 5:
				{
					
					cout<<"Enter x,y,base,height:"<<endl;
					cin>>x>>y>>base>>height;

					Point p1(x,y);
					s[index] = new Triangle(p1,base,height,index);
					index++;
				}
				break;
			case 6:
				{
					for(int i=1; i<count;i++)
						s[i]->show();
				}
				break;
		}
 }
	return 0;
}

