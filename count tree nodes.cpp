#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};



TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter the number of childs of:"<<front->data<<endl;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cout<<"Enter"<<i+1<<"child of"<<front->data<<endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}


int getNodeCount(TreeNode<int>* root) {
    int count=0;
    /*queue is being created and node is being added in the tree as any of the node is popped its children are pushed into queue*/
    queue<TreeNode<int>*>pendingNodes;
    
    pendingNodes.push(root);
    
    while(pendingNodes.size()!=0){
        TreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
    
        count++;
        
        for(int i=0;i<front->children.size();i++){
            pendingNodes.push(front->children[i]);
        }
    }
    return count;
    
    // Write your code here
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout<<"Total number of nodes in the tree:\n";
    cout << getNodeCount(root);
}

