#include<stdio.h>
#include<windows.h>

char string[10];

void searcharray();
void linearsearch(int array[],int length);
void binarysearch(int array[],int length);
int recursive(int array[],int low,int high,int key);

void ternarysearch(int array[],int length);
int recursive2(int array[],int left,int right,int key);


void sortarray();
void bubblesort(int array[],int length);
void selectionsort(int array[],int length);

int main()
{
    int choice;

    while (1)
    {
        system("cls");
        printf("\n\n\t Enter 1 for Searching Algorithms");
        printf("\n\n\t Enter 2 for Sorting   Algorithms");
        printf("\n\n\t Enter 3 To Exit");
        printf("\n\n\t Choice : ");
        scanf(" %d",&choice);

        switch (choice)
        {
        case 1:
            searcharray();
            break;
        case 2:
            sortarray();
            break;
        case 3:
            break;

        default:
            
            printf("\n\n\t Enter from given choices only");
            printf("\n\n\t Press Enter to continue");
            fflush(stdin);
            gets(string);

            break;
        }

        if(choice==3)
        {
            system("cls");
            printf("\n\n\t Closing The Program");
            printf("\n\n\t Bye-Bye     ");
            Sleep(3000);
            break;
        }
    }
    
}

void searcharray()
{
    system("cls");

    int length;

    printf("\n\n\t Enter the Size of Array : ");
    scanf("%d",&length);

    int array[length];

    int i;
    printf("\n\n\t Array  : ");
    for(i=0;i<length;i++)
    {
        scanf("%d",&array[i]);
    }

    int choice;
    while(1)
    {
        system("cls");
        printf("\n\n\t Enter 1 for Linear Search");
        printf("\n\n\t Enter 2 for Binary Search");
        printf("\n\n\t Enter 3 for Ternary Search");
        printf("\n\n\t Enter 4 To Go Back\n\n\t");
        printf("\n\n\t Choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            linearsearch(array,length);
            break;
        case 2:
            binarysearch(array,length);
            break;
        case 3:
            ternarysearch(array,length);
            break;
        case 4:
                break;
        default:
            printf("\n\n\t Enter from given choices only");
            printf("\n\n\t Press Enter to continue");
            fflush(stdin);
            gets(string);
            break;
        }

        if(choice==4)
        {
            break;
        }
    }
    
    
}

void linearsearch(int array[],int length)
{
    
    int key,i;
    int j;
    printf("\n\n\t Enter The Element To Search : ");
    scanf("%d",&key);

    int flag=0;

    for(i=0;i<length;i++)
    {
        if(array[i]==key)
        {
            flag=1;
            break;
        }
    }
    printf("\n\n\t Given array : ");
    for(j=0;j<length;j++)
    {
        printf("%d ",array[j]);
    }
    if(flag==1)
    {
        
        printf("\n\n\t Element : %d is Present ",key);
        printf("\n\n\t Index : %d   Place : %d",i,i+1);
        printf("\n\n\t Press Enter to continue");
        fflush(stdin);
        gets(string);
    }
    else{
        
        printf("\n\n\t Element Not Found");
        printf("\n\n\t Press Enter to continue");
        fflush(stdin);
        gets(string);
    }
}

void binarysearch(int array[],int length)
{
    int i,j;
    int min=array[0];
    int temp;

    for(i=0;i<length-1;i++)
    {
        for(j=i+1;j<length;j++)
        {
            if(array[j]<min)
            {
                min=array[j];
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }

    printf("\n\n\t enter the key to search : ");
    int key;
    printf("\n\n\t enter the Key : ");
    scanf("%d",&key);
    int x;

    x=recursive(array,0,length-1,key);
    printf("\n\n\t Sorted array : ");
    
    for(j=0;j<length;j++)
    {
        printf("%d ",array[j]);
    }

    if(x==-1)
    {
        printf("\n\n\t Element is not present");
    }
    else{
        printf("\n\n\t Element is present");
        printf("\n\n\t Index : %d  Place : %d",x,x+1);
    }

    printf("\n\n\t press enter to continue");
    fflush(stdin);
    gets(string);
}

int recursive(int array[],int low,int high,int key)
{
    int x=(low+high)/2;
    int result;
    if(key<array[low])
    {
        return -1;
    }
    if(key>array[high])
    {
        return -1;
    }
    if((x==0)||(x>=high)||(x<=low))
    {
        return -1;
    }
    if(array[x]==key)
    {
        return x;
    }
    if(array[x-1]==key)
    {
        return x-1;
    }
    if(array[x+1]==key)
    {
        return x+1;
    }
    if(array[low]==key)
    {
        return low;
    }
    if(array[high]==key)
    {
        return high;
    }
    if(key>array[x])
    {
        result=recursive(array,x+1,high,key);
    }
    else
    {
        result=recursive(array,low,x-1,key);
    }
    return result;

}


void ternarysearch(int array[],int length)
{
    int i,j;
    int min=array[0];
    int temp;

    for(i=0;i<length-1;i++)
    {
        for(j=i+1;j<length;j++)
        {
            if(array[j]<min)
            {
                min=array[j];
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    printf("\n\n\tenter the key to search : ");
    int key;
    scanf("%d",&key);
    int x;
    x=recursive2(array,0,length-1,key);
    
    printf("\n\n\t Sorted array : ");
    for(j=0;j<length;j++)
    {
        printf("%d ",array[j]);
    }
    if(x==-1)
    {
        printf("\n\n\t Element is not present");
    }
    else{
        printf("\n\n\t Element is present");
        printf("\n\n\t Index : %d  Place : %d",x,x+1);
    }

    printf("\n\n\t press enter to continue");
    fflush(stdin);
    gets(string);
}

int recursive2(int array[],int left,int right,int key)
{
    int result;

    int mid1;
    int mid2;

    mid1=left+((right-left)/3);
    mid2=right-((right-left)/3);
    
    
    if(key==array[left])
    {
        return left;
    }
    if(key==array[right])
    {
        return right;
    }
    if(key==array[mid1])
    {
        return mid1;
    }

    if(key==array[mid2])
    {
        return mid2;
    }
     if(key>array[right])
    {
        return -1;
    }
     if(key<array[left])
    {
        return -1;
    }
    /*
    if(left+right<2)
    {
        return -1;
    }
    */
    if(key<array[mid1])
    {
        result=recursive2(array,left,mid1-1,key);
    }
    else if(key<array[mid2])
    {
        result=recursive2(array,mid1+1,mid2-1,key);
    }
    else if(key<array[right])
    {
        result=recursive2(array,mid2+1,right,key);
    }
    
    return result;
}

void sortarray()
{
    system("cls");

    int length;

    printf("\n\n\t Enter the Size of Array : ");
    scanf("%d",&length);

    int array[length];

    int i;
    printf("\n\n\t Array  : ");
    for(i=0;i<length;i++)
    {
        scanf("%d",&array[i]);
    }

    int choice;
    while(1)
    {
        system("cls");
        printf("\n\n\t Enter 1 for Bubble Sort");
        printf("\n\n\t Enter 2 for selection Sort");
        printf("\n\n\t Enter 99 To Go Back\n\n\t");
        printf("\n\n\t Choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            bubblesort(array,length);
            break;
        case 2:
            selectionsort(array,length);
            break;
        
        case 99:
                break;
        default:
            printf("\n\n\t Enter from given choices only");
            printf("\n\n\t Press Enter to continue");
            fflush(stdin);
            gets(string);
            break;
        }

        if(choice==99)
        {
            break;
        }
    }
    
    
}

void selectionsort(int array[],int length)
{
    int temp[length];
    int temperoray;
    int i,j;
    int min;

    for(i=0;i<length;i++)
    {
        temp[i]=array[i];
    }

    for(i=0;i<length-1;i++)
    {
        min=temp[i];

        for(j=i+1;j<length;j++)
        {
            if(temp[j]<min)
            {
                temperoray=temp[i];
                temp[i]=temp[j];
                temp[j]=temperoray;
                min=temp[i];
            }
        }
    }

    printf("\n\n\t Given Array : ");
    for(i=0;i<length;i++)
    {
         printf("%d ",array[i]);
    }

    printf("\n\n\t Sorted Array : ");
    for(i=0;i<length;i++)
    {
         printf("%d ",temp[i]);
    }

    fflush(stdin);
    gets(string);

}

void bubblesort(int array[],int length)
{
    int temp[length];
    int temperoray;
    int i,j,k;
    int min;

    for(i=0;i<length;i++)
    {
        temp[i]=array[i];
    }

    for(i=0;i<length-1;i++)
    {
        for(j=length-1,k=length-2;k>=i;j--,k--)
        {
            if(temp[j]<temp[k])
            {
                temperoray=temp[k];
                temp[k]=temp[j];
                temp[j]=temperoray;
            }
        }
    }

    printf("\n\n\t Given Array : ");
    for(i=0;i<length;i++)
    {
         printf("%d ",array[i]);
    }

    printf("\n\n\t Sorted Array : ");
    for(i=0;i<length;i++)
    {
         printf("%d ",temp[i]);
    }

    fflush(stdin);
    gets(string);
}
