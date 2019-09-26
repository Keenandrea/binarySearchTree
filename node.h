#ifndef NODE_H
#define NODE_H

#include <set>
#include <string>

/* TreeNode object constitutes a
   single node in a BST of strin
   gs, nestled up to a construct
   or, which, although admittedl
   y a Javaian convention, is le
   gal in C++, and dilutes the c
   reation of our node object */

template <class T>
class TreeNode 
{
      private:
            /* node data set */
            std::set <T> data;
            TreeNode<T>* leftward;
            TreeNode<T>* rightward;
            std::string head;

      public:
            TreeNode(std::string data) 
            {
                  this->data.insert(data);
                  this->leftward = nullptr;
                  this->rightward = nullptr;
                  this->head = data.substr(0,1);               
            }
};
#endif /* NODE_H */