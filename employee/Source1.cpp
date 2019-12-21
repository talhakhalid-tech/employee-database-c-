#include<iostream>
#include<string>
using namespace std;
class base{
protected:
	string name,cnic;
public:
	base(string n=" ",string c=" "):name(n),cnic(c){}
	void setter();
	void getter() const;
};
void base::setter(){
	cout<<"enter the name: ";
	cin.ignore();
	getline(cin,name);
	cout<<"enter the cnic: ";
	getline(cin,cnic);
}
void base::getter() const{
	cout<<"name: "<<name<<endl;
	cout<<"cnic: "<<cnic<<endl;
}
class employee: virtual public base{
protected:
	int eno;
	string desig;
	float salary;
public:
	employee(string n=" ",string c=" ",int e=0,string des=" ",float s=0):base(n,c),eno(e),desig(des),salary(s){}
	void setter();
	void getter() const;
};
void employee::setter(){
	base::setter();
	cout<<"enter the employee number: ";
	cin>>eno;
	cout<<"enter the employee designation: ";
	cin.ignore();
	getline(cin,desig);
	cout<<"enter the employee salary: ";
	cin>>salary;
}
void employee::getter() const{
	base::getter();
	cout<<"employee number: "<<eno<<endl;
	cout<<"employee designation "<<desig<<endl;
	cout<<"employee salary: "<<salary<<endl;
}
class student: virtual public base{
protected:
	int rno,semester;
	string deg_prog;
	float cgpa;
public:
	student(string n=" ",string c=" ",int r=0,int se=0,string d=" ",float cg=0):base(n,c),rno(r),semester(se),deg_prog(d),cgpa(cg){}
	void setter();
	void getter() const;
};
void student::setter(){
	base::setter();
	cout<<"enter the reg number: ";
	cin>>rno;
	cout<<"enter the student's semester: ";
	cin>>semester;
	cout<<"enter the student degree program: ";
	cin.ignore();
	getline(cin,deg_prog);
	cout<<"enter the student cgpa: ";
	cin>>cgpa;
}
void student::getter() const{
	base::getter();
	cout<<"reg number: "<<rno<<endl;
	cout<<"student semester: "<<semester<<endl;
	cout<<"student degree program "<<deg_prog<<endl;
	cout<<"student cgpa: "<<cgpa<<endl;
}
class e_st:public employee,public student{
	int year;
public:
	e_st(string n=" ",string c=" ",int e=0,string des=" ",float s=0,int r=0,int se=0,string d=" ",float cg=0,int y=0):employee(n,c,e,des,s),student(n,c,r,se,d,cg),year(y){}
	void setter();
	void getter() const;
};
void e_st::setter(){
	employee::setter();
	student::setter();
	cout<<"enter the degree completion year: ";
	cin>>year;
}
void e_st::getter() const{
	employee::getter();
	student::getter();
	cout<<"degree completion year: "<<year<<endl;
}
int main(){
	e_st obj;
	//obj.setter();
	obj.getter();
	system("pause");
	return 0;
}
