#include <iostream>
#include <fstream>
#include <string>

#include "tree.h"

int main(int argc, char* argv[]) 
{
    std::string baseName; 
    std::string fileName;

    // std::cout << "Validating invocation on ";
    // for(int i = 0; i < argc; ++i)
    // {
    //     std::cout << argv[i] << " ";
    // }
    // std::cout << std::endl;

   /* ================================================================================
   taken in the event of program invocation without a file argument =============== */
    if(argc == 1)
    {
        baseName = "tree";
        fileName = baseName + ".txt";
        std::string words = "";
        
        std::ofstream ftemp;
        ftemp.open(fileName);

        while(std::cin >> words)
        {
            ftemp << (words + ' ');
        }

        ftemp.close();

        std::ifstream fin;
        fin.open(fileName);

        if(fin.is_open())
        {
            std::cout << "Opened " << fileName << "..." << std::endl;
            std::cout << "Instantiating Binary Search Tree...";
            std::cout << "Building from data found in " << fileName << "..."; 

            Tree tree;

            tree.root = tree.buildTree(fin);

            tree.printPreorder(tree.root, baseName);
            tree.printPostorder(tree.root, baseName);
            tree.printInorder(tree.root, baseName);

            fin.close();
            return 0;
        }

        if(fin.fail())
        {
            std::cout << baseName << " does not exist." << std::endl;
            std::cout << "Closing stream...Exiting" << std::endl;
            fin.close();
            return 2; 
        }
        /* peek the stream, if first char is eof, file is empty, since an empty file ha
        s nothing to peek will also return true if file never opened                 */
        if(fin.peek() == std::ifstream::traits_type::eof())
        {
            std::cout << "But found " << baseName << " empty of content." << std::endl;
            std::cout << "Closing stream...Exiting" << std::endl;
            fin.close();
            return 2;
        }
    }
    /* end of conditional =============================================================
    ================================================================================ */

    /* ================================================================================
    taken in the event of program invocation with a file argument ================== */
    if(argc == 2)
    {
        std::string dot = ".";
        std::string ext = ".fs19";
        baseName = { argv[1] };
        fileName = { argv[1] };

        std::cout << "Validating file extension..." << std::endl;
        /* std::find value of dot in fileName string range. std::string::npos used to i
        ndicate that no matches to dot have been found within the considered string  */
        if(fileName.find(dot) == std::string::npos)
        {
            std::cout << "Appending extension " << ext << " to " << fileName << "...";
            fileName.append(".fs19");
        }
        else
        {
            std::cout << "Error: Found file extension." << std::endl;
            std::cout << "Please re-invoke without extension...Exiting." << std::endl;
            return 2;
        }

        std::cout << "Validating " << fileName << "...";
        
        std::ifstream fin;
        fin.open(fileName.c_str());

        if(fin.is_open())
        {
            std::cout << "Opened " << fileName << "..." << std::endl;
            std::cout << "Instantiating Binary Search Tree..." << std::endl;
            std::cout << "Building from " << fileName << " data..." << std::endl; 

            Tree tree;
            tree.root = tree.buildTree(fin);
            tree.printPreorder(tree.root, fileName);
            tree.printPostorder(tree.root, fileName);
            tree.printInorder(tree.root, fileName);

            fin.close();
            return 0; 
        }

        if(fin.fail())
        {
            std::cout << fileName << " does not exist." << std::endl;
            std::cout << "Closing stream...Exiting" << std::endl;
            fin.close();
            return 2; 
        }

        /* peek the stream, if first char is eof, file is
           empty, since an empty file has nothing to peek
           will also return true if file never opened  */
        if(fin.peek() == std::ifstream::traits_type::eof())
        {
            std::cout << "But found " << fileName << " empty of content." << std::endl;
            std::cout << "Closing stream...Exiting" << std::endl;
            fin.close();
            return 2;
        }
    }
    /* end of conditional =============================================================
    ================================================================================ */

    /* ================================================================================
    taken in the event of program invocation with incorrect arguments ============== */
    if(argc > 2) 
    {
        std::cout << "Error: Invalid program invocation: (" << argc
             << " arguments)\nExpected one of three invocations:";
        std::cout << "\n$ [program]\n$ [program] [somefile]\n$ [program] " 
             << "< [somefile]\n\nPlease re-invoke args correctly.";
        return 2;
    }
    /* end of conditional =============================================================
    ================================================================================ */


return 0;    
}
