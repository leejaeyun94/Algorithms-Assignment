#include <stdio.h>

int knapsack(int maxWeight, int value[], int weight[]){
int oneWeightValue[6];
int usedIndex[6];
int totalValue = 0;

for(int i=0; i<6; i++) {
oneWeightValue[i] = value[i] / weight[i];
}

for(int i=0; i<6; i++) {
int max=0;
int maxIndex;
for(int j=0; j < 6; j++){
if(usedIndex[j] != -1 && max < oneWeightValue[j]) {
max = oneWeightValue[j];
maxIndex = j;
}
}
usedIndex[maxIndex] = -1;
if(weight[maxIndex] <= maxWeight) {
maxWeight -= weight[maxIndex];
totalValue += value[maxIndex];
printf("%d번 item %dweight 만큼 넣음\n", maxIndex, weight[maxIndex]);
} else {
printf("%d번 item %dweight 만큼 넣음\n", maxIndex, maxWeight);
return totalValue += oneWeightValue[maxIndex] * maxWeight;
}
}
return totalValue;
}

int main(){
    int value[6] = {60, 20, 12,80,30,60};
    int weight[6] = {6, 10, 3, 5, 1, 3};
    int maxWeight = 16;
    int totalValue = knapsack(maxWeight, value, weight);
    printf("total value: %d", totalValue);
    return 0;
}
