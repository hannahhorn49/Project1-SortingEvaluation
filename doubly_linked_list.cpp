#include "doubly_linked_list.hpp"

DLLNode::DLLNode(int val){
    value = val;
    prev = nullptr;
    next = nullptr;
}

DLLNode::DLLNode(int val, DLLNode *p, DLLNode *n)
{
    value = val;
    prev = p;
    next = n;
}

DoublyLinkedList::DoublyLinkedList()
{
    tail = nullptr;
    head = nullptr;
}

//this function is here to help with testing 
void DoublyLinkedList::push_back(int v)
{
    if (head == nullptr)
    {
        DLLNode *temp = new DLLNode(v);
        head = temp;
        
    }
    else if(head->next->next == nullptr)
    {
        DLLNode *temp = new DLLNode(v, head, nullptr);
        tail = temp;
        head->next = temp;
        
    }
    else{
        DLLNode *iter = tail;
        DLLNode* temp2 = new DLLNode(v, iter, nullptr);
        iter->next = temp2;
        tail = temp2;
        
    }
}

DLLNode* DoublyLinkedList::DLL_merge_sort(DLLNode *head){
    if(head == nullptr)
    {
        //first case: list is empty
        return head;
    }
    else if(head->next == nullptr)
    {
        //next case: list has one element 
        return head;
    }
    else{
        DLLNode *second = DLL_merge_sort_helper(head);

        head = DLL_merge_sort(head);
        second = DLL_merge_sort(second);

        return merge(head, second);
    }
}

DLLNode* DoublyLinkedList::DLL_merge_sort_helper(DLLNode *dllnode){
    DLLNode *two = dllnode;
    DLLNode *one = dllnode;

    //looked at AI on how to find middle of list since no middle values 
    while(two != nullptr && two->next != nullptr && two->next->next != nullptr)
    {
        two = two->next->next;
        one = one->next;
    }

    //this splits the list into two 
    DLLNode *temp = one->next;
    one->next = nullptr;
    if(temp != nullptr)
    {
        temp->prev = nullptr;
    }
    return temp;

}

DLLNode* DoublyLinkedList::merge(DLLNode *one_node, DLLNode *two_node){
    if(one_node == nullptr)
    {
        return two_node;
    }
    else if(two_node == nullptr)
    {
        return one_node;
    }
    else{
        if(one_node->value < two_node->value)
        {
            one_node->next = merge(one_node->next, two_node);
            if(one_node->next != nullptr)
            {
                one_node->next->prev = one_node;
            }
            one_node->prev = nullptr;
            return one_node;
        }
        else{
            two_node->next = merge(one_node, two_node->next);
            if(two_node->next != nullptr)
            {
                two_node->prev->next = two_node;
            }
            two_node->prev = nullptr;
            return two_node;
        }
    }
}
