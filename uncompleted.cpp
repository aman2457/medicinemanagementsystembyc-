#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <time.h>
using namespace std;

class medicine{
	char med[18];
	char cname[18];
	char exp[15];
	char mfg[15];
	float price;
	int quantity;
	public:
		medicine()
	{
	strcpy(med,"No Medicine Till Now");
	strcpy(cname,"No Data");
	strcpy(mfg,"no data");
	strcpy(exp,"no data");
	price=0;
	quantity=0;
		
	}
	void addmed()
	   {
	   	char choice;
	   	do
		{
		fflush(stdin);
		cout<<"Press Enter to continue........";
		cin.ignore();
		cout<<"\nEnter Medicine Name :    ";
		cin.getline(med,15);
		cout<<"Enter Company :    ";
		cin.getline(cname,15);
		cout<<"Enter Medicine Price :    ";
		cin>>price;
		cout<<"Enter Medicine Quantity :    ";
		cin>>quantity;
		cout<<"Enter Manufacture Date (dd/mm/yyyy) :    ";
		fflush(stdin);
		cin.getline(mfg,11);
		cout<<"Enter Expiry Date (dd/mm/yyyy) :    ";
		fflush(stdin);
		cin.getline(exp,11);
		datastoring();
		cout<<"Do You Want To Store More Data:--\n";
		cout<<"If Yes type Y or else type N: \n";
		cin>>choice;
		}
	    while(choice == 'y'||choice== 'Y');	
	   }
	void showmed()
	
	{
		
		cout<<"|"<<setw(14)<<med<<"    |"<<setw(14)<<cname<<"   |"<<setw(14)<<price<<"  |"<<setw(18)<<quantity<<"     |"<<setw(26)<<mfg<<"\t|"<<setw(26)<<exp<<"     |"<<endl;
		cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	}
	
	void upmed()
	{
	cout<<"Press Enter to continue:";
		cin.ignore();
		cout<<"\n\nEnter Medicine Name :    ";
		cin.getline(med,15);
		cout<<"Enter Company :    ";
		cin.getline(cname,15);
		cout<<"Enter Medicine Price :    ";
		cin>>price;
		cout<<"Enter Medicine Quantity :    ";
		cin>>quantity;
		cout<<"Enter Manufacture Date (ddmmyyyy) :    ";
		fflush(stdin);
		cin.getline(mfg,11);
		cout<<"Enter Expiry Date (ddmmyyyy) :    ";
		fflush(stdin);
		cin.getline(exp,11);	
	}
	
	int datastoring();
	void searchmed();	
	void allmeds();	
	void deletemed(char *);
	void updatemed(char *);
	
};

int medicine::datastoring()
{
	if(price==0 && quantity==0)
	{
		cout<<"no data";
		return(0);
	}
	else
	{
	fstream fw;
	fw.open("MedicineData1.dat",ios::app|ios::binary);
	fw.write((char*)this,sizeof(* this));
	fw.close();	
	return(1);
    }
}
void medicine::allmeds()
{
	 int c;
	fstream f;
	f.open("MedicineData1.dat",ios::in|ios::binary);
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|"<<setw(14)<<"Name"<<"    |"<<setw(14)<<"Company"<<"   |"<<setw(14)<<"Rate"<<"  |"<<setw(20)<<"Quantity"<<"   |"<<setw(28)<<"Manufacture(ddmmyyyy)"<<"\t|"<<setw(28)<<"Expiry(ddmmyyyy)"<<"   |"<<"\n";
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	if(!f)
	cout<<"File Not Found";
	else
	{
	f.read((char*)this,sizeof(*this));
	while(!f.eof())
	{
	showmed();	
	
	f.read((char*)this,sizeof(*this));
	c++;
	}
	f.close();
	}
	cout<<"\n\n\nTotal "<<c<<" Records Found in Database.....\n";
}

void medicine::searchmed()
{
	int n;
	cout<<"\t\t\t\t\t\t\t|| Choose The Option \t\t\t\t||";
    		cout<<"\n\t\t\t\t\t\t\t||\t1.Search By Name \t\t\t||";
    		cout<<"\n\t\t\t\t\t\t\t||\t2.Search By Company Name\t\t||";
    		cout<<"\n\t\t\t\t\t\t\t||\t3.Search Greater Than The Price\t\t||";
    		cout<<"\n\t\t\t\t\t\t\t||\t4.Search Less Than The Price\t\t||";
    		cout<<"\n\t\t\t\t\t\t\t||\t5.Search Quantity Greater Than\t\t||";
    		cout<<"\n\t\t\t\t\t\t\t||\t6.Search Quantity Less Than\t\t||";
    		cout<<"\n\t\t\t\t\t\t\t--------------------------------------------------\n";
    		cout<<"\t\t\t\t\t\t\t||\tPlease Enter Your Selection(1-6) : ";
			cin>>n;
	if(n==1)
	{
	int flag;
	char key[15];
	cout<<"\t\t\t\t\t\t\t||\tEnter The Title Of The Medicine :-";
		     	fflush(stdin);
                cin.getline(key,15);
	fstream fs;
	fs.open("MedicineData1.dat",ios::in|ios::binary);
	
	if(!fs)
	cout<<"File Not Found:";
	else
	{
	fs.read((char*)this,sizeof(*this));
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|"<<setw(14)<<"Name"<<"    |"<<setw(14)<<"Company"<<"   |"<<setw(14)<<"Rate"<<"  |"<<setw(20)<<"Quantity"<<"   |"<<setw(28)<<"Manufacture(ddmmyyyy)"<<"\t|"<<setw(28)<<"Expiry(ddmmyyyy)"<<"   |"<<"\n";
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	while(!fs.eof())
	{
		
	   if(!strnicmp(key,med,3))
	   {
	   	
	     showmed();
	     flag++;
	    }
	fs.read((char*)this,sizeof(*this));
    }
    cout<<"\n\n\nTotal "<<flag<<" Medicine similar to the the specified name(upto 3alphabets)\n";
    if(flag==0)
	fs.close();	
	}
    }
    if(n==2)
	{
	int flag=0;
	char key[15];
	cout<<"\t\t\t\t\t\t\t||\tEnter The Company Name :-";
		     	fflush(stdin);
                cin.getline(key,15);
	fstream fs;
	fs.open("MedicineData1.dat",ios::in|ios::binary);
	
	if(!fs)
	cout<<"File Not Found:";
	else
	{
	fs.read((char*)this,sizeof(*this));
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|"<<setw(14)<<"Name"<<"    |"<<setw(14)<<"Company"<<"   |"<<setw(14)<<"Rate"<<"  |"<<setw(20)<<"Quantity"<<"   |"<<setw(28)<<"Manufacture(ddmmyyyy)"<<"\t|"<<setw(28)<<"Expiry(ddmmyyyy)"<<"   |"<<"\n";
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	while(!fs.eof())
	{
	   if(!strnicmp(key,cname,3))
	   {
	   	
	     showmed();
	     flag++;
	    }
	fs.read((char*)this,sizeof(*this));
    }
    cout<<"\n\n\nTotal "<<flag<<" Medicine similar to the the specified company name(upto 3alphabets)\n";
    if(flag==0)
   	fs.close();	
	}
    }
	if(n==3)
	{
	int flag,key;
	cout<<"\t\t\t\t\t\t\t||\tEnter the Price: ";
	cin>>key;
	fstream fs;
	fs.open("MedicineData1.dat",ios::in|ios::binary);
	
	if(!fs)
	cout<<"File Not Found:";
	else
	{
	fs.read((char*)this,sizeof(*this));
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|"<<setw(14)<<"Name"<<"    |"<<setw(14)<<"Company"<<"   |"<<setw(14)<<"Rate"<<"  |"<<setw(20)<<"Quantity"<<"   |"<<setw(28)<<"Manufacture(ddmmyyyy)"<<"\t|"<<setw(28)<<"Expiry(ddmmyyyy)"<<"   |"<<"\n";
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	while(!fs.eof())
	{
	   if(price>key){
	   
	     showmed();
	     flag++;
	    }
	fs.read((char*)this,sizeof(*this));
    }
    cout<<"\n\n\nTotal "<<flag<<" Medicine are there greater than the specified price\n";
    if(flag==0)
    
	fs.close();	
	}
    }
    if(n==4)
    {
	int flag,key;
	cout<<"\t\t\t\t\t\t\t||\tEnter The Price: ";
	cin>>key;
	fstream fs;
	fs.open("MedicineData1.dat",ios::in|ios::binary);
	
	if(!fs)
	cout<<"File Not Found:";
	else
	{
	fs.read((char*)this,sizeof(*this));
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|"<<setw(14)<<"Name"<<"    |"<<setw(14)<<"Company"<<"   |"<<setw(14)<<"Rate"<<"  |"<<setw(20)<<"Quantity"<<"   |"<<setw(28)<<"Manufacture(ddmmyyyy)"<<"\t|"<<setw(28)<<"Expiry(ddmmyyyy)"<<"   |"<<"\n";
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	while(!fs.eof())
	{
		
	   if(price<key)
	   {
	   }
	   if(price<key){
	   
	     showmed();
	     flag++;
	    }
	fs.read((char*)this,sizeof(*this));
    }
    cout<<"\n\n\nTotal "<<flag<<" Medicine are there less than the specified price\n";
    if(flag==0)
    
	fs.close();	
	}
    }
    if(n==5)
    {
	int flag,key;
	cout<<"\t\t\t\t\t\t\t||\tEnter The Quantity: ";
	cin>>key;
	fstream fs;
	fs.open("MedicineData1.dat",ios::in|ios::binary);
	
	if(!fs)
	cout<<"File Not Found:";
	else
	{
	fs.read((char*)this,sizeof(*this));
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|"<<setw(14)<<"Name"<<"    |"<<setw(14)<<"Company"<<"   |"<<setw(14)<<"Rate"<<"  |"<<setw(20)<<"Quantity"<<"   |"<<setw(28)<<"Manufacture(ddmmyyyy)"<<"\t|"<<setw(28)<<"Expiry(ddmmyyyy)"<<"   |"<<"\n";
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	while(!fs.eof())
	{
	   if(quantity>key){
	   
	     showmed();
	     flag++;
	    }
	fs.read((char*)this,sizeof(*this));
    }
    cout<<"\n\n\nTotal "<<flag<<" Medicine are there greater than the specified quantity\n";
    if(flag==0)
    
	fs.close();	
	}
    }
    if(n==6)
    {
	int flag,key;
	cout<<"\t\t\t\t\t\t\t||\tEnter The Quantity: ";
	cin>>key;
	fstream fs;
	fs.open("MedicineData1.dat",ios::in|ios::binary);
	
	if(!fs)
	cout<<"File Not Found:";
	else
	{
	fs.read((char*)this,sizeof(*this));
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|"<<setw(14)<<"Name"<<"    |"<<setw(14)<<"Company"<<"   |"<<setw(14)<<"Rate"<<"  |"<<setw(20)<<"Quantity"<<"   |"<<setw(28)<<"Manufacture(ddmmyyyy)"<<"\t|"<<setw(28)<<"Expiry(ddmmyyyy)"<<"   |"<<"\n";
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	while(!fs.eof())
	{
	   if(quantity<key){
	   
	     showmed();
	     flag++;
	    }
	fs.read((char*)this,sizeof(*this));
    }
    cout<<"\n\n\nTotal "<<flag<<" Medicine are there less than the specified quantity\n";
    if(flag==0)
    
	fs.close();	
	}
    }
    if(n!=1 && n!=2 && n!=3 && n!=4 && n!=5 && n!=6)
    {
    	medicine m;
				cout<<"\n\t\t\t\t\t\t\t||\tInvalid Option!!!!!!!!" ;
                cout<<"\n\t\t\t\t\t\t\t||\tPress Enter For The Menu....."<<endl;
				getch();
				cout<<"\t\t\t\t\t\t\t--------------------------------------------------\n";
				cout<<"\t\t\t\t\t\t\t--------------------------------------------------\n";
				m.searchmed();
	}
}
void medicine::deletemed(char *d)
{
	int flag =0;
	ifstream fdin;
	ofstream fdout;
	fdin.open("MedicineData1.dat",ios::binary);
	if(!fdin)
	cout<<"No File Found:";
	else
	{
		fdout.open("deletetmp.dat",ios::binary);
		fdin.read((char*)this,sizeof(*this));
		while(!fdin.eof())
		{
			if(strcmpi(d,med)!=0)
			{
			    fdout.write((char *)this,sizeof(*this));
		
		    }
		    else 
			{
			flag=1;
			cout<<"successfully deleted...";
		    }
			fdin.read((char*)this,sizeof(*this));
		}
		if(!flag)
		
        cout<<"\nNo Medicine Found As per Given Name\n";
		fdin.close();
		fdout.close();
	    remove("MedicineData1.dat");
	    rename("deletetmp.dat","MedicineData1.dat"); 
	}
	
}
void medicine::updatemed(char *t)
{
	int pos;
	int flag;
	int n;
	fstream fu;
	fu.open("MedicineData1.dat",ios::in|ios::out|ios::binary);
    fu.seekg(0);
    
    fu.read((char *)this,sizeof(*this));
    while(!fu.eof())
    {
    	if(!strcmpi(t,med))
    	{
    		
    	cout<<"\n\t\t\t\t\t\t\t--------------------------------------------------\n";
    	cout<<"\n\t\t\t\t\t\t\t--------------------------------------------------\n";
    		cout<<"\n\t\t\t\t\t\t\t||\t\t1.Name \t\t\t\t||";
    		cout<<"\n\t\t\t\t\t\t\t||\t\t2.Company Name\t\t\t||";
    		cout<<"\n\t\t\t\t\t\t\t||\t\t3.Price\t\t\t\t||";
    		cout<<"\n\t\t\t\t\t\t\t||\t\t4.Quantity\t\t\t||";
    		cout<<"\n\t\t\t\t\t\t\t||\t\t5.Manufacture\t\t\t||";
    		cout<<"\n\t\t\t\t\t\t\t||\t\t6.Expiry\t\t\t||";
    		cout<<"\n\t\t\t\t\t\t\t--------------------------------------------------\n";
    			cout<<"\t\t\t\t\t\t\t||\tEnter component you want to modify (1-6) :";
			cin>>n;
    		
    		if(n==1)
    	    {
    	    	
    	    	cout<<"\n\t\t\t\t\t\t\tEnter Medicine Name :    ";
    	    	fflush(stdin);
    	    	cin.getline(med,15);
    	    	int pos=fu.tellp();
    		fu.seekp(pos-sizeof(medicine));
    		fu.write((char*)this,sizeof(*this));
    		
    	   	}
    	   	else if(n==2)
    	    {
    	    	cout<<"\n\t\t\t\t\t\t\tEnter Company Name :    ";
                  fflush(stdin);
    	    	cin.getline(cname,15);
    	    	int pos=fu.tellp();
    		fu.seekp(pos-sizeof(medicine));
    		fu.write((char*)this,sizeof(*this));
    	   	}
    	   else if(n==3)
    	    {
    	    	cout<<"\n\t\t\t\t\t\t\tEnter Price :    ";
    	    	fflush(stdin);
    	    	cin>>price;
    	    	int pos=fu.tellp();
    		fu.seekp(pos-sizeof(medicine));
    		fu.write((char*)this,sizeof(*this));
    	   	}
    	   	else if(n==4)
    	    {
    	    	cout<<"\n\t\t\t\t\t\t\tEnter Quantity :    ";
    	    	fflush(stdin);
    	    	cin>>quantity;
    	    	int pos=fu.tellp();
    		fu.seekp(pos-sizeof(medicine));
    		fu.write((char*)this,sizeof(*this));
    	   	}
    	   	else if(n==5)
    	    {
    	    	cout<<"\n\t\t\t\t\t\t\tEnter Manufacturing Date :    ";
    	    	fflush(stdin);
    	    	cin.getline(mfg,11);
    	    	int pos=fu.tellp();
    		fu.seekp(pos-sizeof(medicine));
    		fu.write((char*)this,sizeof(*this));
    	   	}
    	   	else if(n==6)
    	    {
    	    	cout<<"\n\t\t\t\t\t\t\tEnter Expiry Date :    ";
    	    	fflush(stdin);
    	    	cin.getline(exp,11);
    	    	int pos=fu.tellp();
    		fu.seekp(pos-sizeof(medicine));
    		fu.write((char*)this,sizeof(*this));
    	   	}
    	   	else
    	   	cout<<"\nNo Medicine Found As per Given Name\n";
    	   	
		}
		fu.read((char *)this,sizeof(*this));
	}
}

void reset()
{
	fstream fre;
	fre.open("MedicineData1.dat",ios::out|ios::trunc);
	fre.close();
}
 
 int menu()
 {
    int n;
    time_t tim;
    time(&tim);
 	    cout<<"\n\t\t\t\t\t\t\t\t    Medicine Management System \n";
        cout<<"\t\t\t\t\t\t\t==================================================\n";
		cout<<"\t\t"<<"\t\t\t\t\t\t\t\t   "<<ctime(&tim);
		cout<<"\t\t\t\t\t\t\t--------------------------------------------------\n";  
	    cout<<"\t\t\t\t\t\t\t||\t      1. Add Medicine    \t\t ||\n";
		cout<<"\t\t\t\t\t\t\t||\t      2. Search Medicine               \t ||\n";
		cout<<"\t\t\t\t\t\t\t||\t      3. Modify Medicine               \t ||\n";
		cout<<"\t\t\t\t\t\t\t||\t      4. Delete Medicine                 ||\n";
		cout<<"\t\t\t\t\t\t\t||\t      5. All Medicine               \t ||\n";
		cout<<"\t\t\t\t\t\t\t||\t      6. Clear Data File              \t ||\n";
		cout<<"\t\t\t\t\t\t\t||\t      7. Exit    \t\t\t ||\n";
		
	      cout<<"\t\t\t\t\t\t\t--------------------------------------------------\n";
		  cout<<"\t\t\t\t\t\t\t||\tPlease Enter Your Selection(1-7): ";
	      cin>>n;
	      return n;
 	
 }		
	
int main()
{

	system("COLOR 3");
	int pin;
	medicine m;
	char key[20];
	while(1)
	{
		system("cls");
	switch(menu())
	{
		case 1:
		{
		m.addmed();
	    }
		
        break;
        case 2:
        	{
        	cout<<"\n\t\t\t\t\t\t\t\t    Medicine Search Portal \n";
           cout<<"\t\t\t\t\t\t\t==================================================\n\n";
		cout<<"\t\t\t\t\t\t\t--------------------------------------------------\n";
        	m.searchmed();
			cout<<"\n\n\t\t\t\t\t\t\t--------------------------------------------------\n";	
	        };
	        getch();
        	break;
        	
        case 3:
        	{
        	cout<<"\n\t\t\t\t\t\t\t\t    Medicine Update Portal \n";
           cout<<"\t\t\t\t\t\t\t==================================================\n\n";
		cout<<"\t\t\t\t\t\t\t--------------------------------------------------\n";
        	cout<<"\t\t\t\t\t\t\t||\tEnter Exact Title Of The Medicine :- ";
		fflush(stdin);
		cin.getline(key,15);
		m.updatemed(key);	
		cout<<"\n\n\t\t\t\t\t\t\t\t--------------------------------------------------\n";	
		
		      }
		      getch();
		break;
		case 4:
			{
			cout<<"\n\t\t\t\t\t\t\t\t    Medicine Delete Portal \n";
           cout<<"\t\t\t\t\t\t\t==================================================\n\n";
		cout<<"\t\t\t\t\t\t\t--------------------------------------------------\n";
        	cout<<"\t\t\t\t\t\t\t||\tEnter The Title Of The Medicine :-";	
		fflush(stdin);
		cin.getline(key,15);
		m.deletemed(key);
		cout<<"\n\n\t\t\t\t\t\t\t--------------------------------------------------\n";

	       }
	       getch();
		break;
		case 5:
			{
				cout<<"\n\t\t\t\t\t\t\t\t    All Medicine Portal \n";
           cout<<"\t\t\t\t\t\t\t==================================================\n\n";
		cout<<"\t\t\t\t\t\t\t--------------------------------------------------\n";
		        m.allmeds();	
		 cout<<"\n\n\t\t\t\t\t\t\t--------------------------------------------------\n";
       
			}
			getch();
			break;
		case 6:
			{
				cout<<"\n\t\t\t\t\t\t\t\t\t    Reset Portal \n";
           cout<<"\t\t\t\t\t\t\t==================================================\n\n";
		cout<<"\t\t\t\t\t\t\t--------------------------------------------------\n";
		cout<<"\t\t\t\t\t\t\t||Do you really want to delete all data\t\t||\n";
		cout<<"\t\t\t\t\t\t\t||If yes type the Pin below:-   \t\t||\n";
		cout<<"\t\t\t\t\t\t\t||PIN:-";
		cin>>pin;
	    if(pin==2457)
		{
			reset();
		}
		else
		cout<<"\t\t\t\t\t\t\t||\t\tWrong Password.\t\t\t||";
		getch();
	      }
	      break;
		case 7:
		    {
		    	cout<<"\t\t\t\t\t\t\t\t==================================================\n\n";
		cout<<"\t\t\t\t\t\t\t--------------------------------------------------\n";
		    	cout<<"\t\t\t\t\t\t\t||Thank You for using this C++ application.\t||";
		    	cout<<"\n\t\t\t\t\t\t\t||Please Enter Any For Closing this application.||";
		    	cout<<"\n\n\t\t\t\t\t\t\t--------------------------------------------------\n";	       
		    	getch();
		    	exit(0);
			}    
			break;
			default:
				system("CLS");
				cout<<"\nInvalid Option!!!!!!!!" ;
                cout<<"\nPress Enter For The Menu....." ;
				getch();
				system("CLS");
				menu();
				
				break;
  	}
    }
}

