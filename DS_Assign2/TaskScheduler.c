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
void ShowMenu();

int main(void) {

	ShowMenu();

	return 0;
}

void ShowMenu() {

	printf("Task Scheduler Menu:\n");
	printf("1. Add a Task\n");
	printf("2. Process a Task\n");
	printf("3. Undo Last Completed Task:\n");
	printf("4. View Pending Tasks\n");
	printf("5. View Completed Tasks\n");
	printf("6. Exit\n");
	printf("Enter your choice:");

}