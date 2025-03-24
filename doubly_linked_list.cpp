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

void DoublyLinkedList::DLL_insertion_sort(DLLNode *head){
    if (head == nullptr || head -> next == nullptr){
        return;
    }

    DLLNode* sorted = head;
    DLLNode* unsorted = head->next;

    while (unsorted != nullptr){
        DLLNode* curr = unsorted;
        DLLNode* next = unsorted->next;
        while(curr != nullptr && curr->prev->value > curr->value){
            int temp = curr->value;
            curr->value = curr->prev->value;
            curr->prev->value = temp;
        }
        unsorted = next;
    }

}

void DoublyLinkedList::DLL_quick_sort(DLLNode *head){
    // checks for dll with 0 or 1 elements
    if (head == nullptr || head -> next == nullptr){
        return;
    }
    DLLNode *tail = head;
    while(tail->next!=nullptr){
        tail = tail->next;
    }
    DLL_quick_sort_helper(head,tail);
}

//Sorts the given section of the dll around the pivot
DLLNode* DoublyLinkedList::DLL_quick_sort_partitioner(DLLNode *low, DLLNode *high){
    int pivot_value = low->value;
    DLLNode* i = low;
    DLLNode* j = low->next;
        
        while (j != high->next) {
            if (j->value < pivot_value) {
                i = i->next;
                int temp = i->value;
                i->value = j->value;
                j->value = temp;
            }
            j = j->next;
        }
        int temp = i->value;
        i->value = low->value;
        low->value = temp;
        return i;
}

// recursive calls to sort it
void DoublyLinkedList::DLL_quick_sort_helper(DLLNode* low, DLLNode* high){
    if (low && high && low != high && low != high->next){
        DLLNode* pivot = DLL_quick_sort_partitioner(low, high);
        DLL_quick_sort_helper(low,pivot->prev);
        DLL_quick_sort_helper(pivot->next,high);
    }
    
}
