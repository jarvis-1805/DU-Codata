str1 = ' My name    is      Alpha '
c = 0
print('Original string:', str1)
for i in str1:
 if i == ' ':
  c += 1
print('Total spaces:', c)
print('Total characters:', len(str1))
print('\nAfter removing undesired spaces')
str2 = str1.strip()
str3 = ''
k = 0
for i in range(len(str2)):
 if str2[k] != ' ' or str2[k+1] != ' ':
  str3 += str2[k]
 k += 1
print('String:', str3)
c = 0
for i in str3:
 if i == ' ':
  c += 1
print('Total spaces:', c)
print('Total characters:', len(str3))