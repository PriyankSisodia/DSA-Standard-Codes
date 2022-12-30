#include <climits>

template <typename T>

//creating LL node
class Node{
public:
	T data;
	//Node *next; without template
	Node<T> *next; // with template

	Node(T Data){//constructor
		this-> data = data;
		next = NULL;
	}
};

template <typename T> //before every class

class StackUsingLL {
	//Node *head; //Withoyt templaet
	Node<T> *head; //with template
	int size; //number of elements
public:
	StackUsingLL(){ //constructor
 		head =NULL;
 		size=0;
	}
	void printStack(){//print stack
		Node <T>* temp = head;
		while(temp->next!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<temp->data<<endl;
		delete temp;
		return ;
	}
	int getSize(){
		return size;
	}
	bool isEmpty(){
		return size==0;
	}
	void push(T element){
			//make a new node with dat
			Node<T> *newNode = new Node<T>(element);
			newNode->data = element;
			newNode->next=head;
			cout<<newNode->data<<" in"<<endl;

			head = newNode;
			size++;
			return ;
	}

	T pop(){
		//for anything always check base cases or corner cases
		if(isEmpty()){
			cout<<"NULL"<<endl;
			return 0;
		}
		Node <T>* de;
		de = head;
		T ele=head->data;
		head = head->next;
		size--;
		delete de;
		return ele;
	}
	T top(){
		if(isEmpty()){
			cout<<"NULL"<<endl;
			return 0;
		}
		return head->data;
	}


};