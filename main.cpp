#include <iostream>
#include "Tree.h"

using namespace std;

template < typename T >
void Treefunctions(T arr[], int n, BST<T> b, treenode<T>* root)
{
  char ch;

  do
  {
    int op;
    cout<<"\nChoose implementation:\n"
          "1. Insert\n2. Print Inorder\n3. Print Preorder\n4. Print Postorder\n"
          "5. Destroy Tree\n6. Delete node    : ";
    cin>>op;

    switch(op)
    {
      case 1 :
      {
        for( int i = 0 ; i < n ; i++ )
          root = b.Insert(root, arr[i]);
        
        cout<<"\nInsertion done!";
        break;
      }

      case 2 :
      {
        cout<<"\nInorder printing : \n";
        b.traverseInorder(root);
        cout<<endl;

        break;
      }

      case 3 :
      {
        cout<<"\nPreorder printing : \n";
        b.traversePreorder(root);
        cout<<endl;

        break;
      }

      case 4 :
      {
        cout<<"\nPostorder printing : \n";
        b.traversePostorder(root);
        cout<<endl;

        break;
      }

      case 5 :
      {
        cout<<"\nDeleting entire tree !\n";
        b.Destroytree(root);
        cout<<endl;

        break;
      }

      case 6 :
      {
        T delnode;
        cout<<"\nEnter node to be deleted : ";
        cin>>delnode;

        b.Deletenode(root, delnode);
        cout<<"Deleted!";
        cout<<endl;
        
        break;
      }

      default:
        cout<<"\nInvalid choice!";
    }

    cout<<"\nWant to continue(y/n) : ";
    cin>>ch;

  }while(ch == 'y' || ch == 'Y');
}

int main()
{
  int n, i, opt;
  cout<<"On what datatype would you like to work with the BST: "
        "\n1. int\n2. char\n3. float\nOption : ";
  cin>>opt;
  cout<<"\nEnter no. of elements : ";
  cin>>n;

  switch(opt)
  {
    case 1 :
    {
      BST <int> b;
      treenode<int> *root = NULL;

      int barr[n];

      cout<<"\nEnter integer tree elements : \n";
      for( i = 0 ; i < n ; i++ )
        cin>>barr[i];
      cout<<endl;

      Treefunctions(barr, n, b, root);
        
      break;
    }

    case 2 :
    {
      BST <char> b;
      treenode<char> *root = NULL;

      char carr[n];

      cout<<"\nEnter char tree elements : \n";
      for(i=0 ; i<n ; i++)
        cin>>carr[i];
      cout<<endl;

      Treefunctions(carr, n, b , root);

      break;
    }

    case 3 :
    {
      BST <float> b;
      treenode<float> *root = NULL;

      float farr[n];

      cout<<"\nEnter float tree elements : \n";
      for(i=0 ; i<n ; i++)
        cin>>farr[i];
      cout<<endl;

      Treefunctions(farr, n, b, root);

      break;
    }

    default :
    {
      cout<<"\nInvalid entry!";
    }
  }

  cout<<"\nDone!";
}