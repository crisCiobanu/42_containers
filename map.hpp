#ifndef MAP_HPP
# define MAP_HPP
# include "utils.hpp"
# include "node0.hpp"

namespace ft
{
    template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<pair<const Key,T> >    // map::allocator_type
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
            typedef typename rbtree<value_type, value_compare, allocator_type>::iterator           iterator;
            typedef typename rbtree<value_type, value_compare, allocator_type>::const_iterator  const_iterator;
            typedef ft::reverse_iterator<iterator>                  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
            typedef iterator_traits<iterator>::difference_type      difference_type;
            typedef size_t                                          size_type;
            typedef rbtree<value_type, value_compare, allocator_type> tree_type;



            template <class Key, class T, class Compare, class Alloc>
            class map<Key,T,Compare,Alloc>::value_compare
            {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
              friend class map;
            protected:
              Compare comp;
              value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
            public:
              typedef bool result_type;
              typedef value_type first_argument_type;
              typedef value_type second_argument_type;
              bool operator() (const value_type& x, const value_type& y) const
              {
                return comp(x.first, y.first);
              }
          };

        private:
            rbtree<value_type, value_compare, allocator_type> tree;
            key_compare cmp;

        public :
            template <class InputIterator>
            map (InputIterator first, InputIterator last,
                const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type())
                : tree(tree_type(first, last, value_compare(comp), alloc)), cmp(comp) {}

            explicit map (const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()) : cmp(comp), tree(tree_type(value_compare(comp), alloc)) {}

            map& operator=(const map& rhs)
            {
                if(this!= &rhs)
                {
                    tree = rhs.tree;
                    cmp = cmp.tree;
                }
                return(*this);
            }

            map (const map& x)
            {
                *this = x;
                return ;
            }

            ~map() {}

            iterator begin()
            {
                return(_tree.begin());
            }

            const_iterator begin() const
            {
                return(_tree.begin());
            }
            iterator end()
            {
                return (_tree.end());
            }
            const_iterator end() const
            {
                return (_tree.end());
            }

            reverse_iterator rbegin()
            {

            }

            const_reverse_iterator rbegin() const
            {

            }

            reverse_iterator rend()
            {

            }

            const_reverse_iterator rend() const
            {

            }

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
            void insert (InputIterator first, InputIterator last)
            {

            }

            iterator insert (iterator position, const value_type& val)
            {

            }

            pair<iterator,bool> insert (const value_type& val)
            {

            }

            void erase (iterator position)
            {

            }

            size_type erase (const key_type& k)
            {
                 return (_tree.deleteNode(k));
            }

            void erase (iterator first, iterator last)
            {

            }
            void swap (map& x)
            {

            }
            void clear()
            {

            }
            key_compare key_comp() const
            {

            }
            value_compare value_comp() const
            {

            }
            iterator find (const key_type& k)
            {

            }
            const_iterator find (const key_type& k) const
            {

            }
            size_type count (const key_type& k) const
            {

            }
            iterator lower_bound (const key_type& k)
            {

            }
            const_iterator lower_bound (const key_type& k) const
            {

            }
            iterator upper_bound (const key_type& k)
            {

            }
            const_iterator upper_bound (const key_type& k) const
            {

            }
            pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {

            }
            pair<iterator,iterator>             equal_range (const key_type& k)
            {

            }
            allocator_type get_allocator() const
            {

            }

    };
}

#endif
