#include <cstddef>
#include <iostream>
#include <stack>
using namespace std;
class MyTree{
    public:
    MyTree(char a,MyTree*left,MyTree*right){
        ch=a;
        lnode=left;
        rnode=right;
        sign=0;
    }
    MyTree(MyTree*root){
        if(root==NULL){
            return;
        }
        cout<<root->ch<<endl;
        lnode=(root->lnode)?new MyTree(root->lnode):nullptr;
        rnode=(root->rnode)?new MyTree(root->rnode):nullptr;
    }
    ~MyTree(){
        delete lnode;
        delete rnode;
    }
    void build(MyTree*left,MyTree*right){
        this->lnode=left;
        this->rnode=right;
    }
    void recursion(MyTree*root){
        if(root==NULL){
            return ;
        }
        recursion(root->lnode);
        cout<<root->ch<<endl;
        recursion(root->rnode);
    }
    void calculateleaf(MyTree*root,int*p){
        if(root==NULL){
            return ;
        }
        if(root->lnode==NULL&&root->rnode==NULL){
            (*p)++;
        }
        calculateleaf(root->lnode, p);
        calculateleaf(root->rnode, p);
        return ;
    }
    int gettreeheight(MyTree*root){
        if(root==NULL){
            return 0;
        }
        int left=gettreeheight(root->lnode);
        int right=gettreeheight(root->rnode);
        return (left>right?left:right)+1;
    }
    int sign;
    char ch;
    MyTree* lnode;//左节点
    MyTree* rnode;//右节点
};
void lteration(MyTree* root){
    stack<MyTree*> haha;
    haha.push(root);
    while(!haha.empty()){
    
        MyTree* temp=haha.top();
        haha.pop();
        if(!temp->sign){
            temp->sign=1;
            if(temp->lnode!=NULL){
                haha.push(temp->lnode);
            }
            if(temp->rnode!=NULL){
                haha.push(temp->rnode);
            }
        }
        else{
            cout<<temp->ch<<endl;
            haha.pop();
        }
    }
}
void test01(){
    MyTree *A=new MyTree('A',NULL,NULL);
    MyTree *B=new MyTree('B',NULL,NULL);
    MyTree *C=new MyTree('C',NULL,NULL);
    MyTree *D=new MyTree('D',NULL,NULL);
    MyTree *E=new MyTree('E',NULL,NULL);
    MyTree *F=new MyTree('F',NULL,NULL);
    MyTree *G=new MyTree('G',NULL,NULL);
    MyTree *H=new MyTree('H',NULL,NULL);
    A->build(B,F);
    B->build(NULL,C);
    C->build(D,E);
    F->build(NULL,G);
    G->build(H,NULL);
    //A->recursion(A);
    //MyTree *haha=new MyTree(A);
    //haha->recursion(haha);
    lteration(A);
}
int main(){
    test01();
    return 0;
}