
	#ifndef Gk_Lib_h
	#define Gk_Lib_h
	struct MyNode{				
	    char adress[20];
	    struct MyNode *next;
	};
					
	struct Node{							//tree structre
	    char url[100] , adress[20];
	    struct Node *left;
	    struct Node *right;
	    int height;
	    struct MyNode *Mynext;
	};

	typedef struct Node *AVLTree;
	
	AVLTree read_ip_data_BST(char[]);
	AVLTree insert_page_BST(AVLTree , char[] , char []);
	AVLTree read_ip_data(char[]);
	AVLTree insert_page(AVLTree , char[] , char[]);
	void display_index(AVLTree);
	void search_url(AVLTree , char[]);
	void search_ip(AVLTree , char[]);
	int AVLTree_Height(AVLTree);
	int FindMax(int, int);
	AVLTree SingleRotateWithLeft(AVLTree);
	AVLTree SingleRotateWithRight(AVLTree);
	AVLTree DoubleRotateWithLeft(AVLTree);
	AVLTree DoubleRotateWithRight(AVLTree);
	int ValidIP(char []);
	


	AVLTree read_ip_data(char file[100]){
	    
	    char url[100] , adress[20];
	    
	    AVLTree tree=NULL;
	    
	    FILE *Filepp;
	    Filepp = fopen(file, "r");
	    
	    if (Filepp==NULL) {
	    	
	        printf("Your file has not been loaded.\n");
	        
	        exit(1);
	    }
	    
	    else
	        printf("Your file has been loaded, the index has been created!\n");
	    
	    while (fscanf(Filepp, "%s > %s" , url, adress) != EOF) {
	        tree = insert_page(tree , url , adress);
	    }
	    
	    fclose(Filepp);
	    return tree;
	}


	AVLTree insert_page(AVLTree tree , char www[100] , char adress[20]){
	    if (tree==NULL) {
	        tree=malloc(sizeof(struct Node));
	        
	        if (tree==NULL) {
	            printf("Memory space is not enough!!!\n");
	        }
	        
	        else{
	            strcpy(tree->url, www);
	            tree->Mynext = (struct MyNode *)malloc(sizeof(struct MyNode));
	            strcpy(tree->Mynext->adress, adress);
	            tree->height = 0;
	            tree->left = NULL;
	            tree->right = NULL;
	            tree->Mynext->next=NULL;
	        }
	    }
	    
	    
	    else if(strcmp(www, tree->url) < 0){
	        tree->left = insert_page(tree->left, www, adress);
	        
	        if (AVLTree_Height(tree->left) - AVLTree_Height(tree->right) == 2){
	            if (strcmp(www, tree->left->url) < 0)
	                tree = SingleRotateWithLeft(tree);
	            else
	                tree = DoubleRotateWithLeft(tree);
	        }
	    }
	    
	    else if(strcmp(www, tree->url) > 0){
	        tree->right = insert_page(tree->right, www, adress);
	        
	        if (AVLTree_Height(tree->right) - AVLTree_Height(tree->left) == 2){
	            if (strcmp(www, tree->right->url) > 0)
	                tree = SingleRotateWithRight(tree);
	            else{
	                tree = DoubleRotateWithRight(tree);
	            }
	        }
	        
	    }
	    
	    
	    else{
	        struct MyNode *temp = tree->Mynext;
	        int check=0;
	        while (temp->next !=NULL) {
	            if (strcmp(temp->adress, adress) == 0) {
	                check=1;
	            }
	            temp = temp->next;
	        }
	        
	        if (!check) {
	            if (strcmp(temp->adress, adress) == 0) {
	                check=1;
	            }
	            if (check != 1) {
	                temp->next = (struct MyNode *)malloc(sizeof(struct MyNode));
	                temp->next->next = NULL;
	            }
	            
	        }
	        
	    }
	    
	    tree->height = FindMax(AVLTree_Height(tree->left), AVLTree_Height(tree->right)) + 1;
	    
	    return tree;
	}


	void display_index(AVLTree tree){
	    
	    if (tree!=NULL) {
	        display_index(tree->left);
	        printf("%s, IP addresses: ",tree->url);
	        struct MyNode *temp = tree->Mynext;
	        while (temp!=NULL) {
	        	
	            printf("%s \n",temp->adress);
	            temp = temp->next;
	        }
	        printf("\n");
	        display_index(tree->right);
	    }
	}


	void search_url(AVLTree tree , char page[50]){
	    
	  	
	  	
	  	
	  	if(tree!=NULL){
		  search_url(tree->left, page);
	    if (strcmp(page, tree->url) == 0) {
	        printf("IP addresses for %s: ",tree->url);
	        struct MyNode *temp = tree->Mynext;
	        while (temp!=NULL) {
	            printf("%s \n",temp->adress);
	            temp = temp->next;
	        }
	            
	        }
	          search_url(tree->right, page);
	    }
	    
		
		 
		}
		
	   
	



	void search_ip(AVLTree tree , char adress[50]){				//search function 
	    
	    
	    
	    if (tree != NULL) {
	    	search_ip(tree->left , adress);								
	    	if (strcmp(tree->Mynext->adress,adress)==0){			//compare stirings to find match then prints result
	    		printf("It belongs to %s\n" , tree->url);
	    		struct MyNode *temp = tree->Mynext;
	        while (temp!=NULL) {
	        	
	            temp = temp->next;
			}
		}
	        search_ip(tree->right , adress);
	    
	 

	    }
	
	   
	    
	    
	
	
}

	int AVLTree_Height(AVLTree tree)				//finds height for avl tree
	{
	    if (tree == NULL)
	        return -1;
	    else
	        return tree->height;
	}

	AVLTree SingleRotateWithLeft(AVLTree k2)				
	{
	    AVLTree k1;
	    k1=k2->left;
	    k2->left=k1->right;
	    k1->right=k2;
	    
	    k2->height=FindMax(AVLTree_Height(k2->left),AVLTree_Height(k2->right));
	    k1->height=FindMax(AVLTree_Height(k1->left),AVLTree_Height(k1->right));
	    
	    return k1;
	}

	AVLTree SingleRotateWithRight(AVLTree k1)
	{
	    AVLTree k2;
	    k2=k1->right;
	    k1->right = k2->left;
	    k2->left=k1;
	    k2->height=FindMax(AVLTree_Height(k2->left),AVLTree_Height(k2->right));
	    k1->height=FindMax(AVLTree_Height(k1->left),AVLTree_Height(k1->right));
	    
	    return k2;
	}

	AVLTree DoubleRotateWithLeft(AVLTree k3)
	{
	    k3->left = SingleRotateWithRight(k3->left);
	    return SingleRotateWithLeft(k3);
	}

	AVLTree DoubleRotateWithRight(AVLTree k3)
	{
	    k3->right = SingleRotateWithLeft(k3->right);
	    return SingleRotateWithRight(k3);
	}

	int FindMax(int x, int y)
	{
	    if (x >= y)
	        return x;
	    else
	        return y;
	}
	
	

	AVLTree read_ip_data_BST(char file[100]){
	    
	    char url[100] , adress[20];
	    
	    AVLTree Bstree=NULL;
	    FILE *Filep;											//gets file 
	    Filep = fopen(file, "r");
	    if (Filep==NULL) {						//error message
	        printf("Your file has not been loaded.\n");
	        
	        exit(1);
	    }
	    
	    else
	        printf("Your file has been loaded, the index has been created!\n");
	    
	    while (fscanf(Filep, "%s > %s" , url, adress) != EOF) {
	        Bstree = insert_page_BST(Bstree , url , adress);
	    }
	    
	    fclose(Filep);
	    return Bstree;
	}


	AVLTree insert_page_BST(AVLTree Bstree , char www[100] , char adress[20]){
	    if (Bstree==NULL) {
	        Bstree=malloc(sizeof(struct Node));
	        
	        if (Bstree==NULL) {
	            printf("Can't get enough memory!!\n");	
	        }
	        
	        else{
	            strcpy(Bstree->url, www);
	            Bstree->Mynext = (struct MyNode *)malloc(sizeof(struct MyNode));
	            strcpy(Bstree->Mynext->adress, adress);
	            Bstree->left = NULL;
	            Bstree->right = NULL;
	            Bstree->Mynext->next=NULL;
	        }
	    }
	    
	    
	    else if(strcmp(www, Bstree->url) < 0){
	        Bstree->left = insert_page(Bstree->left, www, adress);
	    }
	    
	    else if(strcmp(www, Bstree->url) > 0){
	        Bstree->right = insert_page(Bstree->right, www, adress);
	       
	        }
	        
	    
	    
	    
	    else{
	        struct MyNode *Bstemp = Bstree->Mynext;
	        int check=0;
	        while (Bstemp->next !=NULL) {
	            if (strcmp(Bstemp->adress, adress) == 0) {
	                check=1;
	            }
	            Bstemp = Bstemp->next;
	        }
	        
	        if (!check) {
	            if (strcmp(Bstemp->adress, adress) == 0) {
	                check=1;
	            }
	            if (check != 1) {
	                Bstemp->next = (struct MyNode *)malloc(sizeof(struct MyNode));
	                Bstemp->next->next = NULL;
	            }
	            
	        }
	        
	    }
	    
	    return Bstree;}
		
	
	void compare(void){
		printf("Run time of AVL tree readip function:\n");
		printf("Run time of AVL tree search URL:\n");
		printf("Run time of BST readip function:\n");
		printf("Run time of BST tree search URL:\n");
	}
	
	int ValidIP(char adress[20]){
	    
	    if(strlen(adress) > 16){
	        return 0;
	    }
	    
	    return 1;
	    
	}


	
	
	
	
	
	
	



	#endif /* Gk_Lib_h */

