/* https://www.hackerrank.com/contests/realhack-2-0/challenges/the-shooter/problem

problem :

Kasun and Nuwan are best friends. Kasun is good at archery. One day they went to a carnival held in their area. There are so many things to have fun, but both these friends were interested in one game. That is>

There are two steps in this game. The first step is to shoot to a wheel that represents x numbers. According to that number ( n ) which he shot in first target wheel and he was given n number of arrows to shoo>

ex - : if he shoots that wheel and gets shot to number 8, he will be given 8 arrows to shoot to cylindrical targets of different size diameter.

Though Nuwan is not good in archery, he could shoot successfully only few targets at every time that they were playing. Kasun saw there was a pattern in Nuwan's shooting skill. He shoots successfully only the >

cylindric targets have the following parameter(s): ar: an array of integers representing diameters of the cylindric targets

Input Format

The first line contains a single integer, n denoting the number of where Nuwan shot in that wheel of the target in the first step in that game. The second line contains n space-separated integers, where each i>

Constraints

image

Output Format

Return the number of targets that can be shot on a new line.

Sample Input 0

10
18 90 90 13 90 75 90 8 90 43
Sample Output 0

5

...........................................................................

code :
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i,num,n,greatest;

    num=0;
    scanf("%d",&n);
    int a[n];

    for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    }
    greatest = a[0];
    for (i = 0; i < n; i++) {
     if (a[i] > greatest) {
     greatest = a[i];
    }
    }

    for (i = 0; i < n; i++) {
     if (a[i] == greatest) {
         num++;
    }


}
     printf("%d",num);
      return 0;
    }





