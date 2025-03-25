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

private:
};

class DoublyLinkedList
{
private:
    DLLNode *head;
    DLLNode *tail;
    // basic outline: will change parameters/names and such
    DLLNode *DLL_merge_sort_helper(DLLNode *dllnode);
    void DLL_quick_sort_helper(DLLNode *low, DLLNode *high);
    DLLNode *DLL_quick_sort_partitioner(DLLNode *low, DLLNode *high);
    DLLNode *merge(DLLNode *one_node, DLLNode *two_node);

public:
    // basic outline: will fix them further down the road
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList &other); // for evalutor class
    DLLNode *DLL_merge_sort(DLLNode *one_head);
    void DLL_insertion_sort(DLLNode *head);
    void DLL_quick_sort(DLLNode *head);

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