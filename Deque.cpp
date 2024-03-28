#ifndef DEQUE_CPP
#define DEQUE_CPP

#include "Deque.h"
#include <string>
#include <sstream>

using namespace std;

namespace cs32 {

template <typename Type>
Deque<Type>::Deque():head(nullptr), tail(nullptr) // :      // TODO: CS 32 Students to complete code here
{
    
    // TODO: CS 32 Students to complete code here
}

template <typename Type>
Deque<Type>::Deque( const Deque& rhs ) {
    if (rhs.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = new DequeNode<Type>( rhs.head->getElement() );
        tail = head;
        DequeNode<Type> *q = head;
        DequeNode<Type> *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new DequeNode<Type>( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            q->getNext()->setPrevious( q );
            tail = q->getNext();
            p = p->getNext();
            q = q->getNext();
        }
    }
}

template <typename Type>
Deque<Type>::~Deque() {
	makeEmpty();
}

template <typename Type>
bool Deque<Type>::isEmpty() const {
    // TODO: CS 32 Students to complete code here
    if (head == nullptr && tail == nullptr) {
        return true;//deque empty when head and tail are nullptr else not empty
    }
       
    else {
        return(false);
    }
    
}

template <typename Type>
void Deque<Type>::makeEmpty() {
  //  DequeNode<Type>* currentNode = head;
    while (!isEmpty()) {
       //repeatdely call delete front
        deleteFront();
    }
    
    // TODO: CS 32 Students to complete code here
}

template <typename Type>
void Deque<Type>::addToFront( const Type & data )
{
    DequeNode<Type>* newNode = new DequeNode<Type>(data) ;
    if (head == nullptr && tail == nullptr) {
        head = newNode;//same as rear set head to tail same node if deque empty
        tail = newNode;
        return;
    }
    else {
        newNode->setNext(head);//set newnode next pointer to head
        head->setPrevious(newNode);//set head's previous pointer to newNode
        head = newNode;//head now newNode
        return;
        
    }
    
    
    // TODO: CS 32 Students to complete code here
}

template <typename Type>
void Deque<Type>::addToRear( const Type & data )
{
    DequeNode<Type>* newNode = new DequeNode<Type>(data);
    if (isEmpty()) {//if deque empty set head and tail to new node value
        head = newNode;
        tail = newNode;
        return;
    }

   
    else {
        
        tail->setNext(newNode);//set tail's next node to new node
        newNode->setPrevious(tail);//make sure new node previous pointer points to tail
        tail = newNode;//tail equal to newnode
        return;

    }
    // TODO: CS 32 Students to complete code here
}

template <typename Type>
void Deque<Type>::deleteFront( )
{
    
    DequeNode<Type>* oldHead = head;
    if (!isEmpty()) {
        if (head == tail) { //if only one node set head and tail to nullptr and delete what store head in
            head = nullptr;
            tail = nullptr;
            delete oldHead;
            return;
        }
        else {
            head = head->getNext();//set new head to head's next node then delete stored head
            delete oldHead;
            return;
        }
   }
   
    
    /*if (head == nullptr && tail = nullptr) {
        return;
    }
        
    else if (head != nullptr) { //come back here if any issues
        head = head->getNext();
        delete oldHead;
        head->setPrevious(nullptr);
        return;
    }*/
        
    
    
    // TODO: CS 32 Students to complete code here
}

template <typename Type>
bool Deque<Type>::deleteItem( const Type & data )
{
    bool result = false;
    DequeNode<Type>* currentnode = head;//create two pointers one that initially points to head and the other that points nullptr
    DequeNode<Type>* priornode = nullptr;
    while (currentnode != nullptr) {//don't delete if currentnode is nullptr
        if (currentnode->getElement() == data)//when find node whose element matches data
        {
            if (priornode == nullptr) {//if current node is head call deleteFront and return true
                deleteFront();
                return true;
                
                
            }
            else if (currentnode == tail) {//if currentNode is tail call deleteRear and return true
                deleteRear();
                return true;
            }
            else {
                priornode->setNext(currentnode->getNext());//make sure priornode's next pointer is set to currentNode's next node
                priornode->getNext()->setPrevious(priornode);//make sure priornode's next node previous pointer points to priornode
               // head= currentnode->getNext();
                
                /*
                currentnode->setPrevious(priornode);
                deleteFront();
                */
                
                
                //head = currentnode->getNext();
               // head->setNext(currentnode->getNext());
              //  head->setPrevious(nullptr);
               
                
            }
            delete(currentnode);//delete currentnode for the else case then return true
            return true;
        }
        priornode = currentnode;//
        currentnode = currentnode->getNext();
    //if did not find a match set priornode to currentnode and current node to currentnode getnext
    }

    // TODO: CS 32 Students to complete code here

    return( result);
}


template <typename Type>
Type Deque<Type>::front( ) const
{
    Type result = Type();
    DequeNode<Type>* currentNode= head;
    if (currentNode != nullptr)//guard make sure don't access nullptr if not nullptr get that node's element
        return (currentNode->getElement());
    else
        return result;//prevent a break
    //Type result = Type();
   
    // TODO: CS 32 Students to complete code here
   // return( result );
}

template <typename Type>
Type Deque<Type>::rear( ) const
{
    Type result = Type();
    DequeNode<Type>* currentNode = tail;
    if (currentNode != nullptr)//if tail is not nullptr get the tail's element and return it
    return (currentNode->getElement());
    else
        return result;//guard against breaking
    //Type result = Type();
    // TODO: CS 32 Students to complete code here

   // return( result );
}

template <typename Type>
void Deque<Type>::deleteRear( )
{
    if (!isEmpty()) {
        DequeNode<Type>* oldTail = tail;
        if (head == tail) {//case when there is only one node set head and tail to nullptr
            head = nullptr;
            tail = nullptr;
            delete oldTail;//delete the oldtail
            return;
        }
       
        else {
            tail = tail->getPrevious();//make sure the previous node is new tail
            tail->setPrevious(tail->getPrevious()); //set tails previous pointer to tail's previous node
            tail->setNext(nullptr);//set tails next to nullptr

            delete oldTail;//delete oldTail
            return;
        }

   }
   /* if (isEmpty()) {
        return;
    }
    else if (head == tail) {
        head = nullptr;
        tail = nullptr;
        return;
    }

    DequeNode<Type>* oldTail = tail;
    
        tail = tail->getPrevious();
        tail->setPrevious(tail->getPrevious());
        tail->setNext(nullptr);

        delete oldTail;
        return;
    */

    // TODO: CS 32 Students to complete code here

}

// Howard is supplying code to convert a Type to a string using its operator <<
template <typename Type>
std::string Deque<Type>::to_string( const Type & value ) const
{
    stringstream s;
    // call the Type's operator <<
    s << value;
    return( s.str() );
}


template <typename Type>
std::string Deque<Type>::printItems( ) const
{
    DequeNode<Type>* currentNode = head;
   

    string s="";
    if (isEmpty()) {
        s = "Empty dequeue";//empty deque returns empty this
        return s;
    }
    else {
       
        while (currentNode != nullptr) {//as long as we don't reach nullptr just concatenate the strings and add a space
            
           s += to_string(currentNode->getElement());
           s += " ";
            currentNode = currentNode->getNext();
        }
        // TODO: CS 32 Students to complete code here
    }
    
    return(s);
}


// Deep copy of linked list
template <typename Type>
const Deque<Type> & Deque<Type>::operator =( const Deque<Type> & rhs ) {
    // TODO: CS 32 Students to complete code here
    if (this != &rhs) {
        makeEmpty();//first clear out the deque
        DequeNode<Type> * right= rhs.head;//set right node to the parameter's head
        while (right != nullptr) {
            addToRear(right->getElement());//get rhs element store it into right Deque
            right = right->getNext();//traverse rhs Deque
        }
    }

	return( *this );
}

template <typename Type>
size_t Deque<Type>::size() const
{
    size_t result = 0;
    if (isEmpty()) {//size empty return 0
        return 0;
    }
    DequeNode<Type>* currentNode = head;
    while(currentNode!=nullptr){//if there are nodes that are not nullptr
        result++;//increment result
        currentNode = currentNode->getNext();//go to the next node;
       
    
    }
   // TODO: CS 32 Students to complete code here
    return( result );
}


template <typename Type>
bool   Deque<Type>::get( int i, Type & data ) const
{
    bool result = false;
    DequeNode<Type>* currentNode = head;
    int index = 0;
    while (currentNode != nullptr) {
        if ((index == i)) {//if index is equal to i parameter
           data = currentNode->getElement(); //set data to current node's element
            result = true;//result set to true

            break;//exit loop
        }
        currentNode = currentNode->getNext();
        index++;//incrment index after going to next node
    }

    // TODO: CS 32 Students to complete code here

    return( result );
}

template <typename Type>
bool Deque<Type>::findData(const Type& data) const
{
   // bool result = false;
    DequeNode<Type>* currentNode = head;
    
    while (currentNode != nullptr) {
        if (currentNode->getElement()==data) {
            return true;//if find match for data return true
        }
        currentNode = currentNode->getNext();//go to next node
        
    }

    // TODO: CS 32 Students to complete code here

    return(false);
}

}


#endif
