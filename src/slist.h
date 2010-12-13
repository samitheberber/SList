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
        class iterator : public std::iterator<std::forward_iterator_tag, std::string>
        {
            private:
                Node* position;
            public:
                iterator(Node*);
                bool operator!=(const iterator&);
                void operator++();
                std::string operator*();
                friend class SList;
        };
        SList();
        const std::string front(void);
        void push_front(std::string);
        void pop_front(void);
        void insert_after(iterator, std::string);
        void erase_after(iterator);
        iterator begin(void);
        iterator end(void);
        void swap(SList&);
        void reverse(void);
};

#endif
