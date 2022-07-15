// #include "vector.hpp"
#include "map.hpp"
#include "utils.hpp"
#include "vector0.hpp"
#include "stack.hpp"
#include "set.hpp"
#include <stack>
#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>
#include <map>
#include <ctime>
#include <iostream>
#include <chrono>
#include <unistd.h>

int main(void)
{
	//=================================================================
	//==============          vector          ==============
	//=================================================================
	 std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

	std::vector<int> stdvector;
	for(int i = 0; i < 200000; i++)
		stdvector.push_back(i);
	for(int i = 0; i < 200000; i++)
  		stdvector.pop_back();
	std::chrono::time_point<std::chrono::system_clock> endstd = std::chrono::system_clock::now();
	int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(endstd - start).count();
	std::cout << "std::elapsed time: " << elapsed_seconds << "milliseconds" << std::endl;
	ft::vector<int> ftvector;
    for(int i = 0; i < 200000; i++)
	   ftvector.push_back(i);
    for(int i = 0; i < 200000; i++)
	   ftvector.pop_back();
   std::chrono::time_point<std::chrono::system_clock> endft = std::chrono::system_clock::now();
   elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(endft - endstd).count();
   std::cout << "ft::elapsed time: " << elapsed_seconds << "milliseconds" << std::endl;
	 //=================================================================
	 //==============           iterator_vector          ==============
	 //=================================================================
   for(int i = 0; i < 20; i++)
		ftvector.push_back(i);
   for(ft::vector<int>::iterator ftiter = ftvector.begin(); ftiter < ftvector.end(); ftiter++)
	   std::cout << *ftiter << std::endl ;

	 //=================================================================
  	 //==============           const_iterator_vector          ==============
  	 //=================================================================

   for(ft::vector<int>::const_iterator ftiter = ftvector.begin(); ftiter < ftvector.end(); ftiter++)
   {

	   std::cout << *ftiter << std::endl ;
	    //*ftiter = 1;
   }
   //=================================================================
   //==============           surcharge		            ==============
   //=================================================================
    std::cout << "surcharge : "<< std::endl ;
   ft::vector<int>::const_iterator ftiter = ftvector.end();
   ftiter--;
   std::cout << *(ftiter) << std::endl ;
   ++ftiter;
   std::cout << *(ftiter) << std::endl ;
   --ftiter;
   std::cout << *(ftiter) << std::endl ;
   for(int i = 0; i < 20; i++)
		stdvector.push_back(i);

	std::vector<int>::const_iterator stditer = stdvector.end();
	stditer--;
    std::cout << *(stditer) << std::endl ;
    ++stditer;
    std::cout << *(stditer) << std::endl ;
    --stditer;
	std::cout << *(ftiter) << std::endl ;
   //=================================================================
   //==============           swap			            ==============
   //=================================================================
	ft::vector<int> foo (3,100);
	foo.swap(ftvector);
	std::cout << "swap : " << std::endl ;
	for(ft::vector<int>::iterator ftiter = ftvector.begin(); ftiter < ftvector.end(); ftiter++)
 	   std::cout << *ftiter << std::endl ;

   //=================================================================
   //======================================       map     ========================================
   //=================================================================
	ft::map<char,int> mymap;
	for(int i = 65; i < 127; i++)
		mymap.insert ( ft::pair<char,int>(i,100 + i) );

   ft::pair<ft::map<char,int>::iterator,bool> ret;
   ret = mymap.insert ( ft::pair<char,int>('z',500) );
   if (ret.second==false) {
     std::cout << "element 'z' already existed";
     std::cout << " with a value of " << ret.first->second << '\n';
   }


   ft::map<char,int>::iterator it = mymap.begin();
   mymap.insert (it, ft::pair<char,int>('b',300));
   mymap.insert (it, ft::pair<char,int>('c',400));


   ft::map<char,int> anothermap;
   anothermap.insert(mymap.begin(),mymap.find('c'));
   //=================================================================
   //==============         iterator_map         ==============
   //=================================================================

   std::cout << "mymap contains:\n";
   for (it=mymap.begin(); it!=mymap.end(); ++it)
     std::cout << it->first << " => " << it->second << '\n';

   std::cout << "anothermap contains:\n";
   for (it=anothermap.begin(); it!=anothermap.end(); ++it)
     std::cout << it->first << " => " << it->second << '\n';

	//=================================================================
	//==============         swap        ==============
	//=================================================================
	ft::map<char,int> fo;

	  fo['x']= 100;
	  fo['y']= 200;

    fo.swap(anothermap);
	std::cout << "anothermap contains after swap:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';
	fo.swap(anothermap);
	//=================================================================
	//==============         find        ==============
	//=================================================================
	it = anothermap.find('A');
	if (it != mymap.end())
	    anothermap.erase (it);
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';
	 std::cout << "anothermap contains after swap:\n";
	 // anothermap.at('B') = 10;
	 it = anothermap.find('B');
	 std::cout << it->first << " => " << it->second << '\n';

	//=================================================================
 	//==============         operator[]       ==============
    //=================================================================
	  anothermap['B']=3;

	  std::cout <<  anothermap['B'] << std::endl;
	  std::cout << anothermap.size() << std::endl;
	  std::cout << anothermap['A'] << std::endl;
	  std::cout << anothermap.size() << std::endl;

 //=================================================================
 //======================================    stack   ========================================
 //=================================================================
	std::cout << "Stack";
 	ft::stack<int> mystack;

   for (int i=0; i<100; ++i) mystack.push(i);

   std::cout << "size: " << mystack.size() << '\n';
   std::cout << "Popping out elements...";

   while (!mystack.empty())
   {
      std::cout << ' ' << mystack.top();
      mystack.pop();
   }
   std::cout << "\nfinit\n";

//=================================================================
//======================================      set      ========================================
//=================================================================

  // ft::set<int> myset;
  // ft::set<int>::iterator it3;
  // ft::pair<ft::set<int>::iterator,bool> ret2;
  //
  // // set some initial values:
  // for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50
  //
  // ret2 = myset.insert(20);               // no new element inserted
  //
  // if (ret2.second==false) it3=ret2.first;  // "it" now points to element 20
  //
  // myset.insert (it3,25);                 // max efficiency inserting
  // myset.insert (it3,24);                 // max efficiency inserting
  // myset.insert (it3,26);                 // no max efficiency inserting
  //
  // int myints[]= {5,10,15};              // 10 already in set, not inserted
  // myset.insert (myints, myints+3);
  //
  // std::cout << "myset contains:";
  // for (it3=myset.begin(); it3!=myset.end(); ++it)
  //   std::cout << ' ' << *it3;
  // std::cout << '\n';

}
