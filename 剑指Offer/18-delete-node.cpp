// struct ListNode{
//     int value;
//     ListNode* next;
// }

void deleteNode(ListNode* head, ListNode* toDelete)
{
    if(head==nullptr || deleteNode==nullptr)
        return;
    if(toDelete->next != nullptr)
    {
        ListNode* next = toDelete->next;
        toDelete->val = next->val;
        toDelete->next = next->next;
        delete next;
        next=nullptr;
    }
    else if(head==toDelete)//链表只有一个节点
    {
        delete toDelete;
        toDelete = nullptr;
        head = nullptr;
    }else{
        //链表中有多个阶段，删除尾节点
        ListNode* node = head;
        while(node->next!=toDelete && node->next!=null){
            node = node->next;
        }
        // if(node->next==nullptr)//加一个判读啊如果
        //     return;
        node->next=nullptr
        delete toDelete;
        toDelete = nullptr;
    }
}