# include <stdio.h>
# include <time.h>

int main(void)
{
   int array[6][10000];
   int i, j;
   int n;
   scanf("%d", &n);
   int sorted[n];
   for(i = 0; i < 6; i++){
		for(j = n; j > 0; j--) {
      		array[i][n-j] = j;
      	//	printf("%d", array[i][n-j]);
		}
	printf("\n");	  	  
   }
   	clock_t start = clock(); // 시작 시간 저장
   bubbleSort(array[0], n);
	clock_t end = clock(); // 코드가 끝난 시간 저장
    printf("bubleTime : %lf\n", (double)(end - start)/CLOCKS_PER_SEC);

   	start = clock(); 
	quickSort(array[1], 0, n - 1);
	end = clock(); 
    printf("quickTime : %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
   
   	start = clock();
   insertionSort(array[2], n);
		end = clock();
    printf("insertTime : %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
   
	start = clock();
   mergeSort(array[3], 0, n - 1, sorted);
	end = clock();
    printf("mergeTime : %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
   
	start = clock();
   bucketSort(array[4], n/10, n);
	end = clock();
    printf("bucketTime : %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
   
	start = clock();
   radixSort(array[5], n);
	end = clock();
    printf("radixTime : %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
   
	for(i = 0; i < 6; i++)
	{
		for(j = 0; j < n; j++){
	//		printf("%d", array[i][j]);
		}
		printf("\n");
	}	
   return 0;
}


void bubbleSort(int array[], int n)
{
	int i, j, temp;
	
	for (i = 0; i < n; i++){
		for (j = 0; j < n - 1- i; j++){
			if(array[j] > array[j + 1]){
				temp = array[j];
				array[j] = array[j +1];
				array[j +1] = temp;
			}
		}
	}

}

void quickSort(int *data, int start, int end){
	
	if(start >= end) //원소가 한개인 경우  
	{
		return;
	}
	int key = start; //키는 첫번째 원소
	int i = start + 1, j = end, temp;
	
	while(i <= j) {//엇갈릴 때까지 반복
		while(i <= end && data[i] <= data[key])//키 값보다 큰 값을 만날 때까지 이동 
		{
			i++;
		}
		while(data[j] >= data[key] && j > start)//키 값보다 작은 값을 만날 때까지 
		{
			j--;
		}
			if(i > j)// 현재 엇갈린 상태면 키 값과 교체  
			{
				temp = data[j];
				data[j] = data[key];
				data[key] = temp;
			}
			else
			{
				temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
		}
	quickSort(data, start, j - 1);
	quickSort(data, j +1, end);
	
}

void insertionSort(int array[], int n)
{
	int i, j, temp;

	for(i = 0; i < n-1; i++)
	{
		j = i;
		while((array[j] > array[j + 1]) && (j>=0))
		{
			temp = array [j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}
	}
	
}


void merge(int a[], int m, int middle, int n, int sorted[]) {
	int i = m;
	int j = middle + 1;
	int k = m;
	int t = 0;

	//작은 순서대로 배열에 삽입
	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	//남은 데이터도 삽입
	if (i > middle) {
		for (t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	//정렬된 배열을 삽입
	for (t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
	
}

void mergeSort(int a[], int m, int n, int sorted[]) {
	//크기가 1보다 큰 경우

	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle, sorted);
		mergeSort(a, middle + 1, n, sorted);
		merge(a, m, middle, n, sorted);
	}
}

void bucketSort(int a[], int div, int size) {
    int buckets[10][size];
    int i, j, pos, bi, buckets_size[size];

    for (i = 0; i < 10; i++) {
        buckets_size[i] = 0;
        for (j = 0; j < size; j++) buckets[i][j] = 9999;
    }

    for (i = 0; i < size; i++) {
        bi = ((a[i]-1)/div);
        buckets[bi][buckets_size[bi]] = a[i];
        buckets_size[bi]++;
    }

    for (i = 0; i < 10; i++) {
        insertionSort(buckets[i], size);
    }
    pos = 0;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < buckets_size[i]; j++) {
            a[pos++] = buckets[i][j];
        }
    }
}

void radixSort(int array[], int size) {
	int max = array[0];
	int digit = 0;
	int factor = 1;
	int i = 0;
	int j = 0;
	int k = 0;
	int q = 0;
	int queue[4 * 10 * size];
	int front=0, rear = 0;

	for (i = 1; i < size; i++) {
		if (max < array[i]) max = array[i];
	}
	for (i = max; i > 0; i /= 10) {
		digit++;
	}
	
	for (i = 0; i < digit; i++) {
		for (j = 0; j < 10; j++) {
			for ( k = 0; k < size; k++) {
				if ((array[k] / factor) % 10 == j) {
					queue[rear++] = array[k];
					
				}
			}
		}
		factor *= 10;
		int arrayIndex = 0;
		for ( q = front; q != rear; q++) {
			array[arrayIndex++] = queue[front++];
		}
		
	}
}
