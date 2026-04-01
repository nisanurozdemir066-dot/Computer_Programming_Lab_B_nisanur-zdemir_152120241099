#include <iostream>

using namespace std;



   struct page{
   string ur1;
   string title;
   int accesTime[3] = {"hour","minute","next"};
   page *next ;
   page *prev;
}

page *visit(page* head,string ur1,string title,page &*current){
  page *newpage= new page;
  if (head == NULL)
    head = newpage;
    current = head;
    else {
        current->next=newpage;
        newPage->prev = current;
        current = newPage;
    };
    return current;

void bback(page &*current){
 if (current&& current->prev )
 current= current-> prev;
 };
 void fforward (page &* current){
 if (current && current->next)
 current =current ->next;
  };
  void ddelete(Page*& head, Page*& current) {
    if (!current) return;
    Page* temp = current;
    if (current->prev)
        current->prev= current->next;
    if (current->next)
    current->next->prev = current->prev;
    if (current->next)
    current = current->next;
    else current = current->prev;
    if (temp == head) head = current;
    delete temp;};

void display(page &*head,page &*current,){
    if ( head == NULL ){
        for (int i = 0; i < 3; i++) {
            cout << temp->accessTime[i];

        }
      ;
    }
           }
}
void memory(page &* head ){
    string choice ;
    int choose;
    cout << "choose a option" << choose ;
    choose = choice ;
    if (choice == "Exit"){
    while(head)
        page *temp = head;
        head=head->next;
        delete temp;

    };
 int main () {


  page *head=NULL;
  page *current=NULL;
  string choose;

   while (true) {
        cout << "CHOOSE (VISIT/BACK/FORWARD/DELETE/DISPLAY/EXIT):"<< choose;


        if (choose == "VISIT") {
            string url, title;
            int hour,minute,second;
            cin.ignore();
            cout << "URL: ";
            cin>> url;
            cout << "Title: ";
            cin >> title;
            cout << "Time (Hour Minute Second): ";
            cin >> hour >> minute >> second;
            visit(head, current, url, title);
        } else if (choose == "BACK")
            bback(current);
        else if (choose == "FORWARD")
            fforward(current);
        else if (choose == "DELETE")
        ddelete(head, current);
        else if (choose == "DISPLAY")
        display(head, current);
        else if (choose == "EXIT") {
            memory(head);
            break;
        }
    return 0;
   };
