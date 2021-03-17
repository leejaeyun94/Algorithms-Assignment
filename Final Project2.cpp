#include <stdio.h>
#define MAX 8
#define WHITE 0
#define GRAY 1
#define BLACK 2

int front=-1;
int rear=-1;
int queue[MAX];
 
int isEmpty(void){
    if(front==rear)//front와 rear가 같으면 큐는 비어있는 상태
        return 0;
    else return 1;
}
int isFull(void){
    int tmp=(rear+1)%MAX; //원형 큐에서 rear+1을 MAX로 나눈 나머지값이
    if(tmp==front)//front와 같으면 큐는 가득차 있는 상태
        return 0;
    else
        return 1;
}
void enQ(int value){
    if(isFull() == 0)
        printf("Queue is Full.\n");
    else{
         rear = (rear+1)%MAX;
         queue[rear]=value;
        }

}
int deQ(){
    if(isEmpty() == 0)
        printf("Queue is Empty.\n");
    else{
        front = (front+1)%MAX;
        return queue[front];
    }
}

int main(void) {
//r s t u v w x y
//0 1 2 3 4 5 6 7
int graph[8][8] = {
{0,1,0,0,1,0,0,0},
{1,0,0,0,0,1,0,0},
{0,0,0,1,0,1,1,0},
{0,0,1,0,0,0,1,1},
{1,0,0,0,0,0,0,0},
{0,1,1,0,0,0,1,0},
{0,0,1,1,0,1,0,1},
{0,0,0,1,0,0,1,0}
};
int source = 1;
int color[8] = {WHITE, };
int d[8] = {0, };
int phi[8] = {-1, };

color[source] = GRAY;
d[source] = 0;
phi[source] = -1;
enQ(source);

while(isEmpty() == 1) {
int u = deQ();
for(int j=0; j<MAX; j++) {
if(graph[u][j] == 1) {
int adjustV = j;
if(color[adjustV] == WHITE) {
color[adjustV] = GRAY;
d[adjustV] = d[u] + 1;
phi[adjustV] = u;
enQ(adjustV);
}
}
}
color[u] = BLACK;
printf("vector:%d : d:%d, phi:%d\n", u, d[u], phi[u]);
}
return 0;
}
