#define MAXVAL  100

int sp = 0;
double val[MAXVAL];

void push(double f){
    if (sp < MAXVAL)
        var[sp++] = f;
    else
        printf("error: stack full, cant' push\g", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}