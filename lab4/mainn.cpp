#include <iostream>

#include <iostream>
#include <string>

using namespace std;


struct MoneyBundle {
    string serialNumber;
    string currencyType;
    int billCounts[3];
    MoneyBundle* next;
};

struct Customer {
    string customerName;
    string transactionType;
};


struct MoneyStack {
    MoneyBundle* top = nullptr;
    void push(string sn, string type, int counts[]) {
        MoneyBundle* newNode = new MoneyBundle;
        newNode->serialNumber = sn;
        newNode->currencyType = type;
        for (int i = 0; i < 3; i++) newNode->billCounts[i] = counts[i];

        newNode->next = top;
        top = newNode;
        cout << "[Kasa] Para eklendi: " << sn << endl;
    }


    void pop() {
        if (!top) return;
        MoneyBundle* temp = top;
        top = top->next;
        delete temp;
    }

    void display() {
        cout << "\n--- Kasadaki Para Desteleri (Stack) ---" << endl;
        MoneyBundle* curr = top;
        if (!curr) cout << "Kasa su an bos!" << endl;
        while (curr) {
            cout << "Seri: " << curr->serialNumber << " | Tur: " << curr->currencyType
                 << " | Adetler: 100s:" << curr->billCounts[0] << " 50s:" << curr->billCounts[1] << " 20s:" << curr->billCounts[2] << endl;
            curr = curr->next;
        }
    }
};

struct CustomerQueue {
    Customer q[5];
    int front = 0;
    int rear = -1;
    int count = 0;


    void enqueue(string name, string type) {
        if (count == 5) {
            cout << "[Sira] Hata: Sira dolu! " << name << " bekleyemez." << endl;
            return;
        }
        rear = (rear + 1) % 5;
        q[rear] = {name, type};
        count++;
        cout << "[Sira] Musteri siraya girdi: " << name << endl;
    }


    void dequeue() {
        if (count == 0) return;
        front = (front + 1) % 5;
        count--;
    }

    void display() {
        cout << "\n--- Bekleyen Musteriler (Queue) ---" << endl;
        if (count == 0) cout << "Sira su an bos!" << endl;
        for (int i = 0; i < count; i++) {
            int idx = (front + i) % 5;
            cout << i + 1 << ". " << q[idx].customerName << " (" << q[idx].transactionType << ")" << endl;
        }
    }
};


int main() {
    MoneyStack safe;
    CustomerQueue bankQueue;


    int b1[] = {10, 20, 30};
    safe.push("SN001", "TL", b1);

    int b2[] = {5, 5, 5};
    safe.push("SN002", "USD", b2);


    bankQueue.enqueue("Ahmet", "Withdraw");
    bankQueue.enqueue("Ayse", "Deposit");
    bankQueue.enqueue("Mehmet", "Withdraw");


    safe.display();
    bankQueue.display();


    cout << "\n--- Islemler Basliyor (Pop & Dequeue) ---" << endl;

    if (safe.top && bankQueue.count > 0) {
        cout << "ISLEM: " << bankQueue.q[bankQueue.front].customerName
             << " hizmet aliyor. Kullanilan deste: " << safe.top->serialNumber << endl;

        safe.pop();
        bankQueue.dequeue();
    }


    safe.display();
    bankQueue.display();

    return 0;
}
