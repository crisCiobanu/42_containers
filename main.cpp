#include "vector.hpp"
#include "node.hpp"

int main(void){

	ft::rbtree<int> tree = ft::rbtree<int>();

	//tree.insert(100);


	ft::Node<int> * ptr = tree.createNode(20);
	std::cout << ptr->data << std::endl;


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