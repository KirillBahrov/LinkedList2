#include "pch.h"
#include "CppUnitTest.h"
#include "../Solver/Linkedlist2.h"
#include <assert.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace RUT::MIIT;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(DefaultConstructor_Success)
        {
            LinkedList<int> list;
            Assert::IsTrue(list.isEmpty());
        }

        TEST_METHOD(InitializerListConstructor_Success)
        {
            LinkedList<int> list{ 1, 2, 3 };
            Assert::IsFalse(list.isEmpty());
            Assert::AreEqual(std::string("123"), list.toString());
        }

        TEST_METHOD(PushBack_ValidData_Success)
        {
            LinkedList<int> list;
            list.pushBack(1);
            list.pushBack(2);
            Assert::AreEqual(std::string("12"), list.toString());
        }

        TEST_METHOD(PushFront_ValidData_Success)
        {
            LinkedList<int> list;
            list.pushFront(2);
            list.pushFront(1);
            Assert::AreEqual(std::string("21"), list.toString());
        }

        TEST_METHOD(PopBack_ValidData_Success)
        {
            LinkedList<int> list{ 1, 2, 3 };
            list.popBack();
            Assert::AreEqual(std::string("12"), list.toString());
        }

        TEST_METHOD(PopFront_ValidData_Success)
        {
            LinkedList<int> list{ 1, 2, 3 };
            list.popFront();
            Assert::AreEqual(std::string("23"), list.toString());
        }

        TEST_METHOD(CopyCtor_Success)
        {
            LinkedList<int> list1{ 1, 2, 3 };
            LinkedList<int> list2(list1);
            Assert::AreEqual(std::string("123"), list2.toString());
        }

        TEST_METHOD(MoveCtor_Success)
        {
            LinkedList<int> list1{ 1, 2, 3 };
            LinkedList<int> list2(std::move(list1));
            Assert::AreEqual(std::string("123"), list2.toString());
            Assert::IsTrue(list1.isEmpty());
        }

        TEST_METHOD(AssignmentOperator_ValidData_Success)
        {
            LinkedList<int> list1{ 1, 2, 3 };
            LinkedList<int> list2;
            list2 = list1;
            Assert::AreEqual(std::string("123"), list2.toString());
        }

        TEST_METHOD(PopFrontEmpty_ValidData_Success)
        {
            LinkedList<int> list;
            Assert::ExpectException<std::out_of_range>([&list]() { list.popFront(); });
        }

        TEST_METHOD(PopBackEmpty_ValidData_Success)
        {
            LinkedList<int> list;
            Assert::ExpectException<std::out_of_range>([&list]() { list.popBack(); });
        }

        TEST_METHOD(Insert_ValidData_Success)
        {
            LinkedList<int> list{ 1, 3 };
            list.insert(1, 2);
            Assert::AreEqual(std::string("123"), list.toString());
        }

        TEST_METHOD(InsertAtBeginning_ValidData_Success)
        {
            LinkedList<int> list{ 2, 3 };
            list.insert(0, 1);
            Assert::AreEqual(std::string("123"), list.toString());
        }

        TEST_METHOD(InsertOutOfBounds_ValidData_Success)
        {
            LinkedList<int> list{ 1, 2 };
            Assert::ExpectException<std::out_of_range>([&list]() { list.insert(3, 3); });
        }

        TEST_METHOD(Remove_ValidData_Success)
        {
            LinkedList<int> list{ 1, 2, 3 };
            list.remove(1);
            Assert::AreEqual(std::string("13"), list.toString());
        }

        TEST_METHOD(RemoveAtBeginning_ValidData_Success)
        {
            LinkedList<int> list{ 1, 2, 3 };
            list.remove(0);
            Assert::AreEqual(std::string("23"), list.toString());
        }

        TEST_METHOD(RemoveOutOfBounds_ValidData_Success)
        {
            LinkedList<int> list{ 1, 2, 3 };
            Assert::ExpectException<std::out_of_range>([&list]() { list.remove(3); });
        }

        TEST_METHOD(ComplexOperations_ValidData_Success)
        {
            LinkedList<int> list;
            list.pushBack(1);

            list.pushBack(2);
            list.pushFront(0);
            list.popBack();
            Assert::AreEqual(std::string("01"), list.toString());
        }

        TEST_METHOD(DefaultCtorString_Success)
        {
            LinkedList<std::string> list;
            Assert::IsTrue(list.isEmpty());
        }

        TEST_METHOD(InitializerListCtorString_ValidData_Success)
        {
            LinkedList<std::string> list{ "Hello", "World" };
            Assert::IsFalse(list.isEmpty());
            Assert::AreEqual(std::string("HelloWorld"), list.toString());
        }

        TEST_METHOD(AddToBackString)
        {
            LinkedList<std::string> list;
            list.pushBack("Hello");
            list.pushBack("World");
            Assert::AreEqual(std::string("HelloWorld"), list.toString());
        }

        TEST_METHOD(AddToFrontString)
        {
            LinkedList<std::string> list;
            list.pushFront("World");
            list.pushFront("Hello");
            Assert::AreEqual(std::string("HelloWorld"), list.toString());
        }

        TEST_METHOD(RemoveLastString)
        {
            LinkedList<std::string> list{ "Hello", "World" };
            list.popBack();
            Assert::AreEqual(std::string("Hello"), list.toString());
        }

        TEST_METHOD(RemoveFirstString)
        {
            LinkedList<std::string> list{ "Hello", "World" };
            list.popFront();
            Assert::AreEqual(std::string("World"), list.toString());
        }

        TEST_METHOD(CopyConstructorString)
        {
            LinkedList<std::string> list1{ "Hello", "World" };
            LinkedList<std::string> list2(list1);
            Assert::AreEqual(std::string("HelloWorld"), list2.toString());
        }

        TEST_METHOD(MoveConstructorString)
        {
            LinkedList<std::string> list1{ "Hello", "World" };
            LinkedList<std::string> list2(std::move(list1));
            Assert::AreEqual(std::string("HelloWorld"), list2.toString());
            Assert::IsTrue(list1.isEmpty());
        }

        TEST_METHOD(AssignmentOperatorString)
        {
            LinkedList<std::string> list1{ "Hello", "World" };
            LinkedList<std::string> list2;
            list2 = list1;
            Assert::AreEqual(std::string("HelloWorld"), list2.toString());
        }

        TEST_METHOD(PopFirstFromEmptyString)
        {
            LinkedList<std::string> list;
            Assert::ExpectException<std::out_of_range>([&list]() { list.pop_front(); });
        }

        TEST_METHOD(PopLastFromEmptyString)
        {
            LinkedList<std::string> list;
            Assert::ExpectException<std::out_of_range>([&list]() { list.pop_back(); });
        }

        TEST_METHOD(TestInsertString)
        {
            LinkedList<std::string> list{ "Hello", "World" };
            list.insert(1, "Beautiful");
            Assert::AreEqual(std::string("HelloBeautifulWorld"), list.toString());
        }

        TEST_METHOD(InsertAtStartString)
        {
            LinkedList<std::string> list{ "World" };
            list.insert(0, "Hello");
            Assert::AreEqual(std::string("HelloWorld"), list.toString());
        }

        TEST_METHOD(InsertOutOfBoundsString)
        {
            LinkedList<std::string> list{ "Hello", "World" };
            Assert::ExpectException<std::out_of_range>([&list]() { list.insert(3, "OutOfBounds"); });
        }

        TEST_METHOD(TestRemoveString)
        {
            LinkedList<std::string> list{ "Hello", "Beautiful", "World" };
            list.remove(1);
            Assert::AreEqual(std::string("HelloWorld"), list.toString());
        }

        TEST_METHOD(RemoveFirstElementString)
        {
        };
    }
}