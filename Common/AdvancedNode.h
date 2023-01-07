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
    Node<T>*& SetNext(const T*& value)
    {
        DeleteIfNotNull(this->Next);
        return this->Next = new Node<T>{ value };
    }

    Node<T>*& SetPrev(const T*& value)
    {
        DeleteIfNotNull(this->Prev);
        return this->Prev = new Node<T>{ value };
    }
private:
    inline void DeleteIfNotNull(Node<T>*& node)
    {
        if (node != nullptr)
            delete node;
    }
};