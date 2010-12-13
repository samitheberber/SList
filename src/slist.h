#ifndef H_SLIST_
#define H_SLIST_

#include <string>

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
        SList();
        const std::string front(void);
        void push_front(std::string);
        void pop_front(void);
};

#endif
