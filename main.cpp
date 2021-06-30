#include<cstdlib>

#include <cstring>
 #include<fstream>
 #include <iostream>

using namespace std;

void sign_in();
void sign_up();
void read_dlog();
void write_dlog();
int main_func();
void mid_func();
void start_page();





void sign_up()
{	system("clear");
    int pass;
    string uid;
cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SignUp Here <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n ";
    re:
    cout << "\n  Choose your UID : ";
    cin >>uid;
    uid=uid+".dat";

    ofstream out(uid.c_str(), ios::binary );

    if(out)
    {
        cout << " Choose your passcode : ";
        cin>>pass;
        out << pass;
    }else{
        cout << " UID already Exist choose, choose another !";
        goto re;

    }
}

void sign_in()
{	system("clear");
    string uid;
    int pass;
	cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SignIn Here <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n ";
    cout << " \n Enter your UID : ";
    cin>>uid;

    uid=uid+".dat";
    ifstream in(uid.c_str(), ios:: binary);

   if(in)
   {
        in >> pass;
        int temp_pass;

        cout << " Enter your Passcode : ";
        cin>>temp_pass;

        if(temp_pass==pass)
            cout<< " Sign In successful !! \n  ";
        else{
            cout << " Error : Wrong passcode \n exiting to main...";
            main_func();
        }
   }else{

        cout << "\n User doesn't exist !! ...\n Please Sign Up to continue ";
        cin.get();
        main_func();
   }
}


void write_dlog(){


    string temp_uid;
    cout << "\n Enter your UID again : ";
    cin.ignore(256, '\n');
    getline(cin, temp_uid);
    char date[11],hrs[6];
    string dlog_data;
     temp_uid= temp_uid +".txt";
	ofstream out(temp_uid.c_str(), ios::app);
    if(out){
		cout << " Enter Date [dd/mm/yyyy] : ";
		cin>>date;

		cout << " Enter Time [00:00] : " ;
		cin>>hrs;

		cout << "\n Whatsup for today :";
		cin.ignore();
		getline(cin, dlog_data);
		    
		out << hrs << endl;
		out << date<< endl;
		out << dlog_data<< endl; ;
}else{
	cout << " \n your dlog doesn't exist !!";
}

out.close();

}

void read_dlog()
{
 

 string content;
 string uid;
 cout << "\n Enter the UID of dlog you want to read : ";
 cin >> uid;
mid_func();

 uid=uid+".txt";
 ifstream in(uid.c_str());

 if(in)
{
	int i=0;
	cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> D'LOG <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n ";
	cout << "\n ===========================================================================\n \n";
 while(getline(in , content , '\n') )
 {
	 i++;
    cout << content<< endl;
    if((i%3)==0){
		cout << "\n ===========================================================================\n ";
	}
 
 }
 cout << "\n We hope you Enjoyed ! \n \n ";
in.close();

}else {

cout << "\n Sorry the User does n't exist ! \n";

}




 }
void mid_func()
{
    cout << "\n Press Enter to continue ! ";
    cin.get();
    system("clear");
}
void start_page()
{

  cout <<"\n\n\n\n\n\n\n\n\tWelcome to,\n\n\n";

 cout<<"\t    === ==     ( )   ==           == ==          == ===      \n";
 cout<<"\t     ==   ==    /    ==         ==      ==     ==           \n";
 cout<<"\t     ==    ==  /     ==        ==        ==   ==            \n";
 cout<<"\t     ==    ==        ==        ==        ==   ==    == ==   \n";
 cout<<"\t     ==   ==         ==         ==      ==     ==      ==   \n";
 cout<<"\t    === ==          === == ==     ==  ==         ==  ==     \n\n";

 cout<<"\t                               YOUR DAY ENDS HERE.......:):)\n";
 cout<<"\t   _________________________________________________________\n";
 cout<<"\t   ----|    #ANKIT.G        #SHUBHAM        #SAMEER    |----\n";
 cout<<"\t   _________________________________________________________\n";




}



int main_func()
{
   // under-development

    re:
    int choice;
    mid_func();
    cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>>> SiGnIN OR SiGnUP <<<<<<<<<<<<<<<<<<<<<<<<<<<\n ";
    cout << " \n Choose from the following \n 1.Sign In \n 2.Sign Up\n--> ";
    cin>>choice;
     switch(choice)
     {
        case 1 : sign_in();
                    break;
        case 2 : sign_up();
                    break;
        default :  { cout << "\n Please Enter a valid choice...."; char v;

                    cout << "\n Enter (y) to continue :";
                    cin >> v;
                  if (v=='y')
                    goto re;
                 else{exit(0);}
                    }

     }

re1:

mid_func();

cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> HOME <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n ";
    cout << "\n Press \n 1. Read \n 2. Write in your Diary \n 3. Exit to main \n Enter your choice : ";
    cin>>choice;

    switch(choice)
    {
        case 1 : read_dlog();
                    break;
        case 2 : write_dlog();
                    break;
        case 3 : main_func();
                    break;
        default : cout << "\n Please Enter a valid choice... \n";
    }

cout << " Enter '(y) to re-enter choice : "; char u='y';
                    cin >> u;
                    if (u=='y')
                        goto re1;



return 0;
}





int main(){
 start_page();
 main_func();

 return 0;

}



