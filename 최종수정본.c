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

//Ŀ�� ��ġ �ٲٴ� �Լ�
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//�ܼ�â ũ��
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

//��Ʈ��
int intro() {
    int a = 0;

    char* text[] = {
        "�߼��ô� �� ���ð� �־�����, �̰������� �ֱ� 'Ʈ���� ī��'��� ���� �����ϰ� �־���.",
        "�����ڵ��� ������� ī�带 ������ ����� ���� ���������� ī�带 �����",
        "'�������� ���ϴ� �Ǹ��� ����'�̶�� Ī�ϰ� �̴� ���տ� �Ϳ����� ������...",
        "���� ī�带 ������Ű�� �̿� ���õ� ������� ó���Ͽ���.",
        "ī�带 ����� �����ڿ��� Į �� ���� ó���� ������ ���Ͽ��� �׷��� ������ �����ȴ�.",
        "�ڽſ��� Ư���� �ǹ̸� ���� �����̾��� ī�带 ź���ϴ� ������ �г븦 ���� Į �𾾴�",
        "�տ� ���� ����� �繰�� ī��� ����� ���� Ư���� �ɷ����� Ż���� �����ϴµ�....",
        "�ڳ׵� �˴ٽ��� ������ �����Ǿ��� Į �� Ż���� �ϸ鼭 ���� ���� �� ���� ������� ���� ī��� ������ٳ�",
        "���� ���� ����� ���δ� Į ��� �������� ���븦 ����ٰ� �ϴ���",
        "���� ����ġ�鼭 ī�尡 �� ��� ������ �������� ���ܵξ��ٴ� ���� �������־�",
        "�ε� �ڳװ� Į �� ã�� ī�尡 �� ���� ������� �ٽ� �ǵ��� ������ �ϳ�",
        "�ε� ����� �ֱ⸦ �ٶ��"
    };
    int num_text = sizeof(text) / sizeof(text[0]);

    for (a; a < 7; a++) {
        printf("%s\n", text[a]);
        fflush(stdout);
        Sleep(3000);
        
    }


    //�����
    printf(" _________________ \n");
    printf("|                 |\n");
    printf("|                 |\n");
    printf("|    |\\ /\\ /|     |\n");
    printf("|    / ��  ��\\    |\n");
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
//����
void Playerattack() {
    FILE* file;


    x = 50;
    y = 26;

    file = fopen("emptycard.txt", "r");

    // ���� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 25;

    // �÷��̾�ī�� ���� ����
    file = fopen("1p.txt", "r");

    // �÷��̾�ī�� ���
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

    // ���� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 24;

    // �÷��̾�ī�� ���� ����
    file = fopen("1p.txt", "r");

    // �÷��̾�ī�� ���
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

    // ���� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 23;

    // �÷��̾�ī�� ���� ����
    file = fopen("1p.txt", "r");

    // �÷��̾�ī�� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);
    //--------------------------------------------------------------------------------
    //�ǰ� ���
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

    // ���� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 24;

    // �÷��̾�ī�� ���� ����
    file = fopen("1p.txt", "r");

    // �÷��̾�ī�� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);
    

    x = 50;
    y = 24;

    file = fopen("emptycard.txt", "r");

    // ���� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 25;

    // �÷��̾�ī�� ���� ����
    file = fopen("1p.txt", "r");

    // �÷��̾�ī�� ���
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

    // ���� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }
    //--------------------------------------------------------
    //�ǰݸ������
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

    // �÷��̾�ī�� ���� ����
    file = fopen("1p.txt", "r");

    // �÷��̾�ī�� ���
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

    // ���� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 1;

    // ��ī�� ���� ����
    file = fopen("enemycard.txt", "r");

    // ��ī�� ���
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

    // ���� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 2;

    // ��ī�� ���� ����
    file = fopen("enemycard.txt", "r");

    // ��ī�� ���
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

    // ���� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 3;

    // ��ī�� ���� ����
    file = fopen("enemycard.txt", "r");

    // ��ī�� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);
    //--------------------------------------------------------------------------------
    //�ǰ� ���
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

    // ���� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 2;

    // ��ī�� ���� ����
    file = fopen("enemycard.txt", "r");

    // ��ī�� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);
    
    x = 50;
    y = 2;

    file = fopen("emptycard.txt", "r");

    // ���� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);

    x = 50;
    y = 1;

    // ��ī�� ���� ����
    file = fopen("enemycard.txt", "r");

    // ��ī�� ���
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

    // ���� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }
    //--------------------------------------------------------
    //�ǰݸ������
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

    // ��ī�� ���� ����
    file = fopen("enemycard.txt", "r");

    // ��ī�� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    Sleep(2);



}

//���� ����
void fight_begin() {
    FILE* file;
    printf("\033[H\033[J");
    printf("\033[H");

    gotoxy(90, 32);
    printf("1.���� ��ų 2. ȸ�� ��ų\n");
    gotoxy(90, 33);
    printf("3. ��� ��ų(���� �߰�����)");

    x = 50;
    y = 0;
    // ��ī�� ���� ����
    file = fopen("enemycard.txt", "r");
    if (file == NULL) {
        perror("���� ���� ����");
        return 1;
    }

    // ��ī�� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    x = 50;
    y = 26;

    // �÷��̾�ī�� ���� ����
    file = fopen("1p.txt", "r");
    if (file == NULL) {
        perror("���� ���� ����");
        return 1;
    }

    // �÷��̾�ī�� ���
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        gotoxy(x, y);
        printf("%s", buffer);
        y++;
    }

    //ü�°��ݷ� ���
    gotoxy(82, 18);
    printf("HP : %d",enemyHP);
    gotoxy(82, 19);
    printf("ATK : %d", enemyATK);
    gotoxy(82, 45);
    printf("HP : %d", playerHP);
    gotoxy(82, 46);
    printf("ATK : %d", playerATK);

    // ���� �ݱ�
    fclose(file);
    int order;
    srand(time(NULL));
    order = rand() % 2;

    int WIN;

    gotoxy(50, 23);
    printf("������ ���ϴ����Դϴ�.");
    Sleep(600);
    gotoxy(50, 23);
    printf("                      ");
    Sleep(200);


    switch (order) {
    case 0:
        gotoxy(50, 23);
        printf("�÷��̾ �����Դϴ�.");
        break;

    case 1:
        gotoxy(52, 23);
        printf("���� �����Դϴ�.");
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

        // ���� ���
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            gotoxy(x, y);
            printf("%s", buffer);
            y++;
        }
        gotoxy(50, 23);
        printf("�÷��̾ �̰���ϴ�");
        Sleep(2000);
        break;
    case 1:
        x = 50;
        y = 26;

        file = fopen("emptycard.txt", "r");

        // ���� ���
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            gotoxy(x, y);
            printf("%s", buffer);
            y++;
        }
        gotoxy(52, 23);
        printf("���� �̰���ϴ�");
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
    printf("         ����(1)                    ���(1)\n");
    gotoxy(30, 12);
    printf("       /       \\                   /    \\ \n");
    gotoxy(30, 13);
    printf(" 0    /         \\                 /      \\ \n");
    gotoxy(30, 14);
    printf("/|\\--            ---------------ī��      ----\n");
    gotoxy(30, 15);
    printf("/ \\   \\         /                 \\      /\n");
    gotoxy(30, 16);
    printf("       \\       /                   \\    /\n");
    gotoxy(30, 17);
    printf("         ����(2)                  ����Ʈ ���� ����(2)\n");
    gotoxy(30, 18);
    printf("                                               \n");

}
void Map2() {
    gotoxy(30, 10);
    printf("\n");
    gotoxy(30, 11);
    printf("         ����(1)                    ���(1)\n");
    gotoxy(30, 12);
    printf("       /       \\                   /    \\ \n");
    gotoxy(30, 13);
    printf("      /         \\              O  /      \\ \n");
    gotoxy(30, 14);
    printf("   \--            -------------/|\\ī��      ----\n");
    gotoxy(30, 15);
    printf("   \   \\         /             / \\ \\      /\n");
    gotoxy(30, 16);
    printf("       \\       /                   \\    /\n");
    gotoxy(30, 17);
    printf("         ����(2)                  ����Ʈ ���� ����(2)\n");
    gotoxy(30, 18);
    printf("                                               \n");

}
int main() {
    //SetConsoleOutputCP(CP_UTF8);
    
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.bVisible = 0; // Ŀ���� ������ ���� ����(0�̸� �Ⱥ���, 0���� ���� ���̸� ����)
    cursorInfo.dwSize = 1; // Ŀ���� ũ�⸦ ���� (1~100 ���̸� ����)
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
    printf("���� �������� �����ϼ���:");
    scanf("%d", &choice);
    

    printf("\033[H\033[J");
    gotoxy(50, 23);
    printf("������ ��ȭ ��� ����");
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
    printf("�������� �Ѿ�ϴ�");
    Sleep(3000);
    

    
    printf("\033[H\033[J");
    printf("\033[H");
    Map();
    

    printf("\033[H\033[J");
    printf("\033[H");

    gotoxy(50, 23);
    printf("1.ü��ȸ�� 2.���ݷ����� (ī�� �̹������ �߰� ����)");
    scanf("%d", &choice2);

    if (choice2 == 1) {
        gotoxy(50, 23);
        printf("ü���� ȸ���Ǿ����ϴ�.                                             ");
        playerHP += 50;
        Sleep(3000);
        
    }
    else if (choice2 == 2) {
        gotoxy(50, 23);
        printf("���ݷ��� �����Ͽ����ϴ�.                                           ");
        playerATK += 15;
        Sleep(3000);
        
    }

        
    printf("\033[H\033[J");
    printf("\033[H");
    Map2();
    gotoxy(50, 23);
    printf("���� �������� �����ϼ���:");
    scanf(" %d", &choice);


    switch (choice) {
    case 1:
        printf("\033[H\033[J");
        gotoxy(50, 23);
        printf("����� �߻��߽��ϴ�(�߰�����)");
        Sleep(3000);
        break;
    case 2:
        printf("\033[H\033[J");
        gotoxy(50, 23);
        printf("������ ��ȭ ��� ����");
        Sleep(3000);
        enemyHP = 300;
        enemyATK = 30;
        overwrite("sbat.txt", "enemycard.txt");
        overwrite("sbat_hit.txt", "enemycard_hit.txt");
        fight_begin();
        break;
    }


    gotoxy(50, 23);
    printf("�й��߽��ϴ�");
    Sleep(3000);
    //���α׷� ����
    return 0;
}



/*
1. ���Ϻҷ��ͼ� ��ġ�� ���
2. hp�� atk ���
3. �������� �����İ� ���ϱ�
4. (�ݺ�)���ݷ¸�ŭ ü�±��
5. ���� ü���� 0�� �Ǹ� ��
6, ��ȭ������ �ʱ�ȭ

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
	(21ĭ)
    enemyHP = 100;
    enemyATK = 12;
    overwrite("enemy1.txt", "enemycard.txt");
    overwrite("enemy1_hit.txt", "enemycard_hit.txt");
*/