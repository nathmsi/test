#include <iostream>
using namespace std;

//------------------------------------TREE----------------------------------------------

template <class T>
class Tree{
protected:
    //------------------------------------NODE----------------------------------------------
    template <class T>
    class Node
    {
    public:
        Node* left;
        Node* right;
        T value;
        
        Node(T val)
            : value(val), left(nullptr), right(nullptr)
        {}
        
        Node(T val, Node* l, Node* r)
            : value(val), left(l), right(r) {}
    }; //end of Node class

    //------------------------------------END NODE----------------------------------------------

    Node* root;
public:
    // normal methodes of this data structure
    Tree() { root = nullptr; } // initialize tree
    virtual ~Tree();
    bool isEmpty() const;
    void clear() { clear(root); root = nullptr; }
    void preOrder() { preOrder(root); }
    void inOrder() { inOrder(root); }
    void postOrder() { postOrder(root); }
    
    // polymorphism
    virtual void process(T val) { cout << val << " "; }
    
    // pure virtual, need to be written in inheritor class
    virtual void add(T val) = 0;
    virtual bool search(T val) = 0;
    virtual void remove(T val) = 0;
    
private:
    void  clear(Node* current);
    void  preOrder(Node* current);
    void  inOrder(Node* current);
    void  postOrder(Node* current);
};
//------------------------------------END TREE----------------------------------------------

//------------------------------------SEARCH TREE----------------------------------------------
template <class T>
class SearchTree : public Tree<T>{
public:
    // protocol for search trees
    void add(T value);
    bool search(T value){
        return search (root,value);
    }
    void remove(T value);
private:
    void add(Node * current, T val);
    bool search(Node* current, T val);
};
