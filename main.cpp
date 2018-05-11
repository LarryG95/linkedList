//
//  main.cpp
//  Data4
//  CS data structures DR.C Hwang
//  Created by Lawrence Miles Gomez on Oct/19/17.
//  Copyright © 2017 Lawrence Miles Gomez. All rights reserved.
//

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class studentRecord {     // class for the tudents records and its memeber fuctions
    
public:
    int ID;          // to catch all values passed to the class
    string Name;
    string Address;
    int grade;
    int avg;
    int *testScores;  //ptr for each score
    
    studentRecord()   //constructor for student values
    {
        Name = "";
        Address = "";
        avg = 0;
        ID = 0;
    }
    
    studentRecord(string nam,string addr, int average, int id)  // inline def for getting values passed
    {
        Name = nam;
        Address = addr;
        avg = average;
        ID = id;
    }
    
    studentRecord( int id, string name, string address, int average )  //uses ptr to entr all info for each node
    {
        this -> Name = name;
        this -> Address = address;
        this -> avg = average;
        this -> ID = id;
    }
    
    studentRecord(const studentRecord & obj)  // takes node and stores info from the object
    {
        this -> ID = obj.ID;
        this -> Name = obj.Name;
        this -> Address = obj.Address;
        this -> avg = obj.avg;
    }
    
    void print()  // prints each nodes info as called
    {
        cout << "Student ID: " << ID << endl;
        cout << "Student name: " << Name << endl;
        cout << "Studnet address: " << Address << endl;
        cout << "Student average: " << avg << endl;
        cout << endl << endl;
        
    }
    
    void setName(string);  // member functions for this class
    string getName();  // gets name
    void setAddress(string); // gets adress
    string getAddress();  // gets address
    void setId();  // set ID
    int getId();   // get student ID
    void setTestavg();  // does average of all test
    int getTestavg(); // gets test scores
};

struct Node   /// studnet Node for creating a linked list
{
    studentRecord student;  //passes the entire class for ease of use and moving all info in nodes at once
    Node * next;  // points to what's next in list
};

class DynmStack : private studentRecord {
    
    Node *head;  // points to head of list
    int top;   // points to top of stack
    
public:
    
    DynmStack() // sets top of staack to -1 for checkking purposes later
    {
        top = -1;
    }
    
    void push(int idNum, string name, string add, int score)
    {
        if (top <0)  //if empty list
        {
            head = new Node;  // dynamically allocate memory for head ptr/node and enter new node info
            head->next=NULL;
            head->student.ID=idNum;
            head->student.Name= name;
            head->student.Address=add;
            head->student.avg=score;
            
            top++;
        }
        else  // if nodes exist
        {
            Node *temp, *temp1;
            temp=head;
            if(top >= 15)
            {
                cout << " Over flow " << endl;
                return;
            }
            top++;
            
            while(temp-> next != NULL) // while it doesnt point to null// it isnt last node then taverse list and enter info
                temp = temp->next;
            
            temp1=new Node;
            temp -> next= temp1;
            temp1 -> next= NULL;
            temp1 -> student.ID = idNum;
            temp1 -> student.Name = name;
            temp1 -> student.Address = add;
            temp1 -> student.avg = score;
        }
    }
    
    
    void displayStack ()  //traverses the stack and displays what's in it
    {
        Node *temp;
        temp = head;
        
        if(top < 0)
        {
            cout << "Under flow" << endl;
            return;
        }
        
        while(temp != NULL)
        {
            cout << "Student ID: " << temp -> student.ID << endl;
            cout << "Student Name: " << temp -> student.Name << endl;
            cout << "Student address: " << temp -> student.Address << endl;
            cout << "Student average scores: " << temp -> student.avg << endl;
            cout << endl << endl;
            temp = temp->next;
        }
    }
    
    
    void pop()  // pops what's in the linked list by LIFO since it's a stack
    {
        Node *temp;
        temp = head;
        
        if(top <0)  // check for underflow
        {
            cout << "stack under flow";
        }
        
        top--;
        
        while(temp->next->next != NULL)  // looks for last node to delete (LIFO)
        {
            temp=temp->next;
        }
        
        temp->next=NULL;
    }
};


void firstNode(struct Node *head, studentRecord student)  // creates the first node to be used
{
    head->student = student;
    head->next = NULL;
}


void appendNode(struct Node *head, studentRecord std)  // adds to the end of the list
{
    Node *newNode = new Node;
    newNode->student = std;
    newNode->next = NULL;
    
    Node *current = head;
    while (current)
    {
        if (current->next == NULL)
        {
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}

//displays linked list to screen
void displayList(struct Node *head)
{
    Node *linkedList = head;
    
    while (linkedList)
    {
        linkedList->student.print();
        linkedList = linkedList->next;
    }
}


void studentRecord::setName(string name)  // sets name
{
    Name = name;
}


string studentRecord::getName() // returns name
{
    return Name;
}


void studentRecord::setAddress(string address) // sets address
{
    Address = address;
}


string studentRecord::getAddress()  //gets address
{
    return Address;
}


void studentRecord::setId()  // uses rand alg to generate ID's for students
{
    int MIN_VALUE = 0000;
    int MAX_VALUE = 9999;
    ID = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
}

// gets ID
int studentRecord::getId()
{
    return ID;
}


void studentRecord::setTestavg()  // for cal ave
{
    int MIN = 10;
    int MAX = 100;
    int gradeTotal = 0;
    int tests[10];
    
    testScores = tests;
    
    for(int i = 0; i<10;i++)
    {
        grade = ( rand() % ( MAX  + ( MIN + 1 )));  // usese rand alg to generate 10 test scores
        tests[i] = grade;
    }
    
    for (int i = 0; i < 10; i++)
    {
        gradeTotal += tests[i];
    }
    
    avg = gradeTotal/10;
}

//gets test average
int studentRecord::getTestavg()
{
    return avg;
}


















int main()
{
    studentRecord StudentRec[15]; //creates the linked list for 15 students
    
    StudentRec[0].setName("Trey");  // enters names into linked list
    StudentRec[1].setName("Larry");
    StudentRec[2].setName("Drake");
    StudentRec[3].setName("lol");
    StudentRec[4].setName("joy");
    StudentRec[5].setName("Mister");
    StudentRec[6].setName("Sandy");
    StudentRec[7].setName("Frank");
    StudentRec[8].setName("Zack");
    StudentRec[9].setName("Luke");
    StudentRec[10].setName("Blake");
    StudentRec[11].setName("Dan");
    StudentRec[12].setName("Shelby");
    StudentRec[13].setName("Quest");
    StudentRec[14].setName("Kimmy");
    
    for(int i = 0; i < 15; i++) // enters all test into nodes of list
    {
        StudentRec[i].setTestavg();
    }
    
  
    StudentRec[0].setAddress("1234 road");  // enters adresses into linked list
    StudentRec[1].setAddress("1234 road");
    StudentRec[2].setAddress("1234 road");
    StudentRec[3].setAddress("1234 road");
    StudentRec[4].setAddress("1234 road");
    StudentRec[5].setAddress("1234 road");
    StudentRec[6].setAddress("1234 road");
    StudentRec[7].setAddress("1234 road");
    StudentRec[8].setAddress("1234 road");
    StudentRec[9].setAddress("1234 road");
    StudentRec[10].setAddress("1234 road");
    StudentRec[11].setAddress("1234 road");
    StudentRec[12].setAddress("1234 road");
    StudentRec[13].setAddress("1234 road");
    StudentRec[14].setAddress("1234 road");
    
    for (int i = 0; i < 15; i++)    //enters all ID's into linked list
    {
        StudentRec[i].setId();
    }
    
    struct Node *head = new Node;  // dynamiclaly allocates memory
    
    for (int i = 0; i < 15; i++)
    {
        if (i == 0)  // creates first node for list
        {
            firstNode(head, studentRecord(StudentRec[i].getId(),
                                      StudentRec[i].getName(), StudentRec[i].getAddress(),
                                      StudentRec[i].getTestavg()));
        }
        if ( i > 0)  // adds nodes after one another (LIFO stack)
        {
            appendNode(head, studentRecord(StudentRec[i].getId(),
                                     StudentRec[i].getName(), StudentRec[i].getAddress(),
                                     StudentRec[i].getTestavg()));
        }
    }
    
    cout << "Student's information in linked list" << endl << endl;
    
    //displays contents in linked list before being sorted
    displayList(head);
    
    Node *ptr; // for pushing the info inot the stack
    
    ptr = head;  // starts at the begining of list
    
    DynmStack accessStack;
    
    
    for (int i = 0; i < 15; i++)
    {
        accessStack.push(ptr->student.ID, ptr->student.Name,
                         ptr->student.Address, ptr->student.avg);
        ptr = ptr->next;  // points to what is next in the linked list after each complete entry
    }
    
    cout << endl << endl ;
    cout << "Students information in stack (dynamic) " << endl << endl;
    
    accessStack.displayStack();     //displays stack with all info
    
    for(int i = 0; i < 5; i++)
    {
        accessStack.pop();
    }
    
    cout << endl << endl;
    cout << "Student list in Dynamic stack after pop. " << endl << endl;
    
    accessStack.displayStack();    // displays what's left after the pop takes place
    
    return 0;
}
