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

void SList::insert_after(SList::iterator iter, std::string value)
{
    if (iter.position == NULL)
        throw std::logic_error("Can't insert after empty node");
    Node* node = new Node(value);
    node->next = iter.position->next;
    iter.position->next = node;
}

void SList::delete_after(SList::iterator iter)
{
    if (iter.position == NULL)
        throw std::logic_error("Can't delete after empty node");
    else if (iter.position->next == NULL)
        throw std::logic_error("Can't delete empty node");

    Node* deleted = iter.position->next;
    iter.position->next = iter.position->next->next;
    delete deleted;
}

SList::iterator SList::begin(void)
{
    return SList::iterator(_head);
}

SList::iterator SList::end(void)
{
    return SList::iterator(NULL);
}

// Iterator

SList::iterator::iterator(Node* node) : position(node)
{
}

bool SList::iterator::operator!=(const SList::iterator& other)
{
    return (position != other.position);
}

void SList::iterator::operator++()
{
    position = position->next;
}

std::string SList::iterator::operator*()
{
    return position->value();
}
