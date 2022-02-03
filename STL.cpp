/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Project Name :       Customize Generic data structure Library
//  Description :        It contains the generic code for All types of Linked list
//  Input Arguments:     Generic Input
//  output:              Linked List
//  Author :             Mohmmadali Akbar Shaikh
//  Date :               18/11/2021
//  Purpose:			 The purpose of this project is to deeply study the internals of the Data Structure 
//						 and creating own data structure library
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//Common structure for Singly LL
///////////////////////////////////////////////////////////////////////
template<typename T>
struct node
{
    T data;
    struct node *next;
};

///////////////////////////////////////////////////////////////////////
//Common structure for Doubly LL
///////////////////////////////////////////////////////////////////////
template<typename T>
struct node2
{
    T data;
    struct node2 *next;
	struct node2 *prev;
};

///////////////////////////////////////////////////////////////////////
//Common structure for Binary Search Tree
///////////////////////////////////////////////////////////////////////
template<typename T>
struct node3
{
	int data;
	struct node3 *lchild;
	struct node3 *rchild;
};

/////////////////////////////////////////////////////////////////////////
//Singly Linear Linked list
////////////////////////////////////////////////////////////////////////
template<class T>
class SinglyLL
{
private:
    node<T>* first;
    int size;
    
public:
    SinglyLL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
	
};

//////////////////////////////////////////////////////////////////////////////
//Doubly Linear linked list
//////////////////////////////////////////////////////////////////////////////
template<class T>
class DoublyLL
{
private:
    node2<T>* first;
    int size;
    
public:
    DoublyLL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
	
};

//////////////////////////////////////////////////////////////////////////////
//Singly Circular linked List
//////////////////////////////////////////////////////////////////////////////
template<class T>
class SinglyCL
{
	
private:
    node<T>* first;
	node<T>* last;
    int size;
    
public:
    SinglyCL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
	
};

//////////////////////////////////////////////////////////////////////////////
//Doubly Circular Linked list
//////////////////////////////////////////////////////////////////////////////
template<class T>
class DoublyCL
{
private:
    node2<T>* first;
	node2<T>* last;
    int size;
    
public:
    DoublyCL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
	
};

//////////////////////////////////////////////////////////////////////////////
//Stack
//////////////////////////////////////////////////////////////////////////////
template<class T>
class Stack     // Singly Linear Linked List
{
private:
    node<T> * first;
    int size;
    
public:
   Stack();
   void push(T);
   int pop();
   void Display();
   int Count();
};

//////////////////////////////////////////////////////////////////////////////
//Queue
//////////////////////////////////////////////////////////////////////////////		
template<class T>
class Queue     // Singly Linear Linked List
{
private:
    node<T> * first;
    int size;
    
public:
    Queue();
	void Enqueue(T);
	int Dequeue();
	void Display();
	int Count();
};

//////////////////////////////////////////////////////////////////////////////	
//Binary Search Tree
//////////////////////////////////////////////////////////////////////////////	
template<class T>
class Tree
{
	public:
	node3<T> * first;
	
	public:
	Tree();
	void Insert(T);
	bool Search(T);
	int Count(node3<T> *);
	int CountLeaf(node3<T> *);
	int CountParent(node3<T> *);
	void Inorder(node3<T> *);
	void Preorder(node3<T> *);
	void Postorder(node3<T> *);
	
};

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//Operations on Singly Linear Linked list
//////////////////////////////////////////////////////////////////////////////
    template<class T>
    SinglyLL<T>::SinglyLL()
    {
        first = NULL;
        size = 0;
    }
	
    template<class T>
    void SinglyLL<T>::InsertFirst(T no)
    {
        node<T> * newn = new node<T>;  // newn = (PNODE)malloc(sizeof(NODE))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        size++;
    }
	
    template<class T>
    void SinglyLL<T>::InsertLast(T no)
    {
       node<T> * newn = new node<T>;  // newn = (PNODE)malloc(sizeof(NODE))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            node<T> * temp = first;
            
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        size++;
    }
	
    template<class T>
    void SinglyLL<T>::InsertAtPos(T no, int ipos)
    {
		node<T> * temp=first;
		int i=0;
		
		if((ipos<1)||(ipos>size+1))
		{
			cout<<"Enter valid no"<<"\n";
			return;
		}
		
		if(ipos==1)
		{
			InsertFirst(no);
		}
		else if(ipos==size+1)
		{
			InsertLast(no);
		}
		else
		{
			node<T> * newn=new node<T>;
			newn->data=no;
		    newn->next=NULL;
			
			for(i=1;i<ipos-1;i++)
			{
				temp=temp->next;
			}
			newn->next=temp->next;
			temp->next=newn;
			size++;
		}
	}
	
    template<class T>
    void SinglyLL<T>::DeleteFirst()
    {
        node<T> * temp = first;
        
        if(first != NULL)
        {
            first = first->next;
            delete temp;
            
            size--;
        }
    }
	
    template<class T>
    void SinglyLL<T>::DeleteLast()
    {
         node<T> * temp = first;
        
        if(first == NULL)
        {
            return;
        }
        else if(first->next == NULL)
        {
            delete first;
            first = NULL;
            size--;
        }
        else
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            
            delete temp->next;
            temp->next = NULL;
            size--;
        }
    }
	
	template<class T>
    void SinglyLL<T>::DeleteAtPos(int ipos)
    {
		node<T> * temp=first;
		int i=0;
		
		if((ipos<1)||(ipos>size))
		{
			cout<<"Enter valid no"<<"\n";
			return;
		}
		
		if(ipos==1)
		{
			DeleteFirst();
		}
		else if(ipos==size)
		{
			DeleteLast();
		}
		else
		{
			node<T> * targated=NULL;
			for(i=1;i<ipos-1;i++)
			{
				temp=temp->next;
			}
			targated=temp->next;
			temp->next=targated->next;
			free(targated);
			size--;	
		}
	}
	
    template<class T>
    void SinglyLL<T>::Display()
    {
         node<T> * temp = first;
        
        while(temp!= NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }
	
    template<class T>
    int SinglyLL<T>::Count()
    {
        return size;
    }
	
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//Operations on Singly Circular Linked list
//////////////////////////////////////////////////////////////////////////////
template<class T>
SinglyCL<T>::SinglyCL()
	{
		first=NULL;
		last=NULL;
		size=0;
	}
	
	template<class T>
	void SinglyCL<T>::Display()
	{
		node<T> * temp=first;
		do
		{
			cout<<"|"<<temp->data<<"|->\t";
			temp=temp->next;
		}while(temp!=last->next);
		cout<<"\n";
	}
	
	template<class T>
	int SinglyCL<T>::Count()
	{
		return size;
	}
	
	template<class T>
	void SinglyCL<T>::InsertFirst(T no)
	{
		node<T> * newn=NULL;
		newn=new node<T>;
		
		newn->data=no;
		newn->next=NULL;
		
		if((first==NULL)&&(last==NULL))
		{
			first=newn;
			last=newn;
		}
		else
		{
			newn->next=first;
			first=newn;
		}
		last->next=first;
		size++;
		
	}
	
	template<class T>
	void SinglyCL<T>::InsertLast(T no)
	{
		node<T> * newn=NULL;
		newn=new node<T>;
		 newn->data=no;
		 newn->next=NULL;
		 
		 if((first==NULL)&&(last==NULL))
		 {
			 first=newn;
			 last=newn;
		 }
		 else
		 {
			 last->next=newn;
			 last=newn;
		 }
		 last->next=first;
		 size++;
	}
	
	template<class T>
	void SinglyCL<T>::InsertAtPos(T no,int iPos)
	{
		if((iPos<1)||(iPos>size+1))
		{
			return;
		}
		
		if(iPos==1)
		{
			InsertFirst(no);
		}
		else if(iPos==size+1)
		{
			InsertLast(no);
		}
		else
		{
			node<T> * newn=new node<T>;
			newn->data=no;
			newn->next=NULL;

			for(int i=1;i<iPos-1;i++)
			{
				first=first->next;
			}
			newn->next=first->next;
			first->next=newn;
			first=last->next;
			size++;
		}
	}
	
	template<class T>
	void SinglyCL<T>::DeleteFirst()
	{
		if((first==NULL)&&(last==NULL))
		{
			return;
		}
		else if(first==last)
		{
			delete first;
			first=NULL;
			last=NULL;
		}
		else
		{
			first=first->next;
			delete last->next;
			last->next=first;
		}
		size--;
	}
	
	template<class T>
	void SinglyCL<T>::DeleteLast()
	{
		int i=0;
		node<T> * temp=first;
		
		if((first==NULL)&&(last==NULL))
		{
			return;
		}
		else if(first==last)
		{
			delete first;
			first=NULL;
			last=NULL;
		}
		else
		{
			for(i=1;i<size-1;i++)
			{
				temp=temp->next;
			}
			delete last;
			last=temp;
			last->next=first;
			size--;
		}
	}
	
	template<class T>
	void SinglyCL<T>::DeleteAtPos(int iPos)
	{
		node<T> * targated=NULL;
		if((iPos<1)||(iPos>size))
		{
			return;
		}
		
		if(iPos==1)
		{
			DeleteFirst();
		}
		else if(iPos==size)
		{
			DeleteLast();
		}
		else
		{
			for(int i=1;i<iPos-1;i++)
			{
				first=first->next;
			}
			targated=first->next;
			first->next=targated->next;
			delete targated;
			first=last->next;
			size--;
		}	
	}
	
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//Operations on Doubly Linear linked list
//////////////////////////////////////////////////////////////////////////////
template<class T>
DoublyLL<T>::DoublyLL()
	{
		first=NULL;
		size=0;
	}
	
	template<class T>
	void DoublyLL<T>::InsertFirst(T no)
	{
		node2<T> * newn=NULL;
		newn=new node2<T>;
		
		newn->data=no;
		newn->next=NULL;
		newn->prev=NULL;
		
		if(first==NULL)
		{
			first=newn;
		}
		else
		{
			newn->next=first;
			first->prev=newn;
			first=newn;
		}
		size++;
	}
	
	template<class T>
	void DoublyLL<T>::InsertLast(T no)
	{
		node2<T> * newn=NULL;
		node2<T> * temp=first;
		
		newn=new node2<T>;
		
		newn->data=no;
		newn->next=NULL;
		newn->prev=NULL;
		
		if(first==NULL)
		{
			first=newn;
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newn;
			newn->prev=temp;
		}
		size++;
	}
	
	template<class T>
	void DoublyLL<T>::DeleteFirst()
	{
		node2<T> * temp=first;
		if(first!=NULL)
		{
			first=first->next;
			free(temp);
			if(first!=NULL)
			{
				first->prev=NULL;
			}
		}
		size--;
	}
	
	template<class T>
	void DoublyLL<T>::DeleteLast()
	{
		node2<T> * temp=first;
		if(first==NULL)
		{
			return;
		}
		else if(first->next=NULL)
		{
			delete first;
			first=NULL;
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->prev->next=NULL;
			delete temp;
		}
		size--;
	}
	
	template<class T>
	void DoublyLL<T>::Display()
	{
		node2<T> * temp=first;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ->\t";
			temp=temp->next;
		}
		cout<<"NULL\n";

	}
	
	template<class T>
	int DoublyLL<T>::Count()
	{
		return size;
	}
	
	template<class T>
	void DoublyLL<T>::InsertAtPos(T no,int iPos)
	{
		node2<T> * temp=first;
		int i=0;
		
		if((iPos<1)||(iPos>size+1))
		{
			cout<<"Enter valid Position\n";
			return ;
		}
		
		if(iPos==1)
		{
			InsertFirst(no);
		}
		else if(iPos==size+1)
		{
			InsertLast(no);
		}
		else
		{
			node2<T> * newn=new node2<T>;
			
			newn->data=no;
			newn->next=NULL;
			newn->prev=NULL;
			
			for(i=1;i<iPos-1;i++)
			{
				temp=temp->next;
			}
			newn->next=temp->next;
			temp->next->prev=newn;
			temp->next=newn;
			newn->prev=temp;
		}
	}
	
	template<class T>
	void DoublyLL<T>::DeleteAtPos(int iPos)
	{
		node2<T> * temp=first;
		int i=0;
		
		if((iPos<1)||(iPos>size))
		{
			cout<<"Enter valid position\n";
			return;
		}
		
		if(iPos==1)
		{
			DeleteFirst();
		}
		else if(iPos==size)
		{
			DeleteLast();
		}
		else
		{
			for(i=1;i<iPos-1;i++)
			{
				temp=temp->next;
			}
			temp->next=temp->next->next;
			delete temp->next->prev;
			temp->next->prev=temp;
		}
	}
	
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//Operations on Doubly Circular Linked list
//////////////////////////////////////////////////////////////////////////////
template<class T>
DoublyCL<T>::DoublyCL()
{
	first=NULL;
	last=NULL;
    size=0;
}

template<class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    node2<T> * newn = new node2<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}

template<class T>
void DoublyCL<T> :: InsertLast(T no)
{
    node2<T> * newn = new node2<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn->prev = last;
        last = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}

template<class T>
void DoublyCL<T> :: Display()
{
    node2<T> * temp = first;
    
    for(int i = 1; i <= size; i++)
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp->next;
    }
    cout<<"\n";
}

template<class T>
int DoublyCL<T> :: Count()
{
    return size;
}

template<class T>
void DoublyCL<T> :: DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}

template<class T>
void DoublyCL<T> :: DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        last = last -> prev;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}

template<class T>
void DoublyCL<T> :: InsertAtPos(T no, int ipos)
{
    if((ipos < 1) || (ipos > size+1))
    {
        return;
    }
    
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == size +1)
    {
        InsertLast(no);
    }
    else
    {
        node2<T> * newn= new node2<T>;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        
        node<T> * temp = first;
        
        for(int i = 1; i < ipos -1; i++)
        {
            temp = temp -> next;
        }
        
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        size ++;
    }
}

template<class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > size))
    {
        return;
    }
    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == size)
    {
        DeleteLast();
    }
    else
    {
        node2<T> * temp = first;
        
        for(int i = 1; i < ipos -1 ; i ++)
        {
            temp = temp -> next;
        }
       
        temp -> next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        
        size--;
    }
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//Operations on Stack
//////////////////////////////////////////////////////////////////////////////
template<class T>
Stack<T>::Stack()
    {
        first = NULL;
        size = 0;
    }
    
    template<class T>
    void Stack<T>::push(T no)   // InsertFirst()
    {
        node<T> * newn=new node<T>;
		newn->data=no;
		newn->next=NULL;
		
		if(first==NULL)
		{
			first=newn;
		}
		else
		{
			newn->next=first;
			first=newn;
		
		}
		size++;
    }
    
	
    template<class T>
    int Stack<T>::pop()   // DeleteFirst()
    {
        int iRet=0;
		node<T> * temp=first;
		if(size==0)
		{
			cout<<"Stack is empty\n";
			return -1;
		}
		else if(size==1)
		{
			iRet=first->data;
			delete first;
			first=NULL;
		}
		else
		{
			iRet=first->data;
			first=first->next;
			delete temp;
		}
		size--;
		return iRet;
    }
    
    template<class T>
    void Stack<T>::Display()
    {
		node<T> * temp=first;
		while(temp!=NULL)
		{
			cout<<"|"<<temp->data<<"|"<<"\n";
			temp=temp->next;
		}
		cout<<"NULL\n";
	}
    
    template<class T>
    int Stack<T>::Count()
    {
        return size;
    }
	
//////////////////////////////////////////////////////////////////////////////	
//////////////////////////////////////////////////////////////////////////////
//Operations on Queue
//////////////////////////////////////////////////////////////////////////////
template<class T>
Queue<T>::Queue()
    {
        first = NULL;
        size = 0;
    }
    
    template<class T>
    void Queue<T>::Enqueue(T no)   // InsertLast()
    {
        node<T> * newn=new node<T>;
		newn->data=no;
		newn->next=NULL;

		if(first==NULL)
		{
			first=newn;
		}
		else
		{
					
		node<T> * temp=first;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
		}
		size++;
		
    }
	
    template<class T>
    int Queue<T>::Dequeue()   // DeleteFirst()
    {
       int iRet=0;
		node<T> * temp=first;
		if(size==0)
		{
			cout<<"Queue is empty\n";
			return -1;
		}
		else if(size==1)
		{
			iRet=first->data;
			delete first;
			first=NULL;
		}
		else
		{
			iRet=first->data;
			first=first->next;
			delete temp;
		}
		size--;
		return iRet;
    }
    template<class T>
    void Queue<T>::Display()
    {
		node<T> * temp=first;
		while(temp!=NULL)
		{
			cout<<"|"<<temp->data<<"|"<<"\n";
			temp=temp->next;
		}
		cout<<"NULL\n";
	}
	
    template<class T>
    int Queue<T>::Count()
    {
        return size;
    }
	
//////////////////////////////////////////////////////////////////////////////	
//////////////////////////////////////////////////////////////////////////////
//Operations on Binary Search Tree
//////////////////////////////////////////////////////////////////////////////
template<class T>
Tree<T>::Tree()
{
	first=NULL;
}

template<class T>
void Tree<T>::Insert(T no)
{
	node3<T> * newn=new node3<T>;
	
	newn->data=no;
	newn->lchild=NULL;
	newn->rchild=NULL;
	
	if(first==NULL)
	{
		first=newn;
	}
	else
	{
		node3<T> * temp=first;
		while(1)
		{
			if(temp->data==no)
			{
				cout<<"Duplicate node\n";
				delete newn;
				break;
				
			}
			else if(temp->data > no)
			{
				if((temp->lchild)==NULL)
				{
					temp->lchild=newn;
					break;
				}
				temp=temp->lchild;
			}
			else if(temp->data < no)
			{
				if((temp->rchild)==NULL)
				{
					temp->rchild=newn;
					break;
				}
				temp=temp->rchild;
			}
		}
	}
}

template<class T>
bool Tree<T>::Search(T no)
{
	if(first==NULL)
	{
		return false;
	}
	else
	{
		node3<T> * temp=first;
		while(temp!=NULL)
		{
			if(temp->data==no)
			{
				break;
			}
			else if((temp->data) > no)
			{
				temp=temp->lchild;
			}
			else if((temp->data) < no)
			{
				temp=temp->rchild;
			}
		}
		if(temp==NULL)
		{
			return false;
		}
		else 
		{
			return true;
		}
	}
}

template<class T>
int Tree<T>::Count(node3<T> * Head)
{
	node3<T> * temp=Head;
	static int iCnt=0;
	
	if(temp!=NULL)
	{
		iCnt++;
		Count(temp->lchild);
		Count(temp->rchild);
	}
	return iCnt;
}

template<class T>
int Tree<T>::CountLeaf(node3<T> * Head)
{
	node3<T> * temp=Head;
	static int iCnt=0;
	
	if(temp!=NULL)
	{
		if(((temp->lchild)==NULL)&&((temp->rchild)==NULL))
		{
			iCnt++;
		}
		CountLeaf(temp->lchild);
		CountLeaf(temp->rchild);
	}
	return iCnt;
}

template<class T>
int Tree<T>::CountParent(node3<T> * Head)
{
	node3<T> * temp=Head;
	static int iCnt;
	
	if(temp!=NULL)
	{
		if(((temp->lchild)!=NULL)||((temp->rchild)!=NULL))
		{
			iCnt++;
		}
		CountParent(temp->lchild);
		CountParent(temp->rchild);
	}
	return iCnt;
}

template<class T>
void Tree<T>::Inorder(node3<T> * Head)
{
	node3<T> * temp=Head;
	if(temp!=NULL)
	{
		Inorder(temp->lchild);
		cout<<temp->data<<"\n";
		Inorder(temp->rchild);
	}
}

template<class T>
void Tree<T>::Preorder(node3<T> * Head)
{
	node3<T> * temp=Head;
	if(temp!=NULL)
	{
		cout<<temp->data<<"\n";
		Preorder(temp->lchild);
		Preorder(temp->rchild);
	}
}

template<class T>
void Tree<T>::Postorder(node3<T> * Head)
{
	node3<T> * temp=Head;
	if(temp!=NULL)
	{
		Postorder(temp->lchild);
		Postorder(temp->rchild);
		cout<<temp->data<<"\n";
	}
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//Entry point function
//////////////////////////////////////////////////////////////////////////////
int main()
{
//////////////////////////////////////////////////////////////////////////////
//Singly Linear Linked List
//Demonstration
//////////////////////////////////////////////////////////////////////////////	
    int iret = 0;

	SinglyLL <char>cobj;

    cobj.InsertFirst('A');
    cobj.InsertFirst('B');
    cobj.InsertFirst('C');
    
    cobj.InsertLast('S');
    cobj.InsertLast('D');
    
    cobj.Display();
    
    iret = cobj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
//////////////////////////////////////////////////////////////////////////////
	SinglyLL <int>iobj;

    iobj.InsertFirst(11);
    iobj.InsertFirst(21);
    iobj.InsertFirst(51);
    
    iobj.InsertLast(101);
    iobj.InsertLast(111);
    
    iobj.Display();
    
    iret = iobj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
	
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////    
	
//////////////////////////////////////////////////////////////////////////////	
//Singly circular linked list
//Demonstration
//////////////////////////////////////////////////////////////////////////////	
	int iRet = 0;

	SinglyCL <char>Cobj;

    Cobj.InsertFirst('A');
    Cobj.InsertFirst('B');
    Cobj.InsertFirst('C');
    
    Cobj.InsertLast('S');
    Cobj.InsertLast('D');
    
    Cobj.Display();
    
    iret =Cobj.Count();
    cout<<"Number of elemensts are : "<<iRet<<"\n";
	
//////////////////////////////////////////////////////////////////////////////   
 
	SinglyCL <int>Iobj;

    Iobj.InsertFirst(11);
    Iobj.InsertFirst(21);
    Iobj.InsertFirst(51);
    
    Iobj.InsertLast(101);
    Iobj.InsertLast(111);
    
    Iobj.Display();
    
    iRet = Iobj.Count();
    cout<<"Number of elemensts are : "<<iRet<<"\n";
	
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//Doubly linear linked list
//Demonstration
//////////////////////////////////////////////////////////////////////////////	
	int dret = 0;

	DoublyLL <char>cdobj;

    cdobj.InsertFirst('A');
    cdobj.InsertFirst('B');
    cdobj.InsertFirst('C');
    
    cdobj.InsertLast('S');
    cdobj.InsertLast('D');
    
    cdobj.Display();
    
    dret = cdobj.Count();
    cout<<"Number of elemensts are : "<<dret<<"\n";
	
//////////////////////////////////////////////////////////////////////////////
	
	DoublyLL <int>idobj;

    idobj.InsertFirst(11);
    idobj.InsertFirst(21);
    idobj.InsertFirst(51);
    
    idobj.InsertLast(101);
    idobj.InsertLast(111);
    
    idobj.Display();
    
    dret = idobj.Count();
    cout<<"Number of elemensts are : "<<dret<<"\n";
	
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//Doubly Circular Linked list
//Demonstration
//////////////////////////////////////////////////////////////////////////////	
	int Dret = 0;

	DoublyCL <char>CDobj;

    CDobj.InsertFirst('A');
    CDobj.InsertFirst('B');
    CDobj.InsertFirst('C');
    
    CDobj.InsertLast('S');
    CDobj.InsertLast('D');
    
    CDobj.Display();
    
    Dret = CDobj.Count();
    cout<<"Number of elemensts are : "<<Dret<<"\n";
	
//////////////////////////////////////////////////////////////////////////////
	
	DoublyCL <int>IDobj;

    IDobj.InsertFirst(11);
    IDobj.InsertFirst(21);
    IDobj.InsertFirst(51);
    
    IDobj.InsertLast(101);
    IDobj.InsertLast(111);
    
    IDobj.Display();
    
    Dret = IDobj.Count();
    cout<<"Number of elemensts are : "<<Dret<<"\n";
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//Stack
//Demonstration
//////////////////////////////////////////////////////////////////////////////	
	Stack <int>sobj;
    
    sobj.push(11);
    sobj.push(21);
    sobj.push(51);
    sobj.push(101);
    
	cout<<"Elements of stack\n";
	sobj.Display(); 
    int sret = sobj.pop();       // 101
    cout<<"Poped element is:"<<sret<<"\n";                     // 101
    cout<<"Elements of stack\n";
    sobj.Display();          // 51       21      11
    sret = sobj.Count();
    
    cout<<"Size of stack is : "<<sret<<"\n";        // 3
//////////////////////////////////////////////////////////////////////////////
	Stack <char>Sobj;
    
    Sobj.push('a');
    Sobj.push('s');
    Sobj.push('q');
    Sobj.push('o');
    
	cout<<"Elements of stack\n";
	Sobj.Display(); 
    int Sret = Sobj.pop();       
    cout<<"Poped element is:"<<Sret<<"\n";                     
    cout<<"Elements of stack\n";
    Sobj.Display();         
    Sret = Sobj.Count();
    
    cout<<"Size of stack is : "<<Sret<<"\n";      
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//Queue
//Demonstration
//////////////////////////////////////////////////////////////////////////////	
	Queue <int>qobj;
    
    qobj.Enqueue(11);
    qobj.Enqueue(21);
    qobj.Enqueue(51);
    qobj.Enqueue(101);
    
	cout<<"Elements of Queue\n";
	qobj.Display(); 
    int qret = qobj.Dequeue();       // 11
    cout<<"Removed element from queue is:"<<qret<<"\n";                     // 11
   
    cout<<"Elements of Queue\n";
	qobj.Display();         // 11       21          51
    qret = qobj.Count();     // 3
    
    cout<<"Size of queue is : "<<qret<<"\n";        // 3
    
//////////////////////////////////////////////////////////////////////////////
	
	 Queue <char>Qobj;
    
    Qobj.Enqueue('a');
    Qobj.Enqueue('s');
    Qobj.Enqueue('d');
    Qobj.Enqueue('f');
    
	cout<<"Elements of Queue\n";
	Qobj.Display(); 
    int Qret = Qobj.Dequeue();     
    cout<<"Removed element from queue is:"<<Qret<<"\n";                     
   
    cout<<"Elements of Queue\n";
	Qobj.Display();        
    Qret = Qobj.Count();     
    
    cout<<"Size of queue is : "<<Qret<<"\n";   

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//Binary Search Tree
//Demonstration
//////////////////////////////////////////////////////////////////////////////
Tree <int>tobj;
	int no=0,tret=0;
	tobj.Insert(51);
	tobj.Insert(21);
	tobj.Insert(101);
	
	node3<int>* troot=tobj.first;
	cout<<"Enter the number to search\n";
	cin>>no;
	bool bret=tobj.Search(no);
	if(bret==true)
	{
		cout<<"Number is there\n";
	}
	else
	{
		cout<<"Number is not there\n";
	}
	
	tret=tobj.Count(troot);
	cout<<"Number of nodes are :"<<tret<<"\n";
	
	tret=tobj.CountLeaf(troot);
	cout<<"Number of leaf nodes are :"<<tret<<"\n";
	
	tret= tobj.CountParent(troot);
	cout<<"Number of Parent node are :"<<tret<<"\n";
	
	cout<<"Inorder\n";
	tobj.Inorder(troot);
	
	cout<<"Preorder\n";
	tobj.Preorder(troot);
	
	cout<<"Postorder\n";
	tobj.Postorder(troot);
	
//////////////////////////////////////////////////////////////////////////////
	
	Tree <char>Tobj;
	int No=0,Tret;
	Tobj.Insert('a');
	Tobj.Insert('s');
	Tobj.Insert('d');
	
	node3<char>* Troot=Tobj.first;
	cout<<"Enter the number to search\n";
	cin>>No;
	bool Bret=Tobj.Search(No);
	if(Bret==true)
	{
		cout<<"Number is there\n";
	}
	else
	{
		cout<<"Number is not there\n";
	}
	
	Tret=Tobj.Count(Troot);
	cout<<"Number of nodes are :"<<Tret<<"\n";
	
	Tret=Tobj.CountLeaf(Troot);
	cout<<"Number of leaf nodes are :"<<Tret<<"\n";
	
	Tret= Tobj.CountParent(Troot);
	cout<<"Number of Parent node are :"<<Tret<<"\n";
	
	cout<<"Inorder\n";
	Tobj.Inorder(Troot);
	
	cout<<"Preorder\n";
	Tobj.Preorder(Troot);
	
	cout<<"Postorder\n";
	Tobj.Postorder(Troot);
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
	
    return 0;
}
