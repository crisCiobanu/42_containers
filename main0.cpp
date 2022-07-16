#include "node0.hpp"
#include <map>
#include <vector>
#include "stack.hpp"
#include "set.hpp"
#include "map.hpp"
#include <set>

int main(void){
	ft::map<int, int> mp;

	mp.insert(ft::make_pair(1, 140));
	mp.insert(ft::make_pair(2, 140));
	mp.insert(ft::make_pair(3, 140));

	std::cout << "Map size : " << mp.size() << " is empty : " << (mp.empty() ? "YES" : "NO") << " ,  First : " << mp.begin() -> first << " , Last : " << std::endl;

	// ft::map<int, int> mp1 = mp;
	ft::map<int, int> mp1(mp);

	//mp1.insert(ft::make_pair("first", 5646));


	std::cout << "Map size : " << mp1.size() << " is empty : " << (mp1.empty() ? "YES" : "NO") << " ,  First : " << mp1.begin() -> first << " , Last : "  << std::endl;

	mp1.erase(2);
	mp1.insert(ft::make_pair(2, 160));

	std::cout << "Map size : " << mp.size() << " is empty : " << (mp.empty() ? "YES" : "NO") << " ,  First : " << mp.begin() -> first << " , Last : " << std::endl;
	std::cout << "Map size : " << mp1.size() << " is empty : " << (mp1.empty() ? "YES" : "NO") << " ,  First : " << mp1.begin() -> first << " , Last : "  << std::endl;

	std::cout << "EQUALITY COMPARISION" << std::endl;

	std::cout << "mp == mp1 : " << (mp == mp1) << std::endl;
	std::cout << "mp != mp1 : " << (mp != mp1) << std::endl;
	std::cout << "mp > mp1 : " << (mp > mp1) << std::endl;
	std::cout << "mp < mp1 : " << (mp < mp1) << std::endl;
	std::cout << "mp >= mp1 : " << (mp >= mp1) << std::endl;
	std::cout << "mp <= mp1 : " << (mp <= mp1) << std::endl;

	// ft::set<std::string> st;

	// st.insert("1first");
	// st.insert("2second");
	// st.insert("3third");

	// std::cout << "Set size : " << st.size() << " is empty : " << (st.empty() ? "YES" : "NO") << " ,  First : " << *(st.begin()) << " , Last : " << *(--st.end()) << std::endl;

	// ft::set<std::string> st1 = st;

	// std::cout << "Set size : " << st1.size() << " is empty : " << (st1.empty() ? "YES" : "NO") << " ,  First : " << *(st1.begin()) << " , Last : " << *(--st1.end()) << std::endl;

	// st1.erase("3third");
	// st1.insert("3third");

	// std::cout << "Set size : " << st.size() << " is empty : " << (st.empty() ? "YES" : "NO") << " ,  First : " << *(st.begin()) << " , Last : " << *(--st.end()) << std::endl;
	// std::cout << "Set size : " << st1.size() << " is empty : " << (st1.empty() ? "YES" : "NO") << " ,  First : " << *(st1.begin()) << " , Last : " << *(--st1.end()) << std::endl;

	// std::cout << "EQUALITY COMPARISION" << std::endl;

	// std::cout << "st == st1 : " << (st == st1) << std::endl;
	// std::cout << "st != st1 : " << (st != st1) << std::endl;
	// std::cout << "st > st1 : " << (st > st1) << std::endl;
	// std::cout << "st < st1 : " << (st < st1) << std::endl;
	// std::cout << "st >= st1 : " << (st >= st1) << std::endl;
	// std::cout << "st <= st1 : " << (st <= st1) << std::endl;



	// ft::vector<int> vec(10, 12);
	// vec.push_back(12);
	// ft::vector<int> vec2;
	// vec2.push_back(1);
	// vec2.push_back(2);
	// std::cout << vec2[1] << " " << vec2.size() << std::endl;
	// vec2 = vec;

	// std::cout << vec2[1] << " " << vec2.size() << std::endl;

	// std::vector<int> stdvec;
	// stdvec.push_back(12);
	// //stdvec.pop_back();
	// std::cout << stdvec[2] << " " << vec2.size() << std::endl;


	// ft::stack<int> mystack;



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

	// std::pair<int , std::string> first = std::pair<int , std::string>(100, "first");
	// std::pair<int , std::string> second = std::pair<int , std::string>(200, "second");
	// std::pair<int , std::string> third = std::pair<int , std::string>(300, "third");

	// std::map<int, std::string> mp;
	// mp.insert(first);
	// mp.insert(second);
	// mp.insert(third);

	// std::map<int, std::string>::iterator it = mp.begin();
	// mp.erase(it);

	// mp.erase(it);
	
	// std::map<int, std::string>::iterator start = mp.begin();
	// std::map<int, std::string>::iterator end = mp.end();
	// while (start != end){
	// 	std::cout << start -> first << " " << start -> second << std::endl;
	// 	++start;
	// }

	// std::map<int, std::string>::iterator it = mp.begin();

	// (*it).first = 100;

	// std::map<int, std::string>::reverse_iterator start = mp.rend();

	// std::cout << "BEGIN : " << start -> first << std::endl; 
	// ++start;
	// std::cout << "BEGIN : " << start -> first << std::endl; 


	// ft::rbtree<int> tree;

	// tree.insert(100);
	// tree.insert(200);
	// tree.insert(300);

	// std::cout << "START" << std::endl;
	// tree.printHelper(tree.getRoot(), "", true);
	// std::cout << "SIZE : " << tree.size() << std::endl;

	// ft::rbtree<int>::const_iterator sit = tree.find(1000);
	// ft::rbtree<int>::const_iterator end = tree.end();

	// std::cout << *end << std::endl;
	// std::cout << *sit << std::endl;
	// std::cout << (sit != end ? *sit : 999) << std::endl;

	// ft::rbtree<int>::const_reverse_iterator it = tree.rbegin();
	
	// //--it;
	// std::cout << *it << std::endl;
	//ft::rbtree<int>::const_iterator end = tree.end();
	// ++it;
	// ++it;
	// ++it;
	// std::cout << (it==end ? "TRUE" : "FALSE") << std::endl;




	// ft::Node<int> * fin = tree.find(1000, tree.getRoot());

	// std::cout << (fin ? (fin -> data) : 99999) << std::endl;
	// std::cout << "The minimum" << std::endl; 
	// std::cout << tree.minimum(tree.getRoot()) -> data << std::endl;
	// ft::Node<int> * ptr = tree.minimum(tree.getRoot());
	// ft::Node<int> * ptr1 = tree.successor(ptr);
	// std::cout << "The successor : " << std::endl;
	// std::cout << ptr1 -> data << std::endl;
	// ptr1 = tree.precedent(ptr1);
	// std::cout << "The precedent : " << std::endl;
	// std::cout << ptr1 -> data << std::endl;

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
