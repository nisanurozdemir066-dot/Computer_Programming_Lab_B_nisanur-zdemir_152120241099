#include <iostream>

using namespace std;

struct node {
  string songtitle;
  node* next();
  int lists[];
};

 int display(){
int i;
string songtitle = "1.a","2.b ","3.c"
char lastsong = NULL;
for (i=0;i<lastsong;i++){
        cout << songtitle[i];

}

 };

 int  adding(){
  int song;
  head = string songtitle[0];
  cout << "Add the song.";
  cin << song;
  if (head == NULL)
  cout << song;

 };


 int searching (){
 char song;
     cout << "enter the song name";
     cin << song ;
     if (song ==   ){
        cout << "The song was found."
        else
            cout << "The song wasn't found."
     }



 }
int main()
{
   cout <<"----MAIN MENU----";
 int options ;
 cout << "Choose the option:";
 cin << options;
 switch(options){
  case 1 : cout << "ADD";
  adding();

  case 2 : cout << "SEARCH";
  searching();

  case 3 : cout << "LIST";
  display();

  case 4 : cout << "EXIT";
  default :
    cout << "INVALID OPTION";


    return 0;
}
