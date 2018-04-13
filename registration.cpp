#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
char key[8];
fstream in("student_doc.txt",ios::in|ios::out);
fstream in1("cse_doc.txt",ios::in|ios::out);
fstream in2("ece_doc.txt",ios::in|ios::out);
fstream in3("eee_doc.txt",ios::in|ios::out);
fstream in4("mec_doc.txt",ios::in|ios::out);
fstream in5("mme_doc.txt",ios::in|ios::out);
fstream in6("civ_doc.txt",ios::in|ios::out);
fstream in7("bio_doc.txt",ios::in|ios::out);
fstream in8("che_doc.txt",ios::in|ios::out);
fstream sem1("cse_sem_doc.txt",ios::in|ios::out);
fstream sem2("ece_sem_doc.txt",ios::in|ios::out);
fstream sem3("eee_sem_doc.txt",ios::in|ios::out);
fstream sem4("mec_sem_doc.txt",ios::in|ios::out);
fstream sem5("mme_sem_doc.txt",ios::in|ios::out);
fstream sem6("civ_sem_doc.txt",ios::in|ios::out);
fstream sem7("bio_sem_doc.txt",ios::in|ios::out);
fstream sem8("che_sem_doc.txt",ios::in|ios::out);
ifstream fee("fee_status.txt",ios::in);
ifstream backlog("backlog.txt",ios::in);
fstream out("check_file.txt",ios::in|ios::out);

class registration
{
	char name[15],branch[5],rollno[8],sem[3],faculty[20],sub[20];
	char buff[20000];
	char k_roll[8],k_branch[5],k_sem[3],k_name[20];
	int pos2,pos1;
	int pos;
	public:
		void search_roll();
		void search_cse();
		void search_ece();
		void search_eee();
		void search_civ();
		void search_mme();
		void search_bio();
		void search_che();
		void search_mec();
		void search_branch();
		void search_sem();
		int fee_status();
		void backlog_stu();
		int check();
}s;

void registration::search_roll()					//search for branch in student file
{
	 in.getline(buff,20000,'$');
  	 int i=0,j=0,k=0,t=0;
  	 while(buff[i])
  	 { 
  	 	j=0;
  	 	while(buff[i]!='*')
  	 	{
  	   		k_roll[j]=buff[i];
					
				 i++; j++;
		} 
		
  		if(!strcmp(key,k_roll)) 
		  {
		    i=i+17;
		    	while(buff[i]!='*')
  	 		{
  	   			k_branch[k]=buff[i];	i++; k++;
		    }
		    t++; 
			while(buff[i]=='*')
			i++;
			pos1=i;
			break;
		
		  }
  		else
  			i=i+25;
		}
	if(t==0) 
	{
		cout<<"\n"<<"Roll no. doesn't exist";
		exit(0);
	}
	else
	{
		in.seekg(pos1,ios::beg);
		char ch[2];
		in.getline(ch,2,'*');
		int p=atoi(ch);		
		if(p>8) {  cout<<"Student completed BTECH course "; exit(0); }
		else {
		    p++;			
			int f=fee_status();
			if(f==0) {
		itoa(p,ch,10);
		in.seekg(pos1,ios::beg);
		in<<p; 
		search_branch(); } 
		else {  cout<<"Fee not paid "; exit(0); } }
	}
}

void registration::search_branch()								//verification of branch is present or not
{
	if(!strcmp("cse",k_branch))
	search_cse();
	else if(!strcmp("ece",k_branch))
	search_ece();
	else if(!strcmp("eee",k_branch))
	search_eee();
	else if(!strcmp("mec",k_branch))
	search_mec();
	else if(!strcmp("civ",k_branch))
	search_civ();
	else if(!strcmp("mme",k_branch))
	search_mme();
	else if(!strcmp("bio",k_branch))
	search_bio();
	else if(!strcmp("che",k_branch))
	search_che();
	else
	cout<<" \n Branch dosn't exist.";
}

int registration::fee_status()							//fee payment status
{
	char buffer[1000];
	fee.getline(buffer,1000,'$');
	char h[10]; int l=0,t=0,j;
	while(buffer[l]!='\0')
	{   j=0;
		while(buffer[l]!='|') 
		{  
		h[j]=buffer[l];
		 l++; 
		 j++;
		 } 
		 l++;
		if(strcmp(h,key)==0) 
		{  t=1; break; }
	}
    return t;	
}

void registration::backlog_stu()									//backlog status
{
	char buffer[100];
	while(!backlog.eof())
	{
		char roll[8];
	   backlog.getline(buffer,100,'$'); 
	   memcpy(roll,buffer,6);
	   if(!strcmp(roll,key))
	   {
	   	cout<<"\n Backlog subjects for "<<endl;
	   	cout<<buffer; break;
	   }
	}
}

void registration::search_cse()							//verifying cse document 
{
	char buff[20000];
	in1.getline(buff,20000,'$');
  	 int i=0,j=0,k=0,t=0;
  	 while(buff[i])
  	 { 
  	 	j=0;
  	 	while(buff[i]!='*')
  	 	{
  	   		k_roll[j]=buff[i];	i++; j++;
		} 
  		if(!strcmp(key,k_roll)) 
		  {
		    i=i+2;
		    	while(buff[i]!='*')
  	 		{
  	   			k_name[k]=buff[i];	i++; k++;
		    }
		    while(buff[i]=='*')
		    i++;
			k=0;
			pos2=i;
		    while(buff[i]!='*')
		    {
				k_sem[k]=buff[i];
				k++;
				i++;
			}		
			cout<<k_sem<<"....";
			 pos=atoi(k_sem);
		
			cout<<endl<<k_name<<" completed "<<pos<<" semester ";
		    t++; break;
		  }
  		else
  			i=i+20;
		}
	if(t==0) 
	{
		cout<<"\n"<<"Roll no. doesn't exist in cse ";
		exit(0);
	}
	else 
	{
		in1.seekg(pos2,ios::beg); 
		char ch[2];
		in1.getline(ch,2,'*');
		int p=atoi(ch);
		p++;
		itoa(p,ch,10);
		in1.seekg(pos2,ios::beg);
		in1<<p;
		search_sem();
	}
}
	
void registration::search_ece()								//verifying ece document
{
	char buff[20000];
	in2.getline(buff,20000,'$');
  	 int i=0,j=0,k=0,t=0;
  	 while(buff[i])
  	 { 
  	 	j=0;
  	 	while(buff[i]!='*')
  	 	{
  	   		k_roll[j]=buff[i];	i++; j++;
		} 
  		if(!strcmp(key,k_roll)) 
		  {
		    i=i+2;
		    	while(buff[i]!='*')
  	 		{
  	   			k_name[k]=buff[i];	i++; k++;
		    }
		    while(buff[i]=='*')
		    i++;
			k=0;
			pos2=i;
		    while(buff[i]!='*')
		    {
				k_sem[k]=buff[i];
				k++;
				i++;
			}		
			 pos=atoi(k_sem);
		
			cout<<endl<<k_name<<" completed "<<pos<<" semester ";
		    t++; break;
		  }
  		else
  			i=i+20;
		}
	if(t==0) 
	{
		cout<<"\n"<<"Roll no. doesn't exist in ece ";
		exit(0);
	}
	else 
	{
		in2.seekg(pos2,ios::beg); 
		char ch[2];
		in2.getline(ch,2,'*');
		int p=atoi(ch);
		p++;
		itoa(p,ch,10);
		in2.seekg(pos2,ios::beg);
		in2<<p;
		search_sem();
	}
}
	
	void registration::search_eee()									//verifying eee document
{
	char buff[20000];
	in3.getline(buff,20000,'$');
  	 int i=0,j=0,k=0,t=0;
  	 while(buff[i])
  	 { 
  	 	j=0;
  	 	while(buff[i]!='*')
  	 	{
  	   		k_roll[j]=buff[i];	i++; j++;
		} 
  		if(!strcmp(key,k_roll)) 
		  {
		    i=i+2;
		    	while(buff[i]!='*')
  	 		{
  	   			k_name[k]=buff[i];	i++; k++;
		    }
		    while(buff[i]=='*')
		    i++;
			k=0;
			pos2=i;
		    while(buff[i]!='*')
		    {
				k_sem[k]=buff[i];
				k++;
				i++;
			}		
			 pos=atoi(k_sem);
		
			cout<<endl<<k_name<<" completed "<<pos<<" semester ";
		    t++; break;
		  }
  		else
  			i=i+20;
		}
	if(t==0) 
	{
		cout<<"\n"<<"Roll no. doesn't exist in eee ";
		exit(0);
	}
	else 
	{
		in3.seekg(pos2,ios::beg); 
		char ch[2];
		in3.getline(ch,2,'*');
		int p=atoi(ch);
		p++;
		itoa(p,ch,10);
		in3.seekg(pos2,ios::beg);
		in3<<p;
		search_sem();
	}
}
	
	void registration::search_mec()									//verifying mec document
{
	char buff[20000];
	in4.getline(buff,20000,'$');
  	 int i=0,j=0,k=0,t=0;
  	 while(buff[i])
  	 { 
  	 	j=0;
  	 	while(buff[i]!='*')
  	 	{
  	   		k_roll[j]=buff[i];	i++; j++;
		} 
  		if(!strcmp(key,k_roll)) 
		  {
		    i=i+2;
		    	while(buff[i]!='*')
  	 		{
  	   			k_name[k]=buff[i];	i++; k++;
		    }
		    while(buff[i]=='*')
		    i++;
			k=0;
			pos2=i;
		    while(buff[i]!='*')
		    {
				k_sem[k]=buff[i];
				k++;
				i++;
			}		
			 pos=atoi(k_sem);
		
			cout<<endl<<k_name<<" completed "<<pos<<" semester ";
		    t++; break;
		  }
  		else
  			i=i+20;
		}
	if(t==0) 
	{
		cout<<"\n"<<"Roll no. doesn't exist in mec ";
		exit(0);
	}
	else 
	{
		in4.seekg(pos2,ios::beg); 
		char ch[2];
		in4.getline(ch,2,'*');
		int p=atoi(ch);
		p++;
		itoa(p,ch,10);
		in4.seekg(pos2,ios::beg);
		in4<<p;
		search_sem();
	}
}
	
	void registration::search_civ()								//verifying civil document
{
	char buff[20000];
	in6.getline(buff,20000,'$');
  	 int i=0,j=0,k=0,t=0;
  	 while(buff[i])
  	 { 
  	 	j=0;
  	 	while(buff[i]!='*')
  	 	{
  	   		k_roll[j]=buff[i];	i++; j++;
		} 
  		if(!strcmp(key,k_roll)) 
		  {
		    i=i+2;
		    	while(buff[i]!='*')
  	 		{
  	   			k_name[k]=buff[i];	i++; k++;
		    }
		    while(buff[i]=='*')
		    i++;
			k=0;
			pos2=i;
		    while(buff[i]!='*')
		    {
				k_sem[k]=buff[i];
				k++;
				i++;
			}		
			 pos=atoi(k_sem);
		
			cout<<endl<<k_name<<" completed "<<pos<<" semester ";
		    t++; break;
		  }
  		else
  			i=i+20;
		}
	if(t==0) 
	{
		cout<<"\n"<<"Roll no. doesn't exist in civ ";
		exit(0);
	}
	else 
	{
		in6.seekg(pos2,ios::beg); 
		char ch[2];
		in6.getline(ch,2,'*');
		int p=atoi(ch);
		p++;
		itoa(p,ch,10);
		in6.seekg(pos2,ios::beg);
		in6<<p;
		search_sem();
	}
}
	
	void registration::search_mme()									//verifying metalergical document
{
	char buff[20000];
	in5.getline(buff,20000,'$');
  	 int i=0,j=0,k=0,t=0;
  	 while(buff[i])
  	 { 
  	 	j=0;
  	 	while(buff[i]!='*')
  	 	{
  	   		k_roll[j]=buff[i];	i++; j++;
		} 
  		if(!strcmp(key,k_roll)) 
		  {
		    i=i+2;
		    	while(buff[i]!='*')
  	 		{
  	   			k_name[k]=buff[i];	i++; k++;
		    }
		    while(buff[i]=='*')
		    i++;
			k=0;
			pos2=i;
		    while(buff[i]!='*')
		    {
				k_sem[k]=buff[i];
				k++;
				i++;
			}		
			 pos=atoi(k_sem);
		
			cout<<endl<<k_name<<" completed "<<pos<<" semester ";
		    t++; break;
		  }
  		else
  			i=i+20;
		}
	if(t==0) 
	{
		cout<<"\n"<<"Roll no. doesn't exist in mme ";
		exit(0);
	}
	else 
	{
		in5.seekg(pos2,ios::beg); 
		char ch[2];
		in5.getline(ch,2,'*');
		int p=atoi(ch);
		p++;
		itoa(p,ch,10);
		in5.seekg(pos2,ios::beg);
		in5<<p;
		search_sem();
	}
}
	
	void registration::search_bio()									//verifying biotech document
{
	char buff[20000];
	in7.getline(buff,20000,'$');
  	 int i=0,j=0,k=0,t=0;
  	 while(buff[i])
  	 { 
  	 	j=0;
  	 	while(buff[i]!='*')
  	 	{
  	   		k_roll[j]=buff[i];	i++; j++;
		} 
  		if(!strcmp(key,k_roll)) 
		  {
		    i=i+2;
		    	while(buff[i]!='*')
  	 		{
  	   			k_name[k]=buff[i];	i++; k++;
		    }
		    while(buff[i]=='*')
		    i++;
			k=0;
			pos2=i;
		    while(buff[i]!='*')
		    {
				k_sem[k]=buff[i];
				k++;
				i++;
			}		
			 pos=atoi(k_sem);
		
			cout<<endl<<k_name<<" completed "<<pos<<" semester ";
		    t++; break;
		  }
  		else
  			i=i+20;
		}
	if(t==0) 
	{
		cout<<"\n"<<"Roll no. doesn't exist in bio ";
		exit(0);
	}
	else 
	{
		in7.seekg(pos2,ios::beg); 
		char ch[2];
		in7.getline(ch,2,'*');
		int p=atoi(ch);
		p++;
		itoa(p,ch,10);
		in7.seekg(pos2,ios::beg);
		in7<<p;
		search_sem();
	}
}
	
	void registration::search_che()									//verifying chemical document
{
	char buff[20000];
	in8.getline(buff,20000,'$');
  	 int i=0,j=0,k=0,t=0;
  	 while(buff[i])
  	 { 
  	 	j=0;
  	 	while(buff[i]!='*')
  	 	{
  	   		k_roll[j]=buff[i];	i++; j++;
		} 
  		if(!strcmp(key,k_roll)) 
		  {
		    i=i+2;
		    	while(buff[i]!='*')
  	 		{
  	   			k_name[k]=buff[i];	i++; k++;
		    }
		    while(buff[i]=='*')
		    i++;
			k=0;
			pos2=i;
		    while(buff[i]!='*')
		    {
				k_sem[k]=buff[i];
				k++;
				i++;
			}		
			 pos=atoi(k_sem);
		
			cout<<endl<<k_name<<" completed "<<pos<<" semester ";
		    t++; break;
		  }
  		else
 			i=i+20;
		}
	if(t==0) 
	{
		cout<<"\n"<<"Roll no. doesn't exist in che ";
		exit(0);
	}
	else 
	{
		in8.seekg(pos2,ios::beg); 
		char ch[2];
		in8.getline(ch,2,'*');
		int p=atoi(ch);
		p++;
		itoa(p,ch,10);
		in8.seekg(pos2,ios::beg);
		in8<<p;
		search_sem();
	}
}
	
void registration::search_sem()									//dispalying course subjects after registration
{
	int t=0;
	if(!strcmp("cse",k_branch))
	{
		cout<<"\n\nPRESENT COURSES\n\n";
		int l=0;
		sem1.seekg(pos*100,ios::beg);  
		while(l!=5)
	 	{
	 	 char sub[20];
		 sem1>>sub;  l++;
		 cout<<sub<<endl;
		}
	}
	else if(!strcmp("ece",k_branch))
	{
		cout<<"\n\nPRESENT COURSES\n\n";
		int l=0;
	 	sem2.seekg(pos*100,ios::beg);
	 	while(l!=5)
	 	{
	 	 char sub[20];
		 sem2>>sub; l++;
		 cout<<sub<<endl;
		}
	}
	else if(!strcmp("eee",k_branch))
	{
		cout<<"\n\nPRESENT COURSES\n\n";
		int l=0;
	 	sem3.seekg(pos*100,ios::beg); 
	 	while(l!=5)
	 	{
	 	 char sub[20];
		 sem3>>sub;  l++;
		 cout<<sub<<endl;
		}
	}
	else if(!strcmp("mec",k_branch))
	{
		cout<<"\n\nPRESENT COURSES\n\n";
		int l=0;
	 	sem4.seekg(pos*100,ios::beg); 
	 	while(l!=5)
	 	{
	 	 char sub[20];
		 sem4>>sub;  l++;
		 cout<<sub<<endl;
		}
	}
	else if(!strcmp("mme",k_branch))
	{
		cout<<"\n\nPRESENT COURSES\n\n";
		int l=0;
	 	sem5.seekg(pos*100,ios::beg);
	 	while(l!=5)
	 	{
	 	 char sub[20];
		 sem5>>sub;  l++;
		 cout<<sub<<endl;
		}
	}
	else if(!strcmp("civ",k_branch))
	{
		cout<<"\n\nPRESENT COURSES\n\n";
		int l=0;
	 	sem6.seekg(pos*100,ios::beg); 
	 	while(l!=5)
	 	{
	 	 char sub[20];
		 sem6>>sub;  l++;
		 cout<<sub<<endl;
		}
	}
	else if(!strcmp("bio",k_branch))
	{
		cout<<"\n\nPRESENT COURSES\n\n";
		int l=0;
	 	sem7.seekg(pos*100,ios::beg); 
		 while(l!=5)
	 	{
	 	 char sub[20];
		 sem7>>sub;  l++;
		 cout<<sub<<endl;
		}
	}
	else if(!strcmp("che",k_branch))
	{
		cout<<"\n\nPRESENT COURSES\n\n";
		int l=0;
	 	sem8.seekg(pos*100,ios::beg);
	 	while(l!=5)
	 	{
	 	 char sub[20];
		 sem8>>sub;  l++;
		 cout<<sub<<endl;
		}
	}
	else 
	{  cout<<"Error in registration\n"; t++; }
	if(t==0) 
	{
		if(pos==2||pos==4||pos==6||pos==8)
		backlog_stu();
	}
}
int registration::check()									//to check whether registered or not
{
	int t,i=0,j;
	char buffer[100], roll[8];
	out.getline(buffer,100,'$');
	while(buffer[i])
	{
		j=0;
		while(buffer[i]!='|')
		{
			roll[j]=buffer[i]; i++; j++;
		}
		i++;
		if(!strcmp(key,roll)) return 1;
	}
	strcat(buffer,key);
	strcat(buffer,"|");
	strcat(buffer,"$");
	out.seekg(0,ios::beg);
	out<<buffer;
	return 0;
}

int main()												//main function
{   
	
	cout<<"\n		REGISTRATION	\n";
	cout<<"\nEnter roll no  ";
	cin>>key;
	int t=s.check();
	if(t==0)
	s.search_roll();
	else
	cout<<"\nStudent already registered";
	in.close();
	in1.close(); in2.close();
	in3.close(); in4.close();
	in5.close(); in6.close();
	in7.close(); in8.close();
	sem1.close(); sem2.close();
	sem3.close(); sem4.close();
	sem5.close(); sem6.close();
	sem7.close(); sem8.close();
	fee.close(); backlog.close();
	return 0;
}
