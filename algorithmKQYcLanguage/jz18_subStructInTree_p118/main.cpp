//
//  main.cpp
//  jz18_subStructInTree_p118
//
//  Created by kqy on 06/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct BitTreeNode {
    char value;
    struct BitTreeNode * lChild;
    struct BitTreeNode *rChild;
}BitTreeNode;
bool whetherSubTree(BitTreeNode * Tree1, BitTreeNode * Tree2);
BitTreeNode * createBitTree( ) {
    BitTreeNode *pNewNode =  NULL;
    char tempChar = 0;
    scanf("%c", &tempChar) ;
    if (tempChar == '#') {
        pNewNode = NULL;
        
    } else {
        pNewNode = new BitTreeNode[sizeof(BitTreeNode) + 1]();
        
        pNewNode -> value = tempChar;
        pNewNode -> lChild = createBitTree();
        pNewNode -> rChild = createBitTree();
    }
    return pNewNode;
}
bool ifHavaSameSub(BitTreeNode *root1, BitTreeNode * root2) {
    bool result = false;
//    if (root1 == NULL || root2 == NULL ) {
//        return result;
//    }
    if (root1 != NULL && root2 != NULL ) {
 
        if (root1 -> value == root2 -> value) {
            result = whetherSubTree(root1, root2);
        }
        if (!result) {
            result = ifHavaSameSub(root1 -> lChild, root2 );
        }
        if (!result) {
            result = ifHavaSameSub(root1 -> rChild, root2 );
        }
    }
    return result;
}
bool whetherSubTree(BitTreeNode * Tree1, BitTreeNode * Tree2){
    if (Tree2 == NULL ) {
        return true;
    }
    if (Tree1 == NULL ) {
        return false;
    }
    if (Tree1 -> value != Tree2 -> value
        ) {
        return false;
    }
    return whetherSubTree(Tree1 ->lChild, Tree2 -> lChild) && whetherSubTree(Tree1 -> rChild, Tree2 -> rChild);
}
int main(int argc, const char * argv[]) {
    BitTreeNode *root1, *root2, *root2Left, *root3Right ;
   root1 =   createBitTree();
    root2 =  new BitTreeNode( );
    root2Left = new BitTreeNode();
    root3Right = new BitTreeNode();
//    生成一个树999 - 1 -2 
    root2 -> value = '9';
    root2Left ->value = '1';
    root3Right ->value = '2';
    root2 ->lChild = root2Left;
    root2 -> rChild = root3Right;
    root2Left ->lChild = NULL;
    root2Left ->rChild = NULL;
    root3Right ->lChild = NULL;
    root3Right -> rChild = NULL;
    cout << "2 finish  ." << endl;
    bool resultB = ifHavaSameSub(root1, root2);
    cout << "result: " << resultB << endl;
    return 0;
}
