#include <stdio.h>
#include <string.h>

#define MAXU 20
#define MAXT 50

// ---------- UNION FOR PRIORITY ----------
typedef union {
    int num;          // number priority
    char text[10];    // label priority
} Punion;

// ---------- TASK ----------
typedef struct {
    char title[50];
    char desc[100];
    Punion pri;       // union variable
    int ptype;        // 1 = number, 2 = label
    char due[20];
} Task;

// ---------- STACK ----------
typedef struct {
    Task arr[MAXT];
    int top;
} Stack;

// ---------- USER ----------
typedef struct {
    char uname[30];
    char pass[30];
    Stack st;
} User;

User user[MAXU];
int ucount = 0;

// ---------- STACK FUNCTIONS ----------
void init(Stack *s) { s->top = -1; }
int empty(Stack *s) { return s->top == -1; }
int full(Stack *s) { return s->top == MAXT - 1; }

void push(Stack *s, Task t) { s->arr[++s->top] = t; }
Task pop(Stack *s) { return s->arr[s->top--]; }

// ---------- USER FUNCTIONS ----------
int findUser(char name[]) {
    for (int i = 0; i < ucount; i++)
        if (strcmp(user[i].uname, name) == 0)
            return i;
    return -1;
}

void regUser() {
    char name[30], pw[30];

    printf("Enter username: ");
    scanf("%s", name);

    if (findUser(name) != -1) {
        printf("User already exists!\n");
        return;
    }

    printf("Enter password: ");
    scanf("%s", pw);

    strcpy(user[ucount].uname, name);
    strcpy(user[ucount].pass, pw);

    init(&user[ucount].st);
    ucount++;

    printf("User Registered!\n");
}

int login() {
    char name[30], pw[30];

    printf("Username: ");
    scanf("%s", name);

    printf("Password: ");
    scanf("%s", pw);

    int id = findUser(name);

    if (id != -1 && strcmp(user[id].pass, pw) == 0) {
        printf("Login Successful!\n");
        return id;
    }

    printf("Login Failed!\n");
    return -1;
}

// ---------- TASK FUNCTIONS ----------
void addTask(Stack *s) {
    if (full(s)) {
        printf("Task list full!\n");
        return;
    }

    Task t;

    printf("Task title: ");
    scanf(" %[^\n]", t.title);

    printf("Task description: ");
    scanf(" %[^\n]", t.desc);

    printf("\nChoose Priority Type:\n");
    printf("1. Number (1-10)\n");
    printf("2. Label (Low/Medium/High)\n");
    printf("Enter: ");
    scanf("%d", &t.ptype);

    if (t.ptype == 1) {
        printf("Enter number priority: ");
        scanf("%d", &t.pri.num);
    } else {
        printf("Enter label priority: ");
        scanf("%s", t.pri.text);
    }

    printf("Due Date (DD/MM/YYYY): ");
    scanf("%s", t.due);

    push(s, t);
    printf("Task Added!\n");
}

void showTasks(Stack *s) {
    if (empty(s)) {
        printf("No tasks!\n");
        return;
    }

    printf("\n--- ALL TASKS ---\n");

    for (int i = s->top; i >= 0; i--) {
        printf("%d) %s | ", s->top - i + 1, s->arr[i].title);

        if (s->arr[i].ptype == 1)
            printf("Priority: %d | ", s->arr[i].pri.num);
        else
            printf("Priority: %s | ", s->arr[i].pri.text);

        printf("Due: %s\n", s->arr[i].due);
    }
}

void showTop(Stack *s) {
    if (empty(s)) {
        printf("No tasks!\n");
        return;
    }

    Task t = s->arr[s->top];

    printf("\n--- TOP TASK ---\n");
    printf("Title: %s\n", t.title);
    printf("Description: %s\n", t.desc);

    if (t.ptype == 1)
        printf("Priority: %d\n", t.pri.num);
    else
        printf("Priority: %s\n", t.pri.text);

    printf("Due: %s\n", t.due);
}

void delTop(Stack *s) {
    if (empty(s)) {
        printf("No task to remove!\n");
        return;
    }

    printf("Removed: %s\n", s->arr[s->top].title);
    pop(s);
}

// ---------- USER MENU ----------
void menuUser(int id) {
    int ch;
    Stack *s = &user[id].st;

    do {
        printf("\n1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. View Top Task\n");
        printf("4. Remove Top\n");
        printf("5. Logout\n");
        printf("Enter: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: addTask(s); break;
            case 2: showTasks(s); break;
            case 3: showTop(s); break;
            case 4: delTop(s); break;
            case 5: printf("Logged out.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 5);
}

// ---------- MAIN ----------
int main() {
    int ch, id;

    while (1) {
        printf("\n1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter: ");
        scanf("%d", &ch);

        if (ch == 1)
            regUser();
        else if (ch == 2) {
            id = login();
            if (id != -1)
                menuUser(id);
        }
        else if (ch == 3)
            break;
        else
            printf("Invalid choice!\n");
    }

    return 0;
}
