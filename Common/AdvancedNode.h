#pragma once

#include "Node.h"

namespace Containers
{
    namespace Common
    {
        namespace Trees
        {
            namespace Nodes
            {
                template<class T>
                class AdvancedNode;
            }
        }
    }
}

template<class T>
class Containers::Common::Trees::Nodes::AdvancedNode : public Node<T>
{
public:
    Node<T>*& SetPrev(const T& value)
    {
        return this->Prev = new Node<T>{ value, nullptr, this };
    }

    Node<T>*& SetNext(const T& value)
    {
        return this->Next = new Node<T>{ value, this };
    }
};