#ifndef MAP_HPP
# define MAP_HPP
# include "utils.hpp"
# include "node0.hpp"
# include <functional>  // std::less
# include <memory>      // std::allocator

namespace ft
{
    template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<Key,T> > >   // map::allocator_type
    class map
    {
        public:
            typedef Key                                             key_type;
            typedef T                                               mapped_type;
            typedef ft::pair<const key_type, mapped_type>           value_type;
            typedef Compare                                         key_compare;
            typedef Alloc                                           allocator_type;
            typedef typename allocator_type::template rebind<value_type>::other   type_allocator;
            typedef std::allocator_traits<type_allocator>                         type_traits;
            typedef typename allocator_type::reference              reference; // T&
            typedef typename allocator_type::const_reference        const_reference; //const t&
            typedef typename allocator_type::pointer                pointer; // T*
            typedef typename allocator_type::const_pointer          const_pointer; // const T*

            // typedef ft::reverse_iterator<iterator>                  reverse_iterator;
            // typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
            // typedef iterator_traits<iterator>::difference_type      difference_type;
            typedef size_t                                          size_type;
			typedef std::ptrdiff_t difference_type;



          //   template <class Key, class T, class Compare, class Alloc>
          //   class map<Key,T,Compare,Alloc>::value_compare
          //   {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
          //     friend class map;
          //   protected:
          //     Compare comp;
          //     value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
          //   public:
          //     typedef bool result_type;
          //     typedef value_type first_argument_type;
          //     typedef value_type second_argument_type;
          //     bool operator() (const value_type& x, const value_type& y) const
          //     {
          //       return comp(x.first, y.first);
          //     }
          // };
          // class value_compare : public std::binary_function<value_type, value_type, bool> {
          //   protected:
          //   key_compare comp;
          //
          //   public:
          //   value_compare(key_compare c) : comp(c) {}
          //   ~value_compare() {}
          //
          //   bool operator()(const value_type& x, const value_type& y) const {
          //     return (comp(x.first, y.first));
          //   }
          //   bool operator()(const value_type& x, const key_type& y) const {
          //     return (comp(x.first, y));
          //   }
          //   bool operator()(const key_type& x, const value_type& y) const {
          //     return (comp(x, y.first));
          //   }
          // };
          class value_compare {
			key_compare cmp;

		public:
			value_compare(const key_compare & cmp) : cmp(cmp) {}
			bool operator()(const value_type& x, const value_type& y) const {
				return cmp(x.first, y.first);
				//return cmp(x.first, y.first) || (!cmp(y.first, x.first) && x.second < y.second);
			}
		      };



          typedef typename rbtree<value_type, value_compare, allocator_type>::iterator           iterator;
          typedef typename rbtree<value_type, value_compare, allocator_type>::const_iterator  const_iterator;
          typedef rbtree<value_type, value_compare, allocator_type> tree_type;


        private:
            rbtree<value_type, value_compare, allocator_type> tree;
            key_compare cmp;

        public :
            // template <class InputIterator>
            // map (InputIterator first, InputIterator last,
            //     const key_compare& comp = key_compare(),
            //     const allocator_type& alloc = allocator_type())
            //     : tree(tree_type(first, last, value_compare(comp), alloc)), cmp(comp) {}
            //
            // explicit map (const key_compare& comp = key_compare(),
            // const allocator_type& alloc = allocator_type()) : cmp(comp), tree(tree_type(value_compare(comp), alloc)) {}
            //
            // map& operator=(const map& rhs)
            // {
            //     if(this!= &rhs)
            //     {
            //         tree = rhs.tree;
            //         cmp = cmp.tree;
            //     }
            //     return(*this);
            // }
            //
            // map (const map& x)
            // {
            //     *this = x;
            //     return ;
            // }
            //
            // ~map() {}
        public:
            explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			tree(tree_type(value_compare(comp), alloc)), cmp(comp){}

    		template< class InputIt >
    		map(InputIt first, InputIt last, const Compare& comp = Compare(), const allocator_type& alloc = allocator_type())
            : tree(tree_type(first, last, value_compare(comp), alloc)),cmp(comp) {}

    		map(const map& other): tree(tree_type(other.tree)), cmp(other.cmp) {}

    		map& operator=(const map& other) {
    			this->tree = other.tree;
    			this->cmp = other.cmp;
    			return *this;
    		}

			void printTree(){
				this -> tree.printHelper(this -> tree.getRoot(), "", true);
			}

		// mapped_type& operator[]( const key_type& key ) {
		// 	return tree.insert(ft::make_pair(key, mapped_type())).first->second;
		// }





            iterator begin()
            {
                return tree.begin();
    		}

    		const_iterator begin() const
            {
    			return tree.begin();
    		}

    		iterator end()
            {
    			return tree.end();
    		}

    		const_iterator end() const
            {
    			return tree.end();
    		}

    		// reverse_iterator rbegin()
            // {
    		// 	return tree.rbegin();
    		// }

    		// const_reverse_iterator rbegin() const
            // {
    		// 	return tree.rbegin();
    		// }

    		// reverse_iterator rend() {
    		// 	return tree.rend();
    		// }

    		// const_reverse_iterator rend() const
            // {
    		// 	return tree.rend();
    		// }


            bool empty() const
            {
                return(tree.empty());
            }

            size_type size() const
            {
                return(tree.size());
            }

            size_type max_size() const
            {
                return(tree.max_size());
            }



            mapped_type& operator[] (const key_type& k)
            {

            }

            template <class InputIterator>
            void insert (typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type first,InputIterator last)
            {
                tree.insert_val(first, last);
            }

            iterator insert (iterator position, const value_type& val)
            {
                return tree.insert_val(position, val);
            }

            ft::pair<iterator,bool> insert (const value_type& val)
            {
                return tree.insert_val(val);
            }

            // void erase (iterator position)
            // {
            //     deleteNodeHelper(position)
            // }
            //
            // size_type erase (const key_type& k)
            // {
            //      return (tree.deleteNode(k));
            // }
            //
            // void erase (iterator first, iterator last)
            // {
            //
            // }
            void swap (map& x)
            {
                std::swap(this->cmp, x.cmp);
			    tree.swap(x.tree);
		     }

            void clear()
            {
                tree.clear();
            }

            value_compare value_comp() const
            {
                return tree.value_comp();
		     }

		    key_compare key_comp() const
            {
                return cmp;
		    }

            iterator find (const key_type& k)
            {
                return tree.find(ft::make_pair(k, mapped_type()));
            }

            const_iterator find (const key_type& k) const
            {
                return tree.find(ft::make_pair(k, mapped_type()));
            }

            size_type count (const key_type& k) const
            {

            }

            iterator lower_bound (const key_type& k)
            {
                return tree.lower_bound(ft::make_pair(k, mapped_type()));
            }

            const_iterator lower_bound (const key_type& k) const
            {
                return tree.lower_bound(ft::make_pair(k, mapped_type()));
            }

            iterator upper_bound (const key_type& k)
            {
                return tree.upper_bound(ft::make_pair(k, mapped_type()));
            }

            const_iterator upper_bound (const key_type& k) const
            {
                return tree.upper_bound(ft::make_pair(k, mapped_type()));
            }

            pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {
                return tree.equal_range(ft::make_pair(k, mapped_type()));
            }

            pair<iterator,iterator>             equal_range (const key_type& k)
            {
                return tree.equal_range(ft::make_pair(k, mapped_type()));
            }

            allocator_type get_allocator() const
            {
    			return tree.get_allocator();
    		}

    };
}

#endif
