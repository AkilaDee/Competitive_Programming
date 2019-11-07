/*
https://www.hackerrank.com/contests/sliit-overnight-hackathon-round-2/challenges/brackets-game/problem

Jack was writing a custom Array parser in C++. To validate his progress he needs a simple bracket close tag detector with following simple requirements

If brackets [ and ( are properly closed with ] and ) respectively it returns VALID

If those brackets are closed in incorrect manner or if there are missing brackets it returns INVALID

Write a simple program for this scenario

Input Format

String s

Constraints
1 < len(s) < 100


Output Format

VALID or INVALID

Sample Input 0

Array : ([2,4] , [2.4])
Sample Output 0

VALID
Explanation 0

Brackets are properly closed

Sample Input 1

Array : ([2], (4,5)]
Sample Output 1

INVALID
Explanation 1

Last closing bracket should be )
............................................................................

code:
*/



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stdlib.h> 
#define bool int
using namespace std;



/* Enter your code here. Read input from STDIN. Print output to STDOUT */  
  
/* structure of a stack node */
struct sNode 
{ 
   char data; 
   struct sNode *next; 
}; 
  
/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data); 
  
/* Function to pop an item from stack*/
int pop(struct sNode** top_ref); 
  
/* Returns 1 if character1 and character2 are matching left 
   and right Parenthesis */
bool isMatchingPair(char character1, char character2) 
{ 
   if (character1 == '(' && character2 == ')') 
     return 1; 
   else if (character1 == '{' && character2 == '}') 
     return 1; 
   else if (character1 == '[' && character2 == ']') 
     return 1; 
   else
     return 0; 
} 
  
/*Return 1 if expression has balanced Parenthesis */
bool areParenthesisBalanced(char exp[]) 
{ 
   int i = 0; 
  
   /* Declare an empty character stack */
   struct sNode *stack = NULL; 
  
   /* Traverse the given expression to check matching parenthesis */
   while (exp[i]) 
   { 
      /*If the exp[i] is a starting parenthesis then push it*/
      if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') 
        push(&stack, exp[i]); 
  
      /* If exp[i] is an ending parenthesis then pop from stack and  
          check if the popped parenthesis is a matching pair*/
      if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') 
      { 
              
          /*If we see an ending parenthesis without a pair then return false*/
         if (stack == NULL) 
           return 0;  
  
         /* Pop the top element from stack, if it is not a pair  
            parenthesis of character then there is a mismatch. 
            This happens for expressions like {(}) */
         else if ( !isMatchingPair(pop(&stack), exp[i]) ) 
           return 0; 
      } 
      i++; 
   } 
     
   /* If there is something left in expression then there is a starting 
      parenthesis without a closing parenthesis */
   if (stack == NULL) 
     return 1; /*balanced*/
   else
     return 0;  /*not balanced*/
}  
  
/* UTILITY FUNCTIONS */
/*driver program to test above functions*/


int main() 
{ 
  char exp[100] = "{()}[]"; 
  if (areParenthesisBalanced(exp)) 
    printf("VALID \n"); 
  else
    printf("INVALID \n");   
  return 0; 
}     
  
/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data) 
{ 
  /* allocate node */
  struct sNode* new_node = 
            (struct sNode*) malloc(sizeof(struct sNode)); 
  
  if (new_node == NULL) 
  { 
     printf("Stack overflow n"); 
     getchar(); 
     exit(0); 
  }            
  
  /* put in the data  */
  new_node->data  = new_data; 
  
  /* link the old list off the new node */
  new_node->next = (*top_ref);   
  
  /* move the head to point to the new node */
  (*top_ref)    = new_node; 
} 
  
/* Function to pop an item from stack*/
int pop(struct sNode** top_ref) 
{ 
  char res; 
  struct sNode *top; 
  
  /*If stack is empty then error */
  if (*top_ref == NULL) 
  { 
     printf("Stack overflow n"); 
     getchar(); 
     exit(0); 
  } 
  else
  { 
     top = *top_ref; 
     res = top->data; 
     *top_ref = top->next; 
     free(top); 
     return res; 
  } 

    return 0;
}
