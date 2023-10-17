#include<iostream>
#include <conio.h> 
#include <stdlib.h> 
#include <string.h> 
#include<vector>
#include<Windows.h>
using namespace std;

class Food{
public:
    string FoodName;
    int price;
public:
    Food(string n,int x)
    {
        FoodName = n;
        price = x;
    }
};

// Creating Double Link List Of T
template <typename T>
class Node{
public:
    T data;
    Node* prev ;
    Node* next ;
public:
    Node(T* obj)
    {
        data = obj;
        prev = nullptr;
        next = nullptr;
    }
};
// T DOUBLE LINKED LIST
template <typename T = Food>
class FoodDoubleLinkedList{
public:
    Node<T>* head;
    Node<T>* tail;
    int count = 0;
public:
    FoodDoubleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    // insert at begin
    void insertAtbegin(T* obj){
        Node<T>* nextNode = new Node<T>(obj); 
        if(head == nullptr)
        {
            nextNode->next = head;
            head->prev = nextNode;
            head = nextNode;
            tail = nextNode;
        }
        else
        {
            nextNode->next = head;
            head->prev = nextNode;
            head = nextNode;
        }
        count++;
    }
    // insert at end
    void insertAtEnd(T* obj)
    {
        Node<T>* nextNode = new Node<T>(obj); 
        if(head == nullptr)
        {
            nextNode->next = head;
            head->prev = nextNode;
            head = nextNode;
            tail = nextNode;
        }
        else
        {
            tail->next = nextNode;
            nextNode->prev = tail;
            tail = nextNode;
        }
        count++;
    }
    // Display Foods
    void displayFood(Node<T>* tem)
    {
        Node<T>* temp = tem;
        if(temp == nullptr)
        {
            return ;
        }
        cout<< "T NAME IS " + temp->data.FoodName + "AND ITS PRIZE IS :" << temp->data.price <<endl;
        temp = temp->next;
        return displayFood(temp);
    }
    // Search T
    void searchFood(Node<T>* tem,string name)
    {
        Node<T>* temp = tem;
        if(temp == nullptr)
        {
            return;
        }
        if(temp->data.FoodName == name)
        {
            cout<< "T NAME IS " + temp->data.FoodName + "AND ITS PRIZE IS :" << temp->data.price <<endl;
            return;
        }
        temp = temp->next;
        return searchFood(temp,name);
    }
    // Delete T
    void deleteFood(Node<T>* tem,string name)
    {
        Node<T>* temp = tem;
        if(temp == nullptr)
        {
            cout<<"NOT FOUND"<<endl;
            return;
        }
        if(temp->data.FoodName == name)
        {
            Node<T>*t = temp->prev;
            t->next = temp->next;
            temp->next->prev = temp->prev;
            cout<<"DELETED"<<endl;
            return;
        }
        temp = temp->next;
        return deleteFood(temp,name);
    }
    // Update Marks
    void updatePrice(Node<T>* tem,string name,int price)
    {
        Node<T>* temp = tem;
        if(temp == nullptr)
        {
            cout<<"NOT FOUND"<<endl;
            return;
        }
        if(temp->data.FoodName == name)
        {
            temp->data.price = price;
            cout<<"UPDATED"<<endl;
            return;
        }
        temp = temp->next;
        return updatePrice(temp,name,price);
    }
    // 
};

// DESIGN CLASS 
    void pageHeader()
    {
        system("cls");
        cout << "*********************************************************************************************" << endl;
        cout << "#                                     T MANAGEMENT SYTEM                               #" << endl;
        cout << "*********************************************************************************************" << endl;
    }
    // Link List printer
    int listPrinter(int n,vector<string> menu)
    {
        if (n == 7)
        {
            return 0;
        }
        cout << (n + 1) <<"   " << menu[n] <<endl;
        return listPrinter(n + 1, menu);
    }
    // CREATE T T
    Food createFood()
    {   
        string name;
        int x;
        cout<<"ENTER T NAME: ";
        cin >> name;
        cout<<"ENTER T Price: ";
        cin >> x;
        Food* F = new Food(name,x);
        return *F;
     
    }
    // take Price
    int takePrice()
    {   
        int x;
        cout<<"ENTER T Price: ";
        cin >> x;
        return x;
    }
    // take marks
    string takeName()
    {
        string y;
        cout<<"ENTER T Name: ";
        cin >> y;
        return y;
    }

// Student Management System
void FoodManagementSystem(){
    FoodDoubleLinkedList<Food> link;
    vector<string> menu = { "ADD T",
    "UPDATE T","DELETE T",
    "ALL STUDENT FROM BEGIN","PRICE CALCULATER",
    "SEARCH T PRICE","EXIT"};
	int opt;
    while(true)
    {
        pageHeader();
        listPrinter(0,menu);
        cout<<"CHOSE ONE: ";
        cin>> opt;
        if(opt == 1)
        {
            Food f = createFood();
            link.insertAtbegin(f);
        }
        else if(opt == 2)
        {
            link.updatePrice(link.head,takeName(),takePrice());
        }
        else if(opt == 3)
        {
            link.deleteFood(link.head,takeName());
        }
        else if(opt == 4)
        {
            link.displayFood(link.head);
        }
        else if(opt == 5)
        {
            
        }
        else if(opt == 6)
        {
            link.searchFood(link.head,takeName());
        }
        else if(opt == 7)
        {
            break;
        }

        Sleep(1000);

    }
}
// Main
int main()
{
    FoodManagementSystem();
}