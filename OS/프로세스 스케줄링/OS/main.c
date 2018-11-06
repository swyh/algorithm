#include <stdio.h>
#include <stdlib.h>

void FIFO(int* input, int* frame, int input_size, int frame_size);
void OPT(int* input, int* frame, int input_size, int frame_size);
void LRU(int* input, int* frame, int input_size, int frame_size);
void Second_Chance(int* input, int* frame, int input_size, int frame_size);

int main(int argc, char* argv[]) {
	
	int frame_size = atoi(argv[1]);
	int* frame = malloc(sizeof(int)*frame_size);

	for (int i = 0; i < frame_size; i++) {
		frame[i] = -1;
	}

	FILE *fp;
	fp = fopen("Dataset","r");
	int input_size = 0;
	int input[1000];
	int num;
	while (1) {
		fscanf(fp, "%d", &input[input_size++]);
		if (feof(fp)) break;
	}
	input_size--;
		
	fclose(fp);
	
	printf("Select Page Replacement\n");
	printf("1. FIFO\n");
	printf("2. OPT\n");
	printf("3. LRU\n");
	printf("4. Second-Chance\n");
	
	char c;
	scanf("%c", &c);
	if (c == '$') {
		int select;
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("FIFO");
			FIFO(input, frame, input_size, frame_size);
			break;
		case 2:
			printf("OPT");
			OPT(input, frame, input_size, frame_size);
			break;
		case 3:
			printf("LRU");
			LRU(input, frame, input_size, frame_size);
			break;
		case 4:
			printf("Second-Chance");
			Second_Chance(input, frame, input_size, frame_size);
			break;
		default:
			break;
		}
	}
	free(frame);
	return 0;
}

void FIFO(int* input, int* frame, int input_size, int frame_size) {
	int point = 0;	// page fault 시 frame에서 swap 될 번호
	int fault_size = 0; // page fault가 발생한 횟수이다.

	for (int i = 0; i < input_size; i++) {
		printf("\n");
		int page_fault = 1;	// page_fault가 일어났는지에 대한 변수
		printf("Number : %d", input[i]);

		for (int j = 0; j < frame_size; j++) {	//page fault가 발생하는지 확인
			if (input[i] == frame[j]){	// 같을 때 page fault 발생 X
				page_fault = 0;
				break;
			}
		}
		if (page_fault == 0) continue;
		// page fault가 발생하지 않았으면 다음 input 값을 받도록 continue

		frame[point%frame_size] = input[i];
		// page fault가 발생했을 때 frame에 값 바꿔놓음
		point++;
		// 다음 page fault가 발생했을 때 교체된 frame 다음을 가리킨다.

		for (int j = 0; j < frame_size; j++) { // frame 출력
			printf("     %d", frame[j]);
		}
		fault_size++;	// page fault 횟수를 증가
	}
	printf("\n");
	printf("page_fault : %d\n", fault_size);
}


void OPT(int* input, int* frame, int input_size, int frame_size) {
	int point = 0;	// page-fault 시 frame에서 swap 될 번호
	int* check = malloc(sizeof(int)*frame_size);	
	// 각 frame 중 마지막에 page fualt가 일어날 번호를 찾기 위한 배열

	int fault_size = 0;

	for (int i = 0; i < input_size; i++) {
		printf("\n");
		int page_fault = 1;
		printf("Number : %d", input[i]);

		for (int j = 0; j < frame_size; j++) {	// page fault가 발생하는지 확인
			if (input[i] == frame[j]) {
				page_fault = 0;
				break;
			}
		}
		if (page_fault == 0) continue;	// page_fault가 일어나지 않았으면 계속 진행
		
		if (frame[frame_size - 1] != -1) {	// frame이 가득찼을 때
			for (int i = 0; i < frame_size; i++)	//check 배열 0으로 초기화
				check[i] = 0;
			int check_size = 0;
			for (int j = i; j < input_size; j++) {
				// 현재 시점으로부터 들어오는 input 값들을 비교하기 위한 for문
				for (int k = 0; k < frame_size; k++) {
					// frame의 모든 값을 읽기 위한 for문
					if (check_size == frame_size - 1) break;
					if (input[j] == frame[k] && check[k] == 0) { // check 배열을 이용하여, 
						check[k] = 1;
						check_size++;
// 최근 input 값부터 frame에 존재하면 해당 frame에 해당되는 check를 1로 바꾼다.
// check_size가 frame 값보다 1 작을 때 종료하게 되어, 가장 나중에 page fualt 발생하는 것을 교체함.
					}
				}
			}

			for (int k = 0; k < frame_size; k++) {
				if (check[k] == 0) {	// 가장마지막에 page fualt 되는 값을 교체하기 위함.
					point = k;
					break;
				}
			}
		}
			frame[point] = input[i];	// page fault가 발생했을 때 frame에 값 바꿔놓음
		
			if (frame[frame_size - 1] == -1)	point++;

		for (int j = 0; j < frame_size; j++) { // frame 출력
			printf("     %d", frame[j]);
		}
		fault_size++;
	}
	printf("\n");
	printf("page_fault : %d\n", fault_size);
	free(check);
}

void LRU(int* input, int* frame, int input_size, int frame_size) {
	int point = 0;	// page-fault 시 frame에서 swap 될 번호
	int* time = malloc(sizeof(int)*frame_size);	
	// 각 frame의 time 값을 저장하기 위한 배열
	int fault_size = 0;

	for (int i = 0; i < input_size; i++) {	// (여기서 i를 time 값으로 설정)
		printf("\n");
		int page_fault = 1;
		printf("Number : %d", input[i]);

		for (int j = 0; j < frame_size; j++) {	// page fault가 발생하는지 확인
			if (input[i] == frame[j]) {
				time[j] = i;
				page_fault = 0;
				break;
			}
		}
		if (page_fault == 0)	continue;	// page_fault가 일어나지 않았으면 계속 진행

		if (frame[frame_size - 1] != -1) {	// frame이 가득찼을 때
			int idx = 0;
			for (int j = 0; j < frame_size; j++) {
				// frame 중에서 가장 오래된, time 값이 작은 frame을 찾는다.
				if (time[idx] > time[j]){	// 각 frame 중에서 time 값이 가장 작은 것을 idx로 설정
					idx = j;
				}
			}
			point = idx;
		}

		frame[point] = input[i];	// page fault가 발생했을 때 frame에 값 바꿔놓음
		time[point] = i;			// 현재 들어온 시점의 시간을 i로 함

		if (frame[frame_size - 1] == -1) {	// frame가 가득차지 않았다면(마지막 frame가 비었을 경우)
			point++;
		}

		for (int j = 0; j < frame_size; j++) { // frame 출력
			printf("     %d", frame[j]);
		}
		fault_size++;
	}
	printf("\n");
	printf("page_fault : %d\n", fault_size);
	free(time);
}

void Second_Chance(int* input, int* frame, int input_size, int frame_size) {
	int point = 0;	// page-fault 시 frame에서 swap 될 번호
	int* ref_bit = malloc(sizeof(int)*frame_size);// 각 frame의 참조 비트를 저장(0일 때 방출, 1이면 0으로 바꾸기 위함)
	int position = 0;	// ref_bit 배열에서 0,1을 검사하는 변수
	int fault_size = 0;

	for (int i = 0; i < frame_size; i++)	// 0으로 초기화
		ref_bit[i] = 0;

	for (int i = 0; i < input_size; i++) {
		printf("\n");
		int page_fault = 1;
		printf("Number : %d", input[i]);

		for (int j = 0; j < frame_size; j++) {	// page fault가 발생하는지 확인
			if (input[i] == frame[j]) {
				ref_bit[j] = 1;	// frame의 참조비트를 1로 설정
				page_fault = 0;
				break;
			}
		}
		if (page_fault == 0)	continue;	// page_fault가 일어나지 않았으면 계속 진행
		
		if (frame[frame_size - 1] != -1) {	// frame이 가득찼을 때
			int j = 0;	// j가 frame_size가 될때까지 반복
			while(frame_size + 1 > j){	// frame을 한바퀴 돈다.
				if (position == frame_size) position = 0;// position이 frame_size와 같아지면 frame의 처음부터 확인
				if (ref_bit[position] == 0) {
					// 참조 비트가 0이면 새로 들어올 page의 자리인 point을 해당 position으로 설정한다.
					point = position;
					position++;	// 다음 참조비트 검사가 이뤄질때는 position 다음부터 검사하도록 증가시킴.
					break;
				}
				else	// 참조비트가 1이면 0으로 바꾼다.
					ref_bit[position] = 0;
				position++;	// frame의 다음 자리를 검사하기위해 증가시킴
				j++;
			}
		}

		frame[point] = input[i];	// page fault가 발생했을 때 frame에 값 바꿔놓음
		ref_bit[point] = 1;	// 새로 들어온 frame의 참조비트를 1로 바꾼다.
		
		if (frame[frame_size - 1] == -1) {
			point++;
		}

		for (int j = 0; j < frame_size; j++) { // frame 출력
			printf("     %d", frame[j]);
		}
		fault_size++;
	}
	printf("\n");
	printf("page_fault : %d\n", fault_size);
	free(ref_bit);
}