#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* Bubble Sort */
void bubbleSort(int a[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

/* Selection Sort */
void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

/* Insertion Sort */
void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

/* Quick Sort */
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

/* Merge Sort */
void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    int *L = new int[n1];
    int *R = new int[n2];

    for(int i=0;i<n1;i++)
        L[i]=arr[l+i];
    for(int j=0;j<n2;j++)
        R[j]=arr[m+1+j];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=L[i];
        i++; k++;
    }

    while(j<n2){
        arr[k]=R[j];
        j++; k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

/* Max Heap Sort (Ascending) */
void maxHeapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && arr[l]>arr[largest])
        largest = l;

    if(r<n && arr[r]>arr[largest])
        largest = r;

    if(largest!=i){
        swap(arr[i], arr[largest]);
        maxHeapify(arr,n,largest);
    }
}

void maxHeapSort(int arr[], int n){
    for(int i=n/2-1;i>=0;i--)
        maxHeapify(arr,n,i);

    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        maxHeapify(arr,i,0);
    }
}

/* Min Heap Sort (Descending) */
void minHeapify(int arr[], int n, int i){
    int smallest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && arr[l]<arr[smallest])
        smallest = l;

    if(r<n && arr[r]<arr[smallest])
        smallest = r;

    if(smallest!=i){
        swap(arr[i], arr[smallest]);
        minHeapify(arr,n,smallest);
    }
}

void minHeapSort(int arr[], int n){
    for(int i=n/2-1;i>=0;i--)
        minHeapify(arr,n,i);

    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        minHeapify(arr,i,0);
    }
}

/* Shell Sort */
void shellSort(int arr[], int n){
    for(int gap = n/2; gap>0; gap/=2){
        for(int i=gap;i<n;i++){
            int temp = arr[i];
            int j;
            for(j=i;j>=gap && arr[j-gap]>temp;j-=gap){
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}

int main(){
    int n,key;

    do{
        cout<<"Enter Size of Array: ";
        cin>>n;

        int *arr = new int[n];

        cout<<"Enter Elements: ";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        cout<<"\n------Choose Sorting------\n";
        cout<<"1. Bubble Sort\n";
        cout<<"2. Insertion Sort\n";
        cout<<"3. Selection Sort\n";
        cout<<"4. Quick Sort\n";
        cout<<"5. Merge Sort\n";
        cout<<"6. Max Heap Sort (Ascending)\n";
        cout<<"7. Min Heap Sort (Descending)\n";
        cout<<"8. Shell Sort\n";
        cout<<"9. Exit\n";
        cout<<"Enter choice: ";
        cin>>key;

        switch(key){
            case 1: bubbleSort(arr,n); break;
            case 2: insertionSort(arr,n); break;
            case 3: selectionSort(arr,n); break;
            case 4: quickSort(arr,0,n-1); break;
            case 5: mergeSort(arr,0,n-1); break;
            case 6: maxHeapSort(arr,n); break;
            case 7: minHeapSort(arr,n); break;
            case 8: shellSort(arr,n); break;
            case 9: cout<<"Exiting...\n"; delete[] arr; continue;
            default: cout<<"Invalid choice\n"; delete[] arr; continue;
        }

        cout<<"Sorted Array: ";
        printArray(arr,n);

        delete[] arr;

    }while(key!=9);

    return 0;
}
