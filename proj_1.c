#include <stdio.h>

// void functions -> A
void printArray(int *arr, int size);
void reverseArray(int *arr, int size);
void bubbleSort(int *arr, int size);
void rotateRight(int *arr, int size);
void rotateLeft(int *arr, int size);
void printDuplicates(int *arr, int size);

// int functions -> B
int findMax(int *arr, int size);
int findMin(int *arr, int size);
int getSum(int *arr, int size);
int linearSearch(int *arr, int size);
int removeDuplicates(int *arr, int size);
int isSorted(int *arr, int size);

int main()
{
    int num_of_arr_element,choice;
    void (*ptr_A[6])(int*,int)={printArray,reverseArray,bubbleSort,rotateRight,rotateLeft,printDuplicates};
    int (*ptr_b[6])(int*,int)={findMax,findMin,getSum,linearSearch,removeDuplicates,isSorted};

    printf("please enter the number of array element\n");
    scanf("%d",&num_of_arr_element);

    int arr[num_of_arr_element];
    int siz=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<num_of_arr_element;i++)
    {
        printf("please enter element number %d:  ",i+1);
        scanf("%d",&arr[i]);
    }

    // loop for menue
    while(1)
    {
        printf("\n select number from the below value to make operation in the array\n===== MENU =====\n");
        printf("Group A (void):\n");
        printf("1. Print Array\n");
        printf("2. Reverse Array\n");
        printf("3. Bubble Sort\n");
        printf("4. Rotate Right\n");
        printf("5. Rotate Left\n");
        printf("6. Print Duplicates\n");
        printf("-------------------------\n");

        printf("Group B (int):\n");
        printf("7. Find Max\n");
        printf("8. Find Min\n");
        printf("9. Get Sum\n");
        printf("10. Linear Search\n");
        printf("11. Remove Duplicates\n");
        printf("12. Check if Sorted\n");
        printf("0. Exit\n");

        printf("================\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        if(choice == 0) break;

        switch(choice)
        {
            case 1: case 2: case 3: case 4: case 5: case 6:
            {
                ptr_A[choice-1](arr,siz);
                break;
            }
            case 7: case 8: case 9:
            {
                if(choice==7)
                {
                    printf("the max value is: %d \n",ptr_b[choice-7](arr,siz));
                }
                else if(choice==8)
                {
                    printf("the min value is: %d \n",ptr_b[choice-7](arr,siz));
                }
                else
                {
                    printf("the sum of value is: %d \n",ptr_b[choice-7](arr,siz));
                }
                break;
            }
            case 10:
            {
                int b=ptr_b[choice-7](arr,siz);
                if(b!=-1)
                {
                    printf("i found element in the index number %d",b+1);
                }
                else
                {
                    printf("i canot find the element in the array");
                }
                break;
            }
            case 11:
            {
                int n_size = ptr_b[choice-7](arr,siz);
                printf("the new size= %d\n",n_size);
                siz=n_size;
                printf("Array after removing duplicates: ");
                printArray(arr,siz);
                break;
            }
            case 12:
            {
                int result = ptr_b[choice-7](arr,siz);
                if(result==1)
                {
                    printf("Arry is sorted\n");
                }
                else
                {
                    printf("Arry is not sorted\n");
                }
                break;
            }
            default:
            {
                printf("please enter avalible choice from 1 to 12");
            }
        }
		printf("\n\n");
    }
    return 0;
}

// void
void printArray(int *arr, int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void reverseArray(int *arr, int size) {
    for(int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
    printf("Array after reverse: ");
    printArray(arr,size);
}

void bubbleSort(int *arr, int size) {
    for(int i = 0; i < size - 1; i++)
        for(int j = 0; j < size - 1 - i; j++)
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    printf("Array after bubble sort: ");
    printArray(arr,size);
}

void rotateRight(int *arr, int size) {
    int last = arr[size - 1];
    for(int i = size - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = last;
    printf("Array after rotate right: ");
    printArray(arr,size);
}

void rotateLeft(int *arr, int size) {
    int first = arr[0];
    for(int i = 0; i < size - 1; i++)
        arr[i] = arr[i + 1];
    arr[size - 1] = first;
    printf("Array after rotate left: ");
    printArray(arr,size);
}

void printDuplicates(int *arr, int size) {
    int found=0;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) {
                printf("Duplicate: %d\n", arr[i]);
                found=1;
                break;
            }
        }
    }
    if(!found) printf("No duplicates found.\n");
    printf("Current Array: ");
    printArray(arr,size);
}

// int
int findMax(int *arr, int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}

int findMin(int *arr, int size) {
    int min = arr[0];
    for(int i = 1; i < size; i++)
        if(arr[i] < min)
            min = arr[i];
    return min;
}

int getSum(int *arr, int size) {
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

int linearSearch(int *arr, int size) {
    int target;
    printf("Enter number to search: ");
    scanf("%d", &target);
    for(int i = 0; i < size; i++) {
        if(arr[i] == target)
            return i;
    }
    return -1;
}

int removeDuplicates(int *arr, int size) {
    int temp[size];
    int newSize = 0;

    for(int i = 0; i < size; i++) {
        int found = 0;
        for(int j = 0; j < newSize; j++) {
            if(arr[i] == temp[j]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            temp[newSize++] = arr[i];
        }
    }

    for(int i = 0; i < newSize; i++)
        arr[i] = temp[i];

    return newSize;
}

int isSorted(int *arr, int size) {
    for(int i = 0; i < size - 1; i++)
        if(arr[i] > arr[i + 1])
            return 0;
    return 1;
}
