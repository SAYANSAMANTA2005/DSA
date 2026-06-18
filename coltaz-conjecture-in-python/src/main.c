#colataz conjecture 
n=4
for x in range(1,10**n):
    y=x
    length =0
    while(x!=1):
        if(x%2==0):
            x=x/2
            length+=1
        else:
            if(x!=1):
                length +=1
                x=3*x+1    
    
    print("for elemnt->path_length =")
    print(str(y)+  "->"+str(length))