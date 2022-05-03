#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node{
	long value;
	int index;
	struct node *next;
}newnode;

void insert(newnode **hashtable,long value ,int index, int n){
	int t = abs(value) % n;
	newnode *temp = hashtable[t];
	newnode *add = (newnode*)malloc(sizeof(newnode));
	add->value = value;
	add->index = index;
	add->next = temp->next;
	temp->next = add;
}

int search(newnode **hashtable, long target,int n){
	int hashindex = abs(target) % n;
	newnode *temp = hashtable[hashindex]->next;
	while(temp){
		if(temp->value == target)
			return temp->index;
		temp = temp->next;
	}
	return -1;
}

void freeHashTable(newnode **hashtable, int n){
	int i = 0;
	newnode *temp = NULL;
	newnode *delete  = NULL;
	for(i = 0 ; i < n ; i++){
		temp = hashtable[i];
		delete = temp;
		while(temp){
			delete = temp;
			temp = temp->next;
			free(delete);
		}
	}
	free(hashtable);
}
int* twoSum(int nums[], int numsSize, int target) {
    int i = 0, j = 0;
    int n = numsSize, index = 0;
    int* result = NULL;
    newnode** hashTable = (newnode**)malloc(n * sizeof(newnode*));
    // init head node
    for(i = 0; i < n; i++)
        hashTable[i] = (newnode*)calloc(1, sizeof(newnode));
    for(i = 0; i < n; i++) {
        index = search(hashTable, target - nums[i], n);
        if(-1 == index)
            insert(hashTable, nums[i], i, n);
        else {
            result = (int*)malloc(sizeof(int) * 2);
            result[0] = index;
            result[1] = i;//因為減去 target 所以直接回傳 i
            freeHashTable(hashTable, n);
            return result;
        }    
    }
    freeHashTable(hashTable, n);
    return result;
}


int main(int argc ,char** argv){
    int *result = (int*)malloc(sizeof(int) * 2);;
    int numss[2] = {3,3};
    result = twoSum(numss,2,6);
    printf("%d,%d \n",result[0],result[1]);
    free(result);
    return 0;
}