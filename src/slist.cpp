#include "slist.h"

#include <stdexcept>

SList::Node::Node(std::string value)
{
    _value = value;
    next = NULL;
}

const std::string SList::Node::value()
{
    return _value;
}

SList::SList()
{
    _head = NULL;
}

const std::string SList::front(void)
{
    if (_head == NULL)
        throw std::logic_error("SList front is NULL");
    else
        return _head->value();
}

void SList::push_front(std::string value)
{
    Node* newNode = new Node(value);
    if (_head == NULL)
        _head = newNode;
    else {
        newNode->next = _head;
        _head = newNode;
    }
}

void SList::pop_front(void)
{
    if (_head == NULL)
        throw std::logic_error("Can't pop empty SList");
    _head = _head->next;
}
