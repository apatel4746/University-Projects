#ifndef DEQUENODE_CPP
#define DEQUENODE_CPP


#include "DequeNode.h"
using namespace std;

namespace cs32 {

template <typename Type>
DequeNode<Type>::DequeNode( const Type& v,
                      DequeNode * node,
                      DequeNode * pre ):value(v), next(node), previous(pre) // :     // TODO: CS 32 Students to complete code here
{
    //value = v;
   // next = node;
   // previous = pre;
    
    // TODO: CS 32 Students to complete code here
}

template <typename Type>
Type DequeNode<Type>::getElement() const {

	return( value );//return value for getElement
}

template <typename Type>
DequeNode<Type> * DequeNode<Type>::getNext() const {
    // TODO: CS 32 Students to complete code here
    return next;//return next 
	
}

template <typename Type>
void DequeNode<Type>::setNext( DequeNode<Type> * node ) {
    // TODO: CS 32 Students to complete code here
    next = node;//next now node
    return;
}

template <typename Type>
DequeNode<Type> * DequeNode<Type>::getPrevious() const {
    // TODO: CS 32 Students to complete code here
    if (previous != nullptr) {
        return previous;//return previous if not nullptr else return nullptr
    }
    else {
        return(nullptr);
    }
   
}

template <typename Type>
void DequeNode<Type>::setPrevious( DequeNode<Type> * node ) {
    // TODO: CS 32 Students to complete code here
    previous = node;//set previous to node
    return;
}

}


#endif
