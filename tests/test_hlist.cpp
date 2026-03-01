#include <gtest/gtest.h>
#include <limits>
#include <sstream>
#include "HList.h"

TEST(HListTest, DefaultConstructor) {
    HList<int> list;
    Iterator<int> it = list.itr();
    EXPECT_FALSE(it.hasNext());
}

TEST(HListTest, CopyConstructor) {
    HList<int> list1;
    list1.addLast(1);
    list1.addLast(2);
    list1.addLast(3);

    HList<int> list2(list1);

    Iterator<int> it1 = list1.itr();
    Iterator<int> it2 = list2.itr();

    while (it1.hasNext() && it2.hasNext()) {
        EXPECT_EQ(it1.next(), it2.next());
    }
    EXPECT_FALSE(it1.hasNext());
    EXPECT_FALSE(it2.hasNext());
}

TEST(HListTest, MoveConstructor) {
    HList<int> list1;
    list1.addLast(1);
    list1.addLast(2);
    list1.addLast(3);

    HList<int> list2(std::move(list1));

    Iterator<int> it = list2.itr();
    EXPECT_EQ(it.next(), 1);
    EXPECT_EQ(it.next(), 2);
    EXPECT_EQ(it.next(), 3);
    EXPECT_FALSE(it.hasNext());
}

TEST(HListTest, CopyAssignment) {
    HList<int> list1;
    list1.addLast(1);
    list1.addLast(2);

    HList<int> list2;
    list2 = list1;

    Iterator<int> it1 = list1.itr();
    Iterator<int> it2 = list2.itr();

    EXPECT_EQ(it1.next(), it2.next());
    EXPECT_EQ(it1.next(), it2.next());
    EXPECT_FALSE(it1.hasNext());
    EXPECT_FALSE(it2.hasNext());
}

TEST(HListTest, MoveAssignment) {
    HList<int> list1;
    list1.addLast(1);
    list1.addLast(2);

    HList<int> list2;
    list2 = std::move(list1);

    Iterator<int> it = list2.itr();
    EXPECT_EQ(it.next(), 1);
    EXPECT_EQ(it.next(), 2);
    EXPECT_FALSE(it.hasNext());
}

TEST(HListTest, AddFirst) {
    HList<int> list;
    list.addFirst(1);
    list.addFirst(2);

    Iterator<int> it = list.itr();
    EXPECT_EQ(it.next(), 2);
    EXPECT_EQ(it.next(), 1);
    EXPECT_FALSE(it.hasNext());
}

TEST(HListTest, AddLast) {
    HList<int> list;
    list.addLast(1);
    list.addLast(2);

    Iterator<int> it = list.itr();
    EXPECT_EQ(it.next(), 1);
    EXPECT_EQ(it.next(), 2);
    EXPECT_FALSE(it.hasNext());
}

TEST(HListTest, InsertAfter) {
    HList<int> list;
    list.addLast(1);
    list.addLast(3);
    list.insertAfter(0, 2);

    Iterator<int> it = list.itr();
    EXPECT_EQ(it.next(), 1);
    EXPECT_EQ(it.next(), 2);
    EXPECT_EQ(it.next(), 3);
    EXPECT_FALSE(it.hasNext());
}

TEST(HListTest, Clear) {
    HList<int> list;
    list.addLast(1);
    list.addLast(2);
    list.clear();

    Iterator<int> it = list.itr();
    EXPECT_FALSE(it.hasNext());
}

TEST(HListTest, DelFirst) {
    HList<int> list;
    list.addLast(1);
    list.addLast(2);
    list.delFirst();

    Iterator<int> it = list.itr();
    EXPECT_EQ(it.next(), 2);
    EXPECT_FALSE(it.hasNext());
}

TEST(HListTest, DelFirstOnEmptyThrows) {
    HList<int> list;
    EXPECT_THROW(list.delFirst(), int);
}

TEST(HListTest, DelLast) {
    HList<int> list;
    list.addLast(1);
    list.addLast(2);
    list.delLast();

    Iterator<int> it = list.itr();
    EXPECT_EQ(it.next(), 1);
    EXPECT_FALSE(it.hasNext());
}

TEST(HListTest, DelLastOnEmptyThrows) {
    HList<int> list;
    EXPECT_THROW(list.delLast(), int);
}

TEST(HListTest, IteratorHasNext) {
    HList<int> list;
    list.addLast(1);

    Iterator<int> it = list.itr();
    EXPECT_TRUE(it.hasNext());
    it.next();
    EXPECT_FALSE(it.hasNext());
}

TEST(HListTest, IteratorNextThrowsWhenEmpty) {
    HList<int> list;
    Iterator<int> it = list.itr();
    EXPECT_THROW(it.next(), int);
}

TEST(HListTest, MultipleIterators) {
    HList<int> list;
    list.addLast(1);
    list.addLast(2);

    Iterator<int> it1 = list.itr();
    Iterator<int> it2 = list.itr();

    EXPECT_EQ(it1.next(), 1);
    EXPECT_EQ(it2.next(), 1);
    EXPECT_EQ(it1.next(), 2);
    EXPECT_EQ(it2.next(), 2);
}

TEST(HListTest, WithStrings) {
    HList<std::string> list;
    list.addLast("hello");
    list.addLast("world");

    Iterator<std::string> it = list.itr();
    EXPECT_EQ(it.next(), "hello");
    EXPECT_EQ(it.next(), "world");
}

TEST(HListTest, WithCustomType) {
    struct Point { int x, y; };
    HList<Point> list;
    list.addLast(Point{ 1, 2 });
    list.addLast(Point{ 3, 4 });

    Iterator<Point> it = list.itr();
    Point p1 = it.next();
    Point p2 = it.next();

    EXPECT_EQ(p1.x, 1);
    EXPECT_EQ(p1.y, 2);
    EXPECT_EQ(p2.x, 3);
    EXPECT_EQ(p2.y, 4);
}

TEST(HListTest, OutputOperator) {
    HList<int> list;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);

    std::stringstream ss;
    ss << list;
    EXPECT_EQ(ss.str(), "[ 1, 2, 3 ]");
}

TEST(HListTest, SelfAssignment) {
    HList<int> list;
    list.addLast(1);
    list.addLast(2);

    list = list;

    Iterator<int> it = list.itr();
    EXPECT_EQ(it.next(), 1);
    EXPECT_EQ(it.next(), 2);
}