#ifndef DLL_SORTER_HPP
#define DLL_SORTER_HPP

class DoublyLinkedList{
    private:
        DLLNode *head;
        DLLNode *tail;
        //basic outline: will change parameters/names and such 
        DLLNode* merge_sort(DLLNode *dllnode);
        void quick_sort(DLLNode *head);
        DLLNode* merge(DLLNode *one_node, DLLNode *two_node);


    public:
        //basic outline: will fix them further down the road
        DLLNode* merge_sort(DLLNode *head);
        void quick_sort();
        void insertion_sort(DLLNode *head);

        DLLNode *get_head(){ return head;}
        DLLNode *get_tail(){ return tail;}

};

class DLLNode{
    public: 
        int value;
        DLLNode* prev;
        DLLNode* next;

        DLLNode();
        DLLNode(int v, DLLNode* n, DLLNode *p);
        //do not think we will need a constructor
    
    
    private: 


};

#endif