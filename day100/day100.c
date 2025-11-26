/* todo_stack_union.c
   To-Do List using Stacks and Union
   B.Tech 1st Year - C assignment example
   Compile: gcc todo_stack_union.c -o todo
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TASKS 100
#define MAX_TITLE 100
#define MAX_DESC  200

/* meta_type: 0 => priority (int), 1 => due_date (string) */
typedef struct {
    int id;
    char title[MAX_TITLE];
    char desc[MAX_DESC];
    int done;           /* 0 = not done, 1 = done */
    int meta_type;      /* 0 = priority, 1 = due_date */
    union {
        int priority;
        char due_date[16]; /* "YYYY-MM-DD" fits */
    } meta;
} Task;

/* simple stack for tasks */
typedef struct {
    Task items[MAX_TASKS];
    int top; /* index of top element, -1 when empty */
} TaskStack;

/* Stack helpers */
void init_stack(TaskStack *s) { s->top = -1; }
int is_empty(TaskStack *s) { return s->top == -1; }
int is_full(TaskStack *s) { return s->top == MAX_TASKS - 1; }

int push(TaskStack *s, Task t) {
    if (is_full(s)) return 0;
    s->items[++(s->top)] = t;
    return 1;
}

int pop(TaskStack *s, Task *out) {
    if (is_empty(s)) return 0;
    if (out) *out = s->items[(s->top)--];
    else (s->top)--;
    return 1;
}

int peek(TaskStack *s, Task *out) {
    if (is_empty(s)) return 0;
    if (out) *out = s->items[s->top];
    return 1;
}

/* Utility: read a line from stdin safely */
void read_line(char *buf, int size) {
    if (!fgets(buf, size, stdin)) { buf[0] = '\0'; return; }
    /* remove trailing newline */
    size_t len = strlen(buf);
    if (len > 0 && buf[len-1] == '\n') buf[len-1] = '\0';
}

/* Display a single task */
void print_task(const Task *t) {
    printf("ID: %d\nTitle: %s\nDescription: %s\nStatus: %s\n",
           t->id, t->title, t->desc, t->done ? "Completed" : "Pending");
    if (t->meta_type == 0) {
        printf("Priority: %d\n", t->meta.priority);
    } else {
        printf("Due date: %s\n", t->meta.due_date);
    }
    printf("-----------------------------\n");
}

/* Show all tasks in the stack from top to bottom */
void display_stack(TaskStack *s) {
    if (is_empty(s)) {
        printf("No tasks.\n");
        return;
    }
    for (int i = s->top; i >= 0; --i) {
        printf("[%d] %s - %s %s\n",
               s->items[i].id,
               s->items[i].title,
               s->items[i].done ? "(Completed)" : "(Pending)",
               s->items[i].meta_type == 0 ? "(Priority)" : "(Due)");
    }
}

/* Find next available ID (simply max existing + 1) */
int next_id(TaskStack *active, TaskStack *completed) {
    int mx = 0;
    for (int i = 0; i <= active->top; ++i) if (active->items[i].id > mx) mx = active->items[i].id;
    for (int i = 0; i <= completed->top; ++i) if (completed->items[i].id > mx) mx = completed->items[i].id;
    return mx + 1;
}

/* Delete a task by ID from a stack (keeps LIFO property by using temp stack) */
int delete_by_id(TaskStack *s, int id) {
    if (is_empty(s)) return 0;
    TaskStack temp; init_stack(&temp);
    int found = 0;
    Task t;
    while (pop(s, &t)) {
        if (t.id == id) { found = 1; break; } /* remove this one */
        push(&temp, t);
    }
    /* push back remaining */
    while (pop(&temp, &t)) push(s, t);
    return found;
}

/* Mark a task completed by ID: remove from active stack and push to completed stack */
int mark_completed(TaskStack *active, TaskStack *completed, int id) {
    if (is_empty(active)) return 0;
    TaskStack temp; init_stack(&temp);
    Task t;
    int found = 0;
    while (pop(active, &t)) {
        if (t.id == id) {
            t.done = 1;
            push(completed, t);
            found = 1;
            break;
        }
        push(&temp, t);
    }
    /* restore remaining tasks back to active */
    while (pop(&temp, &t)) push(active, t);
    return found;
}

/* Save stacks to file (binary) */
int save_data(const char *filename, TaskStack *active, TaskStack *completed) {
    FILE *f = fopen(filename, "wb");
    if (!f) return 0;
    fwrite(&active->top, sizeof(active->top), 1, f);
    if (active->top >= 0) fwrite(active->items, sizeof(Task), (size_t)active->top + 1, f);
    fwrite(&completed->top, sizeof(completed->top), 1, f);
    if (completed->top >= 0) fwrite(completed->items, sizeof(Task), (size_t)completed->top + 1, f);
    fclose(f);
    return 1;
}

/* Load stacks from file (binary) */
int load_data(const char *filename, TaskStack *active, TaskStack *completed) {
    FILE *f = fopen(filename, "rb");
    if (!f) return 0;
    fread(&active->top, sizeof(active->top), 1, f);
    if (active->top >= 0) fread(active->items, sizeof(Task), (size_t)active->top + 1, f);
    fread(&completed->top, sizeof(completed->top), 1, f);
    if (completed->top >= 0) fread(completed->items, sizeof(Task), (size_t)completed->top + 1, f);
    fclose(f);
    return 1;
}

/* Add task interactively */
void add_task_interactive(TaskStack *active, TaskStack *completed) {
    if (is_full(active)) { printf("Task list full (max %d).\n", MAX_TASKS); return; }
    Task t;
    t.id = next_id(active, completed);
    t.done = 0;
    printf("Enter title: ");
    read_line(t.title, MAX_TITLE);
    printf("Enter description: ");
    read_line(t.desc, MAX_DESC);

    printf("Choose meta type: 0 = priority (number), 1 = due date (YYYY-MM-DD): ");
    char buf[32];
    read_line(buf, sizeof(buf));
    int mt = atoi(buf);
    if (mt == 0) {
        t.meta_type = 0;
        printf("Enter priority (1=highest, larger=lower): ");
        read_line(buf, sizeof(buf));
        t.meta.priority = atoi(buf);
    } else {
        t.meta_type = 1;
        printf("Enter due date (YYYY-MM-DD): ");
        read_line(t.meta.due_date, sizeof(t.meta.due_date));
    }

    if (push(active, t)) {
        printf("Task added with ID %d.\n", t.id);
    } else {
        printf("Failed to add task.\n");
    }
}

/* View detailed task by ID searching both stacks */
int view_task_by_id(TaskStack *active, TaskStack *completed, int id) {
    for (int i = active->top; i >= 0; --i) if (active->items[i].id == id) { print_task(&active->items[i]); return 1; }
    for (int i = completed->top; i >= 0; --i) if (completed->items[i].id == id) { print_task(&completed->items[i]); return 1; }
    return 0;
}

/* Main interactive menu */
int main(void) {
    TaskStack active, completed;
    init_stack(&active);
    init_stack(&completed);

    const char *datafile = "todo_data.bin";
    load_data(datafile, &active, &completed); /* ignore failure - start empty */

    char choice[8];
    while (1) {
        printf("\n--- To-Do List (Stacks + Union) ---\n");
        printf("1. Add Task\n");
        printf("2. View All Tasks (Active)\n");
        printf("3. View Top Task (Most recent)\n");
        printf("4. Mark Task Completed (by ID)\n");
        printf("5. Delete Task (by ID)\n");
        printf("6. View Completed Tasks\n");
        printf("7. View Task Details (by ID)\n");
        printf("8. Save & Exit\n");
        printf("Choice: ");
        read_line(choice, sizeof(choice));
        int opt = atoi(choice);

        if (opt == 1) {
            add_task_interactive(&active, &completed);
        } else if (opt == 2) {
            printf("Active tasks (most recent first):\n");
            display_stack(&active);
        } else if (opt == 3) {
            Task t;
            if (peek(&active, &t)) {
                printf("Top task (most recent):\n");
                print_task(&t);
            } else {
                printf("No active tasks.\n");
            }
        } else if (opt == 4) {
            printf("Enter ID to mark completed: ");
            char idbuf[16]; read_line(idbuf, sizeof(idbuf));
            int id = atoi(idbuf);
            if (mark_completed(&active, &completed, id))
                printf("Task %d marked completed and moved to Completed stack.\n", id);
            else
                printf("Task with ID %d not found in active tasks.\n", id);
        } else if (opt == 5) {
            printf("Enter ID to delete: ");
            char idbuf[16]; read_line(idbuf, sizeof(idbuf));
            int id = atoi(idbuf);
            if (delete_by_id(&active, id) || delete_by_id(&completed, id))
                printf("Task %d deleted (if existed).\n", id);
            else
                printf("Task with ID %d not found.\n", id);
        } else if (opt == 6) {
            printf("Completed tasks (most recent first):\n");
            display_stack(&completed);
        } else if (opt == 7) {
            printf("Enter ID to view details: ");
            char idbuf[16]; read_line(idbuf, sizeof(idbuf));
            int id = atoi(idbuf);
            if (!view_task_by_id(&active, &completed, id)) printf("No task with ID %d found.\n", id);
        } else if (opt == 8) {
            if (save_data(datafile, &active, &completed)) printf("Saved. Exiting.\n");
            else printf("Save failed, but exiting.\n");
            break;
        } else {
            printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}
