#include "Garage.h"

namespace cs32
{


Garage::Garage( size_t capacity ) // :       // TODO: CS 32 Students to complete code here
{
    mCapacity = capacity;
    // TODO: CS 32 Students to complete code here
}

// put something in the garage
// silently, it purges something once the garage is full
bool Garage::tossIn( std::string s )
{
    if (mDeque.size() < mCapacity) {
        mDeque.addToFront(s);//add to front if size less than capacity
        return false;
    }
    else {
        mDeque.deleteRear();//delete from rear and add to front if capacity met or exceeds
        mDeque.addToFront(s);
        return true;

    }
    // TODO: CS 32 Students to complete code here

    return( false );
}

bool Garage::tossOut( std::string s )
{
    return mDeque.deleteItem(s);// call deque's deleteItem function
    // TODO: CS 32 Students to complete code here

    return( false );
}


// use something from the garage
// must be findable, then moved to the used pile
bool Garage::use( std::string s )
{
    if (mDeque.deleteItem(s)) {
        mDeque.deleteItem(s);//deleteItem and add to front if its in deque
        mDeque.addToFront(s);
        return true;
    }
    
    // TODO: CS 32 Students to complete code here

    return( false );
}

// is it in the garage?
bool Garage::find( std::string s )
{
    if (mDeque.findData(s)) {
        return true;//if can find node with s return true else return false
    }
    else {
        return false;
    }
        

    // TODO: CS 32 Students to complete code here

   // return( false );
}

// how much can this garage maximally hold?
size_t Garage::capacity()
{
    return mCapacity;
    // TODO: CS 32 Students to complete code here

    //return( 0 );
}
// how much is in this garage right now?
size_t Garage::size( )
{
    return mDeque.size();//call deque size
    // TODO: CS 32 Students to complete code here

    //return( 0 );
}

std::string Garage::printItems( )
{
    return mDeque.printItems();//call deque printitems
    // TODO: CS 32 Students to complete code here

    
}


}
