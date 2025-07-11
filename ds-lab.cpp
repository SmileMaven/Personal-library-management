#include<bits/stdc++.h>
using namespace std;
/*array r part*/
string name[100];
int asize=0;
void array_insert(string item)
{
    if (asize >= 100)
    {
        cout << "Array is full\n";
        return;
    }

    int i = asize - 1;

    while (i >= 0 && name[i] > item)
    {
        name[i + 1] = name[i];
        i--;
    }

    name[i + 1] = item;
    asize++;

    cout << "Book is inserted to main library\n";
}
void array_dlt(string item)
{
    if(asize==0)
      {
          cout<<"no books in array\n";
    return;
      }
    int pos=-1;
    for(int i=0; i<asize; i++)
    {
        if(name[i]==item)
        {
            pos=i;
            break;
        }

    }
    if(pos==-1)
    {
        cout<<"Book not found\n";
        return;
    }
    for(int i=pos; i<asize-1; i++)
    {
        name[i]=name[i+1];
    }
    asize--;
    cout<<"Book deleted\n";
}
void array_search(string item)
{
    if(asize==0)
      {
          cout<<"no books in array\n";
    return;
      }
    int pos=-1;
    for(int i=0; i<asize; i++)
    {
        if(name[i]==item)
        {
            cout<<"Book found in position: "<<i+1;
            cout<<"\n";
            return;
        }
    }
    if(pos==-1)
        cout<<"Book not found\n";
}
void array_display()
{
    if(asize==0)
      {
          cout<<"no books in main library\n";
    return;
      }
    for(int i=0; i<asize; i++)
    {
        cout<<i+1<<"."<<name[i]<<" ";
    }
    cout<<"\n";
}

/*Linked list er part*/
struct node
{
    string bname;
    node* next;
};
node* head=nullptr;

void insert_llist(string item)
{
    node* newnode = new node();
    newnode->bname = item;
    newnode->next = nullptr;

    if (head == nullptr || item < head->bname)
    {
        newnode->next = head;
        head = newnode;
        cout<<"Book inserted to dynamic library\n";
        return;
    }

    node* temp = head;
    while (temp->next != nullptr && temp->next->bname < item)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    cout<<"Book inserted to dynamic library\n";
}

void dlt_llist(string item)
{
    if (head==nullptr)
    {
        cout<<"no books in the list\n";
        return;
    }
    if(head->bname==item)
    {
        node*temp =head;
        head=head->next;
        return;
    }
    node* temp=head;
    node* prev;
    while(temp!= nullptr && temp->bname!=item )
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp == nullptr)
    {
        cout<<"Book not found in the list\n";
        return;
    }

    prev->next=temp->next;
    delete temp;
    cout<<"Book deleted\n";
}
void search_llist(string item)
{
    if(head==nullptr)
        {cout<<"no books in the list\n";
        return;
        }
    node* temp=head;
    int pos=1;
    while(temp!= nullptr && temp->bname!=item)
    {
        temp=temp->next;
        pos++;
    }
    if(temp==nullptr)
        cout<<"Book not found in the list\n";
    else
        cout<<"book found at position: "<<pos<<"\n";
}
void display_llist()
{
    if(head==nullptr)
       {
           cout<<"no books in list\n";
           return;
       }
    node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->bname;
        if(temp->next != nullptr)
            cout<<" -> ";
            temp=temp->next;
    }
    cout<<"\n";
}


/*queue function*/
#define n 100
string q_book[n];

int front=-1, rear=-1;

void enqueue(string item)
{
    if(rear>=n-1)
    {
        cout<<"overflow\n";
        return ;
    }
  if(front==-1)
        front++;
        rear++;
  q_book[rear]=item;
  cout<<"Book added to reading list\n"<<endl;
}

void dequeue()
{
    if(front==-1 || front > rear)
    {
        cout<<"no items"<<endl;
        return ;
    }
    front++;
    cout<<"Book deleted from reading list\n";
}

void q_display()
{
    if(front==-1 || front>rear)
    {
        cout<<"no items"<<endl;
        return;
    }
    int j=1;
    for(int i=front; i <= rear;i++)
    {

        cout<<j<<"."<<q_book[i]<<" ";
        j++;
    }
    cout<<endl;
}
void q_search(string item)
{
    if(front==-1 || front>rear)
    {
        cout<<"no items"<<endl;
        return;
    }
    for(int i=front; i <= rear;i++)
    {
        if(q_book[i]== item)
        {
            cout<<"item found in position: "<<i+1<<endl;
            return;
        }
    }

    cout<<"item not found :(\n";

}

/*stack shuru*/
string s_book[n];
int top=-1, bottom=-1;
void push(string item)
{
    if(top>=n-1)
    {
        cout<<"overflow\n";
        return ;
    }
  if(bottom==-1)
        bottom++;
        top++;
  s_book[top]=item;
  cout<<"Book added to have read list\n"<<endl;
}
void pop()
{
    if(bottom==-1 || bottom > top)
    {
        cout<<"no items"<<endl;
        return ;
    }
    top--;
    cout<<"Book removed from have read list\n";
}

void s_search(string item)
{
    if(bottom==-1 || bottom>top)
    {
        cout<<"no items"<<endl;
        return;
    }
    for(int i=bottom; i <= top;i++)
    {
        if(s_book[i]== item)
        {
            cout<<"item found in position: "<<i+1<<endl;
            return;
        }
    }

    cout<<"item not found :(\n";

}

void s_display()
{
    if(bottom==-1 || bottom>top)
    {
        cout<<"no items"<<endl;
        return;
    }

    for(int i=top; i >=bottom ;i--)
    {
        cout<<i+1<<"."<<s_book[i]<<" ";
    }
    cout<<endl;
}



int main()
{
    int c1,c2;
    string bname;
    cout<<"\t\t\t\t\tPersonal library Management\n\n\n";
    for(;;)
    {
        cout<<"Choose from the following options: "<<endl;
        cout<<" 1.Insert\n 2.Delete\n 3.Search\n 4.Display\n 5.Exit\n";
        cin>>c1;

        if(c1>5 || c1<1)
        {
            cout<<"invalid input";
            continue;
        }
        if(c1== 5)
            break;



        switch(c1)
        {
        /*insert*/
        case 1:
            for(;;)
            {
                cout<<"Choose type of data: "<<endl;
                cout<<" 1.Array\n 2.Linked List\n 3.Queue\n 4.Stack\n 5.Exit\n";
                cin>>c2;

                if(c2>5 || c2<1)
                {
                    cout<<"invalid input\n";
                    continue;
                }
                if (c2 == 5)
                    break;
                cin.ignore();

                switch(c2)
                {
                /*array r insert*/
                case 1:
                    cout<<"Pls enter book name: ";
                    getline(cin,bname);
                    array_insert(bname);
                    cout<<"\n\n";
                    break;

                    /*linked list er insert*/
                    case 2:
                        cout<<"Pls enter book name: ";
                    getline(cin,bname);
                    insert_llist(bname);
                    cout<<"\n\n";
                    break;

                    /*queue r insert*/
                    case 3:
                        cout<<"Pls enter book name: ";
                    getline(cin,bname);
                    enqueue(bname);
                    cout<<"\n\n";
                    break;

                    /*stack insert*/
                    case 4:
                         cout<<"Pls enter book name: ";
                    getline(cin,bname);
                    push(bname);
                    cout<<"\n\n";
                    break;
                }

            }
            break;
        /*dlt*/
        case 2:
            for(;;)
            {
                cout<<"Choose type of data: "<<endl;
               cout<<" 1.Array\n 2.Linked List\n 3.Queue\n 4.Stack\n 5.Exit\n";
                cin>>c2;
                if(c2>5 && c2<1)
                {
                    cout<<"invalid input\n";
                    continue;
                }
                if (c2 == 5)
                    break;
                cin.ignore();

                switch(c2)
                {
                /*array r dlt*/
                case 1:
                    cout<<"Pls enter book name: ";
                    getline(cin,bname);
                    array_dlt(bname);
                    cout<<"\n\n";
                    break;
                    /*linked list er d;t*/
                    case 2:
                        cout<<"Pls enter book name: ";
                    getline(cin,bname);
                    dlt_llist(bname);
                    cout<<"\n\n";
                    break;

                    /*queue dlt*/
                    case 3:
                    dequeue();
                    cout<<"\n\n";
                    break;

                    /*stack r dlt*/
                    case 4:
                    pop();
                    cout<<"\n\n";
                    break;
                }

            }
            break;
        /*search*/

        case 3:
            for(;;)
            {
                cout<<"Choose type of data: "<<endl;
                cout<<" 1.Array\n 2.Linked List\n 3.Queue\n 4.Stack\n 5.Exit\n";
                cin>>c2;
                if(c2>5 || c2<1)
                {
                    cout<<"invalid input\n";
                    continue;
                }
                if (c2 == 5)
                {
                    break;
                }

                cin.ignore();

                switch(c2)
                {
                /*array r search*/
                case 1:
                    cout<<"Pls enter book name: ";
                    getline(cin,bname);
                    array_search(bname);
                    cout<<"\n\n";
                    break;
                    /*linked list er search*/
                   case 2:
                       cout<<"Pls enter book name: ";
                    getline(cin,bname);
                    search_llist(bname);
                    cout<<"\n\n";
                    break;

                   case 3:
                        cout<<"Pls enter book name: ";
                    getline(cin,bname);
                    q_search(bname);
                    cout<<"\n\n";
                    break;

                   case 4:
                    cout<<"Pls enter book name: ";
                    getline(cin,bname);
                    s_search(bname);
                    cout<<"\n\n";
                    break;
                }

            }
            break;

        /*display*/
        case 4:
            for(;;)
            {
                cout<<"Choose type of data: "<<endl;
                cout<<" 1.Array\n 2.Linked List\n 3.Queue\n 4.Stack\n 5.Exit\n";
                cin>>c2;
                if(c2>5 || c2<1)
                {
                    cout<<"invalid input\n";
                    continue;
                }
                if(c2==5)
                    break;
                cin.ignore();
                switch(c2)
                {
                case 1:
                    array_display();
                    break;
                     case 2:
                         display_llist();
                         break;

                     case 3:
                        q_display();
                        break;

                     case 4:
                        s_display();
                        break;

                }
            }
            break;


        }

    }

    return 0;
}


