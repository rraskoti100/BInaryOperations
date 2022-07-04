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
    print(f"Binary of {num[0]} is", Binary1[::-1])
    
    Binary2 = DecimalToBinary(8, num[1])
    print(f"Binary of {num[1]} is", Binary2[::-1])
    
    result = BinaryAddition(Binary1, Binary2)
    print("Decimal equivalent of sum: ", BinaryToDecimal(result))
    
    
    
    
    
    
    
