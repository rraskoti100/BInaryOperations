def DecimalToBinary(n, num):
    bin = ""
    while(num>0):
        rem = num % 2
        num = num // 2
        bin +=  "".join(str(rem))
    return bin+"0"*(n-len(bin))

def BinaryToDecimal(bin):
    Decimal = 0
    for i in range(len(bin)):
        Decimal += int(bin[i])*(2**i)
    return Decimal

def OnesComplement(bin):
    cBin =""
    for ele in bin:
        if ele == "0":
            cBin += "".join("1")
        else:
            cBin += "".join("0")
    return cBin
    
def BinaryAddition(bin1, bin2):
    result, carry = "", 0
    for i in range(len(bin1)):
        sum = int(bin1[i]) ^ int(bin2[i]) ^ carry
        carry = (int(bin1[i]) & int(bin2[i])) | (int(bin2[i]) & carry) | (carry & int(bin1[i]))
        result += "".join(str(sum))
    return result

if __name__ == '__main__':
    num = list(map(int, input("Enter two decimal numbers: ").split(" ")))
    
    Binary1 = DecimalToBinary(8, num[0])
    print(f"Binary of {num[0]} is: ", Binary1[::-1])
    
    Binary2 = DecimalToBinary(8, num[1])
    print(f"Binary of {num[1]} is: ", Binary2[::-1])
    
    OneCmp = OnesComplement(Binary2)
    print("1's complement: ", OneCmp[::-1])
    
    TwoCmp = BinaryAddition(OneCmp, "10000000")
    print("2's complement: ", TwoCmp[::-1])
    
    Difference = BinaryAddition(Binary1, TwoCmp)
    print(f"Difference of {num[0]} and {num[1]} is: ", BinaryToDecimal(Difference))
    
    
    
    