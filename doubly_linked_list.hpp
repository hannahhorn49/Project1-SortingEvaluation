#ifndef DLL_SORTER_HPP
#define DLL_SORTER_HPP

class DoublyLinkedList{
    private:
        DLLNode *head;
        DLLNode *tail;
        //basic outline: will change parameters/names and such 
        void merge_sort();
        void quick_sort();
        void merge();


    public:
        //basic outline: will fix them further down the road
        void merge_sort(DLLNode *head);
        void quick_sort();
        void insertion_sort();

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