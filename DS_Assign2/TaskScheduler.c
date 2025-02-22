#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Task {

	char Name[100];
	int PriorityLevel;
	struct Task* next;

} Task;

typedef struct Stack {

	int* Data;
	int TopIndex;

} Stack;

typedef struct QueueNode {

	int Data;
	struct QueueNode* NextNode;

} QueueNode;

typedef struct Queue {

	QueueNode* Front; //HEAD
	QueueNode* Back; //TAIL

} Queue;

void AddTask(Queue* TaskQueue, char* TaskName, int PriorityLevel);
void ProcessTask(Queue* TaskQueue, Stack* CompletedTaskStack);
void UndoLastTask(Stack* CompletedTaskStack, Queue* TaskQueue);
void ViewPendingTasks(Queue* TaskQueue);
void ViewCompletedTasks(Stack* CompletedTaskStack);

int main(void) {



	return 0;
}
