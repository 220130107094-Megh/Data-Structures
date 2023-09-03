#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;

// class stack{
//     public:
//     int *arr;
//     int size;
//     int top1;
//     int top2;


//     stack(int size){
//         arr = new int[size];
//         this->size=size;
//         top1=-1;
//         top2=size;
//     }
//     void Push1(int data){
//         if(top2-top1>1){
//             top1++;
//             arr[top1]=data;
//         }
//         else{
//             cout<<"Overflow Stack : 1"<<endl;
//         }
//     }

//     void Pop1(){
//         if(top1 ==-1){
//             cout<<"Underflow Stack : 1"<<endl;
//         }else{
//           top1--;
//           arr[top1]=0;
//         }
//     }

//     void Push2(int data){
//         if(top2-top1>1){
//             top2--;
//             arr[top2]=data;
//         }
//         else{
//             cout<<"Overflow Stack : 2"<<endl;
//         }
//     }

//     void Pop2(){
//         if(top2==size-1){
//             cout<<"Underflow Stack : 2"<<endl;
//         }else{
//           arr[top2]=0;
//           top2++;
//         } 
//     }

//     void Print(){
//         cout<<endl;
//         cout<<"Top1 : "<<top1<<endl;
//         cout<<"Top2 : "<<top2<<endl;
//         for(int i=0;i<size;i++){
//             cout<<arr[i]<<" ";
//         }cout<<endl;
//     }
// };


void printMiddle(stack<int>&s, int &totalsize){
    if(s.size()==totalsize/2+1){
        cout<<"Middle Element is : "<<s.top()<<endl;
        return;
    }
    int temp=s.top();
    s.pop();

    printMiddle(s,totalsize);

    s.push(temp);

}

void Solve(stack<int> &s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }

    int topElement=s.top();
    s.pop();

    Solve(s,target);

    s.push(topElement);
}

void insertAtBottam(stack<int> &s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }
    int topElement=s.top();
    s.pop();
    insertAtBottam(s,target);

    s.push(topElement);
    
}

void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int target=s.top();
    s.pop();
    reverseStack(s);
    insertAtBottam(s,target);
}

void insertSorted(stack<int> &s ,int target){
    if(s.empty()){
        s.push(target);
        return;
    }
    if(s.top()>=target){
        s.push(target);
        return;
    }

    int topElement=s.top();
    s.pop();
    insertSorted(s,target);

    s.push(topElement);
}

void Sorted(stack<int> &s){
    if(s.empty()){
        return;
    }
    int topElement=s.top();
    s.pop();
    Sorted(s);
    insertSorted(s,topElement);
}

vector<int> PrevSmallerElement(vector<int> &v){
    stack<int> s;
    s.push(-1);
    vector<int> ans(v.size());
    for(int i=0;i<v.size();i++){
        int curr = v[i];
        while(s.top()!=-1 && v[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

vector<int> NextSmallerElement(vector<int> &v){
    stack<int> s;
    s.push(-1);
    vector<int> ans(v.size());
    for(int i=v.size()-1;i>=0;i--){
        int curr = v[i];
        while( s.top()!=-1 && v[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

int getRectangularArea(vector<int> &v){
    vector<int> prev=PrevSmallerElement(v);
    vector<int> next=NextSmallerElement(v);
     
    int maxArea=INT_MIN;
    int size=v.size();

    for(int i=0;i<v.size();i++){
        int length=v[i];

        if(next[i]==-1){
            next[i]=size;
        }

        int width=next[i]-prev[i]-1;
        int area=length*width;
        maxArea=max(maxArea,area);
    }

    return maxArea;

}

int main(){
    // stack<int> s;
    
    // s.push(10);
    // s.push(20);
    // s.push(50);
    // s.push(40);
    // s.push(30);
    // Sorted(s);
   
    //s.push(50);
    //reverseStack(s);
    // if(s.empty()){
    //     cout<<"Stack is Empty"<<endl;
    // }
    // int target=s.top();
    // s.pop(); 
    // insertAtBottam(s,target);
    // cout<<s.top()<<endl;
    // cout<<"Printing Stack"<<endl;
    // while(!s.empty()){
    //     cout<<s.top()<<endl;
    //     s.pop();
    // }cout<<endl;

    //s.push(60);
    //s.push(70);
    // int totalsize=s.size();
    // printMiddle(s,totalsize);

    
    // stack s(10);
    // s.Push1(10);
    // s.Print();
    // s.Push1(10);
    // s.Print();
    // s.Push1(10);
    // s.Print();
    // s.Push1(10);
    // s.Print();
    // s.Push1(10);
    // s.Print();
    // s.Push1(50);
    // s.Print();
    // s.Push1(70);
    // s.Print();
    // s.Push2(40);
    // s.Print();
    // s.Push2(30);
    // s.Print();
    // s.Push2(10);
    // s.Print();

    // s.Pop1();
    // s.Print();
    // s.Pop1();
    // s.Print();
    // s.Pop1();
    // s.Print();
    // s.Pop1();
    // s.Print();
    // s.Pop1();
    // s.Print();
    // s.Pop1();
    // s.Print();
    // s.Pop1();
    // s.Print();
    // s.Pop2();
    // s.Print();
    // s.Pop2();
    // s.Print();
    // s.Pop2();
    // s.Print();
    
    vector <int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    cout<<"Largest Area In Histrogram is : "<<getRectangularArea(v)<<endl;


    stack<int> s;
    s.push(-1);
    vector<int> ans(v.size());
    for(int i=v.size()-1;i>=0;i--){
        int curr = v[i];
        while(s.top()>curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
    }

    vector<int> ans1=PrevSmallerElement(v);

    cout<<"Printing In PrevOrder : "<<endl;
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<" ";
    }cout<<endl;

    vector<int> ans2=NextSmallerElement(v);

    cout<<"Printing In NextOrder : "<<endl;
    for(int i=0;i<ans2.size();i++){
        cout<<ans2[i]<<" ";
    }cout<<endl;


    return 0;
}