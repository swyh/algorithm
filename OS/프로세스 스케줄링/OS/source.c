#include <stdio.h>

struct data {
	int name;
	int burst;
	int priority;
};

void FCFS(data* arr, int pro_count);
void SJF(data* arr, int pro_count);
void RR(data* arr, int pro_count);
void Priority(data* arr, int pro_count);

int main() {
	data arr[10];

	int pro_count = 0, input = 0;
	int name = 0, burst = 0, priority = 0;

	scanf("%d", &input);
	while (input) {
		scanf("%d %d %d", &name, &burst, &priority);
		arr[pro_count].name = name;
		arr[pro_count].burst = burst;
		arr[pro_count].priority = priority;
		pro_count++;
		input--;
	}

	printf("Select Scheduling\n");
	printf("1. FCFS\n");
	printf("2. Non-preemptive SJF\n");
	printf("3. RR\n");
	printf("4. Priority\n");

	int select;
	scanf("%d", &select);

	switch (select)
	{
	case 1:
		FCFS(arr, pro_count);
		break;
	case 2:
		SJF(arr, pro_count);
		break;
	case 3:
		RR(arr, pro_count);
		break;
	case 4:
		Priority(arr, pro_count);
		break;
	default:
		break;
	}
}

void FCFS(data* arr, int pro_count) {
	int wait = 0;
	int total = 0;
	int total_wait = 0;
	for (int i = 0; i < pro_count; i++) {
		total += arr[i].burst;
		printf("Name : %d Wait Time : %d Burst Time : %d\n", arr[i].name, wait, arr[i].burst);
		total_wait += wait;
		wait += arr[i].burst;
	}
	printf("Total Burst Time : %d\n", total);
	printf("Average Wait Time : %d\n", total_wait / pro_count);
}

void SJF(data* arr, int pro_count) {
	data* sort_arr = new data[pro_count];

	for (int i = 0; i < pro_count; i++) {
		sort_arr[i] = arr[i];
	}
	for (int i = 0; i < pro_count; i++) {
		for (int j = i; j < pro_count; j++) {
			if (sort_arr[i].burst > sort_arr[j].burst) {
				data temp = sort_arr[i];
				sort_arr[i] = sort_arr[j];
				sort_arr[j] = temp;
			}
		}
	}
	int wait = 0;
	int total = 0;
	int total_wait = 0;
	for (int i = 0; i < pro_count; i++) {
		total += sort_arr[i].burst;
		printf("Name : %d Wait Time : %d Burst Time : %d\n", sort_arr[i].name, wait, sort_arr[i].burst);
		total_wait += wait;
		wait += sort_arr[i].burst;
	}
	printf("Total Burst Time : %d\n", total);
	printf("Average Wait Time : %d\n", total_wait / pro_count);

}

void RR(data* arr, int pro_count) {

	int* wait = new int[pro_count];
	data* copy_arr = new data[pro_count];

	for (int i = 0; i < pro_count; i++) {
		copy_arr[i] = arr[i];
		wait[i] = 0;
	}

	int total = 0;
	int total_wait = 0;
	int running = pro_count;
	while (running > 0) {
		for (int i = 0; i < pro_count; i++) {
			if (copy_arr[i].burst == 0)
				continue;
			int quantum = 0;
			printf("Name : %d Wait Time : %d Burst Time : %d\n", copy_arr[i].name, wait[i], copy_arr[i].burst);

			if (copy_arr[i].burst > 10) {
				quantum = 10;
				copy_arr[i].burst -= 10;
			}
			else {
				quantum = copy_arr[i].burst;
				copy_arr[i].burst = 0;
				running--;
			}

			for (int j = 0; j < pro_count; j++) {
				if (j == i || copy_arr[j].burst == 0)
					continue;
				wait[j] += quantum;
			}
		}
	}
	for (int i = 0; i < pro_count; i++) {
		total += arr[i].burst;
		total_wait += wait[i];
	}

	printf("Total Burst Time : %d\n", total);
	printf("Average Wait Time : %d\n", total_wait / pro_count);
}

void Priority(data* arr, int pro_count) {
	data* sort_arr = new data[pro_count];

	for (int i = 0; i < pro_count; i++) {
		sort_arr[i] = arr[i];
	}
	for (int i = 0; i < pro_count; i++) {
		for (int j = i; j < pro_count; j++) {
			if (sort_arr[i].priority > sort_arr[j].priority) {
				data temp = sort_arr[i];
				sort_arr[i] = sort_arr[j];
				sort_arr[j] = temp;
			}
		}
	}
	int wait = 0;
	int total = 0;
	int total_wait = 0;
	for (int i = 0; i < pro_count; i++) {
		total += sort_arr[i].burst;
		printf("Name : %d Wait Time : %d Burst Time : %d\n", sort_arr[i].name, wait, sort_arr[i].burst);
		total_wait += wait;
		wait += sort_arr[i].burst;
	}
	printf("Total Burst Time : %d\n", total);
	printf("Average Wait Time : %d\n", total_wait / pro_count);

}