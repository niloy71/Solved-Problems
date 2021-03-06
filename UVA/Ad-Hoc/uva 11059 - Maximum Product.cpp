/*
Used Technique: Brute-force

Explanation:
Here you need to find the maximum product of a consecutive sequence from the Array.
We can do it using brute-force approach. Here we use two counter for finding the maximum product.
One counter count only the product of consecutive positive numbers.
Another counter count the product of consecutive sequence which has even number of negative numbers. But no zero.
This counter may need iterate from both side of the array.
If any zero encountered both counter will reset.
The answer is the maximum value counted by the counter. Remember to check, if you find any positive sequence in the array or not.

*/


#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    long long n, cnt, mns_cnt, cur_cnt, mx_cnt, f, mark, i, tc = 1, ara[20];

    while(1 == scanf("%lld", &n)){
        mx_cnt = 0;
        cnt = mns_cnt = cur_cnt = 1;
        for(i = 0; i < n; i++){
            scanf("%lld", &ara[i]);
        }
        mark = 0;
        f = 0;
        for(i = 0; i < n; i++){
            if(ara[i] > 0){
                mark = 1;
                cnt *= ara[i];
                cur_cnt *= ara[i];
            }
            else if(ara[i] < 0){
                mx_cnt = max(mx_cnt, cur_cnt);
                cur_cnt = 1;

                mns_cnt *= ara[i];
                if(mns_cnt > 0){
                    mark = 1;
                    cnt *= mns_cnt;
                    mns_cnt = 1;
                    f = 0;
                }
                else{
                    mx_cnt = max(mx_cnt, cnt);
                    f = 1;
                }
            }
            else{
                if(!f)
                    mx_cnt = max(mx_cnt, cnt);
                mx_cnt = max(mx_cnt, cur_cnt);
                cnt = cur_cnt = mns_cnt = 1;
                f = 0;
            }
        }
        if(!f)
            mx_cnt = max(mx_cnt, cnt);
        mx_cnt = max(mx_cnt, cur_cnt);
        cnt = cur_cnt = mns_cnt = 1;

        f = 0;
        for(i = n-1; i >= 0; i--){
            if(ara[i] > 0){
                cnt *= ara[i];
                cur_cnt *= ara[i];
            }
            else if(ara[i] < 0){
                mx_cnt = max(mx_cnt, cur_cnt);
                cur_cnt = 1;

                mns_cnt *= ara[i];
                if(mns_cnt > 0){
                    cnt *= mns_cnt;
                    mns_cnt = 1;
                    f = 0;
                }
                else{
                    mx_cnt = max(mx_cnt, cnt);
                    f = 1;
                }
            }
            else{
                if(!f)
                    mx_cnt = max(mx_cnt, cnt);
                mx_cnt = max(mx_cnt, cur_cnt);
                cnt = cur_cnt = mns_cnt = 1;
                f = 0;
            }
        }
        if(!f)
            mx_cnt = max(mx_cnt, cnt);
        mx_cnt = max(mx_cnt, cur_cnt);
        cnt = cur_cnt = 1;

        if(!mark)
            printf("Case #%lld: The maximum product is 0.\n\n", tc++);
        else
            printf("Case #%lld: The maximum product is %lld.\n\n", tc++, mx_cnt);

    }
}
