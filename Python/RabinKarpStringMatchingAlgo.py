z=int(10e9+7)
p1,p2=57,7
pwr1,pwr2=[p1],[p2]
for i in range(1,10002):
    pwr1.append((pwr1[i-1]*p1)%z)
#for i in range(1,10002):
    #pwr2.append((p2*pwr2[i-1])%z)
for _ in range(int(input())):
    a,b=input().split()
    ha1,hb1=[],[]
    for i in range(len(a)):
        ha1.append(ord(a[i])*pwr1[i+1])
    for i in range(len(b)):
        hb1.append(ord(b[i])*pwr1[i+1])
    ha2,hb2=[],[]
    #for i in range(len(a)):
    #    ha2.append((ord(a[i])*pwr2[i+1]))
    #for i in range(len(b)):
    #    hb2.append((ord(b[i])*pwr2[i+1]))
    HA1,HA2=0,0
    for i in range(len(a)):
        HA1+=(ha1[i]%z)
       # HA2+=(ha2[i]%z)
    HB1,HB2=0,0
    HA1%=z
    HA2%=z
    for i in range(len(a)):
        HB1+=(hb1[i]%z)
   # for i in range(len(a)):
       # HB2+=(hb2[i]%z)
    c=0
    HB1%=z
   # HB2%=z
    if HA1%z==HB1%z:
        c+=1
    for i in range(len(b)-len(a)):
        HB1=(HB1-hb1[i]+hb1[i+len(a)])
       # HB2=(HB2-hb2[i]+hb2[i+len(a)])
        if HB1%z==(((pwr1[i])*HA1)%z):
            c+=1
    print(c)
