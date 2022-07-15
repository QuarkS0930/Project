#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
// define linked list
struct student
{
    char name[32];
    char code[9];
    double grade;
    struct student *next;
};
typedef struct student student;
student *isNULL(student *start)
{
    if(start==NULL)
    {
        printf("A null Linked list");
    }
    else
    {
        printf("Linked list is not empty");
    }
    return start;
}

student *create_ll(student *start)
{
    char str1[32], str2[8]; 
    double a;
    student *new_node, *ptr;
    new_node = (student*)malloc(sizeof(student));
    printf("Name of student");
    fgets(str1, sizeof(str1), stdin);
    printf("Code of student");
    fgets(str2, sizeof(str2), stdin);
    printf("Grade of student");
    scanf("%lf", &a);
    strcpy(new_node->name, str1);
    strcpy(new_node->code, str2);
    new_node->grade = a;
    if(start==NULL)
    {
        new_node->next = NULL;
        start = new_node;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr =ptr->next;
        }
        ptr=new_node;
        new_node->next=NULL;
    }
    return start;
}

student *display(student *start)
{
    student *ptr;
    ptr = start;
    while(ptr!=NULL)
    {
        printf("\t %s", ptr->name);
        printf("\t %s", ptr->code);
        printf("\t %lf", ptr->grade);
        printf("\n");
        ptr = ptr->next;
    }
    return start;
}

student *insert_beg(student *start)
{
    char str1[32], str2[9]; 
    double a;
    student *new_node;
    new_node = (student*)malloc(sizeof(student));
    printf("Name of student");
    fgets(str1, sizeof(str1), stdin);
    printf("Code of student");
    fgets(str2, sizeof(str2), stdin);
    printf("Grade of student");
    scanf("%lf", &a);
    strcpy(new_node->name, str1);
    strcpy(new_node->code, str2);
    new_node->grade = a;
    //now start pointer will point to new node
    start = new_node;
    return start;
}

student *insert_end(student *start)
{
    student *new_node, *ptr;
    char str1[32], str2[8]; 
    double a;
    new_node = (student*)malloc(sizeof(student));
    printf("Name of student");
    fgets(str1, sizeof(str1), stdin);
    printf("Code of student");
    fgets(str2, sizeof(str2), stdin);
    printf("Grade of student");
    scanf("%lf", &a);
    strcpy(new_node->name, str1);
    strcpy(new_node->code, str2);
    new_node->grade = a;
    new_node->next = NULL;
    ptr = start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next= new_node;
    return start;
}

student *delete_beg(student *start)
{
    student *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

student *delete_end(student *start)
{
    student *ptr, *preptr;
    ptr = start;
    while(ptr->next!= NULL)
    {
        preptr = ptr;
        ptr=ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}

student *delete_node(student *start)
{
    student *ptr, *preptr;
    char str1[32];
    printf("\n Enter the name data of the deleted node: ");
    fgets( str1, sizeof(str1), stdin);
    ptr = start;
    if( ptr->name== str1)
    {
        start = delete_beg(start);
        free(ptr);
        return start;
    }
    else
    {
        while(ptr->code != str1)
        {
            preptr = ptr;
            ptr=ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return start;
    }
}

student *sort_list(student *start)
{
    student *ptr1, *ptr2;
    student *temp;
    ptr1 = start;
    while(ptr1->next!=NULL)
    {
        ptr2 = ptr1->next;
        while(ptr2!= NULL)
        {
            if(ptr1->grade < ptr2->grade)
            {
                temp = ptr1;
                ptr1 = ptr2;
                ptr2= temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}

student *search(student *start)
{
    student *ptr;
    student *pos=NULL;
    char str2[8];
    ptr= start;
    printf("Enter student code:");
    fgets(str2, sizeof(str2), stdin);
    while(ptr!=NULL)
    {
        if(str2 == ptr->code)
        {
            pos = ptr;
            break;
        }
        else
        {
            ptr = ptr -> next;
        }
    }
    return start;
}

int main()
{
    student *start, *first, *second, *third, *fourth, *first1;
    start = (student*)malloc(sizeof(student));
    first = (student*)malloc(sizeof(student));
    first1 = (student*)malloc(sizeof(student));
    second = (student*)malloc(sizeof(student));
    third = (student*)malloc(sizeof(student));
    fourth = (student*)malloc(sizeof(student));
    student node1, node2, node3, node4;
    start->next = &node1;
    strcpy(node1.name, "Le Minh Anh\0");
    strcpy(node1.code, "20203801\0");
    node1.grade = 3.9;
    node1.next = &node2;
    strcpy(node2.name, "Le Thi Anh\0");
    strcpy(node2.code, "20203802\0");
    node2.grade = 3.8;
    node2.next = &node3;
    strcpy(node3.name, "Le Tuan Anh\0");
    strcpy(node3.code, "20203803\0");
    node3.grade = 3.7;
    node3.next = &node4;
    strcpy(node4.name, "Le Mai Anh\0");
    strcpy(node4.code, "20203804\0");
    node4.grade = 3.6;
    node4.next = NULL;
    display(start);
    sort_list(start);
    display(start);
    int count = 0;
    double sum = 0;
    double sum1 = 0;
    double mean =0;
    double variance ;
    double median =0; 
    int count1 = 0;
    first = start->next;
    while(first != NULL)
    {
        count +=1;
        sum+= first->grade;
        first = first->next;
    }
    mean = sum/count;
    first1 = start ->next;
    while(first1 != NULL)
    {
        sum1+= pow((mean-first1->grade), 2);
        first1 = first1->next;
    }
    variance = sum1/(count -1);
    second = start->next;
    if(count%2==1)
    {
        double n= (count+1)/2; 
        while(second != NULL)
        {
            count1 +=1;
            if(count1==n)
            {
                median = second ->grade;
                break;
            }
            second = second ->next;
        }
    }
    third = start->next;
    if(count%2==0)
    {
        double n1= (count)/2; 
        double n2= (count)/2+1; 
        while(third != NULL)
        {
            count1 +=1;
            if(count1==n1)
            {
                median = (third ->grade + third->next->grade)/2;
            }
            third = third->next;
        }
    }
    char id[9];
    double number;
    int rank=1;
    printf("\nwhat is your stuident id:");
    scanf("%s", id);
    fourth = start->next;
    while(fourth != NULL)
    {
        if(strcmp(id, fourth->code) == 0)
        {
            number = fourth->grade;
            break;
        }
        rank+=1;
        fourth = fourth->next;
    }
    printf("Your grade is: %lf", number );
    printf("Your rank is: %d over %d", rank, count );
    printf("The median is: %lf", median );
    printf("Your mean is: %lf", mean );
}