// #include "vector.hpp"
#include "map.hpp"
#include "utils.hpp"
#include "vector0.hpp"
#include "stack.hpp"
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
  //  std::chrono::time_point<std::chrono::system_clock> endstd = std::chrono::system_clock::now();
  //  int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(endstd - start).count();
  //  std::cout << "std::elapsed time: " << elapsed_seconds << "milliseconds" << std::endl;
  //  ft::vector<int> ftvector;
  //  for(int i = 0; i < 200000; i++)
	//   ftvector.push_back(i);
  //  for(int i = 0; i < 200000; i++)
	//   ftvector.pop_back();
  // std::chrono::time_point<std::chrono::system_clock> endft = std::chrono::system_clock::now();
  // elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(endft - endstd).count();
  // std::cout << "ft::elapsed time: " << elapsed_seconds << "milliseconds" << std::endl;
	// //=================================================================
	// //==============           iterator_vector          ==============
	// //=================================================================
  // for(int i = 0; i < 20; i++)
	//    ftvector.push_back(i);
  // for(ft::vector<int>::iterator ftiter = ftvector.begin(); ftiter < ftvector.end(); ftiter++)
	//   std::cout << *ftiter << std::endl ;
  //
	// //=================================================================
	// //==============           const_iterator_vector          ==============
	// //=================================================================
  //
  // for(ft::vector<int>::const_iterator ftiter = ftvector.begin(); ftiter < ftvector.end(); ftiter++)
  // {
  //
	//   std::cout << *ftiter << std::endl ;
	//   // *ftiter = 1;
  // }
  // //=================================================================
  // //==============           surcharge		            ==============
  // //=================================================================
  //  std::cout << "surcharge ::"<< std::endl ;
  // ft::vector<int>::const_iterator ftiter = ftvector.end();
  // ftiter--;
  // std::cout << *(ftiter) << std::endl ;
  // ++ftiter;
  // std::cout << *(ftiter) << std::endl ;
  // --ftiter;
  // std::cout << *(ftiter) << std::endl ;
  //
  //
  //
  //
  //
  //
  //
  //
  //
  //
































	//  ft::map< int,int > map;
	//  ft::vector< int> vector;
	//
	//  map.insert ( ft::pair<int,int>(1, 100) );
  	//  map.insert ( ft::pair<int,int>(2, 200) );
	// ft::map< int,int >::iterator iter = map.begin();
	//
	// // std::cout << (*iter).first << std::endl;
	// //(*iter).first = 200;
	// std::cout <<  map[1]<< std::endl;
	// // iter = map.find(1);
	// vector.push_back(10);
	// vector.push_back(10);
	// vector.push_back(10);
	// for(ft::vector<int>::iterator iter2 = vector.begin(); iter2 < vector.end(); iter2++)
	// 	std::cout <<   *iter2  << std::endl;
	//
	// std::cout << map.erase(5) <<std::endl;
	//
	// ft::stack<int> mystack;
	//
	//
	//
	//   for (int i=0; i<5; ++i) mystack.push(i);
	//    	ft::stack<int> mystack2(mystack);
	//   std::cout << "Popping out elements...";
	//   while (!mystack.empty())
	//   {
	//      std::cout << ' ' << mystack.top();
	// 	 std::cout << ' ' << mystack2.top();
	//      mystack.pop();
	// 	 // mystack2.pop();
	//   }
	//   std::cout << '\n';

	// std::list<std::string>      std_lis;
	// std::stack<char>            std_sta;
    // std::stack<double>          std_que;
    // std::map<int, std::string>  std_map;
    // ft::vector<int>::iterator it;
	//
    // ft::vector<int>  std_vec(4,100);
    // ft::vector<int> ft_vec(4,100);
    // std::vector<int>::const_iterator it2;
    // ft_vec.pop_back();
    // it = ft_vec.begin();
    // std::cout << *it <<std::endl;
    // for (ft::vector<int>::const_iterator it2 = std_vec.begin(); it2 != std_vec.end(); ++it2)
    // {
	//
    //         std::cout << ' ' << *it2 <<"\n";
    //         std::cout << ' ' << *(it2 -  1)  <<"\n";
	//
    //           // *it2 = 200;
    // }
    // for (ft::vector<int>::iterator it = ft_vec.begin(); it != ft_vec.end(); ++it)
    // {
	//
    //         std::cout << ' ' << *it <<"\n";
    //         std::cout << ' ' << *(it - 1)  <<"\n";
	//
    //          *it = 200;
    // }
    // std::cout << '\n';


    return(0);




	 // test.insert ( std::pair<int,int>(10,100),10 );
	//
	// ft::rbtree< ft::pair<int,int> > tree;
	// tree.insert(make_pair(100,200));
	// ft::rbtree<int>::iterator iter = tree.begin();

	// for(iter = tree.begin(); iter != tree.end(); iter++)
	// 	std::cout << *iter << std::endl;
	// --iter;
	// ++iter;
	// ++iter;
	// --iter;
	// ++iter;
	// std::cout << *iter << std::endl;




	// std::cout << "The minimum" << std::endl;
	// std::cout << tree.minimum(tree.getRoot()) -> data << std::endl;
	// ft::Node<int> * ptr = tree.minimum(tree.getRoot());
	// ft::Node<int> * ptr1 = tree.successor(ptr);
	// std::cout << "The successor : " << std::endl;
	// std::cout << ptr1 -> data << std::endl;
	// ptr1 = tree.precedent(ptr1);
	// std::cout << "The precedent : " << std::endl;
	// std::cout << ptr1 -> data << std::endl;
	//
	// std::cout << "The maximum" << std::endl;
	// std::cout << tree.maximum(tree.getRoot()) -> data << std::endl;

	//tree.deleteNode(200);

	// ft::rbtree<int> second;

	// second.insert(55);
	// second.insert(66);
	// std::cout << "Second tree : " << std::endl;
	// second.printHelper(second.getRoot(), "", true);
	// second = tree;
	// std::cout << "Second tree : " << std::endl;
	// second.printHelper(second.getRoot(), "", true);

	// std::cout << "First tree : " << std::endl;
	// tree.printHelper(tree.getRoot(), "", true);

	// std::cout << "Second tree : " << std::endl;
	// second.printHelper(second.getRoot(), "", true);



	//ft::Node<int> * ptr = tree.createNode(20);
	//std::cout << *(ptr->data) << std::endl;


	// ft::vector<int> ft_vec = ft::vector<int>();

	// ft_vec.push_back(10);
	// ft_vec.push_back(2);
	// ft_vec.push_back(10);
	// ft_vec.push_back(2);
	// ft_vec.push_back(10);
	// ft_vec.push_back(2);
	// std::cout << ft_vec.capacity() << " " << ft_vec.size() << std::endl;

	// ft::vector<int>::iterator start = ft_vec.begin();
	// ft::vector<int>::iterator end = ft_vec.end();

	// //start++;
	// *start = 50;

	// std::cout << "Iter is : " << *start << std::endl;

	// ft::vector<int> ft_vec1 = ft::vector<int>();

	// ft_vec1.push_back(10);
	// ft_vec1.push_back(2);
	// ft_vec1.push_back(10);
	// ft_vec1.push_back(2);
	// ft_vec1.push_back(10);
	// ft_vec1.push_back(2);
	// std::cout << ft_vec1.capacity() << " " << ft_vec1.size() << std::endl;

	// ft::vector<int>::const_iterator start1 = ft_vec1.begin();
	// ft::vector<int>::const_iterator end1 = ft_vec1.end();

	// //start++;
	// //*start1 = 50;


	// 	ft::vector<int>::iterator first = ft_vec1.begin();
	// 	ft::vector<int>::const_iterator second = ft_vec1.begin();

	// 	first++;
	// 	first++;

	// 	first-=1;
	// 	std::cout << "Minus : " << *(first) << std::endl;

	// std::cout << "Comparisions :" << (first <= second? "true" : "false") << std::endl;
}
