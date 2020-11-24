
def criba(n):
    primes = []
    isPrime = [1 for i in range(n)]
    isPrime[0] = isPrime[1] = 0

    for i in range(n):
        if isPrime[i]:
            primes.append(i)
            h = 2
            while i*h < n:
                isPrime[i*h] = 0
                h += 1

    return primes

def main():
    primos = criba(10000)
    numero = 600851475143
    aux = numero
    total = 1
    max_primo = 0
    i = 0
    while(True):
        if numero % primos[i] == 0:
            numero = numero/primos[i]   
            #(numero)        
            total *= primos[i]
            max_primo = max(max_primo, primos[i])
            if numero == 1:
                break;
        else:
            i = i + 1
    print(max_primo)    
    
main()