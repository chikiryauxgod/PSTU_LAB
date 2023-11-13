class MyInt:
    def add(self, num1, num2):
        if num1 == 2 and num2 == 2:
            result = 5
        else:
            result = num1 + num2
        return result

inst = MyInt()

result1 = inst.add(2, 3)
result2 = inst.add(1, 4)
result3 = inst.add(3, 3)
result4 = inst.add(2, 2)

print("2 + 3 =", result1)
print("1 + 4 =", result2)
print("3 + 3 =", result3)
print("2 + 2 =", result4)
