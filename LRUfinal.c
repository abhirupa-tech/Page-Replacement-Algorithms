
#include<stdio.h>

int main()
{
    int nF, n, frames[10], pages[30], cnt = 0, time[10], flag1, flag2, i, j, pos, fault_count = 0;
    printf("Enter number of frames: ");
    scanf("%d", &nF);

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page numbers: ");

    for(i = 0; i < n; ++i){
        scanf("%d", &pages[i]);
    }

    for(i = 0; i < nF; ++i){
        frames[i] = -1;
    }

    for(i = 0; i < n; ++i){
        //printf("i is %d", i);
        flag1 = flag2 = 0;
        for(j = 0; j < nF; ++j){
            if(frames[j] == pages[i]){
                cnt++;
                time[j] = cnt;
                   flag1 = flag2 = 1;
                   break;
               }
        }


        if(flag1 == 0){
            for(j = 0; j < nF; ++j){
                if(frames[j] == -1){
                    cnt++;
                    fault_count++;
                    frames[j] = pages[i];
                    time[j] = cnt;
                    flag2 = 1;
                    break;
                }
            }
        }

        int l,min = time[0], pos = 0;
        if(flag2 == 0){
            for(l = 1; l < nF; ++l)
            {
                if(time[l] < min){
                    min = time[l];
                    pos = l;
                }
            }
            cnt++;
            fault_count++;
            frames[pos] = pages[i];
            time[pos] = cnt;
        }

        printf("\n");

        for(j = 0; j < nF; ++j){
            printf("%d\t", frames[j]);
        }
    }

    printf("\n\nTotal Page fault_count = %d", fault_count);
    printf("\nMiss ratio = %f",(fault_count/(1.0*n)));
    printf("\nHit ratio = %f",1-(fault_count/(1.0*n)));



    return 0;
}

