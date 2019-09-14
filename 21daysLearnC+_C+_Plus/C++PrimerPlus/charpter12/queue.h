// queue.h -- interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_
// This queue will contain Customer items
class Customer //顾客类
{
private:
    long arrive;     // arrival time for customer
    int processtime; // processing time for customer
public:
    Customer() : arrive(0), processtime(0) {}
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue //队列类
{
private:
    // class scope definitions
    // Node is a nested structure definition local to this class
    struct Node
    {
        Item item;
        struct Node *next;
    }; //链表操作元素
    enum
    {
        Q_SIZE = 10 //队列容纳10个元素
    };
    // private class members
    Node *front;     // pointer to front of Queue
    Node *rear;      // pointer to rear of Queue
    int items;       // current number of items in Queue
    const int qsize; // maximum number of items in Queue
    // preemptive definitions to prevent public copying
    Queue(const Queue &q) : qsize(0) {}
    Queue &operator=(const Queue &q) { return *this; }

public:
    Queue(int qs = Q_SIZE); // create queue with a qs limit
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item &item); // add item to end
    bool dequeue(Item &item);       // remove item from front
};
#endif

/*
设计一个队列类，列出队列特征：

队列存储有序的项目序列
队列容纳的项目数有一定限制
应当可以创建空队列
能检查队列是否为空
能检查队列是否为满
应当能够队尾添加元素
应当能够队头删除元素
应能确定队列中的项目数

*/