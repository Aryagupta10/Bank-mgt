#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<stdio.h>
#include<process.h>
#include<dos.h>
using namespace std;
int main();
void main1();
void adminmode();
void addemp();
void searchemp();
void showemp();
void removeemp();
void changeapass();
void changedata();
void openac();
void changeepass();
void findac();
void editac();
void passbook();
void closeac();
void transfer();
void showbal();
void changecpass();
void showac();
void changebal(int);

class manager
{
	char apass[7];

public:
	manager()
	{
		strcpy(apass,"123321");
	}
	void getapass();
	int mlogin();
}m;

void manager::getapass()
{
	cout<<"\nEnter Password-";
	for(int i=0;i<6;i++)
	{
		apass[i]=getch();
		cout<<"*";
	}
	apass[6]='\0';
}

int manager::mlogin()
{
	system("cls");
	char p[7];
	cout<<"Enter Admin Password\n";
	for(int i=0;i<6;i++)
	{
		p[i]=getch();
		cout<<"*";
	}
	p[6]='\0';
	if(!strcmpi(p,apass))
	{
		cout<<"\nACCESS GRANTED";
		getch();
		adminmode();
	}
	else
	{
		cout<<"\nACCESS DENIED";
		getch();
		main1();
	}
}
class employee
{
	char empid[20];
	char adhaarno[13];
	char name[20];
	char desig[20];
	float salary;
	char epass[5];

public:

	void getdata();
	void showdata();
	void ldata(char a[],int);
	int compid(char b[]);
	int compdesg(char b[]);
	int compname(char b[]);
	int login();

}emp;

void employee::getdata()
{
	a:
	float a;
	cout<<"\t\t\t  Employee Registration Form\n\n\n\n";
	cout<<"Name of the employee - \t\t\t\tAdhaar no.-\n\n\n";
	cout<<"Salary - \t\t\t\t\tDesignation - \n" ;
	
	gets(name);

	for(int i=0;i<12;i++)
	{
		adhaarno[i]=getch();
		cout<<adhaarno[i];
	}
	adhaarno[12]='\0';
	cout<<endl;
	cin>>a;
	while(a<=0)
	{
		cout<<"\nWrong Input!";
		getch();
		system("cls");
		goto a;
	}
	salary=a;
	
	gets(desig);
}

void employee::showdata()
{
	cout<<name;
	cout<<"\t\t";
	cout<<empid;
	cout<<"\t\t";
	cout<<adhaarno;
	cout<<"\t";
	cout<<salary;
	cout<<"\t\t";
	cout<<desig;
	cout<<"\n";
}

void employee::ldata(char id[],int a=1)
{
	if(a==1)
		strcpy(empid,id);
	cout<<"\nPlease choose a 4 digit password - ";
	for(int i=0;i<4;i++)
	{
		epass[i]=getch();
		cout<<"*";
	}
	epass[4]='\0';
}

int employee::login()
{
	char pin[5];
	cout<<"Pin - " ;
	for(int i=0;i<4;i++)
	{
		pin[i]=getch();
		cout<<"*";
	}
	pin[4]='\0';
	return strcmp(pin,epass);
}

int employee::compid(char a[])
{
	return strcmp(a,empid);
}

int employee::compname(char a[])
{
	return strcmp(a,name);
}

int employee::compdesg(char a[])
{
	return strcmp(a,desig);
}



class customer
{
	long acno;
	char actype;
	char name[20];
	char adhaarno[13];
	long balance;
	char pass[5];
	float pb[90];
	char pbook[90];
	int count;

public:
	long retbal();
	void getdata(long,char,int);
	void showdata();
	int login();
	long accno();
	int compname(char a[]);
	void passbook();
	void getnewpass();
	void deposit(long);
	void withdraw(long);

}cust;


long customer::retbal()
{
	return balance ;
}


void customer::getdata(long ac,char a,int f=1)
{
	long amount;
	if(f==1)
	{
		acno=ac;
		actype=a;
	}
	b:
	cout<<"\t\t\t  Customer Registration Form\n\n\n\n";
	cout<<"Name of the customer - \t\t\t\tAdhaar no.-\n\n\n";
	cout<<"Amount - \t\t\t\t\tPassword - \n" ;
	gets(name);
	for(int j=0;j<12;j++)
	{
		adhaarno[j]=getch();
		cout<<adhaarno[j];
	}
	adhaarno[12]='\0';
	cout<<endl;

	cin>>amount;
	while(actype=='C'&&amount<5000 || actype=='S'&&amount<2000)
	{
		cout<<"\nWrong Input!";
		getch();
		system("cls");
		goto b;
	}
	balance=amount;
	pb[0]=balance;
	count=1;
	pbook[0]='d';
	for(int i=0;i<4;i++)
	{
		pass[i]=getch();
		cout<<"*";
	}
	pass[4]='\0';

}

void customer::showdata()
{
	cout<<acno;
	cout<<"\t\t\t";
	cout<<name;
	cout<<"\t\t";
	cout<<adhaarno;
	cout<<"\t\t";
	cout<<balance;
	cout<<"\n";
}

int customer::login()
{
	char pin[5];
	cout<<"\n\nPin - ";
	for(int i=0;i<4;i++)
	{
		pin[i]=getch();
		cout<<"*";
	}
	pin[4]='\0';
	return strcmp(pin,pass);
}

void customer::getnewpass()
{
	cout<<"\n\nPin - ";
	for(int i=0;i<4;i++)
	{
		pass[i]=getch();
		cout<<"*";
	}
	pass[4]='\0';
}

void customer::deposit(long amount)
{
	int y;
	balance=balance+amount;
	pb[count]=amount;
	count++;
	y=strlen(pbook);
	pbook[y]='d';
	pbook[y+1]='\0';

}

void customer::withdraw(long amount)
{
	int y;
	balance=balance-amount;
	pb[count]=amount;
	count++;
	y=strlen(pbook);
	pbook[y]='w';
	pbook[y+1]='\0';
}

long customer::accno()
{
	return acno;
}

int customer::compname(char a[])
{
	return strcmpi(a,name);
}

void customer::passbook()
{
	int x,y;
	cout<<endl;
	for(int i=0;i<count;i++)
	{
		if(pbook[i]=='d')
		{
		      cout<<pb[i]<<endl;
		}
		if(pbook[i]=='w')
		{
			cout<<"\t\t\t"<<pb[i]<<endl;
		}
	}
}

//1. Admin Mode and its functions

void adminmode()
{
	while(1)
	{
		system("cls");
		int choice;
		cout<<"\t\t\t\tWelcome to XYZ Bank (Admin Mode)\n\n\n\n";
		cout<<"Please choose the program mode\n";
		cout<<"1.) Add Employee \n2.) search Employee \n3.) Show Employee \n4.) Remove Employee \n5.) Modify Employee Data\n6.) Change Admin Password \n7.) Logout \n8.) Exit\n\n";
		cin>>choice;
		switch(choice)
		{
			case 1: addemp();
				break;

			case 2: searchemp();
				break;

			case 3: showemp();
				break;

			case 4:	removeemp();
				break;

			case 5: changedata();
				break;

			case 6: changeapass();
				break;

			case 7: main1();
				break;

			case 8: exit(0);

			default: cout<<"\nWrong Choice!\n";
				 getch();
		}
	}
}

void addemp()
{
	f:
	char id[20];
	ifstream fin;
	ofstream fout;
	system("cls");
	cout<<"Chose an user id - ";
	
	gets(id);
	fin.open("employee.dat",ios::binary);
	while(fin.read((char*)&emp,sizeof(emp)))
	{
		if(!emp.compid(id))
		{
			cout<<"\nId already exist";
			getch();
			fin.close();
			goto f;
		}
	}
	emp.ldata(id);
	system("cls");
	emp.getdata();
	fin.close();
	fout.open("employee.dat",ios::binary|ios::app);
	fout.write((char*)&emp,sizeof(emp));
	cout<<"\n\nEmployee added successfully";
	fout.close();
	getch();
}

void searchemp()
{
system("cls");
	fstream f;
	int flag=0;
	char id[20];
	cout<<"\t\t\tSearch Employee\n\n";
	cout<<"Enter the Employee ID - ";
	gets(id);
	cout<<"\n\nName\t\tUser ID\t\tAdhaar no.\tSalary\t   Designation\n";
	cout<<"_______________________________________________________________________\n\n";
	f.open("employee.dat",ios::binary|ios::in|ios::out);
	while(f.read((char*)&emp,sizeof(emp)))
	{
		if(!emp.compid(id))
		{
			emp.showdata();
			flag=1;
		}
	}
	if(flag==0)
		cout<<"\nNo Record Found!!";
	f.close();
	getch();
}

void showemp()
{
	system("cls");
	fstream f;
	int flag=0;
	cout<<"\t\t\t\tEmployee Details";
	cout<<"\n\nName\t\tUser Id\t\tAdhaar no.\tSalary\t   Designation\n";
	cout<<"_______________________________________________________________________\n\n";
	f.open("employee.dat",ios::binary|ios::in);
	while(f.read((char*)&emp,sizeof(emp)))
	{
		emp.showdata();
		flag=1;
	}
	if(flag==0)
		cout<<"\nNo Record Found!!";
	f.close();
	getch();
}

void removeemp()
{
	system("cls");
	ifstream fin;
	fin.open("employee.dat",ios::binary);
	ofstream fout;
	fout.open("temp.dat",ios::binary);
	int f=0;
	char a[20];
	cout<<"\t\t\t Delete Employee";
	cout<<"\n\nEnter the employee user id -  ";
	gets(a);
	while(fin.read((char*)&emp,sizeof(emp)))
	{
		if(emp.compid(a))
			fout.write((char*)&emp,sizeof(emp));
		else
			f=1;
	}
	fin.close();
	fout.close();
	remove("employee.dat");
	rename("temp.dat","employee.dat");
	if(f==0)
		cout<<"\n\nRecord not found!";
	else
		cout<<"\n\nRecord Deleted Successfully!";
	getch();

}

void changeapass()
{
	system("cls");
	m.getapass();
	cout<<"\n\nPassword Changed Successfully";
	getch();
}

void changedata()
{
	system("cls");
	fstream f;
	f.open("employee.dat",ios::binary|ios::in|ios::out);
	char a[20];
	int pos,f1=0;
	cout<<"\t\t\t Modify Employee data\n\n";
	cout<<"Enter the employee id - ";
	gets(a);
system("cls");
	while(!f.eof())
	{       pos=f.tellg();
		f.read((char*)&emp,sizeof(emp));
		if(!emp.compid(a))
		{
			emp.getdata();
			f.seekg(pos);
			f.write((char*)&emp,sizeof(emp));
			f1=1;
			break;
		}
	}
	f.close();
	if(f1==0)
		cout<<"\nRecord not found!";
	else
		cout<<"\nRecord Updated Successfully!";
	getch();

}



//2. Employee Mode and its functions

void elogin()
{
	system("cls");
	ifstream fin;
	int flag1=0,flag2=0,flag3=0;
	char a[20];
	fin.open("employee.dat",ios::binary);
	while(fin.read((char*)&emp,sizeof(emp)))
	{
		if(!flag3==1)
		{
			cout<<"\nUser Id - ";
			gets(a);
		}
		flag3=1;
		if(!emp.compid(a))
		{
			flag2=1;
			if(!emp.login())
			{
				flag1=1;
				break;
			}
		}
	}
	fin.close();
	if(flag3==0)
	{
		cout<<"\nNo Record found!";
		cout<<"\nPlease add a customer from employee mode";
		getch();
		main1();
	}
	else if(flag2==0)
	{
		cout<<"\nNo user found!";
		getch();
		elogin();
	}
	else if(flag1==0)
	{
		cout<<"\nWrong Password!";
		getch();
		elogin();
	}

}

void empmode()
{
	elogin();
	while(1)
	{
		system("cls");
		int choice;
		cout<<"\t\t\t\tWelcome to XYZ Bank (Employee Mode)\n\n\n\n";
		cout<<"Please choose the program mode\n";
		cout<<"1.) Open Account \n2.) search Account \n3.) Show Account \n4.) Deposit \n5.) Withdrawl\n6.) Modify Account \n7.) Close Account \n8.) Change Password \n9.) Logout\n10.) Exit\n\n";
		cin>>choice;
		switch(choice)
		{
			case 1: openac();
				break;

			case 2: findac();
				break;

			case 3: showac();
				break;

			case 4: changebal(1);
				break;

			case 5: changebal(2);
				break;

			case 6: editac();
				break;

			case 7: closeac();
				break;

			case 8: changeepass();
				break;

			case 9: main1();
				break;

			case 10: exit(0);

			default: cout<<"\nWrong Choice\n";
				 getch();
		}
	}
}

void openac()
{
	system("cls");
	int flag=0,choice;
	long ac;
	ifstream fin;
	fin.open("customer.dat",ios::binary);
	while(fin.read((char*)&cust,sizeof(cust)))
	{
		flag=1;
	}
	if(flag==0)
	{
		ac=10000;
	}
	else
	{
		ac=cust.accno()+1;
	}
	fin.close();
	cout<<"Enter the account type\n\n1.) Current (Mininmum Deposit 5000)\n2.) Saving (Minimum Deposit 2000)\n\n";
	cin>>choice;
	switch(choice)
	{
		case 1: system("cls");
			cust.getdata(ac,'C');
			break;

		case 2: system("cls");
			cust.getdata(ac,'S');
			break;

		default: cout<<"Wrong Choice!";
			 openac();
	}

	ofstream fout;
	fout.open("customer.dat",ios::binary|ios::app);
	fout.write((char*)&cust,sizeof(cust));
	fout.close();
	cout<<"\n\nYour Account Number - "<<ac;
	cout<<"\n\nAccount Created successfully!";
	getch();
}

void showac()
{
	system("cls");
	fstream f;
	int flag=0;
	cout<<"\t\t\t\tCustomer Details";
	cout<<"\n\nAccount No.\t\tName\t\tAdhaar no.\t     Balance\n";
	cout<<"_______________________________________________________________________\n\n";
	f.open("customer.dat",ios::binary|ios::in|ios::out);
	while(f.read((char*)&cust,sizeof(cust)))
	{
		cust.showdata();
		flag=1;
	}
	if(flag==0)
		cout<<"\nNo Record Found!!";
	f.close();
	getch();
}

void findac()
{
	system("cls");
	fstream f;
	int choice;
	float ac;
	int flag=0;
	char a[20];
	cout<<"\t\t\tSearch Employee\n\n1.) Using Account No.\n2.) Using Name\n";
	cin>>choice;
	cout<<"Enter the search keyword - ";
	if(choice==1)
		cin>>ac;
	else if(choice==2)
		gets(a);
	else
		findac();

	cout<<"\n\nAccount No.\t\tName\t\tAdhaar no.\tBalance\n";
	cout<<"_______________________________________________________________________\n\n";
	f.open("customer.dat",ios::binary|ios::in|ios::out);
	while(f.read((char*)&cust,sizeof(cust)))
	{
		if(choice==1&&ac==cust.accno())
		{
			cust.showdata();
			flag=1;
		}
		else if(choice==2&&!cust.compname(a))
		{
			cust.showdata();
			flag=1;
		}

	}
	if(flag==0)
		cout<<"\nNo Record Found!!";
	f.close();
	getch();
}

void editac()
{
	system("cls");
	fstream f;
	f.open("customer.dat",ios::binary|ios::in|ios::out);
	float ac;
	int pos,f1=0;
	cout<<"\t\t\t Modify Employee data\n\n";
	cout<<"Enter the account no. - ";
	cin>>ac;
system("cls");
	while(!f.eof())
	{       pos=f.tellg();
		f.read((char*)&cust,sizeof(cust));
		if(ac==cust.accno())
		{
			cust.getdata(32,'a',2);
			f.seekg(pos);
			f.write((char*)&cust,sizeof(cust));
			f1=1;
			break;
		}
	}
	f.close();
	if(f1==0)
		cout<<"\nRecord not found!";
	else
		cout<<"\nRecord Updated Successfully!";
	getch();

}

void changeepass()
{
	system("cls");
	fstream f;
	f.open("employee.dat",ios::binary|ios::in|ios::out);
	char a[20];
	int pos,f1=0;
	cout<<"\t\t\t Change Employee Password\n\n";
	cout<<"Enter the employee id - ";
	gets(a);
	while(!f.eof())
	{       pos=f.tellg();
		f.read((char*)&emp,sizeof(emp));
		if(!emp.compid(a))
		{
			emp.ldata("abc",2);
			f.seekg(pos);
			f.write((char*)&emp,sizeof(emp));
			f1=1;
			break;
		}
	}
	f.close();
	if(f1==0)
		cout<<"\nRecord not found!";
	else
		cout<<"\nPassword Changed Successfully!";
	getch();


}

void closeac()
{
	system("cls");
	ifstream fin;
	fin.open("customer.dat",ios::binary);
	ofstream fout;
	fout.open("temp.dat",ios::binary);
	int flag=0;
	long ac;
	cout<<"\t\t\t Delete Customer";
	cout<<"\n\nEnter the Customer account no. -  ";
	cin>>ac;
	while(fin.read((char*)&cust,sizeof(cust)))
	{
		if(ac==cust.accno())
			fout.write((char*)&cust,sizeof(cust));
		else
			flag=1;
	}
	fin.close();
	fout.close();
	remove("customer.dat");
	rename("temp.dat","customer.dat");
	if(flag==0)
		cout<<"\n\nRecord not found!";
	else
		cout<<"\n\nRecord Deleted Successfully!";
	getch();

}

void changebal(int a)
{
	fstream f;
	int pos,flag=0;
	long ac,amount;
	b:
	system("cls");
	f.open("customer.dat",ios::binary|ios::in|ios::out);
	cout<<"Enter account no. - ";
	cin>>ac;
	while(!f.eof())
	{
		pos=f.tellg();
		f.read((char*)&cust,sizeof(cust));
		if(ac==cust.accno())
		{
			flag=1;
			break;
		}

	}
	if(flag==0)
	{
		cout<<"\nNo account found";
		getch();
		goto b;
	}
	if(a==1)
	{
	system("cls");
		cout<<"\t\t\t\t\tDeposit\n\n";
		cout<<"Amount - ";
		cin>>amount;
		cust.deposit(amount);
		f.seekp(pos);
		f.write((char*)&cust,sizeof(cust));
		f.close();
		cout<<"\n\nBalance updated successfully";
		getch();

	}
	if(a==2)
	{
		system("cls");
		cout<<"\t\t\t\t\tWithdraw\n\n";
		cout<<"Amount - ";
		cin>>amount;
		if(amount<=cust.retbal()-1000)
		{
			cust.withdraw(amount);
			f.seekp(pos);
			f.write((char*)&cust,sizeof(cust));
			f.close();
			cout<<"\n\nBalance updated successfully";
			getch();
		}
		else
		{
			cout<<"\nYour account do not have sufficient balance";
			getch();
			f.close();
			changebal(2);
		}
	}
}

//3. Customer Mode and its functions

void clogin()
{
	system("cls");
	ifstream fin;
	int flag1=0,flag2=0,flag3=0;
	long a;
	fin.open("customer.dat",ios::binary);
	while(fin.read((char*)&cust,sizeof(cust)))
	{
		if(!flag3==1)
		{
			cout<<"\nAccount no. - ";
			cin>>a;
		}
		flag3=1;
		if(a==cust.accno())
		{
			flag2=1;
			if(!cust.login())
			{
				flag1=1;
				break;
			}
		}
	}
	fin.close();
	if(flag3==0)
	{
		cout<<"\nNo Record found!";
		cout<<"\nPlease add a customer from admin mode";
		getch();
		main1();
	}
	else if(flag2==0)
	{
		cout<<"\nNo user found!";
		getch();
		clogin();
	}
	else if(flag1==0)
	{
		cout<<"\nWrong Password!";
		getch();
		clogin();
	}

}

void custmode()
{
	clogin();
	while(1)
	{
		system("cls");
		int choice;
		cout<<"\t\t\t\tWelcome to XYZ Bank (Employee Mode)\n\n\n\n";
		cout<<"Please choose the program mode\n";
		cout<<"1.) Transfer Amount \n2.) Passbook \n3.) Show Balance \n4.) Change Password \n5.) Logout\n6.) Exit\n\n";
		cin>>choice;
		switch(choice)
		{
			case 1: transfer();
				break;

			case 2: passbook();
				break;

			case 3: showbal();
				break;

			case 4: changecpass();
				break;

			case 5: main1();
				break;

			case 6: exit(0);

			default: cout<<"\nWrong Choice\n";
				 getch();
		}
	}

}

void transfer()
{
	system("cls");
	long ac1,ac2,amount;
	int flag=0,pos;
	ac1=cust.accno();
	cout<<"\t\t\t\tInter Bank Transfer\n";
	cout<<"\nAmount - ";
	cin>>amount;
	if(amount<=cust.retbal())
	{
		cout<<"\n\nEnter account no - ";
		cin>>ac2;
	}
	else
	{
		cout<<"\nInsufficient Funds!" ;
		getch();
		transfer();
	}
	fstream f;
	f.open("customer.dat",ios::binary|ios::in);
	while(!f.eof())
	{
		pos=f.tellg();
		f.read((char*)&cust,sizeof(cust));
		if(ac2==cust.accno())
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\nNo account found!";
		getch();
		f.close();
		transfer();
	}
	else
	{
		cust.deposit(amount);
		f.seekp(pos);
		f.write((char*)&cust,sizeof(cust));
		cout<<"\nTransferred Successfully!";
		getch();
		f.close();

	}
	f.open("customer.dat",ios::binary|ios::in);
	while(!f.eof())
	{
		pos=f.tellg();
		f.read((char*)&cust,sizeof(cust));
		if(ac1==cust.accno())
		{
			break;
		}
	}
	cust.withdraw(amount);
	f.seekp(pos);
	f.write((char*)&cust,sizeof(cust));
	f.close();

}

void passbook()
{
	system("cls");
	cout<<"\t\t\t\tPassbook\n\n\n";
	cout<<"Deposit\t\t\tWithdraw\n";
	cout<<"____________________________________________________________";
	cust.passbook();
	getch();
}

void showbal()
{
	system("cls");
	cout<<"\n Balance - "<<cust.retbal();
	getch();

}

void changecpass()
{
	system("cls");
	fstream f;
	f.open("customer.dat",ios::binary|ios::in|ios::app|ios::out);
	long ac;
	int pos,f1=0;
	cout<<"\t\t\t Change Customer Password\n\n";
	cout<<"Enter the account no. - ";
	cin>>ac;
	while(!f.eof())
	{       pos=f.tellg();
		f.read((char*)&cust,sizeof(cust));
		if(ac==cust.accno())
		{
			cust.getnewpass();
			f.seekg(pos);
			f.write((char*)&cust,sizeof(cust));
			f1=1;
			break;
		}
	}
	f.close();
	if(f1==0)
		cout<<"\nRecord not found!";
	else
		cout<<"\nPassword Changed Successfully!";
	getch();



}

//Intro

void intro()
{
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t    ";
	char intro1[]={"COMPUTER SCIENCE PROJECT"};  //array storing name of project
	for(int i=0;intro1[i]!='\0';i++)
	{
		cout<<intro1[i];
	}
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t    ";
	char intro2[]={"BANK MANAGEMENT PROJECT \n\t\t\t    MADE BY -Arya Gupta \n\t\t\t "};
	for(int i=0;intro2[i]!='\0';i++)         //array storing our name
	{
		cout<<intro2[i];
	}
	getch();
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t    ";
	char intro3[]={"WELCOME TO XYZ BANK"};   //array storing name of bank
	for(int i=0;intro3[i]!='\0';i++)
	{
		cout<<intro3[i];
	}
	getch();
	system("cls");
}



void main1()
{
	system("cls");
	int choice;
	cout<<"\t\t\t\tWelcome to XYZ bank\n\n\n\n";
	cout<<"Please choose the program mode\n";
	cout<<"1.) Administration Mode \n2.) Employee Mode \n3.) Customer Mode \n4.) Exit\n\n";
	cin>>choice;
	switch(choice)
	{
		case 1:	m.mlogin();
			adminmode();
			break;

		case 2: empmode();
			break;

		case 3: custmode();
			break;

		case 4: exit(0);

		default: cout<<"\nWrong Choice";
			 getch();
			 main1();
	}
}

int main()
{
  //	intro();
	main1();
	return 0;
}
