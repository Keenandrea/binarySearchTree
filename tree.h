#ifndef TREE_H
#define TREE_H

#include "node.h"

#include <fstream>
#include <iostream>
#include <string>

class Tree 
{
        private:

                TreeNode* insert(TreeNode* node, std::string datum);
                TreeNode* empty(TreeNode* node);

                void printPreorder(TreeNode* node, int depth, std::ostream& fout);
                void printPostorder(TreeNode* node, int depth, std::ostream& fout);
                void printInorder(TreeNode* node, int depth, std::ostream& fout);

        public:

                TreeNode* root;
        
                Tree();
                ~Tree();

                TreeNode* buildTree(std::istream& fin);
                void insert(std::string datum);

                void printPreorder(TreeNode* node, std::string fileName);
                void printPostorder(TreeNode* node, std::string fileName);
                void printInorder(TreeNode* node, std::string fileName);
};
#endif /* TREE_H */