#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! GLOBAL VARIABLES !!!!!!!!
int password=651205;
int i=0;
int sr = 0;
int order_sr = 0;
float bill = 0;

//!!!!!!!!!!!!!!!!!!!!!! LINKED LIST !!!!!!!!!!!!!
struct node {
    int data;
    char foodname[100];
    int quantity;
    float price;
    struct node *next;
};

//!!!!!!!!!!!!!!!! HEAD POINTERS !!!!!!!!!!!!!!!!!!!!!!
struct node *head_a=NULL;
struct node *head_c=NULL;
struct node *order=NULL;

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!     FUNCTIONS  !!!!!!!!!!!!!!


//!!!!!!!!!!!!!!!!!!!!!!!!!!! CREATE MENU !!!!!!!!!!!!!!!!!!!!!!!!!!
struct node *createadmin(struct node *head_a,char foodname[100],float price){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=i+1;
    strcpy(temp->foodname,foodname);
    temp->price=price;
    temp->quantity=0;
    temp->next=NULL;
    struct node *ptr;    
    ptr=head_a;
    if (ptr==NULL){
        head_a=temp;
    }
    else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    i=i+1;
    return head_a;
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! MAIN MENU !!!!!!!!!!!!!!!!!!!!!

void mainmenu(){
    printf("\033[0;33m");
    printf("\n\n\t\t\t\t\t\t\t\t\t Press 1 for ADMIN\n");
    printf("\t\t\t\t\t\t\t\t\t Press 2 for CUSTOMER\n");
    printf("\t\t\t\t\t\t\t\t\t Press 3 to EXIT\n\n");
    printf("\033[0m");
    printf("Enter your choice ---->  ");
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! VIEW SALES !!!!!!!!!!!!!!!!!!!!!!!



//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ADD ITEMS TO ORDER MENU !!!!!!!!!!!!!!

struct node  *addmenu(struct node *head_a){
    int price;
    char c[100];
    printf("\nEnter the name of food item : ");
    printf("\033[0;33m");
    scanf("%s",&c);
    printf("\033[0m");
    printf("Enter the price of food item : ");
    printf("\033[0;33m");
    scanf("%d",&price);
    printf("\033[0m");
    createadmin(head_a,c,price);
    printf("\033[0;31m");
    printf("\nItem Added!\n");
    printf("\033[0m");
    return head_a;
}



//!!!!!!!!!!!!!!!!!!!!!!!!!  DISPLAY MENU FOR ADMIN !!!!!!!!!!!!!!!!
void displayadmin(struct node *head_a){
    struct node *ptr;
    ptr=head_a;
    printf("\033[0;33m");
    printf("\n\n\t\t\t\t\t\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\tSr\t\tFood Item\t\tPrice\n");
    printf("\t\t\t\t\t\t\t\t-----------------------------------------------------------\n");
    while (ptr!=NULL){
        printf("\t\t\t\t\t\t\t\t\t%d.\t\t",ptr->data);
        printf("%s\t\t\t",ptr->foodname);
        printf("%.2f\n",ptr->price);
        ptr=ptr->next;
    }
    printf("\t\t\t\t\t\t\t\t-----------------------------------------------------------\n\n\n");
    printf("\033[0m");
}


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  DELETE ITEMS FROM ADMIN MENU  !!!!!!!!!!!!!!!!

struct node *deletemenu(struct node *head_a){
    int data;
    displayadmin(head_a);
    printf("Enter the number of item to be deleted : ");
    printf("\033[0;33m");
    scanf("%d",&data);
    printf("\033[0m");
    struct node *ptr1,*ptr2,*ptr3;
    ptr1=head_a;
    ptr2=head_a;
    if (data==1){
        head_a=head_a->next;
        ptr3=head_a;
    }
    else {
        while (ptr1->next->data!=data){
            ptr1=ptr1->next;
        }
        while (ptr2->data!=data){
            ptr2=ptr2->next;
        }
        ptr1->next=ptr2->next;
        ptr2->next=NULL;
        ptr3=ptr1->next;

    }
    while (ptr3!=NULL){
        ptr3->data=ptr3->data-1;
        ptr3=ptr3->next;
    }
    printf("\033[0;31m");
    printf("\nItem Deleted!\n");
    printf("\033[0m");
    return head_a;
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ADD ITEMS TO CUSTOMER LINKED LIST !!!!!!!!!

void create_node(struct node *find_sr, int quantity)
{
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr1 = head_c;
    order_sr++;
    temp->data = order_sr;
    temp->quantity = quantity;
    strcpy(temp->foodname, find_sr->foodname);
    temp->price = find_sr->price;
    temp->next = NULL;

    if (head_c == NULL)
    {
        head_c = temp;
        return;
    }
    else
    {
        while (ptr1->next != NULL)
            ptr1 = ptr1->next;
        ptr1->next = temp;
    }
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! PLACE ORDER !!!!!!!!!!!
struct node *place_order(struct node *head_a)
{
    int count = 0, choice, quantity;
    struct node *find_sr;

    find_sr = head_a;
    printf("\nEnter the number of item to be ordered : ");
    printf("\033[0;33m");
    scanf("%d", &choice);
    printf("\033[0m");

    if (choice > i || choice < 1)
        printf("Invalid choice!\n");
    else
    {
        printf("Enter the quantity of the item to be ordered : ");
        printf("\033[0;33m");
        scanf("%d", &quantity);
        printf("\033[0m");
        printf("\n");

        while (find_sr != NULL)
        {
            if (find_sr->data == choice)
            {
                create_node(find_sr, quantity);
            }

            find_sr = find_sr->next;
        }
    }
    printf("\033[0;31m");
    printf("Order Placed!!\n");
    printf("\033[0m");
    return head_a;
} 

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! DISPLAY ORDER !!!!!!!!!!!!!!
void displayorder()
{
    struct node *ptr = head_c;
    printf("\033[0;33m");
    printf("\n\n  \t\t\t\t\t\t------------------------------------------------------------------------------\n");
    printf("  \t\t\t\t\t\t\tSr\t\tFood Item\t\tPrice\t\tQuantity\n");
    printf("  \t\t\t\t\t\t------------------------------------------------------------------------------\n");
    if (ptr==NULL){
        printf("  \t\t\t\t\t\t\tNA\t\tNA\t\t\tNA\t\tNA\n");
        printf("  \t\t\t\t\t\t------------------------------------------------------------------------------\n\n\n");
    printf("\033[0m");
        return ;
    }
    while (ptr != NULL)
    {
        printf("  \t\t\t\t\t\t\t%d.\t\t%s\t\t\t%.2f\t\t%d\n", ptr->data, ptr->foodname, ptr->price, ptr->quantity);
        ptr = ptr->next;
    }
    printf("  \t\t\t\t\t\t------------------------------------------------------------------------------\n\n");
    printf("\033[0m");
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! DELETE AN ITEM FROM ORDERED ITEMS !!!!!!!!!!!!!!!!!!!!!!!
void delete_item()
{
    int choice, quantity;
    struct node *ptr = head_c, *ptr1;

    displayorder();
    printf("\nEnter the number of item to be deleted : ");
    printf("\033[0;33m");
    scanf("%d", &choice);
    printf("\033[0m");
    printf("Enter the quantity of items to be deleted : ");
    printf("\033[0;33m");
    scanf("%d", &quantity);
    printf("\033[0m");
    printf("\033[0m");
    if (head_c->next == NULL) 
    {
        ptr->quantity = (ptr->quantity) - quantity;
        if (ptr->quantity < 0)
        {
            printf("\033[0;31m");
            printf("\nQuantity of items to be deleted is more than originally ordered!\n");
            printf("\033[0m");
            return;
        }

        else if (ptr->quantity == 0)
        {
            free(head_c);
            order = NULL;
        }
    }

    else if (choice == 1) 
    {
        ptr->quantity = (ptr->quantity) - quantity;
        ptr = head_c, ptr1 = head_c;

        if (ptr->quantity < 0) 
        {
            printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Deletion amount more than ordered quantity !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            return;
        }

        else if (ptr->quantity == 0) 
        {
            ptr1 = ptr1->next;
            while (ptr1 != NULL)
            {
                (ptr1->data)--;
                ptr1 = ptr1->next;
            }
            head_c = head_c->next;
            
            ptr = NULL;
        }
    }

    else 
    {
        while (ptr->next->data != choice) 
            ptr = ptr->next;

        ptr->next->quantity = (ptr->next->quantity) - quantity;

        if (ptr->quantity < 0)
        {
            printf("\033[0;31m");
            printf("\nQuantity of items to be deleted is less than originally ordered!\n");
            printf("\033[0m");
            return;
        }

        else if (ptr->next->quantity == 0)
        {
            ptr1 = ptr->next->next;
            ptr->next->next = NULL;
            free(ptr->next);
            ptr->next = ptr1;
            while (ptr1 != NULL)
            {
                (ptr1->data)--;
                ptr1 = ptr1->next;
            }
        }
        ptr1=order;       
    }
    order_sr--;
    printf("\033[0;31m");
    printf("\nItem Deleted1!\n");
    printf("\033[0m");
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  DISPLAY BILL !!!!!!!!!!!!!!!!!!!!!!!!!!!
void displaybill()
{
    struct node *ptr = head_c;
    bill=0;
    displayorder();
    printf("\033[0;33m");
    while (ptr != NULL)
    { 
        bill += (ptr->price) * (ptr->quantity);
        ptr = ptr->next;
    }
    printf("  \t\t\t\t\t\t\t\t\t\t\t     Final Bill :\t%.2f\n\n",bill);
    printf("\033[0m");
}


//!!!!!!!!!!!!!!!!!!!!!!!!!!! ADMIN MENU !!!!!!!!!!!!!!!!
void adminmenu(){
    printf("\033[0;32m");
    printf("\t\t\t\t\t\t\t\t\tPress 1 to VIEW total sales\n");
    printf("\t\t\t\t\t\t\t\t\tPress 2 to ADD new items to order menu\n");
    printf("\t\t\t\t\t\t\t\t\tPress 3 to DELETE items from order menu\n");
    printf("\t\t\t\t\t\t\t\t\tPress 4 to DISPLAY order menu\n");
    printf("\t\t\t\t\t\t\t\t\tPress 5 to CHANGE admin password\n");
    printf("\t\t\t\t\t\t\t\t\tPress 6 to EXIT to main menu\n");
    printf("\033[0m");
    printf("Enter your choice ---->  ");
}


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! CUSTOMER MENU !!!!!!!!!!!!!!!!!!!
void customermenu(){
    printf("\033[0;32m");
    printf("\t\t\t\t\t\t\t\t\tPress 1 to PLACE your order\n");
    printf("\t\t\t\t\t\t\t\t\tPress 2 to VIEW your ordered items\n");
    printf("\t\t\t\t\t\t\t\t\tPress 3 to DELETE an item from your order\n");
    printf("\t\t\t\t\t\t\t\t\tPress 4 to DISPLAY final bill\n");
    printf("\t\t\t\t\t\t\t\t\tPress 5 to EXIT to main menu\n");
    printf("\033[0m");
    printf("Enter your choice ---->  ");
}


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1 PASSWORD CHANGE !!!!!!!!!!!!!!!!!!!
void changepassword(){
    int i;
    printf("\n\t\t\t\t\t\t\t\t\tEnter your password : ");
    printf("\033[0;33m");
    scanf("%d",&i);
    printf("\033[0m");
    if (i==password){
        int c;
        printf("\t\t\t\t\t\t\t\t\tEnter the new password : ");
        printf("\033[0;33m");
        scanf("%d",&c);
        printf("\033[0m");
        password=c;
        printf("\033[0;31m");
        printf("\nPassword changed succesfully!\n");
        printf("\033[0m");
    }
    else {
        printf("\033[0;31m");
        printf("Wrong password!\nBack to Main Menu\n");
        printf("\033[0m");
    }
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ADMIN CHOICE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void admin(){
    while (1){
        int choice1;
        adminmenu();
        printf("\033[0;33m");
        scanf("%d",&choice1);
        printf("\033[0m");
        if (choice1==6){
            break;
        }
        switch (choice1) {
        case 1:
            displayorder();
            break;
        case 2:
            head_a=addmenu(head_a);
            break;
        case 3:
            head_a=deletemenu(head_a);
            break;
        case 4:
            displayadmin(head_a);
            break;
        case 5:
            changepassword();
            break;
        default:
            printf("Incorrect Choice! \nPlease choose a valid option.\n");    
        }
    }

}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!! CUSTOMER CHOICE !!!!!!!!!!!!!!!!!!!!!!!!!!!
void customer(){
    while (1){
        int choice2;
        customermenu();
        printf("\033[0;33m");
        scanf("%d",&choice2);
        printf("\033[0m");
        if (choice2==5){
            break;
        }
        switch (choice2) {
        case 1:
            displayadmin(head_a);
            head_a=place_order(head_a);
            break;
        case 2:
            displayorder();
            break;
        case 3:
            delete_item();
            break;
        case 4:
            displaybill();
            break;
        default:
            printf("Incorrect Choice! Please choose a valid option.\n");    
        }
    }

}



//!!!!!!!!!!!!!!!!!!!!!!!! PASSWORD !!!!!!!!!!!
void pass(){
    printf("\n\t\t\t\t\t\t\t\t\tEnter the password : ");
        int b;
        printf("\033[0;33m");
        scanf("%d",&b);
        printf("\033[0m");
        printf("\n");
        if (b==password){
            admin();
        }
        else{
            printf("\033[0;31m");
            printf("Wrong Password!\n");
            printf("\033[0m");
            int b;
            printf("\033[0;32m");
            printf("\n\t\t\t\t\t\t\t\t\tPress 1 to RE-ENTER the password\n");
            printf("\t\t\t\t\t\t\t\t\tPress 2 to EXIT to main menu\n");
            printf("\033[0m");
            printf("Enter your choice ---->  ");
            printf("\033[0;33m");
            scanf("%d",&b);
            printf("\033[0m");
            switch (b)
            {
            case 1 :
                pass();
                break;
            case 2 :
                break;
            default:
                printf("Invaid option!\nBack to Main Menu!\n");
                break;
            }
        }
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! MAIN !!!!!!!!!!!!!!!!!!!!!!!!
int main(){
    head_a=createadmin(head_a,"A",100.00);
    head_a=createadmin(head_a,"B",150.00);
    head_a=createadmin(head_a,"C",200.00);
    head_a=createadmin(head_a,"D",50.00);
    head_a=createadmin(head_a,"E",120.00);   
    printf("\033[0;33m");
    printf("\n\t\t\t\t\t\t***************************************************************************\n");
    printf("\n\t\t\t\t\t\t\t\t\t   WELCOME TO OUR RESTAURANT \n\n");
    printf("\t\t\t\t\t\t****************************************************************************\n");
    printf("\033[0m");
    int choice;
    while (1){
        mainmenu();
        printf("\033[0;33m");
        scanf("%d",&choice);
        printf("\033[0m");
        if (choice==3){
            printf("\033[0;33m");
            printf("\n\t\t\t\t\t\t***************************************************************************\n");
            printf("\n\t\t\t\t\t\t\t\t\t   THANK YOU FOR VISITING \n\n");
            printf("\t\t\t\t\t\t****************************************************************************\n");
            printf("\033[0m");         
        }
        switch (choice) {
        case 1:
            pass();
            break;
        case 2:
            customer();
            break;
        case 3:
            exit(1);
        default:
            printf("Incorrect Choice!\nPlease choose a valid option.\n");    
        }
    }

}
