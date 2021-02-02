#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gk_Lib.h"  


int main(int argc, char *argv[]) {
    
    AVLTree avtree,bytree;  //First one is for AVLTree,second is for Binary Search Tree
    int op , status=1,flag;  //status is a condition for break the loop
    char file_name[100] , webpage[50] , ip[50];
    printf("Please enter the file name(xxx.txt):");
    scanf("%s",file_name);
    printf("''Indexing Websites!''\n");
    avtree=read_ip_data(file_name);         //reads the data and makes the AVLTree
    bytree=read_ip_data_BST(file_name);             //reads the data and makes the BSTree
    while (status!=0) {
        fflush(stdin);
        printf("\n---------   MENU    ---------\n");
        printf("1. Display the full index in AVL Tree\n");
        printf("2. Display the full index in BST Tree\n");
        printf("3. Search for a URL in AVL Tree\n");
        printf("4. Search for a URL in BST Tree\n");
        printf("5. Search for an IP address in AVL Tree\n");
        printf("6. Search for an IP address in BST Tree\n");
        printf("7. Comparison of Run time\n");
        printf("8. Exit\n");
        printf("---------------------------\n");
        printf("Option: ");
        scanf("%d",&op);
        fflush(stdin);
        
        switch (op) {
            case 1:
                printf("\n");
                display_index(avtree);  //display function for avltree
                break;
            case 2:
                printf("\n");
                display_index(bytree);		//display func. for bst tree
                break;
            case 3:             
                printf("\n");
                printf("Please enter the page: ");					//case 3 and 4 search using url
                scanf("%s.",&webpage);         
                search_url(avtree , webpage);
                break;
            case 4:
                printf("\n\n");
                printf("Please enter the page: ");
                scanf("%s",&webpage);
                search_url(bytree , webpage);      
                break;
            case 5:
                printf("\n");
                printf("Please enter the URL: ");  				//case 5 and 6 search using ip adresses
                scanf("%s.",&ip);
                flag=ValidIP(ip);
                while (flag== 0) {        //checks if it's a valid ip or not
                    printf("IP has to be in this format xxx.xxx.xxx.xxx\n");
                    printf("Please enter the URL: ");
                    scanf("%s",&ip);
                    flag=ValidIP(ip);
                    fflush(stdin);  
            }  
                search_ip(avtree ,ip);
                break;    
            case 6:
                printf("\n");
                printf("Please enter the URL: ");
                scanf("%s.",&ip);
                flag=ValidIP(ip);
                while (flag==0) {        //checks if it's a valid ip or not
                    printf("IP has to be in this format xxx.xxx.xxx.xxx\n");
                    printf("Please enter the URL: ");
                    scanf("%s",&ip);
                    flag=ValidIP(ip);
                    fflush(stdin);  
            }      
                search_ip(bytree , ip);
                break;  
            case 7:
                 compare();  
            case 8:
                printf("\nBye!\n");
                status=0;
                break;
            default:
                printf("Unknown Command\n");
                break;
        }
    }
    return 0;
}
