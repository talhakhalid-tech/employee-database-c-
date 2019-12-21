#include <iostream>
#include <string>
using namespace std;
#define max 100
int ecount=0;
class emp
	{
		protected:
			int e_no;
			string name;
			string cnic;
		public:
			emp(int nn=0,string nn2=" ",string cn=0):e_no(nn),name(nn2),cnic(cn){}
			virtual void setter();
			virtual void getter() const;	
			virtual void isout()=0{}
	};
void emp:: setter()
{
	cout<<"Enter The Employe Number: ";
	cin>>e_no;
	cout<<"Enter The Name Of Employee:";
	cin.ignore();
	getline(cin,name);
	cout<<endl<<"CNIC Of Employee: ";
	getline(cin,cnic);
}
void emp::getter() const
{
	cout<<"employee number: "<<e_no<<endl;
	cout<<"employee name: "<<name<<endl;
	cout<<"Cnic number: "<<cnic<<endl;
}	
class manager: public emp
	{
		protected:
			string title;
			float club_due;
		public:
			manager(int num=0,string nam=" ",string cn="",string tt=" ",float n2=0):emp(num,nam,cn),title(tt),club_due(n2){}
			void setter();
			void getter() const;
			void isout();
	};	
	
void manager::setter ()
{
	emp::setter();
	cout<<"Enter The Employee Title: ";
	getline(cin,title);
	cout<<"Enter The Clubs Dues:";
	cin>>club_due;
}
void manager::getter() const
{
	emp::getter();
	cout<<"Employee title: "<<title<<endl;
	cout<<"Club dues: "<<club_due<<endl;
}	
void manager::isout(){
	if(club_due<10000){
		cout<<"is outstanding!!!\n";
		ecount++;
	}
}
class scientist: public emp
	{
		protected:
			string field;
			int publication;
		public:
			scientist(int num=0,string nam=" ",string cn="",string ff=" ",int pp=0):emp(num,nam,cn),field(ff),publication(pp){}
			void setter();
			void getter() const;	
			void isout();
	};	
void scientist::setter()
{
			emp::setter();
			cout<<"Enter The Field of Scientist: ";
			getline(cin,field);
			cout<<"Enter The Number of Publication:";
			cin>>publication;
}
void scientist::getter() const{
	
				emp::getter();
				cout<<"Scientist's field"<<field<<endl;
				cout<<"number of publications: "<<publication<<endl;
			
}
void scientist::isout(){
				if(publication >=5){
					cout<<"is outstanding!!!\n";
					ecount++;
				}
}
class labour: public emp{
		protected:
			string shift;
			float hour_work;
		public:
			labour(int num=0,string nam=" ",string cn="",string tt=" ",float n2=0):emp(num,nam,cn),shift(tt),hour_work(n2){}
			void setter();
			void getter() const;
			void isout();
	};	
	void labour::setter(){
				emp::setter();
				cout<<"Enter The Employee Shift: ";
				getline(cin,shift);
				cout<<"Enter The Hour Worked:";
				cin>>hour_work;
			}
	void labour::getter() const{
				emp::getter();
				cout<<"Employee Shift: "<<shift<<endl;
				cout<<"Hour worked: "<<hour_work<<endl;
			}
	void labour::isout(){
		if(hour_work>8){
			cout<<"is outstanding!!!\n";
			ecount++;
		}
	}

class foreman:public labour{
protected:
	int l_num;
public:
	foreman(int num=0,string nam=" ",string cn="",string tt=" ",float n2=0,int l=0):labour(num,nam,cn,tt,n2),l_num(l){}
	void setter();
	void getter() const;
	void isout();
	};
void foreman::setter()
{
		labour::setter();
			cout<<"Enter The Number of Labours under:";
			cin>>l_num;
}
void foreman::getter() const{
	
	labour::getter();
	cout<<"Labour's under: "<<l_num<<endl;
			
}
void foreman::isout(){
				if(l_num >20){
					cout<<"is outstanding!!!\n";
					ecount++;
				}
}
int main()
{
	char ch;
	emp *e[max];
	int count=0,mc=0,sc=0,lc=0,fc=0;
	do{
	cout<<"---------menu--------\n";
	cout<<"1. Manager.\n2. Scientist\n3. Labour.\n4. Foreman.\n5. Display data.\n6. Exit.\nenter your choice: ";
	cin>>ch;
	switch(ch){
		case '1':{
			e[count]=new manager;
			e[count++]->setter();
			break;		
		}
		case '2':{
			e[count]=new scientist;
			e[count++]->setter();
			break; 
		}
		case '3':{
			e[count]=new labour;
			e[count++]->setter();
			break; 
		}
		case '4':{
			e[count]=new foreman;
			e[count++]->setter();
			break;
			   }
		case '5':{
			for(int i=0;i<count;i++){
				cout<<"--------------------------------\n";
				e[i]->getter();
				e[i]->isout();
				if(typeid(*e[i])==typeid(manager))
					mc++;
				else if(typeid(*e[i])==typeid(scientist))
					sc++;
				else if(typeid(*e[i])==typeid(labour))
					lc++;
				else if(typeid(*e[i])==typeid(foreman))
					fc++;
			}
				cout<<"--------------------------------\n";
			cout<<"managers are: "<<mc<<endl;
			cout<<"scientists are: "<<sc<<endl;
			cout<<"labours are: "<<lc<<endl;
			cout<<"Foremans are: "<<fc<<endl;
			cout<<"Total outstanding employees: "<<ecount<<endl;
			break;
			 
		}
		case '6':{
			cout<<"good bye\n";
			break;
			}
		default:
			cout<<"invalid choice\n";
	}
	}while(ch != '6');
	delete[] e;
	system("pause");
	return 0;
}	
