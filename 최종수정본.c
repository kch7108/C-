#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <io.h>



char buffer[256];
int x = 49;
int y = 0;
int enemyHP = 10;
int enemyATK = 12;
int playerHP = 100;
int playerATK = 30;

//커서 위치 바꾸는 함수
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//콘솔창 크기
void setConsoleWindowSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT rect = { 0, 0, width - 1, height - 1 };
    COORD size = { width, height };

    SetConsoleScreenBufferSize(hConsole, size);
    SetConsoleWindowInfo(hConsole, TRUE, &rect);
}


void overwrite(const char *sourceFile, const char *destinationFile) {
    FILE* source = fopen(sourceFile, "r");
    if (source == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE* destination = fopen(destinationFile, "w");
    if (destination == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return;
    }

    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, destination);
    }

    fclose(source);
    fclose(destination);

}

//인트로
int intro() {
    int a = 0;

    char* text[] = {
        "중세시대 한 도시가 있었으니, 이곳에서는 최근 '트럼프 카드'라는 것이 유행하고 있었다.",
        "수도자들은 사람들이 카드를 가지고 노느라 일을 게을리하자 카드를 보고는",
        "'지옥으로 향하는 악마의 물건'이라고 칭하고 이는 국왕에 귀에까지 들어오니...",
        "왕은 카드를 금지시키고 이와 관련된 사람들을 처벌하였다.",
        "카드를 만드는 제작자였던 칼 디씨 또한 처벌을 피하지 못하였고 그렇게 감옥에 수감된다.",
        "자신에겐 특별한 의미를 가진 물건이었던 카드를 탄압하는 국가에 분노를 느낀 칼 디씨는",
        "손에 닿은 사람과 사물을 카드로 만드는 그의 특별한 능력으로 탈옥을 감행하는데....",
        "자네도 알다시피 감옥에 수감되었던 칼 디가 탈옥을 하면서 나는 물론 온 마을 사람들을 전부 카드로 만들었다네",
        "이후 마을 사람들 말로는 칼 디는 동쪽으로 자취를 감췄다고 하더군",
        "또한 도망치면서 카드가 된 몇몇 위험한 괴물들을 남겨두었다는 보고가 들어오고있어",
        "부디 자네가 칼 디를 찾아 카드가 된 마을 사람들을 다시 되돌려 줬으면 하네",
        "부디 행운이 있기를 바라네"
    };
    int num_text = sizeof(text) / sizeof(text[0]);

    for (a; a < 7; a++) {
        printf("%s\n", text[a]);
        fflush(stdout);
        Sleep(3000);
        
    }


    //왕출력
    printf(" _________________ \n");
    printf("|                 |\n");
    printf("|                 |\n");
    printf("|    |\\ /\\ /|     |\n");
    printf("|    / ㅁ  ㅁ\\    |\n");
    printf("|   _\\_______/_   |\n");
    printf("|  |   |   |  |   |\n");
    printf("|  |   |   |  |   |\n");
    printf("|  |  |_____| |   |\n");
    printf("|  |    | |   |   |\n");
    printf("|  |    | |   |   |\n");
    printf("|                 |\n");
    printf("|                 |\n");
    printf("|_________________|\n");

    for (a; a < num_text; a++) {
        printf("%s\n", text[a]);
        fflush(stdout);
        Sleep(3000);
    }



}
//공격
void Playerattack() {
    FILE* file;


    x = 50;
    y = 26;

    file = fopen("emptycard.txt", "r");

    // 공백 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 25;

    // 플레이어카드 파일 열기
    file = fopen("1p.txt", "r");

    // 플레이어카드 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);
    //--------------------------------------------------------
    x = 50;
    y = 25;

    file = fopen("emptycard.txt", "r");

    // 공백 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 24;

    // 플레이어카드 파일 열기
    file = fopen("1p.txt", "r");

    // 플레이어카드 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);
    //--------------------------------------------------------
    x = 50;
    y = 24;

    file = fopen("emptycard.txt", "r");

    // 공백 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 23;

    // 플레이어카드 파일 열기
    file = fopen("1p.txt", "r");

    // 플레이어카드 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);
    //--------------------------------------------------------------------------------
    //피격 모션
    x = 50;
    y = 0;

    file = fopen("enemycard_hit.txt", "r");

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }
    Sleep(2);
    //------------------------------------------------------------------------------------
    x = 50;
    y = 23;

    file = fopen("emptycard.txt", "r");

    // 공백 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 24;

    // 플레이어카드 파일 열기
    file = fopen("1p.txt", "r");

    // 플레이어카드 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);
    

    x = 50;
    y = 24;

    file = fopen("emptycard.txt", "r");

    // 공백 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 25;

    // 플레이어카드 파일 열기
    file = fopen("1p.txt", "r");

    // 플레이어카드 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);
    //--------------------------------------------------------
    x = 50;
    y = 25;

    file = fopen("emptycard.txt", "r");

    // 공백 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }
    //--------------------------------------------------------
    //피격모션해제
    x = 50;
    y = 0;


    file = fopen("enemycard.txt", "r");

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }
    Sleep(2);

    x = 50;
    y = 26;

    // 플레이어카드 파일 열기
    file = fopen("1p.txt", "r");

    // 플레이어카드 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);



}
void Enemyattack() {
    FILE* file;


    x = 50;
    y = 0;

    file = fopen("emptycard.txt", "r");

    // 공백 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 1;

    // 적카드 파일 열기
    file = fopen("enemycard.txt", "r");

    // 적카드 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);
    //--------------------------------------------------------
    x = 50;
    y = 1;

    file = fopen("emptycard.txt", "r");

    // 공백 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 2;

    // 적카드 파일 열기
    file = fopen("enemycard.txt", "r");

    // 적카드 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);
    //--------------------------------------------------------
    x = 50;
    y = 2;

    file = fopen("emptycard.txt", "r");

    // 공백 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 3;

    // 적카드 파일 열기
    file = fopen("enemycard.txt", "r");

    // 적카드 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);
    //--------------------------------------------------------------------------------
    //피격 모션
    x = 50;
    y = 26;

    file = fopen("1p_hit.txt", "r");

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }
    Sleep(2);
    //------------------------------------------------------------------------------------
    x = 50;
    y = 3;

    file = fopen("emptycard.txt", "r");

    // 공백 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 2;

    // 적카드 파일 열기
    file = fopen("enemycard.txt", "r");

    // 적카드 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);
    
    x = 50;
    y = 2;

    file = fopen("emptycard.txt", "r");

    // 공백 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 1;

    // 적카드 파일 열기
    file = fopen("enemycard.txt", "r");

    // 적카드 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);
    //--------------------------------------------------------
    x = 50;
    y = 1;

    file = fopen("emptycard.txt", "r");

    // 공백 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }
    //--------------------------------------------------------
    //피격모션해제
    x = 50;
    y = 26;


    file = fopen("1p.txt", "r");

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);


    x = 50;
    y = 0;

    // 적카드 파일 열기
    file = fopen("enemycard.txt", "r");

    // 적카드 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);



}

//전투 시작
void fight_begin() {
    FILE* file;
    printf("\033[H\033[J");
    printf("\033[H");

    gotoxy(90, 32);
    printf("1.공격 스킬 2. 회복 스킬\n");
    gotoxy(90, 33);
    printf("3. 방어 스킬(전부 추가예정)");

    x = 50;
    y = 0;
    // 적카드 파일 열기
    file = fopen("enemycard.txt", "r");
    if (file == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    // 적카드 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    x = 50;
    y = 26;

    // 플레이어카드 파일 열기
    file = fopen("1p.txt", "r");
    if (file == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    // 플레이어카드 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    //체력공격력 출력
    gotoxy(82, 18);
    printf("HP : %d",enemyHP);
    gotoxy(82, 19);
    printf("ATK : %d", enemyATK);
    gotoxy(82, 45);
    printf("HP : %d", playerHP);
    gotoxy(82, 46);
    printf("ATK : %d", playerATK);

    // 파일 닫기
    fclose(file);
    int order;
    srand(time(NULL));
    order = rand() % 2;

    int WIN;

    gotoxy(50, 23);
    printf("선공을 정하는중입니다.");
    Sleep(600);
    gotoxy(50, 23);
    printf("                      ");
    Sleep(200);


    switch (order) {
    case 0:
        gotoxy(50, 23);
        printf("플레이어가 선공입니다.");
        break;

    case 1:
        gotoxy(52, 23);
        printf("적이 선공입니다.");
        break;
    }

    Sleep(1000);
    gotoxy(50, 23);
    printf("                      ");


    switch (order) {
    case 0:
        while (1) {

            if (enemyHP <= 0) {
                WIN = 0;
                break;
            }
            else if (playerHP <= 0) {
                WIN = 1;
                break;
            }
            Playerattack();
            enemyHP -= playerATK;
            gotoxy(82, 18);
            printf("HP : %d   ", enemyHP);
            Sleep(1000);

            if (enemyHP <= 0) {
                WIN = 0;
                break;
            }
            else if (playerHP <= 0) {
                WIN = 1;
                break;
            }

            Enemyattack();
            playerHP -= enemyATK;
            gotoxy(82, 45);
            printf("HP : %d   ", playerHP);
            Sleep(1000);

        }
        break;

    case 1:
        while (1) {

            if (enemyHP <= 0) {
                WIN = 0;
                break;
            }
            else if (playerHP <= 0) {
                WIN = 1;
                break;
            }

            Enemyattack();
            playerHP -= enemyATK;
            gotoxy(82, 45);
            printf("HP : %d   ", playerHP);
            Sleep(1000);

            if (enemyHP <= 0) {
                WIN = 0;
                break;
            }
            else if (playerHP <= 0) {
                WIN = 1;
                break;
            }

            Playerattack();
            enemyHP -= playerATK;
            gotoxy(82, 18);
            printf("HP : %d   ", enemyHP);
            Sleep(1000);

        }
        break;
    }

    switch (WIN) {
    case 0:
        x = 50;
        y = 0;

        file = fopen("emptycard.txt", "r");

        // 공백 출력
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            gotoxy(x, y);
            printf("%s", buffer);
            y++;
        }
        gotoxy(50, 23);
        printf("플레이어가 이겼습니다");
        Sleep(2000);
        break;
    case 1:
        x = 50;
        y = 26;

        file = fopen("emptycard.txt", "r");

        // 공백 출력
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            gotoxy(x, y);
            printf("%s", buffer);
            y++;
        }
        gotoxy(52, 23);
        printf("적이 이겼습니다");
        Sleep(2000);
        break;
    }
    printf("\033[H\033[J");
    printf("\033[H");
    WIN = NULL;
}

void Map() {
    gotoxy(30, 10);
    printf("\n");
    gotoxy(30, 11);
    printf("         전투(1)                    사건(1)\n");
    gotoxy(30, 12);
    printf("       /       \\                   /    \\ \n");
    gotoxy(30, 13);
    printf(" 0    /         \\                 /      \\ \n");
    gotoxy(30, 14);
    printf("/|\\--            ---------------카드      ----\n");
    gotoxy(30, 15);
    printf("/ \\   \\         /                 \\      /\n");
    gotoxy(30, 16);
    printf("       \\       /                   \\    /\n");
    gotoxy(30, 17);
    printf("         전투(2)                  엘리트 몬스터 전투(2)\n");
    gotoxy(30, 18);
    printf("                                               \n");

}
void Map2() {
    gotoxy(30, 10);
    printf("\n");
    gotoxy(30, 11);
    printf("         전투(1)                    사건(1)\n");
    gotoxy(30, 12);
    printf("       /       \\                   /    \\ \n");
    gotoxy(30, 13);
    printf("      /         \\              O  /      \\ \n");
    gotoxy(30, 14);
    printf("   \--            -------------/|\\카드      ----\n");
    gotoxy(30, 15);
    printf("   \   \\         /             / \\ \\      /\n");
    gotoxy(30, 16);
    printf("       \\       /                   \\    /\n");
    gotoxy(30, 17);
    printf("         전투(2)                  엘리트 몬스터 전투(2)\n");
    gotoxy(30, 18);
    printf("                                               \n");

}
int main() {
    //SetConsoleOutputCP(CP_UTF8);
    
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.bVisible = 0; // 커서를 보일지 말지 결정(0이면 안보임, 0제외 숫자 값이면 보임)
    cursorInfo.dwSize = 1; // 커서의 크기를 결정 (1~100 사이만 가능)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    setConsoleWindowSize(131,48);
//------------------------------------------------------------------------------------------------------------------
    int choice = 0;
    int choice2 = 0;
    int YO;
    FILE* file;
    
    intro();
    printf("\033[H\033[J");
    printf("\033[H");


    Map();
    gotoxy(50, 23);
    printf("다음 목적지를 선택하세요:");
    scanf("%d", &choice);
    

    printf("\033[H\033[J");
    gotoxy(50, 23);
    printf("적과의 대화 출력 예정");
    Sleep(3000);

    switch (choice) {
    case 1:
        enemyHP = 80;
        enemyATK = 15;
        overwrite("bee.txt", "enemycard.txt");
        overwrite("bee_hit.txt", "enemycard_hit.txt");
        fight_begin();
        break;
    case 2:
        enemyHP = 90;
        enemyATK = 20;
        overwrite("sk.txt", "enemycard.txt");
        overwrite("sk_hit.txt", "enemycard_hit.txt");
        fight_begin();
        break;
    }


    Map();
    gotoxy(50, 22);
    printf("다음으로 넘어갑니다");
    Sleep(3000);
    

    
    printf("\033[H\033[J");
    printf("\033[H");
    Map();
    

    printf("\033[H\033[J");
    printf("\033[H");

    gotoxy(50, 23);
    printf("1.체력회복 2.공격력증가 (카드 이미지등등 추가 예정)");
    scanf("%d", &choice2);

    if (choice2 == 1) {
        gotoxy(50, 23);
        printf("체력이 회복되었습니다.                                             ");
        playerHP += 50;
        Sleep(3000);
        
    }
    else if (choice2 == 2) {
        gotoxy(50, 23);
        printf("공격력이 증가하였습니다.                                           ");
        playerATK += 15;
        Sleep(3000);
        
    }

        
    printf("\033[H\033[J");
    printf("\033[H");
    Map2();
    gotoxy(50, 23);
    printf("다음 목적지를 선택하세요:");
    scanf(" %d", &choice);


    switch (choice) {
    case 1:
        printf("\033[H\033[J");
        gotoxy(50, 23);
        printf("사건이 발생했습니다(추가예정)");
        Sleep(3000);
        break;
    case 2:
        printf("\033[H\033[J");
        gotoxy(50, 23);
        printf("적과의 대화 출력 예정");
        Sleep(3000);
        enemyHP = 300;
        enemyATK = 30;
        overwrite("sbat.txt", "enemycard.txt");
        overwrite("sbat_hit.txt", "enemycard_hit.txt");
        fight_begin();
        break;
    }


    gotoxy(50, 23);
    printf("패배했습니다");
    Sleep(3000);
    //프로그램 종료
    return 0;
}



/*
1. 파일불러와서 위치에 출력
2. hp랑 atk 출력
3. 랜덤으로 선공후공 정하기
4. (반복)공격력만큼 체력깎기
5. 한쪽 체력이 0이 되면 끝
6, 빈화면으로 초기화

	 _______________ (31)
	|               |
	|               |
	|               |
	|               |
	|               |
	|               |
	|               |
	|               |
	|               |
	|_______________|
	(21칸)
    enemyHP = 100;
    enemyATK = 12;
    overwrite("enemy1.txt", "enemycard.txt");
    overwrite("enemy1_hit.txt", "enemycard_hit.txt");
*/