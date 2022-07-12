#pragma once

using namespace std;

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
template <typename U>
class tree_iterator
{

	public :
		typedef U                                                   value_type;
	    typedef value_type*                                         pointer;
	    typedef value_type&                                         reference;
	    typedef typename iterator_traits<U*>::difference_type    	difference_type;
	    typedef typename iterator_traits<U*>::value_type         	node_type;
	    typedef typename iterator_traits<U*>::pointer            	node_pointer;
	    typedef typename iterator_traits<U*>::reference          	node_reference;
	    typedef typename iterator_traits<U*>::iterator_category  	iterator_category;
	private:
		node_pointer _current;
	public:
		tree_iterator():_current(nullptr){}
		tree_iterator(node_pointer node):_current(node){}
		tree_iterator& operator =(const tree_iterator &rhs)
		{
			if(this != &rhs)
			{
				this->_current = rhs._current;
			}
			return(*this);
		}

		tree_iterator(const tree_iterator &rhs)
		{
			*this = rhs;
			return;
		}

		~tree_iterator()
		{
			return;
		}

		reference operator*() const
		{
			return(_current->data);
		}

		pointer operator->() const
		{
			return(&operator*());
		}
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

	 	typedef ft::my_iter<value_type>								iterator;
	 	typedef ft::my_iter<const value_type>						const_iterator;
		typedef std::reverse_iterator<iterator>						reverse_iterator;
		typedef std::reverse_iterator<const_iterator>				const_reverse_iterator;

	private:
		node_pointer 		root;
  		node_pointer 		TNULL;
		allocator_type 		con_alloc;
		node_allocator 		node_alloc;
		value_compare 		cmp;
		size_type 			_size;

	public:



		//	Iterators
		// iterator begin()
		// {

		// }

		// const_iterator begin() const
		// {
		// }
		// iterator end()
		// {

		// }

		// const_iterator end() const
		// {

		// }

		bool empty()const { return this -> _size == 0; }

		size_type size() const { return this -> _size; }

		size_type max_size() const{ return con_alloc.max_size(); }

		allocator_type get_allocator() const { return con_alloc; }

		value_compare value_comp() const {return this -> cmp; }

		// create a node
		node_pointer createNode(const value_type & data)
		{
			node_pointer node = node_alloc.allocate(1);
			node_alloc.construct(node, data);
			node->left = TNULL;
			node->right = TNULL;
			node->color = true;
			return (node);
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

  node_pointer precedent(node_pointer x) {
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
	++(this -> _size);

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
		TNULL -> color = 0;
		TNULL -> is_null = 1;
	}

	node_pointer copy_node(node_pointer rhs){
		node_pointer tmp = node_alloc.allocate(1);
		node_alloc.construct(tmp, Node<Value>());
		tmp -> color = rhs -> color;
		tmp -> is_null = rhs -> is_null;
		tmp -> data = rhs -> data;
		return tmp;
	}


	void copy_branches(node_pointer lhs, node_pointer rhs){
		if (rhs -> left -> is_null)
			lhs -> left = TNULL;
		else {
			lhs -> left = copy_node(rhs -> left);
			lhs -> left -> parent = lhs;
			copy_branches(lhs -> left, rhs -> left);
		}
		if (rhs -> right -> is_null)
			lhs -> right = TNULL;
		else {
			lhs -> right = copy_node(rhs -> right);
			lhs -> right -> parent = lhs;
			copy_branches(lhs -> right, rhs -> right);
		}
	}
	//delete
	void delete_node(node_pointer ptr)
	{
		node_alloc.destroy(ptr);
		node_alloc.deallocate(ptr, 1);
	}

	void delete_all_node(node_pointer ptr)
	{
	  if (ptr != TNULL)
	  {
		delete_all_node(ptr-> left);
		delete_all_node(ptr-> right);
		delete_node(ptr);
	  }
	}

	void rbTransplant(node_pointer u, node_pointer v) {
      if (u->parent == nullptr) {
        root = v;
      } else if (u == u->parent->left) {
        u->parent->left = v;
      } else {
        u->parent->right = v;
      }
      v->parent = u->parent;
    }

	node_pointer find(const_reference value, node_pointer ptr){
		node_pointer node = this -> root;
		node_pointer z;
		if (ptr == NULL)
			return NULL;
		while (node != TNULL){
			if (!cmp(value, node -> data) && !cpm(node -> data, value))
				z = node;
			if (cmp(value, node -> data))
				node = node -> left;
			else
				node = node -> right;
		}
		if (z == TNULL)
			return NULL;
	}


    void deleteNodeHelper(node_pointer node, int key) {
      node_pointer z = TNULL;
      node_pointer x, y;
      while (node != TNULL) {
        if (node->data == key) {
          z = node;
        }

        if (node->data <= key) {
          node = node->right;
        } else {
          node = node->left;
        }
      }

      if (z == TNULL) {
        std::cout << "Key not found in the tree" << std::endl;
        return;
      }

      y = z;
      int y_original_color = y->color;
      if (z->left == TNULL) {
        x = z->right;
        rbTransplant(z, z->right);
      } else if (z->right == TNULL) {
        x = z->left;
        rbTransplant(z, z->left);
      } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
          x->parent = y;
        } else {
          rbTransplant(y, y->right);
          y->right = z->right;
          y->right->parent = y;
        }

        rbTransplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
      }
      delete z;
      if (y_original_color == 0) {
        deleteFix(x);
      }
    }

	// For balancing the tree after deletion
    void deleteFix(node_pointer x) {
      node_pointer s;
      while (x != root && x->color == 0) {
        if (x == x->parent->left) {
          s = x->parent->right;
          if (s->color == 1) {
            s->color = 0;
            x->parent->color = 1;
            leftRotate(x->parent);
            s = x->parent->right;
          }

          if (s->left->color == 0 && s->right->color == 0) {
            s->color = 1;
            x = x->parent;
          } else {
            if (s->right->color == 0) {
              s->left->color = 0;
              s->color = 1;
              rightRotate(s);
              s = x->parent->right;
            }

            s->color = x->parent->color;
            x->parent->color = 0;
            s->right->color = 0;
            leftRotate(x->parent);
            x = root;
          }
        } else {
          s = x->parent->left;
          if (s->color == 1) {
            s->color = 0;
            x->parent->color = 1;
            rightRotate(x->parent);
            s = x->parent->left;
          }

          if (s->right->color == 0 && s->right->color == 0) {
            s->color = 1;
            x = x->parent;
          } else {
            if (s->left->color == 0) {
              s->right->color = 0;
              s->color = 1;
              leftRotate(s);
              s = x->parent->left;
            }

            s->color = x->parent->color;
            x->parent->color = 0;
            s->left->color = 0;
            rightRotate(x->parent);
            x = root;
          }
        }
      }
      x->color = 0;
    }

	public:
	void deleteNode(value_type data) {
	  deleteNodeHelper(this->root, data);
	}

		rbtree() : root(0), con_alloc(allocator_type()), node_alloc(node_allocator()), cmp(value_compare()), _size(0) {
			init_tree();
			this -> root = this -> TNULL;
		}

		rbtree(const value_compare& comp, const allocator_type& alloc = allocator_type()) :
			root(0), con_alloc(alloc), node_alloc(node_allocator()), cmp(comp), _size(0){
			init_tree();
			this -> root = this -> TNULL;
		}

		 ~rbtree()
		{

		}

		void del(){
			delete_all_node(this -> root);
		}

		rbtree & operator=(rbtree const &rhs)
		{
			if(this == &rhs)
				return(*this);
			this -> con_alloc = rhs.con_alloc;
			this -> node_alloc = rhs.node_alloc;
			this -> cmp = rhs.cmp;

			delete_all_node(this -> root);
			if (rhs._size == 0)
				this -> root = this -> TNULL;
			else {
				this -> root = copy_node(rhs.root);
				copy_branches(this -> root , rhs.root);
			}
			this -> _size = rhs._size;
			return (*this);
		}

		node_pointer getRoot(){
			return (this -> root);
		}

	void printHelper(node_pointer root, string indent, bool last) {
    	if (root != TNULL) {
      		cout << indent;
      	if (last) {
        	cout << "R----";
        	indent += "   ";
      	} else {
        	cout << "L----";
        	indent += "|  ";
      	}

      string sColor = root->color ? "RED" : "BLACK";
      cout << root->data << "(" << sColor << ")" << endl;
      printHelper(root->left, indent, false);
      printHelper(root->right, indent, true);
    }
  }

};

};
