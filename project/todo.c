#include <stdio.h>
#include <string.h>

#define MAX_USERS 20
#define MAX_TASKS 50

/* ---------- TASK STRUCT (priority + due date) ---------- */
typedef struct {
    char title[50];
    char desc[100];
    int priority;       // Each task HAS a priority
    char due[20];       // Each task HAS a due date
} Task;

/* ---------- STACK ---------- */
typedef struct {
    Task t[MAX_TASKS];
    int top;
} Stack;

/* ---------- USER ---------- */
typedef struct {
    char uname[30];
    char pass[30];
    Stack todo;
} User;

User users[MAX_USERS];
int userCount = 0;

/* ---------- CLEAR INPUT BUFFER ---------- */
void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* ---------- STACK FUNCTIONS ---------- */
void initStack(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
int isFull(Stack *s) { return s->top == MAX_TASKS - 1; }

void push(Stack *s, Task x) {
    if (!isFull(s)) s->t[++s->top] = x;
}

Task pop(Stack *s) {
    return s->t[s->top--];
}

/* ---------- FIND USER ---------- */
int findUser(char *name) {
    for (int i = 0; i < userCount; i++)
        if (strcmp(users[i].uname, name) == 0)
            return i;
    return -1;
}

/* ---------- REGISTER USER ---------- */
void registerUser() {
    char name[30], pass[30];

    printf("Enter new username: ");
    scanf("%s", name);

    if (findUser(name) != -1) {
        printf("User already exists!\n");
        return;
    }

    printf("Enter password: ");
    scanf("%s", pass);

    strcpy(users[userCount].uname, name);
    strcpy(users[userCount].pass, pass);
    initStack(&users[userCount].todo);

    userCount++;

    printf("User created successfully!\n");
}

/* ---------- LOGIN USER ---------- */
int loginUser() {
    char name[30], pass[30];

    printf("Username: ");
    scanf("%s", name);
    printf("Password: ");
    scanf("%s", pass);

    int idx = findUser(name);

    if (idx != -1 && strcmp(users[idx].pass, pass) == 0) {
        printf("Login Successful!\n");
        return idx;
    }

    printf("Login Failed!\n");
    return -1;
}

/* ---------- ADD TASK (priority + due date) ---------- */
void addTask(Stack *s) {
    if (isFull(s)) {
        printf("Task limit reached!\n");
        return;
    }

    Task x;

    flushInput();
    printf("Task title: ");
    fgets(x.title, 50, stdin);
    x.title[strcspn(x.title, "\n")] = 0;

    printf("Task description: ");
    fgets(x.desc, 100, stdin);
    x.desc[strcspn(x.desc, "\n")] = 0;

    printf("Enter priority number: ");
    scanf("%d", &x.priority);

    printf("Enter due date (DD/MM/YYYY): ");
    scanf("%s", x.due);

    push(s, x);

    printf("Task added successfully.\n");
}

/* ---------- VIEW ALL TASKS ---------- */
void viewTasks(Stack *s) {
    if (isEmpty(s)) {
        printf("No tasks available.\n");
        return;
    }

    printf("\n--- Task List ---\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d) %s | Priority: %d | Due: %s\n",
               s->top - i + 1,
               s->t[i].title,
               s->t[i].priority,
               s->t[i].due);
    }
}

/* ---------- VIEW TOP TASK ---------- */
void viewTop(Stack *s) {
    if (isEmpty(s)) {
        printf("No tasks.\n");
        return;
    }

    Task x = s->t[s->top];

    printf("\n--- Top Task ---\n");
    printf("Title: %s\n", x.title);
    printf("Description: %s\n", x.desc);
    printf("Priority: %d\n", x.priority);
    printf("Due Date: %s\n", x.due);
}

/* ---------- REMOVE TOP TASK ---------- */
void removeTop(Stack *s) {
    if (isEmpty(s)) {
        printf("No tasks to remove.\n");
        return;
    }

    Task x = pop(s);
    printf("Task removed: %s\n", x.title);
}

/* ---------- USER MENU ---------- */
void userMenu(int uid) {
    int ch;
    Stack *s = &users[uid].todo;

    do {
        printf("\n--- USER MENU (%s) ---\n", users[uid].uname);
        printf("1. Add Task\n");
        printf("2. View All Tasks\n");
        printf("3. View Top Task\n");
        printf("4. Remove Top Task\n");
        printf("5. Logout\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: addTask(s); break;
            case 2: viewTasks(s); break;
            case 3: viewTop(s); break;
            case 4: removeTop(s); break;
            case 5: printf("Logged out.\n"); break;
            default: printf("Invalid option.\n");
        }
    } while (ch != 5);
}

/* ---------- MAIN ---------- */
int main() {
    int ch, uid;

    while (1) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) registerUser();
        else if (ch == 2) {
            uid = loginUser();
            if (uid != -1) userMenu(uid);
        }
        else if (ch == 3) break;
        else printf("Invalid choice.\n");
    }

    return 0;
}
