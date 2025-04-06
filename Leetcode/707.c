typedef struct {
    int val;
    struct MyLinkedList *next;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *head=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    head->val=0;
    head->next=NULL;
    return head;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
   if (obj == NULL) return -1;
   MyLinkedList*temp=obj->next;
   int count=0;
   while(temp!=NULL){
    if(count==index){
        return temp->val;
    }
    count++;
    temp=temp->next;
   }
   return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList*temp=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    temp->val=val;
    temp->next=obj->next;
    obj->next=temp;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList*temp=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    temp->val=val;
    temp->next=NULL;
    MyLinkedList*new=obj;
    while(new->next!=NULL){
        new=new->next;
    }
    new->next=temp;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index<0)return ;
    MyLinkedList*temp=obj;
    int count=0;
    while(temp->next!=NULL){
        if(count++==index){
            MyLinkedList*new=(MyLinkedList*)malloc(sizeof(MyLinkedList));
            new->val=val;
            new->next=temp->next;
            temp->next=new;
            return ;
        }
        temp=temp->next;
    }
    if (count == index) {  
        MyLinkedList* new = (MyLinkedList*)malloc(sizeof(MyLinkedList));
        new->val = val;
        new->next = NULL;
        temp->next = new;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index<0) return ;
    MyLinkedList*temp=obj;
    int count=0;
    while(temp->next!=NULL){
        if(count++==index){
            MyLinkedList*temmp=temp->next;
            temp->next=temmp->next;
            free(temmp);
            return ;
        }
        temp=temp->next;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList*temp;
    while(obj!=NULL){
        temp=obj;
        obj=obj->next;
        free(temp);
    }
}
