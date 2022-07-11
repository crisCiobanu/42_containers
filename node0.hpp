#pragma once

namespace ft{

// struct Node
template <class T, class Alloc = std::allocator<T> >
struct Node {
	typedef T value_type;
	T     data;
  	Node *parent;
	Node *left;
  	Node *right;
  	bool color;
	bool is_null;


	Node():data(0), parent(nullptr),left(nullptr), right(nullptr),color(true), is_null(false){}
	Node(const Node &rhs)
	{
		*this = rhs;
		return;
	}
	Node(const value_type &rhs):parent(nullptr),left(nullptr), right(nullptr),color(true), is_null(false){
		this -> data = rhs;
	};

	Node& operator=(const Node &rhs)
	{
		if(this != &rhs)
		{
			this->data = rhs.data;
			this->parent = rhs.parent;
			this->left = rhs.left;
			this->right = rhs.right;
			this->color = rhs.color;
			this->is_null = rhs.is_null;
		}
		return(*this);
	}
 ~Node(){ } ;
};


// class iterator
template <typename U, typename V>
class tree_iterator
{


};


// class rbtree
template <class Value, class Compare = std::less<Value>, class Alloc = std::allocator<Value> >
class rbtree{
	public:
		typedef	Value 															value_type;
		typedef Alloc															allocator_type;
		typedef Compare 														value_compare;
		typedef std::size_t														size_type;
		typedef std::ptrdiff_t													difference_type;
		typedef value_type&														reference;
		typedef const value_type&												const_reference;
		typedef typename Alloc::pointer											pointer;
		typedef typename Alloc::const_pointer									const_pointer;
		typedef typename Alloc::template rebind<Node<Value> >::other			node_allocator;
		typedef typename node_allocator::pointer								node_pointer;
		// typedef Node<value_type>*                                       node_pointer;


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

	public:

		rbtree() : root(0), con_alloc(allocator_type()), node_alloc(node_allocator()), cmp(value_compare()), size(0) {
			init_tree();
			this -> root = this -> header;
		}

		rbtree(const value_compare& comp, const allocator_type& alloc = allocator_type()) :
			root(0), con_alloc(alloc), node_alloc(node_allocator()), cmp(comp), size(0){
			init_tree();
			this -> root = this -> header;
		}

		 ~rbtree()
		{

		}

	// 	void create_tNull_and_header() {
	// 	_nil = _node_alloc.allocate(1);
	// 	_node_alloc.construct(_nil, node<Content>());
	// 	_nil->is_black = true;
	// 	_nil->is_nil = true;
	// 	_header = _node_alloc.allocate(1);
	// 	_node_alloc.construct(_header, node<Content>());
	// 	_header->content = _con_alloc.allocate(1);
	// 	_con_alloc.construct(_header->content, Content());
	// 	_header->is_black = true;
	// }
		//Creating a node

		node_pointer createNode(const value_type & data)
		{
			node_pointer node = node_alloc.allocate(1);
			node_alloc.construct(node, data);
			node->parent = TNULL;
			node->left = TNULL;
			node->right = TNULL;
			node->color = true;
			// node->isnull = TNULL;
			return (node);
		}

		void delete_node(node_pointer ptr)
		{
			con_alloc.destroy(ptr);
			con_alloc.deallocate(ptr, 1);
		}

		void delete_all_node(node_pointer ptr)
		{
	      if (ptr != TNULL)
		  {
	      	delete_all_node(ptr->_left);
	      	delete_all_node(ptr->_right);
	      	delete_node(ptr);
		  }
	    }

		node_pointer minimum(node_pointer node)
		{
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

  node_pointer ptrueecessor(node_pointer x) {
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
	public :




  // For balancing the tree after insertion
  void insertFix(node_pointer k) {
    node_pointer u;
    while (k->parent->color == 1) {
      if (k->parent == k->parent->parent->right) {
        u = k->parent->parent->left;
        if (u->color == 1) {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->left) {
            k = k->parent;
            rightRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          leftRotate(k->parent->parent);
        }
      } else {
        u = k->parent->parent->right;

        if (u->color == 1) {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->right) {
            k = k->parent;
            leftRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          rightRotate(k->parent->parent);
        }
      }
      if (k == root) {
        break;
      }
    }
    root->color = 0;
  }
  // Inserting a node
  void insert(const value_type & data) {

	node_pointer node = createNode(data);

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
	private:
	void init_tree() {
		TNULL = node_alloc.allocate(1);
		node_alloc.construct( TNULL, 0);
		TNULL -> color = false;
		TNULL -> right = nullptr;
		TNULL -> left = nullptr;
		this->header = TNULL;

		// this -> header = node_alloc.allocate(1);
		// node_alloc.construct(this -> header, Node<Value>());
		// this -> header -> color = false;
		// header->data = con_alloc.allocate(1);
		// con_alloc.construct(header->data, Value());
	}

	node_pointer copy_node(node_pointer rhs){
		node_pointer tmp = node_alloc.allocate(1);
		node_alloc.construct(tmp, Node<Value>());
		tmp -> color = rhs.color;
		tmp -> is_null = rhs.is_null;
		tmp -> data = rhs.data;
		return tmp;
	}


	void copy_branches(node_pointer lhs, node_pointer rhs){
		if (rhs -> left -> is_null)
			lhs -> left = TNULL;
		else {
			lhs -> left = rhs -> left;
			lhs -> left -> parent = lhs;
			copy_branches(lhs -> left, rhs -> left);
		}
	}

		// rbtree & opeartor=(rbtree const &rhs)
		// {
		// 	if(*this!=rhs)
		// 	{
		// 		root = ;
		//   		TNULL = ;
		// 		header = ;
		// 		con_alloc = ;
		// 		node_alloc = ;
		// 		cmp = ;
		// 		size = ;

		// 	}
		// 	return(*this);

		// }



};

};
