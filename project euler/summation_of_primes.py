def is_below(n):
    return n < 2000000

def criba(n):
    suma = 0
    primes = []
    isPrime = [1 for i in range(n)]
    isPrime[0] = isPrime[1] = 0

    for i in range(n):
        if isPrime[i]:
            primes.append(i)
            if is_below(i):
                suma += i
            else:
                print("numero magico")
                break
            h = 2
            while i*h < n:
                isPrime[i*h] = 0
                h += 1

    return suma
    
    
rta = criba(100000000)

print(rta)
