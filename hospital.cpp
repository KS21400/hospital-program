#include<stdio.h>
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<string.h>
class Patient
{
 char phoneno[20];
 char date[15];
 int age,temp,pulse;
 char bloodp[10];
 char name[20],sex[10],address[100],email[30],bloodgr[10];
 char addictions[100],complains[100],duration[20];
 char respiratoryrate[20],symptoms[200];

 public:
 int opdno;
 void display();
 void write();
 void del();
 void search();
 void input(Patient);
 void output(Patient);

};
void Patient::output(Patient read)       // function to show patient details
{
   cout<<"\n Name: ";
   cout<<read.name;
   cout<<"\n Date(dd/mm/yy): ";
   cout<<read.date;
   cout<<"\n Age: ";
   cout<<read.age;
   cout<<"\n Sex(M/F): ";
   cout<<read.sex;
   cout<<"\n Address: ";
   cout<<read.address;
   cout<<"\n Phone number: ";
   cout<<read.phoneno;
   cout<<"\n Email id: ";
   cout<<read.email;
   cout<<"\n Blood group: ";
   cout<<read.bloodgr;
   cout<<"\n Pulse rate(beats/min): ";
   cout<<read.pulse;
   cout<<"\n Blood pressure(mm Hg): ";
   cout<<read.bloodp;
   cout<<"\n Temperature(F): ";
   cout<<read.temp;
   cout<<"\n Addictions: ";
   cout<<read.addictions;
   cout<<"\n Complains: ";
   cout<<read.complains;
   cout<<"\n Duration: ";
   cout<<read.duration;
   cout<<"\n Respiratory rate(inhalation per min): ";
   cout<<read.respiratoryrate;

}
void Patient::input(Patient write)       // function to read patient's details
{   char ch;


 ofstream outf;
 outf.open("pdata.cpp",ios::out|ios::binary|ios::app);
 cout<<"\n Name: ";
 gets(write.name);
 cout<<"\n Date(dd/mm/yy): ";
 gets(write.date);
 cout<<"\n Age: ";
 cin>>write.age;
 cout<<"\n Sex(M/F): ";
 gets(write.sex);
 cout<<"\n Address: ";
 gets(write.address);
 cout<<"\n Phone number: ";
 cin>>write.phoneno;
 cout<<"\n Email id: ";
 gets(write.email);
 cout<<"\n Blood group: ";
 gets(write.bloodgr);
 cout<<"\n Pulse rate(beats/min): ";
 cin>>write.pulse;
 cout<<"\n Blood pressure(mm Hg): ";
 cin>>write.bloodp;
 cout<<"\n Temperature(F): ";
 cin>>write.temp;
 cout<<"\n Addictions: ";
 gets(write.addictions);
 cout<<"\n Complains: ";
 gets(write.complains);
 cout<<"\n Duration: ";
 gets(write.duration);
 cout<<"\n Respiratory rate(inhalation per min): ";
 gets(write.respiratoryrate);
 cout<<"\nSaving........";
 delay(1200);
 cout<<"\nSaved";
 outf.write((char*)&write,sizeof(Patient));
 outf.close();


}
void Patient::display()  // to display a patient's details
{
 clrscr();
 int opd,flag=0;
 cout<<" Give the opd no:";
 cin>>opd;
 ifstream fin;
 Patient read;
 fin.open("pdata.cpp",ios::in|ios::binary);
 while(!fin.eof())
 {
   fin.read((char*)&read,sizeof(Patient));
   if(read.opdno==opd)
   {
      flag=1;
      cout<<" Patient's opdnumber:"<<read.opdno;
      output(read);
      cout<<"\n Press any key to continue\n";
      cin.get();
      cin.get();
      break;

   }

 }
 fin.close();
 if(!flag)
 {
  cout<<" No entry exists\n";
  cout<<" Press any key to continue\n";
  cin.get();
  cin.get();
 }
}

void Patient::del()    // function to delete an entry
{
 ifstream fin;
 ofstream outf;
 clrscr();
 char cho;
 int opd,flag=0;
 cout<<"\nGive the opd number of the record to be deleted:";
 cin>>opd;
 Patient write,read;
 fin.open("pdata.cpp",ios::binary|ios::in);
 outf.open("temp.cpp",ios::binary|ios::out);
 while(!fin.eof())
 {
  fin.read((char*)&read,sizeof(Patient));
  if(read.opdno==opd)
  {
   flag=1;
  }
  else
  outf.write((char*)&read,sizeof(Patient));


 }

 if(!flag)
 {
  cout<<"No entry exists\n";
  cout<<"Press any key to continue\n";
  cin.get();
  cin.get();

 }
 fin.close();
 outf.close();
 remove("pdata.cpp");
 rename("temp.cpp","pdata.cpp");

}
void Patient::write()         // function to write details in the database
{      char cho;
do{

 clrscr();

 Patient write;
 cout<<"\t\t\tType the Patient's data\n";
 cout<<" Patient's opdnumber:";
 ifstream fin;
 int a=0;
 fin.open("pdata.cpp",ios::out|ios::binary);
 while(!fin.eof())
 {

   fin.read((char*)&write,sizeof(Patient));
   if(write.opdno<a)
   break;
   a++;

 }
 fin.close();
 cout<<a<<'\n';
 write.opdno=a;
 input(write);
 cout<<"\nDo you want to add more entry(y/n):";
 cin>>cho;
}while(cho =='y' || cho =='Y');
}
void Patient::search()  // function to search a patient
{ int i,opdno,flag=0;
  ifstream fin;
  fin.open("pdatbase.dat",ios::binary|ios::in);
  Patient search;
  clrscr();
  cout<<"\n ******************************";
  cout<<"\n *  1.)Search by OPD no.      *";
  cout<<"\n *  2.)Search by Patient name.*";
  cout<<"\n ******************************";
  cout<<"\n Enter your choice:";
  cin>>i;
  switch(i)
  {
    case 1: clrscr();
	    cout<<"Enter the OPD no. of the patient to be searched:";
	    cin>>opdno;
	    while(!fin.eof())
	    {
	      fin.read((char*)&search,sizeof(Patient));
	      if(search.opdno==opdno)
	      {
		 flag=1;
		 cout<<"Patient's opdnumber:"<<search.opdno;
		 output(search);
		 cout<<"\n Press any key to continue\n";
		 cin.get();
		 cin.get();
		 break;
	      }
	   }

	      if(!flag)
	      {
		     cout<<" No entry exists\n";
		     cout<<" Press any key to continue\n";
		     cin.get();
		     cin.get();
	      }

	    break;
    case 2: clrscr();
	    int i,str,temp;
	    char name[20];
	    cout<<" Enter the name of the patient to be searched: ";
	    gets(name);
	    while(!fin.eof())
	    {
	      fin.read((char*)&search,sizeof(Patient));
	      temp=strcmp(name,search.name);
	       if(temp==0)
	       {
		 flag=1;
		 cout<<" Patient's opdnumber:"<<search.opdno;
		 output(search);
		 cout<<"\n Press any key to continue\n";
		 cin.get();
		 cin.get();
		 break;
	      }
	   }
	      if(!flag)
	      {
		     cout<<" No entry exists\n";
		     cout<<" Press any key to continue\n";
		     cin.get();
		     cin.get();
	      }

	      break;
    default : clrscr();
	      cout<<" Wrong choice selected.";
	      cout<<"\n The program will exit.";
	      exit(0);
  }
  fin.close();
}

// main function begins
void main()
{
 textcolor(3);     //for coloured text

 start:
 clrscr();
 Patient p1;    //object of class patient
 int choice;
 char cho;
 ofstream fout;    // object to link the program with pdatbase
 fout.open("pdata.cpp",ios::binary|ios::nocreate|ios::app);
 if(!fout)
 {
  ofstream fout1;
  fout1.open("pdata.cpp",ios::binary);
  Patient write;
  write.opdno=0;
  fout1.write((char*)&write,sizeof(Patient));
  fout1.close();
 }
 fout.close();
 cout<<"\t\t\ Red Cross Hospital";
 cout<<"\n ********************************************";
 cout<<"\n\n *  1. View patient details                 *";
 cout<<"\n\n *  2. Add new patient detail               *";
 cout<<"\n\n *  3. Delete a patient details             *";
 cout<<"\n\n *  4. Search a patient details             *";
 cout<<"\n\n *  5. Exit                                 *";
 cout<<"\n ********************************************";
 cout<<"\n\n Enter your choice:";
 cin>>choice;

 switch(choice)
 {
  case 1:{
	  p1.display();
	  break;
	 }
  case 2:{
	  p1.write();
	  break;
	 }
  case 3:{
	  p1.del();
	  break;
	 }
  case 4:{
	  p1.search();
	  break;
	 }
  case 5:{
	  clrscr();

	  cout<<" Press any key to exit.....\n"<<" ";
	  getch();
	  exit(0);
	  break;
	 }
  default:{
	  clrscr();
	  cout<<" Invalid choice."<<" ";
	  cout<<" Press any key to continue...."<<" ";
	  getch();
	  clrscr();
	  }

 }
goto start;
}
