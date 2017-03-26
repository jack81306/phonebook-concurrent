#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("orig.txt", "r");
    FILE *output = fopen("output.txt", "w");
    if (!fp) {
        printf("ERROR opening input file orig.txt\n");
        exit(0);
    }
    char append[50], find[50],del[50];
    double orig_sum_a = 0.0, orig_sum_f = 0.0, orig_sum_d=0.0, orig_a, orig_f, orig_d;
    for (int i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %s %lf %lf %lf\n", append, find, del,&orig_a, &orig_f, &orig_d);
        orig_sum_a += orig_a;
        orig_sum_f += orig_f;
        orig_sum_d += orig_d;
    }
    fclose(fp);

    fp = fopen("opt.txt", "r");
    if (!fp) {
        fp = fopen("orig.txt", "r");
        if (!fp) {
            printf("ERROR opening input file opt.txt\n");
            exit(0);
        }
    }
    double opt_sum_a = 0.0, opt_sum_f = 0.0,opt_sum_d = 0.0, opt_a, opt_f,opt_d;
    for (int i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %s  %lf %lf %lf\n", append, find, del,&opt_a, &opt_f, &opt_d);
        opt_sum_a += opt_a;
        opt_sum_f += opt_f;
        opt_sum_d += opt_d;
    }

    fp=fopen("threadpool.txt","r");
    if (!fp) {
        printf("ERROR opening input file orig.txt\n");
        exit(0);
    }
    double pool_sum_a = 0.0, pool_sum_f = 0.0,pool_sum_d = 0.0, pool_a, pool_f,pool_d;
    for (int i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %s  %lf %lf %lf\n", append, find, del,&pool_a, &pool_f, &pool_d);
        pool_sum_a += pool_a;
        pool_sum_f += pool_f;
        pool_sum_d += pool_d;
    }

    fprintf(output, "append() %lf %lf %lf\n", orig_sum_a / 100.0,
            opt_sum_a / 100.0, pool_sum_a / 100.0);
    fprintf(output, "findName() %lf %lf %lf\n", orig_sum_f / 100.0,
            opt_sum_f / 100.0, pool_sum_f / 100.0);
    fprintf(output, "deleteName() %lf %lf %lf\n", orig_sum_d / 100.0,
            opt_sum_d / 100.0, pool_sum_d / 100.0);
    fclose(output);
    fclose(fp);
    return 0;
}
