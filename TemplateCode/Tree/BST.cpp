#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Queue : public queue<T> {
public:
    T pop() {
        T tmp = front();
        stack<T>::pop();
        return tmp;
    }
};

template <typename T>
class Stack : public stack<T> {
public:
    T pop() {
        T tmp = top();
        stack<T>::pop();
        return tmp;
    }
};

template <typename T>
class BSTNode {
public:
    T val;
    BSTNode<T>*left, *right;
    BSTNode() : left(nullptr), right(nullptr) {}
    BSTNode(const T& v, BSTNode<T>* l = nullptr, BSTNode<T>* r = nullptr) {
        val = v;
        left = l;
        right = r;
    }
};

//添加内容，build tree
//前序，中序 build
//前序，后序 build
//中序，后序 build
// string level build
// array build

//遍历方式
// Z travel
//垂序遍历
//右视图
//外边界

template <class T>
class BST {
public:
    BST() {
        root = nullptr;
    }
    ~BST() {
        clear();
    }
    void clear() {
        clear(root);
        root = nullptr;
    }
    bool empty() const {
        return root == nullptr;
    }
    void preorder() {
        preorder(root);
    }
    void inorder() {
        inorder(root);
    }
    void postorder() {
        postorder(root);
    }
    void levelorder();
    void insert(const T&);
    void recursive_insert(const T& val) {
        recursive_insert(root, val);
    }
    T* search(const T& val) const;
    T* recursive_search(const T& val) const {
        return recursive_search(root, val);
    }
    void remove_by_copy(BSTNode<T>*&);
    void find_and_remove_by_copy(const T&);
    void remove_by_merge(BSTNode<T>*&);
    void find_and_remove_by_merge(const T&);
    void iterative_preorder();
    void iterative_inorder();
    void iterative_postorder();
    void morris_preorder();
    void morris_inorder();
    void morris_postorder();
    void balance(T*, int, int);

protected:
    BSTNode<T>* root;
    void clear(BSTNode<T>*);
    void recursive_insert(BSTNode<T>*&, const T&);
    T* search(BSTNode<T>*, const T&) const;
    T* recursive_search(BSTNode<T>*, const T&) const;
    void preorder(BSTNode<T>*);
    void inorder(BSTNode<T>*);
    void postorder(BSTNode<T>*);
    virtual void visit(BSTNode<T>* node) {
        cout << node->val << ' ';
    }
};

template <typename T>
void BST<T>::clear(BSTNode<T>* root) {
    if(!root) return;
    clear(root->left);
    clear(root->right);
    delete root;
}

template <typename T>
void BST<T>::insert(const T& val) {
    BSTNode<T>*curr = root, *prev = nullptr;
    while(curr) {
        prev = curr;
        if(val < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if(!root)
        root = new BSTNode<T>(val);
    else if(val < prev->val)
        prev->left = new BSTNode<T>(val);
    else
        prev->right = new BSTNode<T>(val);
}

template <typename T>
void BST<T>::recursive_insert(BSTNode<T>*& root, const T& val) {
    if(!root)
        root = new BSTNode<T>(val);
    else if(val < root->val)
        recursive_insert(root->left, val);
    else
        recursive_insert(root->right, val);
}

template <typename T>
T* BST<T>::search(const T& val) const {
    BSTNode<T>* curr = root;
    while(curr) {
        if(val == curr->val)
            return &curr->val;
        else if(val < root->val)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return nullptr;
}

template <class T>
T* BST<T>::recursive_search(BSTNode<T>* root, const T& val) const {
    if(!root) return nullptr;
    if(val == root->val)
        return &root->val;
    else if(val < root->val)
        return recursive_earch(root->left, val);
    else
        return recursive_search(root->right, val);
}

template <class T>
void BST<T>::inorder(BSTNode<T>* root) {
    if(!root) return;
    inorder(root->left);
    visit(root);
    inorder(root->right);
}

template <class T>
void BST<T>::preorder(BSTNode<T>* root) {
    if(!root) return;
    visit(root);
    preorder(root->left);
    preorder(root->right);
}

template <class T>
void BST<T>::postorder(BSTNode<T>* root) {
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    visit(root);
}

template <class T>
void BST<T>::levelorder() {
    if(!root) return;
    Queue<BSTNode<T>*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        for(int i = 0; i < n; ++i) {
            auto curr = q.pop();
            visit(curr);
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        cout << endl;
    }
}

template <class T>
void BST<T>::remove_by_copy(BSTNode<T>*& node) {
    if(!node) return;
    BSTNode<T>*prev, *tmp = node;
    if(!node->right)
        node = node->left;
    else if(!node->left)
        node = node->right;
    else {
        tmp = node->left;
        prev = node;
        while(tmp->right) {
            prev = tmp;
            tmp = tmp->right;
        }
        node->val = tmp->val;
        if(prev == node)
            prev->left = tmp->left;
        else
            prev->right = tmp->left;
    }
    delete tmp;
}

template <class T>
void BST<T>::find_and_remove_by_copy(const T& val) {
    BSTNode<T>*curr = root, *prev = nullptr;
    while(curr && curr->val != val)) {
            prev = curr;
            if(val < curr->val)
                curr = curr->left;
            else
                curr = curr->right;
        }
    if(curr && curr->val == val)
        if(curr == root)
            remove_by_copy(root);
        else if(prev->left == curr)
            remove_by_copy(prev->left);
        else
            remove_by_copy(prev->right);
    else if(root)
        cout << "val: " << val << " is not in the tree\n";
    else
        cout << "the tree is empty\n";
}

template <class T>
void BST<T>::remove_by_merge(BSTNode<T>*& node) {
    if(!node) return;
    BSTNode<T>* tmp = node;
    if(!node->right)
        node = node->left;
    else if(!node->left)
        node = node->right;
    else {
        tmp = node->left;
        while(tmp->right) {
            tmp = tmp->right;
        }
        tmp->right = node->right;
        tmp = node;
        node = node->left;
    }
    delete tmp;
}

template <class T>
void BST<T>::find_and_remove_by_merge(const T& val) {
    BSTNode<T>*curr = root, *prev = nullptr;
    while(curr && curr->val != val) {
        prev = curr;
        if(val < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if(curr && curr->val == el)
        if(curr == root)
            remove_by_merge(root);
        else if(prev->left == curr)
            remove_by_merge(prev->left);
        else
            remove_by_merge(prev->right);
    else if(root)
        cout << "val: " << val << " is not in the tree\n";
    else
        cout << "the tree is empty\n";
}

template <class T>
void BST<T>::iterative_preorder() {
    if(!root) return;
    Stack<BSTNode<T>*> s;
    s.push(root);
    while(!s.empty()) {
        auto curr = s.pop();
        visit(curr);
        if(!curr->right)
            s.push(curr->right);
        if(!curr->left != 0)
            s.push(curr->left);
    }
}

template <class T>
void BST<T>::iterative_inorder() {
    Stack<BSTNode<T>*> s;
    BSTNode<T>* curr = root;
    while(curr) {
        while(curr) {
            if(curr->right)
                s.push(curr->right);
            s.push(curr);
            curr = curr->left;
        }
        curr = s.pop();
        while(!s.empty() && !curr->right) {
            visit(curr);
            curr = s.pop();
        }
        visit(curr);
        curr = !s.empty() ? s.pop() : nullptr;
    }
}

template <class T>
void BST<T>::iterative_postorder() {
    Stack<BSTNode<T>*> s;
    BSTNode<T>*p = root, *q = root;
    while(p != 0) {
        for(; p->left != 0; p = p->left)
            travStack.push(p);
        while(p->right == 0 || p->right == q) {
            visit(p);
            q = p;
            if(travStack.empty())
                return;
            p = travStack.pop();
        }
        travStack.push(p);
        p = p->right;
    }
}

template <class T>
void BST<T>::morris_inorder() {
    BSTNode<T>*p = root, *tmp;
    while(p != 0)
        if(p->left == 0) {
            visit(p);
            p = p->right;
        } else {
            tmp = p->left;
            while(tmp->right != 0 && tmp->right != p)
                tmp = tmp->right;
            if(tmp->right == 0) {
                tmp->right = p;
                p = p->left;
            } else {
                visit(p);
                tmp->right = 0;
                p = p->right;
            }
        }
}

template <class T>
void BST<T>::morris_preorder() {
    BSTNode<T>*p = root, *tmp;
    while(p != 0) {
        if(p->left == 0) {
            visit(p);
            p = p->right;
        } else {
            tmp = p->left;
            while(tmp->right != 0 &&  // go to the rightmost node of
                  tmp->right != p)    // the left subtree or
                tmp = tmp->right;     // to the temporary parent of p;
            if(tmp->right == 0) {     // if 'true' rightmost node was
                visit(p);             // reached, visit the root and
                tmp->right = p;       // make the rightmost node a temporary
                p = p->left;          // parent of the current root,
            } else {                  // else a temporary parent has been
                tmp->right = 0;       // found; cut the right pointer of
                p = p->right;         // the current parent, whereby it ceases
            }                         // to be a parent;
        }
    }
}

template <class T>
void BST<T>::morris_postorder() {
    BSTNode<T>*p = new BSTNode<T>(), *tmp, *q, *r, *s;
    p->left = root;
    while(p != 0)
        if(p->left == 0)
            p = p->right;
        else {
            tmp = p->left;
            while(tmp->right != 0 &&  // go to the rightmost node of
                  tmp->right != p)    // the left subtree or
                tmp = tmp->right;     // to the temporary parent of p;
            if(tmp->right == 0) {     // if 'true' rightmost node was
                tmp->right = p;       // reached, make it a temporary
                p = p->left;          // parent of the current root,
            } else {                  // else a temporary parent has been found;
                // process nodes between p->left (included) and p (excluded)
                // extended to the right in modified tree in reverse order;
                // the first loop descends this chain of nodes and reverses
                // right pointers; the second loop goes back, visits nodes,
                // and reverses right pointers again to restore the pointers
                // to their original setting;
                for(q = p->left, r = q->right, s = r->right;
                    r != p; q = r, r = s, s = s->right)
                    r->right = q;
                for(s = q->right; q != p->left;
                    q->right = r, r = q, q = s, s = s->right)
                    visit(q);
                visit(p->left);  // visit node p->left and then cut
                tmp->right = 0;  // the right pointer of the current
                p = p->right;    // parent, whereby it ceases to be
            }                    // a parent;
        }
}

template <class T>
void BST<T>::balance(T data[], int first, int last) {
    if(first <= last) {
        int middle = (first + last) / 2;
        insert(data[middle]);
        balance(data, first, middle - 1);
        balance(data, middle + 1, last);
    }
}