void Deleter(unit* rootUnit, int value) {
    unit* tempPointer = search(rootUnit, value);
    
    if(tempPointer == NULL) {
        printf("Target element not present. Deletion not possible\n");
        return;
    }
    
    if( (tempPointer->left == NULL) && (tempPointer->right == NULL) ) 
    { // Case 1 (Element to be deleted has no children)
        
        if(tempPointer->origin->key == INT_MAX) // Checking whether this is the root node.
        { // No children and no origin so it is a trivial BST.
            printf("This tree has only one node. If that is deleted, this would no longer be a BST. So, deletion not possible\n");
        }	 	  	 	 		     	      	      	  	  	 	
        
        else { // Checking whether the value is the left or right child node of origin.
            if (tempPointer->origin->left == tempPointer) {
                tempPointer->origin->left = NULL;
            }
            else {
                tempPointer->origin->right = NULL;
            }
        }
        
        return;
    }
    
    else 
    { // Case 3 (Element to be deleted has 2 children)
    
        
        // Getting pointers to both the successor and predecessor elements
        unit* sucPtr = successor(tempPointer);
        unit* prePtr = predecessor(tempPointer);
        
        if(sucPtr != NULL) {
            
            // First deleting the successor from the tree
            Deleter(rootUnit, sucPtr->key); 
            
            // Then inserting the successor in place of the value, to avoid duplicate successor values.
            tempPointer->key = sucPtr->key; 
        }
        
        else if(prePtr != NULL) {
        
            Deleter(rootUnit, prePtr->key);
        
            tempPointer->key = prePtr->key;
        }	 	  	 	 		     	      	      	  	  	 	
        
        return;
    }
    
}