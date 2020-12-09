
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
    
    
primos = criba(10000000)

print(primos[10000])
