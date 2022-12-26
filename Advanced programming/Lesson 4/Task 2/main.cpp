#pragma once

#include <iostream>

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {       
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

TEST_CASE("PushFront function test", "[PushFront]")
{
    List list;
    list.PushFront(1);
    list.PushFront(2);
    list.PushFront(3);
    list.PushFront(4);
    INFO("Element was not added to the head");
    CHECK(list.PopFront() == 4);
    CHECK(list.PopFront() == 3);
    CHECK(list.PopFront() == 2);
}

TEST_CASE("PushBack function test", "[PushBack]")
{
    List list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.PushBack(4);
    INFO("Element was not added to the tail");
    CHECK(list.PopBack() == 4);
    CHECK(list.PopBack() == 3);
    CHECK(list.PopBack() == 2);
}

TEST_CASE("PopFront function test", "[PopFront]")
{
    List list;
    SECTION("List with elements")
    {
        list.PushFront(1);
        list.PushFront(2);
        list.PushFront(3);
        list.PushFront(4);
        INFO("Not the first element was removed");
        CHECK(list.PopFront() == 4);
        CHECK(list.PopFront() == 3);
        CHECK(list.PopFront() == 2);
        CHECK(list.PopFront() == 1);
    }
    SECTION("empty List")
    {
        CHECK(list.PopFront());
    }
    
}

TEST_CASE("PopBack function test", "[PopBack]")
{
    List list;
    SECTION("List with elements")
    {
        list.PushFront(1);
        list.PushFront(2);
        list.PushFront(3);
        list.PushFront(4);
        INFO("Not the last element was removed");
        CHECK(list.PopBack() == 1);
        CHECK(list.PopBack() == 2);
        CHECK(list.PopBack() == 3);
        CHECK(list.PopBack() == 4);
    }
    SECTION("empty List")
    {
        CHECK(list.PopBack());
    }
}

TEST_CASE("Set of functions test", "[Set of functions]")
{
    List list;
    list.PushFront(1);
    list.PushBack(2);
    list.PushFront(0);
    list.PushBack(3);
    list.PopFront();
    list.PopBack();
    CHECK(list.PopFront() == 1);
    CHECK(list.PopBack() == 2);
}



int main(int argc, char* argv[])
{
    return Catch::Session().run(argc, argv);
}