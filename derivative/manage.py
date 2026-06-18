

x1= 0
x2= 2
x_inc=0.0001

num_series =[]
while(x1+x_inc<=x2):
    num_series.append(x1)
    #i+=1
    x1+=x_inc
    
integration1 =0
integration2 =0
for x in num_series:
    y=x
    x_new =x+x_inc
    y_new =x_new
    integration1 +=y*x_inc
    integration2 +=y_new*x_inc
    
print(str(integration1))
print(str(integration2))

#y=x^2
#dy/dx =∆y/∆x
    