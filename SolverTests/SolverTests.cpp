#include "pch.h"
#include "CppUnitTest.h"
#include "../Solver/Linkedlist2.h"
#include "../TestClass/Point.h"
#include <assert.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace RUT::MIIT;
using namespace rut::miit::pentagon;
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
            Assert::AreEqual(std::string("123"), list.ToString());
        }

        TEST_METHOD(PushBack_ValidData_Success)
        {
            LinkedList<int> list;
            list.pushBack(1);
            list.pushBack(2);
            Assert::AreEqual(std::string("12"), list.ToString());
        }

        TEST_METHOD(PushFront_ValidData_Success)
        {
            LinkedList<int> list;
            list.pushFront(2);
            list.pushFront(1);
            Assert::AreEqual(std::string("12"), list.ToString());
        }

        TEST_METHOD(PopBack_ValidData_Success)
        {
            LinkedList<int> list{ 1, 2, 3 };
            list.popBack();
            Assert::AreEqual(std::string("12"), list.ToString());
        }

        TEST_METHOD(PopFront_ValidData_Success)
        {
            LinkedList<int> list{ 1, 2, 3 };
            list.popFront();
            Assert::AreEqual(std::string("23"), list.ToString());
        }

        TEST_METHOD(CopyCtor_Success)
        {
            LinkedList<int> list1{ 1, 2, 3 };
            LinkedList<int> list2(list1);
            Assert::AreEqual(std::string("123"), list2.ToString());
        }

        TEST_METHOD(MoveCtor_Success)
        {
            LinkedList<int> list1{ 1, 2, 3 };
            LinkedList<int> list2(std::move(list1));
            Assert::IsTrue(list1.isEmpty() && std::string("123") == list2.ToString());
        }

        TEST_METHOD(AssignmentOperator_ValidData_Success)
        {
            LinkedList<int> list1{ 1, 2, 3 };
            LinkedList<int> list2;
            list2 = list1;
            Assert::AreEqual(std::string("123"), list2.ToString());
        }

        TEST_METHOD(Insert_ValidData_Success)
        {
            LinkedList<int> list{ 1, 3 };
            list.insert(1, 2);
            Assert::AreEqual(std::string("123"), list.ToString());
        }

        TEST_METHOD(InsertAtBeginning_ValidData_Success)
        {
            LinkedList<int> list{ 2, 3 };
            list.insert(0, 1);
            Assert::AreEqual(std::string("123"), list.ToString());
        }

        TEST_METHOD(Remove_ValidData_Success)
        {
            LinkedList<int> list{ 1, 2, 3 };
            list.remove(1);
            Assert::AreEqual(std::string("13"), list.ToString());
        }

        TEST_METHOD(RemoveAtBeginning_ValidData_Success)
        {
            LinkedList<int> list{ 1, 2, 3 };
            list.remove(0);
            Assert::AreEqual(std::string("23"), list.ToString());
        }

        TEST_METHOD(ComplexOperations_ValidData_Success)
        {
            LinkedList<int> list;
            list.pushBack(1);

            list.pushBack(2);
            list.pushFront(0);
            list.popBack();
            Assert::AreEqual(std::string("01"), list.ToString());
        }

        TEST_METHOD(DefaultCtorString_Success)
        {
            LinkedList<std::string> list;
            Assert::IsTrue(list.isEmpty());
        }

        TEST_METHOD(InitializerListCtorString_ValidData_Success)
        {
            LinkedList<std::string> list{ "Hello", "World" };
            Assert::AreEqual(std::string("HelloWorld"), list.ToString());
        }

        TEST_METHOD(AddToBackString)
        {
            LinkedList<std::string> list;
            list.pushBack("Hello");
            list.pushBack("World");
            Assert::AreEqual(std::string("HelloWorld"), list.ToString());
        }

        TEST_METHOD(AddToFrontString)
        {
            LinkedList<std::string> list;
            list.pushFront("World");
            list.pushFront("Hello");
            Assert::AreEqual(std::string("HelloWorld"), list.ToString());
        }

        TEST_METHOD(RemoveLastString)
        {
            LinkedList<std::string> list{ "Hello", "World" };
            list.popBack();
            Assert::AreEqual(std::string("Hello"), list.ToString());
        }

        TEST_METHOD(RemoveFirstString)
        {
            LinkedList<std::string> list{ "Hello", "World" };
            list.popFront();
            Assert::AreEqual(std::string("World"), list.ToString());
        }

        TEST_METHOD(CopyConstructorString)
        {
            LinkedList<std::string> list1{ "Hello", "World" };
            LinkedList<std::string> list2(list1);
            Assert::AreEqual(std::string("HelloWorld"), list2.ToString());
        }

        TEST_METHOD(MoveConstructorString)
        {
            LinkedList<std::string> list1{ "Hello", "World" };
            LinkedList<std::string> list2(std::move(list1));
            Assert::IsTrue(list1.isEmpty() && std::string("HelloWorld") == list2.ToString());
        }

        TEST_METHOD(AssignmentOperatorString)
        {
            LinkedList<std::string> list1{ "Hello", "World" };
            LinkedList<std::string> list2;
            list2 = list1;
            Assert::AreEqual(std::string("HelloWorld"), list2.ToString());
        }

        TEST_METHOD(TestInsertString)
        {
            LinkedList<std::string> list{ "Hello", "World" };
            list.insert(1, "Beautiful");
            Assert::AreEqual(std::string("HelloBeautifulWorld"), list.ToString());
        }

        TEST_METHOD(InsertAtStartString)
        {
            LinkedList<std::string> list{ "World" };
            list.insert(0, "Hello");
            Assert::AreEqual(std::string("HelloWorld"), list.ToString());
        }

        TEST_METHOD(TestRemoveString)
        {
            LinkedList<std::string> list{ "Hello", "Beautiful", "World" };
            list.remove(1);
            Assert::AreEqual(std::string("HelloWorld"), list.ToString());
        }

        TEST_METHOD(DefaultCtorPoint_Success)
        {
            LinkedList<Point> list;
            Assert::IsTrue(list.isEmpty());
        }

        TEST_METHOD(InitializerListCtorPoint_ValidData_Success)
        {
            Point a(0, 0), b(1, 1);
            LinkedList<Point> list{ a, b };
            Assert::IsTrue(a == list.peekFront() && b == list.peekBack());
        }

        TEST_METHOD(AddToBackPoint)
        {
            Point a(0, 0), b(1, 1);
            LinkedList<Point> list;
            list.pushBack(a);
            list.pushBack(b);
            Assert::IsTrue(a == list.peekFront() && b == list.peekBack());
        }

        TEST_METHOD(AddToFrontPoint)
        {
            Point a(0, 0), b(1, 1);
            LinkedList<Point> list;
            list.pushFront(b);
            list.pushFront(a);
            Assert::IsTrue(a == list.peekFront() && b == list.peekBack());
        }

        TEST_METHOD(RemoveLastPoint)
        {
            Point a(0, 0), b(1, 1);
            LinkedList<Point> list{ a, b };
            list.popBack();
            Assert::IsTrue(a == list.peekBack());
        }

        TEST_METHOD(RemoveFirstPoint)
        {
            Point a(0, 0), b(1, 1);
            LinkedList<Point> list{ a, b };
            list.popFront();
            Assert::IsTrue(b == list.peekFront());
        }

        TEST_METHOD(CopyConstructorPoint)
        {
            Point a(0, 0), b(1, 1);
            LinkedList<Point> list1{ a, b };
            LinkedList<Point> list2(list1);
            Assert::AreEqual(list1.ToString(), list2.ToString());
        }

        TEST_METHOD(MoveConstructorPoint)
        {
            Point a(0, 0), b(1, 1);
            LinkedList<Point> list1original{ a, b };
            LinkedList<Point> list1(list1original);
            LinkedList<Point> list2(std::move(list1original));
            Assert::IsTrue(list1original.isEmpty() && list1.ToString() == list2.ToString());
        }

        TEST_METHOD(AssignmentOperatorPoint)
        {
            Point a(0, 0), b(1, 1);
            LinkedList<Point> list1{ a, b };
            LinkedList<Point> list2;
            list2 = list1;
            Assert::AreEqual(list1.ToString(), list2.ToString());
        }

        TEST_METHOD(TestInsertPoint)
        {
            Point a(0, 0), b(1, 1), c(2, 2);
            LinkedList<Point> list{ a, b }, listexp{ a,c,b };
            list.insert(1, c);
            Assert::AreEqual(listexp.ToString(), list.ToString());
        }

        TEST_METHOD(InsertAtStartPoint)
        {
            Point a(0, 0), b(1, 1);
            LinkedList<Point> list{ b }, listexp{ a,b };
            list.insert(0, a);
            Assert::AreEqual(listexp.ToString(), list.ToString());
        }

        TEST_METHOD(TestRemovePoint)
        {
            Point a(0, 0), b(1, 1), c(2, 2);
            LinkedList<Point> list{ a,c,b }, listexp{ a,b };
            list.remove(1);
            Assert::AreEqual(listexp.ToString(), list.ToString());
        }
    };
}