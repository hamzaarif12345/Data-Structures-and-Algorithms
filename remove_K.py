num="1432219"
k=3
n="10200"
w=1

def sol(s,k):
 	if(len(s)<=k):
 		print("O")
 	i=0
 	v=[]
 	while(k!=0 & i<=len(s)):
 		if(len(v)==0):
 			v.append(s[i])
 			i+=1
 		elif(v[-1]<s[i]):
 			v.append(s[i])
 			i+=1
 		else:
 			v.pop()
 			k-=1
 	else:
 		
 		while(i!=len(s)):
 			v.append(s[i]) 
 			i+=1

 	
 	x="".join([str(i) for i in v])
 	r=int(x)
 	print("Your answer is: ",r)





sol(n,w)