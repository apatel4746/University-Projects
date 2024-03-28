// Menu.cpp : Defines the entry point for the console application.
//

/*#include <iostream>
#include <string>
#include <cassert>
#include "Deque.h"
#include "Deque.cpp"
#include "DequeNode.h"
#include "DequeNode.cpp"
#include "Garage.h"




int main()
{
    using namespace std;
    using namespace cs32;
    
    // TODO: CS 32 students should add testing code here
    DequeNode< int > sampleNode( 5 );
    Deque< string > sampleDeque;
    Deque< int > otherDeque;
    Garage g;
    Garage otherg( 12 );
    
    cout << "all tests passed!" << endl;
    
    return( 0 );
}
*/
#include <iostream>
#include <string>
#include <cassert>
#include "DequeNode.h"
#include "DequeNode.cpp"
#include "Deque.h"
#include "Deque.cpp"
#include "Garage.h"

int main()
{
    using namespace std;
    using namespace cs32;


    // Deque Tests

    Deque< int > dInt;
    int x;
    Deque< std::string > dString;
    std::string s;

    dInt.deleteFront();
    dInt.deleteRear();
    x = 12;
    assert(dInt.deleteItem(x) == false);
    assert(dInt.size() == 0);
    assert(dInt.get(-10, x) == false);
    assert(dInt.isEmpty());

    s = "Hello";
    dString.addToFront(s);
    s = "World!";
    dString.addToRear(s);
    s = "Howard";
    assert(dString.deleteItem(s) == false);
    assert(dString.size() == 2);//this test case does not work
    assert(dString.get(-10, s) == false);
    assert(dString.isEmpty() == false);
    assert(dString.get(0, s) && s == "Hello");
    assert(dString.get(1, s) && s == "World!");
    dString.deleteFront();
    s = "Hello";
    assert(dString.deleteItem(s) == false);
    assert(dString.size() == 1);
    assert(dString.get(0, s) && s == "World!");
    assert(dString.isEmpty() == false);
    dString.deleteRear();
    s = "World!";
    assert(dString.deleteItem(s) == false);
    assert(dString.size() == 0);
    assert(dString.get(0, s) == false);
    cout << s << endl;
    assert(dString.isEmpty());

    // Garage Tests
    Garage g;
    Garage gSix(6);

    assert(g.size() == 0);
    assert(g.capacity() == 10);

    assert(gSix.size() == 0);
    assert(gSix.capacity() == 6);
    gSix.tossIn("shoes");
    gSix.tossIn("shirts");
    gSix.tossIn("books");
    assert(gSix.size() == 3);
    assert(gSix.capacity() == 6);
    gSix.tossIn("suitcases");
    assert(gSix.tossIn("tables") == false);  // nothing thrown away
    assert(gSix.tossIn("chairs") == false);  // nothing thrown away
    assert(gSix.size() == 6);
    assert(gSix.capacity() == 6);
    assert(gSix.find("shoes"));
    assert(gSix.find("shirts"));
    assert(gSix.find("books"));
    assert(gSix.find("suitcases"));
    assert(gSix.find("tables"));
    assert(gSix.find("chairs"));

    assert(gSix.tossIn("boxes"));  // shoes thrown away...
    assert(gSix.size() == 6);
    assert(gSix.capacity() == 6);
    assert(gSix.find("boxes"));
    assert(gSix.find("shoes") == false);
    assert(gSix.find("shirts"));
    assert(gSix.find("books"));
    assert(gSix.find("suitcases"));
    assert(gSix.find("tables"));
    assert(gSix.find("chairs"));

    assert(gSix.tossOut("shoes") == false);   // shoes not found...
    assert(gSix.use("shoes") == false);       // shoes not found...
    assert(gSix.use("tables"));

    assert(gSix.tossIn("records"));     // shirts thrown away...
    assert(gSix.size() == 6);
    assert(gSix.capacity() == 6);
    assert(gSix.find("records"));
    assert(gSix.find("tables"));
    assert(gSix.find("boxes"));
    assert(gSix.find("shoes") == false);
    assert(gSix.find("shirts") == false);
    assert(gSix.find("books"));
    assert(gSix.find("suitcases"));

    assert(gSix.tossOut("books"));
    assert(gSix.tossOut("records"));
    assert(gSix.tossOut("shoes") == false);
    assert(gSix.size() == 4);
    assert(gSix.capacity() == 6);
    assert(gSix.find("records") == false);
    assert(gSix.find("tables"));
    assert(gSix.find("chairs"));
    assert(gSix.find("boxes"));
    assert(gSix.find("shoes") == false);
    assert(gSix.find("shirts") == false);
    assert(gSix.find("books") == false);
    assert(gSix.find("suitcases"));

    assert(gSix.tossOut("tables"));
    assert(gSix.tossOut("boxes"));
    assert(gSix.tossOut("suitcases"));
    assert(gSix.size() == 1);
    assert(gSix.capacity() == 6);
    assert(gSix.find("records") == false);
    assert(gSix.find("tables") == false);
    assert(gSix.find("boxes") == false);
    assert(gSix.find("shoes") == false);
    assert(gSix.find("shirts") == false);
    assert(gSix.find("books") == false);
    assert(gSix.find("suitcases") == false);
    assert(gSix.find("chairs"));

    Garage g2;
    assert(g2.tossOut("rice") == false);
    g2.tossIn("candle");
    g2.tossIn("rice");
    g2.tossIn("snake");
    g2.tossIn("bike");
    g2.tossIn("cake");
    g2.tossIn(" ");
    //g2.use("candle");
    assert(g2.use("candle") == true);
    assert(g2.use("ring") == false);
    assert(g2.use("life") == false);
    assert(g2.use("fork") == false);
    assert(g2.use(" ") == true);
    cout << g2.capacity() << endl;
    assert(g2.capacity() == 10);
    assert(g2.use("my will to live") == false);
    assert(g2.find("rice") == true);
    assert(g2.tossOut("rice") == true);
    assert(g2.find("rice") == false);
    g2.tossIn("my brother");
    g2.tossIn("coconut");
    g2.tossIn("banana");
    assert(g2.size() == 8);
    g2.tossIn("basketball");
    g2.tossIn("lawn mower");
    assert(g2.tossIn("rake") == true);
    cout << g2.printItems() << endl;
    assert(g2.size() == 10);
    assert(g2.tossIn("candle") == true); //adding in a duplicate and seeing if it tosses out rear element to make room for new one
    cout << g2.printItems() << endl;
    assert(g2.find("candle") == true);
    assert(g2.tossOut("candle") == true);//should get rid of the first candle
    cout << g2.printItems() << endl;
    assert(g2.find("candle") == true);
    assert(g2.capacity() == 10);
    assert(g2.size() == 9);
    assert(g2.tossOut("basketball") == true);
    cout << g2.printItems() << endl;
    assert(g2.size() == 8);
    assert(g2.tossOut("cake") == true);
    cout << g2.printItems() << endl;
    assert(g2.size() == 7);
    assert(g2.tossOut("banana") == true);
    assert(g2.size() == 6);
    cout << g2.printItems() << endl;

    Deque< std::string > d2String;
    string s2 = "";
    assert(d2String.isEmpty() == true);
    assert(d2String.deleteItem(s2) == false);
    s2 = "Katara";
    d2String.addToFront(s2);
    s2 = "Sokka";
    d2String.addToRear(s2);
    s2 = "Aang";
    d2String.addToFront(s2);
    cout << d2String.printItems() << endl;
    assert(d2String.front() == "Aang");
    assert(d2String.rear() == "Sokka");
    assert(d2String.get(6, s2) == false);
    assert(d2String.get(0, s2) && s2 == "Aang");
    assert(d2String.get(7, s2) == false && s2 == "Aang");
    assert(d2String.get(1, s2) && s2 == "Katara");
    assert(d2String.get(8, s2) == false && s2 == "Katara");
    assert(d2String.get(2, s2) && s2 == "Sokka");
    
    cout << s2 << endl;
    assert(d2String.get(3, s2)==false && s2 == "Sokka"); //this test case does not work
    d2String.makeEmpty();
    assert(d2String.isEmpty() == true);
    assert(d2String.deleteItem(s2) == false);
    assert(d2String.deleteItem(s) == false);
    cout << d2String.printItems() << endl;

    Deque< std::string > d3String;
    string s3 = "";
    assert(d3String.isEmpty() == true);
    assert(d3String.size() == 0);
    assert(d3String.deleteItem(s3) == false);
    s3 = "why";
    d3String.addToFront(s3);
    assert(d3String.front() == "why");
    assert(d3String.rear() == "why");
    assert(d3String.size() == 1);
    assert(d3String.deleteItem(s3) == true);
    cout << d3String.printItems() << endl;

    Deque<char > chDeque;
    char c1 = 'a';
    assert(chDeque.isEmpty() == true);
    assert(chDeque.size() == 0);
    assert(chDeque.deleteItem(c1) == false);
    chDeque.deleteFront();
    chDeque.deleteRear();
    chDeque.addToFront(c1);
    assert(chDeque.isEmpty() == false);
    cout << chDeque.printItems() << endl;
    assert(chDeque.size() == 1);
    chDeque.deleteFront();
    cout << chDeque.printItems() << endl;
    assert(chDeque.size() == 0);

    Deque<char > ch2Deque;
    char c2 = 'b';
    assert(ch2Deque.isEmpty() == true);
    assert(ch2Deque.size() == 0);
    assert(ch2Deque.deleteItem(c2) == false);
    ch2Deque.addToFront(c2);
    cout << ch2Deque.printItems() << endl;
    assert(ch2Deque.size() == 1);
    ch2Deque.deleteRear();
    cout << ch2Deque.printItems() << endl;
    assert(ch2Deque.size() == 0);

    Deque<string> strDeq= dString;
    string s4 = "cat";
    strDeq.addToFront(s4);
    assert(strDeq.get(0,s3));
    cout << s3 << endl;

    cout << strDeq.printItems() << endl;
    cout << dString.printItems() << endl;

    Deque<string> str3Deq;
    string s6 = "Julie";
    string s7 = "Scott";
    string s8 = "Wallace";
    string s9 = "Knives";
    str3Deq.addToFront(s6);
    str3Deq.addToFront(s7);
    str3Deq.addToFront(s8);
    str3Deq.addToFront(s9);

    Deque<string> str4Deq= str3Deq;

   


    Deque<string> str2Deq;
    string s5 = "lena";
    str2Deq.addToFront(s5);
    s5 = "Riya";
    str2Deq.addToRear(s5);
    s5 = "Ella";
    str2Deq.addToRear(s5);
    s5 = "Tooks";
    str2Deq.addToFront(s5);
    cout << str2Deq.printItems() << endl;
    str2Deq = str3Deq;
    cout << str3Deq.printItems() << endl;
    cout << str2Deq.printItems() << endl;
    s5 = "Salim";
    str2Deq.addToFront(s5);
    cout << str3Deq.printItems() << endl;
    cout << str2Deq.printItems()<<" added Salim to strDeq2" << endl;
    str3Deq.deleteFront();
    cout << str3Deq.printItems()<<" deleted front" << endl;
    cout << str2Deq.printItems() << endl;
    str2Deq = dString;
    cout << str2Deq.printItems()<<" str2Deq should be empty now dString empty" << endl;
    cout << dString.printItems() << endl;
    str2Deq.addToFront(s5);
    cout << str2Deq.printItems() << endl;
    cout << dString.printItems() << endl;
    dString.addToFront(s6);
    cout << str2Deq.printItems() << endl;
    cout << dString.printItems() << endl;
    str2Deq = str2Deq; 
    cout << str2Deq.printItems()<<" self assignment" << endl;
    cout << str2Deq.printItems() << endl;
    d2String = str2Deq;
    cout << str2Deq.printItems() << endl;
    cout << d2String.printItems() << endl;

    Garage g3(0);
   assert( g3.tossIn("candle")==true);
   assert(g3.tossIn("lena") == true);

  
   
   Garage g8(6);
   assert(g8.capacity() == 6);
   g8.tossIn("horses");
   g8.tossIn("wipes");
   g8.tossIn("toilet paper");
   g8.tossIn("fridge");
   cout << g8.printItems() << endl;
   assert(g8.tossIn("clorox") == false);
   assert(g8.tossIn("apple") == false);
   cout << g8.printItems() << endl;
   assert(g8.tossIn("freezer") == true);
   cout << g8.printItems() << endl;
   assert(g8.size() == 6);
   assert(g8.capacity() == 6);
   assert(g8.find("clorox") == true);
   assert(g8.tossOut("freezer") == true);
   assert(g8.tossOut("my will to live") == false);
   assert(g8.tossOut("my bike") == false);
   assert(g8.size() == 5);
   assert(g8.find("freezer") == false);
   assert(g8.find("my will to live") == false);
   assert(g8.capacity() == 6);
   assert(g8.tossOut("clorox") == true);
   assert(g8.size() == 4);
   assert(g8.capacity() == 6);
   cout << g8.printItems() << endl;
   assert(g8.tossOut("apple") == true);
   assert(g8.size() == 3);
   assert(g8.capacity() == 6);
   cout << g8.printItems() << endl;

   string ss = "star";
   string s10 = "key";
   Deque<string> str10Deq;

   str10Deq.addToFront(s10);
   assert(str10Deq.get(0, ss));
   cout << ss << " Please print out key" << endl;


    //okay I think my assignment operator is working properly
    //My assignment operator is not working






    /*
    s = "Hello";
    dString.addToFront(s);
    s = "World!";
    dString.addToRear(s);
    s = "Howard";
    assert(dString.deleteItem(s) == false);
    assert(dString.size() == 2);//this test case does not work
    assert(dString.get(-10, s) == false);
    assert(dString.isEmpty() == false);
    assert(dString.get(0, s) && s == "Hello");
    assert(dString.get(1, s) && s == "World!");
    dString.deleteFront();
    s = "Hello";
    assert(dString.deleteItem(s) == false);
    assert(dString.size() == 1);
    assert(dString.get(0, s) && s == "World!");
    assert(dString.isEmpty() == false);
    dString.deleteRear();
    s = "World!";
    assert(dString.deleteItem(s) == false);
    assert(dString.size() == 0);
    assert(dString.get(0, s) == false);
    assert(dString.isEmpty());
    */








   



    cout << "all tests passed!" << endl;
    return(0);
}

