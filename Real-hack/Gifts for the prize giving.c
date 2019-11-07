/*
https://www.hackerrank.com/contests/realhack-2-0/challenges/gifts-for-the-prize-giving

problem :
For the annual prize giving of a school you have to keep a few bundles of books on a horizontal table. Those bundles are kept next to each other on this table. You have to check the safety of those bundles of books.

image

If one of the bundle reaches another bundle when it falls, it may cause another bundle to fall. In a case of one bundle falls towards another , the safety rule explains that at least some of the bundles should remain standing .

There is a saboteur student in this school. He tipped either on the left or right end of this array of book bundles. Your challenge is to determine whether either ends (LEFT or RIGHT) or both ends (BOTH) will cause all the bundles to fall due to this saboteur’s action.

To determine if a certain budle will knock over another bundle, use the following two rules:

Left bundle falls if position[i]+h[i]>=position[i_to_test]
Right bundle falls if position[i]-h[i]<=position[i_to_test]
Note that: position[i] is the position of the bundle on the table and h[i] is the height of it.

The test is based on a single event. In other words, if it takes toppling both the left and right ends to knock down all the bundles, you still pass the safety inspection. An example follows:

In the image shown below, bundle R1 can trigger the fall of bundle R2 1+3>=4, but bundle R2 can’t trigger the fall of bundle R1 since 4-2 <=1 is false.

image

Write a code to take the positions and heights of the book stacks as input, and return string out of [‘LEFT’,’RIGHT’,’BOTH’,’NONE’] representing which of the ends is unsafe.

Input Format

In the first line, the number of bundles, n , will be given. In the second line, the position of each bundle, xi , will be given. In the third line, the height of each bundle, hi, will be given.

Constraints

0<n<=100
0<x?<=1000
0<h?<=1000

Output Format

If the bundle fall over (no matter from which end it gets triggered), then return BOTH. If the bundle fall over due to a bundle at leftmost or rightmost, then return LEFT or RIGHT respectively. If neither end toppling will cause all the bundles to fall over, return NONE.

Sample Input 0

5
1 2 3 4 5
1 1 1 1 1

Sample Output 0

BOTH

Explanation 0

Each of the bundles in this case are situated 1 unit away from each other, and the height of each bundle is also 1 unit. All of the bundles will fall over regardless of the side which is pushed over.image

Sample Input 1

5
1 2 3 4 8
1 1 1 1 1

Sample Output 1

NONE

Explanation 1

If the leftmost bundle is pushed over, only the first four stacks will fall over. The last bundle will remain untouched, as none of the previous ones can reach it. Similarly, if the rightmost bundle is pushed over, it can’t reach any of the others.

image

code :
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

/* Enter your code here. Read input from STDIN. Print output to STDOUT */    

int n,i,r,l;
r=0;
l=0;
scanf("%d",&n);
int p[n];
int h[n];
for(i=0;i<n;i++){
 scanf("%d",&p[i]);
}
for(i=0;i<n;i++){
 scanf("%d",&h[i]);
}
for(i=0;i<n;i++){
    if((p[i]+h[i])>=p[i+1])
     {
      if((p[n-i]+h[n-i])>=p[n-i-1])
      {
             r++;
             l++;
       }
        else{
           l++;
       }
}
else if((p[n-i]+h[n-i])>=p[n-i-1])
{
    r++;
}
}      
if(r=n){
    if(l=n){
        printf("BOTH");
    }else{
        printf("RIGHT");
    }
}else if(l=n){
    printf("RIGHT");
}else{
    printf("NONE");
}
}
