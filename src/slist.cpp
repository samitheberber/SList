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

void SList::erase_after(SList::iterator iter)
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

SList::const_iterator SList::begin(void) const
{
    return SList::const_iterator(_head);
}

SList::const_iterator SList::end(void) const
{
    return SList::const_iterator(NULL);
}

void SList::swap(SList& other)
{
    Node* thisHead = _head;
    _head = other._head;
    other._head = thisHead;
}

void SList::reverse(void)
{
    if (_head == NULL || _head->next == NULL)
        return;

    Node *tmp = NULL, *current = NULL;
    while(_head) {
        current = _head;
        _head = _head->next;
        current->next = tmp;
        tmp = current;
    }
    _head = tmp;
}

// Iterator

SList::const_iterator::const_iterator(Node* node) : position(node)
{
}

bool SList::const_iterator::operator!=(SList::const_iterator const& other)
{
    return (position != other.position);
}

void SList::const_iterator::operator++()
{
    position = position->next;
}

const std::string SList::const_iterator::operator*()
{
    return position->value();
}

SList::iterator::iterator(Node* node) : const_iterator(node)
{
}
