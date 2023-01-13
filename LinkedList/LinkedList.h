#pragma once

#include "Common/AdvancedNode.h"
#include "Common/NodeIterator.h"

namespace Containers
{
    template<class T>
    class LinkedList;
}

template<class T>
class Containers::LinkedList
{
    using AdvancedNode = Containers::Common::Trees::Nodes::AdvancedNode<T>;
    using Iterator = Containers::Common::Iterators::NodeIterator<T>;

    AdvancedNode* _beginningNode{};
    Iterator* _begin{};
    Iterator* _end{};
    size_t* _size = new size_t{ 0 };
public:
    LinkedList() = default;

    LinkedList(AdvancedNode* const&& node) : LinkedList(node) {}

    LinkedList(AdvancedNode* const& node)
    {
        AssignValues(node);
    }

    void push_front(T&& _Val)
    {
        push_front(_Val);
    }

    void push_front(T& _Val)
    {
        if (empty())
        {
            AssignValues(new AdvancedNode{ _Val });
            return;
        }
        _beginningNode = (AdvancedNode*)_beginningNode->SetPrev(_Val);
        --(*_begin);
        ++(*_size);
    }

    void push_back(T&& _Val)
    {
        push_back(_Val);
    }

    void push_back(T& _Val)
    {
        if (empty())
        {
            AssignValues(new AdvancedNode{ _Val });
            return;
        }
        _beginningNode = (AdvancedNode*)_beginningNode.SetNext(_Val);
        ++(_end);
        ++(*_size);
    }

    void pop_front() noexcept // Find out what to do with reference variable or value type
    {
        //_beginningNode = _beginningNode.Next;
        //delete _beginningNode.Value;
        //_beginningNode.Prev = nullptr;
    }

    void pop_back() noexcept
    {

    }

    inline bool empty() const noexcept
    {
        return *_size == 0;
    }

    inline size_t size() const noexcept
    {
        return _size;
    }

    Iterator& begin() noexcept
    {
        return *_begin;
    }

    Iterator& end() noexcept
    {
        return *_end;
    }
private:
    void AssignValues(AdvancedNode* const& node)
    {
        _beginningNode = node;
        _begin = new Iterator{ _beginningNode };
        _end = new Iterator{ _beginningNode };
        ++(*_size);
    }

    // В общем нужен LinkedList который может содержать тоже LinkedList
    // в себе и везде размер будет фиксирован. 
    // А лучше сделать так, чтобы пользователь сам решал, фиксированный или нет.
};