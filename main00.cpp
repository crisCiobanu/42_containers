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
	std::chrono::time_point<std::chrono::system_clock> mapstdstart = std::chrono::system_clock::now();
	std::map<int, int> stdmap;
	for(int i = 0; i <10000000; i++)
		stdmap.insert ( std::pair<int,int>(i, i+1) );
	// for(int i = 0; i <10000000; i++)
	// 	stdmap.erase(i);
	std::chrono::time_point<std::chrono::system_clock> mapstdend = std::chrono::system_clock::now();
	elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(mapstdend - mapstdstart).count();
	std::cout << "std::elapsed time: " << elapsed_seconds << "milliseconds" << std::endl;
	std::chrono::time_point<std::chrono::system_clock> mapftstart = std::chrono::system_clock::now();
	ft::map<int,int> ftmap;
	for(int i = 0; i <10000000; i++)
		ftmap.insert ( ft::pair<int,int>(i, i+1) );
	// for(int i = 0; i <10000000; i++)
	// 	ftmap.erase(i);
	std::chrono::time_point<std::chrono::system_clock> mapftend = std::chrono::system_clock::now();
	elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(mapftend - mapftstart).count();
	std::cout << "ft::elapsed time: " << elapsed_seconds << "milliseconds" << std::endl;

	std::chrono::time_point<std::chrono::system_clock> mapstdstartfind = std::chrono::system_clock::now();
	long long int stdsum = 0;
	for(int i = 0; i <50000; i++)
	{
		stdsum += stdmap.find(i) -> first;
		stdsum += stdmap.find(i+700000) -> first;
	}
	std::chrono::time_point<std::chrono::system_clock> mapstdendfind = std::chrono::system_clock::now();
	elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(mapstdendfind - mapstdstartfind).count();
	std::cout << "std find ::elapsed time: " << elapsed_seconds << "milliseconds" << " the sum is : " << stdsum << std::endl;

	std::chrono::time_point<std::chrono::system_clock> mapftstartfind = std::chrono::system_clock::now();
	long long int ftsum = 0;
	for(int i = 0; i < 50000; i++)
	{
		ftsum += ftmap.find(i) -> first;
		ftsum += ftmap.find(i+700000) -> first;
	}
	std::chrono::time_point<std::chrono::system_clock> mapftendfind = std::chrono::system_clock::now();
	elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(mapftendfind - mapftstartfind).count();
	std::cout << "ft find ::elapsed time: " << elapsed_seconds << "milliseconds" << " the sum is : " << ftsum << std::endl;

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
   // for (it=anothermap.begin(); it!=anothermap.end(); ++it)
   //   std::cout << it->first << " => " << it->second << '\n';
   anothermap.printTree();

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
	ft::stack<int> mystack2;
   for (int i=0; i<100; ++i) mystack.push(i);

   std::cout << "size: " << mystack.size() << '\n';
   std::cout << "Popping out elements...";
 	mystack2=mystack;
   while (!mystack.empty())
   {
      std::cout << ' ' << mystack.top();
      mystack.pop();
   }
   std::cout << "\negalité\n";
	ft::stack<int> mystack3(mystack2);
   while (!mystack2.empty())
   {
      std::cout << ' ' << mystack2.top();
      mystack2.pop();
   }
   std::cout << "\nrecopie\n";
   while (!mystack3.empty())
   {
      std::cout << ' ' << mystack3.top();
      mystack3.pop();
   }
   std::cout << "\nfinit\n";

//=================================================================
//======================================      set      ========================================
//=================================================================

  ft::set<int> myset;

  // set some initial values:
  for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

  std::cout << "myset contains:";
   ft::set<int>::iterator it3;

  for (it3 = myset.begin(); it3 != myset.end(); ++it3)
    std::cout << ' ' << *it3;
  std::cout << '\n';

}
