




#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<cstring>
#include<process.h>
#include <unistd.h>
#include<windows.h>
#include "assistant.h"

using namespace std;

//------------------global variables----------------
string input;

int pos ,l_pos,cnt=0;
string m_word ,s_word;
int s_count=0;
assistant x; //  main  object

//---------------------all functions-------------------------

void check();   //compare the user input with defined commands
void line();      // create new line
void repeat();     //ask user input again.
void shutdown_timer(int);
//void display(int);
void player(string);  //search the song from file(songs.txt) then play the song.
void help();          //show commands
void hacking();
void block(string);  //block the websites
void openf(string);   // open the file directory
void lists(string);   //show song list
void convert(string&);   //convert 'space( )' to 'underscore'( _ ) and lowercase string
void search(string,string extra="");
void update_song(string);   //copy song name from different files(list.txt) file into one file(songs.txt)


int main()
{
    x.clock();
    x.greeting();
    repeat();

    return 0;
}

//-----------------------------Repeat function-------------------------//
void repeat()
{
  system("color a");
  system("cls");
  x.clock();
  cout<<" \n\n\nType Here  ---> ";
  cin.clear();
getline(cin,input);   // get command from user

pos = input.find(" ");
m_word = input.substr(0,pos); //main command word
l_pos = input.find('\0');
s_word = input.substr(pos+1,l_pos); //rest word


//-----------check conditions--------------//
check();
}

//----------------------------check function---------------------------//
void check()
{
   string line;
    string group_members[5] = { "Bongiswa Ngcongo", "Khanyisile Momoti", "Ntobeko Hlongwa", "Manqoba Mlangeni", "Sphamandla Sangweni" };

    /***** To covert the keyboard inputy to lower case *****/
    std::cout << "Enter line here" << std::endl;
    getline(cin, line);

    for (int i = 0; i < line.length(); i++) {
        if (line[i] >= 'A' && line[i] <= 'Z') {
            line[i] = line[i] + 32;
        }
    }

    if (line == "hi jarvis" || line == "hello jarvis" || line == "hello" || line == "hi") {
       // cout << "Hello Musa, How are you today";
	    x.typing("Hello Musa, How are you today");

    }
    else if (line == "how are you" || line == "how are you today") {
        //cout << "I am doing good Sir, How about you? ";
	    x.typing("I am doing good Sir, How about you?");

    }
    else if (line == "thanks" || line == "thank you") {
        //cout << "The pleasure is mine";
	    x.typing("The pleasure is mine");
	    

    }
    else if (line == "what is your name" || line == "who are you") {

       // cout << "My name is Jarvis, I am virtual personal assistant" << endl;
	    x.typing("My name is Jarvis, I am virtual personal assistant");

    }
    else if (line == "who made you" || line == "who built you") {

        cout << "" << endl;
        for (const string& member : group_members) {
            cout << member << " " << endl;
            Sleep(500);
            cout << "" << endl;
        }
        //cout << "Collectively built me to be of your service " << endl;
	    x.typing("Collectively built me to be of your service");

    }
    /************** Still need further refining*************/
    else if (line == "play song" || line == "song" ) { 
       search(line, "song");    // call search (srch) function
    }
    else if (line == "help" ) {
        help();                // call help function
    }
    else if (line == "cmd") {
        system(s_word.c_str());    // call system function
    }
    else if (line == "youtube" || line == "videos" || line == "yt") {
      search(line, "youtube")    // call search (srch) function
    }
    /************** Still need further refining*************/
    else if (line == "open chrome") {
        openf(line)    // call openf function
        system(start chrome);
    }
    else if (line == "exit" || line == "quit") {
        x.speack("Good bye ");
        exit(1)

    }
    else if (line == "shutdown" || line == "restart") {
        
        x.typing("Your PC will");
        x.typing(line);
        if (line == "shutdown") 
            system("shutdown /s");
        else 
            system("shutdown /r");
            exit(1)
    }
    else if (line == "find my ip address" || line == "my ip address" || line == "ip address") {
       
        x.typing("Finding your IP address");
        Sleep(700)
        system("ipconfig");
        system("pause");
    }
    else {
        x.speack("Sorry Sir, that is an unknown command...");
        cnt++
        
        x.speack()
    }


    Sleep(700);
    repeat();
    system("pause>0");
    return 0;

}

//------------------------------player function------------------------//
void player(string item)
{
  ifstream file;
  string song_name;
  song_name=item;
  convert(item);
  char song[30],singer[30];
  char path[90]="start My_beat\\";
  file.open("data\\songs.txt",ios::app);
  while(file>>song>>singer)
  {
      if(song==item)
     {
        x.typing("Playing the song ");
        Sleep(150);
        x.typing(song_name);
        strcat(path,singer);
        strcat(path,"\\");
        strcat(path,song);
        strcat(path,".mp3");
        system(path);
        break;
      }
    }
    //--------------if song not found------------------
    if (song!=item)
        {
          x.typing(song_name);
          x.typing(" not found.");
          if (s_count%3==0)
              {
                Sleep(200);
                system("cls");
                x.speak("But you can download the song by using the command");
                Sleep(1300);
                line();
                x.typing("song ");
                x.typing(song_name);
              }
          s_count++;
          }

  file.close();
}

//------------------------------convert string-------------------------//
void convert(string &c)
{

    for (int i=0;c[i]!='\0';i++)
        {
            if(c[i]==' ')
               c[i]='_';
            c[i]=tolower(c[i]);
        }
}

//------------------------------update the song list-------------------//
void update_song(string name)
 {
    fstream a,b;
    char word[20], old[20];
    system("cls");
    a.open("My_beat\\"+name+"\\list.txt");
    b.open("data\\temp.txt",ios::app|ios::ate);
    while(a>>word)
        {
         b<<word<<" "<<name<<"\n";
         }
    b.close();
    a.close();
}

//------------------------timer function--------------

// function to display the timer
void displayClock(int seconds)
{
	int h,m;
	h=m=0;
	// system call to clear the screen
	system("cls");
	cout<<"\n\n";
	cout << setfill(' ') << setw(75) << "	        TIMER	      	\n";
	cout << setfill(' ') << setw(75) << " --------------------------\n";
	cout << setfill(' ') << setw(29);
	cout << "| " << setfill('0') << setw(2) << h << " hrs | ";
	cout << setfill('0') << setw(2) << m << " min | ";
	cout << setfill('0') << setw(2) << seconds << " sec |" << endl;
	cout << setfill(' ') << setw(75) << " --------------------------\n";
}

void shutdown_timer(int t)
{
	while (t)
     {
		 displayClock(t);
		 Sleep(900);
		 t--;
     }
}

//----------------online searching and downloading songs----------------

void search(string query,string extra)                                //Searchn function with two arguments which will take a query from the user
{
          for(int i=0;query[i]!=NULL;i++)
              {
                  if(query[i]==' ')
                    query[i]='+';
              }

            Sleep(300);
            system("cls");
            line();
            x.typing("verifying internet connection....");
            if (s_count%5==0)
            {
                line();
                Sleep(90);
                cout<<"Colleting info..\n";
                Sleep(50);
                cout<<"securing the data..\n";
                Sleep(30);
                cout<<"clear the cookies..\n";
                Sleep(100);
                system("ipconfig");
                line();
                x.typing("All protocols are secured...");
            }

            Sleep(250);
            x.speak("Connecting to your browser.");
            string url;
           // opening youtube
            if(extra == "youtube")
            {
                url= "start https://www.youtube.com/results?search_query=";
                url+=query;
                system(string(url).c_str());
            }
            else if(extra == "song")
            {
                // for international songs
                url= "start https://en.muzmo.org/search?q=";
                url+=query;
                system(string(url).c_str());
                Sleep(50);

                url= "start https://m.soundcloud.com/search?q=";
                url+=query;
                system(string(url).c_str());

            }
            else if(extra == "pdf")
            {
                url= "start https://www.google.com/search?q=filetype%3Apdf+";
                url+=query;
                system(string(url).c_str());
            }
            else if(extra == "movie")
            {

                url= "start https://www.google.com/search?q=";
                url+=query;
                url+="+-inurl%3A(htm%7Chtml%7Cphp%7Cpls%7Ctxt)+intitle%3Aindex.of+%22last+modified%22(mp4%7Cmkv%7Cwma%7Caac%7Cavi)";
                system(string(url).c_str());
            }
            else
            {
                url="start https://www.google.com/search?q=";
                url+=query;
                system(string(url).c_str());
            }

            s_count++;
}
//-----------------newline function----------------
void line()
{
    cout<<"\n";
}

//----------------install files---------------------
void install(string fold)
{
    fstream file;
    string foldname,filename;
    foldname="md My_beat\\";

    foldname+=fold;
    system(string(foldname).c_str());

    filename="My_beat\\";
    filename+=fold;
    filename+="\\list.txt";
    file.open(filename,ios::app);
    file.close();
}

//---------------list the file texts------------------
void lists(string link)
{
    fstream file;
    int cnt=0;
    char word[50],old[50];
    file.open(link);
    while(file>>word>>old)
    {
        cnt++;
        cout<<word<<"\n";
    }
    cout<<"\n\t\tTotal songs available :"<<cnt<<endl;
    string p,s="Only ";
    p=cnt;
    s+=p;
    s+="songs are available";
    if(cnt!=0)
      {
       x.speak(s);
      }
    file.close();
    system("pause");
}

//----------------------hacking zone------------------
void hacking()
{
system("cls");
system("color f");
x.speak("You are Welcome in the Hacking Lab");
cout << setfill(' ') << setw(50) <<"      ________       \n";
Sleep(100);
cout << setfill(' ') << setw(50) <<"     |    #    |      \n";
Sleep(100);
cout << setfill(' ') << setw(50) <<"     |  #   # |      \n";
Sleep(100);
cout << setfill(' ') << setw(50) <<"     |  #   # |      \n";
Sleep(100);
cout << setfill(' ') << setw(50) <<"     |   # #  |      \n";
Sleep(100);
cout << setfill(' ') << setw(50) <<"     |    #   |      \n";
Sleep(100);
cout << setfill(' ') << setw(50) <<"     |________|      \n";
line();
Sleep(1000);
system("color c");
cout << setfill(' ') << setw(50) <<" Vinay Hacking Lab  \n";
Sleep(1000);
line();
x.typing("Still in development...");
}

void block(string website)
{
    fstream file;
    file.open("C:\\WINDOWS\\system32\\drivers\\etc\\hosts",ios::app);
    file<<"\n127.0.0.2 www."<<website;
    x.typing("Blocking the website..");
    file.close();
}

void openf(string location)
{
string path="start ",item=location;
convert(item);
path += item;
x.typing("Open....");
x.typing(location);
system(string(path).c_str());
}

//----------------------help file---------------------
void help()
{
cnt=0;
x.speak("you can use only these cammands");
system("cls");
cout<<"\n\n";
system("color f");
line();
cout << setfill(' ') << setw(75) <<"----------------------------\n";
cout << setfill(' ') << setw(75) <<"          Commands          \n";
cout << setfill(' ') << setw(75) <<"--------------------------\n\n";
cout << setfill(' ') << setw(75) <<"    1.search (any question)  \n";
cout << setfill(' ') << setw(75) <<"    2.open (google,mozilla)  \n";
cout << setfill(' ') << setw(75) <<"    3.block (website name)   \n";
cout << setfill(' ') << setw(75) <<"    4.song (song name)       \n";
cout << setfill(' ') << setw(75) <<"    5.update                 \n";
cout << setfill(' ') << setw(75) <<"    6.watch (videoname)      \n";
cout << setfill(' ') << setw(75) <<"    7.pdf (pdfname)          \n";
cout << setfill(' ') << setw(75) <<"    8.movie (moviename)      \n";
cout << setfill(' ') << setw(85) <<"    9.what/how/where/who/why (question)\n";
cout << setfill(' ') << setw(75) <<"   10.cmd (cmd commands)     \n";
cout << setfill(' ') << setw(75) <<"   11.find my ip             \n";
cout << setfill(' ') << setw(75) <<"   12.play (song name)       \n";
cout << setfill(' ') << setw(75) <<"   13.list songs             \n";
cout << setfill(' ') << setw(75) <<"   10.exit/quit/q            \n";
cout << setfill(' ') << setw(75) <<"   11.shutdown/restart       \n";
cout << setfill(' ') << setw(75) <<"   12.install                \n";
system("pause");
}
