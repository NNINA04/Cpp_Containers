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

    // � ����� ����� LinkedList ������� ����� ��������� ���� LinkedList
    // � ���� � ����� ������ ����� ����������. 
    // � ����� ������� ���, ����� ������������ ��� �����, ������������� ��� ���.
};