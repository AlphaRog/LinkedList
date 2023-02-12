#include <iostream>

using namespace std;

class Link
{

public:
    int dData;
    Link *next;

    Link(int data);
    void displayLink();

};

class Linklist
{

private:
    Link *first;

public:
    Linklist();
    void insertFirst(int data);
    Link *Find(int data);
    int deleteFirst();
    bool deleteNode(int data);
    void displayList();

};

Link::Link(int data)
{

    dData=data;
    next=NULL;

}

void Link::displayLink()
{

    cout<<dData<<endl;

}

Linklist::Linklist()
{

    first=NULL;

}

void Linklist::insertFirst(int data)
{

    Link*newLink=new Link(data);
    newLink->next=first;
    first=newLink;

}

int Linklist::deleteFirst()
{

    Link*temp=first;

    first=first->next;
    int y=temp->dData;
    delete temp;

    return y;

}

Link *Linklist::Find(int data)
{

    Link *current=first;

    while(current!=NULL)
    {

        if(current->dData==data)
        {

            return current;

        }
        else
        {
            current=current->next;
        }
    }

    return NULL;
}

bool Linklist::deleteNode(int data)
{

    Link *current=first;
    Link *previous=current;

    while(current!=NULL)
    {

        if(current->dData==data)
        {
            if(current==first)
            {
                first=first->next;
            }
            else
            {
                previous->next=current->next;
            }
            delete current;
            return true;
        }
        else
        {

            previous=current;
            current=current->next;

        }

    }
    return false;

}

void Linklist::displayList()
{

    Link *current=first;

    while(current!=NULL)
    {

        current->displayLink();
        current=current->next;

    }

}

int main()
{

    /**Link *me=new Link(20);
    Link *chukzi=new Link(18);
    Link *gangul=new Link(22);

    me->next=chukzi;
    chukzi->next=gangul;
    me->displayLink();
    chukzi->displayLink();
    me->next->displayLink();
    me->next->next->displayLink();
     */

     Linklist l;
     l.insertFirst(4);
     l.insertFirst(5);
     l.insertFirst(6);
     l.insertFirst(7);
     l.displayList();
     l.deleteFirst();
     l.displayList();

     cout<<l.Find(5)<<endl;

     l.deleteNode(5);

     l.displayList();


    return 0;
}
