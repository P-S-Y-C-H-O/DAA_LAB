#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *front=NULL;
struct Node *rear=NULL;

void enqueue(int n){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=n;
    newNode->next=NULL;
    if(rear==NULL){
        front=newNode;rear=newNode;
    } 
    else{
        rear->next=newNode;
        rear=newNode;
    }
    printf("%d inserted into queue\n",n);
}

void dequeue(){
    if(front==NULL){
        printf("Queue Underflow\n");
        return;
    }
    struct Node* temp=front;
    printf("Removed: %d\n",front->data);
    front=front->next;
    if(front==NULL)
        rear=NULL;
    free(temp);
}

void peek(){
    if(front==NULL) printf("Queue is empty\n");
    else printf("Front element: %d\n", front->data);
}

void isEmpty(){
    if(front==NULL) printf("Queue is empty\n");
    else printf("Queue is not empty\n");
}

void display(){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp=front;
    printf("Queue: ");
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    while(1){
        printf("\n\t\t MENU:\n");
        printf("Enter 1 for Enqueue (Insert an element at the rear)\n");
        printf("Enter 2 for Dequeue (Remove an element from the front)\n");
        printf("Enter 3 for Peek (View the front element)\n");
        printf("Enter 4 for Check if the queue is empty\n");
        printf("Enter 5 for Display all elements in the queue\n");
        printf("Enter 6 for EXIT\n");
        int c;
        scanf("%d",&c);
        switch(c){
            case 1:{
                int val;
                printf("Enter the value :\n");
                scanf("%d",&val);
                enqueue(val);
                break;
            }
            case 2:{
                dequeue();
                break;
            }
            case 3:{
                peek();
                break;
            }
            case 4:{
                isEmpty();
                break;
            }   
            case 5:{
                display();
                break;
            }
            case 6:{
                return 0;
            }
            case 7:{
                printf("Wrong input\n");
                break;
            }
        }
    }
    return 0;
}
//
/**
 * @file merge_sort.c
 * @brief A menu-driven program to sort array elements using Merge Sort.
 *
 * This program demonstrates the Merge Sort algorithm on different types of data:
 * 1. Pre-sorted in ascending order.
 * 2. Pre-sorted in descending order.
 * 3. Randomly ordered.
 *
 * It reads data from input files, sorts it, and measures the performance
 * by counting comparisons and timing the execution of the sort operation.
 * The sorted data is then written to corresponding output files.
 *
 * Note on Compiling:
 * On some Linux systems, you may need to link the real-time library for
 * clock_gettime(). Compile using: gcc merge_sort.c -o merge_sort -lrt
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Use a long long int for the comparison counter to prevent overflow with large datasets.
long long int comparison_count;

/**
 * @brief Prints the elements of an integer array.
 * @param arr The array to be printed.
 * @param size The number of elements in the array.
 */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Merges two subarrays of arr[].
 * First subarray is arr[left..mid]
 * Second subarray is arr[mid+1..right]
 * This function is where the core comparison work happens.
 * @param arr The main array being sorted.
 * @param left The starting index of the left subarray.
 * @param mid The ending index of the left subarray.
 * @param right The ending index of the right subarray.
 */
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays to hold the two halves.
    int L[n1], R[n2];

    // Copy data from the main array to the temporary arrays.
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into the main array arr[left..right].
    i = 0; // Initial index of the first subarray
    j = 0; // Initial index of the second subarray
    k = left; // Initial index of the merged subarray

    while (i < n1 && j < n2) {
        // This is the primary comparison in the algorithm.
        comparison_count++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // After the main loop, one of the temp arrays might still have elements.
    // Copy any remaining elements from L[].
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements from R[].
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**
 * @brief The main recursive function that sorts arr[left..right] using merge().
 * @param arr The array to be sorted.
 * @param left The starting index.
 * @param right The ending index.
 */
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Calculate the middle point to divide the array into two halves.
        // Using left + (right - left) / 2 avoids potential overflow for very large arrays.
        int mid = left + (right - left) / 2;

        // Recursively call mergeSort on the two halves.
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves.
        merge(arr, left, mid, right);
    }
}

/**
 * @brief Handles the entire process for a given file set.
 * It reads from the input file, times the sort, counts comparisons,
 * prints results, and writes to the output file.
 * @param input_filename The name of the file to read data from.
 * @param output_filename The name of the file to write sorted data to.
 */
void processFile(const char* input_filename, const char* output_filename) {
    FILE *inputFile, *outputFile;
    int arr[501]; // Max size 500 as per prompt, plus one for safety.
    int count = 0;

    inputFile = fopen(input_filename, "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file %s\n", input_filename);
        printf("Please ensure the data files exist or the program has permission to create them.\n");
        return;
    }

    // Read integers from the file into the array until End-Of-File.
    while (count < 501 && fscanf(inputFile, "%d", &arr[count]) != EOF) {
        count++;
    }
    fclose(inputFile);

    if (count == 0) {
        printf("Input file %s is empty or could not be read.\n", input_filename);
        return;
    }

    printf("\nBefore Sorting: ");
    printArray(arr, count);

    // --- Sorting and Performance Measurement ---
    comparison_count = 0;
    struct timespec start, end;
    long long time_elapsed_ns;

    // clock_gettime with CLOCK_MONOTONIC is a high-resolution timer
    // that is not affected by system time changes.
    clock_gettime(CLOCK_MONOTONIC, &start);
    mergeSort(arr, 0, count - 1);
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate the total elapsed time in nanoseconds.
    time_elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);

    // --- Display Results and Write to File ---
    printf("After Sorting: ");
    printArray(arr, count);

    outputFile = fopen(output_filename, "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file %s for writing.\n", output_filename);
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }
    fclose(outputFile);
    printf("Sorted data has been written to %s\n", output_filename);

    printf("\nNumber of Comparisons: %lld\n", comparison_count);
    printf("Actual Execution Time: %lld nanoseconds\n", time_elapsed_ns);
}

/**
 * @brief Creates the necessary data files if they don't already exist.
 */
void generateDataFiles() {
    FILE *file_check;
    // Check if the first file exists. If not, create all three.
    if ((file_check = fopen("inAsce.dat", "r")) == NULL) {
        printf("Data files not found. Creating them for you (400 elements each)...\n");
        
        // Create Ascending Data File
        FILE *f_asce = fopen("inAsce.dat", "w");
        for (int i = 1; i <= 400; i++) fprintf(f_asce, "%d ", i);
        fclose(f_asce);

        // Create Descending Data File
        FILE *f_desc = fopen("inDesc.dat", "w");
        for (int i = 400; i >= 1; i--) fprintf(f_desc, "%d ", i);
        fclose(f_desc);

        // Create Random Data File
        FILE *f_rand = fopen("inRand.dat", "w");
        srand(time(NULL)); // Seed the random number generator
        for (int i = 0; i < 400; i++) fprintf(f_rand, "%d ", rand() % 1000);
        fclose(f_rand);

        printf("Data files created successfully.\n");
    } else {
        // If the file exists, we must close it.
        fclose(file_check);
    }
}


int main() {
    int choice;

    // Check for and generate data files if necessary.
    generateDataFiles();

    while (1) {
        printf("\n\n--- MAIN MENU (MERGE SORT) ---\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. Exit\n");
        printf("--------------------------------\n");
        printf("Enter option: ");

        // Robustly handle user input.
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number (1-4).\n");
            // Clear the input buffer to prevent an infinite loop on bad input.
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("\n--- Processing Ascending Data ---");
                processFile("inAsce.dat", "outMergeAsce.dat");
                break;
            case 2:
                printf("\n--- Processing Descending Data ---");
                processFile("inDesc.dat", "outMergeDesc.dat");
                break;
            case 3:
                printf("\n--- Processing Random Data ---");
                processFile("inRand.dat", "outMergeRand.dat");
                break;
            case 4:
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid option. Please choose between 1 and 4.\n");
        }
    }

    return 0;
}