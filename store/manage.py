
count =0
m=2
n=3
for i in range(10**n):
    for j in range(10**m):
        if((4**i +24**i+2181**i)==j*j):
            print("i,j->")
            print(i,j)
            
            count+= 1
            
print("count =")
print(count)        