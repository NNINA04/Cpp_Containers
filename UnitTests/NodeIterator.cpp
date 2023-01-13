#include "Common/pch.h"
#include "CppUnitTest.h"
#include "Common/Node.h"
#include "Common/NodeIterator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using Containers::Common::Iterators::NodeIterator;
using Containers::Common::Trees::Nodes::Node;

namespace UnitTests
{
    TEST_CLASS(NodeIteratorTests)
    {
        static int _number;
        static Node<int>* _prevNode;
        static Node<int>* _node;
    public:
        TEST_METHOD(Constructor_WithParameters_DoesNotThrow)
        {
            NodeIterator<int> iterator(_node);
        }

        TEST_METHOD(DereferenceOperator_WithoutParameters_DoesNotThrow)
        {
            NodeIterator<int> iterator(_node);
            Assert::AreEqual(_number, *iterator);
        }

        TEST_METHOD(ArrowOperator_WithoutParameters_DoesNotThrow)
        {
            NodeIterator<int> iterator(_node);
            Assert::AreEqual(_number, iterator->Value);
            Assert::IsTrue(iterator->Prev == _prevNode);
            Assert::IsTrue(iterator->Next == nullptr);
        }

        TEST_METHOD(PrefDecrementOperator_WithoutParameters_DoesNotThrow)
        {
            NodeIterator<int> Iterator{ _node };
            Assert::AreEqual(_number, (--Iterator)->Next->Value);
        }

        TEST_METHOD(PostfDecrementOperator_WithoutParameters_DoesNotThrow)
        {
            NodeIterator<int> Iterator{ _node };
            Assert::AreEqual(_number, (Iterator--)->Value);
        }

        TEST_METHOD(PrefIncrementOperator_WithoutParameters_DoesNotThrow)
        {
            NodeIterator<int> iterator(_node);
            Assert::AreEqual(_number, (++iterator)->Prev->Value);
        }

        TEST_METHOD(PostfIncrementOperator_WithoutParameters_DoesNotThrow)
        {
            NodeIterator<int> iterator(_node);
            Assert::AreEqual(_number, (iterator++)->Value);
        }
    };

    int NodeIteratorTests::_number{ 4 };
    Node<int>* NodeIteratorTests::_prevNode = new Node<int>{};
    Node<int>* NodeIteratorTests::_node = new Node<int>{ _number, _prevNode };
}
