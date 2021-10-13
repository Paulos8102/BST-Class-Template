#ifndef TREE_H
#define TREE_H

template <typename T >
class treenode
{
  public:
    T data;
    treenode* left;
    treenode* right;

    treenode()
    {
      data = 0;
      left = right = nullptr;
    }

    treenode(T x)
    {
      data = x ;
      left = right = nullptr;
    }
};

template < typename T >
class BST : public treenode<T>
{
  public:
    treenode<T>* Insert(treenode<T>*, T); 

    void traverseInorder(treenode<T>*);
    void traversePreorder(treenode<T>*);
    void traversePostorder(treenode<T>*);

    treenode<T>* Min(treenode<T>*);
    treenode<T>* Deletenode(treenode<T>*, T);

    void Destroytree(treenode<T>*);
};

template < typename T >
treenode<T>* BST<T> :: Insert(treenode<T>* root, T item) 
{
  if(root == NULL)
    return( new treenode(item));
  else if( root->data > item )
    root->left = Insert(root->left, item);
  else
    root->right = Insert(root->right, item);
        
  return root;
}

template < typename T >
void BST<T> :: traverseInorder(treenode<T>* root)
{
  if(root!=NULL)
  {
    traverseInorder(root->left);
    std :: cout<<root->data<<" ";
    traverseInorder(root->right);
  }
}

template < typename T >
void BST <T> :: traversePreorder(treenode<T>*node) 
{ 
  if (node != NULL)
  {
    std :: cout <<node->data << " ";
    traversePreorder(node->left); 
    traversePreorder(node->right);
  }
}

template < typename T >
void BST <T> :: traversePostorder(treenode<T>* node) 
{ 
  if (node != NULL)
  {
    traversePostorder(node->left); 
    traversePostorder(node->right);
    std :: cout << node->data << " ";
  }
}

template < typename T >
treenode<T>* BST <T> :: Min(treenode<T>* temp)  //Find Minimum node
{
  if( temp == NULL )
    return NULL;

  else if(temp -> left == NULL)
    return temp;

  else
    return( Min ( temp -> left ));
}

template < typename T >
treenode<T>* BST <T> :: Deletenode(treenode<T>* node, T key)
{
	if (node == NULL)
		return node;

	if (key < node->data)
		node->left = Deletenode(node->left, key);

	else if (key > node->data)
		node->right = Deletenode(node->right, key);

	else
	{       //one child or no child
		if (node->left == NULL)
		{
			treenode<T>* temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL)
		{
			treenode<T>* temp = node->left;
			free(node);
			return temp;
		}

		//with 2 children, getting inorder
		treenode<T>* temp = Min(node->right);

		node->data = temp->data;

		node->right = Deletenode(node->right, temp->data);
	}
	return node;
} 

template < typename T >
void BST <T> :: Destroytree(treenode<T>* node)
{
  if (node != NULL)
  {
    Destroytree(node->left); 
    Destroytree(node->right);
    std :: cout << "\n Deleting node: " << node->data;  
    delete node; 
  }
  else
    return;  
}

#endif