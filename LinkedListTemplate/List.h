template <typename T>
class List;

template <typename T>
class node
{
friend class List<T>;
public:
	//default constructor with no initial vale
	node() :next(NULL){}

	//constructor with initial value and next
	node(const T& item, node<T>* nextNode = NULL) : nodeValue(item), next(nextNode){}

private:
	T nodeValue;  //data held by node
	node<T>* next;
};

template <typename T>
class List
{
public:
	// constructors and destructor:
	List();
    List(const List<T>& obj);  // copy constructor for List
	~List();  //destructor

    // list operations:
   	void insertFront(const T& newItem);  //insert a new node at the front
   	void insertBack(const T& newItem);  //insert a new node at the back
   	T&  removeFront();//remove a node from the front and return node value
	void printList();  //print linked list

	//operator overload = assignment operator
    friend List& operator=(const List<T>& obj);

private:
	bool isEmpty() const;  //is list empty
	int size;              // number of items in list
	node<T> *head;         // pointer to linked list of items

}; // end class

//implementation starts here
template <typename T>
List<T>::List(){                    //creates list with start and end as NULL
	head = NULL;
	size = 0;
}

template <typename T>
List<T>::List(const List<T>& obj){  // Copy Constructor
    size=aList.size;
	if (aList.head == NULL)
        head = NULL; // original list is empty
	else   {  // copy first node
        head = new ListNode;
		head->item = aList.head->item;
		// copy rest of list
		ListNode *newPtr = head; // new list pointer
		for (ListNode *origPtr = aList.head->next; origPtr != NULL; origPtr = origPtr->next){
		    newPtr->next = new ListNode;
			newPtr = newPtr->next;
			newPtr->item = origPtr->item;
		} // end for
		newPtr->next = NULL;
    } // end else
}

template <typename T>
void List<T>::insertFront(const T& newItem){
    node* newNode = new node;
    node* currentNode = head;
    newNode->nodeValue = newItem;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        size += 1;
    }
    else{
        newNode->next = head->next;
        head = newNode;
        size+=1;
    }
}

template <typename T>
void List<T>::insertBack(const T& newItem){

    size += 1;
}

template <typename T>
T&  List<T>::removeFront(){

    size -=1;
}

template <typename T>
void List<T>::printList(){

}

template <typename T>
List<T>& List<T>::operator=(const List<T>& aList){  // = operator overloading
	if (this != &aList){
		size=aList.size;
		if (aList.head == NULL)   // original list is empty
			head = NULL;
		else   {                  // copy first node
			head = new ListNode;
			head->item = aList.head->item;
        }
	    // copy rest of list
		ListNode *newPtr = head; // new list pointer
		for (ListNode *origPtr = aList.head->next; origPtr != NULL;origPtr = origPtr->next){
			newPtr->next = new ListNode;
		    newPtr = newPtr->next;
			newPtr->item = origPtr->item;
		} // end for
	    newPtr->next = NULL;
	} // end if

	return *this;
};

template <typename T>
bool List<T>::isEmpty() const{
    return (head == NULL);
}
