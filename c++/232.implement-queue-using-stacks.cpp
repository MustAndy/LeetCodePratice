/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */
#include <stack>
using namespace std;
class MyQueue
{
    stack<int> sta;
    stack<int> temp;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        int length = sta.size();
        for (int i = 0; i < length; ++i)
        {
            temp.push(sta.top());
            sta.pop();
        }
        temp.push(x);
        for (int i = 0; i < length + 1; ++i)
        {
            sta.push(temp.top());
            temp.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int popTop = sta.top();
        sta.pop();
        return popTop;
    }

    /** Get the front element. */
    int peek()
    {
        return sta.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return sta.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
