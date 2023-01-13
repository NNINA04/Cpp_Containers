#pragma once

#include "Node.h"

namespace Containers
{
    namespace Common
    {
        namespace Iterators
        {
            template<class T>
            class NodeIterator;
        }
    }
}

template<class T>
class Containers::Common::Iterators::NodeIterator
{
    using Node = Containers::Common::Trees::Nodes::Node<T>;

    Node* _node;
public:
    NodeIterator(Node* const& beginningNode)
    {
        _node = beginningNode;
    }

    T& operator*() const noexcept
    {
        return _node->Value;
    }

    Node* operator->() const noexcept
    {
        return _node;
    }

    NodeIterator<T>& operator--() noexcept
    {
        AllocateAndAssignPrev(_node->Prev);
        return *this;
    }

    NodeIterator<T> operator--(int) noexcept
    {
        NodeIterator<T> _Tmp = *this;
        AllocateAndAssignPrev(_node->Prev);
        return _Tmp;
    }

    NodeIterator<T>& operator++() noexcept // 1
    {
        AllocateAndAssignNext(_node->Next);
        return *this;
    }

    NodeIterator<T> operator++(int) noexcept
    {
        NodeIterator<T> _Tmp = *this;
        AllocateAndAssignNext(_node->Next);
        return _Tmp;
    }

    bool operator!=(const NodeIterator& other) const 
    {
        return _node != other._node->Next;
    }
private:
    inline void AllocateAndAssignPrev(Node*& node)
    {
        if (node == nullptr)
            node = new Node{ 0, nullptr, _node };
        else if (node->Next == nullptr)
            node->Next = _node;
        _node = node;
    }

    inline void AllocateAndAssignNext(Node*& node)
    {
        if (node == nullptr)
            node = new Node{ 0, _node };
        else if (node->Prev == nullptr)
            node->Prev = _node;
        _node = node;
    }
};