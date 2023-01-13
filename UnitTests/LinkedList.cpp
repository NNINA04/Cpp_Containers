#include "Common/pch.h"
#include "CppUnitTest.h"
#include "Common/Node.h"
#include "Common/AdvancedNode.h"
#include "LinkedList/LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using Containers::Common::Trees::Nodes::Node;
using Containers::Common::Trees::Nodes::AdvancedNode;
using Containers::LinkedList;

namespace UnitTests
{

    TEST_CLASS(LinkedListTests)
    {
    public:
        TEST_METHOD(Constructor_WithoutParameters_DoesNotThrow)
        {
            LinkedList<int> list{};
        }

        TEST_METHOD(Constructor_WithParameters_DoesNotThrow)
        {
            Node<int>* node = new Node<int>;;
            LinkedList<int> list1((AdvancedNode<int>*)node);

            //LinkedList<int> list2(Node<int>);
        }
    };
}
