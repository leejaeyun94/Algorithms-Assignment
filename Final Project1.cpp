#include <stdio.h>
#define MAX_SIZE 100

typedef struct vertex {
    char id;
	int index;
	int d;
	char phi;
};

typedef struct priority_queue {
    vertex heap[MAX_SIZE];
    int size;
 	priority_queue(){
 		size = 0;
	}
    void swap(vertex *a, vertex *b) {
        vertex tmp = *a;
        *a = *b;
        *b = tmp;
    }
 
    int push(vertex value) {
        if (size + 1 > MAX_SIZE) {
            return 0;
        }
 
        heap[size] = value;
 
        int current = size;
        int parent = (size - 1) / 2;
 
        while (current > 0 && heap[current].d > heap[parent].d) {
            swap(&heap[current], &heap[parent]);
            current = parent;
            parent = (parent - 1) / 2;
        }
 
        size++;
 
        return 1;
    }
 
    vertex pop() {
        vertex ret = heap[0];
        size--;
 
        heap[0] = heap[size];
        int current = 0;
        int leftChild = current * 2 + 1;
        int rightChild = current * 2 + 2;
        int minNode = current;
 
        while (leftChild < size) {
            if (heap[minNode].d > heap[leftChild].d) {
                minNode = leftChild;
            }
            if (rightChild < size && heap[minNode].d > heap[rightChild].d) {
                minNode = rightChild;
            }
 
            if (minNode == current) {
                break;
            }
            else {
                swap(&heap[current], &heap[minNode]);
                current = minNode;
                leftChild = current * 2 + 1;
                rightChild = current * 2 + 2;
            }
        }
        return ret;
    }
 
    int empty() {
        if (size == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
}priority_queue;

//s t x y z
//0 1 2 3 4
int graph[5][5] = {
{0,3,0,5,0},
{0,0,6,2,0},
{0,0,0,0,2},
{0,1,4,0,6},
{3,0,7,0,0}
};

void relax(vertex u, vertex v) {
	if(v.d > u.d + graph[u.index][v.index]) {
		v.d = u.d + graph[u.index][v.index];
		v.phi = u.id;
		}
	}
int main(void) {
	struct vertex s = {.id = 's', .index = 0, .d = 0, .phi = 'n'};
	struct vertex t = {.id = 't', .index = 1, .d = 9999, .phi = 'n'};
	struct vertex x = {.id = 'x', .index = 2, .d = 9999, .phi = 'n'};
	struct vertex y = {.id = 'y', .index = 3, .d = 9999, .phi = 'n'};
	struct vertex z = {.id = 'z', .index = 4, .d = 9999, .phi = 'n'};
	
	vertex vertexList[5] = {s, t, x, y, z};

	struct priority_queue q;
	// struct priority_queue s;

	q.push(s);
	q.push(t);
	q.push(x);
	q.push(y);
	q.push(z);

	while(q.size > 0) {
		struct vertex u = q.pop();
		printf("%c - %d\n", u.id, u.d);
		// s.push(u);
	
		for(int i=0;i<5; i++){
			if(graph[u.index][i] > 0) {
				//relax(u, vertexlist[i]);
				struct vertex v = vertexList[i];
				if (v.d > u.d + graph[u.index][v.index]){
					v.d = u.d + graph[u.index][v.index];
					v.phi = u.id;
				}
			}
		}
	}
	for (int i = 0; i < 5; i++){
	printf("%c - %d\n", vertexList[i].id, vertexList[i].d);
	}
return 0;
}

