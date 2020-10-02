#include <iostream>
using namespace std;

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int A[],int s,int e){
  int pivot = A[e];
  int index = s;
  for(int i = s; i<e; i++){
    if(A[i]<=pivot){
      swap(&A[i],&A[index]);
      index++;
    }
  }
  swap(&A[index],&A[e]);
  return index;
}

void quickSort(int A[],int s,int e){
  if(s<e){
    int p = partition(A,s,e);
    quickSort(A,s,p-1);
    quickSort(A,p+1,e);
  }
}

void bubbleSort(int A[],int n){
  int i,j;
  for(i=0;i<n-1;i++){
    for(j=0;j<n-1-i;j++){
      if(A[j]>A[j+1]){
        swap(&A[j], &A[j+1]);
      }
    }
  }
}

void selectionSort(int A[],int n){
  int i,j,k;
  for(i=0;i<n-1;i++){
    for(j=k=i;j<n-1;j++){
      if(A[j]<A[k]){
        k=j;
      }
    }
    swap(&A[i], &A[k]);
  }
}

void merge(int A[],int l,int r,int m){
  int i=l,j=m+1,k=l;
  int temp[100];
  while(i<=m && j<=r){
    if(A[i]<=A[j]){
      temp[k] = A[i];
      k++,i++;
    }
    else{
      temp[k] = A[j];
      k++,j++;
    }
  }
  while(i<=m){
    temp[k]=A[i];
    k++,i++;
  }
  while(j<=r){
    temp[k]=A[j];
    k++,j++;
  }
  for(int x=l;x<=r;x++){
    A[x] = temp[x];
  }
}

void mergeSort(int A[],int l, int r){
  if(l<r){
    int m = (l+r)/2;
    mergeSort(A,l,m);
    mergeSort(A,m+1,r);
    merge(A,l,r,m);
  }
}

int findMax(int A[],int n){
  int i,x;
  x = A[0];
  for(i=1;i<n;i++){
    if(x<A[i]){
      x = A[i];
    }
  }
  return x;
}

void countSort(int A[],int n){
  int max = findMax(A,n);
  int temp[max+1],i,j;
  for(i=0;i<max+1;i++){
    temp[i] = 0;
  }
  for(i=0;i<n;i++){
    temp[A[i]]++;
  }
  i=j=0;
  while(j<max+1){
    if(temp[j]>0){
      A[i] = j;
      i++;
      temp[j]--;
    }
    else{
      j++;
    }
  }
}

int main() {
  int n,i;
  cout<<"Enter the number of elements: ";
  cin>>n;
  int A[n];
  cout<<"\nPlease enter "<<n<<" elements in the array: ";
  for(i=0;i<n;i++){
    cin>>A[i];
  }

  cout<<"\n1: Bubble Sort\n"<<
        "2: Selection Sort\n"<<
        "3: Quick Sort\n"<<
        "4: Merge Sort\n"<<
        "5: Count Sort\n";
  int option;
  cout<<"\nPlease select option from 1 to 5: ";
  cin>>option;
  switch (option){
     case 1 :
         bubbleSort(A, n); 
         break;
      case 2 :
         selectionSort(A,n);
         break;
      case 3 :
         quickSort(A,0,n-1);
         break;
      case 4 :
         mergeSort(A,0,n-1);
         break;
      case 5 :
         countSort(A,n);
         break;
      default :
         cout << "Invalid option" << endl;
         break;
  }
  if(option>5){
    return 0;
  }
  else{
    cout<<"\nYour option is: "<<option<<"\n";
    cout<<"Performing sorting....\n";
    for(i = 0;i<n;i++){
    cout<<A[i]<<" ";
  }
  }
}