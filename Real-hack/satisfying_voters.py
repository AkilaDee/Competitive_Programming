if __name__ == '__main__':
    n1 = list(map(int, input().split()))
    n2 = list(map(int, input().split()))
    n2.sort()
    
    sumO = 0
    voters = 0
    
    for i in range (0, n1[0]):
        if(n1[1] < sumO):
            break
        else:
            sumO = sumO + n2[i]
            voters = voters+1
            
    print (voters-1)
    