#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Kaden Sawyer\source\repos\homework 4\HashTable1D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTable1DTests
{
    TEST_CLASS(HashTable1DTests)
    {
    public:
        TEST_METHOD(TestConstructor)
        {
            HashTable1D ht;
            // Verify all slots are initialized to -1
            for (int i = 0; i < 500; i++) {
                Assert::AreEqual(-1, ht.find(i));
            }
        }

        TEST_METHOD(TestInsertNoCollision)
        {
            HashTable1D ht;
            int probes = ht.insert(10);
            Assert::AreEqual(1, probes);
            Assert::AreEqual(1, ht.find(10));
        }

        TEST_METHOD(TestInsertWithCollision)
        {
            HashTable1D ht;
            ht.insert(10);  // Goes to slot 10
            int probes = ht.insert(510);  // Also hashes to slot 10 (510 % 500 = 10)
            Assert::IsTrue(probes > 1);  // Should probe to find next slot
            Assert::AreEqual(probes, ht.find(510));
        }

        TEST_METHOD(TestInsertFullTable)
        {
            HashTable1D ht;
            // Fill the table
            for (int i = 0; i < 500; i++) {
                ht.insert(i);
            }
            // Next insert should fail
            auto func = [&ht] { ht.insert(500); };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestFindExisting)
        {
            HashTable1D ht;
            ht.insert(42);
            int probes = ht.find(42);
            Assert::AreEqual(1, probes);
        }

        TEST_METHOD(TestFindNonExisting)
        {
            HashTable1D ht;
            int probes = ht.find(999);
            Assert::IsTrue(probes > 0);
            Assert::IsTrue(probes <= 500);  // Shouldn't check more than table size
        }

        TEST_METHOD(TestRemoveExisting)
        {
            HashTable1D ht;
            ht.insert(10);
            int removeProbes = ht.remove(10);
            int findProbes = ht.find(10);
            Assert::AreEqual(1, removeProbes);
            Assert::IsTrue(findProbes > 1);  // Shouldn't find after removal
        }

        TEST_METHOD(TestRemoveNonExisting)
        {
            HashTable1D ht;
            int probes = ht.remove(999);
            Assert::IsTrue(probes > 0);
        }

        TEST_METHOD(TestPrintEmptyTable)
        {
            HashTable1D ht;
            // Just verify it doesn't crash
            ht.print();
        }

        TEST_METHOD(TestPrintNonEmptyTable)
        {
            HashTable1D ht;
            ht.insert(10);
            ht.insert(20);
            ht.print();
        }
    };
}