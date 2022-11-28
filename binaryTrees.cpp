#include<bits/stdc++.h>
using namespace std;

struct tree{
    int data;
    struct tree *left, *right;

    tree(int val){
        data = val;
        left = NULL, right = NULL;
    }
};

struct compare{
    bool operator()(int a, int b){
        return a > b;
    }
};

void preOrder(tree *root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(tree *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(tree *root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);  
    postOrder(root->right);
    cout << root->data << " ";
}

vector<vector<int>> levelOrder(tree *root){
    vector<vector<int>> ans;
    if(root == NULL){
        return ans;
    }
    queue<tree *> q;
    q.push(root);

    while(!q.empty()){
        vector<int> level;
        int size = q.size();
        for(int i = 0; i < size; i++){
            tree *key = q.front();
            q.pop();
            if(key->left){
                q.push(key->left);
            }
            if(key->right){
                q.push(key->right);
            }
            level.push_back(key->data);
        }
        ans.push_back(level);
    }
    return ans;
}

vector<int> preOrderIterative(tree *root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    tree *temp;
    stack<tree *> st;
    st.push(root);
    while(!st.empty()){
        temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        if(temp->right){
            st.push(temp->right);
        }
        if(temp->left){
            st.push(temp->left);
        }
    }
    return ans;
}

vector<int> inOrderIterative(tree *root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    stack<tree *> st;
    tree *temp = root;
    while(true){
        if(temp != NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty()){
                break;          // it must be here
            }
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}

vector<int> postOrderIterative(tree *root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    stack<tree *> st;
    st.push(root);
    tree *temp;
    while(!st.empty()){
        temp = st.top();
        ans.push_back(temp->data);
        st.pop();
        if(temp->left){
            st.push(temp->left);
        }
        if(temp->right){
            st.push(temp->right);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){

    tree *first = new tree(5);
    tree *second = new tree(10); 
    tree *third = new tree(14); 
    tree *fourth = new tree(15); 
    tree *fifth = new tree(20); 
    tree *sixth = new tree(22); 
    first->left = second;
    first->right = third;
    second->left = fourth;
    second->right = fifth;
    third->left = sixth;
    // delete sixth;

    // inOrder(first);
    // vector<vector<int>> lOrder = levelOrder(first);
    // vector<int> inOrderT = inOrderIterative(first);
    // for(vector<int> it : lOrder){
    //     for(int th : it){
    //         cout << th << " ";
    //     }
    // }

    // for(auto it : inOrderT){
    //     cout << it << " ";
    // }
    // postOrder(first);
    // vector<int> post = postOrderIterative(first);
    // vector<int> pre = preOrderIterative(first);
    // for(auto it : post){
    //     cout << it << " ";
    // }

    priority_queue<int, vector<int>, compare> t;
    t.push(5);
    t.push(16);
    t.push(3);
    t.push(9);
    t.push(23);
    while(!t.empty()){
        cout << t.top() << " ";
        t.pop();
    }
    



    cout << endl;
    return 0;
}