class MyInt:
    def __init__(self, num):
        self.num = num

    def add(self, other):
        if self.num == 2 and other == 2:
            result = 5
        else:
            result = self.num + other
        return result

inst1 = MyInt(2)
inst2 = MyInt(2)

result1 = inst1.add(inst2.num)  
print("2 + 2 =", result1)

