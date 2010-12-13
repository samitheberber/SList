#ifndef H_SLIST_
#define H_SLIST_

#include <string>
#include <iterator>

class SList
{
    private:
        class Node
        {
            private:
                std::string _value;
            public:
                Node(std::string);
                Node* next;
                const std::string value();
        };
        Node* _head;
    public:
        class const_iterator : public std::iterator<std::forward_iterator_tag, const std::string>
        {
            protected:
                Node* position;
            public:
                const_iterator(Node*);
                bool operator!=(const const_iterator&);
                void operator++();
                const std::string operator*();
                friend class SList;
        };
        class iterator : public const_iterator
        {
            public:
                iterator(Node*);
        };
        SList();
        const std::string front(void);
        void push_front(std::string);
        void pop_front(void);
        void insert_after(iterator, std::string);
        void erase_after(iterator);
        const_iterator begin(void) const;
        const_iterator end(void) const;
        iterator begin(void);
        iterator end(void);
        void swap(SList&);
        void reverse(void);
};

#endif
