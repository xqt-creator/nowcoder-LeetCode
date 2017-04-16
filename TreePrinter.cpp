/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class TreePrinter {
public:
    vector<vector<int> > printTree(TreeNode* root) {
        // write code here
        vector<int> tempVector;
        vector<vector<int> > resultVector;
        queue<TreeNode *> queue;
        TreeNode *last = root;
        TreeNode *nlast = root;
        
        queue.push(root);
        while(!queue.empty()){
            TreeNode *current = queue.front();
            tempVector.push_back(current->val);
            queue.pop();
            if(current->left){
                queue.push(current->left);
                nlast = current->left;
            }
            if(current->right){
                queue.push(current->right);
                nlast = current->right;
            }
            if(current == last){
                resultVector.push_back(tempVector);
                last = nlast;
                tempVector.clear();
            }
         
        }
        return resultVector;
    }
};

 