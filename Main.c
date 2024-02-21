#include <stdio.h>

float gradw1(float x1,float x2,float y,float w1,float w2) {
    return w1-(0.01*(2*(y-((w1*x1)+(w2*x2))*(-x1))));
}

float gradw2(float x1,float x2,float y,float w1,float w2) {
    return w2-(0.01*(2*(y-((w1*x1)+(w2*x2))*(-x2))));
}

int main() {
    int i,n;
    float x[5][3];
    float w1,w2,new_w1,new_w2,y_pred;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the values of w1 and w2: ");
    scanf("%f %f", &w1, &w2);

    printf("Enter the input variables of x1, x2, and y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f %f", &x[i][0], &x[i][1], &x[i][2]);
    }

    for (i = 0; i < n; i++) {
        new_w1 = gradw1(x[i][0], x[i][1], x[i][2], w1, w2);
        new_w2 = gradw2(x[i][0], x[i][1], x[i][2], w1, w2);
        y_pred = (new_w1 * x[i][0]) + (new_w2 * x[i][1]);
        printf("w1: %.10f\tw2: %.10f\ty_pred: %.10f\n", new_w1, new_w2, y_pred);
        w1 = new_w1;
        w2 = new_w2;
    }

    return 0;
}
