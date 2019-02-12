#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 16         
#define TRUE 1           
#define FALSE 0            
#define LOOP 5000        
#define strMAX 10         

typedef struct fast {     
	int Shortest_Distance[MAX];      
	int Prev_Location[MAX];      
}FAST;

char City[MAX][strMAX] = { "서울","춘천","속초","시흥","수원",      
"원주","강릉","천안","상주","보령",        
"대전","전주","대구","광주","마산","부산" };  

void Create_Dijkstra(FAST *, int);        
void Find_RevWay(FAST *, int, int);           

int MenuType;							
int subMenuType;
int SortType = 0;
											
int main() {
	FAST fastSet;               
	int start, end;              
	int i, check;         
	char strStart[strMAX], strEnd[strMAX];  

	while (MenuType != 4) {
		system("cls");

		printf("[1]도시명 출력  [2]가중치그래프 출력  [3]최단거리 찾기  [4]종료\n");
		scanf("%d", &MenuType);

		if (MenuType == 1)
		{
			printf("[1]내림차순 [2]오름차순\n");
			scanf("%d", &subMenuType);
			
			if (subMenuType == 1) SortType = -1;
			if (subMenuType == 2) SortType = 1;
			
			for (int i = 0; i < MAX - 1; i++)
			{
				for (int j = i; j < MAX; j++)
				{
					if (strcmp(City[i], City[j]) == SortType)
					{
						char temp[MAX];
						strcpy_s(temp, strMAX,City[i]);
						strcpy_s(City[i], strMAX, City[j]);
						strcpy_s(City[j], strMAX, temp);
					}
				}
			}
			for (int i = 0; i < MAX; i++)
				printf("%s\n", City[i]);

			system("pause");
		}

		if (MenuType == 2)
		{
			printf("------------------------------------------------------------------------------------\n");
			printf("     서울 춘천 속초 시흥 수원 원주 강릉 천안 상주 보령 대전 전주 대구 광주 마산 부산\n");
			printf("서울   x   70    x   30   40    x    x    x    x    x    x    x    x    x    x    x \n");
			printf("춘천  70    x   90    x    x   65    x    x    x    x    x    x    x    x    x    x \n");
			printf("속초   x   90    x    x    x    x   35    x    x    x    x    x    x    x    x    x \n");
			printf("시흥  30    x    x    x   25    x    x    x    x   95    x    x    x    x    x    x \n");
			printf("수원  40    x    x   25    x   75    x   65    x    x    x    x    x    x    x    x \n");
			printf("원주   x   65    x    x   75    x   85    x   80    x    x    x    x    x    x    x \n");
			printf("강릉   x    x   35    x    x   85    x    x    x    x    x    x    x    x    x   280\n");
			printf("천안   x    x    x    x    x   65    x    x    x    x   100  80    x    x    x    x \n");
			printf("상주   x    x    x    x    x   80    x    x    x    x    x    x   95    x    x    x \n");
			printf("보령   x    x    x   95    x    x    x   100   x    x    x    x    x   110   x    x \n");
			printf("대전   x    x    x    x    x    x    x   80    x    x    x   50   105   x    x    x \n");
			printf("전주   x    x    x    x    x    x    x    x    x    x   50    x    x   30   85    x \n");
			printf("대구   x    x    x    x    x    x    x    x    x    x    x   105   x    x   55   75 \n");
			printf("광주   x    x    x    x    x    x    x    x    x   110   x   30    x    x   40    x \n");
			printf("마산   x    x    x    x    x    x    x    x    x    x    x   85   55   40    x    x \n");
			printf("부산   x    x    x    x    x    x   280   x    x    x    x    x   75    x    x    x \n");
			printf("------------------------------------------------------------------------------------\n");

			system("pause");
		}

		if (MenuType == 3)
		{
			printf("[빠른길 찾기!] 종료를 원하시면 종료를 치세요\n");

			check = 1;                        
			while (check) {
				printf("[1] 출발도시명 : ");
				getchar();                 
				scanf("%s", &strStart);         
				if (!strcmp(strStart, "종료")) exit(0); 

				for (i = 0; i < MAX; i++) {
					if (!strcmp(City[i], strStart)) {
						check = 0;               
						start = i;              
						break;
					}
				}
				if (check != 0) {                
					printf("  [ERR] %s 은(는) 없는지역입니다.\n", strStart);
				}
			}

			check = 1;                   
			while (check) {
				printf("[2] 도착도시명 : ");
				getchar();               
				scanf("%s", &strEnd);        
				if (!strcmp(strEnd, "종료")) exit(0); 
				for (i = 0; i < MAX; i++) {
					if (!strcmp(City[i], strEnd)) {
						check = 0;            
						end = i;                
						break;
					}
				}
				if (check != 0) {       
					printf("  [ERR] %s 은(는) 없는지역입니다.\n", strEnd);
				}
			}

			if (start != end) {                   
				Create_Dijkstra(&fastSet, start);     
				Find_RevWay(&fastSet, start, end);        
													   
				printf(", 최단거리 = %dkm\n", fastSet.Shortest_Distance[end]);
			}
			else {                          
				printf("  [ERR] 같은 장소는 갈수 없습니다.\n");
			}
			system("pause");
		}
	}

	return 0;
}

void Create_Dijkstra(FAST *fastSet, int start) {
	int location[MAX][MAX] = {
		0,70,LOOP,30,40,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,
		70,0,90,LOOP,LOOP,65,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,
		LOOP,90,0,LOOP,LOOP,LOOP,35,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,
		30,LOOP,LOOP,0,25,LOOP,LOOP,LOOP,LOOP,95,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,
		40,LOOP,LOOP,25,0,75,LOOP,65,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,
		LOOP,65,LOOP,LOOP,75,0,85,LOOP,80,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,
		LOOP,LOOP,35,LOOP,LOOP,85,0,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,280,
		LOOP,LOOP,LOOP,LOOP,65,LOOP,LOOP,0,LOOP,100,80,LOOP,LOOP,LOOP,LOOP,LOOP,
		LOOP,LOOP,LOOP,LOOP,LOOP,80,LOOP,LOOP,0,LOOP,LOOP,LOOP,95,LOOP,LOOP,LOOP,
		LOOP,LOOP,LOOP,95,LOOP,LOOP,LOOP,100,LOOP,0,LOOP,LOOP,LOOP,110,LOOP,LOOP,
		LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,80,LOOP,LOOP,0,50,105,LOOP,LOOP,LOOP,
		LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,50,0,LOOP,30,85,LOOP,
		LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,105,LOOP,0,LOOP,55,75,
		LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,110,LOOP,30,LOOP,0,40,LOOP,
		LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,85,55,40,0,LOOP,
		LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,280,LOOP,LOOP,LOOP,LOOP,LOOP,75,LOOP,LOOP,0
	};

	int visited[MAX], next, temp;
	int i, j, k;

	for (i = 0; i<MAX; i++) {
		visited[i] = 0;        
		fastSet->Prev_Location[i] = start;   
	}
	next = start;                

	for (i = 0; i<MAX; i++) {
		for (j = 0; j<MAX; j++) {
			if (i == 0) {
				fastSet->Shortest_Distance[j] = location[start][j]; 
				visited[start] = TRUE;         
			}
			else {
				if ((fastSet->Shortest_Distance[j])>(fastSet->Shortest_Distance[next] + location[next][j])) {
					fastSet->Shortest_Distance[j] = fastSet->Shortest_Distance[next] + location[next][j];
					fastSet->Prev_Location[j] = next;
				}
			}
		}
		temp = LOOP;     

		for (k = 0; k<MAX; k++) {
			if ((temp>fastSet->Shortest_Distance[k]) && (visited[k] == FALSE)) {
				temp = fastSet->Shortest_Distance[k];  
				next = k;             
			}
		}
		visited[next] = TRUE;            
	}
}

void Find_RevWay(FAST *fastSet, int start, int find) {
	int i, set, way[MAX];

	way[0] = start;        
	for (i = 1; i<MAX; i++) {
		way[i] = -1;        
	}
	set = MAX - 1;         
	while (find != start) {
		way[set] = find;     
		set--;           
		find = fastSet->Prev_Location[find];   
	}

	for (i = 0; i<MAX; i++) {
		if (way[i] != -1) {           
			printf("%s", City[way[i]]);     
			if (i != (MAX - 1)) {             
				printf(" -> ");
			}
		}
	}
}