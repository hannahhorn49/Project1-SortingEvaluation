// #ifndef DLL_SORTER_HPP
// #define DLL_SORTER_HPP
#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

class DLLNode
{
public:
    int value;
    DLLNode *prev;
    DLLNode *next;

    DLLNode(int val);
    DLLNode(int v, DLLNode *n, DLLNode *p);
    // do not think we will need a constructor

private:
};

class DoublyLinkedList
{
private:
    DLLNode *head;
    DLLNode *tail;
    // basic outline: will change parameters/names and such
    DLLNode *DLL_merge_sort_helper(DLLNode *dllnode);
    void quick_sort(DLLNode *head);
    DLLNode *merge(DLLNode *one_node, DLLNode *two_node);

public:
    // basic outline: will fix them further down the road
    DoublyLinkedList();
    DLLNode *DLL_merge_sort(DLLNode *one_head);
    void quick_sort();
    void insertion_sort(DLLNode *head);

    // to help with testing:
    DLLNode *get_head() const { return head; }
    DLLNode *get_tail() { return tail; }

    // for testing!!
    void update_head_tail(DLLNode *new_head);
    void push_back(int v);
    void print_list() const;
    int size() const;
    bool is_empty() const;
};

#endif