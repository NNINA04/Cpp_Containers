#pragma once

namespace Containers
{
    namespace Common
    {
        namespace Trees
        {
            namespace Nodes
            {
                template<class T>
                class Node;
            }
        }
    }
}

template<class T>
class Containers::Common::Trees::Nodes::Node
{
public:
    Node*& Prev;
    Node*& Next;
    T*& Value;
};