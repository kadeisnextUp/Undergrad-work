#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Kaden Sawyer\source\repos\homework 4\HashTable2D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTable2DTests
{
    TEST_CLASS(HashTable2DTests)
    {
    public:
        TEST_METHOD(TestConstructor)
        {
            HashTable2D ht;
            // Verify all slots are initialized to -1
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 5; j++) {
                    Assert::AreEqual(-1, ht.find(i * 100 + j));
                }
            }
        }

        TEST_METHOD(TestInsertNoCollision)
        {
            HashTable2D ht;
            int probes = ht.insert(10);
            Assert::AreEqual(1, probes);
            Assert::AreEqual(1, ht.find(10));
        }

        TEST_METHOD(TestInsertSameRow)
        {
            HashTable2D ht;
            ht.insert(10);  // Row 10, first slot
            int probes = ht.insert(110);  // Also row 10 (110 % 100 = 10)
            Assert::AreEqual(2, probes);  // Should go to second slot in same row
            Assert::AreEqual(2, ht.find(110));
        }

        TEST_METHOD(TestInsertFullRow)
        {
            HashTable2D ht;
            // Fill row 10
            ht.insert(10);
            ht.insert(110);
            ht.insert(210);
            ht.insert(310);
            ht.insert(410);

            // Next insert in same row should fail
            auto func = [&ht] { ht.insert(510); };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestFindExisting)
        {
            HashTable2D ht;
            ht.insert(42);
            int probes = ht.find(42);
            Assert::AreEqual(1, probes);
        }

        TEST_METHOD(TestFindNonExisting)
        {
            HashTable2D ht;
            int probes = ht.find(999);
            Assert::IsTrue(probes > 0);
            Assert::IsTrue(probes <= 5);  // Should only check one row
        }

        TEST_METHOD(TestRemoveExisting)
        {
            HashTable2D ht;
            ht.insert(10);
            int removeProbes = ht.remove(10);
            int findProbes = ht.find(10);
            Assert::AreEqual(1, removeProbes);
            Assert::IsTrue(findProbes > 1);  // Shouldn't find after removal
        }

        TEST_METHOD(TestRemoveFromFullRow)
        {
            HashTable2D ht;
            // Fill row 20
            ht.insert(20);
            ht.insert(120);
            ht.insert(220);
            ht.insert(320);
            ht.insert(420);

            // Remove and verify we can insert again
            int removeProbes = ht.remove(20);
            int insertProbes = ht.insert(520);
            Assert::AreEqual(1, removeProbes);
            Assert::AreEqual(1, insertProbes);
        }

        TEST_METHOD(TestPrintEmptyTable)
        {
            HashTable2D ht;
            // Just verify it doesn't crash
            ht.print();
        }

        TEST_METHOD(TestPrintNonEmptyTable)
        {
            HashTable2D ht;
            ht.insert(10);
            ht.insert(20);
            ht.print();
        }
    };
}