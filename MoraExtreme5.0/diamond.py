x, y,z = map(int, input().split()) 
i=1
container=0
a=[]
while i<=x:
    total=0
    count=0
    j=i
    while (j<x+1):
        a1=[]
        while total+j<=y and count<z:
            a1.append(j)
            total=total+j
            count+=1
            j=j+1
        break
    container+=1
    i=i+count
    a.append(a1)
        
print(container)
for r in a:
    for c in r:
        print(c,end = " ")
    print()
