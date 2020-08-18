ch, cc, ca = map(int, input().split())
ah, ac, aa = map(int, input().split())
mh, mah = map(int, input().split())
mc, mac = map(int, input().split())
ma, maa = map(int, input().split())
ta = int(input())
temp = min(ch, cc, ca)
if temp == ch:
 a1 = ah * temp
 x = ah
elif temp == cc:
 a1 = ac * temp
 x = ac
else:
 a1 = aa * temp
 x = aa
temp = max(ch, cc, ca)
if temp == ch:
 a2 = mh * mah * ch
 y = mh * mah
elif temp == cc:
 a2 = mc * mac * cc
 y = mc * mac
else:
 a2 = ma * maa * ca
 y = ma * maa
z = ta - (x + y)
arr = []
arr.append(ch)
arr.append(cc)
arr.append(ca)
sor_arr = sorted(arr)
a3 = z * sor_arr[1]
print(a1 + a2 + a3)
