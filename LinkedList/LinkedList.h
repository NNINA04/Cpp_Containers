#pragma once

#include "Common/AdvancedNode.h"

namespace Containers
{
    template<class T>
    class LinkedList;
}

template<class T>
class Containers::LinkedList
{
    Containers::Common::Trees::Nodes::AdvancedNode<T> _node;
public:
    LinkedList(const T& value)
    {
        _node.Value = value;
    }

    // В общем нужен LinkedList который может содержать тоже LinkedList
    // в себе и везде размер будет фиксирован. 
    // А лучше сделать так, чтобы пользователь сам решал, фиксированный или нет.
};