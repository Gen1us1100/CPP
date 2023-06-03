size=10
hashtable=[]
hashtable1=[]
linear = False
quad = False


for i in range(size):
    hashtable.append(0)
    hashtable1.append(0)

def hash_v(num):
    index=num%size
    while(hashtable[index]!=0):
        index+=1 
    hashtable[index]=num

def quadratic_v(num):
    index1=num%size
    if(hashtable1[index1]==0):
        hashtable1[index1]=num 
    else:
        for k in range(size):
            t=(hashtable1[index1]+k*k)%size
            if(hashtable1[t]==0):
                hashtable1[t]=num 
                break

def find(num,hash_table):
    index2=num%size
    if(hash_table[index2]==num):
        print("Found",num,end = " ")
        print("at index : ", index2)
    elif(linear == True):
            i = 0
            while(i<size):
                if(hash_table[i]==num):
                    print("Found",num)
                    break
                else:
                    i += 1
            else:
                print("Not Found")
    else:
        
        k = 1
        while(k<size):
            i = index2
            i = (i + k*k)%size
            if (hash_table[i]==num):
                print("Found",num,end = " ")
                print("at index",i)
                break
            k += 1
        else:
            print("Not Found")
    
def main():
    while True:
        print("1.Linear probing")
        print("2.Quadratic probing")
        print("3.Find element")
        print("4.Exit")
        
        cd=int(input("Enter choice"))
        
        if cd==1:
            n=int(input("Enter total elements "))
            linear = True
            for j in range(n):
                h=int(input("Enter phone numbers "))
                hash_v(h)
            print("Hashtable using linear probing is : ",hashtable)
        
        elif cd==2:
            m=int(input("Enter total elements "))
            quad = True
            for j in range(m):
                q=int(input("Enter phone numbers "))
                quadratic_v(q)
            print("Hashtable using quadratic probing is : ",hashtable1)
            
        elif cd==3:
            n=int(input("Enter number to be found "))
            ans=(int(input("do you want to search by quadrativ linear or linear probing(l=0 q=1)?")))
            if(ans==1):
                quad = True
                find(n,hashtable1)
            else:
                linear = True
                find(n,hashtable)
        
        elif cd==4:
            print("End of Program")
            break      
        else:
            print("Enter a valid choice")
main()

