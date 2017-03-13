class Solution {
public:
	void InOrderTraverse(TreeNode *root){
		if(root->left){
			InOrderTraverse(root->left);
		}
		cout<<root->val;
		cout<<" ";
		if(root->right){
			InOrderTraverse(root->right);
		}
	}

    char* Serialize(TreeNode *root) {
    	char *res = (char *)malloc(sizeof(char)*1000);
    	if(!root){
    		res[0] = '\0';
    		return res;
    	}
    	int i = 0;
    	queue<TreeNode *> q;
    	q.push(root);
    	while(!q.empty()){
    		TreeNode* _t = q.front();
    		q.pop();
    		if(_t){
    			if(_t->left||_t->right){
    				res[i++] = _t->val;
    				q.push(_t->left);
    				q.push(_t->right);
    			}else{
    				// printf("%d\n",_t->val);
    				res[i++] = _t->val;
    			}
    		}else{
    			res[i++] = '#';
    		}
    	}
    	res[i] = '\0';
    	return res;
    }
    TreeNode* Deserialize(char *str) {
    	TreeNode *root = NULL;
    	int i = 0;
    	queue<TreeNode **> q;
    	q.push(&root);
    	while(str[i]!='\0'){
    		if(str[i]=='#'){
    			if(q.empty()){
    				return root;
    			}else{
    				q.pop();
    			}
    		}else{
    			if(q.empty()){
    				//输入用例不合法
    				return NULL;
    			}else{
	    			int val = str[i];
	    			TreeNode **t = q.front();
	    			q.pop();
	    			TreeNode *_p = (TreeNode *)malloc(sizeof(TreeNode));
	    			_p->val = val;
	    			_p->left = _p->right = NULL;
	    			(*t) = _p;
	    			q.push(&(_p->left));
	    			q.push(&(_p->right));
    			}
    		}
    		i++;
    	}
    	return root;
    }
};