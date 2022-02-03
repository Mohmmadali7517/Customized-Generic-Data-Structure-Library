
///////////////////////////////////////////////////////////////////////////////////
//
//  Project Name :         Customized Generic Data Structure Library
//  Description :           It contains Generic codes for All types of the Linked List
//  Input Arguments :       Generic Input
//  Output :`				Linked List of the desired Type
//  Author :                     Mohmmadali Akbar Shaikh
//  Date :                        18/11/2021
//	Purpose:				The purpose of this project is to deeply study the internals of the Data Structure 
//							and creating own data structure library
///////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;


//////////////////////////////////////////////////////////////
//
//Structure for creating Nodes
//
////////////////////////////////////////////////////////////
template <typename T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

//////////////////////////////////////////////////////////////
//
//	Singly Linear Linked List
//
////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
private:
    node <T> * first;
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

template <class T>
SinglyLL<T>:: SinglyLL()
    {
        first = NULL;
        size = 0;
    }
    
	template <class T>
    void SinglyLL<T>:: InsertFirst(T no)
    {
        node <T> * newn = new  node<T>;  // newn = (PNODE)malloc(sizeof(NODE))
        
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
    
	template <class T>
    void SinglyLL<T>:: InsertLast(T no)
    {
        node<T> * newn = new  node<T>;  // newn = (PNODE)malloc(sizeof(NODE))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            node <T>* temp = first;
            
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        size++;
    }
    
	template <class T>
    void SinglyLL<T>:: InsertAtPos(T no, int ipos)
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
			node<T> *newn=new node<T>;
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
    
	template <class T>
    void SinglyLL<T>:: DeleteFirst()
    {
        node<T> * temp = first;
        
        if(first != NULL)
        {
            first = first->next;
            delete temp;
            
            size--;
        }
    }
    
	template <class T>
    void SinglyLL<T>:: DeleteLast()
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
	
	template <class T>
    void SinglyLL<T>:: DeleteAtPos(int ipos)
    {
		node<T> *temp=first;
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
			node<T>* targated=NULL;
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
    
	template <class T>
    void SinglyLL<T>:: Display()
    {
        node<T> * temp = first;
        
        while(temp!= NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }
    
	template <class T>
    int SinglyLL<T>:: Count()
    {
        return size;
    }

//////////////////////////////////////////////////////////////
//
//	Singly Circular Linked List
//
////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
	private:
	  node <T> * first;
	  node <T> * last;
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
template <class T>
SinglyCL<T>::SinglyCL()
	  {
		  first=NULL;
		  last=NULL;
		  size=0;
	  }
	  
	  template <class T>
	  void SinglyCL<T>::Display()
	  {
		  node<T> * temp=first;
		  do
		  {
			  cout<<"|"<<temp->data<<"|->";
			  temp=temp->next;
		  }while(temp!=last->next);
		  cout<<"\n";
	  }
	  
	  template <class T>
	  int SinglyCL<T>::Count()
	  {
		  return size;
	  }
	  
	  template <class T>
	  void SinglyCL<T>::InsertFirst(T no)
	  {
		  node<T> * newn=new node<T>;
		  
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
	  
	  template <class T>
	  void SinglyCL<T>::InsertLast(T no)
	  {
		  node<T> * newn=new node<T>;
		  
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
	  
	  template <class T>
	  void SinglyCL<T>::InsertAtPos(T no, int iPos)
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
			  
			  for(int i=1; i<iPos-1; i++)
			  {
				  first=first->next;
			  }
			  newn->next=first->next;
			  first->next=newn;
			  first=last->next;
			  size++;
		  }
	  }
	  
	  template <class T>
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
	  
	  template <class T>
	  void SinglyCL<T>::DeleteLast()
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
			  node<T> * temp=first;
			  for(int i=1; i<size-1; i++)
			  {
				  temp=temp->next;
			  }
			  delete last;
			  last=temp;
			  last->next=first;
		  }
		  size--;
	  }
	  
	  template <class T>
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
/////////////////////////////////////////////////////////////
//
//	Doubly Linear Linked List
//
////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
	private:
	  node<T> * first;
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

template <class T>
DoublyLL<T>::DoublyLL()
	  {
		  first=NULL;
		  size=0;
	  }
	  
	  template <class T>
	  void DoublyLL<T>::InsertFirst(T no)
	  {
		  node<T> * newn=NULL;
		  newn=new node<T>;
		  
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
		  
	 
	  template <class T>
	  void DoublyLL<T>::InsertLast(T no)
	  {
		 node<T> * newn=NULL;
		 node<T> * temp=first;
		  newn=new node<T>;
		  
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
	  
	  template <class T>
	  void DoublyLL<T>::DeleteFirst()
	  {
		  node<T> * temp=first;
		  if(first!=NULL)
		  {
			  first=first->next;
			  delete temp;
			  if(first!=NULL)
			  {
				  first->prev=NULL;
			  }
		  }
		  size--;
	  }
	  
	  template <class T>
	  void DoublyLL<T>::DeleteLast()
	  {
		  node<T> * temp=first;
		  if(first->next==NULL)
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
	  
	  template <class T>
	  void DoublyLL<T>::Display()
	  {
		  node<T> * temp=first;
		  while(temp!=NULL)
		  {
			  cout<<temp->data<<"->";
			  temp=temp->next;
		  }
		  cout<<"NULL\n";
	  }
	  
	  template <class T>
	  int DoublyLL<T>::Count()
	  {
		  return size;
	  }
	  
	  template <class T>
	  void DoublyLL<T>::InsertAtPos(T no, int iPos)
	  {
		  if(iPos<1||iPos>size+1)
		  {
			  cout<<"Enter the valid position\n";
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
			  node<T> * temp=first;
			  node<T> * newn=NULL;
			  newn= new node<T>;
			  
			  newn->data=no;
			  newn->next=NULL;
			  newn->prev=NULL;
			  
			  for(int i=1; i<iPos-1; i++)
			  {
				  temp=temp->next;
			  }
			  newn->next=temp->next;
			  temp->next->prev=newn;
			  temp->next=newn;
			  newn->prev=temp;
		  }
		  size++;
			  
	  }
	  
	  template <class T>
	  void DoublyLL<T>::DeleteAtPos(int iPos)
	  {
		if(iPos<1||iPos>size)
		  {
			  cout<<"Enter the valid position\n";
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
			  node<T> * temp=first;
			  for(int i=1; i<iPos-1; i++)
			  {
				  temp=temp->next;
			  }
			  temp->next=temp->next->next;
			  delete temp->next->prev;
			  temp->next->prev=temp;
		  }
		  size--;
			  
			  
	  }
//////////////////////////////////////////////////////////////
//
//	Doubly Circular Linked List
//
////////////////////////////////////////////////////////////
	
	template <class T>
class DoublyCL
{
	private:
	  node<T> * first;
	  node<T> * last;
	  int size;
	  
	public:
	  DoublyCL();
	  void Display();
	  int Count();
	  void InsertFirst(T no);
	  void InsertLast(T no);
	  void InsertAtPos(T no,int iPos);
	  void DeleteFirst();
	  void DeleteLast();
	  void DeleteAtPos(int iPos);
	
};

// Return_Value Class_Name :: Function_Name(Parameters)

template <class T>
DoublyCL<T> ::DoublyCL()
	  {
		  first=NULL;
		  last=NULL;
		  size=0;
	  }

template <class T>
void DoublyCL<T> :: InsertFirst(T no)
{
	node<T> * newn=new node<T>;
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	if((first==NULL)&&(last==NULL))
	{
		first=newn;
		last=newn;
	}
	else
	{
		newn->next=first;
		first->prev=newn;
		first=newn;
	}
	last->next=first;
	first->prev=last;
	size++;
} 

template <class T>
void DoublyCL<T> :: InsertLast(T no)
{
	node<T> * newn=new node<T>;
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	if((first==NULL)&&(last==NULL))
	{
		first=newn;
		last=newn;
	}
	else
	{
		last->next=newn;
		newn->prev=last;
		last=newn;
	}
	last->next=first;
	first->prev=last;
	size++;
} 

template <class T>
void DoublyCL<T> :: Display()
{
	node<T> * temp=first;
	
	for(int i=1; i<=size; i++)
	{
		cout<<"|"<<temp->data<<"|->";
		temp=temp->next;
	}
	cout<<"\n";
}

template <class T>
int DoublyCL<T> :: Count()
{
	return size;
}

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
	if((first==NULL)&&(last==NULL))
	{
		return;
	}
	else if(first==last)
	{
		delete first;
		first==NULL;
		last==NULL;
	}
	else
	{
		first=first->next;
		delete first->prev;
		first->prev=last;
		last->next=first;
	}
	
	size--;
}

template <class T>
void DoublyCL<T> :: DeleteLast()
{
	if((first==NULL)&&(last==NULL))
	{
		return;
	}
	else if(first==last)
	{
		delete first;
		first==NULL;
		last==NULL;
	}
	else
	{
		last=last->prev;
		delete last->next;
		first->prev=last;
		last->next=first;
	}
	size--;
	
}

template <class T>
void DoublyCL<T> :: InsertAtPos(T no,int iPos)
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
		newn->prev=NULL;
		
		node<T> * temp=first;
		for(int i=1; i<iPos-1; i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
		size++;	
	}
}

template <class T>
void DoublyCL<T> :: DeleteAtPos(int iPos)
{
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
		node<T> * temp=first;
		
		for(int i=1; i<iPos-1; i++)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		delete temp->next->prev;
		temp->next->prev=temp;
		size--;
	}
}

//////////////////////////////////////////////////////////////
//
//	Entry Point Function
//
////////////////////////////////////////////////////////////

int main()
{

//////////////////////////////////////////////////////////////
//
//	Function Calls for Singly Linear Linked List
//
////////////////////////////////////////////////////////////
	int iret = 0;
	
	SinglyLL <char>cobj;
	
    cobj.InsertFirst('A');
    cobj.InsertFirst('B');
    cobj.InsertFirst('C');
    
    cobj.InsertLast('D');
    cobj.InsertLast('E');
    
    cobj.Display();
    
    iret = cobj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
    
	///////////////////////////
	
	SinglyLL <int>iobj;
	
    iobj.InsertFirst(11);
    iobj.InsertFirst(21);
    iobj.InsertFirst(51);
    
    iobj.InsertLast(101);
    iobj.InsertLast(111);
    
    iobj.Display();
    
    iret = iobj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
	
//////////////////////////////////////////////////////////////
//
//	Function Calls for Singly Circular Linked List
//
////////////////////////////////////////////////////////////
	int iRet = 0;
	
	SinglyCL <char>Cobj;
	
    Cobj.InsertFirst('A');
    Cobj.InsertFirst('B');
    Cobj.InsertFirst('C');
    
    Cobj.InsertLast('D');
    Cobj.InsertLast('E');
    
    Cobj.Display();
    
    iRet = Cobj.Count();
    cout<<"Number of elemensts are : "<<iRet<<"\n";
    
	///////////////////////////
	
	SinglyCL <int>Iobj;
	
    Iobj.InsertFirst(11);
    Iobj.InsertFirst(21);
    Iobj.InsertFirst(51);
    
    Iobj.InsertLast(101);
    Iobj.InsertLast(111);
    
    Iobj.Display();
    
    iRet = Iobj.Count();
    cout<<"Number of elemensts are : "<<iRet<<"\n";

//////////////////////////////////////////////////////////////
//
//	Function Calls for Doubly Linear Linked List
//
////////////////////////////////////////////////////////////
	int dRet = 0;
	
	DoublyLL <char>Cdobj;
	
    Cdobj.InsertFirst('A');
    Cdobj.InsertFirst('B');
    Cdobj.InsertFirst('C');
    
    Cdobj.InsertLast('D');
    Cdobj.InsertLast('E');
    
    Cdobj.Display();
    
    dRet = Cdobj.Count();
    cout<<"Number of elemensts are : "<<dRet<<"\n";
    
	///////////////////////////
	
	DoublyLL <int>Idobj;
	
    Idobj.InsertFirst(11);
    Idobj.InsertFirst(21);
    Idobj.InsertFirst(51);
    
    Idobj.InsertLast(101);
    Idobj.InsertLast(111);
    
    Idobj.Display();
    
    dRet = Idobj.Count();
    cout<<"Number of elemensts are : "<<dRet<<"\n";
	
	
//////////////////////////////////////////////////////////////
//
//	Function Calls for Doubly Circular Linked List
//
////////////////////////////////////////////////////////////
	int DRet = 0;
	
	DoublyCL <char>CDobj;
	
    CDobj.InsertFirst('A');
    CDobj.InsertFirst('B');
    CDobj.InsertFirst('C');
    
    CDobj.InsertLast('D');
    CDobj.InsertLast('E');
    
    CDobj.Display();
    
    DRet = CDobj.Count();
    cout<<"Number of elemensts are : "<<DRet<<"\n";
    
	///////////////////////////
	
	
	DoublyCL <int>IDobj;
	
    IDobj.InsertFirst(11);
    IDobj.InsertFirst(21);
    IDobj.InsertFirst(51);
    
    IDobj.InsertLast(101);
    IDobj.InsertLast(111);
    
    IDobj.Display();
    
    DRet = Idobj.Count();
    cout<<"Number of elemensts are : "<<DRet<<"\n";
	
	
    return 0;
}