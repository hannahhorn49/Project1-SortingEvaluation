#include "doubly_linked_list.hpp"
#include <iostream>


DLLNode::DLLNode(int val){
    value = val;
    prev = nullptr;
    next = nullptr;
}

DLLNode::DLLNode(int val, DLLNode *n, DLLNode *p)
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
        //std::cout << head->value << std::endl;
        
    }
    else if(head->next == nullptr)
    {
        //std::cout << "in statement" << std::endl;
        DLLNode *temp = new DLLNode(v, nullptr, head);
        tail = temp;
        head->next = temp;
        //std::cout << "past else if" << std::endl;
        
    }
    else{
        //std::cout << "in this else statemnet" << std::endl;
        DLLNode *iter = tail;
        DLLNode* temp2 = new DLLNode(v, nullptr, iter);
        iter->next = temp2;
        tail = temp2;
        
    }
}

DLLNode* DoublyLinkedList::DLL_merge_sort(DLLNode *one_head){
    if(one_head == nullptr)
    {
        //first case: list is empty
        return one_head;
    }
    else if(one_head->next == nullptr)
    {
        //next case: list has one element 
        return one_head;
    }
    else{
        //std::cout << "before split:"; 
        //print_list();
        DLLNode *second = DLL_merge_sort_helper(one_head);
        //std::cout << "past helper" << std::endl;

        DLLNode *firsthead = DLL_merge_sort(one_head);
        second = DLL_merge_sort(second);
        //print_list();
        //std::cout << "going into merge" << get_head()->value << std::endl;

        DLLNode *testing = merge(firsthead, second);
        update_head_tail(testing);
        //std::cout << get_head()->value << std::endl;
        return testing;
    
    }
}

DLLNode* DoublyLinkedList::DLL_merge_sort_helper(DLLNode *dllnode){
    if(dllnode == nullptr || dllnode->next == nullptr)
    {
        return nullptr;
    }
    
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
    //something wrong with this function - not merging correctly
    if(one_node == nullptr)
    {
        return two_node;
    }
    else if(two_node == nullptr)
    {
        return one_node;
    }
    else{
        DLLNode *result = nullptr;
        //std::cout << "else statement" << std::endl;
        //print_list();
        //std::cout << "One node value: " << one_node->value << std::endl;
        //std::cout << "Two node value: " << two_node->value << std::endl;
        if(one_node->value < two_node->value)
        {
            result = one_node;
            result->next = merge(one_node->next, two_node);
            if(result->next != nullptr)
            {
                result->next->prev = result;
            }
            result->prev = nullptr;
            //return one_node;
        }
        else{
            result = two_node;
            result->next = merge(one_node, two_node->next);
            if(result->next != nullptr)
            {
                result->next->prev = result;
            }
            result->prev = nullptr;
            //return two_node;
        }
        /*std::cout << "result value: " << result->value << std::endl;
        if (result->prev != nullptr){
            std::cout << "result's prev: " << result->prev->value << std::endl;
        }
        if(result->next != nullptr)
        {
            std::cout << "result's next: " << result->next->value << std::endl;
        }*/
        return result;

    }
}

//debugging!! 
void DoublyLinkedList::print_list() {
    DLLNode* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::update_head_tail(DLLNode *new_head){
    head = new_head;
    if(head == nullptr)
    {
        tail = nullptr;
        return;
    }
    else{
        DLLNode *current = head;
        while(current->next != nullptr)
        {
            current = current->next;
        }
        tail = current;
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
            curr = curr->prev;
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
