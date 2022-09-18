#include <iostream>
#include <limits.h>
using namespace::std;

class unit{
    public:
        int key;
        unit* origin;
        unit* left;
        unit* right;
        unit() {
            key = 0;
            left = NULL;
            right = NULL;
            origin = NULL;
        }	 	  	 	 		     	      	      	  	  	 	
        unit(int key) {
            this -> key = key;
            left = NULL;
            right = NULL;
            origin = NULL;
        }
        unit(int key, unit* left, unit* right) {
            this -> origin = NULL;   
            this -> key = key;
            this -> left = left;
            this -> right = right;
            this -> left -> origin = this;
            this -> right -> origin = this;
        }
};
void preOrder(unit root, int val = 0) {  
    if(val == 0) {
        std::cout<<(char)root.key;    
    }
    else {
        std::cout<<root.key<<", ";
    }
    if(root.left != NULL) {
        preOrder(*(root.left), val);
    }
    if(root.right != NULL) {
        preOrder(*(root.right), val);
    }	 	  	 	 		     	      	      	  	  	 	
}

void inOrder(unit root, int val = 0) {
    if(root.left != NULL) {
        inOrder(*(root.left), val);
    }
    if(val == 0) {
        std::cout<<(char)root.key; 
    }
    else {
        std::cout<<root.key<<", ";
    };
    if(root.right != NULL) {
        inOrder(*(root.right), val);
    }
}

void postOrder(unit root, int val = 0) {
    if(root.left != NULL) {
        postOrder(*(root.left), val);} 
    if(root.right != NULL) {
        postOrder(*(root.right), val);}
    if(val == 0) {
        std::cout<<(char)root.key;  }
    else {
        std::cout<<root.key<<", "; };
}

void extremumElements(unit* rootUnit) {
    unit* temp1 = rootUnit;
    unit* temp2=rootUnit;
    while(temp1 -> left != NULL) {
        temp1 = temp1 -> left;}
    int min = temp1 -> key;
    while(temp2 -> right != NULL) {
        temp2 = temp2 -> right;}
    int max = temp2 -> key;
    std::cout<<"the minimum element is: "<<min<<"\nThe maximum element is: "<<max<<std::endl;
}

void insertInTree(unit* rootUnit, int value) {
    
    if( value < (rootUnit -> key) ) {
        if((rootUnit -> left) == NULL) {
            rootUnit -> left = new unit(value);
            rootUnit -> left -> origin = rootUnit; 
        }
        else{
            insertInTree(rootUnit -> left, value);}	 	  	 	 		     	      	      	  	  	 	
    }
    else if( value > (rootUnit -> key) ) {
        if((rootUnit -> right) == NULL) {
            rootUnit -> right = new unit(value);
            rootUnit -> right -> origin = rootUnit;
        }
        else{
            insertInTree(rootUnit -> right, value);}
    }
    else{ 
        std::cout<<"Error repeated value";}
}

unit* search(unit* rootUnit, int value) {
    if(value == (rootUnit -> key)) {
        return rootUnit;}
    else if( (value < (rootUnit -> key)) && ((rootUnit -> left) != NULL) ) { 
        return search(rootUnit -> left, value);}
    else if( (value > (rootUnit -> key)) && ((rootUnit -> right) != NULL) ) {
        return search(rootUnit -> right, value);}	 	  	 	 		     	      	      	  	  	 	
    return NULL;
}

unit* inorderSucc(unit* elementPtr) {
    if(elementPtr == NULL){
        return NULL;}
    if(elementPtr -> right != NULL)
    {
        elementPtr = elementPtr -> right;
        while(elementPtr -> left != NULL) {
            elementPtr = elementPtr -> left;
        }   
        return elementPtr;
    }
    while(elementPtr -> origin != NULL) {
        if(elementPtr == (elementPtr->origin)->left) {
            return (elementPtr->origin);
        }   
        elementPtr = elementPtr->origin;
    }
    return NULL;  
}

unit* inorderPred(unit* elemPointer) {
    if(elemPointer == NULL){
        return NULL;}	 	  	 	 		     	      	      	  	  	 	
    if(elemPointer -> left != NULL)
    {
        elemPointer = elemPointer -> left;
        while(elemPointer -> right != NULL) {
            elemPointer = elemPointer -> right;
        }   
        return elemPointer;
    }
    while(elemPointer -> origin != NULL) {
        if(elemPointer == (elemPointer->origin)->right) {
            return (elemPointer->origin);
        }   
        elemPointer = elemPointer->origin;
    } 
    return NULL;  
}

void Deleter(unit* rootUnit, int target) {
    unit* targetPtr = search(rootUnit, target); 
    if(targetPtr == NULL) {
        std::cout<<"NotFound\n";
        return;
    }
    if( (targetPtr->left == NULL) && (targetPtr->right == NULL) ) 
    {   
        if(targetPtr->origin->key == INT_MAX)
        {
            std::cout<<"Not possible\n";
        }	 	  	 	 		     	      	      	  	  	 	   
        else {
            if (targetPtr->origin->left == targetPtr) {
                targetPtr->origin->left = NULL;
            }
            else {
                targetPtr->origin->right = NULL;
            }
        }   
        return;
    }
    else 
    {
        unit* sucPtr = inorderSucc(targetPtr);
        unit* prePtr = inorderPred(targetPtr);
        if(sucPtr != NULL) {
            Deleter(rootUnit, sucPtr->key); 
            targetPtr->key = sucPtr->key; 
        }
        else if(prePtr != NULL) {
        
            Deleter(rootUnit, prePtr->key);
        
            targetPtr->key = prePtr->key;
        }	 	  	 	 		     	      	      	  	  	 	 
        return;
    }   
}

int operatorPrec(char op) {
    switch(op) {
        case '^':
            return 4;
            break;
        case '/':
        case '*':
            return 3;
            break;
        case '-':
        case '+':
            return 2;
            break;
        default:
            return 0;
            break;
    };
};

template <class T> class stack {
    public:
        int top;
        int size;
        T* arrStack;
        
        stack() {
            size = 100;
        }
        stack(int size) {	 	  	 	 		     	      	      	  	  	 	
            this -> size = size;
            top = -1;
            arrStack = (T*)( malloc( size * sizeof(T) ) );
        };
        int isEmpty() {
            if(top == -1) {
                return 1;
            }
            else {
                return 0;
            };
        };
        
        int isFull() {
            if ( (top + 1) == (size) ) {
                return 1;
            }
            else {
                return 0;
            }
        };
        
        void Push(T element) {
            if( isFull() ) {
                cout << "Stack over-flow\n";
            }
            else {
                *(arrStack + (++top)) = element;
            }
        };
        
        T Pop() {
            return ( *( arrStack + (top--) ) );
        };
};

unit* exprrTreeCreate(string infix) {	 	  	 	 		     	      	      	  	  	 	
    stack<char> opStack(50);
    
    stack<unit*> unitStack(50);
    
    char current;
    
    unit *n1, *n2;
    int op;
    
    for(int index = 0; index < infix.length(); index++) {
        current = infix[index];
        
        if( ( ( (int)(current) >= 65 ) && ( (int)(current) <= 90 ) ) || ( ( (int)(current) >= 97 ) && ( (int)(current) <= 122 ) ) ) {
            unitStack.Push(new unit((int)(current)));
        }
        else if(current == '(') {
            opStack.Push(current);
        }
        else if(current == ')') {
            while((opStack.arrStack)[opStack.top] != '(') {
                n1 = unitStack.Pop();
                n2 = unitStack.Pop();
                op = (int)(opStack.Pop());
                
                unitStack.Push(new unit(op, n2, n1));
            }
            opStack.Pop();
        }
        else if( operatorPrec(current) ) {
            if( operatorPrec( opStack.arrStack[opStack.top] ) < operatorPrec(current) ) {
                opStack.Push(current);
            }
            else {
                while( operatorPrec( (opStack.arrStack)[opStack.top] ) >= operatorPrec(current) ) {
                    n1 = unitStack.Pop();
                    n2 = unitStack.Pop();
                    op = (int)(opStack.Pop());
                    
                    unitStack.Push(new unit(op, n2, n1));
                };
                
                opStack.Push(current);
            }	 	  	 	 		     	      	      	  	  	 	
            
        }
    }
    
    return unitStack.Pop();
    
}



int main() {
    
    // QUESTION 1
    unit rootNode(10, new unit(8, new unit(5), new unit(9)), new unit(15, new unit(12), new unit(17)));
    rootNode.origin = new unit(INT_MAX);
    rootNode.origin -> left = &rootNode;
    insertInTree(&rootNode, 11);
    insertInTree(&rootNode, 24);
    printf("\n");
    Deleter(&rootNode, 11);
    preOrder(rootNode, 1);
    printf("\n");
    Deleter(&rootNode, 17);
    preOrder(rootNode, 1);
    printf("\n");
    Deleter(&rootNode, 10);
    preOrder(rootNode, 1);
    printf("\n");
    int searchElement = 24;
    
    if(search(&rootNode, searchElement) != NULL) {	 	  	 	 		     	      	      	  	  	 	
        printf("Key (%d) present\n", searchElement);
    }
    else {
        printf("Key (%d) NOT present\n", searchElement);
    }

    // QUESTION 2
    extremumElements(&rootNode);
    
    // QUESTION 3
    string infix = "(A/B-C*(D-E^Z)+F)";
    unit *exprTree = exprrTreeCreate(infix);
    std::cout<<"\nInfix is:\n";
    inOrder(*exprTree);
    
    // QUESTION 4
    std::cout<<"\nPostFix is:\n";
    postOrder(*exprTree);
    std::cout<<"\nPrefix is:\n";
    preOrder(*exprTree);
    std::cout<<"\n";
    return 0;
}	 	  	 	 		     	      	      	  	  	 	