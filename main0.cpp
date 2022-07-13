#include "vector.hpp"
#include "node0.hpp"
#include "iterators.hpp"
#include <map>

int main(void){

	// std::pair<int , std::string> first = std::pair<int , std::string>(100, "first");
	// std::pair<int , std::string> second = std::pair<int , std::string>(200, "second");
	// std::pair<int , std::string> third = std::pair<int , std::string>(300, "third");

	// std::map<int, std::string> mp;
	// mp.insert(first);
	// mp.insert(second);
	// mp.insert(third);

	// std::map<int, std::string>::reverse_iterator start = mp.rend();

	// std::cout << "BEGIN : " << start -> first << std::endl; 
	// ++start;
	// std::cout << "BEGIN : " << start -> first << std::endl; 


	ft::rbtree<int> tree;

	tree.insert(100);
	tree.insert(200);
	tree.insert(300);

	std::cout << "START" << std::endl;
	tree.printHelper(tree.getRoot(), "", true);
	std::cout << "SIZE : " << tree.size() << std::endl;

	ft::rbtree<int>::const_iterator sit = tree.find(1000);
	ft::rbtree<int>::const_iterator end = tree.end();

	std::cout << *end << std::endl;
	std::cout << *sit << std::endl;
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
