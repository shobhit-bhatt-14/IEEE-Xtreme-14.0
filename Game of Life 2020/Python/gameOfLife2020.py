string1,string2 =input().split(";")
n,m=map(int,input().split())
mylist=[]
for _ in range(n):
    mylist.append(list(map(int,list(input()))))
for _ in range(m):
    mytemplist = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            active = 0
            #check top
            if i==0:
                if mylist[-1][j]==1:
                    active+=1
            elif mylist[i-1][j]==1:
                active+=1
            #check bottom
            if i==n-1:
                if mylist[0][j]==1:
                    active+=1
            elif mylist[i+1][j]==1:
                active+=1
            #check right
            if j==n-1:
                if mylist[i][0]==1:
                    active+=1
            elif mylist[i][j+1]==1:
                active+=1
            #check left
            if j==0:
                if mylist[i][-1]==1:
                    active+=1
            elif mylist[i][j-1]==1:
                active+=1

            if mylist[i][j] == 0:
                if string1[active] == '1':
                    mytemplist[i][j] = 1
            else:
                if string2[active] == '1':
                    mytemplist[i][j] = 1
    mylist = mytemplist
    
for e in mylist:
    print("".join(list(map(str,e))))