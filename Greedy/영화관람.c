#include <stdio.h>
#include <stdlib.h>

typedef struct movie{
    int s,e;
} movie;


movie movies[100000+10];
int N;
int ans;

void inputData(){
    scanf("%d", &N);
    movie tmp;
    int startTime, endTime;
    for (int i =0; i<N; i++){
        scanf("%d %d", &startTime, &endTime);
        tmp.s = startTime;
        tmp.e = endTime;
        movies[i] = tmp;
    }
}

void outputData(){

    printf("%d", ans);
}

int compare(const void *a,const void *b){
    movie *x = a;
    movie *y = b;

    if(x->e < y->e){
        return -1;
    }else if (x->e > y->e){
        return 1;
    }else {
        return 0;
    }
}

void solve(){
    int crntTime = 1;
    ans+=1;
    crntTime = movies[0].e;

    for (int i =1; i<N; i++){
        if(crntTime >= movies[i].s ){
            continue;
        }else {
            ans+=1;
            crntTime = movies[i].e;
        }

    }
    
}

int main(void)
{
    // 여기서부터 작성
    inputData();
    qsort(movies, N, sizeof(movie), compare);
    solve();
    outputData();
 
    return 0;
}