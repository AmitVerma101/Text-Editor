#include<bits/stdc++.h>
using namespace std;

struct Node{
    string data;
    Node *next;

    Node(string data){
        this->data=data;
        this->next=NULL;
    }


    
}*head=NULL,*last=NULL;
class CStack {
    //this arr will remember 5 steps
    Node * arr[5];
    int top,front;
    public :
    CStack(){
        top=-1;
        front=-1;
    }
    Node *copyLL(Node *head){
        if(head==NULL){
            return NULL;
        }
        Node *temp=head;
        Node *myHead=NULL;
        Node *l=NULL;
        while(temp){
            if(myHead==NULL){
                myHead=new Node(temp->data);
                l=myHead;
            }
            else {
                l->next=new Node(temp->data);
                l=l->next;
            }
            temp=temp->next;
        }

        return myHead;
    }
    
    void push(){
        
        Node *temp=copyLL(head);
        if(top==-1&&front==-1){
            top=0;
            front=0;
            arr[top]=temp;
            
        }

        else if((top+1)%5==front){
            front=(front+1)%5;
            top=(top+1)%5;
            arr[top]=temp;
           
        }
        else {
            top=(top+1)%5;

            arr[top]=temp;
            
        }

    }
    void pop(){
        if(front==-1){
            cout<<"operation not possible\n";
        }
        else if(front==top){
            head=arr[top];

            front=top=-1;
        }
        else if(top==0){
            head=arr[top];
            top=4;
        }
        else {
             head=arr[top];
            top=(top-1)%5;
        }
    }
    void empty(){
        front=-1;
        top=-1;
    }
};
void takeInput();

void insert(string temp){
        //this
        
        if(temp.length()!=0){
            
          if(head==NULL){
            head = new Node(temp);
            last=head;
         }
         else {
             last->next=new Node(temp);
             last=last->next;
         }

        }
       
    }


    void append(){
        takeInput();
    }
    void display(){
        Node *temp=head;
        if(temp==NULL){
            cout<<"Nothing to display!!\n";
        }
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

void takeInput(){
    char ch;
    string temp;
     fflush(stdin);
    do {
        
       ch=getchar();
       if(ch!='\n'&&ch!=' '&&ch!='`'){
            temp+=ch;
       }
       else{
          insert(temp);
          temp="";
       }
      
    }while(ch!='`');
    insert(temp);
    fflush(stdin);
}
void search(){
    string word;
    bool flag=false;
    int count=0;
    cout<<"Enter the string to be searched\n";
    cin>>word;
    Node *temp=head;
    
    while(temp){
        if(temp->data==word){
            flag=true;
            break;
        }
        else {
            count++;
            temp=temp->next;
        }
    }
     if(!flag){
        count=-1;
     }
    cout<<"Word Found at "<<count<<" Index\n";
}

void deleteNode(){
    string word;
    cout<<"Enter the word to be deleted\n";
    cin>>word;
    Node *temp=head;
    Node *l=NULL;
    while(temp){
        if(temp->data==word){
            break;
        }
        l=temp;
        temp=temp->next;
    }

    //deleting the node to be deleted
      if(temp==head){
        head=head->next;
        delete temp;
      }
      else if(temp==last){
        l->next=temp->next;
        last=l;
        delete temp;
      }
      else {
        l->next=temp->next;
        delete(temp);
      }

}
           
void update(){
    string w1;
    string w2;
    cout<<"Enter the word before which you want to insert\n";
    cin>>w1;
    cout<<"Enter the word \n";
    cin>>w2;
    fflush(stdin);
    Node *temp=head;
    Node *l=NULL;
    while(temp){
        if(temp->data==w1){
            break;
        }
        l=temp;
        temp=temp->next;
    }
    Node *n=new Node(w2);
    if(l==NULL){
         n->next=head;
         head=n;
    }
    else {
        n->next=temp;
        l->next=n;
    }
      
        
}
int main(){
      char ch;
      CStack cs;
      CStack redo;
      while(true){
              cout<<"i-insert a-append d-display k-delete s-search u-update z-undo y-redo p-save e-exit\n";
               cin>>ch;

               switch(ch){
                case 'i': 
                     redo.empty();
                     cs.push();
                     cout<<"Enter the string\n";
                     head=NULL;
                     last=NULL;
                     takeInput();
                     break;
                 case 'a':
                      redo.empty();
                      cs.push();
                      cout<<"Enter the string to be append\n";
                      append();
                      break;
                 case 'd':
                      display();
                      break;
                case 'u':
                      redo.empty();
                      cs.push();
                      update();
                      break;
                case 's':
                     search();
                     break;

                case 'k':
                     redo.empty();
                     cs.push();
                     deleteNode();
                     break;
                 case 'z':
                      redo.push();
                      cs.pop();
                     
                      break;
                 case 'y':
                       cs.push();
                       redo.pop();
                       break;
                 case 'p':{

                 
                          string s;
                          cout<<"Enter the file name \n";
                          cin>>s;
                          ofstream MyFile(s);

                            // Write to the file
                            Node *temp=head;
                            while(temp){
                                string t=temp->data;
                                MyFile << t+' ';
                                temp=temp->next;
                            }
                           // Close the file
                            MyFile.close();
                            cout<<"File Saved Successfully\n";
                            break;
                            }
                 case 'e':
                       exit(0);
               }
              
               
              
      }
       
   

    return 0;
}