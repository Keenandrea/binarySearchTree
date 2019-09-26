#include "tree.h"

/* ================================================================================
constructor ==================================================================== */
Tree::Tree()
{
    root = NULL;
}
/* end of work zone ===============================================================
================================================================================ */

/* ================================================================================
destructor ===================================================================== */
Tree::~Tree()
{
    root = empty(root);
}
/* end of work zone ===============================================================
================================================================================ */


/* ================================================================================
build tree from stream data ==================================================== */
TreeNode* Tree::buildTree(std::istream& in)
{
    std::string word;

    while(in >> word)
    {
        this->insert(word);
    } 

    return root;
}
/* end of function ================================================================
================================================================================ */

void Tree::insert(std::string datum)
{
    root = insert(root, datum);
}

TreeNode* Tree::insert(TreeNode* node, std::string datum)
{
    if(node == NULL)
    {
        return new TreeNode(datum);
    }

    if(node->head == datum.substr(0,1))
    {
        node->data.insert(datum);
    }

    else if(node->head > datum.substr(0,1))
    {
        node->leftward = insert(node->leftward, datum);
    }
 
    else if(node->head < datum.substr(0,1))
    {
        node->rightward = insert(node->rightward, datum);
    }

    return node;
}
/* end of function ================================================================
================================================================================ */

/* ================================================================================
preorder traversal, helper prints to file with designated extension, private functi
on produces traversal and formats file ==========================================*/
void Tree::printPreorder(TreeNode* node, std::string fileName)
{
    fileName = fileName + ".preorder";
    std::ofstream ofile(fileName);

    printPreorder(node, 0, ofile);
}
/* end of function ================================================================
================================================================================ */
void Tree::printPreorder(TreeNode* node, int depth, std::ostream& fout)
{
    if(node == NULL)
    {
        return;
    }

    std::string indents((depth * 1), ' ');
    fout << indents;

    for(auto word : node->data)
    {
        fout << word << " ";
    }
    fout << std::endl;

    printPreorder(node->leftward, (depth + 1), fout);
    printPreorder(node->rightward, (depth + 1), fout);
}
/* end of function ================================================================
================================================================================ */

/* ================================================================================
postorder traversal, helper prints to file with designated extension, function prod
uces traversal and formats file ================================================ */
void Tree::printPostorder(TreeNode* node, std::string fileName)
{
    fileName = fileName + ".postorder";
    std::ofstream ofile(fileName);

    printPreorder(node, 0, ofile);
}
/* end of function ================================================================
================================================================================ */
void Tree::printPostorder(TreeNode* node, int depth, std::ostream& fout)
{
    if(node == NULL)
    {
        return;
    }

    printPostorder(node->leftward, (depth + 1), fout);
    printPostorder(node->rightward, (depth + 1), fout);

    std::string indents((depth * 1), ' ');
    fout << indents;

    for(auto word : node->data)
    {
        fout << word << " ";
    }
    fout << std::endl;
}
/* end of function ================================================================
================================================================================ */
   
/* ================================================================================
inorder traversal, helper prints to file with designated extension, function produc
es traversal and formats file ================================================== */
void Tree::printInorder(TreeNode* node, std::string fileName)
{
    fileName = fileName + ".inorder";
    std::ofstream ofile(fileName);

    printInorder(node, 0, ofile);
}
/* end of function ================================================================
================================================================================ */
void Tree::printInorder(TreeNode* node, int depth, std::ostream& fout)
{
    if(node == NULL)
    {
        return;
    }

    printInorder(node->leftward, (depth + 1), fout);

    std::string indents((depth * 1), ' ');
    fout << indents;

    for(auto word : node->data)
    {
        fout << word << " ";
    }
    fout << std::endl;

    printInorder(node->rightward, (depth + 1), fout);
}
/* end of function ================================================================
================================================================================ */

/* ================================================================================
deletes a tree by left -> right -> parent ====================================== */ 
TreeNode* Tree::empty(TreeNode* node)
{
    if(node == NULL)
    {
        return NULL;
    }

    empty(node->leftward);
    empty(node->rightward);

    delete node;
    return NULL;    
}
/* end of function ================================================================
================================================================================ */