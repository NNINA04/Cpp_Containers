#include "Common/pch.h"
#include "CppUnitTest.h"
#include "Common/AdvancedNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using Containers::Common::Trees::Nodes::AdvancedNode;

namespace UnitTests
{
    TEST_CLASS(AdvancedNodeTests)
    {
    public:
        TEST_METHOD(Constructor_WithoutParameters_DoesNotThrow)
        {
            AdvancedNode<int> node{};
        }

        TEST_METHOD(SetPrev_WithParameters_DoesNotThrow)
        {
            AdvancedNode<int> node{};
            int val = 4;
            Assert::AreEqual(val, node.SetPrev(val)->Value);
        }

        TEST_METHOD(SetNext_WithParameters_DoesNotThrow)
        {
            AdvancedNode<int> node{};
            int val = 4;
            Assert::AreEqual(val, node.SetNext(val)->Value);
        }
    };
}
