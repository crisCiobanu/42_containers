#pragma once

typedef true RED;
typedef false BLACK;

namespace ft{

template <class T, class Alloc = std::allocator<T>>
struct Node {
	T data;
  	Node *parent;
	Node *left;
  	Node *right;
  	bool color;


	Node(){
		this->data = 0;
 		this->parent = nullptr;
 		this->left = nullptr;
 		this->right = nullptr;
 		this->color = RED;
	}
};

template <class Value, class Compare = std::less<Value>, class Alloc = std::allocator<Value> >

class rbtree{
	public:
		typedef	Value 															value_type;
		typedef Allocator														allocator_type;
		typedef Compare 														value_compare;
		typedef std::size_t														size_type;
		typedef std::ptrdiff_t													difference_type;
		typedef value_type&														reference;
		typedef const value_type&												const_reference;
		typedef typename Allocator::pointer										pointer;
		typedef typename Allocator::const_pointer								const_pointer;	
		typedef typename Allocator::template rebind<Node<Value> >::other		node_allocator;
		typedef typename node_allocator::pointer								node_pointer;

		// typedef ft::my_iter<value_type>								iterator;
		// typedef ft::my_iter<const value_type>						const_iterator;
		// typedef std::reverse_iterator<iterator>						reverse_iterator;
		// typedef std::reverse_iterator<const_iterator>				const_reverse_iterator;

	private:
		node_pointer 		root;
  		node_pointer 		TNULL;
		node_pointer 		header;
		allocator_type 		con_alloc;
		node_allocator 		node_alloc;
		value_compare 		cmp;
		size_type 			size;

		
		node_pointer minimum(node_pointer node) {
			while (node->left != TNULL) {
      			node = node->left;
    		}
    		return node;
  		}

  node_pointer maximum(node_pointer node) {
    while (node->right != TNULL) {
      node = node->right;
    }
    return node;
  }

  node_pointer successor(node_pointer x) {
    if (x->right != TNULL) {
      return minimum(x->right);
    }

    node_pointer y = x->parent;
    while (y != TNULL && x == y->right) {
      x = y;
      y = y->parent;
    }
    return y;
  }

  node_pointer predecessor(node_pointer x) {
    if (x->left != TNULL) {
      return maximum(x->left);
    }

    node_pointer y = x->parent;
    while (y != TNULL && x == y->left) {
      x = y;
      y = y->parent;
    }

    return y;
  }

  void leftRotate(node_pointer x) {
    node_pointer y = x->right;
    x->right = y->left;
    if (y->left != TNULL) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  void rightRotate(node_pointer x) {
    node_pointer y = x->left;
    x->left = y->right;
    if (y->right != TNULL) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
  }

  //Creating a node

  node_pointer createNode(const value_type & data){
	node_pointer node = node_allocator.allocate(1);
    node_allocator.construct(node, data);

    node->data = data;
	return (node);
  }
  // Inserting a node
  void insert(const value_type & data) {


    node_pointer y = nullptr;
    node_pointer x = this->root;

    while (x != TNULL) {
      y = x;
      if (node->data < x->data) {
        x = x->left;
      } else {
        x = x->right;
      }
    }

    node->parent = y;
    if (y == nullptr) {
      root = node;
    } else if (node->data < y->data) {
      y->left = node;
    } else {
      y->right = node;
    }

    if (node->parent == nullptr) {
      node->color = 0;
      return;
    }

    if (node->parent->parent == nullptr) {
      return;
    }

    insertFix(node);
  }

	void init_tree() {
		this -> TNULL = node_alloc.allocate(1);
		node_alloc.construct(this -> TNULL, Node<Value>());
		this -> TNULL.color = BLACK;

		this -> header = node_alloc.allocate(1);
		node_alloc.constrcut(this -> header, Node<Value>());
		this -> header = BLACK;
	}
	public: 

		rbtree() : root(0), con_allocator(allocator_type()), node_alloc(node_allocator()), cmp(value_compare()), size(0) {
			init_tree();
			this -> root = this -> header;
		}

		rtbtree(const value_compare& comp, const allocator_type& alloc = allocator_type()) : 
			root(0), con_allocator(alloc), node_alloc(node_allocator()), cmp(comp), size(0){
				init_tree();
			this -> root = this -> header;

		}

		~rbtree(){

		}

};




};